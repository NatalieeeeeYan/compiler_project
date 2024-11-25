%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
int c;
int calc(char *s, int len);
%}

%x COMMENT1
%x COMMENT2


%%

<INITIAL>"\t" { col+=4; }


<INITIAL>[1-9][0-9]* {
    yylval.tokenNum = A_TokenNum(A_Pos(line, col), calc(yytext, yyleng));
    col+=yyleng;
    return UNUM;
}
<INITIAL>0 {
    yylval.tokenNum = A_TokenNum(A_Pos(line, col), 0);
    ++col;
    return UNUM;
}

<INITIAL>"//" {  col += 2; BEGIN(COMMENT1);  }
<INITIAL>"/*" {  col += 2; BEGIN(COMMENT2);  }
<COMMENT2>"\n" {  line += 1; col = 0; }
<COMMENT2>"*/" {  col += 2; BEGIN(INITIAL);  }
<COMMENT2>.  {col += 1;}
<COMMENT1>"\n" {  line += 1; col = 0; BEGIN(INITIAL);  }
<COMMENT1>.*  {col += strlen(yytext);}

<INITIAL>"fn" {yylval.pos = A_Pos(line, col); col += 2; return FN;}
<INITIAL>"struct" {yylval.pos = A_Pos(line, col); col += 6; return STRUCT;}
<INITIAL>"if" {yylval.pos = A_Pos(line, col); col += 2; return IF;}
<INITIAL>"else" {yylval.pos = A_Pos(line, col); col += 4; return ELSE;}
<INITIAL>"while" {yylval.pos = A_Pos(line, col); col += 5; return WHILE;}
<INITIAL>"let" {yylval.pos = A_Pos(line, col); col += 3; return LET;}
<INITIAL>"int" {yylval.pos = A_Pos(line, col); col += 3; return INT;}
<INITIAL>"ret" {yylval.pos = A_Pos(line, col); col += 3; return RETURN;}
<INITIAL>"break" {yylval.pos = A_Pos(line, col); col += 5; return BREAK;}
<INITIAL>"continue" {yylval.pos = A_Pos(line, col); col += 8; return CONTINUE;}
<INITIAL>[a-z_A-Z][a-z_A-Z0-9]*  {yylval.tokenId = A_TokenId(A_Pos(line, col), strdup(yytext)); col += strlen(yytext); return ID;}
<INITIAL>"("	{yylval.pos = A_Pos(line, col); col += 1; return LPAR;}
<INITIAL>")"	{yylval.pos = A_Pos(line, col); col += 1; return RPAR;}
<INITIAL>"[" {yylval.pos = A_Pos(line, col); col += 1; return LBRA;}
<INITIAL>"]" {yylval.pos = A_Pos(line, col); col += 1; return RBRA;}
<INITIAL>"{" {yylval.pos = A_Pos(line, col); col += 1; return LCUR;}
<INITIAL>"}" {yylval.pos = A_Pos(line, col); col += 1; return RCUR;}
<INITIAL>"+"	{yylval.pos = A_Pos(line, col); col += 1; return ADD;}
<INITIAL>"-"	{yylval.pos = A_Pos(line, col); col += 1; return SUB;}
<INITIAL>"*"	{yylval.pos = A_Pos(line, col); col += 1; return MUL;}
<INITIAL>"/"	{yylval.pos = A_Pos(line, col); col += 1; return DIV;}
<INITIAL>"&&" {yylval.pos = A_Pos(line, col); col += 2; return AND;}
<INITIAL>"||" {yylval.pos = A_Pos(line, col); col += 2; return OR;}
<INITIAL>"!" {yylval.pos = A_Pos(line, col); col += 1; return NOT;}
<INITIAL>"." {yylval.pos = A_Pos(line, col); col += 1; return DOT;}
<INITIAL>">" {yylval.pos = A_Pos(line, col); col += 1; return GT;}
<INITIAL>"<" {yylval.pos = A_Pos(line, col); col += 1; return LT;}
<INITIAL>">=" {yylval.pos = A_Pos(line, col); col += 2; return GE;}
<INITIAL>"<=" {yylval.pos = A_Pos(line, col); col += 2; return LE;}
<INITIAL>"!=" {yylval.pos = A_Pos(line, col); col += 2; return NE;}
<INITIAL>"==" {yylval.pos = A_Pos(line, col); col += 2; return EQUAL;}
<INITIAL>"=" {yylval.pos = A_Pos(line, col); col += 1; return ASSIGN;}
<INITIAL>"->" {yylval.pos = A_Pos(line, col); col += 2; return ARR;}
<INITIAL>"," {yylval.pos = A_Pos(line, col); col += 1; return COMMA;}
<INITIAL>":" {yylval.pos = A_Pos(line, col); col += 1; return COLON;}
<INITIAL>" "   {col += 1;}
<INITIAL>"\n" {line++; col = 0;}
<INITIAL>";"     {yylval.pos = A_Pos(line, col); col += 1; return SEMICOLON;}
<INITIAL>.	{ printf("Unknown character! line: %d, col: %d\n", &line, &col); }


%%

int calc(char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}


