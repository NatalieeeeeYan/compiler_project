#include "ast2llvm.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
#include <list>

using namespace std;
using namespace LLVMIR;

static unordered_map<string, FuncType> funcReturnMap;
static unordered_map<string, StructInfo> structInfoMap;
static unordered_map<string, Name_name*> globalVarMap;  // 全局变量表
//static unordered_map<string, Temp_temp*> localVarMap;   // 局部变量表
static list<unordered_map<string, Temp_temp*>> localVarStack;  // 局部变量表栈
static list<L_stm*> emit_irs;

LLVMIR::L_prog* ast2llvm(aA_program p)
{
    auto defs = ast2llvmProg_first(p);
    auto funcs = ast2llvmProg_second(p);
    vector<L_func*> funcs_block;
    for(const auto &f : funcs)
    {
        funcs_block.push_back(ast2llvmFuncBlock(f));
    }
    for(auto &f : funcs_block)
    {
        ast2llvm_moveAlloca(f);
    }
    return new L_prog(defs,funcs_block);
}

int ast2llvmRightVal_first(aA_rightVal r)
{
    if(r == nullptr)
    {
        return 0;
    }
    switch (r->kind)
    {
    case A_arithExprValKind:
    {
        return ast2llvmArithExpr_first(r->u.arithExpr);
        break;
    }
    case A_boolExprValKind:
    {
        return ast2llvmBoolExpr_first(r->u.boolExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolExpr_first(aA_boolExpr b)
{
    switch (b->kind)
    {
    case A_boolBiOpExprKind:
    {
        return ast2llvmBoolBiOpExpr_first(b->u.boolBiOpExpr);
        break;
    }
    case A_boolUnitKind:
    {
        return ast2llvmBoolUnit_first(b->u.boolUnit);
        break;
    }
    default:
         break;
    }
    return 0;
}

int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b)
{
    int l = ast2llvmBoolExpr_first(b->left);
    int r = ast2llvmBoolExpr_first(b->right);
    if(b->op == A_and)
    {
        return l && r;
    }
    else
    {
        return l || r;
    }
}

int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b)
{
    if(b->op == A_not)
    {
        return !ast2llvmBoolUnit_first(b->cond);
    }
    return 0;
}

int ast2llvmBoolUnit_first(aA_boolUnit b)
{
    switch (b->kind)
    {
    case A_comOpExprKind:
    {
        return ast2llvmComOpExpr_first(b->u.comExpr);
        break;
    }
    case A_boolExprKind:
    {
        return ast2llvmBoolExpr_first(b->u.boolExpr);
        break;
    }
    case A_boolUOpExprKind:
    {
        return ast2llvmBoolUOpExpr_first(b->u.boolUOpExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmComOpExpr_first(aA_comExpr c)
{
    auto l = ast2llvmExprUnit_first(c->left);
    auto r = ast2llvmExprUnit_first(c->right);
    switch (c->op)
    {
    case A_lt:
    {
        return l < r;
        break;
    }
    case A_le:
    {
        return l <= r;
        break;
    }
    case A_gt:
    {
        return l > r;
        break;
    }
    case A_ge:
    {
        return l >= r;
        break;
    }
    case A_eq:
    {
        return l == r;
        break;
    }
    case A_ne:
    {
        return l != r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a)
{
    auto l= ast2llvmArithExpr_first(a->left);
    auto r = ast2llvmArithExpr_first(a->right);
    switch (a->op)
    {
    case A_add:
    {
        return l + r;
        break;
    }
    case A_sub:
    {
        return l - r;
        break;
    }
    case A_mul:
    {
        return l * r;
        break;
    }
    case A_div:
    {
        return l / r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithUExpr_first(aA_arithUExpr a)
{
    if(a->op == A_neg)
    {
        return -ast2llvmExprUnit_first(a->expr);
    }
    return 0;
}

int ast2llvmArithExpr_first(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithBiOpExprKind:
    {
        return ast2llvmArithBiOpExpr_first(a->u.arithBiOpExpr);
        break;
    }
    case A_exprUnitKind:
    {
        return ast2llvmExprUnit_first(a->u.exprUnit);
        break;
    }
    default:
        assert(0);
        break;
    }
    return 0;
}

int ast2llvmExprUnit_first(aA_exprUnit e)
{
    if(e->kind == A_numExprKind)
    {
        return e->u.num;
    }
    else if(e->kind == A_arithExprKind)
    {
        return ast2llvmArithExpr_first(e->u.arithExpr);
    }
    else if(e->kind == A_arithUExprKind)
    {
        return ast2llvmArithUExpr_first(e->u.arithUExpr);
    }
    else
    {
        assert(0);
    }
    return 0;
}

std::vector<LLVMIR::L_def*> ast2llvmProg_first(aA_program p)
{
    vector<L_def*> defs;
    for(const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            if(v->u.varDeclStmt->kind == A_varDeclKind)
            {
                if(v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind)
                {
                    if(v->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                            Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id),*v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP,0,*v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,def,vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                            Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
                        TempDef def(TempType::INT_TEMP,0);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,def,vector<int>()));
                    }
                }
                else if(v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind)
                {
                    if(v->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                            Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id),v->u.varDeclStmt->u.varDecl->u.declArray->len,*v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR,v->u.varDeclStmt->u.varDecl->u.declArray->len,*v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id,def,vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                            Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id),v->u.varDeclStmt->u.varDecl->u.declArray->len));
                        TempDef def(TempType::INT_PTR,v->u.varDeclStmt->u.varDecl->u.declArray->len);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id,def,vector<int>()));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else if(v->u.varDeclStmt->kind == A_varDefKind)
            {
                if(v->u.varDeclStmt->u.varDef->kind == A_varDefScalarKind)
                {
                    if(v->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                            Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id),*v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP,0,*v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id,def,vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                            Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id)));
                        TempDef def(TempType::INT_TEMP,0);
                        vector<int> init;
                        init.push_back(ast2llvmRightVal_first(v->u.varDeclStmt->u.varDef->u.defScalar->val));
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id,def,init));
                    }
                }
                else if(v->u.varDeclStmt->u.varDef->kind == A_varDefArrayKind)
                {
                    if(v->u.varDeclStmt->u.varDef->u.defArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                            Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id),v->u.varDeclStmt->u.varDef->u.defArray->len,*v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR,v->u.varDeclStmt->u.varDef->u.defArray->len,*v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id,def,vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                            Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id),v->u.varDeclStmt->u.varDef->u.defArray->len));
                        TempDef def(TempType::INT_PTR,v->u.varDeclStmt->u.varDef->u.defArray->len);
                        vector<int> init;
                        for(auto &el : v->u.varDeclStmt->u.varDef->u.defArray->vals)
                        {
                            init.push_back(ast2llvmRightVal_first(el));
                        }
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id,def,init));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }
        case A_programStructDefKind:
        {
            StructInfo si;
            int off = 0;
            vector<TempDef> members;
            for(const auto &decl : v->u.structDef->varDecls)
            {
                if(decl->kind == A_varDeclScalarKind)
                {
                    if(decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_TEMP,0,*decl->u.declScalar->type->u.structType);
                        MemberInfo info(off++,def);
                        si.memberinfos.emplace(*decl->u.declScalar->id,info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP,0);
                        MemberInfo info(off++,def);
                        si.memberinfos.emplace(*decl->u.declScalar->id,info);
                        members.push_back(def);
                    }
                }
                else if(decl->kind == A_varDeclArrayKind)
                {
                    if(decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR,decl->u.declArray->len,*decl->u.declArray->type->u.structType);
                        MemberInfo info(off++,def);
                        si.memberinfos.emplace(*decl->u.declArray->id,info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR,decl->u.declArray->len);
                        MemberInfo info(off++,def);
                        si.memberinfos.emplace(*decl->u.declArray->id,info);
                        members.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            structInfoMap.emplace(*v->u.structDef->id,std::move(si));
            defs.push_back(L_Structdef(*v->u.structDef->id,members));
            break;
        }
        case A_programFnDeclStmtKind:
        {
            FuncType type;
            if(v->u.fnDeclStmt->fnDecl->type == nullptr)
            {
                type.type = ReturnType::VOID_TYPE;
            }
            else if(v->u.fnDeclStmt->fnDecl->type->type == A_nativeTypeKind)
            {
                type.type = ReturnType::INT_TYPE;
            }
            else if(v->u.fnDeclStmt->fnDecl->type->type == A_structTypeKind)
            {
                type.type = ReturnType::STRUCT_TYPE;
                type.structname = *v->u.fnDeclStmt->fnDecl->type->u.structType;
            }
            else
            {
                assert(0);
            }
            if(funcReturnMap.find(*v->u.fnDeclStmt->fnDecl->id) == funcReturnMap.end())
                funcReturnMap.emplace(*v->u.fnDeclStmt->fnDecl->id,std::move(type));
            vector<TempDef> args;
            for(const auto & decl : v->u.fnDeclStmt->fnDecl->paramDecl->varDecls)
            {
                if(decl->kind == A_varDeclScalarKind)
                {
                    if(decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR,0,*decl->u.declScalar->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP,0);
                        args.push_back(def);
                    }
                }
                else if(decl->kind == A_varDeclArrayKind)
                {
                    if(decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR,-1,*decl->u.declArray->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR,-1);
                        args.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            defs.push_back(L_Funcdecl(*v->u.fnDeclStmt->fnDecl->id,args,type));
            break;
        }
        case A_programFnDefKind:
        {
            if(funcReturnMap.find(*v->u.fnDef->fnDecl->id) == funcReturnMap.end())
            {
                FuncType type;
                if(v->u.fnDef->fnDecl->type == nullptr)
                {
                    type.type = ReturnType::VOID_TYPE;
                }
                else if(v->u.fnDef->fnDecl->type->type == A_nativeTypeKind)
                {
                    type.type = ReturnType::INT_TYPE;
                }
                else if(v->u.fnDef->fnDecl->type->type == A_structTypeKind)
                {
                    type.type = ReturnType::STRUCT_TYPE;
                    type.structname = *v->u.fnDef->fnDecl->type->u.structType;
                }
                else
                {
                    assert(0);
                }
                funcReturnMap.emplace(*v->u.fnDef->fnDecl->id,std::move(type));
            }
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return defs;
}

std::vector<Func_local*> ast2llvmProg_second(aA_program p)
{
    vector<Func_local*> funcs;
    for(const auto & v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            break;
        }
        case A_programStructDefKind:
        {
            break;
        }
        case A_programFnDeclStmtKind:
        {
            break;
        }
        case A_programFnDefKind:
        {
            funcs.push_back(ast2llvmFunc(v->u.fnDef));
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return funcs;
}

// TODO: 
Func_local* ast2llvmFunc(aA_fnDef f)
{
    auto name = *f->fnDecl->id;
    auto ret = funcReturnMap[name];  // 从映射中获取函数返回类型
    std::vector<Temp_temp*> args;
    //localVarMap.clear();
    localVarStack.clear();
    localVarStack.push_back(unordered_map<string, Temp_temp*>());  // 栈底元素为nullptr
    emit_irs.clear();

    // 创建函数起始标签并添加到IR语句列表
    auto start_label = Temp_newlabel();
    emit_irs.push_back(L_Label(start_label));

    // 遍历所有函数参数并进行处理
    for (const auto& decl : f->fnDecl->paramDecl->varDecls) {
        if (decl->kind == A_varDeclScalarKind) {
            auto declScalar = decl->u.declScalar;
            auto id = *declScalar->id;
            auto type = declScalar->type;
            if (type->type == A_structTypeKind) {
                // 结构体参数以指针形式传递
                auto temp = Temp_newtemp_struct_ptr(0, *type->u.structType);
                args.push_back(temp);           // 添加到参数向量
                //localVarMap.emplace(id, temp);  // 映射参数名称到局部变量
                localVarStack.back().emplace(id, temp);  // 映射参数名称到局部变量
            } else {
                // 处理标量参数
                auto temp = Temp_newtemp_int();
                args.push_back(temp);
                auto stackPtr = Temp_newtemp_int_ptr(0);
                //localVarMap.emplace(id, stackPtr);
                localVarStack.back().emplace(id, stackPtr);

                // 分配内存并存储初值
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(stackPtr)));
                emit_irs.push_back(
                    L_Store(AS_Operand_Temp(temp), AS_Operand_Temp(stackPtr)));
            }
        } else if (decl->kind == A_varDeclArrayKind) {
            auto declArray = decl->u.declArray;
            auto id = *declArray->id;     // 提取数组参数标识符
            auto type = declArray->type;  // 提取数组元素类型
            auto len = declArray->len;    // 提取数组长度
            if (type->type == A_structTypeKind) {
                // 结构体数组以指针形式传递
                auto temp = Temp_newtemp_struct_ptr(-1, *type->u.structType);
                args.push_back(temp);
                //localVarMap.emplace(id, temp);
                localVarStack.back().emplace(id, temp);
            } else {
                // 基本类型数组处理
                auto temp = Temp_newtemp_int_ptr(-1);
                args.push_back(temp);
                //localVarMap.emplace(id, temp);
                localVarStack.back().emplace(id, temp);
            }
        } else {
            assert(0);  // 断言未知类型
        }
    }

    aA_codeBlockStmt currentStmt = nullptr;  // 当前处理的语句初始化为nullptr

    localVarStack.push_back(unordered_map<string, Temp_temp*>());
    // 处理函数体内的所有语句
    for (const auto& stmt : f->stmts) {
        currentStmt = stmt;
        ast2llvmBlock(stmt);  // 转换语句块为IR

        // 遇到返回语句时终止处理
        if (stmt->kind == A_codeBlockStmtType::A_returnStmtKind) {
            break;
        }
    }
    localVarStack.pop_back();
    // 如果函数返回类型为void且没有遇到返回语句，添加返回null的IR语句
    if (ret.type == ReturnType::VOID_TYPE &&
        (currentStmt == nullptr ||
         currentStmt->kind != A_codeBlockStmtType::A_returnStmtKind)) {
        emit_irs.push_back(L_Ret(nullptr));
    }

    // 构建并返回最终的IR函数对象
    return new Func_local(name, ret, args, emit_irs);
}

void ast2llvmBlock(aA_codeBlockStmt b,Temp_label *con_label,Temp_label *bre_label)
{
    switch (b->kind) {
        case A_codeBlockStmtType::A_nullStmtKind: {
        } break;
        case A_codeBlockStmtType::A_varDeclStmtKind: {
            ast2llvmVarDeclStmt(b->u.varDeclStmt);
        } break;
        case A_codeBlockStmtType::A_assignStmtKind: {
            ast2llvmAssignStmt(b->u.assignStmt);
        } break;
        case A_codeBlockStmtType::A_callStmtKind: {
            ast2llvmCallStmt(b->u.callStmt);
        } break;
        case A_codeBlockStmtType::A_ifStmtKind: {
            ast2llvmIfStmt(b->u.ifStmt, con_label, bre_label);
        } break;
        case A_codeBlockStmtType::A_whileStmtKind: {
            ast2llvmWhileStmt(b->u.whileStmt);
        } break;
        case A_codeBlockStmtType::A_returnStmtKind: {
            ast2llvmReturnStmt(b->u.returnStmt);
        } break;
        case A_codeBlockStmtType::A_continueStmtKind: {
            emit_irs.push_back(L_Jump(con_label));
        } break;
        case A_codeBlockStmtType::A_breakStmtKind: {
            emit_irs.push_back(L_Jump(bre_label));
        } break;
        default:
            assert(0);
    }
}

AS_operand* ast2llvmRightVal(aA_rightVal r)
{
    if (r == nullptr) {
        return nullptr;
    }
    if (r->kind == A_rightValType::A_arithExprValKind) {
        return ast2llvmArithExpr(r->u.arithExpr);
    }
    if (r->kind == A_rightValType::A_boolExprValKind) {
        return ast2llvmBoolExpr(r->u.boolExpr);
    }
    return nullptr;
}

AS_operand* ast2llvmLeftVal(aA_leftVal l)
{
    if (l == nullptr) {
        return nullptr;
    }
    if (l->kind == A_leftValType::A_varValKind) {
        return ast2llvmVarval(*l->u.id);
    } else if (l->kind == A_leftValType::A_arrValKind) {
        return ast2llvmArrayExpr(l->u.arrExpr);
    } else if (l->kind == A_leftValType::A_memberValKind) {
        return ast2llvmMemberExpr(l->u.memberExpr);
    }
    return nullptr;
}

AS_operand* ast2llvmIndexExpr(aA_indexExpr index)
{
    if (index->kind == A_indexExprKind::A_numIndexKind) {
        return AS_Operand_Const(index->u.num);
    }else if (index->kind == A_indexExprKind::A_idIndexKind) {
        auto id = *index->u.id;
        auto temp_ptr = ast2llvmVarval(id);
        auto temp_val = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Load(temp_val, temp_ptr));
        return temp_val;
    }
    return nullptr;
}

AS_operand* ast2llvmBoolExpr(aA_boolExpr b,Temp_label *true_label,Temp_label *false_label)
{
    bool should_return = false;
    AS_operand* stackPtr = nullptr;
    if (true_label == nullptr || false_label == nullptr) {
        true_label = Temp_newlabel();
        false_label = Temp_newlabel();
        should_return = true;
        stackPtr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));

        // 需要分配空间存放布尔值(用int表示)
        emit_irs.push_back(L_Alloca(stackPtr));
    }
    if (b->kind == A_boolExprType::A_boolBiOpExprKind) {
        ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
    } else if (b->kind == A_boolExprType::A_boolUnitKind) {
        ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
    }
    if (should_return) {
        //cerr<<"ast2llvmBoolExpr: should_return"<<endl;
        auto temp = AS_Operand_Temp(Temp_newtemp_int());
        auto end_label = Temp_newlabel();
        //cerr<<"true:"<<true_label->name<<" false:"<<false_label->name<<" end:"<<end_label->name<<endl;
        //cerr<<"stackPtr:"<<stackPtr->u.TEMP->num<<endl;
        // 在真和假标签处，分别存储整数值1和0到之前分配的stackPtr
        // 从这两个标签跳转到一个公共的结束标签

        // true
        emit_irs.push_back(L_Label(true_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(1), stackPtr));
        emit_irs.push_back(L_Jump(end_label));

        // false
        emit_irs.push_back(L_Label(false_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(0), stackPtr));
        emit_irs.push_back(L_Jump(end_label));

        //加载 stackPtr 的内容到另一个新的临时变量
        // ir: end
        emit_irs.push_back(L_Label(end_label));
        emit_irs.push_back(L_Load(temp, stackPtr));

        return temp;
    }
    return nullptr;
}

void ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b,Temp_label *true_label,Temp_label *false_label)
{
    if (b->op == A_boolBiOp::A_and) {
        //andTrueLabel 中间跳转点，表示左操作数为真时程序的跳转位置
        auto andTrueLabel = Temp_newlabel();
        ast2llvmBoolExpr(b->left, andTrueLabel, false_label);
        emit_irs.push_back(L_Label(andTrueLabel));
        ast2llvmBoolExpr(b->right, true_label, false_label);
    }
    if (b->op == A_boolBiOp::A_or) {
        //orFalseLabel 中间跳转点，表示左操作数为假时程序的跳转位置
        auto orFalseLabel = Temp_newlabel();
        ast2llvmBoolExpr(b->left, true_label, orFalseLabel);
        emit_irs.push_back(L_Label(orFalseLabel));
        ast2llvmBoolExpr(b->right, true_label, false_label);
    }
}

void ast2llvmBoolUnit(aA_boolUnit b,Temp_label *true_label,Temp_label *false_label)
{
    if (b->kind == A_boolUnitType::A_boolExprKind) {
        ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
    } else if (b->kind == A_boolUnitType::A_boolUOpExprKind) {
        ast2llvmBoolUOpExpr(b->u.boolUOpExpr, true_label, false_label);
    } else if (b->kind == A_boolUnitType::A_comOpExprKind) {
        ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
    }
}

void ast2llvmComOpExpr(aA_comExpr c,Temp_label *true_label,Temp_label *false_label)
{
    auto l = ast2llvmExprUnit(c->left);
    auto r = ast2llvmExprUnit(c->right);
    auto dst = AS_Operand_Temp(Temp_newtemp_int());
    switch (c->op) {
        case A_comOp::A_lt: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_lt, l, r, dst));
            break;
        }
        case A_comOp::A_le: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_le, l, r, dst));
            break;
        }
        case A_comOp::A_gt: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_gt, l, r, dst));
            break;
        }
        case A_comOp::A_ge: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_ge, l, r, dst));
            break;
        }
        case A_comOp::A_eq: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_eq, l, r, dst));
            break;
        }
        case A_comOp::A_ne: {
            emit_irs.push_back(L_Cmp(L_relopKind::T_ne, l, r, dst));
            break;
        }
        default:
            break;
    }

    emit_irs.push_back(L_Cjump(dst, true_label, false_label));
}

AS_operand* ast2llvmArithBiOpExpr(aA_arithBiOpExpr a)
{
    auto left = ast2llvmArithExpr(a->left);
    auto right = ast2llvmArithExpr(a->right);
    auto dst = AS_Operand_Temp(Temp_newtemp_int());
    switch (a->op) {
        case A_arithBiOp::A_add:
            emit_irs.push_back(L_Binop(L_binopKind::T_plus, left, right, dst));
            break;
        case A_arithBiOp::A_div:
            emit_irs.push_back(L_Binop(L_binopKind::T_div, left, right, dst));
            break;
        case A_arithBiOp::A_mul:
            emit_irs.push_back(L_Binop(L_binopKind::T_mul, left, right, dst));
            break;
        case A_arithBiOp::A_sub:
            emit_irs.push_back(L_Binop(L_binopKind::T_minus, left, right, dst));
            break;
        default:
            assert(0);
            break;
    }
    return dst;
}

AS_operand* ast2llvmArithUExpr(aA_arithUExpr a)
{
    auto left = AS_Operand_Const(0);
    auto right = ast2llvmExprUnit(a->expr);
    auto dst = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.push_back(L_Binop(L_binopKind::T_minus, left, right, dst));
    return dst;
}

AS_operand* ast2llvmArithExpr(aA_arithExpr a)
{
    if (a->kind == A_arithExprType::A_arithBiOpExprKind) {
        return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
    } else if (a->kind == A_arithExprType::A_exprUnitKind) {
        return ast2llvmExprUnit(a->u.exprUnit);
    } else {
        assert(0);
    }
    return nullptr;
}

AS_operand* ast2llvmExprUnit(aA_exprUnit e)
{
    switch (a->kind) {
        case A_exprUnitType::A_numExprKind:
            return AS_Operand_Const(a->u.num);
        case A_exprUnitType::A_arithExprKind:
            return ast2llvmArithExpr(a->u.arithExpr);
        case A_exprUnitType::A_arithUExprKind:
            return ast2llvmArithUExpr(a->u.arithUExpr);
        case A_exprUnitType::A_arrayExprKind: {
            auto arrayptr = ast2llvmArrayExpr(a->u.arrayExpr);
            auto res = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(res, arrayptr));
            return res;
        }
        case A_exprUnitType::A_memberExprKind: {
            auto memberptr = ast2llvmMemberExpr(a->u.memberExpr);
            auto res = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(res, memberptr));
            return res;
        }
        case A_exprUnitType::A_idExprKind: {
            auto temp_ptr = ast2llvmVarval(*a->u.id);
            if (temp_ptr->kind == OperandKind::TEMP &&
                temp_ptr->u.TEMP->type == TempType::INT_PTR &&
                temp_ptr->u.TEMP->len == 0) {
                auto val_dst_operand = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(val_dst_operand, temp_ptr));
                return val_dst_operand;
            } else if (temp_ptr->kind == OperandKind::NAME &&
                       temp_ptr->u.NAME->type ==
                           TempType::INT_TEMP) {  // 全局变量int
                auto val_dst_operand = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(val_dst_operand, temp_ptr));
                return val_dst_operand;
            } else if (temp_ptr->kind == OperandKind::ICONST) {
                return temp_ptr;
            } else {
                return temp_ptr;
            }
        }
        case A_exprUnitType::A_fnCallKind: {
            auto callExpr = a->u.callExpr;
            std::vector<AS_operand*> args;
            for (auto& arg : callExpr->vals) {
                args.push_back(ast2llvmRightVal(arg));
            }
            auto res = Temp_newtemp_int();
            emit_irs.push_back(
                L_Call(*callExpr->fn, AS_Operand_Temp(res), args));
            return AS_Operand_Temp(res);
        }
        default:
            assert(0);
            return nullptr;
    }
}

LLVMIR::L_func* ast2llvmFuncBlock(Func_local *f)
{
    
}

// TODO ends. 

void ast2llvm_moveAlloca(LLVMIR::L_func *f)
{
    auto first_block = f->blocks.front();
    for(auto i = ++f->blocks.begin();i != f->blocks.end();++i)
    {
        for(auto it = (*i)->instrs.begin();it != (*i)->instrs.end();)
        {
            if((*it)->type == L_StmKind::T_ALLOCA)
            {
                first_block->instrs.insert(++first_block->instrs.begin(),*it);
                it = (*i)->instrs.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}