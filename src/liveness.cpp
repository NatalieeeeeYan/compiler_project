#include "liveness.h"
#include <unordered_map>
#include <unordered_set>
#include "graph.hpp"
#include "llvm_ir.h"
#include "temp.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

struct inOut {
    TempSet_ in;
    TempSet_ out;
};

struct useDef {
    TempSet_ use;
    TempSet_ def;
};

static unordered_map<GRAPH::Node<LLVMIR::L_block*>*, inOut> InOutTable;
static unordered_map<GRAPH::Node<LLVMIR::L_block*>*, useDef> UseDefTable;

list<AS_operand**> get_all_AS_operand(L_stm* stm) {
    list<AS_operand**> AS_operand_list;
    switch (stm->type) {
        case L_StmKind::T_BINOP: {
            AS_operand_list.push_back(&(stm->u.BINOP->left));
            AS_operand_list.push_back(&(stm->u.BINOP->right));
            AS_operand_list.push_back(&(stm->u.BINOP->dst));

        } break;
        case L_StmKind::T_LOAD: {
            AS_operand_list.push_back(&(stm->u.LOAD->dst));
            AS_operand_list.push_back(&(stm->u.LOAD->ptr));
        } break;
        case L_StmKind::T_STORE: {
            AS_operand_list.push_back(&(stm->u.STORE->src));
            AS_operand_list.push_back(&(stm->u.STORE->ptr));
        } break;
        case L_StmKind::T_LABEL: {
        } break;
        case L_StmKind::T_JUMP: {
        } break;
        case L_StmKind::T_CMP: {
            AS_operand_list.push_back(&(stm->u.CMP->left));
            AS_operand_list.push_back(&(stm->u.CMP->right));
            AS_operand_list.push_back(&(stm->u.CMP->dst));
        } break;
        case L_StmKind::T_CJUMP: {
            AS_operand_list.push_back(&(stm->u.CJUMP->dst));
        } break;
        case L_StmKind::T_MOVE: {
            AS_operand_list.push_back(&(stm->u.MOVE->src));
            AS_operand_list.push_back(&(stm->u.MOVE->dst));
        } break;
        case L_StmKind::T_CALL: {
            AS_operand_list.push_back(&(stm->u.CALL->res));
            for (auto& arg : stm->u.CALL->args) {
                AS_operand_list.push_back(&arg);
            }
        } break;
        case L_StmKind::T_VOID_CALL: {
            for (auto& arg : stm->u.VOID_CALL->args) {
                AS_operand_list.push_back(&arg);
            }
        } break;
        case L_StmKind::T_RETURN: {
            if (stm->u.RET->ret != nullptr)
                AS_operand_list.push_back(&(stm->u.RET->ret));
        } break;
        case L_StmKind::T_PHI: {
            AS_operand_list.push_back(&(stm->u.PHI->dst));
            for (auto& phi : stm->u.PHI->phis) {
                AS_operand_list.push_back(&(phi.first));
            }
        } break;
        case L_StmKind::T_ALLOCA: {
            AS_operand_list.push_back(&(stm->u.ALLOCA->dst));
        } break;
        case L_StmKind::T_GEP: {
            AS_operand_list.push_back(&(stm->u.GEP->new_ptr));
            AS_operand_list.push_back(&(stm->u.GEP->base_ptr));
            AS_operand_list.push_back(&(stm->u.GEP->index));
        } break;
        default: {
            printf("%d\n", (int)stm->type);
            assert(0);
        }
    }
    return AS_operand_list;
}

// 获得所有被赋值的操作数
std::list<AS_operand**> get_def_operand(L_stm* stm) {
    // Todo
    std::list<AS_operand**> operand_list;
    switch(stm->type){
        case L_StmKind::T_BINOP:{
            operand_list.push_back(&(stm->u.BINOP->dst));
            break;
        }
        case L_StmKind::T_LOAD:{
            operand_list.push_back(&(stm->u.LOAD->dst));
            break;
        }
        case L_StmKind::T_STORE:{
            // 可能是NAME
            // def_operands.push_back(&(stm->u.STORE->ptr));
            break;
        }
        case L_StmKind::T_LABEL:{
            break;
        }
        case L_StmKind::T_JUMP:{
            break;
        }
        case L_StmKind::T_CMP:{
            operand_list.push_back(&(stm->u.CMP->dst));
            break;
        }
        case L_StmKind::T_CJUMP:{
            break;
        }
        case L_StmKind::T_MOVE:{
            operand_list.push_back(&(stm->u.MOVE->dst));
            break;
        }
        case L_StmKind::T_CALL:{
            // TODO 是否记录函数返回值写入的寄存器
            break;
        }
        case L_StmKind::T_VOID_CALL:{
            break;
        }
        case L_StmKind::T_RETURN:{
            break;
        }
        case L_StmKind::T_PHI:{
            operand_list.push_back(&(stm->u.PHI->dst));
            break;
        }
        case L_StmKind::T_NULL:{
            break;
        }
        case L_StmKind::T_ALLOCA:{  // 数组的alloca没有被消除
            operand_list.push_back(&(stm->u.ALLOCA->dst));
            break;
        }
        case L_StmKind::T_GEP:{
            operand_list.push_back(&(stm->u.GEP->new_ptr));
            break;
        }
        default: {
            break;
        }
    }

    return operand_list;
}

/**
 * @note 获得语句赋值的寄存器
*/
list<Temp_temp*> get_def(L_stm* stm) {
    auto AS_operand_list = get_def_operand(stm);
    list<Temp_temp*> Temp_list;
    for (auto AS_op : AS_operand_list) {
        Temp_list.push_back((*AS_op)->u.TEMP);
    }
    return Temp_list;
}

std::list<AS_operand**> get_use_operand(L_stm* stm) {
    // Todo
    std::list<AS_operand**> operand_list;
    switch (stm->type) {
        case L_StmKind::T_BINOP: {
            operand_list.push_back(&(stm->u.BINOP->left));
            operand_list.push_back(&(stm->u.BINOP->right));
            break;
        }
        case L_StmKind::T_LOAD: {
            operand_list.push_back(&(stm->u.LOAD->ptr));
            break;
        }
        case L_StmKind::T_STORE: {
            operand_list.push_back(&(stm->u.STORE->src));
            break;
        }
        case L_StmKind::T_LABEL: {
            break;
        }
        case L_StmKind::T_JUMP: {
            break;
        }
        case L_StmKind::T_CMP: {
            operand_list.push_back(&(stm->u.CMP->left));
            operand_list.push_back(&(stm->u.CMP->right));
            break;
        }
        case L_StmKind::T_CJUMP: {
            operand_list.push_back(&(stm->u.CJUMP->dst));
            break;
        }
        case L_StmKind::T_MOVE: {
            operand_list.push_back(&(stm->u.MOVE->src));
            break;
        }
        case L_StmKind::T_CALL: {
            for (int i = 0; i<stm->u.CALL->args.size(); i++) {
                operand_list.push_back(&(stm->u.CALL->args[i]));
            }
            break;
        }
        case L_StmKind::T_VOID_CALL: {
            for (int i = 0; i<stm->u.VOID_CALL->args.size(); i++) {
                operand_list.push_back(&(stm->u.VOID_CALL->args[i]));
            }
            break;
        }
        case L_StmKind::T_RETURN:{
            if (stm->u.RET->ret != nullptr)
                operand_list.push_back(&(stm->u.RET->ret));
            break;
        }
        case L_StmKind::T_PHI:{
            for (int i = 0; i<stm->u.PHI->phis.size(); i++) {
                AS_operand* operand = stm->u.PHI->phis[i].first;
                operand_list.push_back(&(operand));
            }
            break;
        }
        case L_StmKind::T_NULL:{
            break;
        }
        case L_StmKind::T_ALLOCA:{
            break;
        }
        case L_StmKind::T_GEP:{
            operand_list.push_back(&(stm->u.GEP->base_ptr));
            operand_list.push_back(&(stm->u.GEP->index));
            break;
        }
        default: {
            assert(0);
        }
    }

    return operand_list;
}

list<Temp_temp*> get_use(L_stm* stm) {
    auto AS_operand_list = get_use_operand(stm);
    list<Temp_temp*> Temp_list;
    for (auto AS_op : AS_operand_list) {
        if ((*AS_op)->kind == OperandKind::TEMP&&(*AS_op)->u.TEMP->len==0) {  // 否则可能引入立即数
            Temp_list.push_back((*AS_op)->u.TEMP);
        }
    }
    return Temp_list;
}

static void init_INOUT() {
    InOutTable.clear();
    UseDefTable.clear();
}

TempSet_& FG_Out(GRAPH::Node<LLVMIR::L_block*>* r) {
    return InOutTable[r].out;
}
TempSet_& FG_In(GRAPH::Node<LLVMIR::L_block*>* r) {
    return InOutTable[r].in;
}
TempSet_& FG_def(GRAPH::Node<LLVMIR::L_block*>* r) {
    return UseDefTable[r].def;
}
TempSet_& FG_use(GRAPH::Node<LLVMIR::L_block*>* r) {
    return UseDefTable[r].use;
}

// 使用深度优先搜索从根节点遍历所有的节点，从根节点可达的节点颜色设置为color
static void DFS(Node<L_block*>* r, Graph<L_block*>& bg, int color) {
    if(r->color == color)
        return;

    r->color = color;
    for(auto &succ_id: *r->succ()){
        DFS(bg.mynodes[succ_id], bg, color);
    }
}

// 获得每个块对应的使用定义变量
static void Use_def(GRAPH::Node<LLVMIR::L_block*>* r, GRAPH::Graph<LLVMIR::L_block*>& bg, std::vector<Temp_temp*>& args) {
    // TODO
    if (r->color == 1) {
        return;
    }

    // 清空之前的use和def表
    UseDefTable.clear();

    // 遍历图中所有节点
    list<L_stm*> stms = r->nodeInfo()->instrs;
    useDef block_use_def = UseDefTable[r];
    for (L_stm* stm : stms) {
        list<Temp_temp*> used_temps = get_use(stm);
        // 遍历基本块中的每条指令，获取每条指令的def和use操作数，将操作数添加到相应的def或use集合
        for (Temp_temp* used_temp : used_temps) {
            if(block_use_def.def.find(used_temp)!=block_use_def.def.end())
                continue;
            block_use_def.use.emplace(used_temp);
        }

        list<Temp_temp*> def_temps = get_def(stm);
        for (Temp_temp* def_temp : def_temps) {
            // 只有当temp不在def集合中时，才添加到use集合
            if(block_use_def.use.find(def_temp) != block_use_def.use.end())
                continue;
            block_use_def.def.emplace(def_temp);
        }
    }
    UseDefTable[r] = block_use_def;
    r->color = 1;

    // 处理后继块
    for (int succ_id : *r->succ()) {
        Use_def(bg.mynodes[succ_id], bg, args);
    }

    if (r->mykey == 0) {
        // root节点
        DFS(r, bg, 0);
    }

    // 输出每个节点的use和def集合长度
    // for (auto& node_pair : bg.mynodes) {
    //     Node<L_block*>* node = node_pair.second;
    //     L_block* block = node->info;
    //     auto& def = UseDefTable[node].def;
    //     auto& use = UseDefTable[node].use;
    //     cerr << "block " << block->label->name << " def size=" << def.size()
    //          << " use size=" << use.size() << endl;
    // }
}

static int gi = 0;
static bool LivenessIteration(GRAPH::Node<LLVMIR::L_block*>* r, GRAPH::Graph<LLVMIR::L_block*>& bg) {
    // Todo
    bool ret = false;
    for(auto pair:bg.mynodes){
        if(pair.second!=nullptr&&pair.second->nodeInfo()!=nullptr){
            Node<L_block*>* node = pair.second;
            inOut block_in_out = InOutTable[node];
            useDef block_use_def = UseDefTable[node];

            // cerr << "block_num=" << block_num << endl;
            // cerr << "block_sucessor_num=" << block->succs.size() << endl;

            // For each successor, add its in to current out
            for(int succ_id:*node->succ()){
                Node<L_block*>* succ = bg.mynodes[succ_id];
                TempSet unionSet = TempSet_union(&(block_in_out.out), &(InOutTable[succ].in));
                block_in_out.out = *unionSet;
                delete unionSet;
            }

            TempSet diffSet = TempSet_diff(&(block_in_out.out), &(block_use_def.def));
            int original_size = block_in_out.in.size();
            block_in_out.in = *(TempSet_union(&(block_in_out.in), diffSet));
            if(block_in_out.in.size()>original_size)
                ret = true;
            delete diffSet;
            
            InOutTable[node] = block_in_out;
            UseDefTable[node] = block_use_def;
        }
    }
    return ret;
}

void PrintTemps(FILE *out, TempSet set) {
    for(auto x:*set){
        printf("%d  ",x->num);
    }
}


void Show_Liveness(FILE* out, GRAPH::Graph<LLVMIR::L_block*>& bg) {
    fprintf(out, "\n\nNumber of iterations=%d\n\n", gi);
    for(auto block_node:bg.mynodes){
        fprintf(out, "----------------------\n");
        printf("block %s \n",block_node.second->info->label->name.c_str());
        fprintf(out, "def=\n"); PrintTemps(out, &FG_def(block_node.second)); fprintf(out, "\n");
        fprintf(out, "use=\n"); PrintTemps(out, &FG_use(block_node.second)); fprintf(out, "\n");
        fprintf(out, "In=\n");  PrintTemps(out, &FG_In(block_node.second)); fprintf(out, "\n");
        fprintf(out, "Out=\n"); PrintTemps(out, &FG_Out(block_node.second)); fprintf(out, "\n");
    }
}
// 以block为单位
void Liveness(GRAPH::Node<LLVMIR::L_block*>* r, GRAPH::Graph<LLVMIR::L_block*>& bg, std::vector<Temp_temp*>& args) {
    init_INOUT();
    Use_def(r, bg, args);

    // 初始化IN
    for(auto pair:bg.mynodes){
        if(pair.second!=nullptr&&pair.second->nodeInfo()!=nullptr&&UseDefTable.find(pair.second)!=UseDefTable.end()){
            InOutTable[pair.second].in = UseDefTable[pair.second].use;
        }
    }

    gi = 0;
    bool changed = true;
    while (changed)
        changed = LivenessIteration(r, bg);
}
