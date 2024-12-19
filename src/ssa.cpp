#include "ssa.h"
#include <cassert>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "bg_llvm.h"
#include "graph.hpp"
#include "liveness.h"
#include "printLLVM.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;
struct imm_Dominator {
    LLVMIR::L_block* pred;
    unordered_set<LLVMIR::L_block*> succs;
};

unordered_map<L_block*, unordered_set<L_block*>> dominators;
unordered_map<L_block*, imm_Dominator> tree_dominators;
unordered_map<L_block*, unordered_set<L_block*>> DF_array;
unordered_map<L_block*, Node<LLVMIR::L_block*>*> revers_graph;
// 寄存器到操作数的映射
unordered_map<Temp_temp*, AS_operand*> temp2ASoper;

static void init_table() {
    dominators.clear();
    tree_dominators.clear();
    DF_array.clear();
    revers_graph.clear();
    temp2ASoper.clear();
}

LLVMIR::L_prog* SSA(LLVMIR::L_prog* prog) {
    for (auto& fun : prog->funcs) {
        init_table();
        combine_addr(fun);  // 把Orpand的相同内容合并成一个地址
        mem2reg(fun);   // 把mem里面可以用reg的变量替换掉，替换了一些load和store变成move
        auto RA_bg = Create_bg(fun->blocks);    // 建图
        // Show_graph(stdout,RA_bg);
        SingleSourceGraph(RA_bg.mynodes[0], RA_bg,fun);     // 删掉图中从根不可到达的block
        // Show_graph(stdout,RA_bg);

        Liveness(RA_bg.mynodes[0], RA_bg, fun->args);   // 迭代计算每个点进入和输出的活跃变量集合
        // Show_Liveness(stderr, RA_bg);
        Dominators(RA_bg);  // 计算支配集
        // printf_domi();   
        tree_Dominators(RA_bg); // 构造支配树
        // printf_D_tree();
        // 默认0是入口block
        computeDF(RA_bg, RA_bg.mynodes[0]);     // 计算支配边界
        // printf_DF();
        Place_phi_fu(RA_bg, fun);   // 插入phi函数
        Rename(RA_bg);
        combine_addr(fun);
    }
    return prog;
}

// 判断一条语句是否是alloc且是否是分配在栈上
static bool is_mem_variable(L_stm* stm) {
    return stm->type == L_StmKind::T_ALLOCA && stm->u.ALLOCA->dst->kind == OperandKind::TEMP && stm->u.ALLOCA->dst->u.TEMP->type == TempType::INT_PTR && stm->u.ALLOCA->dst->u.TEMP->len == 0;
}

// 保证相同的AS_operand地址一样，常量除外
void combine_addr(LLVMIR::L_func* fun) {
    unordered_map<Temp_temp*, unordered_set<AS_operand**>> temp_set;
    unordered_map<Name_name*, unordered_set<AS_operand**>> name_set;
    for (auto& block : fun->blocks) {
        for (auto& stm : block->instrs) {
            auto AS_operand_list = get_all_AS_operand(stm);
            for (auto AS_op : AS_operand_list) {
                if ((*AS_op)->kind == OperandKind::TEMP) {
                    temp_set[(*AS_op)->u.TEMP].insert(AS_op);
                } else if ((*AS_op)->kind == OperandKind::NAME) {
                    name_set[(*AS_op)->u.NAME].insert(AS_op);
                }
            }
        }
    }
    for (auto temp : temp_set) {
        AS_operand* fi_AS_op = **temp.second.begin();
        for (auto AS_op : temp.second) {
            *AS_op = fi_AS_op;
        }
    }
    for (auto name : name_set) {
        AS_operand* fi_AS_op = **name.second.begin();
        for (auto AS_op : name.second) {
            *AS_op = fi_AS_op;
        }
    }
}

void mem2reg(LLVMIR::L_func* fun) {
    // Todo
    // Step 1: 将栈上的变量替换成寄存器
    for(auto block : fun->blocks){
        for(auto it = block->instrs.begin(); it!=block->instrs.end(); it++){
            L_stm* stm = *it;
            if(is_mem_variable(stm)){
                Temp_temp *new_temp = Temp_newtemp_int();
                AS_operand *new_oper = AS_Operand_Temp(new_temp);
                // 将旧的temp映射到新的temp
                temp2ASoper[stm->u.ALLOCA->dst->u.TEMP] = new_oper;
                // 默认值为0
                *it = L_Move(AS_Operand_Const(0), new_oper);
            }
        }
    }

    // Step 2: 记录将栈上的标量load的寄存器，在普通语句中替换
    unordered_map<Temp_temp*, AS_operand*> loadTemp2ASOper;

    for(auto block : fun->blocks){
        for(auto it = block->instrs.begin(); it!=block->instrs.end(); ){
            L_stm* stm = *it;
            switch(stm->type){
                case L_StmKind::T_STORE:{
                    AS_operand* ptr = stm->u.STORE->ptr;
                    AS_operand* src = stm->u.STORE->src;
                    if(src->kind==OperandKind::TEMP && src->u.TEMP->type==TempType::INT_TEMP && loadTemp2ASOper.find(src->u.TEMP)!=loadTemp2ASOper.end()){
                        src = loadTemp2ASOper[src->u.TEMP];
                        stm->u.STORE->src = src;
                    }
                    if(ptr->kind==OperandKind::TEMP && ptr->u.TEMP->type==TempType::INT_PTR && ptr->u.TEMP->len==0 && temp2ASoper.find(ptr->u.TEMP) != temp2ASoper.end()){
                        *it = L_Move(src, temp2ASoper[ptr->u.TEMP]);
                    }
                    break;
                }
                case L_StmKind::T_LOAD:{
                    AS_operand* dst = stm->u.LOAD->dst;
                    AS_operand* ptr = stm->u.LOAD->ptr;
                    if(ptr->kind==OperandKind::TEMP && ptr->u.TEMP->type == TempType::INT_PTR && ptr->u.TEMP->len == 0 
                       && (temp2ASoper.find(ptr->u.TEMP) != temp2ASoper.end())){
                        if(dst->kind==OperandKind::TEMP){
                            loadTemp2ASOper[dst->u.TEMP] = temp2ASoper[ptr->u.TEMP];
                            auto old_it = it;
                            it++;
                            block->instrs.erase(old_it);
                            continue;
                        }
                        else{
                            assert(0);
                        }
                    }
                    break;
                }
                default:{
                    list<AS_operand**> as_list = get_all_AS_operand(stm);
                    for(auto as : as_list){
                        AS_operand *oper = *as;
                        if(oper->kind==OperandKind::TEMP && oper->u.TEMP->type==TempType::INT_TEMP && loadTemp2ASOper.find(oper->u.TEMP)!=loadTemp2ASOper.end()){
                            *as = loadTemp2ASOper[oper->u.TEMP];
                        }
                    }
                    break;
                }
            }

            it++;
        }
    }

}

void Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg) {
    // Todo
    // 所有基本块的集合，用于初始化
    std::unordered_set<L_block*> allBlocks;
    for (auto& node_pair : bg.mynodes) {
        allBlocks.insert(node_pair.second->info);
    }

    // 初始化dominators集合
    for (auto& node_pair : bg.mynodes) {
        L_block* block = node_pair.second->info;
        if (node_pair.second->preds.empty()) {
            // 入口节点，只支配自己
            dominators[block].insert(block);
        } else {
            // 其他节点，初始假设所有节点都是支配节点。//
            dominators[block] = allBlocks;
        }
    }
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto& node_pair : bg.mynodes) {
            L_block* block = node_pair.second->info;
            if (node_pair.second->preds.empty())
                continue;  // 跳过入口节点

            std::unordered_set<L_block*> intersection;
            bool first = true;
            // 计算所有前驱的交集
            for (auto pred : node_pair.second->preds) {
                L_block* pred_block = bg.mynodes[pred]->info;
                if (first) {
                    intersection = dominators[pred_block];  // intersection
                    first = false;  // 初始化为第一个前驱的支配集。
                } else {
                    std::unordered_set<L_block*> temp_intersection;
                    // 迭代第一个集合的每一个元素
                    for (auto element : intersection) {
                        // 检查这个元素是否也存在于第二个集合中
                        if (dominators[pred_block].find(element) != dominators[pred_block].end()) {
                            // 如果存在，添加到临时交集容器中
                            temp_intersection.insert(element);
                        }
                    }
                    // 将新计算的交集结果赋值给 intersection
                    intersection = std::move(temp_intersection);
                }
            }
            // 将自身添加到交集中
            intersection.insert(block);
            
            // 如果计算得到的新支配集合与旧的不同，更新并标记已改变
            if (dominators[block] != intersection) {
                dominators[block] = intersection;
                changed = true;  // 只要这一轮存在node的dominator集合改变，就标记为true
            }
        }
    }
}

void printf_domi() {
    printf("Dominator:\n");
    for (auto x : dominators) {
        printf("%s :\n", x.first->label->name.c_str());
        for (auto t : x.second) {
            printf("%s ", t->label->name.c_str());
        }
        printf("\n\n");
    }
}

void printf_D_tree() {
    printf("dominator tree:\n");
    for (auto x : tree_dominators) {
        printf("%s :\n", x.first->label->name.c_str());
        for (auto t : x.second.succs) {
            printf("%s ", t->label->name.c_str());
        }
        printf("\n\n");
    }
}
void printf_DF() {
    printf("DF:\n");
    for (auto x : DF_array) {
        printf("%s :\n", x.first->label->name.c_str());
        for (auto t : x.second) {
            printf("%s ", t->label->name.c_str());
        }
        printf("\n\n");
    }
}

void tree_Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg) {
    // Todo
    // 初始化支配树映射
    for (auto& node_pair : bg.mynodes) {
        L_block* block = node_pair.second->info;
        if (dominators[block].size() == 1) {
            // 如果该节点只支配自己，它可能是起始节点s0
            tree_dominators[block].pred = nullptr;
            continue;
        }

        // 寻找当前节点的直接必经节点
        L_block* idom_candidate = nullptr;
        for (auto& dom : dominators[block]) {
            if (dom == block)
                continue;  // 跳过自身

            // 不是block其他必经节点的必经节点
            bool isImmediate = true;
            for (auto& other_dom : dominators[block]) {
                if (other_dom != dom && other_dom != block &&
                    dominators[other_dom].find(dom) !=
                        dominators[other_dom].end()) {
                    isImmediate = false;
                    break;
                }
            }

            if (isImmediate) {
                idom_candidate = dom;
                break;
            }
        }

        // 设置当前节点的直接必经节点
        if (idom_candidate) {
            tree_dominators[block].pred = idom_candidate;
            tree_dominators[idom_candidate].succs.insert(block);
        }
    }
}

// 计算支配边界
void computeDF(GRAPH::Graph<LLVMIR::L_block*>& bg, GRAPH::Node<LLVMIR::L_block*>* r) {
    unordered_set<L_block*> s= unordered_set<L_block*>();

    // 计算 DF_local[n]
    for (int succ_id : *r->succ()) {
        Node<L_block*>* node = bg.mynodes[succ_id];
        imm_Dominator idom = tree_dominators[node->nodeInfo()];
        if(idom.pred != r->nodeInfo()){
            s.emplace(node->nodeInfo());
        }
    }

    imm_Dominator idom = tree_dominators[r->nodeInfo()];
    
    // 递归遍历所有子节点（直接必经节点的后继）
    for( L_block* succ : idom.succs) {
        int succ_id = bg.findNode(succ);
        if(succ_id == -1){
            assert(0);
        }
        computeDF(bg, bg.mynodes[succ_id]);
        unordered_set<L_block*> c_df_array = DF_array[succ];
        // 综合子节点的 DF 到当前节点
        for(L_block* c_df:c_df_array){
            if(dominators[c_df].find(r->nodeInfo()) == dominators[c_df].end() || r->nodeInfo() == c_df){
                s.emplace(c_df);
            }
        }
    }

    // 存储当前节点的支配边界
    DF_array[r->nodeInfo()] = s;
}

// 获得一条语句中所有定义的int标量操作数
static list<AS_operand**> get_def_int_operand(LLVMIR::L_stm* stm) {
    list<AS_operand**> ret1 = get_def_operand(stm), ret2;
    for (auto AS_op : ret1) {
        if ((**AS_op).kind == OperandKind::TEMP && (**AS_op).u.TEMP->type == TempType::INT_TEMP) {
            ret2.push_back(AS_op);
        }
    }
    return ret2;
}

// 获得一条语句中所有使用的int标量操作数
static list<AS_operand**> get_use_int_operand(LLVMIR::L_stm* stm) {
    list<AS_operand**> ret1 = get_use_operand(stm), ret2;
    for (auto AS_op : ret1) {
        if ((**AS_op).kind == OperandKind::TEMP && (**AS_op).u.TEMP->type == TempType::INT_TEMP) {
            ret2.push_back(AS_op);
        }
    }
    return ret2;
}

// 插入Phi，只对标量做
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block*>& bg, L_func* fun) {
    unordered_map<L_block*, unordered_set<AS_operand*>> A_orig;
    unordered_map<AS_operand*, unordered_set<L_block*>> defsites;
    unordered_map<L_block*, unordered_set<AS_operand*>> A_phi;

    // 求A_orig
    for (auto pair : bg.mynodes) {
        L_block* block = pair.second->nodeInfo();
        for (L_stm* stm : block->instrs) {
            list<AS_operand**> def_operands = get_def_int_operand(stm);
            for (AS_operand** def_operand : def_operands) {
                auto it = std::find_if(temp2ASoper.begin(), temp2ASoper.end(), [&](const auto &pair)
                                       { return pair.second == *def_operand; });
                if (it != temp2ASoper.end()) {
                    A_orig[block].emplace(*def_operand);
                }
            }
        }
    }

    // 计算defsites
    for (auto pair : A_orig) {
        L_block* block = pair.first;
        for(AS_operand* operand:pair.second){
            defsites[operand].emplace(block);
        }
    }

    // 插入phi语句
    for (auto pair : defsites) {
        AS_operand* a = pair.first;
        unordered_set<L_block*> w = pair.second;
        while (w.size() > 0) {
            L_block* n = w.extract(w.begin()).value();
            w.erase(n);
            unordered_set<L_block*> df_array = DF_array[n];

            for (L_block* y : df_array) {
                if(A_phi[y].find(a)==A_phi[y].end()){
                    int node_id = bg.findNode(y);
                    Node<L_block*>* y_node = bg.mynodes[node_id];

                    std::vector<std::pair<AS_operand*, Temp_label*>> phis;
                    for(int pred_id:*y_node->pred()){
                        Node<L_block*>* pred = bg.mynodes[pred_id];
                        phis.push_back({a, pred->nodeInfo()->label});
                    }
                    L_stm* first_stm = y->instrs.front();
                    if(first_stm->type==L_StmKind::T_LABEL){
                        y->instrs.pop_front();
                    }
                    y->instrs.push_front(L_Phi(a, phis));
                    if(first_stm->type==L_StmKind::T_LABEL){
                        y->instrs.push_front(first_stm);
                    }

                    A_phi[y].emplace(a);
                    if(A_orig[y].find(a)==A_orig[y].end()){
                        w.emplace(y);
                    }
                }
            }
        }
    }
}

// 寄存器重命名
static void Rename_temp(GRAPH::Graph<LLVMIR::L_block*>& bg, GRAPH::Node<LLVMIR::L_block*>* n, unordered_map<Temp_temp*, stack<Temp_temp*>> Stack) {
    // Todo
    // 遍历当前基本块中的每条指令
    for (L_stm* stm : n->nodeInfo()->instrs) {
        if (stm->type != L_StmKind::T_PHI) {
            // 对于每个指令的使用的变量，重命名它们
            // cerr << "instr:" << instr->toString() << endl;
            // if (instr->type == L_StmKind::T_MOVE) {
            //     cerr << "move" << endl;
            //     printL_oper(cerr, instr->u.MOVE->src);cerr<<" ";
            //     printL_oper(cerr, instr->u.MOVE->dst);cerr<<endl;
            // }
            list<AS_operand**> used_operands = get_use_int_operand(stm);
            for (AS_operand** used_operand : used_operands) {
                // cerr << "used_operand:" << (*used_operand)->u.TEMP->num;
                if (Stack.find((*used_operand)->u.TEMP) != Stack.end()) {
                    *used_operand = AS_Operand_Temp(Stack[(*used_operand)->u.TEMP].top());
                    // 只改变num，其他属性不变
                    // cerr << ", newTemp:" << used_operand->u.TEMP->num << endl;
                }
            }
        }
        list<AS_operand**> def_operands = get_def_int_operand(stm);
        for (AS_operand** def_operand : def_operands) {
            // cerr << "def_operand:" << (*def_operand)->u.TEMP->num;
            if (Stack.find((*def_operand)->u.TEMP) != Stack.end()) {
                Temp_temp* new_temp = Temp_newtemp_int();  // 创建新的临时变量
                Stack[(*def_operand)->u.TEMP].push(new_temp);
                *def_operand = AS_Operand_Temp(new_temp);
                // cerr << ", " << Stack[def_operand->u.TEMP].top()->num<<")" << endl;
                // cerr << ", newTemp:" << def_operand->num << endl;
            }
        }
    }
    
    // phi参数的重命名
    for(int succ_id : *n->succ()){
        Node<L_block*>* succ = bg.mynodes[succ_id];
        // 记录n是succ的第几个前驱
        int loc = 0;
        for(int pred_id:*succ->pred()){
            Node<L_block*>* pred = bg.mynodes[pred_id];
            if(n==pred)
                break;
            
            loc++;
        }

        // 递归处理n的每一个子结点，即支配树的后继
        for(L_stm* stm : succ->nodeInfo()->instrs){
            if(stm->type==L_StmKind::T_PHI){
                Temp_temp* old_temp = stm->u.PHI->phis[loc].first->u.TEMP;
                stm->u.PHI->phis[loc].first = AS_Operand_Temp(Stack[old_temp].top());
            }
        }
    }

    imm_Dominator idom = tree_dominators[n->nodeInfo()];
    // 当前基本块处理完毕后，从栈中移除本基本块中定义的所有变量
    for(L_block* succ:idom.succs){
        int node_id = bg.findNode(succ);
        Rename_temp(bg, bg.mynodes[node_id], Stack);
    }
}

// 寄存器重命名，只初始化，具体由Rename_Temp实现
void Rename(GRAPH::Graph<LLVMIR::L_block*>& bg) {
    // Todo
    // 初始化
    unordered_map<Temp_temp*, stack<Temp_temp*>> stack;
    for (auto pair : temp2ASoper) {
        stack[pair.second->u.TEMP].push(pair.second->u.TEMP);
    }
    Rename_temp(bg, bg.mynodes[0], stack);
}
