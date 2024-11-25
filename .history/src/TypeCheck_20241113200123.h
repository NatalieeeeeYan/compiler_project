#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "TeaplAst.h"
#include "TeaplaAst.h"
#include <unordered_map>

// token id to token type, including function name to return type
typedef struct tc_type_* tc_type;
typedef std::unordered_map<string, tc_type> typeMap; 
typedef std::unordered_map<string,int> intMap;

// func name to params
typedef std::unordered_map<string, vector<aA_varDecl>*> paramMemberMap; 

void check_Prog(std::ostream& out, aA_program p);
void check_VarDecl(std::ostream& out, aA_varDeclStmt vd, string funcName);
void check_StructDef(std::ostream& out, aA_structDef sd);
void check_FnDecl(std::ostream& out, aA_fnDecl fd);
void check_FnDeclStmt(std::ostream& out, aA_fnDeclStmt fd);
void check_FnDef(std::ostream& out, aA_fnDef fd);
void check_CodeblockStmt(std::ostream& out, aA_codeBlockStmt cs, string funcName);
void check_AssignStmt(std::ostream& out, aA_assignStmt as, string funcName);
void check_ArrayExpr(std::ostream& out, aA_arrayExpr ae);
tc_type check_MemberExpr(std::ostream& out, aA_memberExpr me, string funcName);
void check_IfStmt(std::ostream& out, aA_ifStmt is, string funcName);
void check_BoolExpr(std::ostream& out, aA_boolExpr be, string funcName);
void check_BoolUnit(std::ostream& out, aA_boolUnit bu, string funcName);
tc_type check_ExprUnit(std::ostream& out, aA_exprUnit eu, string funcName);
tc_type check_ArithExpr(std::ostream& out, aA_arithExpr ae, string funcName);
void check_FuncCall(std::ostream& out, aA_fnCall fc);
void check_WhileStmt(std::ostream& out, aA_whileStmt ws, string funcName);
void check_CallStmt(std::ostream& out, aA_callStmt cs);
void check_ReturnStmt(std::ostream& out, aA_returnStmt rs);

struct tc_type_{
    aA_type type;
    uint isVarArrFunc; // 0 for scalar, 1 for array, 2 for function
};

tc_type tc_Type(aA_type t, uint isVarArrFunc);

void print_token_map(typeMap* map);
bool hasFunctionParameter(const paramMemberMap& func2Param, const std::string& name, const std::string& para);
void check_ArithBiOpExpr(std::ostream& out, aA_arithBiOpExpr ae,tc_type orType);
void printFunctionParameters(const paramMemberMap& func2Param);
void printLastTypeMap(const vector<typeMap*>& local_token2Type);
tc_type returnFunctionParameter(const paramMemberMap& func2Param, const std::string& name, const std::string& para);

void addToLastScope(const string& paramName, tc_type paramType);
bool findMemberInStruct(string member, vector<aA_varDecl>* varDecls);
tc_type check_VarExpr(std::ostream& out, A_pos pos, string name,string funcName);
void add_VarDecl(aA_varDeclStmt vd, bool global, vector<string>* s);

void print_token_map(typeMap* map);
void print_token_maps();
void error_print(std::ostream& out, A_pos p, string info);
bool comp_aA_type(aA_type target, aA_type t);
bool comp_tc_type(tc_type target, tc_type t);
