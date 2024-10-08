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
  // Program
  A_pos pos;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_structDef structDef;
  A_varDeclStmt varDeclStmt;
  A_fnDeclStmt fnDeclStmt;
  A_fnDef fnDef;
  
  // TODO 

  // Id
  A_tokenId tokenId;
  // Num
  A_tokenNum tokenNum;
  // Arithmatic Expressions
  A_arrayExpr arrayExpr;
  A_memberExpr memberExpr;
  A_arithUExpr arithUExpr;
  A_arithBiOpExpr arithBiOpExpr;
  A_indexExpr indexExpr;
  // Condition Expressions
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_boolUOpExpr boolUOpExpr;
  A_boolBiOpExpr boolBiOpExpr;
  // Assignment
  A_assignStmt assignStmt;
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_rightValList rightValList;
  // Function Call
  A_fnCall fnCall;
  // Variable Declarations
  A_varDecl varDecl;
  A_varDef varDef;
  A_type type;
  A_varDeclScalar varDeclScalar;
  A_varDeclArray varDeclArray;
  A_varDeclList varDeclList;
  A_varDefScalar varDefScalar;
  A_varDefArray varDefArray;
  // Structure
  //
  // Function Declaration and Definition
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  A_codeBlockStmt codeBlockStmt;
  A_returnStmt returnStmt;
  A_callStmt callStmt;
  A_codeBlockStmtList codeBlockStmtList;
  // Control Flows
  A_ifStmt ifStmt;
  A_whileStmt whileStmt;
}


%token <pos> ADD SUB
%token <pos> MUL DIV
// TODO
%token <pos> GT LT
%token <pos> GTE LTE
%token <pos> EQ NE
%token <pos> ASSIGN
%token <pos> AND OR NOT
%token <pos> LPAREN RPAREN
%token <pos> LBRACKET RBRACKET
%token <pos> LBRACE RBRACE
%token <pos> COLON COMMA ARROW DOT SEMICOLON
%token <pos> IF ELSE WHILE BREAK CONTINUE RETURN
%token <pos> INT FN STRUCT LET
%token <tokenNum> NUM
%token <tokenId> ID


%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef

// TODO
// %type <tokenId> tokenId
// %type <tokenNum> tokenNum
%type <arrayExpr> ArrayExpr
%type <memberExpr> MemberExpr
%type <arithUExpr> ArithUExpr
%type <arithBiOpExpr> ArithBiOpExpr
%type <indexExpr> IndexExpr
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
%type <boolUOpExpr> BoolUOpExpr
%type <boolBiOpExpr> BoolBiOpExpr
%type <assignStmt> AssignStmt
%type <leftVal> LeftVal
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <fnCall> FnCall
%type <varDecl> VarDecl
%type <varDef> VarDef
%type <type> Type
%type <varDeclScalar> VarDeclScalar
%type <varDeclArray> VarDeclArray
%type <varDeclList> VarDeclList
%type <varDefScalar> VarDefScalar
%type <varDefArray> VarDefArray
%type <fnDecl> FnDecl
%type <paramDecl> ParamDecl
%type <codeBlockStmt> CodeBlockStmt
%type <returnStmt> ReturnStmt
%type <callStmt> CallStmt
%type <codeBlockStmtList> CodeBlockStmtList
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt


%start Program

// TODO
%left SEMICOLON COMMA
%left IF ELSE WHILE BREAK CONTINUE RETURN
%left ASSIGN
%left AND OR
%left GT LT GTE LTE EQ NE
%left ADD SUB
%left MUL DIV
%right NOT
%right LBRACKET
%left RBRACKET
%left DOT
%right LPAREN
%left RPAREN



%%                   /* beginning of rules section */


// Program
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


// Arithmatic Expressions
ArithExpr: ArithBiOpExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, $1);
}
|
ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
};

ArithBiOpExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_add, $1, $3);
}
|
ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_sub, $1, $3);
}
|
ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_mul, $1, $3);
}
|
ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_div, $1, $3);
};

ExprUnit: NUM
{
  $$ = A_NumExprUnit($1->pos, $1->num);
}
| ID
{
  $$ = A_IdExprUnit($1->pos, $1->id);
}
| LPAREN ArithExpr RPAREN
{
  $$ = A_ArithExprUnit($2->pos, $2);
}
| FnCall
{
  $$ = A_CallExprUnit($1->pos, $1);
}
| ArrayExpr
{
  $$ = A_ArrayExprUnit($1->pos , $1);
}
| MemberExpr
{
  $$ = A_MemberExprUnit($1->pos, $1);
}
| ArithUExpr
{
  $$ = A_ArithUExprUnit($1->pos, $1);
}
;

ArithUExpr: SUB ExprUnit
{
  $$ = A_ArithUExpr($1, A_neg, $2);
}
;


// Condition Expressions
BoolExpr: BoolBiOpExpr
{
  $$ = A_BoolBiOp_Expr($1->pos, $1);
}
|
BoolUnit
{
  $$ = A_BoolExpr($1->pos, $1);
};

BoolBiOpExpr: BoolExpr AND BoolExpr
{
  $$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
}
|
BoolExpr OR BoolExpr
{
  $$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
};

BoolUnit: ExprUnit GT ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_gt, $1, $3));
}
| ExprUnit LT ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_lt, $1, $3));
}
| ExprUnit GTE ExprUnit
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_ge, $1, $3));
}
| ExprUnit LTE ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_le, $1, $3));
}
| ExprUnit EQ ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_eq, $1, $3));
}
| ExprUnit NE ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_ne, $1, $3));
}
| LPAREN BoolExpr RPAREN
{
  $$ = A_BoolExprUnit($1, $2);
}
| BoolUOpExpr
{
  $$ = A_BoolUOpExprUnit($1->pos, $1);
};
;

BoolUOpExpr: NOT BoolUnit
            {
              $$ = A_BoolUOpExpr($1, A_not, $2);
            };


//  Assignment 
AssignStmt: LeftVal ASSIGN RightVal SEMICOLON
{
  $$ = A_AssignStmt($1->pos, $1, $3);
}
;

LeftVal: ID
{
  $$ = A_IdExprLVal($1->pos, $1->id);
}
| ArrayExpr
{
  $$ = A_ArrExprLVal($1->pos, $1);
}
| MemberExpr 
{
  $$ = A_MemberExprLVal($1->pos, $1);
}
;

RightVal: ArithExpr
{
  $$ = A_ArithExprRVal($1->pos, $1);
}
| BoolExpr
{
  $$ = A_BoolExprRVal($1->pos, $1);
}
;

IndexExpr: NUM
{
  $$ = A_NumIndexExpr($1->pos, $1->num);
}
|
ID
{
  $$ = A_IdIndexExpr($1->pos, $1->id);
};

ArrayExpr: LeftVal LBRACKET IndexExpr RBRACKET
{
  $$ = A_ArrayExpr($1->pos, $1, $3);
}
;

MemberExpr: LeftVal DOT ID
{
  $$ = A_MemberExpr($1->pos, $1, $3->id);
}
;

// Function Call
FnCall: ID LPAREN RightValList RPAREN  
{
  $$ = A_FnCall($1->pos, $1->id, $3);
} 
| ID LPAREN RPAREN
{
  $$ = A_FnCall($1->pos, $1->id, nullptr);
}
;

RightValList: RightVal COMMA RightValList
{
  $$ = A_RightValList($1, $3);
}
| RightVal
{
  $$ = A_RightValList($1, nullptr);
}
;


// Variable Declarations
VarDeclStmt: LET VarDecl SEMICOLON
{ 
  $$ = A_VarDeclStmt($1, $2);
}
| LET VarDef SEMICOLON
{
  $$ = A_VarDefStmt($1, $2);
}
;

VarDecl: VarDeclScalar
{
  $$ = A_VarDecl_Scalar($1->pos, $1);
}
| VarDeclArray
{
  $$ = A_VarDecl_Array($1->pos, $1);
}
;

VarDef: VarDefScalar
{
  $$ = A_VarDef_Scalar($1->pos, $1);
}
| VarDefArray
{
  $$ = A_VarDef_Array($1->pos, $1);
}
;

VarDeclScalar: ID COLON Type
{
  $$ = A_VarDeclScalar($1->pos, $1->id, $3);
}
| ID 
{
  $$ = A_VarDeclScalar($1->pos, $1->id, nullptr);
}
;

VarDeclArray: ID LBRACKET NUM RBRACKET COLON Type
{
  $$ = A_VarDeclArray($1->pos, $1->id, $3->num, $6);
}
| ID LBRACKET NUM RBRACKET
{
  $$ = A_VarDeclArray($1->pos, $1->id, $3->num, nullptr);
}
;

VarDefScalar: ID COLON Type ASSIGN RightVal
{
  $$ = A_VarDefScalar($1->pos, $1->id, $3, $5);
}
| ID ASSIGN RightVal
{
  $$ = A_VarDefScalar($1->pos, $1->id, nullptr, $3);
}
;

VarDefArray: ID LBRACKET NUM RBRACKET COLON Type ASSIGN RightValList
{
  $$ = A_VarDefArray($1->pos, $1->id, $3->num, $6, $8);
}
| ID LBRACKET NUM RBRACKET ASSIGN RightValList
{
  $$ = A_VarDefArray($1->pos, $1->id, $3->num, nullptr, $6);
}
;

Type: INT
{
  $$ = A_NativeType($1, A_intTypeKind);
}
| ID
{
  $$ = A_StructType($1->pos, $1->id);
}
;


// Define A New Structure
StructDef: STRUCT ID LBRACE VarDeclList RBRACE
{
  $$ = A_StructDef($1, $2->id, $4);
}
;

VarDeclList: VarDecl COMMA VarDeclList
{
  $$ = A_VarDeclList($1, $3);
}
| VarDecl
{
  $$ = A_VarDeclList($1, nullptr);
}
;



// Function Declaration and Definition
FnDeclStmt: FnDecl SEMICOLON 
{
  $$ =  A_FnDeclStmt($1->pos, $1);
}
;

FnDecl: FN ID LPAREN ParamDecl RPAREN ARROW Type
{
  $$ = A_FnDecl($1, $2->id, $4, $7);
}
| FN ID LPAREN ParamDecl RPAREN
{
  $$ = A_FnDecl($1, $2->id, $4, nullptr);
}
;

ParamDecl: VarDeclList
{
  $$ = A_ParamDecl($1);
}
| 
{
  $$ = A_ParamDecl(nullptr);
}
;

FnDef: FnDecl LBRACE CodeBlockStmtList RBRACE
{
  $$ = A_FnDef($1->pos, $1, $3);
}
;

CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList
{
  $$ = A_CodeBlockStmtList($1, $2);
}
|
{
  $$ = nullptr;
}
;

CodeBlockStmt: VarDeclStmt
{
  $$ = A_BlockVarDeclStmt($1->pos, $1);
}
| AssignStmt
{
  $$ = A_BlockAssignStmt($1->pos, $1);
}
| CallStmt
{
  $$ = A_BlockCallStmt($1->pos, $1);  
}
| IfStmt
{
  $$ = A_BlockIfStmt($1->pos, $1);
}
| WhileStmt
{
  $$ = A_BlockWhileStmt($1->pos, $1);
}
| ReturnStmt
{
  $$ = A_BlockReturnStmt($1->pos, $1);
}
| CONTINUE SEMICOLON
{
  $$ = A_BlockContinueStmt($1);
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

CallStmt: FnCall SEMICOLON
{
  $$ = A_CallStmt($1->pos, $1);
}
;


// Control Flows
IfStmt: IF LPAREN BoolUnit RPAREN LBRACE CodeBlockStmtList RBRACE ELSE LBRACE CodeBlockStmtList RBRACE
{
  $$ = A_IfStmt($1, $3, $6, $10);
}
| IF LPAREN BoolUnit RPAREN LBRACE CodeBlockStmtList RBRACE
{
  $$ = A_IfStmt($1, $3, $6, nullptr);
}
;

WhileStmt: WHILE LPAREN BoolUnit RPAREN LBRACE CodeBlockStmtList RBRACE 
{
  $$ = A_WhileStmt($1, $3, $6);
}
;

ReturnStmt: RETURN RightVal SEMICOLON
{
  $$ = A_ReturnStmt($1, $2);
}
| RETURN SEMICOLON
{
  $$ = A_ReturnStmt($1, nullptr);
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


