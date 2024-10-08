%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
int c;
int calc(const char *s, int len);
%}

letter [a-z_A-Z]
digit [0-9]
id {letter}({letter}|{digit})*

%s COMMENT_LINE
%s COMMENT_SCOPE

%%
<INITIAL>"\t"           { col += 4; }
<INITIAL>" "            { col++; }
<INITIAL>"\n"           { line++; }

<INITIAL>[1-9][0-9]*    {yylval.tokenNum = A_TokenNum(A_Pos(line, col), calc(yytext, yyleng));col+=yyleng;return NUM;}
<INITIAL>0              {yylval.tokenNum = A_TokenNum(A_Pos(line, col), 0);++col;return NUM;}

<INITIAL>"+"            {yylval.pos = A_Pos(line,col++); return ADD;}
<INITIAL>"-"            {yylval.pos = A_Pos(line,col++); return SUB;}
<INITIAL>"*"            {yylval.pos = A_Pos(line,col++); return MUL;}
<INITIAL>"/"            {yylval.pos = A_Pos(line,col++); return DIV;}

<INITIAL>":"            {yylval.pos = A_Pos(line,col++); return COLON;}
<INITIAL>","            {yylval.pos = A_Pos(line,col++); return COMMA;}
<INITIAL>"->"           {yylval.pos = A_Pos(line,col); col += 2; return ARROW;}
<INITIAL>"."            {yylval.pos = A_Pos(line,col++); return DOT;}
<INITIAL>";"            {yylval.pos = A_Pos(line,col++); return SEMICOLON;}

<INITIAL>"if"           {yylval.pos = A_Pos(line,col); col += 2; return IF;}
<INITIAL>"else"         {yylval.pos = A_Pos(line,col); col += 4; return ELSE;}
<INITIAL>"while"        {yylval.pos = A_Pos(line,col); col += 5; return WHILE;}
<INITIAL>"break"        {yylval.pos = A_Pos(line,col); col += 5; return BREAK;}
<INITIAL>"continue"     {yylval.pos = A_Pos(line,col); col += 8; return CONTINUE;}
<INITIAL>"ret"          {yylval.pos = A_Pos(line,col); col += 3; return RETURN;}

<INITIAL>"int"          {yylval.pos = A_Pos(line,col); col += 3; return INT;}
<INITIAL>"fn"           {yylval.pos = A_Pos(line,col); col += 2; return FN;}
<INITIAL>"struct"       {yylval.pos = A_Pos(line,col); col += 6; return STRUCT;}
<INITIAL>"let"          {yylval.pos = A_Pos(line,col); col += 3; return LET;}

<INITIAL>">="   {yylval.pos = A_Pos(line,col); col += 2; return GTE;}
<INITIAL>"<="   {yylval.pos = A_Pos(line,col); col += 2; return LTE;}
<INITIAL>">"    {yylval.pos = A_Pos(line,col++); return GT;}
<INITIAL>"<"    {yylval.pos = A_Pos(line,col++); return LT;}
<INITIAL>"!="   {yylval.pos = A_Pos(line,col); col += 2; return NE;}
<INITIAL>"=="   {yylval.pos = A_Pos(line,col); col += 2; return EQ;}
<INITIAL>"="    {yylval.pos = A_Pos(line,col++); return ASSIGN;}

<INITIAL>"&&"   {yylval.pos = A_Pos(line,col); col += 2; return AND;}
<INITIAL>"||"   {yylval.pos = A_Pos(line,col); col += 2; return OR;}
<INITIAL>"!"    {yylval.pos = A_Pos(line,col++); return NOT;}

<INITIAL>"("    {yylval.pos = A_Pos(line,col++); return LPAREN;}
<INITIAL>")"    {yylval.pos = A_Pos(line,col++); return RPAREN;}
<INITIAL>"["    {yylval.pos = A_Pos(line,col++); return LBRACKET;}
<INITIAL>"]"    {yylval.pos = A_Pos(line,col++); return RBRACKET;}
<INITIAL>"{"    {yylval.pos = A_Pos(line,col++); return LBRACE;}
<INITIAL>"}"    {yylval.pos = A_Pos(line,col++); return RBRACE;}

<INITIAL>"//"   {BEGIN COMMENT_LINE;}
<INITIAL>"/*"   {BEGIN COMMENT_SCOPE;}

<COMMENT_LINE>"\n"  {line++; col = 0; BEGIN INITIAL;}
<COMMENT_LINE>[^\n] {}

<COMMENT_SCOPE>"*/"  {BEGIN INITIAL;}
<COMMENT_SCOPE>"\n" {line++; col = 0;}
<COMMENT_SCOPE>"\t"   {col += 4;}
<COMMENT_SCOPE>.   {col += 1;}

<INITIAL>{id}   {yylval.tokenId = A_TokenId(A_Pos(line, col), strdup(yytext)); col += yyleng; return ID;}

%%

// This function takes a string of digits and its length as input, and returns the integer value of the string.
int calc(const char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}