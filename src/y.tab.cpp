/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int yywrap();
}


#line 86 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_STRUCT = 4,                     /* STRUCT  */
  YYSYMBOL_FN = 5,                         /* FN  */
  YYSYMBOL_CONTINUE = 6,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_UNUM = 12,                      /* UNUM  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 20,                     /* COLON  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 21,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 22,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_EQUAL = 23,                     /* EQUAL  */
  YYSYMBOL_OPEN_BRACE = 24,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSED_BRACE = 25,              /* CLOSED_BRACE  */
  YYSYMBOL_LEFT_PARENTHESIS = 26,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 27,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_RIGHT_ARROW = 28,               /* RIGHT_ARROW  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_LESS = 34,                      /* LESS  */
  YYSYMBOL_GREATER = 35,                   /* GREATER  */
  YYSYMBOL_LESS_EQUAL = 36,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 37,             /* GREATER_EQUAL  */
  YYSYMBOL_IS = 38,                        /* IS  */
  YYSYMBOL_IS_NOT = 39,                    /* IS_NOT  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_ProgramElementList = 42,        /* ProgramElementList  */
  YYSYMBOL_ProgramElement = 43,            /* ProgramElement  */
  YYSYMBOL_RightVal = 44,                  /* RightVal  */
  YYSYMBOL_RightValList = 45,              /* RightValList  */
  YYSYMBOL_ArithExpr = 46,                 /* ArithExpr  */
  YYSYMBOL_NUM = 47,                       /* NUM  */
  YYSYMBOL_ExprUnit = 48,                  /* ExprUnit  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_VarDeclStmt = 50,               /* VarDeclStmt  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDef = 52,                    /* VarDef  */
  YYSYMBOL_StructDef = 53,                 /* StructDef  */
  YYSYMBOL_VarDeclList = 54,               /* VarDeclList  */
  YYSYMBOL_FnDeclStmt = 55,                /* FnDeclStmt  */
  YYSYMBOL_FnDecl = 56,                    /* FnDecl  */
  YYSYMBOL_ParamDecl = 57,                 /* ParamDecl  */
  YYSYMBOL_FnDef = 58,                     /* FnDef  */
  YYSYMBOL_CodeBlockStmtList = 59,         /* CodeBlockStmtList  */
  YYSYMBOL_CodeBlockStmt = 60,             /* CodeBlockStmt  */
  YYSYMBOL_AssignStmt = 61,                /* AssignStmt  */
  YYSYMBOL_LeftVal = 62,                   /* LeftVal  */
  YYSYMBOL_ArrayExpr = 63,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 64,                /* MemberExpr  */
  YYSYMBOL_ReturnStmt = 65,                /* ReturnStmt  */
  YYSYMBOL_CallStmt = 66,                  /* CallStmt  */
  YYSYMBOL_FnCall = 67,                    /* FnCall  */
  YYSYMBOL_IfStmt = 68,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 69,                 /* WhileStmt  */
  YYSYMBOL_BoolExpr = 70,                  /* BoolExpr  */
  YYSYMBOL_BoolUnit = 71,                  /* BoolUnit  */
  YYSYMBOL_BoolBiOp = 72,                  /* BoolBiOp  */
  YYSYMBOL_ComOp = 73                      /* ComOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   165,   165,   172,   177,   182,   186,   190,   194,   198,
     204,   208,   213,   217,   222,   227,   231,   235,   239,   243,
     249,   253,   261,   265,   269,   273,   277,   285,   297,   301,
     307,   311,   316,   320,   324,   328,   333,   337,   341,   345,
     350,   355,   359,   364,   369,   374,   378,   383,   389,   394,
     398,   403,   407,   411,   415,   419,   423,   427,   431,   435,
     440,   445,   449,   453,   458,   462,   467,   472,   476,   481,
     486,   493,   498,   504,   510,   514,   519,   523,   527,   547,
     551,   556,   560,   564,   568,   572,   576
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "STRUCT", "FN",
  "CONTINUE", "BREAK", "RETURN", "WHILE", "IF", "ELSE", "UNUM", "ID",
  "INT", "ADD", "SUB", "MUL", "DIV", "SEMICOLON", "COLON",
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "EQUAL", "OPEN_BRACE",
  "CLOSED_BRACE", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "RIGHT_ARROW",
  "DOT", "COMMA", "AND", "OR", "NOT", "LESS", "GREATER", "LESS_EQUAL",
  "GREATER_EQUAL", "IS", "IS_NOT", "$accept", "Program",
  "ProgramElementList", "ProgramElement", "RightVal", "RightValList",
  "ArithExpr", "NUM", "ExprUnit", "Type", "VarDeclStmt", "VarDecl",
  "VarDef", "StructDef", "VarDeclList", "FnDeclStmt", "FnDecl",
  "ParamDecl", "FnDef", "CodeBlockStmtList", "CodeBlockStmt", "AssignStmt",
  "LeftVal", "ArrayExpr", "MemberExpr", "ReturnStmt", "CallStmt", "FnCall",
  "IfStmt", "WhileStmt", "BoolExpr", "BoolUnit", "BoolBiOp", "ComOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,    13,    28,    43,  -124,    76,  -124,    55,  -124,  -124,
    -124,    83,  -124,   109,   103,   108,    71,    87,  -124,  -124,
    -124,    91,   120,   112,    -2,  -124,  -124,   118,   118,   121,
     123,    24,    18,    18,   122,  -124,  -124,   119,    91,  -124,
      82,  -124,  -124,  -124,  -124,   130,  -124,  -124,  -124,  -124,
     127,  -124,   139,   131,     6,    -2,    18,  -124,    67,  -124,
    -124,    34,    44,    85,  -124,   104,  -124,   117,   124,   132,
    -124,   125,  -124,  -124,  -124,   136,    -2,   134,   135,    -2,
    -124,  -124,    96,    -2,   143,  -124,    -2,  -124,    -5,    51,
      81,    94,  -124,    26,    26,    26,    26,  -124,  -124,    18,
     120,   112,   118,  -124,   133,  -124,    81,    91,    91,   137,
     138,   140,   141,   145,  -124,  -124,   120,   142,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,    26,  -124,    26,   129,   129,
    -124,  -124,  -124,  -124,   146,  -124,   120,   144,   147,    -2,
    -124,  -124,  -124,  -124,   148,    -2,   149,   150,  -124,  -124,
     162,  -124,   151,   152,  -124,   120,   154,    -2,  -124,  -124,
      91,   155,   156,  -124,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     9,     0,     2,     4,     5,     6,
       7,     0,     8,    34,     0,     0,     0,     0,     1,     3,
      44,     0,     0,     0,     0,    30,    31,    43,    43,     0,
       0,     0,     0,     0,    61,    59,    51,     0,    49,    52,
       0,    62,    63,    56,    53,     0,    54,    55,    29,    28,
      32,    20,     0,     0,    23,     0,     0,    37,    10,    22,
      19,     0,    25,    26,    27,    11,    75,    34,    41,     0,
      47,     0,    57,    58,    68,     0,     0,     0,     0,    14,
      48,    50,     0,     0,     0,    69,     0,    21,    35,     0,
      19,     0,    78,     0,     0,     0,     0,    79,    80,     0,
       0,     0,    43,    40,    45,    67,     0,     0,     0,    12,
       0,     0,     0,     0,    66,    36,     0,     0,    24,    85,
      83,    86,    84,    81,    82,     0,    77,     0,    15,    16,
      17,    18,    74,    32,     0,    42,     0,     0,     0,    14,
      70,    65,    64,    60,    33,    14,     0,    35,    46,    73,
      71,    13,     0,     0,    76,     0,     0,    14,    39,    33,
       0,     0,     0,    38,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   153,  -124,   -11,  -123,   -47,   -20,   -48,   -91,
      54,   173,  -124,  -124,   -23,  -124,  -124,  -124,  -124,   -37,
    -124,  -124,   -21,   -19,   -17,  -124,  -124,   -15,  -124,  -124,
     -43,    -3,  -124,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,   109,   110,    58,    59,    60,    50,
      36,    68,    15,     9,    69,    10,    11,    71,    12,    37,
      38,    39,    61,    62,    63,    43,    44,    64,    46,    47,
      65,    66,    99,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    81,    41,    53,    42,    70,    45,    90,    89,   133,
      51,    54,    91,    57,    52,   116,   151,    40,   117,    41,
      75,    42,   153,    45,    55,   144,    13,   -61,   106,    77,
      78,    56,    79,    91,   161,   -61,    51,    54,    51,    54,
      52,    16,    52,    74,    76,   148,   128,   129,   130,   131,
      55,    56,   127,    92,     8,    82,    17,    56,     1,     2,
       3,     8,   112,    84,   159,   -62,    93,    94,    95,    96,
     137,   138,   113,   -62,     4,   115,    18,   146,   118,   135,
      89,   134,    93,    94,    95,    96,    40,    40,    41,    41,
      42,    42,    45,    45,     1,    27,   132,    29,    30,    31,
      32,    33,    20,    82,    34,    83,   -63,    21,    51,   111,
      35,    84,    52,    28,   -63,   119,   120,   121,   122,   123,
     124,   126,    25,   162,    51,    97,    98,    26,    52,    22,
      23,    67,    24,    48,    49,    97,    98,   100,   101,    40,
      72,    41,    73,    42,    80,    45,    95,    96,    79,    85,
      86,    87,   104,    88,   102,   105,   114,   103,   107,   108,
      19,   136,   141,   142,   143,   140,   145,   139,   147,   149,
     155,   152,   150,   156,    14,   157,   154,   158,   160,     0,
     163,   164
};

static const yytype_int16 yycheck[] =
{
      21,    38,    21,    23,    21,    28,    21,    55,    55,   100,
      12,    13,    55,    24,    16,    20,   139,    38,    23,    38,
      31,    38,   145,    38,    26,   116,    13,    21,    76,    32,
      33,    33,    26,    76,   157,    29,    12,    13,    12,    13,
      16,    13,    16,    19,    26,   136,    93,    94,    95,    96,
      26,    33,    26,    56,     0,    21,    13,    33,     3,     4,
       5,     7,    82,    29,   155,    21,    15,    16,    17,    18,
     107,   108,    83,    29,    19,    86,     0,   125,    27,   102,
     127,   101,    15,    16,    17,    18,   107,   108,   107,   108,
     107,   108,   107,   108,     3,    24,    99,     6,     7,     8,
       9,    10,    19,    21,    13,    23,    21,    24,    12,    13,
      19,    29,    16,    26,    29,    34,    35,    36,    37,    38,
      39,    27,    19,   160,    12,    31,    32,    19,    16,    20,
      21,    13,    23,    13,    14,    31,    32,    20,    21,   160,
      19,   160,    19,   160,    25,   160,    17,    18,    26,    19,
      23,    12,    27,    22,    30,    19,    13,    25,    24,    24,
       7,    28,    22,    22,    19,    27,    24,    30,    22,    25,
      20,    23,    25,    11,     1,    24,    27,    25,    24,    -1,
      25,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    19,    41,    42,    43,    50,    53,
      55,    56,    58,    13,    51,    52,    13,    13,     0,    42,
      19,    24,    20,    21,    23,    19,    19,    24,    26,     6,
       7,     8,     9,    10,    13,    19,    50,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    13,    14,
      49,    12,    16,    47,    13,    26,    33,    44,    46,    47,
      48,    62,    63,    64,    67,    70,    71,    13,    51,    54,
      54,    57,    19,    19,    19,    44,    26,    71,    71,    26,
      25,    59,    21,    23,    29,    19,    23,    12,    22,    46,
      48,    70,    71,    15,    16,    17,    18,    31,    32,    72,
      20,    21,    30,    25,    27,    19,    48,    24,    24,    44,
      45,    13,    47,    44,    13,    44,    20,    23,    27,    34,
      35,    36,    37,    38,    39,    73,    27,    26,    46,    46,
      46,    46,    71,    49,    47,    54,    28,    59,    59,    30,
      27,    22,    22,    19,    49,    24,    48,    22,    49,    25,
      25,    45,    23,    45,    27,    20,    11,    24,    25,    49,
      24,    45,    59,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    52,    52,    52,    52,
      53,    54,    54,    54,    55,    56,    56,    57,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    62,    62,    62,    63,    63,    64,    65,    65,    66,
      67,    68,    68,    69,    70,    70,    71,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     6,     1,     4,     5,     3,    10,     8,
       5,     1,     3,     0,     2,     5,     7,     1,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       4,     1,     1,     1,     4,     4,     3,     3,     2,     2,
       4,     5,     9,     5,     3,     1,     5,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ProgramElementList  */
#line 166 "parser.yacc"
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
}
#line 1264 "y.tab.cpp"
    break;

  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 173 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1272 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 177 "parser.yacc"
{
  (yyval.programElementList) = NULL;
}
#line 1280 "y.tab.cpp"
    break;

  case 5: /* ProgramElement: VarDeclStmt  */
#line 183 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1288 "y.tab.cpp"
    break;

  case 6: /* ProgramElement: StructDef  */
#line 187 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1296 "y.tab.cpp"
    break;

  case 7: /* ProgramElement: FnDeclStmt  */
#line 191 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1304 "y.tab.cpp"
    break;

  case 8: /* ProgramElement: FnDef  */
#line 195 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1312 "y.tab.cpp"
    break;

  case 9: /* ProgramElement: SEMICOLON  */
#line 199 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 1320 "y.tab.cpp"
    break;

  case 10: /* RightVal: ArithExpr  */
#line 205 "parser.yacc"
{
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1328 "y.tab.cpp"
    break;

  case 11: /* RightVal: BoolExpr  */
#line 209 "parser.yacc"
{
  (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
}
#line 1336 "y.tab.cpp"
    break;

  case 12: /* RightValList: RightVal  */
#line 214 "parser.yacc"
{
  (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), NULL);
}
#line 1344 "y.tab.cpp"
    break;

  case 13: /* RightValList: RightVal COMMA RightValList  */
#line 218 "parser.yacc"
{
  (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1352 "y.tab.cpp"
    break;

  case 14: /* RightValList: %empty  */
#line 222 "parser.yacc"
{
  (yyval.rightValList) = NULL;
}
#line 1360 "y.tab.cpp"
    break;

  case 15: /* ArithExpr: ArithExpr ADD ArithExpr  */
#line 228 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1368 "y.tab.cpp"
    break;

  case 16: /* ArithExpr: ArithExpr SUB ArithExpr  */
#line 232 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1376 "y.tab.cpp"
    break;

  case 17: /* ArithExpr: ArithExpr MUL ArithExpr  */
#line 236 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1384 "y.tab.cpp"
    break;

  case 18: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 240 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1392 "y.tab.cpp"
    break;

  case 19: /* ArithExpr: ExprUnit  */
#line 244 "parser.yacc"
{
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1400 "y.tab.cpp"
    break;

  case 20: /* NUM: UNUM  */
#line 250 "parser.yacc"
{ 
  (yyval.tokenNum) = (yyvsp[0].tokenNum);
}
#line 1408 "y.tab.cpp"
    break;

  case 21: /* NUM: SUB UNUM  */
#line 254 "parser.yacc"
{
  (yyval.tokenNum) = (A_tokenNum) malloc(sizeof(struct A_tokenNum_));
  (yyval.tokenNum)->pos = (yyvsp[0].tokenNum)->pos;
  (yyval.tokenNum)->num = -((yyvsp[0].tokenNum)->num); 
}
#line 1418 "y.tab.cpp"
    break;

  case 22: /* ExprUnit: NUM  */
#line 262 "parser.yacc"
{
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1426 "y.tab.cpp"
    break;

  case 23: /* ExprUnit: ID  */
#line 266 "parser.yacc"
{
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1434 "y.tab.cpp"
    break;

  case 24: /* ExprUnit: LEFT_PARENTHESIS ArithExpr RIGHT_PARENTHESIS  */
#line 270 "parser.yacc"
{
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
}
#line 1442 "y.tab.cpp"
    break;

  case 25: /* ExprUnit: ArrayExpr  */
#line 274 "parser.yacc"
{
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1450 "y.tab.cpp"
    break;

  case 26: /* ExprUnit: MemberExpr  */
#line 278 "parser.yacc"
{
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1458 "y.tab.cpp"
    break;

  case 27: /* ExprUnit: FnCall  */
#line 286 "parser.yacc"
{
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1466 "y.tab.cpp"
    break;

  case 28: /* Type: INT  */
#line 298 "parser.yacc"
{
  (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1474 "y.tab.cpp"
    break;

  case 29: /* Type: ID  */
#line 302 "parser.yacc"
{
  (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1482 "y.tab.cpp"
    break;

  case 30: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 308 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1490 "y.tab.cpp"
    break;

  case 31: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 312 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1498 "y.tab.cpp"
    break;

  case 32: /* VarDecl: ID COLON Type  */
#line 317 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1506 "y.tab.cpp"
    break;

  case 33: /* VarDecl: ID LEFT_SQUARE_BRACKET NUM RIGHT_SQUARE_BRACKET COLON Type  */
#line 321 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-5].tokenId)->pos, A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type)));
}
#line 1514 "y.tab.cpp"
    break;

  case 34: /* VarDecl: ID  */
#line 325 "parser.yacc"
{
   (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, NULL));
}
#line 1522 "y.tab.cpp"
    break;

  case 35: /* VarDecl: ID LEFT_SQUARE_BRACKET NUM RIGHT_SQUARE_BRACKET  */
#line 329 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-3].tokenId)->pos, A_VarDeclArray((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].tokenNum)->num, NULL));
}
#line 1530 "y.tab.cpp"
    break;

  case 36: /* VarDef: ID COLON Type EQUAL RightVal  */
#line 334 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 1538 "y.tab.cpp"
    break;

  case 37: /* VarDef: ID EQUAL RightVal  */
#line 338 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, NULL, (yyvsp[0].rightVal)));
}
#line 1546 "y.tab.cpp"
    break;

  case 38: /* VarDef: ID LEFT_SQUARE_BRACKET NUM RIGHT_SQUARE_BRACKET COLON Type EQUAL OPEN_BRACE RightValList CLOSED_BRACE  */
#line 342 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Array((yyvsp[-9].tokenId)->pos, A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 1554 "y.tab.cpp"
    break;

  case 39: /* VarDef: ID LEFT_SQUARE_BRACKET NUM RIGHT_SQUARE_BRACKET EQUAL OPEN_BRACE RightValList CLOSED_BRACE  */
#line 346 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Array((yyvsp[-7].tokenId)->pos, A_VarDefArray((yyvsp[-7].tokenId)->pos, (yyvsp[-7].tokenId)->id, (yyvsp[-5].tokenNum)->num, NULL, (yyvsp[-1].rightValList)));
}
#line 1562 "y.tab.cpp"
    break;

  case 40: /* StructDef: STRUCT ID OPEN_BRACE VarDeclList CLOSED_BRACE  */
#line 351 "parser.yacc"
{
  (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1570 "y.tab.cpp"
    break;

  case 41: /* VarDeclList: VarDecl  */
#line 356 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), NULL); 
}
#line 1578 "y.tab.cpp"
    break;

  case 42: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 360 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList)); 
}
#line 1586 "y.tab.cpp"
    break;

  case 43: /* VarDeclList: %empty  */
#line 364 "parser.yacc"
{
  (yyval.varDeclList) = NULL;
}
#line 1594 "y.tab.cpp"
    break;

  case 44: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 370 "parser.yacc"
{
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 1602 "y.tab.cpp"
    break;

  case 45: /* FnDecl: FN ID LEFT_PARENTHESIS ParamDecl RIGHT_PARENTHESIS  */
#line 375 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), NULL);
}
#line 1610 "y.tab.cpp"
    break;

  case 46: /* FnDecl: FN ID LEFT_PARENTHESIS ParamDecl RIGHT_PARENTHESIS RIGHT_ARROW Type  */
#line 379 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1618 "y.tab.cpp"
    break;

  case 47: /* ParamDecl: VarDeclList  */
#line 384 "parser.yacc"
{
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1626 "y.tab.cpp"
    break;

  case 48: /* FnDef: FnDecl OPEN_BRACE CodeBlockStmtList CLOSED_BRACE  */
#line 390 "parser.yacc"
{
  (yyval.fnDef) = A_FnDef((yyvsp[-3].fnDecl)->pos, (yyvsp[-3].fnDecl), (yyvsp[-1].codeBlockStmtList));
}
#line 1634 "y.tab.cpp"
    break;

  case 49: /* CodeBlockStmtList: CodeBlockStmt  */
#line 395 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), NULL);
}
#line 1642 "y.tab.cpp"
    break;

  case 50: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 399 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1650 "y.tab.cpp"
    break;

  case 51: /* CodeBlockStmt: VarDeclStmt  */
#line 404 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1658 "y.tab.cpp"
    break;

  case 52: /* CodeBlockStmt: AssignStmt  */
#line 408 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 1666 "y.tab.cpp"
    break;

  case 53: /* CodeBlockStmt: CallStmt  */
#line 412 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 1674 "y.tab.cpp"
    break;

  case 54: /* CodeBlockStmt: IfStmt  */
#line 416 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 1682 "y.tab.cpp"
    break;

  case 55: /* CodeBlockStmt: WhileStmt  */
#line 420 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 1690 "y.tab.cpp"
    break;

  case 56: /* CodeBlockStmt: ReturnStmt  */
#line 424 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 1698 "y.tab.cpp"
    break;

  case 57: /* CodeBlockStmt: CONTINUE SEMICOLON  */
#line 428 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
}
#line 1706 "y.tab.cpp"
    break;

  case 58: /* CodeBlockStmt: BREAK SEMICOLON  */
#line 432 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
}
#line 1714 "y.tab.cpp"
    break;

  case 59: /* CodeBlockStmt: SEMICOLON  */
#line 436 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 1722 "y.tab.cpp"
    break;

  case 60: /* AssignStmt: LeftVal EQUAL RightVal SEMICOLON  */
#line 441 "parser.yacc"
{
  (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1730 "y.tab.cpp"
    break;

  case 61: /* LeftVal: ID  */
#line 446 "parser.yacc"
{
  (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1738 "y.tab.cpp"
    break;

  case 62: /* LeftVal: ArrayExpr  */
#line 450 "parser.yacc"
{
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1746 "y.tab.cpp"
    break;

  case 63: /* LeftVal: MemberExpr  */
#line 454 "parser.yacc"
{
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1754 "y.tab.cpp"
    break;

  case 64: /* ArrayExpr: LeftVal LEFT_SQUARE_BRACKET NUM RIGHT_SQUARE_BRACKET  */
#line 459 "parser.yacc"
{
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1762 "y.tab.cpp"
    break;

  case 65: /* ArrayExpr: LeftVal LEFT_SQUARE_BRACKET ID RIGHT_SQUARE_BRACKET  */
#line 463 "parser.yacc"
{
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1770 "y.tab.cpp"
    break;

  case 66: /* MemberExpr: LeftVal DOT ID  */
#line 468 "parser.yacc"
{
  (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1778 "y.tab.cpp"
    break;

  case 67: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 473 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 1786 "y.tab.cpp"
    break;

  case 68: /* ReturnStmt: RETURN SEMICOLON  */
#line 477 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), NULL);
}
#line 1794 "y.tab.cpp"
    break;

  case 69: /* CallStmt: FnCall SEMICOLON  */
#line 482 "parser.yacc"
{
  (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 1802 "y.tab.cpp"
    break;

  case 70: /* FnCall: ID LEFT_PARENTHESIS RightValList RIGHT_PARENTHESIS  */
#line 487 "parser.yacc"
{
  (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1810 "y.tab.cpp"
    break;

  case 71: /* IfStmt: IF BoolUnit OPEN_BRACE CodeBlockStmtList CLOSED_BRACE  */
#line 494 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList), NULL);
}
#line 1818 "y.tab.cpp"
    break;

  case 72: /* IfStmt: IF BoolUnit OPEN_BRACE CodeBlockStmtList CLOSED_BRACE ELSE OPEN_BRACE CodeBlockStmtList CLOSED_BRACE  */
#line 499 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-8].pos), (yyvsp[-7].boolUnit), (yyvsp[-5].codeBlockStmtList), (yyvsp[-1].codeBlockStmtList));
}
#line 1826 "y.tab.cpp"
    break;

  case 73: /* WhileStmt: WHILE BoolUnit OPEN_BRACE CodeBlockStmtList CLOSED_BRACE  */
#line 505 "parser.yacc"
{
  (yyval.whileStmt) = A_WhileStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList));
}
#line 1834 "y.tab.cpp"
    break;

  case 74: /* BoolExpr: BoolExpr BoolBiOp BoolUnit  */
#line 511 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[-2].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, (yyvsp[-1].boolBiOp), (yyvsp[-2].boolExpr), A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit))));
}
#line 1842 "y.tab.cpp"
    break;

  case 75: /* BoolExpr: BoolUnit  */
#line 515 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1850 "y.tab.cpp"
    break;

  case 76: /* BoolUnit: LEFT_PARENTHESIS ExprUnit ComOp ExprUnit RIGHT_PARENTHESIS  */
#line 520 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, (yyvsp[-2].comOp), (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1858 "y.tab.cpp"
    break;

  case 77: /* BoolUnit: LEFT_PARENTHESIS BoolExpr RIGHT_PARENTHESIS  */
#line 524 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1866 "y.tab.cpp"
    break;

  case 78: /* BoolUnit: NOT BoolUnit  */
#line 528 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[-1].pos), A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit)));
}
#line 1874 "y.tab.cpp"
    break;

  case 79: /* BoolBiOp: AND  */
#line 548 "parser.yacc"
{
  (yyval.boolBiOp) = A_and;
}
#line 1882 "y.tab.cpp"
    break;

  case 80: /* BoolBiOp: OR  */
#line 552 "parser.yacc"
{
  (yyval.boolBiOp) = A_or;
}
#line 1890 "y.tab.cpp"
    break;

  case 81: /* ComOp: IS  */
#line 557 "parser.yacc"
{
  (yyval.comOp) = A_eq;
}
#line 1898 "y.tab.cpp"
    break;

  case 82: /* ComOp: IS_NOT  */
#line 561 "parser.yacc"
{
  (yyval.comOp) = A_ne;
}
#line 1906 "y.tab.cpp"
    break;

  case 83: /* ComOp: GREATER  */
#line 565 "parser.yacc"
{
  (yyval.comOp) = A_gt;
}
#line 1914 "y.tab.cpp"
    break;

  case 84: /* ComOp: GREATER_EQUAL  */
#line 569 "parser.yacc"
{
  (yyval.comOp) = A_ge;
}
#line 1922 "y.tab.cpp"
    break;

  case 85: /* ComOp: LESS  */
#line 573 "parser.yacc"
{
  (yyval.comOp) = A_lt;
}
#line 1930 "y.tab.cpp"
    break;

  case 86: /* ComOp: LESS_EQUAL  */
#line 577 "parser.yacc"
{
  (yyval.comOp) = A_le;
}
#line 1938 "y.tab.cpp"
    break;


#line 1942 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 583 "parser.yacc"


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


