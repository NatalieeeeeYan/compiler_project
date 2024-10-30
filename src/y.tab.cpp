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
/* Line 193 of yacc.c.  */
#line 223 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 236 "y.tab.cpp"

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
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

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
      19,    21,    24,    28,    32,    36,    40,    42,    44,    46,
      50,    52,    57,    62,    66,    70,    74,    76,    82,    88,
      94,   100,   106,   112,   116,   119,   125,   131,   137,   143,
     149,   155,   159,   164,   166,   171,   176,   180,   182,   186,
     188,   193,   197,   201,   205,   209,   216,   218,   223,   229,
     233,   244,   253,   255,   257,   261,   263,   265,   266,   272,
     275,   281,   289,   294,   297,   299,   300,   302,   304,   307,
     309,   311,   315,   318,   321,   324,   326,   332,   338,   348
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    42,    -1,    -1,    54,
      -1,    60,    -1,    61,    -1,    63,    -1,     7,    -1,    11,
      -1,     4,    11,    -1,    45,     3,    45,    -1,    45,     4,
      45,    -1,    45,     5,    45,    -1,    45,     6,    45,    -1,
      46,    -1,    44,    -1,    10,    -1,    12,    45,    13,    -1,
      53,    -1,    50,    14,    10,    15,    -1,    50,    14,    44,
      15,    -1,    50,    16,    10,    -1,    47,    17,    47,    -1,
      47,    18,    47,    -1,    48,    -1,    12,    46,    23,    46,
      13,    -1,    12,    46,    19,    46,    13,    -1,    12,    46,
      24,    46,    13,    -1,    12,    46,    20,    46,    13,    -1,
      12,    46,    21,    46,    13,    -1,    12,    46,    22,    46,
      13,    -1,    12,    47,    13,    -1,    25,    48,    -1,    12,
      46,    23,    46,    13,    -1,    12,    46,    24,    46,    13,
      -1,    12,    46,    19,    46,    13,    -1,    12,    46,    20,
      46,    13,    -1,    12,    46,    21,    46,    13,    -1,    12,
      46,    22,    46,    13,    -1,    12,    47,    13,    -1,    12,
      25,    48,    13,    -1,    10,    -1,    50,    14,    10,    15,
      -1,    50,    14,    44,    15,    -1,    50,    16,    10,    -1,
      45,    -1,    51,     9,    52,    -1,    51,    -1,    10,    12,
      52,    13,    -1,    10,    12,    13,    -1,    27,    55,     7,
      -1,    27,    56,     7,    -1,    10,     8,    57,    -1,    10,
      14,    44,    15,     8,    57,    -1,    10,    -1,    10,    14,
      44,    15,    -1,    10,     8,    57,    26,    51,    -1,    10,
      26,    51,    -1,    10,    14,    44,    15,     8,    57,    26,
      38,    52,    39,    -1,    10,    14,    44,    15,    26,    38,
      52,    39,    -1,    36,    -1,    10,    -1,    55,     9,    58,
      -1,    55,    -1,    58,    -1,    -1,    35,    10,    38,    58,
      39,    -1,    62,     7,    -1,    34,    10,    12,    59,    13,
      -1,    34,    10,    12,    59,    13,    37,    57,    -1,    62,
      38,    64,    39,    -1,    65,    64,    -1,    65,    -1,    -1,
      54,    -1,    68,    -1,    53,     7,    -1,    67,    -1,    66,
      -1,    33,    51,     7,    -1,    33,     7,    -1,    32,     7,
      -1,    31,     7,    -1,     7,    -1,    30,    49,    38,    64,
      39,    -1,    28,    49,    38,    64,    39,    -1,    28,    49,
      38,    64,    39,    29,    38,    64,    39,    -1,    50,    26,
      51,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   156,   161,   166,   170,   174,   178,   182,
     188,   192,   198,   202,   206,   210,   214,   220,   224,   228,
     232,   236,   240,   244,   250,   254,   258,   264,   268,   272,
     276,   280,   284,   288,   292,   297,   301,   305,   309,   313,
     317,   321,   325,   331,   335,   339,   343,   349,   363,   367,
     373,   377,   383,   387,   393,   397,   401,   405,   410,   414,
     418,   422,   428,   432,   438,   442,   448,   453,   458,   464,
     470,   474,   480,   486,   490,   495,   500,   504,   508,   512,
     516,   520,   524,   528,   532,   536,   542,   548,   552,   558
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "SEMICOLON",
  "COLON", "COMMA", "ID", "UNUM", "LPAR", "RPAR", "LBRA", "RBRA", "DOT",
  "AND", "OR", "GE", "LE", "EQUAL", "NE", "GT", "LT", "NOT", "ASSIGN",
  "LET", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RET", "FN", "STRUCT",
  "INT", "ARR", "LCUR", "RCUR", "$accept", "Program", "ProgramElementList",
  "ProgramElement", "NUM", "ArithExpr", "ExprUnit", "BoolExpr", "BoolUnit",
  "BoolUnit_", "LeftVal", "RightVal", "RightValList", "FnCall",
  "VarDeclStmt", "VarDecl", "VarDef", "Type", "VarDeclList", "ParamDecl",
  "StructDef", "FnDeclStmt", "FnDecl", "FnDef", "CodeBlockStmtList",
  "CodeBlockStmt", "WhileStmt", "IfStmt", "AssignStmt", 0
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
      44,    44,    45,    45,    45,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    47,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      62,    62,    63,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     3,     1,     5,     5,     5,
       5,     5,     5,     3,     2,     5,     5,     5,     5,     5,
       5,     3,     4,     1,     4,     4,     3,     1,     3,     1,
       4,     3,     3,     3,     3,     6,     1,     4,     5,     3,
      10,     8,     1,     1,     3,     1,     1,     0,     5,     2,
       5,     7,     4,     2,     1,     0,     1,     1,     2,     1,
       1,     3,     2,     2,     2,     1,     5,     5,     9,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     9,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,     8,    56,     0,     0,     0,     0,     1,     3,
      69,    75,     0,     0,     0,    52,    53,    67,     0,    85,
      43,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      74,    80,    79,    77,    63,    62,    54,     0,    10,     0,
      18,     0,    17,    47,    16,     0,    59,    20,    56,    65,
      66,     0,     0,     0,     0,     0,     0,    84,    83,    82,
       0,     0,     0,     0,    78,    72,    73,     0,    11,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    68,    51,    49,     0,     0,     0,     0,     0,    26,
      75,    75,    81,     0,     0,    46,     0,    58,     0,     0,
      19,    12,    13,    14,    15,     0,     0,    23,    54,     0,
      64,     0,     0,    50,     0,    16,     0,     0,    34,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
      44,    45,    89,    55,     0,    21,    22,    57,    71,    48,
      34,     0,     0,     0,     0,     0,     0,    33,     0,    42,
       0,     0,     0,     0,     0,     0,    24,    25,    87,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    35,    36,     0,     0,    61,    55,    28,
      30,    31,    32,    27,    29,    75,     0,     0,    60,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    52,    53,    54,   126,    99,    65,
      55,    93,    94,    57,    38,    59,    15,    46,    60,    61,
       9,    10,    11,    12,    39,    40,    41,    42,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
      10,  -113,     4,    17,    38,    22,  -113,    10,  -113,  -113,
    -113,     5,  -113,    49,    48,    52,    64,    46,  -113,  -113,
    -113,    19,    18,     9,   125,  -113,  -113,    91,    91,  -113,
     101,   107,   107,   119,   120,   121,    72,   123,  -113,    99,
      19,  -113,  -113,  -113,  -113,  -113,   117,   153,  -113,   151,
     100,   125,  -113,   149,  -113,    71,  -113,  -113,   131,   163,
    -113,   165,   140,   111,    92,   142,   143,  -113,  -113,  -113,
     175,    54,   173,   125,  -113,  -113,  -113,   125,  -113,     7,
     105,   125,   125,   125,   125,   130,   174,    18,     9,    91,
     148,  -113,  -113,   177,   176,    95,    -1,   127,   150,  -113,
      19,    19,  -113,   172,   178,  -113,   181,  -113,    18,   154,
    -113,    25,    25,  -113,  -113,   179,   180,   128,  -113,   182,
    -113,    18,   125,  -113,    -1,   138,   152,    95,   183,   125,
     125,   125,   125,   125,   125,  -113,    -1,    -1,   159,   160,
    -113,  -113,  -113,   164,   125,   157,   161,   192,  -113,  -113,
    -113,   125,   125,   125,   125,   125,   125,  -113,   138,  -113,
     188,   189,   190,   191,   193,   194,  -113,   195,   162,  -113,
     167,   169,    18,   196,   197,   198,   200,   201,   202,  -113,
    -113,  -113,  -113,  -113,  -113,   184,   125,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,    19,   185,   186,  -113,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   209,  -113,    12,   -42,   -61,   -59,   -88,   187,
     -21,   -17,  -112,   -19,    16,   215,  -113,   -83,   -22,  -113,
    -113,  -113,  -113,  -113,   -39,  -113,  -113,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      36,    76,    37,    97,   118,    98,    62,    56,   128,    80,
     149,   127,    20,    47,    13,   108,     8,     1,    70,    36,
      48,    37,    18,     8,   124,   143,    29,    16,    44,    30,
      83,    84,   171,   109,   125,    49,   150,     2,   148,   111,
     112,   113,   114,    21,     3,     4,     2,    31,    17,    32,
      33,    34,    35,    80,    45,    25,   106,    22,    47,    26,
     107,   138,   139,    23,   103,    48,   158,   120,   160,   161,
     162,   163,   164,   165,   196,    24,    27,   166,   167,    36,
      36,    37,    37,   104,    28,    85,    71,    86,    72,   188,
     173,   174,   175,   176,   177,   178,    47,   116,    73,    47,
     119,    58,    50,    48,    95,    50,    48,    95,    81,    82,
      83,    84,    63,    63,   -43,    47,   -43,    96,   110,    64,
     124,    50,    48,    51,    92,    47,    67,    68,    69,    47,
      74,    50,    48,    51,    47,    50,    48,    51,    75,    87,
     115,    48,   -46,    77,   -46,    88,   129,   130,   131,   132,
     133,   134,    81,    82,    83,    84,   197,   151,   152,   153,
     154,   155,   156,   135,    78,   157,    79,   136,   137,   136,
     137,   -44,    89,   -44,    36,   -45,    37,   -45,    90,    91,
     100,   101,   102,   105,   117,   121,   122,   140,   142,   123,
     170,   185,   144,   141,   145,   146,   159,   147,   168,   169,
     172,   179,   180,   181,   182,   186,   183,   184,   187,   189,
     190,   191,   136,   192,   193,   194,    19,    14,     0,    66,
       0,     0,   195,     0,   198,   199
};

static const yytype_int16 yycheck[] =
{
      21,    40,    21,    64,    87,    64,    28,    24,    96,    51,
     122,    12,     7,     4,    10,     8,     0,     7,    35,    40,
      11,    40,     0,     7,    25,   108,     7,    10,    10,    10,
       5,     6,   144,    26,    95,    23,   124,    27,   121,    81,
      82,    83,    84,    38,    34,    35,    27,    28,    10,    30,
      31,    32,    33,    95,    36,     7,    73,     8,     4,     7,
      77,   100,   101,    14,    10,    11,   127,    89,   129,   130,
     131,   132,   133,   134,   186,    26,    12,   136,   137,   100,
     101,   100,   101,    71,    38,    14,    14,    16,    16,   172,
     151,   152,   153,   154,   155,   156,     4,    85,    26,     4,
      88,    10,    10,    11,    12,    10,    11,    12,     3,     4,
       5,     6,    12,    12,    14,     4,    16,    25,    13,    12,
      25,    10,    11,    12,    13,     4,     7,     7,     7,     4,
       7,    10,    11,    12,     4,    10,    11,    12,    39,     8,
      10,    11,    14,    26,    16,    14,    19,    20,    21,    22,
      23,    24,     3,     4,     5,     6,   195,    19,    20,    21,
      22,    23,    24,    13,    11,    13,    15,    17,    18,    17,
      18,    14,     9,    16,   195,    14,   195,    16,    13,    39,
      38,    38,     7,    10,    10,    37,     9,    15,     7,    13,
      26,    29,    38,    15,    15,    15,    13,    15,    39,    39,
       8,    13,    13,    13,    13,    38,    13,    13,    39,    13,
      13,    13,    17,    13,    13,    13,     7,     2,    -1,    32,
      -1,    -1,    38,    -1,    39,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    27,    34,    35,    41,    42,    43,    54,    60,
      61,    62,    63,    10,    55,    56,    10,    10,     0,    42,
       7,    38,     8,    14,    26,     7,     7,    12,    38,     7,
      10,    28,    30,    31,    32,    33,    50,    53,    54,    64,
      65,    66,    67,    68,    10,    36,    57,     4,    11,    44,
      10,    12,    44,    45,    46,    50,    51,    53,    10,    55,
      58,    59,    58,    12,    12,    49,    49,     7,     7,     7,
      51,    14,    16,    26,     7,    39,    64,    26,    11,    15,
      45,     3,     4,     5,     6,    14,    16,     8,    14,     9,
      13,    39,    13,    51,    52,    12,    25,    46,    47,    48,
      38,    38,     7,    10,    44,    10,    51,    51,     8,    26,
      13,    45,    45,    45,    45,    10,    44,    10,    57,    44,
      58,    37,     9,    13,    25,    46,    47,    12,    48,    19,
      20,    21,    22,    23,    24,    13,    17,    18,    64,    64,
      15,    15,     7,    57,    38,    15,    15,    15,    57,    52,
      48,    19,    20,    21,    22,    23,    24,    13,    46,    13,
      46,    46,    46,    46,    46,    46,    47,    47,    39,    39,
      26,    52,     8,    46,    46,    46,    46,    46,    46,    13,
      13,    13,    13,    13,    13,    29,    38,    39,    57,    13,
      13,    13,    13,    13,    13,    38,    52,    64,    39,    39
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
#line 150 "parser.yacc"
    {  
  root = A_Program((yyvsp[(1) - (1)].programElementList));
  (yyval.program) = A_Program((yyvsp[(1) - (1)].programElementList));
}
    break;

  case 3:
#line 157 "parser.yacc"
    {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[(1) - (2)].programElement), (yyvsp[(2) - (2)].programElementList));
}
    break;

  case 4:
#line 161 "parser.yacc"
    {
  (yyval.programElementList) = nullptr;
}
    break;

  case 5:
#line 167 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 6:
#line 171 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramStructDef((yyvsp[(1) - (1)].structDef)->pos, (yyvsp[(1) - (1)].structDef));
}
    break;

  case 7:
#line 175 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[(1) - (1)].fnDeclStmt)->pos, (yyvsp[(1) - (1)].fnDeclStmt));
}
    break;

  case 8:
#line 179 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDef((yyvsp[(1) - (1)].fnDef)->pos, (yyvsp[(1) - (1)].fnDef));
}
    break;

  case 9:
#line 183 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 10:
#line 189 "parser.yacc"
    {
  (yyval.tokenNum) = A_TokenNum((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 11:
#line 193 "parser.yacc"
    {
  (yyval.tokenNum) = A_TokenNum((yyvsp[(1) - (2)].pos), -((yyvsp[(2) - (2)].tokenNum)->num));
}
    break;

  case 12:
#line 199 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_add, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 13:
#line 203 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_sub, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 14:
#line 207 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_mul, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 15:
#line 211 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (3)].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos, A_div, (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr)));
}
    break;

  case 16:
#line 215 "parser.yacc"
    {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[(1) - (1)].exprUnit)->pos, (yyvsp[(1) - (1)].exprUnit));
}
    break;

  case 17:
#line 221 "parser.yacc"
    {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 18:
#line 225 "parser.yacc"
    {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 19:
#line 229 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[(2) - (3)].arithExpr)->pos, (yyvsp[(2) - (3)].arithExpr));
}
    break;

  case 20:
#line 233 "parser.yacc"
    {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[(1) - (1)].fnCall)->pos, (yyvsp[(1) - (1)].fnCall));
}
    break;

  case 21:
#line 237 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (4)].leftVal)->pos, A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), A_IdIndexExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(3) - (4)].tokenId)->id)));
}
    break;

  case 22:
#line 241 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (4)].leftVal)->pos, A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), A_NumIndexExpr((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(3) - (4)].tokenNum)->num)));
}
    break;

  case 23:
#line 245 "parser.yacc"
    {
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[(1) - (3)].leftVal)->pos, A_MemberExpr((yyvsp[(1) - (3)].leftVal)->pos, (yyvsp[(1) - (3)].leftVal), (yyvsp[(3) - (3)].tokenId)->id));
}
    break;

  case 24:
#line 251 "parser.yacc"
    {
 (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_and, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr)));
}
    break;

  case 25:
#line 255 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (3)].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos, A_or, (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolExpr)));
}
    break;

  case 26:
#line 259 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolExpr((yyvsp[(1) - (1)].boolUnit)->pos, (yyvsp[(1) - (1)].boolUnit));
}
    break;

  case 27:
#line 265 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_gt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 28:
#line 269 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_ge, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 29:
#line 273 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_lt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 30:
#line 277 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_le, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 31:
#line 281 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_eq, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 32:
#line 285 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(1) - (5)].pos), A_ne, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 33:
#line 289 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].boolExpr));
}
    break;

  case 34:
#line 293 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[(1) - (2)].pos), A_BoolUOpExpr((yyvsp[(1) - (2)].pos), A_not, (yyvsp[(2) - (2)].boolUnit)));
}
    break;

  case 35:
#line 298 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_gt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 36:
#line 302 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_lt, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 37:
#line 306 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_ge, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 38:
#line 310 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_le, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 39:
#line 314 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_eq, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 40:
#line 318 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (5)].pos), A_ComExpr((yyvsp[(2) - (5)].exprUnit)->pos, A_ne, (yyvsp[(2) - (5)].exprUnit), (yyvsp[(4) - (5)].exprUnit)));
}
    break;

  case 41:
#line 322 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[(2) - (3)].boolExpr)->pos, (yyvsp[(2) - (3)].boolExpr));
}
    break;

  case 42:
#line 326 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[(1) - (4)].pos), A_BoolUOpExpr((yyvsp[(3) - (4)].boolUnit)->pos, A_not, (yyvsp[(3) - (4)].boolUnit)));
}
    break;

  case 43:
#line 332 "parser.yacc"
    {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 44:
#line 336 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (4)].leftVal)->pos,A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos,(yyvsp[(1) - (4)].leftVal),A_IdIndexExpr((yyvsp[(3) - (4)].tokenId)->pos,(yyvsp[(3) - (4)].tokenId)->id)));
}
    break;

  case 45:
#line 340 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (4)].leftVal)->pos,A_ArrayExpr((yyvsp[(1) - (4)].leftVal)->pos,(yyvsp[(1) - (4)].leftVal),A_NumIndexExpr((yyvsp[(3) - (4)].tokenNum)->pos,(yyvsp[(3) - (4)].tokenNum)->num)));
}
    break;

  case 46:
#line 344 "parser.yacc"
    {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[(1) - (3)].leftVal)->pos,A_MemberExpr((yyvsp[(1) - (3)].leftVal)->pos,(yyvsp[(1) - (3)].leftVal),(yyvsp[(3) - (3)].tokenId)->id)); // $1todo
}
    break;

  case 47:
#line 350 "parser.yacc"
    {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[(1) - (1)].arithExpr)->pos, (yyvsp[(1) - (1)].arithExpr));
}
    break;

  case 48:
#line 364 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (3)].rightVal), (yyvsp[(3) - (3)].rightValList));
}
    break;

  case 49:
#line 368 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (1)].rightVal), nullptr);
}
    break;

  case 50:
#line 374 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id,(yyvsp[(3) - (4)].rightValList));
}
    break;

  case 51:
#line 378 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, nullptr);
}
    break;

  case 52:
#line 384 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDecl));
}
    break;

  case 53:
#line 388 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].varDef));
}
    break;

  case 54:
#line 394 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDeclScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, (yyvsp[(3) - (3)].type)));
}
    break;

  case 55:
#line 398 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (6)].tokenId)->pos,  A_VarDeclArray((yyvsp[(1) - (6)].tokenId)->pos, (yyvsp[(1) - (6)].tokenId)->id, (yyvsp[(3) - (6)].tokenNum)->num, (yyvsp[(6) - (6)].type)));
}
    break;

  case 56:
#line 402 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (1)].tokenId)->pos,  A_VarDeclScalar((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id, nullptr));
}
    break;

  case 57:
#line 406 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (4)].tokenId)->pos,  A_VarDeclArray((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].tokenNum)->num, nullptr));
}
    break;

  case 58:
#line 411 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (5)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (5)].tokenId)->pos, (yyvsp[(1) - (5)].tokenId)->id, (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].rightVal)));
}
    break;

  case 59:
#line 415 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (3)].tokenId)->pos, A_VarDefScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, nullptr, (yyvsp[(3) - (3)].rightVal)));
}
    break;

  case 60:
#line 419 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (10)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (10)].tokenId)->pos, (yyvsp[(1) - (10)].tokenId)->id, (yyvsp[(3) - (10)].tokenNum)->num, (yyvsp[(6) - (10)].type), (yyvsp[(9) - (10)].rightValList)));
}
    break;

  case 61:
#line 423 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (8)].tokenId)->pos, A_VarDefArray((yyvsp[(1) - (8)].tokenId)->pos, (yyvsp[(1) - (8)].tokenId)->id, (yyvsp[(3) - (8)].tokenNum)->num, nullptr, (yyvsp[(7) - (8)].rightValList)));
}
    break;

  case 62:
#line 429 "parser.yacc"
    {
  (yyval.type) = A_NativeType((yyvsp[(1) - (1)].pos), A_intTypeKind);
}
    break;

  case 63:
#line 433 "parser.yacc"
    {
  (yyval.type) = A_StructType((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 64:
#line 439 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (3)].varDecl), (yyvsp[(3) - (3)].varDeclList));
}
    break;

  case 65:
#line 443 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (1)].varDecl), NULL);
}
    break;

  case 66:
#line 449 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl((yyvsp[(1) - (1)].varDeclList));
}
    break;

  case 67:
#line 453 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl(nullptr);
}
    break;

  case 68:
#line 459 "parser.yacc"
    {
  (yyval.structDef) = A_StructDef((yyvsp[(2) - (5)].tokenId)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].varDeclList));  // $2->pos todo 
}
    break;

  case 69:
#line 465 "parser.yacc"
    {
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[(1) - (2)].fnDecl)->pos, (yyvsp[(1) - (2)].fnDecl));
}
    break;

  case 70:
#line 471 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (5)].pos), (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].paramDecl), nullptr);
}
    break;

  case 71:
#line 475 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (7)].pos), (yyvsp[(2) - (7)].tokenId)->id, (yyvsp[(4) - (7)].paramDecl), (yyvsp[(7) - (7)].type));
}
    break;

  case 72:
#line 481 "parser.yacc"
    {
  (yyval.fnDef) = A_FnDef((yyvsp[(1) - (4)].fnDecl)->pos, (yyvsp[(1) - (4)].fnDecl), (yyvsp[(3) - (4)].codeBlockStmtList));
}
    break;

  case 73:
#line 487 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (2)].codeBlockStmt), (yyvsp[(2) - (2)].codeBlockStmtList));
}
    break;

  case 74:
#line 491 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (1)].codeBlockStmt), nullptr);
}
    break;

  case 75:
#line 495 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = nullptr;
}
    break;

  case 76:
#line 501 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 77:
#line 505 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[(1) - (1)].assignStmt)->pos, (yyvsp[(1) - (1)].assignStmt));
}
    break;

  case 78:
#line 509 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[(1) - (2)].fnCall)->pos, A_CallStmt((yyvsp[(1) - (2)].fnCall)->pos, (yyvsp[(1) - (2)].fnCall)));
}
    break;

  case 79:
#line 513 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[(1) - (1)].ifStmt)->pos, (yyvsp[(1) - (1)].ifStmt)); 
}
    break;

  case 80:
#line 517 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[(1) - (1)].whileStmt)->pos, (yyvsp[(1) - (1)].whileStmt));
}
    break;

  case 81:
#line 521 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockReturnStmt((yyvsp[(1) - (3)].pos), A_ReturnStmt((yyvsp[(1) - (3)].pos), (yyvsp[(2) - (3)].rightVal)));
}
    break;

  case 82:
#line 525 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockReturnStmt((yyvsp[(1) - (2)].pos), A_ReturnStmt((yyvsp[(1) - (2)].pos), nullptr));
}
    break;

  case 83:
#line 529 "parser.yacc"
    {
  (yyval.codeBlockStmt) =A_BlockContinueStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 84:
#line 533 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 85:
#line 537 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 86:
#line 543 "parser.yacc"
    {
  (yyval.whileStmt) = A_WhileStmt((yyvsp[(1) - (5)].pos), (yyvsp[(2) - (5)].boolUnit), (yyvsp[(4) - (5)].codeBlockStmtList));
}
    break;

  case 87:
#line 549 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (5)].pos), (yyvsp[(2) - (5)].boolUnit), (yyvsp[(4) - (5)].codeBlockStmtList), nullptr);
}
    break;

  case 88:
#line 553 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (9)].pos), (yyvsp[(2) - (9)].boolUnit), (yyvsp[(4) - (9)].codeBlockStmtList), (yyvsp[(8) - (9)].codeBlockStmtList));
}
    break;

  case 89:
#line 559 "parser.yacc"
    {
  (yyval.assignStmt) = A_AssignStmt((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), (yyvsp[(3) - (4)].rightVal));
}
    break;


/* Line 1267 of yacc.c.  */
#line 2219 "y.tab.cpp"
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


#line 563 "parser.yacc"


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



