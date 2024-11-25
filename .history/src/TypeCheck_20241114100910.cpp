#include "TypeCheck.h"

//global tabels
typeMap func2retType; // function name to return type

// global token ids to type
typeMap g_token2Type; 

// defined function
typeMap defFunc_token2Type; 

// local token ids to type, since func param can override global param
typeMap funcparam_token2Type;
vector<typeMap*> local_token2Type;

paramMemberMap func2Param;
paramMemberMap struct2Members;

intMap arr2Len;

string cur_fn;

// private util functions
void error_print(std::ostream& out, A_pos p, string info)
{
    out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}


void print_token_map(typeMap* map){
    for(auto it = map->begin(); it != map->end(); it++){
        std::cout << it->first << " : ";
        switch (it->second->type->type)
        {
        case A_dataType::A_nativeTypeKind:
            switch (it->second->type->u.nativeType)
            {
            case A_nativeType::A_intTypeKind:
                std::cout << "int";
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            std::cout << *(it->second->type->u.structType);
            break;
        default:
            break;
        }
        switch(it->second->isVarArrFunc){
            case 0:
                std::cout << " scalar";
                break;
            case 1:
                std::cout << " array";
                break;
            case 2:
                std::cout << " function";
                break;
        }
        std::cout << "\tloc: " << it->second->type->pos<< ":" << it->second->type->pos->col;
        std::cout << std::endl;
    }
}


void print_token_maps(){
    std::cout << "global token2Type:" << std::endl;
    print_token_map(&g_token2Type);
    std::cout << "local token2Type:" << std::endl;
    print_token_map(&funcparam_token2Type);
    std::cout << "defFunc token2Type:" << std::endl;
    print_token_map(&defFunc_token2Type);
}


bool comp_aA_type(aA_type target, aA_type t){
    if(!target || !t)
        return false;
    if(target->type != t->type)
        return false;
    if(target->type == A_dataType::A_nativeTypeKind)
        if(target->u.nativeType != t->u.nativeType)
            return false;
    if(target->type == A_dataType::A_structTypeKind)
        if(target->u.structType != t->u.structType)
            return false;
    return true;
}


bool comp_tc_type(tc_type target, tc_type t){
    if(!target || !t)
        return false;
    
    // arr kind first
    if (target->isVarArrFunc && t->isVarArrFunc == 0)
        return false;
    
    // if target type is nullptr, alwayse ok
    return comp_aA_type(target->type, t->type);
}


tc_type tc_Type(aA_type t, uint isVarArrFunc){
    tc_type ret = new tc_type_;
    ret->type = t;
    ret->isVarArrFunc = isVarArrFunc;
    return ret;
}


tc_type tc_Type(aA_varDecl vd){
    if(vd->kind == A_varDeclType::A_varDeclScalarKind)
        return tc_Type(vd->u.declScalar->type, 0);
    else if(vd->kind == A_varDeclType::A_varDeclArrayKind)
        return tc_Type(vd->u.declArray->type, 1);
    return nullptr;
}


// public functions
void check_Prog(std::ostream& out, aA_program p)
{
    for (auto ele : p->programElements)
    {
        if(ele->kind == A_programVarDeclStmtKind){
            check_VarDecl(out, ele->u.varDeclStmt, "");
        }else if (ele->kind == A_programStructDefKind){
            check_StructDef(out, ele->u.structDef);
        }
    }
    
    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDeclStmtKind){
            check_FnDeclStmt(out, ele->u.fnDeclStmt);
        }
        else if (ele->kind == A_programFnDefKind){
            check_FnDecl(out, ele->u.fnDef->fnDecl);
        }
    }

    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDefKind){
            check_FnDef(out, ele->u.fnDef);
        }
        else if (ele->kind == A_programNullStmtKind){
            // do nothing
        }
    }

    out << "Typecheck passed!" << std::endl;
    return;
}


bool hasFunctionParameter(const paramMemberMap& func2Param, const std::string& name, const std::string& para) {
    // 首先检查是否存在名称为 name 的函数
    // std::cout << "hasFunctionParameter: " << name << " " << para << std::endl;
    // for (auto para : func2Param) {
    //     std::cout << "para: " << para.first << "\t";
    // }
    // std::cout << std::endl;
    auto it = func2Param.find(name);
    if (it != func2Param.end()) {
        // 如果找到了名为 name 的函数，则检查它是否具有名为 para 的参数
        const std::vector<aA_varDecl>* parameters = it->second;
        if (parameters) {
            for (const auto& param : *parameters) {
                if (param->kind == A_varDeclType::A_varDeclScalarKind && *(param->u.declScalar->id) == para) {
                    return true;
                } else if (param->kind == A_varDeclType::A_varDeclArrayKind && *(param->u.declArray->id) == para) {
                    return true;
                }
            }
        }
    }
    // 如果未找到匹配的函数或参数，则返回 false
    return false;
}

// 在结构体中查找成员变量
bool findMemberInStruct(string member, vector<aA_varDecl>* varDecls) {
    // 标记变量是否存在于结构体中
    bool isMemberFound = false;
    // 遍历结构体的每个变量声明
    for (auto varDecl : *varDecls) {
        if (varDecl->kind == A_varDeclType::A_varDeclScalarKind) {      // 如果变量声明是标量类型
            aA_varDeclScalar scalarVarDecl = varDecl->u.declScalar;
            string varName = *(scalarVarDecl->id);
            // 检查是否与 member 匹配
            if (varName == member) {
                isMemberFound = true;
                break;
            }
        } else if (varDecl->kind == A_varDeclType::A_varDeclArrayKind) {      // 如果变量声明是数组类型
            aA_varDeclArray arrayVarDecl = varDecl->u.declArray;
            string varName = *(arrayVarDecl->id);
            // 检查是否与 member 匹配
            if (varName == member) {
                isMemberFound = true;
                break;
            }
        }
    }
    return isMemberFound;
}

tc_type returnFunctionParameter(const paramMemberMap& func2Param, const std::string& name, const std::string& para) {
    // 首先检查是否存在名称为 name 的函数
    auto it = func2Param.find(name);
    if (it != func2Param.end()) {
        // 如果找到了名为 name 的函数，则检查它是否具有名为 para 的参数
        const std::vector<aA_varDecl>* parameters = it->second;
        if (parameters) {
            for (const auto& param : *parameters) {
                if (param->kind == A_varDeclType::A_varDeclScalarKind && *(param->u.declScalar->id) == para) {
                    aA_type paramType = param->u.declScalar->type;
                    tc_type paramTcType = tc_Type(paramType, 0); // scalar
                    return paramTcType;
                } else if (param->kind == A_varDeclType::A_varDeclArrayKind && *(param->u.declArray->id) == para) {
                    aA_type paramType = param->u.declArray->type;
                    tc_type paramTcType = tc_Type(paramType, 1); // scalar
                    return paramTcType;
                }
            }
        }
    }
    // 如果未找到匹配的函数或参数，则返回 false
    return nullptr;
}

// 检查变量是否被定义
tc_type check_VarExpr(std::ostream& out, A_pos pos, string name, string funcName) {
    tc_type ret = nullptr;
    if (func2Param.find(name) != func2Param.end()) {
        error_print(out, pos, "Func name can't be used as a var");
    }
    if (struct2Members.find(name) != struct2Members.end()) {
        error_print(out, pos, "Struct name can't be used as a var");
    }
    if(!local_token2Type.empty()){
        typeMap lastScopeMap = *local_token2Type.back();
        if (lastScopeMap.find(name) != lastScopeMap.end()){
            ret = lastScopeMap[name];
            return ret;
        }
    }
        if(hasFunctionParameter(func2Param,funcName,name)){
            ret = returnFunctionParameter(func2Param,funcName,name);       
            return ret;
        }

        if (g_token2Type.find(name) != g_token2Type.end()) {
            ret = g_token2Type[name];

        }else {
            error_print(out, pos, "Var " + name + " not declared.");
        }
    
    return ret;
}

bool check_ExprUnitArr(aA_exprUnit eu){
    if(!eu)
        return false;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            string id = *(eu->u.id);
            typeMap lastScopeMap = *local_token2Type.back();
            if(lastScopeMap.find(id) != lastScopeMap.end()) {
                if(lastScopeMap[id]->isVarArrFunc==1){
                    return true;
                }
            }
            else if(hasFunctionParameter(func2Param,cur_fn,id)){
                tc_type type = returnFunctionParameter(func2Param,cur_fn,id);
                if(type->isVarArrFunc==1){
                    return true;
                }
            }
            else {
                if(g_token2Type.find(id) != g_token2Type.end() && lastScopeMap.find(id) == lastScopeMap.end()) {
                    if(g_token2Type[id]->isVarArrFunc==1){
                        return true;
                    }
                }
            }
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            if (eu->u.arithExpr->kind == A_arithExprType::A_exprUnitKind) {
                return check_ExprUnitArr(eu->u.arithExpr->u.exprUnit);
            }
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            return check_ExprUnitArr(eu->u.arithUExpr->expr);
        }
            break;
    }
    return false;
}

tc_type check_ExprUnit(std::ostream& out, aA_exprUnit eu, string funcName){
    // return the aA_type of expr eu
    if(!eu)
        return nullptr;
    tc_type ret;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            /* fill code here */
            string id = *(eu->u.id);
            ret = check_VarExpr(out, eu->pos, id,funcName);
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            aA_type numt = new aA_type_;
            numt->pos = eu->pos;
            numt->type = A_dataType::A_nativeTypeKind;
            numt->u.nativeType = A_nativeType::A_intTypeKind;
            ret = tc_Type(numt, 0);
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            check_FuncCall(out, eu->u.callExpr);
            // check_FuncCall will check if the function is defined
            /* fill code here */
            string name = *eu->u.callExpr->fn;
            paramMemberMap::iterator fn;
            if(func2Param.find(name) != func2Param.end()){
                fn = func2Param.find(name);
            }else{
                error_print(out, eu->pos, "Function does not exist");
            }
            ret = funcparam_token2Type.find(name)->second;
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            check_ArrayExpr(out, eu->u.arrayExpr);
            /* fill code here */
            // string id = *(eu->u.arrayExpr->arr->u.id);
            // ret = check_VarExpr(out, eu->pos, id, funcName);
            string name = *eu->u.arrayExpr->arr->u.id;
            bool is_find = false;
            for(int i = 0; i < local_token2Type.size(); i++){
                if(local_token2Type[i]->find(name) != local_token2Type[i]->end()){
                    is_find = true;
                    ret = tc_Type(local_token2Type[i]->find(name)->second->type, 0);
                    break;
                }
            }
            if (!is_find){
                if(g_token2Type.find(name) != g_token2Type.end()){
                    ret = tc_Type(g_token2Type.find(name)->second->type, 0);
                }
            }
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            ret = check_MemberExpr(out, eu->u.memberExpr, funcName);
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            ret = check_ArithExpr(out, eu->u.arithExpr, funcName);
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            ret = check_ExprUnit(out, eu->u.arithUExpr->expr, funcName);
        }
            break;
    }
    return ret;
}


void check_ArithBiOpExpr(std::ostream& out, aA_arithBiOpExpr ae, tc_type orType) {
    aA_arithExpr left = ae->left;
    if(left->kind == A_arithExprType::A_arithBiOpExprKind) {
        check_ArithBiOpExpr(out, left->u.arithBiOpExpr, orType);
    }
    if(left->kind == A_arithExprType::A_exprUnitKind) {
        tc_type type = check_ExprUnit(out, left->u.exprUnit, "");
        
        if(orType->type->type==A_dataType::A_structTypeKind){
                error_print(out, left->u.exprUnit->pos, "Return value want type: '"+*orType->type->u.structType+"'.");
            }
            // FIXME: 
            // if(orType->type->type == A_dataType::A_nativeTypeKind){
            //     error_print(out, left->u.exprUnit->pos, "Want 'int' type.");
            // }
    }

    aA_arithExpr right = ae->right;
    if(right->kind == A_arithExprType::A_arithBiOpExprKind) {
        check_ArithBiOpExpr(out, right->u.arithBiOpExpr, orType);
    }
    if(right->kind == A_arithExprType::A_exprUnitKind) {
         
        tc_type type = check_ExprUnit(out, right->u.exprUnit, "");
        
        if(!comp_tc_type(type,orType)) {
            if(orType->type->type==A_dataType::A_structTypeKind){
                error_print(out, right->u.exprUnit->pos, "Want type: "+*orType->type->u.structType);
            }
            if(orType->type->type==A_dataType::A_nativeTypeKind){
                error_print(out, right->u.exprUnit->pos, "Want 'int' type.");
            }
        }

    }
}


void check_VarDecl(std::ostream& out, aA_varDeclStmt vd, string funcName)
{
    if (!vd)
        return;
    string name;
    aA_type type = nullptr;     // 初始化为nullptr，表示未知类型
    if (vd->kind == A_varDeclStmtType::A_varDeclKind){
        // decl only
        aA_varDecl vdecl = vd->u.varDecl;
        if(vdecl->kind == A_varDeclType::A_varDeclScalarKind){
            name = *vdecl->u.declScalar->id;
            /* fill code here*/
            // 变量名和函数名同名
            if(g_token2Type.find(name) != g_token2Type.end() && g_token2Type[name]->isVarArrFunc==2){
                error_print(out, vdecl->u.declScalar->pos, "Var " + name + " cannot be the function name.");
            }
            // 判断是否为全局变量
            if (g_token2Type.find(name) != g_token2Type.end()){
                error_print(out, vdecl->u.declScalar->pos, "Var " + name + " exists in global.");
            } else {
                g_token2Type.insert(std::make_pair(name, tc_Type(vdecl)));
            }
            // 已经定义过的局部变量
            if(!local_token2Type.empty()){
                typeMap lastScopeMap = *local_token2Type.back();
                if(lastScopeMap.find(name)!=lastScopeMap.end()){
                        error_print(out, vdecl->u.declScalar->pos, "Var " + name + " has been defined before.");
                }
            }
            // 变量名和参数同名
            if(hasFunctionParameter(func2Param, funcName, name)){
                error_print(out, vdecl->u.declScalar->pos, "Var " + name + " dplicates with function params.");
            }

            if(vdecl->u.declScalar->type!=nullptr){
                if(vdecl->u.declScalar->type->type==A_dataType::A_structTypeKind){
                    string structName = *vdecl->u.declScalar->type->u.structType;
                    if(struct2Members.find(structName)==struct2Members.end()){
                        error_print(out, vdecl->u.declScalar->pos, "Struct " + structName + " is not declared.");    
                    }
                }
            }
            // 检查是否定义类型
            type = vdecl->u.declScalar->type ? vdecl->u.declScalar->type : nullptr;
            if(!type){
                if (vdecl->u.declScalar->type == nullptr) {
                    vdecl->u.declScalar->type = new aA_type_;
                }
                vdecl->u.declScalar->type->type=A_dataType::A_unknownTypeKind;
            }
            
            if (funcName.empty()) {
                // 全局变量
                g_token2Type.insert(std::make_pair(name, tc_Type(vdecl)));
            } else {
                // 局部变量
                if (!local_token2Type.empty()) { 
                    local_token2Type.back()->insert(std::make_pair(name, tc_Type(vdecl)));
                }
            }
            
        } else if (vdecl->kind == A_varDeclType::A_varDeclArrayKind){
            name = *vdecl->u.declArray->id;
            /* fill code here*/
            if(g_token2Type.find(name)!=g_token2Type.end() && g_token2Type[name]->isVarArrFunc==2){
                error_print(out, vdecl->u.declArray->pos, "Var " + name + " cannot be the function name.");
            }
            if (g_token2Type.find(name) != g_token2Type.end()){
                error_print(out, vdecl->u.declArray->pos, "Var " + name + " exists in global.");
            } 

            // 已经定义过的局部变量
            if(!local_token2Type.empty()){
                typeMap lastScopeMap = *local_token2Type.back();
                if(lastScopeMap.find(name)!=lastScopeMap.end()){
                        error_print(out, vdecl->u.declArray->pos, "Var " + name + " has been defined before.");
                }
            }
            // 变量名和参数同名
            if(hasFunctionParameter(func2Param,funcName,name)){
                error_print(out, vdecl->u.declArray->pos, "Var " + name + " dplicates with function params.");
            }

            type = vdecl->u.declArray->type;
            if(vdecl->u.declArray->type != nullptr){
                if(vdecl->u.declArray->type->type == A_dataType::A_structTypeKind){
                    string structName = *vdecl->u.declArray->type->u.structType;
                    if(struct2Members.find(structName) == struct2Members.end()){
                        error_print(out, vdecl->u.declArray->pos, "Struct " + structName + " is not declared.");    
                    }
                }
            }

            arr2Len.insert(make_pair(name, vdecl->u.declArray->len));

            if(!type){
                if (vdecl->u.declArray->type == nullptr) {
                    vdecl->u.declArray->type = new aA_type_;
                }
                vdecl->u.declArray->type->type=A_dataType::A_unknownTypeKind;
            }

            if (funcName.empty()) {
                // 全局变量 
                g_token2Type.insert(std::make_pair(name, tc_Type(vdecl)));
            } else {
                // 局部变量
                if (!local_token2Type.empty()) {
                    local_token2Type.back()->insert(std::make_pair(name, tc_Type(vdecl)));
                }
            }
        }
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind) {
        // decl and def
        aA_varDef vdef = vd->u.varDef;

        name = *vdef->u.defArray->id;
        int len = vdef->u.defArray->len;

        if (vdef->kind == A_varDefType::A_varDefScalarKind) {
            name = *vdef->u.defScalar->id;
            /* fill code here, allow omited type */
            if(g_token2Type.find(name)!=g_token2Type.end() && g_token2Type[name]->isVarArrFunc==2) {
                error_print(out, vdef-> u.defScalar->pos, "Var " + name + " cannot be the function name.");
            }
            if (g_token2Type.find(name) != g_token2Type.end()) {
                error_print(out, vdef->u.defScalar->pos, "Var " + name + " exists in global.");
            } 
            // 已经定义过的局部变量
            if (!local_token2Type.empty()) {
                typeMap lastScopeMap = *local_token2Type.back();
                if (lastScopeMap.find(name) != lastScopeMap.end()) {
                        error_print(out, vdef->u.defScalar->pos, "Var " + name + " has been defined before.");
                }
            }
            // 变量名和参数同名
            if (hasFunctionParameter(func2Param,funcName,name)) {
                error_print(out, vdef->u.defScalar->pos, "Var " + name + " dplicates with function params.");
            }
            type = vdef->u.defScalar->type ? vdef->u.defScalar->type : nullptr;
            aA_rightVal val = vdef->u.defScalar->val;
            // 定义时不能赋值为bool
            if (val->kind == A_rightValType::A_boolExprValKind) {
                error_print(out, val->pos, "Can't be assigned a bool value");
            }
            if (vdef->u.defScalar->type != nullptr) {
                if (vdef->u.defScalar->type->type == A_dataType::A_structTypeKind) {
                    string structName = *vdef->u.defScalar->type->u.structType;
                    if (struct2Members.find(structName) == struct2Members.end()) {
                        error_print(out, vdef->u.defScalar->pos, "Struct " + structName + " is not declared.");    
                    }
                }
            }
            // 判断右侧是否定义或正确
            if (type != nullptr) {
                if (val->kind == A_rightValType::A_arithExprValKind) {
                    aA_arithExpr arExpr=val->u.arithExpr;
                    if (arExpr->kind == A_arithExprType::A_exprUnitKind) {
                        tc_type rType = check_ExprUnit(out, arExpr->u.exprUnit, "");
                        if (!comp_aA_type(type, rType->type) ) {
                            error_print(out, arExpr->pos, "Right-value's type inconsistent with desired type");
                        }
                    }
                    else if (arExpr->kind == A_arithExprType::A_arithBiOpExprKind) {
                        tc_type ty = tc_Type(type, 0);
                        check_ArithBiOpExpr(out, arExpr->u.arithBiOpExpr,ty);
                    }
                }
            }
            
            if (!type) {
                // 暂时将类型设置为一个特殊的未知类型，以便后续的类型检查能够发现这些未定义的变量
                type = new aA_type_;
                type->type = A_dataType::A_unknownTypeKind;
                if (val->u.arithExpr->u.exprUnit->kind == A_exprUnitType::A_numExprKind) {  // 若右侧为int
                    if (vdef->u.defScalar->type == nullptr) {
                        vdef->u.defScalar->type = new aA_type_;
                    }
                    vdef->u.defScalar->type->type = A_dataType::A_nativeTypeKind;
                    type->type = A_dataType::A_nativeTypeKind;  // 直接类型推断为int
                }
            }
            
            if (funcName.empty() ) {
                // 全局变量
                g_token2Type.insert(std::make_pair(name,check_ArithExpr(out, vdef->u.defScalar->val->u.arithExpr, funcName)));
            } else {
                // 局部变量
                if (!local_token2Type.empty() ) {
                    local_token2Type.back()->insert(std::make_pair(name, check_ArithExpr(out, vdef->u.defScalar->val->u.arithExpr, funcName)));
                }
            }

        } else if (vdef->kind == A_varDefType::A_varDefArrayKind){
            name = *vdef->u.defArray->id;
            /* fill code here, allow omited type */
            if(g_token2Type.find(name)!=g_token2Type.end() && g_token2Type[name]->isVarArrFunc==2){
                error_print(out, vdef->u.defScalar->pos, "Var " + name + " cannot be the function name.");
            }
            // 已经定义过的局部变量
            if(!local_token2Type.empty() ){
                typeMap lastScopeMap = *local_token2Type.back();
                if(lastScopeMap.find(name)!=lastScopeMap.end()){
                        error_print(out, vdef->u.defScalar->pos, "Var " + name + " has been defined before.");
                }
            }
            // 变量名和参数同名
            if (hasFunctionParameter(func2Param, funcName,name) ) {
                error_print(out, vdef->u.defScalar->pos, "Var " + name + " dplicates with function params.");

            }
            if (g_token2Type.find(name) != g_token2Type.end() ) {
                error_print(out, vdef->u.defScalar->pos, "Var " + name + " exists in global.");
            } 
            // 定义时数组长度不一致
            if (vdef->u.defArray->vals.size() != len) {
                error_print(out, vdef->u.defScalar->pos, "Can't assign differnt length list to array '" + name + "'.");
            }
            if (vdef->u.defArray->type != nullptr) {
                if (vdef->u.defArray->type->type == A_dataType::A_structTypeKind) {
                    string structName = *vdef->u.defArray->type->u.structType;
                    if (struct2Members.find(structName) == struct2Members.end() ) {
                        error_print(out, vdef->u.defArray->pos, "Struct " + structName + " is not declared.");    
                    }
                }
            }
            arr2Len.insert(make_pair(name, vdef->u.defArray->len));
        }
    }

    if (type == nullptr) {
        // 这里暂时将类型设置为一个特殊的未知类型，以便后续的类型检查能够发现这些未定义的变量
        type = new aA_type_;
        type->type = A_dataType::A_unknownTypeKind;
        // FIXME
        if (val->u.arithExpr->u.exprUnit->kind == A_exprUnitType::A_numExprKind) {  // 若右侧为int
            if (vdef->u.defScalar->type == nullptr) {
                vdef->u.defScalar->type = new aA_type_;
            }
            vdef->u.defScalar->type->type = A_dataType::A_nativeTypeKind;
            type->type = A_dataType::A_nativeTypeKind;  // 直接类型推断为int
        }
    }

    if (funcName.empty()) {
        // 全局变量 
        g_token2Type.insert(std::make_pair(name, tc_Type(type, 0)));
    } else {
        // 局部变量
        if (!local_token2Type.empty()) {
            local_token2Type.back()->insert(std::make_pair(name, tc_Type(type, 0)));
        }
    }

    return;
}


void check_StructDef(std::ostream& out, aA_structDef sd)
{
    if (!sd)
        return;
    string name = *sd->id;
    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, sd->pos, "This id is already defined!");
    struct2Members[name] = &(sd->varDecls);

    vector<aA_varDecl>* varDecls = struct2Members[name];
    // 遍历结构体的每个变量声明
    for (auto varDecl : *varDecls) {
        // 如果变量声明是标量类型
        if (varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
            aA_varDeclScalar scalarVarDecl = varDecl->u.declScalar;
            string varName = *(scalarVarDecl->id);
            // 使用变量名进行进一步处理
            // std::cout << "Variable name: " << varName << std::endl;
        }
        // 如果变量声明是数组类型
        else if (varDecl->kind == A_varDeclType::A_varDeclArrayKind) {
            aA_varDeclArray arrayVarDecl = varDecl->u.declArray;
            string varName = *(arrayVarDecl->id);
            // 使用变量名进行进一步处理
            // std::cout << "Variable name: " << varName << std::endl;
        }
    }

    return;
}


void check_FnDecl(std::ostream& out, aA_fnDecl fd)
{
    if (!fd)
        return;
    string name = *fd->id;

    // if already declared, should match
    if (func2Param.find(name) != func2Param.end()) {
        // is function ret val matches
        /* fill code here */
        // std::cout << "already declared" << std::endl;
        if(!comp_aA_type(func2retType[name]->type, fd->type)){
            error_print(out, fd->pos, "The function return type doesn't match the declaration. ");
        }

        // is function params matches decl
        /* fill code here */
        vector<aA_varDecl> varDecls = fd->paramDecl->varDecls;
        vector<aA_varDecl> vp = *func2Param[name];
        
        aA_type cur;
        aA_type new_cur;
        string name;
        string new_name;

        if (varDecls.size() != vp.size()) {
            error_print(out, fd->pos, "Param number incompatible between define and declare.");
        }
        for (int i = 0; i < varDecls.size(); i++) {
            if (vp[i]->kind != varDecls[i]->kind) {
                error_print(out, fd->pos, "Param mismatch between define and declare.");
            }
            if (vp[i]->kind == A_varDeclType::A_varDeclScalarKind) {
                cur = vp[i]->u.declScalar->type;
                new_cur = varDecls[i]->u.declScalar->type;
                if(cur->type != new_cur->type) {
                    error_print(out, fd->pos, "Param type mismatch between define and declare.");
                }
            }
            if (vp[i]->kind == A_varDeclType::A_varDeclArrayKind) {
                cur = vp[i]->u.declArray->type;
                new_cur = varDecls[i]->u.declArray->type;
                if(cur->type != new_cur->type) {
                    error_print(out, fd->pos, "Param type mismatch between define and declare. ");
                }
            }
            // 检查函数参数是否与变量重名
            if (vp[i]->kind == A_varDeclType::A_varDeclScalarKind) {
                name = *(vp[i]->u.declScalar->id);
                // print_token_maps(); 
                // std::cout << "param name: " << name << std::endl;
                for (auto global_var : g_token2Type) {
                    if (global_var.first == name) {
                        vp[i]->pos->line = fd->pos->line;
                        vp[i]->pos->col -= 2; 
                        error_print(out, vp[i]->pos, "Param name " + name + " conflicts with global variable name.");
                    }
                }
            }
        }

    } else {
        // std::cout << "new declaration" << std::endl; 
        // if not defined
        /* fill code here */
        aA_type type = fd->type;
        tc_type tc= tc_Type(type, 2);  // 2: function
        g_token2Type.insert(make_pair(name, tc)); 
        // print_token_maps();
        
        func2retType.insert(make_pair(name, tc));

        vector<aA_varDecl> vars = fd->paramDecl->varDecls;
        for(auto var : vars) {
            if (var->kind == A_varDeclType::A_varDeclScalarKind) {
                aA_varDeclScalar vds = var->u.declScalar;
                string* id = vds->id;
                if (vds->type->type == 1) { // struct
                // std::cout << "type->type:" << *vds->type->u.structType << std::endl;
                    type = new aA_type_;  
                    type->type = A_dataType::A_structTypeKind;
                    type->u.structType = vds->type->u.structType;
                }
                else if (vds->type->type == 0) { // native
                    type = new aA_type_;  
                    type->type = A_dataType::A_nativeTypeKind;
                    type->u.nativeType = A_nativeType::A_intTypeKind;
                }

            }
            if (var->kind == A_varDeclType::A_varDeclArrayKind) {
                aA_varDeclArray vda = var->u.declArray;
                string* id = vda->id;

                if (vda->type->type == 1) { // struct
                // std::cout << "type->type:" << *vds->type->u.structType << std::endl;
                    type = new aA_type_;  
                    type->type = A_dataType::A_structTypeKind;
                    type->u.structType = vda->type->u.structType;
                }
                else if (vda->type->type == 0) { // native
                    type = new aA_type_;  
                    type->type = A_dataType::A_nativeTypeKind;
                    type->u.nativeType = A_nativeType::A_intTypeKind;
                }
            }
            
        }
        vector<aA_varDecl>* vp = new vector<aA_varDecl>(vars);
        // std::cout << "name:" << name << std::endl;
        func2Param.insert(make_pair(name, vp));
        // printFunctionParameters(func2Param);
        // std::cout << "size:" << func2Param.size() << std::endl;

    }
    return;
}


void check_FnDeclStmt(std::ostream& out, aA_fnDeclStmt fd)
{
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
}


void check_ReturnStmt(std::ostream& out, aA_returnStmt rs){
    if(!rs)
        return;
    // out << "IN check return stmt" << std::endl; 
    // out << "ret val type: " << rs->retVal->kind << std::endl;
    // FIXME: 
    if (rs->retVal->kind == A_rightValType::A_arithExprValKind && rs->retVal->u.arithExpr->kind == A_arithExprType::A_arithBiOpExprKind) {
        // out << "left arith type: " << rs->retVal->u.arithExpr->kind << std::endl;
        if (rs->retVal->u.arithExpr->u.arithBiOpExpr->left != NULL) {
            auto left_expr = rs->retVal->u.arithExpr->u.arithBiOpExpr->left->u.exprUnit;
            // out << "left type" << left_expr->kind << std::endl; 
            switch (left_expr->kind) {
                case A_exprUnitType::A_arithExprKind: {
                    // out << "check return:arith" << std::endl; 
                    check_ArithExpr(out, left_expr->u.arithExpr, cur_fn);
                }
                    break; 
                case A_exprUnitType::A_fnCallKind: {
                    // out << "check return:fnCall" << std::endl;
                    // out << "left func call: " << *left_expr->u.callExpr->fn << std::endl;
                    check_FuncCall(out, left_expr->u.callExpr);
                }
                    break;
                case A_exprUnitType::A_memberExprKind: {
                    // out << "check return:member" << std::endl;
                    check_MemberExpr(out, left_expr->u.memberExpr, cur_fn);
                }
                    break;
                case A_exprUnitType::A_arrayExprKind: {
                    // out << "check return:array" << std::endl;
                    check_ArrayExpr(out, left_expr->u.arrayExpr);
                }
                    break;

                default:
                    break;   
            }
        } 

        if (rs->retVal->u.arithExpr->u.arithBiOpExpr->right != NULL) {
            auto right_expr = rs->retVal->u.arithExpr->u.arithBiOpExpr->right->u.exprUnit;
            switch (right_expr->kind)
            {
                case A_exprUnitType::A_arithExprKind: {
                    // out << "check return:arith" << std::endl; 
                    check_ArithExpr(out, right_expr->u.arithExpr, cur_fn);
                }
                    break; 
                case A_exprUnitType::A_fnCallKind: {
                    // out << "check return:fnCall" << std::endl;
                    check_FuncCall(out, right_expr->u.callExpr);
                }
                    break;
                case A_exprUnitType::A_memberExprKind: {
                    // out << "check return:member" << std::endl;
                    check_MemberExpr(out, right_expr->u.memberExpr, cur_fn);
                }
                    break;
                case A_exprUnitType::A_arrayExprKind: {
                    // out << "check return:array" << std::endl;
                    check_ArrayExpr(out, right_expr->u.arrayExpr);
                }
                    break;
            
            default:
                break;
            }
        }

    }

    return;
}


void check_FnDef(std::ostream& out, aA_fnDef fd)
{
    if (!fd)
        return;
    // should match if declared
    check_FnDecl(out, fd->fnDecl);
    
    // add params to local tokenmap, func params override global ones
    string name=*fd->fnDecl->id;
    cur_fn = name;
    if(defFunc_token2Type.find(name)!=defFunc_token2Type.end()){
        error_print(out, fd->pos, "Function " + name + " cannot be deplicately defined.");
    }

    // add params to local tokenmap, func params override global ones
    local_token2Type.push_back(new typeMap);
    aA_type type = fd->fnDecl->type;
    tc_type tc= tc_Type(type, 2);  // 2表示function
    defFunc_token2Type.insert(make_pair(name, tc));
    
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        /* fill code here */
        // FIXME
        if (vd->kind == A_varDeclType::A_varDeclScalarKind) {
            aA_varDeclScalar vds = vd->u.declScalar;
            string* id = vds->id;
            if (vds->type->type == 1) { // struct
                type = new aA_type_;  
                type->type = A_dataType::A_structTypeKind;
                type->u.structType = vds->type->u.structType;
            }
            else if (vds->type->type == 0) { // native
                type = new aA_type_;  
                type->type = A_dataType::A_nativeTypeKind;
                type->u.nativeType = A_nativeType::A_intTypeKind;
            }
            local_token2Type.back()->insert(make_pair(*id, tc_Type(type, 0)));
        }
    }

    /* fill code here */
    for (aA_codeBlockStmt stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt, name);
        // return value type should match
        /* fill code here */
    }
    return;
}


void check_CodeblockStmt(std::ostream& out, aA_codeBlockStmt cs, string funcName){
    if(!cs)
        return;
    // variables declared in a code block should not duplicate with outer ones.
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt, funcName);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt, funcName);
        break;
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt, funcName);
        break;
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt, funcName);
        break;
    case A_codeBlockStmtType::A_callStmtKind:
        // std::cout << "call stmt" << std::endl;
        check_CallStmt(out, cs->u.callStmt);
        break;
    case A_codeBlockStmtType::A_returnStmtKind:
        // out << "return statement: " << cs->u.returnStmt->pos->line << ":" << cs->u.returnStmt->pos->col << std::endl; 
        // if (cs->u.returnStmt->retVal->u.arithExpr->u.arithBiOpExpr->right) {
        //     out << "return statement: " << cs->u.returnStmt->retVal->u.arithExpr->u.arithBiOpExpr->right->kind << std::endl;
        // }
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }
    return;
}


void check_AssignStmt(std::ostream& out, aA_assignStmt as, string funcName){
    if(!as)
        return;
    string name;
    tc_type deduced_type; // deduced type if type is omitted at decl
    // FIXME
    switch (as->leftVal->kind)
    {
        case A_leftValType::A_varValKind: {
            name = *as->leftVal->u.id;
            /* fill code here */
            // 变量未声明
            typeMap lastScopeMap = *local_token2Type.back();
            if (lastScopeMap.find(name) == lastScopeMap.end() && g_token2Type.find(name) == g_token2Type.end() && (!hasFunctionParameter(func2Param, funcName, name)))
                error_print(out, as->pos, "Var " + name + " is not defined.");
            
            // 变量名和函数名同名
            if (g_token2Type.find(name) != g_token2Type.end() && g_token2Type[name]->isVarArrFunc == 2) {
                error_print(out, as->pos, "Var " + name + " cannot be the function name.");
            }

            if (lastScopeMap.find(name) != lastScopeMap.end()) {
                tc_type type = lastScopeMap[name];
                aA_rightVal rightVal = as->rightVal;
                
                if (rightVal->kind == A_rightValType::A_arithExprValKind) {
                    if (rightVal->u.arithExpr->kind == A_arithExprType::A_exprUnitKind) {
                        tc_type ty = check_ExprUnit(out,rightVal->u.arithExpr->u.exprUnit,"");
                        if (lastScopeMap[name]->isVarArrFunc != ty->isVarArrFunc) {
                            error_print(out, as->pos, "Can't assign to different type.");
                        }
                        
                        if (type->type->type == A_dataType::A_unknownTypeKind) {
                            if (ty->type->type == A_dataType::A_nativeTypeKind) {
                                lastScopeMap[name]->type->type = A_dataType::A_nativeTypeKind;
                            }
                            if (ty->type->type == A_dataType::A_structTypeKind) {
                                lastScopeMap[name]->type->type = A_dataType::A_structTypeKind;
                                lastScopeMap[name]->type->u.structType = ty->type->u.structType;
                            }
                        }
                    }            
                }
            }
        }
            break;
        
        case A_leftValType::A_arrValKind:{
            /* fill code here */
            check_ArrayExpr(out, as->leftVal->u.arrExpr);
            typeMap lastScopeMap = *local_token2Type.back();
            aA_rightVal rightVal = as->rightVal;
            if (rightVal->kind == A_rightValType::A_boolExprValKind) {
                error_print(out, as->pos, "Can't assign a bool value.");
            }

            if (lastScopeMap.find(name) != lastScopeMap.end()) {
                if(rightVal->u.arithExpr->kind == A_arithExprType::A_exprUnitKind) {
                    tc_type ty = check_ExprUnit(out,rightVal->u.arithExpr->u.exprUnit, "");
                    if (lastScopeMap[name]->type->type != ty->type->type) {
                        error_print(out, as->pos, "Can't assign to different type.");
                    }
                    if (lastScopeMap[name]->type->type == A_dataType::A_structTypeKind) {
                        if (*lastScopeMap[name]->type->u.structType != *ty->type->u.structType) {
                            error_print(out, as->pos, "Can't assign type: "+*ty->type->u.structType+" to type: "+*lastScopeMap[name]->type->u.structType);
                        }
                    }
                }  
            }

            if (g_token2Type.find(name) != g_token2Type.end()) {
                if (rightVal->u.arithExpr->kind==A_arithExprType::A_exprUnitKind) {
                    tc_type ty = check_ExprUnit(out, rightVal->u.arithExpr->u.exprUnit, "");
                    if (g_token2Type[name]->type->type != ty->type->type){
                        error_print(out, as->pos, "Can't assign to different type.");
                    }
                    if (g_token2Type[name]->type->type == A_dataType::A_structTypeKind) {
                        if (*g_token2Type[name]->type->u.structType != *ty->type->u.structType) {
                            error_print(out, as->pos, "Can't assign type: "+*ty->type->u.structType+" to type: "+*g_token2Type[name]->type->u.structType);
                        }
                    }
                }
            }
        }
            break;
        
        case A_leftValType::A_memberValKind:{
            /* fill code here */
            typeMap lastScopeMap = *local_token2Type.back();
            name = *as->leftVal->u.memberExpr->structId->u.id;
            // std::cout << "!!funcname: " << funcName << "\t!!name: " << name << std::endl;
            // std::cout << "hasfunpara: " << hasFunctionParameter(func2Param, funcName, name) << std::endl;
            // std::cout << "!!funcparamname: "; 
            // for (auto it : funcparam_token2Type) {
            //     std::cout << it.first << " ";
            // }
            // auto it = func2Param.find(cur_fn); 
            // if (it != func2Param.end()) {
            //     vector<aA_varDecl>* v = it->second;
            //     for (auto i : *v) {
            //         if (i->kind == A_varDeclType::A_varDeclScalarKind) {
            //             std::cout << "**param: " << *i->u.declArray->id << "\ttype:" << i->u.declArray->type << " ";
            //         }
            //     }
            // }
            // std::cout << std::endl;
            if (lastScopeMap.find(name) != lastScopeMap.end() && lastScopeMap[name]->isVarArrFunc != 2) {   // 在局部变量里声明
                for (auto v : lastScopeMap) {
                    // std::cout << "!!localname: "<< v.first << "\tlocaltype: " << v.second->type->type << std::endl;
                    A_dataType v_type = v.second->type->type; 
                    if (funcparam_token2Type.find(name) != funcparam_token2Type.end()) {
                        if (v_type != funcparam_token2Type[name]->type->type) {
                            error_print(out, as->pos, "Can't assign to different type.");
                        }
                    }
                }
                if (lastScopeMap[name]->type->type == A_dataType::A_nativeTypeKind) {
                    error_print(out, as->pos, name + " is not a struct.");
                }
                string structType = *lastScopeMap[name]->type->u.structType;
                vector<aA_varDecl>* varDecls = struct2Members[structType];
                // std::cout << "!!structname:" << structType << std::endl;
                string member;
                // print_token_map(&lastScopeMap);
                member = *as->leftVal->u.memberExpr->memberId;
                // std::cout<<"!!membername:"<<member<<std::endl;
                if ( !findMemberInStruct(member, varDecls) ) {
                    error_print(out, as->pos, "member '" + member + "' is not defined.");
                }
            } else if (g_token2Type.find(name) != g_token2Type.end() ) {    // 在全局变量里声明
                if (g_token2Type[name]->type->type == A_dataType::A_nativeTypeKind) {
                    error_print(out, as->pos, name + " is not a struct.");
                }
                string structType = *g_token2Type[name]->type->u.structType;
                vector<aA_varDecl>* varDecls = struct2Members[structType];
                string member;
                member = *as->leftVal->u.memberExpr->memberId;
                
                if ( !findMemberInStruct(member, varDecls) ) {
                    error_print(out, as->pos, "member '" + member + "' is not defined.");
                }
            } else if ( hasFunctionParameter(func2Param, funcName, name) ) {    // 在函数参数
                // FIXME
                tc_type type = returnFunctionParameter(func2Param, funcName, name);
                if (type->type->type == A_dataType::A_nativeTypeKind) {
                    error_print(out, as->pos, name + " is not a struct.");
                }
                string structType = *type->type->u.structType;
                vector<aA_varDecl>* varDecls = struct2Members[structType];
                string member;
                member = *as->leftVal->u.memberExpr->memberId;
                if ( !findMemberInStruct(member,varDecls) ) {
                    error_print(out, as->pos, "member '" + member + "' is not defined.");
                }
            } else {
                error_print(out, as->pos, "Struct " + name + " is not defined.");
            }
        }
            break;
    }
    return;
}


void check_ArrayExpr(std::ostream& out, aA_arrayExpr ae){
    if(!ae)
        return;
    string name = *ae->arr->u.id;
    // check array name
    /* fill code here */
    if ( !local_token2Type.empty() ) {
        typeMap lastScopeMap = *local_token2Type.back();
        if (lastScopeMap.find(name) == lastScopeMap.end() && g_token2Type.find(name) == g_token2Type.end() ){
           error_print(out, ae->pos, name + " is not declared!");
        }
        if ( lastScopeMap.find(name) != lastScopeMap.end() ){
            // 判断是否给非数组的变量赋值
            if ( lastScopeMap[name]->isVarArrFunc != 1 ){
                error_print(out, ae->pos, name + " is not an array.");
            }
        }
    }
    
    if ( g_token2Type.find(name) != g_token2Type.end() ) {
        // 判断是否给非数组的变量赋值
        if (g_token2Type[name]->isVarArrFunc != 1) {
            error_print(out, ae->pos, name + " is not an array.");
        }
    }
        
    // check index
    /* fill code here */
    if ( ae->idx->kind == A_indexExprKind::A_idIndexKind) {
        string id = *(ae->idx->u.id);
        tc_type type;
        type = check_VarExpr(out, ae->idx->pos, id,"");
        if (type->type->type != A_dataType::A_nativeTypeKind) {
            error_print(out, ae->idx->pos, "Id " + id + " type in array must be int.");
        }
    }

    if (ae->idx->kind == A_indexExprKind::A_numIndexKind) {
        if (arr2Len[name] <= ae->idx->u.num){
            error_print(out, ae->pos, "Exceeds the maximum range of the array.");
        }
        if (ae->idx->u.num < 0) {
            error_print(out, ae->idx->pos, "Num in array must > 0");
        }
    }

    return;
}


tc_type check_MemberExpr(std::ostream& out, aA_memberExpr me, string funcName){
    // check if the member exists and return the tyep of the member
    if(!me)
        return nullptr;
    string name = *me->structId->u.id;
    // check struct name
    /* fill code here */
    tc_type structT = check_VarExpr(out, me->pos, name, funcName);
    if (structT->type->type == A_dataType::A_nativeTypeKind) {
        error_print(out, me->pos, name + " is not a struct.");
    }
    string structType = *(structT->type->u.structType);
    if (struct2Members.find(structType) == struct2Members.end()) { 
        error_print(out, me->pos, "Struct name " + structType + " not exist");
    }
        
    // check member name
    /* fill code here */
    vector<aA_varDecl>* varDecls = struct2Members[structType];
    string member;
    member = *me->memberId;
    
    if (!findMemberInStruct(member, varDecls)) {
        error_print(out, me->pos, "member '" + member + "' is not defined.");
    }
    tc_type ret;

    string cur_id;
    for (auto var : *varDecls) {
        if (var->kind == A_varDeclType::A_varDeclScalarKind) {
            aA_varDeclScalar vds = var->u.declScalar;
            cur_id = *(vds->id);
            if (cur_id == member) {
                ret = tc_Type(vds->type,0);
                return ret;
            }
        }
        if (var->kind == A_varDeclType::A_varDeclArrayKind) {
            aA_varDeclArray vda = var->u.declArray;
            cur_id = *(vda->id);
            if (cur_id == member) {
                ret = tc_Type(vda->type,1);
                return ret;
            }
        }
    }
        
    return nullptr;
}


void check_IfStmt(std::ostream& out, aA_ifStmt is, string funcName){
    if(!is)
        return;

    if ( !local_token2Type.empty() ) {
        local_token2Type.push_back(new typeMap(*local_token2Type.back()));
    } else {
        // 如果 local_token2Type 为空，则创建一个新的 typeMap 并添加到向量中
        local_token2Type.push_back(new typeMap);
    }

    check_BoolUnit(out, is->boolUnit, funcName);
    /* fill code here, take care of variable scope */

    for(aA_codeBlockStmt s : is->ifStmts){
        check_CodeblockStmt(out, s, funcName);
    }
    
    /* fill code here */
    if ( !local_token2Type.empty() ) {
        delete local_token2Type.back(); // 删除最后一个 typeMap 对象
        local_token2Type.pop_back(); // 从向量中删除指向该对象的指针
    }

    if ( !local_token2Type.empty() ) {
        local_token2Type.push_back(new typeMap(*local_token2Type.back()));
    } else {
        // 如果 local_token2Type 为空，则创建一个新的 typeMap 并添加到向量中
        local_token2Type.push_back(new typeMap);
    }

    for(aA_codeBlockStmt s : is->elseStmts){
        check_CodeblockStmt(out, s, funcName);
    }
    /* fill code here */
    if ( !local_token2Type.empty() ) {
        delete local_token2Type.back(); // 删除最后一个 typeMap 对象
        local_token2Type.pop_back(); // 从向量中删除指向该对象的指针
    }

    return;
}


void check_BoolExpr(std::ostream& out, aA_boolExpr be, string funcName){
    if(!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        check_BoolExpr(out, be->u.boolBiOpExpr->left, funcName);
        check_BoolExpr(out, be->u.boolBiOpExpr->right, funcName);
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit, funcName);
        break;
    default:
        break;
    }
    return;
}


void check_BoolUnit(std::ostream& out, aA_boolUnit bu ,string funcName){
    if(!bu)
        return;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
            /* fill code here */
            aA_exprUnit left = bu->u.comExpr->left;
            tc_type type = check_ExprUnit(out, left, funcName);
            if (type->type->type != A_dataType::A_nativeTypeKind) {
                error_print(out, left->pos, "Variable type in comparison must be int.");
            }
            aA_exprUnit right = bu->u.comExpr->right;
            type = check_ExprUnit(out, right, funcName);
            if (type->type->type != A_dataType::A_nativeTypeKind) {
                error_print(out, right->pos, "Variable type in comparison must be int");
            }
        }
            break;
        case A_boolUnitType::A_boolExprKind:
            check_BoolExpr(out, bu->u.boolExpr, funcName);
            break;
        case A_boolUnitType::A_boolUOpExprKind:
            check_BoolUnit(out, bu->u.boolUOpExpr->cond, funcName);
            break;
        default:
            break;
    }
    return;
}


tc_type check_ArithExpr(std::ostream& out, aA_arithExpr ae, string funcName){
    if(!ae)
        return nullptr;
    tc_type ret;
    switch (ae->kind)
    {
        case A_arithExprType::A_arithBiOpExprKind:{
            ret = check_ArithExpr(out, ae->u.arithBiOpExpr->left, funcName);
            tc_type rightTyep = check_ArithExpr(out, ae->u.arithBiOpExpr->right, funcName);
            if(ret->type->type > 0 || ret->type->type != A_dataType::A_nativeTypeKind || ret->type->u.nativeType != A_nativeType::A_intTypeKind ||
            rightTyep->type->type > 0 || rightTyep->type->type != A_dataType::A_nativeTypeKind || rightTyep->type->u.nativeType != A_nativeType::A_intTypeKind)
                error_print(out, ae->pos, "Only int can be arithmetic expression operation values!");
        }
            break;
        case A_arithExprType::A_exprUnitKind:
            ret = check_ExprUnit(out, ae->u.exprUnit, funcName);
            break;
    }
    return ret;
}

void assign_type_check(std::ostream& out, tc_type type, aA_rightVal val) //check whether type of 'type' and 'val' matches, also val validity
{
    // std::cout << "type: " << type->type << std::endl;
    // std::cout << "val: " << val->kind << std::endl;
    if(val->kind == A_rightValType::A_boolExprValKind) {
        error_print(out, val->pos, "Can't be assigned a bool value");
    }

    if(val->kind == A_rightValType::A_arithExprValKind) {
        aA_arithExpr arExp = val->u.arithExpr;
    
        if(arExp->kind == A_arithExprType::A_arithBiOpExprKind) {
            check_ArithBiOpExpr(out, arExp->u.arithBiOpExpr,type);
        }
        if(arExp->kind == A_arithExprType::A_exprUnitKind) {
            tc_type rType = check_ExprUnit(out, arExp->u.exprUnit,"");
            if(!comp_tc_type(type, rType)) {
                error_print(out, arExp->pos, "Para type inconsistent with desired type.");
            }
        }
    }
    return;
}


void assign_arr_check(std::ostream& out, bool isArr, aA_rightVal val) {
    bool check_res = false;

    if(val->kind == A_rightValType::A_arithExprValKind) {
        aA_arithExpr arExp = val->u.arithExpr;
        if(arExp->kind == A_arithExprType::A_exprUnitKind) {
            check_res = check_ExprUnitArr(arExp->u.exprUnit);    
        }
    }
    if(isArr != check_res) {
        error_print(out, val->pos, "Array and Scalar not match");
    }
}


void check_FuncCall(std::ostream& out, aA_fnCall fc){
    if(!fc)
        return;
    // check if function defined
    string func_name = *fc->fn;
    // out << "Func call check. func_name: " << func_name << std::endl;
    
    /* fill code here */
    if (func2Param.find(func_name) == func2Param.end()) {
        error_print(out, fc->pos, "Function name " + func_name + " not defined. ");
    }
    aA_type cur;
    tc_type curType;
    vector<aA_rightVal> vals = fc->vals;
    vector<aA_varDecl> vars = *(func2Param.at(func_name));
    
    // std::cout << "cur: " << cur << "\tcurType: " << curType << std::endl; 
    // for (auto val : vals) { 
    //     std::cout << "val: " << val->pos->col << "\t" << val->kind << "\t"; 
    // }
    // std::cout << std::endl; 
    // for (auto var : vars) {
    //     std::cout << "var: " << var->kind << "\t"; 
    // }
    // std::cout << std::endl;

    if(vals.size() != vars.size()) {
        error_print(out, fc->pos, "Param number incompatible with function " + func_name);
    }
    // check if parameter list matches
    for(int i = 0; i < fc->vals.size(); i++) {
        /* fill code here */
        if (vars[i]->kind == A_varDeclType::A_varDeclScalarKind) {
            cur = vars[i]->u.declScalar->type;
            curType = tc_Type(cur, 0);
            assign_arr_check(out, false, vals[i]);
        }
        if (vars[i]->kind == A_varDeclType::A_varDeclArrayKind) {
            cur = vars[i]->u.declArray->type;
            curType = tc_Type(cur, 1);
            assign_arr_check(out, true, vals[i]);
        }
        assign_type_check(out, curType, vals[i]);
    }
    
    return ;
}


void check_WhileStmt(std::ostream& out, aA_whileStmt ws, string funcName){
    if(!ws)
        return;
    check_BoolUnit(out, ws->boolUnit, funcName);
    /* fill code here, take care of variable scope */
    local_token2Type.push_back(new typeMap(*local_token2Type.back()));

    for(aA_codeBlockStmt s : ws->whileStmts){
        check_CodeblockStmt(out, s, funcName);
    }

    /* fill code here */
    if (!local_token2Type.empty()) {
        delete local_token2Type.back(); // 删除最后一个 typeMap 对象
        local_token2Type.pop_back(); // 从向量中删除指向该对象的指针
    }

    return;
}


void check_CallStmt(std::ostream& out, aA_callStmt cs){
    if(!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}




