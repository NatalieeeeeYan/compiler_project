/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     DOT = 262,
     SEMICOLON = 263,
     LET = 264,
     COLON = 265,
     COMMA = 266,
     OPENBRACKET = 267,
     CLOSEBRACKET = 268,
     ID = 269,
     NUM = 270,
     NType = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     EQ = 275,
     NE = 276,
     GT = 277,
     GE = 278,
     LT = 279,
     LE = 280,
     ASSIGN = 281,
     OPENCURLYBRACKET = 282,
     CLOSECURLYBRACKET = 283,
     LPa = 284,
     RPa = 285,
     STRUCT = 286,
     ARROW = 287,
     FN = 288,
     RET = 289,
     CONTINUE = 290,
     BREAK = 291,
     IF = 292,
     ELSE = 293,
     WHILE = 294
   };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define DOT 262
#define SEMICOLON 263
#define LET 264
#define COLON 265
#define COMMA 266
#define OPENBRACKET 267
#define CLOSEBRACKET 268
#define ID 269
#define NUM 270
#define NType 271
#define AND 272
#define OR 273
#define NOT 274
#define EQ 275
#define NE 276
#define GT 277
#define GE 278
#define LT 279
#define LE 280
#define ASSIGN 281
#define OPENCURLYBRACKET 282
#define CLOSECURLYBRACKET 283
#define LPa 284
#define RPa 285
#define STRUCT 286
#define ARROW 287
#define FN 288
#define RET 289
#define CONTINUE 290
#define BREAK 291
#define IF 292
#define ELSE 293
#define WHILE 294




/* Copy the first part of user declarations.  */
#line 1 "parser.yacc"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.yacc"
{
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
  A_memberExpr memberExpr;
  A_arrayExpr arrayExpr; 
  A_indexExpr indexExpr; 
}
/* Line 193 of yacc.c.  */
#line 232 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 245 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    23,    27,    29,    33,    38,    45,    47,    49,    53,
      59,    68,    79,    81,    85,    86,    88,    90,    92,    96,
      97,   101,   105,   109,   113,   115,   117,   119,   123,   125,
     127,   129,   132,   136,   140,   142,   146,   150,   154,   158,
     162,   166,   170,   173,   178,   180,   182,   184,   189,   195,
     198,   204,   212,   214,   219,   221,   224,   226,   228,   230,
     232,   234,   236,   239,   242,   244,   248,   251,   254,   266,
     274,   282,   286,   290,   294,   299,   301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    42,    -1,    -1,    44,
      -1,    58,    -1,    59,    -1,    62,    -1,     8,    -1,     9,
      45,     8,    -1,     9,    47,     8,    -1,    14,    -1,    14,
      10,    46,    -1,    14,    12,    15,    13,    -1,    14,    12,
      15,    13,    10,    46,    -1,    16,    -1,    14,    -1,    14,
      26,    49,    -1,    14,    10,    46,    26,    49,    -1,    14,
      12,    15,    13,    26,    27,    50,    28,    -1,    14,    12,
      15,    13,    10,    46,    26,    27,    50,    28,    -1,    45,
      -1,    45,    11,    48,    -1,    -1,    51,    -1,    53,    -1,
      49,    -1,    49,    11,    50,    -1,    -1,    51,     3,    51,
      -1,    51,     4,    51,    -1,    51,     5,    51,    -1,    51,
       6,    51,    -1,    52,    -1,    15,    -1,    14,    -1,    29,
      51,    30,    -1,    57,    -1,    70,    -1,    69,    -1,     4,
      52,    -1,    53,    17,    53,    -1,    53,    18,    53,    -1,
      54,    -1,    52,    22,    52,    -1,    52,    23,    52,    -1,
      52,    24,    52,    -1,    52,    25,    52,    -1,    52,    20,
      52,    -1,    52,    21,    52,    -1,    29,    53,    30,    -1,
      19,    54,    -1,    56,    26,    49,     8,    -1,    14,    -1,
      70,    -1,    69,    -1,    14,    29,    50,    30,    -1,    31,
      14,    27,    48,    28,    -1,    60,     8,    -1,    33,    14,
      29,    61,    30,    -1,    33,    14,    29,    61,    30,    32,
      46,    -1,    48,    -1,    60,    27,    63,    28,    -1,    64,
      -1,    64,    63,    -1,    44,    -1,    55,    -1,    66,    -1,
      67,    -1,    68,    -1,    65,    -1,    35,     8,    -1,    36,
       8,    -1,     8,    -1,    34,    49,     8,    -1,    34,     8,
      -1,    57,     8,    -1,    37,    29,    53,    30,    27,    63,
      28,    38,    27,    63,    28,    -1,    37,    29,    53,    30,
      27,    63,    28,    -1,    39,    29,    53,    30,    27,    63,
      28,    -1,    14,     7,    14,    -1,    70,     7,    14,    -1,
      69,     7,    14,    -1,    56,    12,    71,    13,    -1,    15,
      -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   149,   154,   159,   163,   167,   171,   175,
     183,   187,   195,   199,   203,   207,   217,   221,   229,   233,
     237,   241,   247,   251,   256,   261,   265,   271,   275,   280,
     285,   289,   293,   297,   301,   308,   312,   316,   320,   324,
     328,   332,   339,   343,   347,   354,   358,   362,   366,   370,
     374,   378,   382,   390,   397,   401,   405,   412,   419,   426,
     434,   438,   445,   452,   459,   463,   469,   473,   477,   481,
     485,   489,   493,   497,   501,   508,   512,   519,   526,   530,
     537,   543,   547,   551,   558,   564,   568
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "DOT",
  "SEMICOLON", "LET", "COLON", "COMMA", "OPENBRACKET", "CLOSEBRACKET",
  "ID", "NUM", "NType", "AND", "OR", "NOT", "EQ", "NE", "GT", "GE", "LT",
  "LE", "ASSIGN", "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "LPa", "RPa",
  "STRUCT", "ARROW", "FN", "RET", "CONTINUE", "BREAK", "IF", "ELSE",
  "WHILE", "$accept", "Program", "ProgramElementList", "ProgramElement",
  "VarDeclStmt", "VarDecl", "Type", "VarDef", "VarDeclList", "RightVal",
  "RightValList", "ArithExpr", "ExprUnit", "BoolExpr", "BoolUnit",
  "AssignStmt", "LeftVal", "FnCall", "StructDef", "FnDeclStmt", "FnDecl",
  "ParamDecl", "FnDef", "CodeBlockStmtList", "CodeBlockStmt", "ReturnStmt",
  "CallStmt", "IfStmt", "WhileStmt", "MemberExpr", "ArrayExpr",
  "IndexExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    47,    47,
      47,    47,    48,    48,    48,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    56,    56,    56,    57,    58,    59,
      60,    60,    61,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    67,
      68,    69,    69,    69,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     4,     6,     1,     1,     3,     5,
       8,    10,     1,     3,     0,     1,     1,     1,     3,     0,
       3,     3,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     2,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     4,     1,     1,     1,     4,     5,     2,
       5,     7,     1,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     2,     2,    11,     7,
       7,     3,     3,     3,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     9,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,     8,    12,     0,     0,     0,     0,     1,     3,
      59,     0,     0,     0,     0,    10,    11,    24,    24,    74,
      54,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,    64,    71,    68,    69,    70,    56,    55,    17,    16,
      13,     0,     0,    36,    35,     0,     0,    18,    25,    34,
      26,    44,     0,    38,    40,    39,    12,    22,     0,    62,
       0,     0,    29,    76,     0,    72,    73,     0,     0,     0,
       0,    77,    63,    65,     0,     0,     0,    14,     0,    41,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    58,
      60,    81,    27,     0,    75,     0,     0,    86,    85,     0,
       0,    83,    82,    19,     0,     0,    34,    37,    51,    30,
      31,    32,    33,    49,    50,    45,    46,    47,    48,    42,
      43,    13,     0,    23,     0,    29,    57,     0,     0,    84,
      53,    15,    29,    14,    61,    28,     0,     0,     0,     0,
       0,     0,     0,    29,    20,    15,    79,    80,     0,     0,
      21,     0,     0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    36,    67,    50,    15,    68,   112,
     113,    58,    59,    60,    61,    37,    62,    63,     9,    10,
      11,    70,    12,    40,    41,    42,    43,    44,    45,    64,
      65,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
      76,  -102,    48,    55,    79,    96,  -102,    76,  -102,  -102,
    -102,     6,  -102,    85,   106,   110,    72,    97,  -102,  -102,
    -102,    52,    88,   118,    21,  -102,  -102,   135,   135,  -102,
      12,    86,   143,   145,   126,   130,  -102,  -102,    80,   153,
     132,    52,  -102,  -102,  -102,  -102,   155,   156,  -102,  -102,
     138,   154,    13,     9,  -102,    21,    21,  -102,   124,   123,
      35,  -102,   157,  -102,    56,    91,    98,   159,   137,  -102,
     136,   158,    21,  -102,   160,  -102,  -102,    21,    21,   109,
      21,  -102,  -102,  -102,   161,   162,    21,     8,    13,  -102,
     123,  -102,     7,    95,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    21,    21,    88,   163,   135,  -102,
     139,  -102,   166,   144,  -102,   102,   104,  -102,  -102,   167,
     165,  -102,  -102,  -102,    88,   164,  -102,  -102,  -102,   152,
     152,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   168,
    -102,  -102,   169,  -102,    88,    21,  -102,   170,   171,  -102,
    -102,   173,    21,   174,  -102,  -102,    52,    52,   175,   151,
      88,   172,   176,    21,  -102,  -102,   147,  -102,   177,   179,
    -102,    52,   180,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   181,  -102,    44,   185,  -101,  -102,   -25,   -16,
     -96,   -49,   -23,   -47,   128,  -102,   -21,   -19,  -102,  -102,
    -102,  -102,  -102,   -40,  -102,  -102,  -102,  -102,  -102,   -17,
     -15,  -102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
      38,    83,    39,    69,    46,   141,    47,    92,    57,    93,
      94,    95,    96,    97,    20,    74,    71,    52,   124,    71,
      38,   -54,    39,   151,    46,    52,    47,    53,    54,    89,
     115,   116,    90,    21,   125,    53,    54,   127,    72,    92,
      55,    72,    88,   154,     8,   129,   130,   131,   132,   155,
      56,     8,   104,   105,    90,    90,   159,   139,   140,   165,
      29,     2,    13,    84,   120,   126,    30,   168,   -56,    16,
     123,   126,   126,   126,   126,   133,   134,   135,   136,   137,
     138,    90,    90,   143,     1,     2,    31,    32,    33,    34,
      52,    35,    79,    17,    73,    22,    18,    23,    85,    27,
      53,    54,    48,   -55,    49,    55,    80,     3,   106,     4,
     107,    24,   104,   105,    25,    56,   161,   162,    26,   104,
     105,   104,   105,   117,   118,   128,    28,    94,    95,    96,
      97,   172,   147,    51,   148,    38,    38,    39,    39,    46,
      46,    47,    47,    98,    99,   100,   101,   102,   103,    66,
      38,    75,    39,    76,    46,    77,    47,    96,    97,    78,
      82,    81,    84,    85,    86,   109,   110,    87,   114,    79,
     108,   144,   111,   150,   146,   121,   122,   145,   142,   164,
     149,     0,   153,    91,   160,   169,   105,    14,    19,     0,
       0,   152,     0,     0,     0,     0,     0,   156,   157,   158,
     166,     0,   163,     0,   167,   170,   171,     0,   173
};

static const yytype_int16 yycheck[] =
{
      21,    41,    21,    28,    21,   106,    21,    56,    24,    56,
       3,     4,     5,     6,     8,    31,     7,     4,    10,     7,
      41,    12,    41,   124,    41,     4,    41,    14,    15,    52,
      77,    78,    55,    27,    26,    14,    15,    30,    29,    88,
      19,    29,    29,   144,     0,    94,    95,    96,    97,   145,
      29,     7,    17,    18,    77,    78,   152,   104,   105,   160,
       8,     9,    14,     7,    80,    88,    14,   163,    12,    14,
      86,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   108,     8,     9,    34,    35,    36,    37,
       4,    39,    12,    14,     8,    10,     0,    12,     7,    27,
      14,    15,    14,    12,    16,    19,    26,    31,    10,    33,
      12,    26,    17,    18,     8,    29,   156,   157,     8,    17,
      18,    17,    18,    14,    15,    30,    29,     3,     4,     5,
       6,   171,    30,    15,    30,   156,   157,   156,   157,   156,
     157,   156,   157,    20,    21,    22,    23,    24,    25,    14,
     171,     8,   171,     8,   171,    29,   171,     5,     6,    29,
      28,     8,     7,     7,    26,    28,    30,    13,     8,    12,
      11,    32,    14,     8,    30,    14,    14,    11,    15,    28,
      13,    -1,    13,    55,    10,    38,    18,     2,     7,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    27,    27,    26,
      28,    -1,    27,    -1,    28,    28,    27,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    31,    33,    41,    42,    43,    44,    58,
      59,    60,    62,    14,    45,    47,    14,    14,     0,    42,
       8,    27,    10,    12,    26,     8,     8,    27,    29,     8,
      14,    34,    35,    36,    37,    39,    44,    55,    56,    57,
      63,    64,    65,    66,    67,    68,    69,    70,    14,    16,
      46,    15,     4,    14,    15,    19,    29,    49,    51,    52,
      53,    54,    56,    57,    69,    70,    14,    45,    48,    48,
      61,     7,    29,     8,    49,     8,     8,    29,    29,    12,
      26,     8,    28,    63,     7,     7,    26,    13,    29,    52,
      52,    54,    51,    53,     3,     4,     5,     6,    20,    21,
      22,    23,    24,    25,    17,    18,    10,    12,    11,    28,
      30,    14,    49,    50,     8,    53,    53,    14,    15,    71,
      49,    14,    14,    49,    10,    26,    52,    30,    30,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    52,    53,
      53,    46,    15,    48,    32,    11,    30,    30,    30,    13,
       8,    46,    27,    13,    46,    50,    27,    27,    26,    50,
      10,    63,    63,    27,    28,    46,    28,    28,    50,    38,
      28,    27,    63,    28
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 143 "parser.yacc"
    {  
  root = A_Program((yyvsp[(1) - (1)].programElementList));
  (yyval.program) = A_Program((yyvsp[(1) - (1)].programElementList));
}
    break;

  case 3:
#line 150 "parser.yacc"
    {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[(1) - (2)].programElement), (yyvsp[(2) - (2)].programElementList));
}
    break;

  case 4:
#line 154 "parser.yacc"
    {
  (yyval.programElementList) = nullptr;
}
    break;

  case 5:
#line 160 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 6:
#line 164 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramStructDef((yyvsp[(1) - (1)].structDef)->pos, (yyvsp[(1) - (1)].structDef));
}
    break;

  case 7:
#line 168 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[(1) - (1)].fnDeclStmt)->pos, (yyvsp[(1) - (1)].fnDeclStmt));
}
    break;

  case 8:
#line 172 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDef((yyvsp[(1) - (1)].fnDef)->pos, (yyvsp[(1) - (1)].fnDef));
}
    break;

  case 9:
#line 176 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 10:
#line 184 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDecl)); 
}
    break;

  case 11:
#line 188 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDef)); 
}
    break;

  case 12:
#line 196 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (1)].tokenId)->pos, A_VarDeclScalar((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id, NULL));
}
    break;

  case 13:
#line 200 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDeclScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, (yyvsp[(3) - (3)].type)));
}
    break;

  case 14:
#line 204 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (4)].tokenId)->pos, A_VarDeclArray((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].tokenNum)->num, NULL));
}
    break;

  case 15:
#line 208 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (6)].tokenId)->pos, A_VarDeclArray((yyvsp[(1) - (6)].tokenId)->pos, (yyvsp[(1) - (6)].tokenId)->id, (yyvsp[(3) - (6)].tokenNum)->num, (yyvsp[(6) - (6)].type)));
}
    break;

  case 16:
#line 218 "parser.yacc"
    {
  (yyval.type) = A_NativeType((yyvsp[(1) - (1)].pos), A_intTypeKind); 
}
    break;

  case 17:
#line 222 "parser.yacc"
    {
  (yyval.type) = A_StructType((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id); 
}
    break;

  case 18:
#line 230 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, NULL, (yyvsp[(3) - (3)].rightVal)));
}
    break;

  case 19:
#line 234 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (5)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (5)].tokenId)->pos, (yyvsp[(1) - (5)].tokenId)->id, (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].rightVal))); 
}
    break;

  case 20:
#line 238 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (8)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (8)].tokenId)->pos, (yyvsp[(1) - (8)].tokenId)->id, (yyvsp[(3) - (8)].tokenNum)->num, NULL, (yyvsp[(7) - (8)].rightValList)));
}
    break;

  case 21:
#line 242 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (10)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (10)].tokenId)->pos, (yyvsp[(1) - (10)].tokenId)->id, (yyvsp[(3) - (10)].tokenNum)->num, (yyvsp[(6) - (10)].type), (yyvsp[(9) - (10)].rightValList)));
}
    break;

  case 22:
#line 248 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (1)].varDecl), NULL);
}
    break;

  case 23:
#line 252 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (3)].varDecl), (yyvsp[(3) - (3)].varDeclList));
}
    break;

  case 24:
#line 256 "parser.yacc"
    {
  (yyval.varDeclList) = NULL; 
}
    break;

  case 25:
#line 262 "parser.yacc"
    {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[(1) - (1)].arithExpr)->pos, (yyvsp[(1) - (1)].arithExpr)); 
}
    break;

  case 26:
#line 266 "parser.yacc"
    {
  (yyval.rightVal) = A_BoolExprRVal((yyvsp[(1) - (1)].boolExpr)->pos, (yyvsp[(1) - (1)].boolExpr)); 
}
    break;

  case 27:
#line 272 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (1)].rightVal), NULL); 
}
    break;

  case 28:
#line 276 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (3)].rightVal), (yyvsp[(3) - (3)].rightValList)); 
}
    break;

  case 29:
#line 280 "parser.yacc"
    {
  (yyval.rightValList) = NULL;
}
    break;

  case 30:
#line 286 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_add, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr))); 
}
    break;

  case 31:
#line 290 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_sub, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr))); 
}
    break;

  case 32:
#line 294 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_mul, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr))); 
}
    break;

  case 33:
#line 298 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_div, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr))); 
}
    break;

  case 34:
#line 302 "parser.yacc"
    {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[(1) - (1)].exprUnit)->pos, (yyvsp[(1) - (1)].exprUnit));
}
    break;

  case 35:
#line 309 "parser.yacc"
    {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num); 
}
    break;

  case 36:
#line 313 "parser.yacc"
    {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id); 
}
    break;

  case 37:
#line 317 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[(2) - (3)].arithExpr)->pos, (yyvsp[(2) - (3)].arithExpr)); 
}
    break;

  case 38:
#line 321 "parser.yacc"
    {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[(1) - (1)].fnCall)->pos, (yyvsp[(1) - (1)].fnCall)); 
}
    break;

  case 39:
#line 325 "parser.yacc"
    {
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (1)].arrayExpr)->pos, (yyvsp[(1) - (1)].arrayExpr));
}
    break;

  case 40:
#line 329 "parser.yacc"
    {
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[(1) - (1)].memberExpr)->pos, (yyvsp[(1) - (1)].memberExpr));
}
    break;

  case 41:
#line 333 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[(1) - (2)].pos), A_ArithUExpr((yyvsp[(1) - (2)].pos), A_neg, (yyvsp[(2) - (2)].exprUnit))); 
}
    break;

  case 42:
#line 340 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_and, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr))); 
}
    break;

  case 43:
#line 344 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_or, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr))); 
}
    break;

  case 44:
#line 348 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolExpr((yyvsp[(1) - (1)].boolUnit)->pos, (yyvsp[(1) - (1)].boolUnit)); 
}
    break;

  case 45:
#line 355 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_gt, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 46:
#line 359 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_ge, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 47:
#line 363 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_lt, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 48:
#line 367 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_le, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 49:
#line 371 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_eq, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 50:
#line 375 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (3)].exprUnit)->pos, A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos, A_ne, (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit))); 
}
    break;

  case 51:
#line 379 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].boolExpr)); 
}
    break;

  case 52:
#line 383 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[(1) - (2)].pos), A_BoolUOpExpr((yyvsp[(1) - (2)].pos), A_not, (yyvsp[(2) - (2)].boolUnit))); 
}
    break;

  case 53:
#line 391 "parser.yacc"
    {
  (yyval.assignStmt) = A_AssignStmt((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), (yyvsp[(3) - (4)].rightVal)); 
}
    break;

  case 54:
#line 398 "parser.yacc"
    {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id); 
}
    break;

  case 55:
#line 402 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (1)].arrayExpr)->pos, (yyvsp[(1) - (1)].arrayExpr));
}
    break;

  case 56:
#line 406 "parser.yacc"
    {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[(1) - (1)].memberExpr)->pos, (yyvsp[(1) - (1)].memberExpr));
}
    break;

  case 57:
#line 413 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].rightValList)); 
}
    break;

  case 58:
#line 420 "parser.yacc"
    {
  (yyval.structDef) = A_StructDef((yyvsp[(2) - (5)].tokenId)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].varDeclList)); 
}
    break;

  case 59:
#line 427 "parser.yacc"
    {
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[(1) - (2)].fnDecl)->pos, (yyvsp[(1) - (2)].fnDecl)); 
}
    break;

  case 60:
#line 435 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(2) - (5)].tokenId)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].paramDecl), NULL); 
}
    break;

  case 61:
#line 439 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(2) - (7)].tokenId)->pos, (yyvsp[(2) - (7)].tokenId)->id, (yyvsp[(4) - (7)].paramDecl), (yyvsp[(7) - (7)].type)); 
}
    break;

  case 62:
#line 446 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl((yyvsp[(1) - (1)].varDeclList)); 
}
    break;

  case 63:
#line 453 "parser.yacc"
    {
  (yyval.fnDef) = A_FnDef((yyvsp[(1) - (4)].fnDecl)->pos, (yyvsp[(1) - (4)].fnDecl), (yyvsp[(3) - (4)].codeBlockStmtList));
}
    break;

  case 64:
#line 460 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (1)].codeBlockStmt), NULL);
}
    break;

  case 65:
#line 464 "parser.yacc"
    {
  (yyval.codeBlockStmtList) =  A_CodeBlockStmtList((yyvsp[(1) - (2)].codeBlockStmt), (yyvsp[(2) - (2)].codeBlockStmtList)); 
}
    break;

  case 66:
#line 470 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt)); 
}
    break;

  case 67:
#line 474 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[(1) - (1)].assignStmt)->pos, (yyvsp[(1) - (1)].assignStmt)); 
}
    break;

  case 68:
#line 478 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[(1) - (1)].callStmt)->pos, (yyvsp[(1) - (1)].callStmt)); 
}
    break;

  case 69:
#line 482 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[(1) - (1)].ifStmt)->pos, (yyvsp[(1) - (1)].ifStmt)); 
}
    break;

  case 70:
#line 486 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[(1) - (1)].whileStmt)->pos, (yyvsp[(1) - (1)].whileStmt)); 
}
    break;

  case 71:
#line 490 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[(1) - (1)].returnStmt)->pos, (yyvsp[(1) - (1)].returnStmt)); 
}
    break;

  case 72:
#line 494 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[(1) - (2)].pos)); 
}
    break;

  case 73:
#line 498 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[(1) - (2)].pos)); 
}
    break;

  case 74:
#line 502 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[(1) - (1)].pos)); 
}
    break;

  case 75:
#line 509 "parser.yacc"
    {
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].rightVal)); 
}
    break;

  case 76:
#line 513 "parser.yacc"
    {
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[(1) - (2)].pos), NULL);
}
    break;

  case 77:
#line 520 "parser.yacc"
    {
  (yyval.callStmt) = A_CallStmt((yyvsp[(1) - (2)].fnCall)->pos, (yyvsp[(1) - (2)].fnCall)); 
}
    break;

  case 78:
#line 527 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (11)].pos), (yyvsp[(3) - (11)].boolExpr), (yyvsp[(6) - (11)].codeBlockStmtList), (yyvsp[(10) - (11)].codeBlockStmtList)); 
}
    break;

  case 79:
#line 531 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (7)].pos), (yyvsp[(3) - (7)].boolExpr), (yyvsp[(6) - (7)].codeBlockStmtList), NULL); 
}
    break;

  case 80:
#line 538 "parser.yacc"
    {
  (yyval.whileStmt) = A_WhileStmt((yyvsp[(1) - (7)].pos), (yyvsp[(3) - (7)].boolExpr), (yyvsp[(6) - (7)].codeBlockStmtList)); 
}
    break;

  case 81:
#line 544 "parser.yacc"
    {
  (yyval.memberExpr) = A_MemberExpr((yyvsp[(1) - (3)].tokenId)->pos, A_IdExprLVal((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id), (yyvsp[(3) - (3)].tokenId)->id); 
}
    break;

  case 82:
#line 548 "parser.yacc"
    {
  (yyval.memberExpr) = A_MemberExpr((yyvsp[(1) - (3)].arrayExpr)->pos, A_ArrExprLVal((yyvsp[(1) - (3)].arrayExpr)->pos, (yyvsp[(1) - (3)].arrayExpr)), (yyvsp[(3) - (3)].tokenId)->id);
}
    break;

  case 83:
#line 552 "parser.yacc"
    {
  (yyval.memberExpr) = A_MemberExpr((yyvsp[(1) - (3)].memberExpr)->pos, A_MemberExprLVal((yyvsp[(1) - (3)].memberExpr)->pos, (yyvsp[(1) - (3)].memberExpr)), (yyvsp[(3) - (3)].tokenId)->id);
}
    break;

  case 84:
#line 559 "parser.yacc"
    {
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), (yyvsp[(3) - (4)].indexExpr));
}
    break;

  case 85:
#line 565 "parser.yacc"
    {
    (yyval.indexExpr) = A_NumIndexExpr((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 86:
#line 569 "parser.yacc"
    {
    (yyval.indexExpr) = A_IdIndexExpr((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
}
    break;


/* Line 1267 of yacc.c.  */
#line 2196 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 574 "parser.yacc"


extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "语法错误：%s\n",s);
}
int yywrap()
{
  return(1);
}
}



