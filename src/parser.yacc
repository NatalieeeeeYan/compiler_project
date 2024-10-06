%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

%union {
  A_pos pos;
  A_tokenId tokenId;
  A_tokenNum tokenNum;
  A_type type;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_structDef structDef;
  A_varDeclStmt varDeclStmt;
  A_fnDeclStmt fnDeclStmt;
  A_fnDef fnDef;

  A_tokenId id;
  A_tokenNum num;
  A_fnCall fnCall;
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_assignStmt assignStmt;
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_rightValList rightValList;
  A_varDecl varDecl;
  A_varDeclList varDeclList;
  A_varDef varDef;
  A_type type;
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  A_codeBlockStmtList codeBlockStmtList;
  A_codeBlockStmt codeBlockStmt;
}

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> SEMICOLON // ;

%token <pos> COLON // :
%token <pos> COMMA // ,

%token <id> ID
%token <num> NUM
%token <pos> LPAR // (
%token <pos> RPAR // )
%token <pos> LBRA // [
%token <pos> RBRA // ]
%token <pos> DOT // .

%token <pos> AND
%token <pos> OR

%token <pos> GE  // A_ge
%token <pos> LE // A_le
%token <pos> EQUAL  // A_eq
%token <pos> NE  // A_ne
%token <pos> GT  // A_gt
%token <pos> LT  // A_lt
%token <pos> NOT  // !

%token <pos> ASSIGN // =

%token <pos> LET
%token <pos> IF
%token <pos> ELSE
%token <pos> WHILE
%token <pos> BREAK
%token <pos> CONTINUE
%token <pos> RET
%token <pos> FN
%token <pos> STRUCT
%token <pos> INT
%token <pos> ARR
%token <pos> LCUR
%token <pos> RCUR

%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef

%type <fnCall> FnCall
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
// %type <assignStmt> AssignStmt
%type <rightVal> RightVal
%type <leftVal> LeftVal
%type <rightValList> RightValList
%type <varDeclList> VarDeclList
%type <varDecl> VarDecl
%type <varDef> VarDef
%type <fnDecl> FnDecl
%type <paramDecl> ParamDecl
%type <codeBlockStmtList> CodeBlockStmtList
%type <codeBlockStmt> CodeBlockStmt
%type <type> Type

%left SEMICOLON
%left COMMA
%left WHILE
%left IF
%left ELSE
%left ID
%left ASSIGN
%left OR
%left AND
%left LT LE GT GE EQUAL NE
%left ADD SUB
%left MUL DIV
%right NOT NEG
%right LBRA
%left RBRA
%left DOT
%right LPAR
%left RPAR

%start Program

%%                   /* beginning of rules section */

Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = nullptr;
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_ProgramNullStmt($1);
}
;


ArithExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

ExprUnit : NUM
{
  $$ = A_NumExprUnit($1->pos, $1->num);
}
| ID
{
  $$ = A_IdExprUnit($1->pos, $1->id);
}
| LPAR ArithExpr RPAR
{
  $$ = A_ArithExprUnit($1, $2);
}
| FnCall
{
  $$ = A_CallExprUnit($1->pos, $1);
}
| LeftVal LBRA ID RBRA
{
  $$ = A_ArrayExprUnit($1->pos, A_ArrayExpr($1->pos, $1, A_IdIndexExpr($1->pos, $3->id)));
}
| LeftVal LBRA NUM RBRA
{
  $$ = A_ArrayExprUnit($1->pos, A_ArrayExpr($1->pos, $1, A_NumIndexExpr($1->pos, $3->num)));
}
| LeftVal DOT ID
{
  $$ = A_MemberExprUnit($1->pos, A_MemberExpr($1->pos, $1, $3->id));
}
| SUB ExprUnit
{
  $$ = A_ArithUExprUnit($1, A_ArithUExpr($1, A_neg ,$2));
}
;

BoolExpr : BoolExpr AND BoolExpr
{
 $$ = A_BoolBiOp_Expr($1->pos,A_BoolBiOpExpr($1->pos,A_and,$1,$3));
}
| BoolExpr OR  BoolExpr
{
  $$ = A_BoolBiOp_Expr($1->pos,A_BoolBiOpExpr($1->pos,A_or,$1,$3));
}
| BoolUnit
{
  $$ = A_BoolExpr($1->pos,$1);  // qiguai
}
;

BoolUnit : ExprUnit GT  ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_gt, $1, $3));
}
| ExprUnit LT ExprUnit  
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_lt, $1, $3));
}
| ExprUnit GE ExprUnit  
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_ge, $1, $3));
}
| ExprUnit LE ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_le, $1, $3));
}
| ExprUnit EQUAL ExprUnit  
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_eq, $1, $3));
}
| ExprUnit NE ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_ne, $1, $3));
}
| LPAR BoolExpr RPAR 
{
  $$ = A_BoolExprUnit($1, $2);
}
| NOT BoolUnit 
{
  $$ = A_BoolUOpExprUnit($1, A_BoolUOpExpr($1, A_not, $2));
}
;


LeftVal : ID
{
  $$ = A_IdExprLVal($1->pos,$1->id);
}
| LeftVal LBRA ID RBRA
{
  $$ = A_ArrExprLVal($1->pos,A_ArrayExpr($1->pos,$1,A_IdIndexExpr($3->pos,$3->id)));
}
| LeftVal LBRA NUM RBRA 
{
  $$ = A_ArrExprLVal($1->pos,A_ArrayExpr($1->pos,$1,A_NumIndexExpr($3->pos,$3->num)));
}
| LeftVal DOT ID
{
  $$ = A_MemberExprLVal($1->pos,A_MemberExpr($1->pos,$1,$3->id)); // $1todo
}
;

RightVal : ArithExpr 
{
  $$ = A_ArithExprRVal($1->pos, $1);
}
| BoolExpr
{
  $$ = A_BoolExprRVal($1->pos, $1);
}
;

RightValList:RightVal COMMA RightValList
{
  $$=A_RightValList($1, $3);
}
|RightVal
{
  $$=A_RightValList($1, nullptr);
}
;

FnCall : ID LPAR RightValList RPAR
{
  $$ = A_FnCall($1->pos, $1->id,$3);
}
|ID LPAR RPAR
{
  $$ = A_FnCall($1->pos, $1->id, nullptr);
}
;

VarDeclStmt: LET VarDecl SEMICOLON
{
  $$ = A_VarDeclStmt($1,$2);
}
| LET VarDef SEMICOLON
{
  $$ = A_VarDefStmt($1,$2);
}
;

VarDecl: ID COLON Type
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
| ID LBRA NUM RBRA COLON Type
{
  $$ = A_VarDecl_Array($1->pos,  A_VarDeclArray($1->pos, $1->id, $3->num, $6));
}
| ID
{
  $$ = A_VarDecl_Scalar($1->pos,  A_VarDeclScalar($1->pos, $1->id, nullptr));
}
| ID LBRA NUM RBRA
{
  $$ = A_VarDecl_Array($1->pos,  A_VarDeclArray($1->pos, $1->id, $3->num, nullptr));
};

VarDef: ID COLON Type ASSIGN RightVal
{
  $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, $3, $5));
}
| ID ASSIGN RightVal  //primitive type
{
  $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, nullptr, $3));
}
| ID LBRA NUM RBRA COLON Type ASSIGN LCUR RightValList RCUR
{
  $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->id, $3->num, $6, $9));
}
| ID LBRA NUM RBRA ASSIGN LCUR RightValList RCUR  // cur todo
{
  $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->id, $3->num, nullptr, $7));
}
;

Type : INT
{
  $$ = A_NativeType($1, A_intTypeKind);
}
|ID
{
  $$ = A_StructType($1->pos, $1->id);
}
;

VarDeclList : VarDecl COMMA VarDeclList
{
  $$ = A_VarDeclList($1, $3);
}
| VarDecl
{
  $$ = A_VarDeclList($1, NULL);
}
;

ParamDecl : VarDeclList
{
  $$ = A_ParamDecl($1);
}
|
{
  $$ = A_ParamDecl(nullptr);
}
;


StructDef: STRUCT ID LCUR VarDeclList RCUR
{
  $$ = A_StructDef($2->pos, $2->id, $4);  // $2->pos todo 
}
;

FnDeclStmt : FnDecl SEMICOLON
{
  $$ = A_FnDeclStmt($1->pos, $1);
}
;

FnDecl : FN ID LPAR ParamDecl RPAR 
{
  $$ = A_FnDecl($1, $2->id, $4, nullptr);
}
| FN ID LPAR ParamDecl RPAR ARR Type 
{
  $$ = A_FnDecl($1, $2->id, $4, $7);
}
;

FnDef : FnDecl LCUR CodeBlockStmtList RCUR // todo
{
  $$ = A_FnDef($1->pos, $1, $3);
}  
;

CodeBlockStmtList : CodeBlockStmt CodeBlockStmtList
{
  $$ = A_CodeBlockStmtList($1, $2);
}
| CodeBlockStmt
{
  $$ = A_CodeBlockStmtList($1, nullptr);
}
;

CodeBlockStmt: VarDeclStmt
{
  $$ = A_BlockVarDeclStmt($1->pos, $1);
}
| LeftVal ASSIGN RightVal SEMICOLON 
{
  $$ = A_BlockAssignStmt($1->pos, A_AssignStmt($1->pos, $1, $3));
}
| FnCall SEMICOLON
{
  $$ = A_BlockCallStmt($1->pos, A_CallStmt($1->pos, $1));
}
| IF LPAR BoolExpr RPAR LCUR CodeBlockStmtList RCUR ELSE LCUR CodeBlockStmtList RCUR
{
  $$ = A_BlockIfStmt($1, A_IfStmt($1, $3, $6, $10));
}
| IF LPAR BoolExpr RPAR LCUR CodeBlockStmtList RCUR
{
  $$ = A_BlockIfStmt($1, A_IfStmt($1, $3, $6, NULL));
}
| WHILE LPAR BoolExpr RPAR LCUR CodeBlockStmtList RCUR 
{
  $$ = A_BlockWhileStmt($1, A_WhileStmt($1, $3, $6));
}
| RET RightVal SEMICOLON
{
  $$ =A_BlockReturnStmt($1, A_ReturnStmt($1, $2));
}
| RET SEMICOLON
{
  $$ =A_BlockReturnStmt($1, A_ReturnStmt($1, nullptr));
}
| CONTINUE SEMICOLON 
{
  $$ =A_BlockContinueStmt($1);
}
| BREAK SEMICOLON
{
  $$ = A_BlockBreakStmt($1);
}
| SEMICOLON
{
  $$ = A_BlockNullStmt($1);
}
;


%%

extern "C"{
void yyerror(const char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}


