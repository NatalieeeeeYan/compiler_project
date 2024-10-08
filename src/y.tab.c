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
     SEMICOLON = 262,
     COLON = 263,
     COMMA = 264,
     ID = 265,
     NUM = 266,
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
     RCUR = 294,
     NEG = 295
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
#define NUM 266
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
#define NEG 295




/* Copy the first part of user declarations.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
}
/* Line 193 of yacc.c.  */
#line 222 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "y.tab.c"

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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    23,    27,    31,    35,    37,    39,    41,    45,    48,
      50,    55,    60,    64,    68,    72,    74,    80,    86,    92,
      98,   104,   110,   114,   117,   119,   124,   129,   133,   135,
     139,   141,   146,   150,   154,   158,   162,   169,   171,   176,
     182,   186,   197,   206,   208,   210,   214,   216,   218,   219,
     225,   228,   234,   242,   247,   250,   252,   254,   259,   262,
     274,   282,   290,   294,   297,   300,   303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    43,    -1,    -1,    53,
      -1,    59,    -1,    60,    -1,    62,    -1,     7,    -1,    45,
       3,    45,    -1,    45,     4,    45,    -1,    45,     5,    45,
      -1,    45,     6,    45,    -1,    46,    -1,    10,    -1,    11,
      -1,    12,    45,    13,    -1,     4,    46,    -1,    52,    -1,
      49,    14,    10,    15,    -1,    49,    14,    11,    15,    -1,
      49,    16,    10,    -1,    47,    17,    47,    -1,    47,    18,
      47,    -1,    48,    -1,    12,    46,    23,    46,    13,    -1,
      12,    46,    24,    46,    13,    -1,    12,    46,    19,    46,
      13,    -1,    12,    46,    20,    46,    13,    -1,    12,    46,
      21,    46,    13,    -1,    12,    46,    22,    46,    13,    -1,
      12,    47,    13,    -1,    25,    48,    -1,    10,    -1,    49,
      14,    10,    15,    -1,    49,    14,    11,    15,    -1,    49,
      16,    10,    -1,    45,    -1,    50,     9,    51,    -1,    50,
      -1,    10,    12,    51,    13,    -1,    10,    12,    13,    -1,
      27,    54,     7,    -1,    27,    55,     7,    -1,    10,     8,
      56,    -1,    10,    14,    11,    15,     8,    56,    -1,    10,
      -1,    10,    14,    11,    15,    -1,    10,     8,    56,    26,
      50,    -1,    10,    26,    50,    -1,    10,    14,    11,    15,
       8,    56,    26,    38,    51,    39,    -1,    10,    14,    11,
      15,    26,    38,    51,    39,    -1,    36,    -1,    10,    -1,
      54,     9,    57,    -1,    54,    -1,    57,    -1,    -1,    35,
      10,    38,    57,    39,    -1,    61,     7,    -1,    34,    10,
      12,    58,    13,    -1,    34,    10,    12,    58,    13,    37,
      56,    -1,    61,    38,    63,    39,    -1,    64,    63,    -1,
      64,    -1,    53,    -1,    49,    26,    50,     7,    -1,    52,
       7,    -1,    28,    12,    47,    13,    38,    63,    39,    29,
      38,    63,    39,    -1,    28,    12,    47,    13,    38,    63,
      39,    -1,    30,    12,    47,    13,    38,    63,    39,    -1,
      33,    50,     7,    -1,    33,     7,    -1,    32,     7,    -1,
      31,     7,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   148,   153,   158,   162,   166,   170,   174,
     181,   185,   189,   193,   197,   203,   207,   211,   215,   219,
     223,   227,   231,   238,   242,   246,   253,   257,   261,   265,
     269,   273,   277,   281,   288,   292,   296,   300,   306,   320,
     324,   330,   334,   340,   344,   350,   354,   358,   362,   367,
     371,   375,   379,   385,   389,   395,   399,   405,   410,   416,
     422,   428,   432,   438,   444,   448,   454,   458,   462,   466,
     470,   474,   478,   482,   486,   490,   494
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "SEMICOLON",
  "COLON", "COMMA", "ID", "NUM", "LPAR", "RPAR", "LBRA", "RBRA", "DOT",
  "AND", "OR", "GE", "LE", "EQUAL", "NE", "GT", "LT", "NOT", "ASSIGN",
  "LET", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RET", "FN", "STRUCT",
  "INT", "ARR", "LCUR", "RCUR", "NEG", "$accept", "Program",
  "ProgramElementList", "ProgramElement", "ArithExpr", "ExprUnit",
  "BoolExpr", "BoolUnit", "LeftVal", "RightVal", "RightValList", "FnCall",
  "VarDeclStmt", "VarDecl", "VarDef", "Type", "VarDeclList", "ParamDecl",
  "StructDef", "FnDeclStmt", "FnDecl", "FnDef", "CodeBlockStmtList",
  "CodeBlockStmt", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      60,    61,    61,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     3,     2,     1,
       4,     4,     3,     3,     3,     1,     5,     5,     5,     5,
       5,     5,     3,     2,     1,     4,     4,     3,     1,     3,
       1,     4,     3,     3,     3,     3,     6,     1,     4,     5,
       3,    10,     8,     1,     1,     3,     1,     1,     0,     5,
       2,     5,     7,     4,     2,     1,     1,     4,     2,    11,
       7,     7,     3,     2,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     9,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,     8,    47,     0,     0,     0,     0,     1,     3,
      60,     0,     0,     0,     0,    43,    44,    58,     0,    76,
      34,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      65,    54,    53,    45,     0,     0,    15,    16,     0,    38,
      14,     0,    50,    19,    47,    56,    57,     0,     0,     0,
       0,     0,    75,    74,    73,     0,     0,     0,     0,    68,
      63,    64,     0,    48,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    59,    42,    40,     0,
       0,     0,     0,    25,     0,    72,     0,     0,    37,     0,
      49,     0,     0,    17,    10,    11,    12,    13,     0,     0,
      22,    45,     0,    55,     0,     0,    41,     0,     0,     0,
      33,     0,     0,     0,     0,    35,    36,    67,    46,     0,
      20,    21,    48,    62,    39,    14,     0,     0,     0,     0,
       0,     0,    32,     0,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      46,    28,    29,    30,    31,    26,    27,    70,    71,     0,
       0,    51,     0,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    49,    50,   119,    93,    51,    88,
      89,    53,    38,    55,    15,    43,    56,    57,     9,    10,
      11,    12,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
       9,  -108,     7,    20,    30,    14,  -108,     9,  -108,  -108,
    -108,     4,  -108,    15,    46,    50,    52,    29,  -108,  -108,
    -108,    49,     2,    63,   120,  -108,  -108,    94,    94,  -108,
      66,   102,   106,   121,   126,   109,    36,   146,  -108,   111,
      49,  -108,  -108,   112,   139,   120,   129,  -108,   120,   143,
    -108,    47,  -108,  -108,    41,   147,  -108,   142,   118,    99,
       3,     3,  -108,  -108,  -108,   151,    16,   149,   120,  -108,
    -108,  -108,   120,     5,  -108,    80,   120,   120,   120,   120,
      90,   150,     2,   152,    94,   124,  -108,  -108,   153,   154,
      35,     3,    53,  -108,    89,  -108,   155,   156,  -108,   157,
    -108,     2,   127,  -108,   131,   131,  -108,  -108,   158,   159,
     101,  -108,   160,  -108,     2,   120,  -108,    35,    68,   122,
    -108,   130,     3,     3,   134,  -108,  -108,  -108,   140,   120,
     113,   128,   161,  -108,  -108,    68,   120,   120,   120,   120,
     120,   120,  -108,    49,  -108,   162,    49,   138,   141,     2,
     164,   165,   168,   169,   170,   171,   148,   163,   120,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,   166,  -108,   167,
     172,  -108,    49,   173,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   178,  -108,   -44,   -42,   -54,    95,   -21,   -14,
    -107,   -20,    18,   186,  -108,   -77,   -19,  -108,  -108,  -108,
    -108,  -108,   -38,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      36,    37,    71,    74,    75,   111,    92,    94,   134,    58,
      52,    20,    41,   101,    18,    90,     1,    13,     8,    36,
      37,    65,   148,    22,   128,     8,    96,    97,    91,    23,
      16,   102,   104,   105,   106,   107,     2,   133,    42,    45,
      17,    24,    21,     3,     4,    46,    47,   117,   118,    82,
      66,   169,    67,    25,    99,    83,    29,    26,   100,    30,
      91,    80,    68,    81,    27,   113,   121,    28,   144,   145,
     122,   123,   160,    75,    44,   135,     2,    31,    59,    32,
      33,    34,    35,    76,    77,    78,    79,   136,   137,   138,
     139,   140,   141,   103,   150,   151,   152,   153,   154,   155,
     108,   109,   124,    45,    54,   156,   122,   123,   157,    46,
      47,    48,    87,    45,    60,   -37,    64,   -37,    61,    46,
      47,    48,    36,    37,    45,    36,    37,   -35,    62,   -35,
      46,    47,    48,    63,   173,   142,    78,    79,    72,   122,
     123,    59,   -36,   -34,   -36,   -34,    76,    77,    78,    79,
      70,    36,    37,    69,    73,    85,    84,    86,    95,    98,
     110,   114,   115,   112,   127,   129,   147,   116,   143,   149,
     125,   126,   146,   130,   131,   132,   158,   161,   162,   122,
     159,   163,   164,   165,   166,    19,   120,   167,    14,     0,
       0,     0,     0,     0,     0,   170,     0,     0,     0,     0,
       0,     0,   168,     0,     0,     0,   171,     0,     0,     0,
     172,     0,   174
};

static const yytype_int16 yycheck[] =
{
      21,    21,    40,    45,    48,    82,    60,    61,   115,    28,
      24,     7,    10,     8,     0,    12,     7,    10,     0,    40,
      40,    35,   129,     8,   101,     7,    10,    11,    25,    14,
      10,    26,    76,    77,    78,    79,    27,   114,    36,     4,
      10,    26,    38,    34,    35,    10,    11,    12,    90,     8,
      14,   158,    16,     7,    68,    14,     7,     7,    72,    10,
      25,    14,    26,    16,    12,    84,    13,    38,   122,   123,
      17,    18,   149,   117,    11,   117,    27,    28,    12,    30,
      31,    32,    33,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    24,    13,   136,   137,   138,   139,   140,   141,
      10,    11,    13,     4,    10,   143,    17,    18,   146,    10,
      11,    12,    13,     4,    12,    14,     7,    16,    12,    10,
      11,    12,   143,   143,     4,   146,   146,    14,     7,    16,
      10,    11,    12,     7,   172,    13,     5,     6,    26,    17,
      18,    12,    14,    14,    16,    16,     3,     4,     5,     6,
      39,   172,   172,     7,    15,    13,     9,    39,     7,    10,
      10,    37,     9,    11,     7,    38,    26,    13,    38,     8,
      15,    15,    38,    15,    15,    15,    38,    13,    13,    17,
      39,    13,    13,    13,    13,     7,    91,    39,     2,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      38,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    27,    34,    35,    42,    43,    44,    53,    59,
      60,    61,    62,    10,    54,    55,    10,    10,     0,    43,
       7,    38,     8,    14,    26,     7,     7,    12,    38,     7,
      10,    28,    30,    31,    32,    33,    49,    52,    53,    63,
      64,    10,    36,    56,    11,     4,    10,    11,    12,    45,
      46,    49,    50,    52,    10,    54,    57,    58,    57,    12,
      12,    12,     7,     7,     7,    50,    14,    16,    26,     7,
      39,    63,    26,    15,    46,    45,     3,     4,     5,     6,
      14,    16,     8,    14,     9,    13,    39,    13,    50,    51,
      12,    25,    47,    48,    47,     7,    10,    11,    10,    50,
      50,     8,    26,    13,    45,    45,    45,    45,    10,    11,
      10,    56,    11,    57,    37,     9,    13,    12,    46,    47,
      48,    13,    17,    18,    13,    15,    15,     7,    56,    38,
      15,    15,    15,    56,    51,    46,    19,    20,    21,    22,
      23,    24,    13,    38,    47,    47,    38,    26,    51,     8,
      46,    46,    46,    46,    46,    46,    63,    63,    38,    39,
      56,    13,    13,    13,    13,    13,    13,    39,    39,    51,
      29,    39,    38,    63,    39
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
#line 142 "parser.yacc"
    {  
  root = A_Program((yyvsp[(1) - (1)].programElementList));
  (yyval.program) = A_Program((yyvsp[(1) - (1)].programElementList));
}
    break;

  case 3:
#line 149 "parser.yacc"
    {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[(1) - (2)].programElement), (yyvsp[(2) - (2)].programElementList));
}
    break;

  case 4:
#line 153 "parser.yacc"
    {
  (yyval.programElementList) = nullptr;
}
    break;

  case 5:
#line 159 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 6:
#line 163 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramStructDef((yyvsp[(1) - (1)].structDef)->pos, (yyvsp[(1) - (1)].structDef));
}
    break;

  case 7:
#line 167 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[(1) - (1)].fnDeclStmt)->pos, (yyvsp[(1) - (1)].fnDeclStmt));
}
    break;

  case 8:
#line 171 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDef((yyvsp[(1) - (1)].fnDef)->pos, (yyvsp[(1) - (1)].fnDef));
}
    break;

  case 9:
#line 175 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 10:
#line 182 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_add, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 11:
#line 186 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_sub, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 12:
#line 190 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_mul, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 13:
#line 194 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_div, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 14:
#line 198 "parser.yacc"
    {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[(1) - (1)].exprUnit)->pos, (yyvsp[(1) - (1)].exprUnit));
}
    break;

  case 15:
#line 204 "parser.yacc"
    {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 16:
#line 208 "parser.yacc"
    {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 17:
#line 212 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[(2) - (3)].arithExpr)->pos, (yyvsp[(2) - (3)].arithExpr));
}
    break;

  case 18:
#line 216 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[(1) - (2)].pos), A_ArithUExpr((yyvsp[(2) - (2)].exprUnit)->pos, A_neg, (yyvsp[(2) - (2)].exprUnit)));
}
    break;

  case 19:
#line 220 "parser.yacc"
    {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[(1) - (1)].fnCall)->pos, (yyvsp[(1) - (1)].fnCall));
}
    break;

  case 20:
#line 224 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (4)].leftVal)->pos, A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), A_IdIndexExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(3) - (4)].tokenId)->id)));
}
    break;

  case 21:
#line 228 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (4)].leftVal)->pos, A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), A_NumIndexExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(3) - (4)].tokenNum)->num)));
}
    break;

  case 22:
#line 232 "parser.yacc"
    {
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[(1) - (3)].leftVal)->pos, A_MemberExpr((yyvsp[(1) - (3)].leftVal)->pos, (yyvsp[(1) - (3)].leftVal), (yyvsp[(3) - (3)].tokenId)->id));
}
    break;

  case 23:
#line 239 "parser.yacc"
    {
 (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_and, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr)));
}
    break;

  case 24:
#line 243 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_or, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr)));
}
    break;

  case 25:
#line 247 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolExpr((yyvsp[(1) - (1)].boolUnit)->pos, (yyvsp[(1) - (1)].boolUnit));
}
    break;

  case 26:
#line 254 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_gt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 27:
#line 258 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_lt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 28:
#line 262 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_ge, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 29:
#line 266 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_le, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 30:
#line 270 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_eq, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 31:
#line 274 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_ne, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 32:
#line 278 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[(2) - (3)].boolExpr)->pos, (yyvsp[(2) - (3)].boolExpr));
}
    break;

  case 33:
#line 282 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[(1) - (2)].pos), A_BoolUOpExpr((yyvsp[(1) - (2)].pos), A_not, (yyvsp[(2) - (2)].boolUnit)));
}
    break;

  case 34:
#line 289 "parser.yacc"
    {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 35:
#line 293 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (4)].leftVal)->pos,A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos,(yyvsp[(1) - (4)].leftVal),A_IdIndexExpr((yyvsp[(3) - (4)].tokenId)->pos,(yyvsp[(3) - (4)].tokenId)->id)));
}
    break;

  case 36:
#line 297 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (4)].leftVal)->pos,A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos,(yyvsp[(1) - (4)].leftVal),A_NumIndexExpr((yyvsp[(3) - (4)].tokenNum)->pos,(yyvsp[(3) - (4)].tokenNum)->num)));
}
    break;

  case 37:
#line 301 "parser.yacc"
    {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[(1) - (3)].leftVal)->pos,A_MemberExpr((yyvsp[(1) - (3)].leftVal)->pos,(yyvsp[(1) - (3)].leftVal),(yyvsp[(3) - (3)].tokenId)->id)); // $1todo
}
    break;

  case 38:
#line 307 "parser.yacc"
    {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[(1) - (1)].arithExpr)->pos, (yyvsp[(1) - (1)].arithExpr));
}
    break;

  case 39:
#line 321 "parser.yacc"
    {
  (yyval.rightValList)=A_RightValList((yyvsp[(1) - (3)].rightVal), (yyvsp[(3) - (3)].rightValList));
}
    break;

  case 40:
#line 325 "parser.yacc"
    {
  (yyval.rightValList)=A_RightValList((yyvsp[(1) - (1)].rightVal), nullptr);
}
    break;

  case 41:
#line 331 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id,(yyvsp[(3) - (4)].rightValList));
}
    break;

  case 42:
#line 335 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, nullptr);
}
    break;

  case 43:
#line 341 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDecl));
}
    break;

  case 44:
#line 345 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDef));
}
    break;

  case 45:
#line 351 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDeclScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, (yyvsp[(3) - (3)].type)));
}
    break;

  case 46:
#line 355 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (6)].tokenId)->pos,  A_VarDeclArray((yyvsp[(1) - (6)].tokenId)->pos, (yyvsp[(1) - (6)].tokenId)->id, (yyvsp[(3) - (6)].tokenNum)->num, (yyvsp[(6) - (6)].type)));
}
    break;

  case 47:
#line 359 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (1)].tokenId)->pos,  A_VarDeclScalar((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id, nullptr));
}
    break;

  case 48:
#line 363 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (4)].tokenId)->pos,  A_VarDeclArray((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].tokenNum)->num, nullptr));
}
    break;

  case 49:
#line 368 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (5)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (5)].tokenId)->pos, (yyvsp[(1) - (5)].tokenId)->id, (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].rightVal)));
}
    break;

  case 50:
#line 372 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, nullptr, (yyvsp[(3) - (3)].rightVal)));
}
    break;

  case 51:
#line 376 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (10)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (10)].tokenId)->pos, (yyvsp[(1) - (10)].tokenId)->id, (yyvsp[(3) - (10)].tokenNum)->num, (yyvsp[(6) - (10)].type), (yyvsp[(9) - (10)].rightValList)));
}
    break;

  case 52:
#line 380 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (8)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (8)].tokenId)->pos, (yyvsp[(1) - (8)].tokenId)->id, (yyvsp[(3) - (8)].tokenNum)->num, nullptr, (yyvsp[(7) - (8)].rightValList)));
}
    break;

  case 53:
#line 386 "parser.yacc"
    {
  (yyval.type) = A_NativeType((yyvsp[(1) - (1)].pos), A_intTypeKind);
}
    break;

  case 54:
#line 390 "parser.yacc"
    {
  (yyval.type) = A_StructType((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 55:
#line 396 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (3)].varDecl), (yyvsp[(3) - (3)].varDeclList));
}
    break;

  case 56:
#line 400 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (1)].varDecl), NULL);
}
    break;

  case 57:
#line 406 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl((yyvsp[(1) - (1)].varDeclList));
}
    break;

  case 58:
#line 410 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl(nullptr);
}
    break;

  case 59:
#line 417 "parser.yacc"
    {
  (yyval.structDef) = A_StructDef((yyvsp[(2) - (5)].tokenId)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].varDeclList));  // $2->pos todo 
}
    break;

  case 60:
#line 423 "parser.yacc"
    {
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[(1) - (2)].fnDecl)->pos, (yyvsp[(1) - (2)].fnDecl));
}
    break;

  case 61:
#line 429 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (5)].pos), (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].paramDecl), nullptr);
}
    break;

  case 62:
#line 433 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (7)].pos), (yyvsp[(2) - (7)].tokenId)->id, (yyvsp[(4) - (7)].paramDecl), (yyvsp[(7) - (7)].type));
}
    break;

  case 63:
#line 439 "parser.yacc"
    {
  (yyval.fnDef) = A_FnDef((yyvsp[(1) - (4)].fnDecl)->pos, (yyvsp[(1) - (4)].fnDecl), (yyvsp[(3) - (4)].codeBlockStmtList));
}
    break;

  case 64:
#line 445 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (2)].codeBlockStmt), (yyvsp[(2) - (2)].codeBlockStmtList));
}
    break;

  case 65:
#line 449 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (1)].codeBlockStmt), nullptr);
}
    break;

  case 66:
#line 455 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 67:
#line 459 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[(1) - (4)].leftVal)->pos, A_AssignStmt((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), (yyvsp[(3) - (4)].rightVal)));
}
    break;

  case 68:
#line 463 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[(1) - (2)].fnCall)->pos, A_CallStmt((yyvsp[(1) - (2)].fnCall)->pos, (yyvsp[(1) - (2)].fnCall)));
}
    break;

  case 69:
#line 467 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[(1) - (11)].pos), A_IfStmt((yyvsp[(1) - (11)].pos), A_BoolExprUnit((yyvsp[(3) - (11)].boolExpr)->pos, (yyvsp[(3) - (11)].boolExpr)), (yyvsp[(6) - (11)].codeBlockStmtList), (yyvsp[(10) - (11)].codeBlockStmtList)));
}
    break;

  case 70:
#line 471 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[(1) - (7)].pos), A_IfStmt((yyvsp[(1) - (7)].pos), A_BoolExprUnit((yyvsp[(3) - (7)].boolExpr)->pos, (yyvsp[(3) - (7)].boolExpr)), (yyvsp[(6) - (7)].codeBlockStmtList), NULL));
}
    break;

  case 71:
#line 475 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[(1) - (7)].pos), A_WhileStmt((yyvsp[(1) - (7)].pos), A_BoolExprUnit((yyvsp[(3) - (7)].boolExpr)->pos, (yyvsp[(3) - (7)].boolExpr)), (yyvsp[(6) - (7)].codeBlockStmtList)));
}
    break;

  case 72:
#line 479 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockReturnStmt((yyvsp[(1) - (3)].pos), A_ReturnStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].rightVal)));
}
    break;

  case 73:
#line 483 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockReturnStmt((yyvsp[(1) - (2)].pos), A_ReturnStmt((yyvsp[(1) - (2)].pos), nullptr));
}
    break;

  case 74:
#line 487 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockContinueStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 75:
#line 491 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 76:
#line 495 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[(1) - (1)].pos));
}
    break;


/* Line 1267 of yacc.c.  */
#line 2111 "y.tab.c"
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


#line 501 "parser.yacc"


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



