%{
#include <stdio.h>
#include "TeaplAst.h"

// extern int yydebug = 1; 

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

%union {
  A_pos pos;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_structDef structDef;
  A_varDeclStmt varDeclStmt;
  A_varDecl varDecl;
  A_varDeclList varDeclList;
  A_type type; 
  A_nativeType nativeType;
  A_varDef varDef;
  A_rightVal rightVal;
  A_rightValList rightValList; 
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_assignStmt assignStmt;
  A_leftVal leftVal; 
  A_fnDeclStmt fnDeclStmt;
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  char* structType; 
  A_fnDef fnDef;
  A_fnCall fnCall; 
  A_tokenId tokenId; 
  A_tokenNum tokenNum; 
  A_codeBlockStmtList codeBlockStmtList; 
  A_codeBlockStmt codeBlockStmt;
  A_returnStmt returnStmt;
  A_codeBlockStmtType continueStmt; 
  A_codeBlockStmtType breakStmt; 
  A_callStmt callStmt;
  A_ifStmt ifStmt;
  A_whileStmt whileStmt;
}

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> DOT            // .
%token <pos> SEMICOLON      // ;
%token <pos> LET            // let, for variable definition
%token <pos> COLON          // :
%token <pos> COMMA          // ,
%token <pos> OPENBRACKET    // [
%token <pos> CLOSEBRACKET   // ]
%token <tokenId> ID         // ]
%token <tokenNum> NUM       // ]
%token <pos> NType          // int
%token <pos> AND
%token <pos> OR
%token <pos> NOT
%token <pos> EQ
%token <pos> NE
%token <pos> GT
%token <pos> GE
%token <pos> LT
%token <pos> LE
%token <pos> ASSIGN
%token <pos> OPENCURLYBRACKET  // {
%token <pos> CLOSECURLYBRACKET // }
%token <pos> LPa              // (
%token <pos> RPa              // )
%token <pos> STRUCT
%token <pos> ARROW            // ->
%token <pos> FN
%token <pos> RET
%token <pos> CONTINUE
%token <pos> BREAK
%token <pos> IF
%token <pos> ELSE
%token <pos> WHILE



%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <varDecl> VarDecl
%type <varDeclList> VarDeclList
%type <varDef> VarDef
%type <type> Type
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
%type <assignStmt> AssignStmt
%type <leftVal> LeftVal
%type <fnDeclStmt> FnDeclStmt
%type <fnDecl> FnDecl
%type <paramDecl> ParamDecl
%type <fnDef> FnDef
%type <fnCall> FnCall
%type <codeBlockStmtList> CodeBlockStmtList
%type <codeBlockStmt> CodeBlockStmt
%type <returnStmt> ReturnStmt
%type <callStmt> CallStmt
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt

%start Program

%left ADD SUB
%left MUL DIV
%left AND
%left OR
// %left UMINUS

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


// varDeclStmt := < let > (varDecl | varDef) < ; >
VarDeclStmt: LET VarDecl SEMICOLON
{
  $$ = A_VarDeclStmt($1, $2); 
}
| LET VarDef SEMICOLON
{
  $$ = A_VarDefStmt($1, $2); 
}
; 


// varDecl := id < : > Type | id < [ > num < ] >< : > Type | id | id < [ > num < ] >
VarDecl: ID 
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, NULL));
}
| ID COLON Type 
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
| ID OPENBRACKET NUM CLOSEBRACKET 
{
  $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->id, $3->num, NULL));
}
| ID OPENBRACKET NUM CLOSEBRACKET COLON Type 
{
  $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->id, $3->num, $6));
}
;


// type := nativeType | structType
// nativeType := int
// structType := id
Type : NType 
{
  $$ = A_NativeType($1, A_intTypeKind); 
}
| ID 
{
  $$ = A_StructType($1->pos, $1->id); 
}
; 

// VarDef := id < : > Type < = > rightVal | id < = > rightVal     // permitive Type (int)
// | id < [ > num < ] < : > type < = > < { > rightVal ( <, > rightVal)* | epsilon < } > id < [ > num < ] > < = > < { > rightVal (< , > rightVal)* | epsilon < } >   // array type
VarDef : ID ASSIGN RightVal 
{
  $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, NULL, $3));
}
| ID COLON Type ASSIGN RightVal 
{
  $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, $3, $5)); 
}
| ID OPENBRACKET NUM CLOSEBRACKET ASSIGN OPENCURLYBRACKET RightValList CLOSECURLYBRACKET 
{
  $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->id, $3->num, NULL, $7));
}
| ID OPENBRACKET NUM CLOSEBRACKET COLON Type ASSIGN OPENCURLYBRACKET RightValList CLOSECURLYBRACKET 
{
  $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->id, $3->num, $6, $9));
}
; 

VarDeclList : VarDecl
{
  $$ = A_VarDeclList($1, NULL);
}
| VarDecl COMMA VarDeclList 
{
  $$ = A_VarDeclList($1, $3);
}
| 
{
  $$ = NULL; 
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

RightValList: RightVal 
{
  $$ = A_RightValList($1, NULL); 
}
| RightVal COMMA RightValList 
{
  $$ = A_RightValList($1, $3); 
}
| 
{
  $$ = NULL;
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

// ExprUnit := num | id | < ( > ArithExpr < ) > | fnCall | LeftVal | < [ > id | num < ] > | RightVal < . > id | ArithUOp ExprUnit
ExprUnit: NUM
{
  $$ = A_NumExprUnit($1->pos, $1->num); 
}
| ID 
{
  $$ = A_IdExprUnit($1->pos, $1->id); 
}
| LPa ArithExpr RPa
{
  $$ = A_ArithExprUnit($2->pos, $2); 
}
| FnCall 
{
  $$ = A_CallExprUnit($1->pos, $1); 
}
| ID OPENBRACKET ID CLOSEBRACKET
{
  $$ = A_ArrayExprUnit($1->pos, A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_IdIndexExpr($3->pos, $3->id))); 
}
| ID OPENBRACKET NUM CLOSEBRACKET
{
  $$ = A_ArrayExprUnit($1->pos, A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_NumIndexExpr($3->pos, $3->num))); 
}
| ID DOT ID
{
  $$ = A_MemberExprUnit($1->pos, A_MemberExpr($1->pos, A_IdExprLVal($1->pos, $1->id), $3->id)); 
}
| SUB ExprUnit 
{
  $$ = A_ArithUExprUnit($1, A_ArithUExpr($1, A_neg, $2)); 
}
; 

// BoolExpr := BoolExpr BoolBiOp BoolUnit | BoolUnit
BoolExpr : BoolExpr AND BoolExpr 
{
  $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_and, $1, $3)); 
}
| BoolExpr OR BoolExpr 
{
  $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_or, $1, $3)); 
}
| BoolUnit 
{
  $$ = A_BoolExpr($1->pos, $1); 
}
; 

// BoolUnit := exprUnit comOp ExprUnit | < ( > BoolExpr < ) > | BoolUop BoolUnit
BoolUnit : ExprUnit GT ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_gt, $1, $3)); 
}
| ExprUnit GE ExprUnit 
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_ge, $1, $3)); 
}
| ExprUnit LT ExprUnit
{
  $$ = A_ComExprUnit($1->pos, A_ComExpr($1->pos, A_lt, $1, $3)); 
}
| ExprUnit LE ExprUnit
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
| LPa BoolExpr RPa
{
  $$ = A_BoolExprUnit($1, $2); 
}
| NOT BoolUnit
{
  $$ = A_BoolUOpExprUnit($1, A_BoolUOpExpr($1, A_not, $2)); 
}
; 


// Assignment := LeftVal < = > RightVal < ; >
AssignStmt: LeftVal ASSIGN RightVal SEMICOLON 
{
  $$ = A_AssignStmt($1->pos, $1, $3); 
}
; 

// LeftVal := id | id < [ > id | num | < ] > | id < . > id
LeftVal: ID
{
  $$ = A_IdExprLVal($1->pos, $1->id); 
}
| ID OPENBRACKET NUM CLOSEBRACKET
{
  $$ = A_ArrExprLVal($1->pos, A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_NumIndexExpr($3->pos, $3->num))); 
}
| ID OPENBRACKET ID CLOSEBRACKET
{
  $$ = A_ArrExprLVal($1->pos, A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_IdIndexExpr($3->pos, $3->id)));
}
| ID DOT ID
{
  $$ = A_MemberExprLVal($1->pos, A_MemberExpr($1->pos, A_IdExprLVal($1->pos, $1->id), $3->id)); 
}
; 

// FnCall := id < ( > RightVal ( < , > RightVal) * | e < ) >
FnCall: ID LPa RightValList RPa
{
  $$ = A_FnCall($1->pos, $1->id, $3); 
}
; 

// StructDef := < struct > id < { > (VarDecl) (< , > VarDecl)* < } >
StructDef: STRUCT ID OPENCURLYBRACKET VarDeclList CLOSECURLYBRACKET
{
  $$ = A_StructDef($2->pos, $2->id, $4); 
}
; 

// FnDeclStmt := FnDecl < ; >
FnDeclStmt: FnDecl SEMICOLON
{
  $$ = A_FnDeclStmt($1->pos, $1); 
}
; 

// FnDecl := < fn > id < ( > ParamDecl < ) > 
//         | < fn > id < ( > ParamDecl < ) > < -> > Type
FnDecl: FN ID LPa ParamDecl RPa
{
  $$ = A_FnDecl($2->pos, $2->id, $4, NULL); 
}
| FN ID LPa ParamDecl RPa ARROW Type
{
  $$ = A_FnDecl($2->pos, $2->id, $4, $7); 
}
; 

// ParamDecl := VarDecl (< , > VarDecl)* | e
ParamDecl: VarDeclList
{
  $$ = A_ParamDecl($1); 
}
; 

// FnDef := FnDecl CodeBlock
FnDef: FnDecl OPENCURLYBRACKET CodeBlockStmtList CLOSECURLYBRACKET
{
  $$ = A_FnDef($1->pos, $1, $3);
}
; 

// CodeBlock := < { > (VarDeclStmt | Assignment | CallStmt | IfStmt | WhileStmt | ReturnStmt | CONTINUE | BREAK | < ; >)* < } >
CodeBlockStmtList: CodeBlockStmt
{
  $$ = A_CodeBlockStmtList($1, NULL);
}
| CodeBlockStmt CodeBlockStmtList
{
  $$ =  A_CodeBlockStmtList($1, $2); 
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

// ReturnStmt := < ret > RightVal < ; >
ReturnStmt: RET RightVal SEMICOLON
{
  $$ = A_ReturnStmt($1, $2); 
}
; 

// CallStmt := FnCal < ; >
CallStmt: FnCall SEMICOLON
{
  $$ = A_CallStmt($1->pos, $1); 
}
; 

// IfStmt := < if > < ( > BoolExpr < ) > CodeBlock ( < else > CodeBlock | e )
IfStmt: IF LPa BoolExpr RPa OPENCURLYBRACKET CodeBlockStmtList CLOSECURLYBRACKET ELSE OPENCURLYBRACKET CodeBlockStmtList CLOSECURLYBRACKET
{
  $$ = A_IfStmt($1, $3, $6, $10); 
}
| IF LPa BoolExpr RPa OPENCURLYBRACKET CodeBlockStmtList CLOSECURLYBRACKET
{
  $$ = A_IfStmt($1, $3, $6, NULL); 
}
; 

// WhileStmt := < while > < ( > BoolExpr < ) > CodeBlock
WhileStmt: WHILE LPa BoolExpr RPa OPENCURLYBRACKET CodeBlockStmtList CLOSECURLYBRACKET
{
  $$ = A_WhileStmt($1, $3, $6); 
}
; 



%%

extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}


