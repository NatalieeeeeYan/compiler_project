/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADD = 258,
     SUB = 259,
     MUL = 260,
     DIV = 261,
     SEMICOLON = 262,
     COLON = 263,
     COMMA = 264,
     ID = 265,
     UNUM = 266,
     LPAR = 267,
     RPAR = 268,
     LBRA = 269,
     RBRA = 270,
     DOT = 271,
     AND = 272,
     OR = 273,
     GE = 274,
     LE = 275,
     EQUAL = 276,
     NE = 277,
     GT = 278,
     LT = 279,
     NOT = 280,
     ASSIGN = 281,
     LET = 282,
     IF = 283,
     ELSE = 284,
     WHILE = 285,
     BREAK = 286,
     CONTINUE = 287,
     RET = 288,
     FN = 289,
     STRUCT = 290,
     INT = 291,
     ARR = 292,
     LCUR = 293,
     RCUR = 294
   };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define SEMICOLON 262
#define COLON 263
#define COMMA 264
#define ID 265
#define UNUM 266
#define LPAR 267
#define RPAR 268
#define LBRA 269
#define RBRA 270
#define DOT 271
#define AND 272
#define OR 273
#define GE 274
#define LE 275
#define EQUAL 276
#define NE 277
#define GT 278
#define LT 279
#define NOT 280
#define ASSIGN 281
#define LET 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define BREAK 286
#define CONTINUE 287
#define RET 288
#define FN 289
#define STRUCT 290
#define INT 291
#define ARR 292
#define LCUR 293
#define RCUR 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.yacc"
{
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

  A_fnCall fnCall;
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_boolUnit_ boolUnit_; 
  A_assignStmt assignStmt;
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_rightValList rightValList;
  A_varDecl varDecl;
  A_varDeclList varDeclList;
  A_varDef varDef;
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  A_codeBlockStmtList codeBlockStmtList;
  A_codeBlockStmt codeBlockStmt;
  A_whileStmt whileStmt; 
  A_ifStmt ifStmt; 
}
/* Line 1529 of yacc.c.  */
#line 161 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

