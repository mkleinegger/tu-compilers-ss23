/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "oxout.y"


/* output from Ox version 1.10.3 */

/* Ox-generated Attribute Grammar Evaluator parser specification
   for Yacc-compatible parser generators

   Copyright (C) 1992-1994  Kurt M. Bischoff
   Copyright (C) 2004-2022  Thomas E. Shields

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As an exception to the standard GNU General Public License, you may
   create a larger work that contains the Ox Attribute Grammar Evaluator
   parser specification skeleton and distribute that work under terms of
   your own choice, so long as that work isn't itself an
   Attribute Grammar Evaluator generator using the skeleton or a
   modified version thereof as an evaluator parser specification
   skeleton.  */

/* Identify Ox output. */
#define YYYOX 1

#if defined (lint)
#include <note.h>
#endif

#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void yyerror(char const*);

extern int yylex();

#line 67 "oxout.y"

struct yyyT1 {
#line 21 "parser.y"
 char *name; int lineNr;
#line 72 "oxout.y"

};

struct yyyT2 {
#line 22 "parser.y"
 struct type_t type;
#line 79 "oxout.y"

};

struct yyyT3 {
#line 23 "parser.y"
 struct type_t typeIn; struct type_t typeOut;
#line 86 "oxout.y"

};

struct yyyT4 {
#line 24 "parser.y"
 struct node_t *names;
#line 93 "oxout.y"

};

struct yyyT5 {
#line 25 "parser.y"
 struct node_t *namesIn; struct node_t *namesOut;
#line 100 "oxout.y"

};

struct yyyT6 {
#line 26 "parser.y"
 struct node_t *out;
#line 107 "oxout.y"

};

struct yyyT7 {
#line 27 "parser.y"
 struct node_t *in; struct node_t *out;
#line 114 "oxout.y"

};

struct yyyT8 {
#line 28 "parser.y"
 struct node_t *in; struct type_t type;
#line 121 "oxout.y"

};

struct yyyT9 {
#line 29 "parser.y"
 struct node_t *in; struct node_t *out; struct type_t type;
#line 128 "oxout.y"

};

struct yyyT10 {
#line 30 "parser.y"
 struct node_t *in; struct node_t *out; struct type_t typeIn; struct type_t typeOut;
#line 135 "oxout.y"

};

struct yyyT11 {
#line 31 "parser.y"
 struct node_t *ids; struct type_t type;
#line 142 "oxout.y"

};

#if defined (__cplusplus)
#include <cstring>
#include <new>
#endif

union yyyAttrbs {
  struct yyyT1 yyyAttrb1;
  struct yyyT2 yyyAttrb2;
  struct yyyT3 yyyAttrb3;
  struct yyyT4 yyyAttrb4;
  struct yyyT5 yyyAttrb5;
  struct yyyT6 yyyAttrb6;
  struct yyyT7 yyyAttrb7;
  struct yyyT8 yyyAttrb8;
  struct yyyT9 yyyAttrb9;
  struct yyyT10 yyyAttrb10;
  struct yyyT11 yyyAttrb11;
};

#if defined (__cplusplus)
#include <cstdbool>
#include <cstdlib>
#else
#include <stdbool.h>
#include <stdlib.h>
#endif

typedef unsigned short yyyWAT;
typedef unsigned short yyyRCT;
typedef unsigned short yyyPNT;
typedef unsigned short yyyWST;
 /* funny type; as wide as the widest of yyyWAT, yyyWST, yyyRCT */
typedef unsigned short yyyFT;



struct yyySolvedSAlistCell {yyyWAT attrbNum;
                            struct yyySolvedSAlistCell *next;
                           };
typedef struct yyySolvedSAlistCell yyySSALC;

struct yyySemEl {struct yyyGenNode *node;
                 struct yyySolvedSAlistCell *solvedSAlist;
                };
typedef struct yyySemEl yyySIT;

typedef struct yyyOxAttrbs {
struct yyySemEl *semEl;
} yyyOxAttrbs;

typedef union{struct yyySemEl *stackref; struct yyyGenNode *noderef;} yyyParent;
struct yyyGenNode {yyyParent parent;
                   bool parentIsStack; /* =true =>  `(yyySIT *) parent' is referenced on the Yacc semantic stack  */
                                       /* =false => `(yyyGNT *) parent' is this node's parent node  */
                   int cLlen; /* length of child list */
                   struct yyyGenNode **cL; /* child list */
                   int refCountListLen; /* length of RCL */
                   yyyRCT *refCountList;
                   yyyPNT prodNum;
                   yyyWST whichSym; /* which child of parent? */
                   union yyyAttrbs yyyAttrbs; /* the Ox semantic attributes */
                  };
typedef struct yyyGenNode yyyGNT;
#line 209 "oxout.y"

#define yyyinit()
#line 212 "oxout.y"

struct yyyRSitem {yyyGNT *node;
                  yyyWST whichSym;
                  yyyWAT whichAttrb;
                 };

static struct yyyRSitem *yyyRS;
static long yyyRSTop = 0L;
#define yyyRSBottom 1L
static long yyyAfterRS = 1L;

#include <limits.h>
#define yyyR USHRT_MAX

#line 282 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OBJECT = 258,                  /* OBJECT  */
    INT = 259,                     /* INT  */
    CLASS = 260,                   /* CLASS  */
    END = 261,                     /* END  */
    RETURN = 262,                  /* RETURN  */
    COND = 263,                    /* COND  */
    CONTINUE = 264,                /* CONTINUE  */
    BREAK = 265,                   /* BREAK  */
    NOT = 266,                     /* NOT  */
    OR = 267,                      /* OR  */
    NEW = 268,                     /* NEW  */
    NULLTERM = 269,                /* NULLTERM  */
    ID = 270,                      /* ID  */
    NUM = 271,                     /* NUM  */
    LEFTASSIGN = 272,              /* LEFTASSIGN  */
    RIGHTASSIGN = 273              /* RIGHTASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OBJECT 258
#define INT 259
#define CLASS 260
#define END 261
#define RETURN 262
#define COND 263
#define CONTINUE 264
#define BREAK 265
#define NOT 266
#define OR 267
#define NEW 268
#define NULLTERM 269
#define ID 270
#define NUM 271
#define LEFTASSIGN 272
#define RIGHTASSIGN 273

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 229 "oxout.y"

struct {
struct yyySemEl *semEl;
} yyyOxAttrbs;

#line 377 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OBJECT = 3,                     /* OBJECT  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_COND = 8,                       /* COND  */
  YYSYMBOL_CONTINUE = 9,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NEW = 13,                       /* NEW  */
  YYSYMBOL_NULLTERM = 14,                  /* NULLTERM  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_NUM = 16,                       /* NUM  */
  YYSYMBOL_LEFTASSIGN = 17,                /* LEFTASSIGN  */
  YYSYMBOL_RIGHTASSIGN = 18,               /* RIGHTASSIGN  */
  YYSYMBOL_19_ = 19,                       /* ';'  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_22_ = 22,                       /* ')'  */
  YYSYMBOL_23_ = 23,                       /* '-'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '#'  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_yyyAugNonterm = 29,             /* yyyAugNonterm  */
  YYSYMBOL_Start = 30,                     /* Start  */
  YYSYMBOL_Program = 31,                   /* Program  */
  YYSYMBOL_Selector = 32,                  /* Selector  */
  YYSYMBOL_OptType = 33,                   /* OptType  */
  YYSYMBOL_Type = 34,                      /* Type  */
  YYSYMBOL_Class = 35,                     /* Class  */
  YYSYMBOL_MemberStart = 36,               /* MemberStart  */
  YYSYMBOL_OptMember = 37,                 /* OptMember  */
  YYSYMBOL_Member = 38,                    /* Member  */
  YYSYMBOL_Pars = 39,                      /* Pars  */
  YYSYMBOL_Par = 40,                       /* Par  */
  YYSYMBOL_Stats = 41,                     /* Stats  */
  YYSYMBOL_Stat = 42,                      /* Stat  */
  YYSYMBOL_Return = 43,                    /* Return  */
  YYSYMBOL_Conditions = 44,                /* Conditions  */
  YYSYMBOL_OptGuarded = 45,                /* OptGuarded  */
  YYSYMBOL_Guarded = 46,                   /* Guarded  */
  YYSYMBOL_ContinueOrBreak = 47,           /* ContinueOrBreak  */
  YYSYMBOL_Expr = 48,                      /* Expr  */
  YYSYMBOL_Negations = 49,                 /* Negations  */
  YYSYMBOL_PlusTerm = 50,                  /* PlusTerm  */
  YYSYMBOL_MulTerm = 51,                   /* MulTerm  */
  YYSYMBOL_OrTerm = 52,                    /* OrTerm  */
  YYSYMBOL_RepExpr = 53,                   /* RepExpr  */
  YYSYMBOL_Term = 54                       /* Term  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 235 "oxout.y"

#include <stdio.h>
#include <stdarg.h>

bool yyyYok = true;
void yyyabort (void);

static void yyyExecuteRRsection (yyyGNT *);
static void yyyDoTraversals (yyyGNT *);
static void yyyGenIntNode (long, int, int, int, yyyOxAttrbs *, ...);
static void yyyReclaimSemStkEls (int, ...);
static void yyyAdjustINRC (long, int, long, long, yyyOxAttrbs *, ...);
static void yyyCheckUnsolvedInstTrav (yyyGNT *, long *, long *);
static void yyyUnsolvedInstSearchTravAux (yyyGNT *);
static void yyyDecorate (bool pruning);

#line 472 "y.tab.c"


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
typedef yytype_int8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
       2,     2,     2,     2,     2,    27,     2,     2,     2,     2,
      20,    22,    25,    24,    21,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,     2,    26,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   257,   257,    36,   282,    47,    52,    60,   334,    71,
      78,    79,    82,    89,   428,   100,   108,   112,   484,   131,
     141,   521,   152,   162,   168,   174,   179,   185,   192,   198,
     628,   206,   215,   220,   228,   229,   232,   237,   242,   248,
     254,   260,   266,   272,   279,   280,   281,   282,   285,   290,
     298,   303,   311,   316,   953,   325,   333,   338,   342,   346,
     351
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
  "\"end of file\"", "error", "\"invalid token\"", "OBJECT", "INT",
  "CLASS", "END", "RETURN", "COND", "CONTINUE", "BREAK", "NOT", "OR",
  "NEW", "NULLTERM", "ID", "NUM", "LEFTASSIGN", "RIGHTASSIGN", "';'",
  "'('", "','", "')'", "'-'", "'+'", "'*'", "'>'", "'#'", "$accept",
  "yyyAugNonterm", "Start", "Program", "Selector", "OptType", "Type",
  "Class", "MemberStart", "OptMember", "Member", "Pars", "Par", "Stats",
  "Stat", "Return", "Conditions", "OptGuarded", "Guarded",
  "ContinueOrBreak", "Expr", "Negations", "PlusTerm", "MulTerm", "OrTerm",
  "RepExpr", "Term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    59,
      40,    44,    41,    45,    43,    42,    62,    35
};
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -74,     8,   -74,    33,   -74,   -74,   -74,     2,     3,    19,
      24,   -74,   -74,    37,   -74,    56,     1,    36,   -74,    48,
      52,   -74,    44,   -74,   -10,     1,     1,   -74,    57,   -74,
     -74,   -74,    20,     1,   -74,   -74,    66,    88,   -74,   -74,
      60,   -74,   -14,   -74,    88,   -74,    61,    59,    78,   -74,
     -74,    98,   -11,    47,   -74,    77,   -74,    88,    88,    63,
      70,   -74,   -74,   -74,   -74,   -74,    15,    15,    15,    15,
      15,    72,    69,    86,   -74,   -74,    87,    89,   -74,   -74,
     -74,    88,   -74,   -74,   -74,   -74,   -74,    15,    15,    15,
      45,   -74,   -74,    29,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,    45,    88,   -74,   -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     3,     1,    11,    10,     0,     0,     0,
       0,    14,     5,     0,     6,     0,    13,     0,    12,     0,
       0,     8,    16,    15,     0,     0,     0,     7,     0,    18,
       9,    20,     0,     0,    21,    19,     0,     0,    30,    44,
       0,    58,    59,    57,     0,    45,     0,     0,    23,    24,
      27,     0,    36,    59,    28,     0,    43,     0,     0,     0,
       0,    22,    17,    46,    47,    37,     0,     0,     0,     0,
       0,    38,    39,    40,    29,    21,     0,     0,    26,    54,
      56,     0,    52,    48,    50,    42,    41,     0,     0,     0,
       0,    31,    21,     0,    25,    49,    51,    53,    34,    35,
      23,    32,     0,     0,    60,    33,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,     7,   -74,   -74,   -74,
     -74,   -74,    82,   -73,   -74,    74,   -74,   -74,   -74,    14,
     -37,   -74,   -74,   -74,   -74,   -74,   -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     3,     8,    24,    46,    10,    15,    16,
      20,    32,    29,    36,    47,   100,    49,    55,    76,   101,
      50,    51,    71,    72,    73,    93,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      54,    66,    90,    57,     5,     6,    58,    59,     4,    65,
       9,    26,    27,    67,    68,    69,    70,    11,    77,   102,
      78,    79,    12,    19,    82,    83,    84,    85,    86,    41,
      53,    43,    28,    30,    13,    44,     5,     6,     7,    21,
      28,    33,    34,    14,    94,    95,    96,    97,     5,     6,
     103,   104,    37,    38,    98,    99,    39,    17,    40,    41,
      42,    43,    18,    22,    25,    44,   106,    58,    45,     5,
       6,    23,    31,    37,    38,    56,    60,    39,    61,    40,
      41,    42,    43,    74,    62,    80,    44,    81,    39,    45,
      40,    41,    53,    43,    88,    75,    87,    44,    89,    39,
      45,    40,    41,    53,    43,     0,    91,    92,    44,    63,
      48,    45,    41,    53,    43,    35,   105,     0,    44,     0,
       0,    64
};

static const yytype_int8 yycheck[] =
{
      37,    12,    75,    17,     3,     4,    20,    44,     0,    51,
       3,    21,    22,    24,    25,    26,    27,    15,    55,    92,
      57,    58,    19,    16,    66,    67,    68,    69,    70,    14,
      15,    16,    25,    26,    15,    20,     3,     4,     5,     3,
      33,    21,    22,    19,    81,    87,    88,    89,     3,     4,
      21,    22,     7,     8,     9,    10,    11,    20,    13,    14,
      15,    16,     6,    15,    20,    20,   103,    20,    23,     3,
       4,    19,    15,     7,     8,    15,    15,    11,    19,    13,
      14,    15,    16,     6,     6,    22,    20,    17,    11,    23,
      13,    14,    15,    16,    25,    18,    24,    20,    12,    11,
      23,    13,    14,    15,    16,    -1,    19,    18,    20,    11,
      36,    23,    14,    15,    16,    33,   102,    -1,    20,    -1,
      -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    31,     0,     3,     4,     5,    32,    34,
      35,    15,    19,    15,    19,    36,    37,    20,     6,    34,
      38,     3,    15,    19,    33,    20,    21,    22,    34,    40,
      34,    15,    39,    21,    22,    40,    41,     7,     8,    11,
      13,    14,    15,    16,    20,    23,    34,    42,    43,    44,
      48,    49,    54,    15,    48,    45,    15,    17,    20,    48,
      15,    19,     6,    11,    23,    54,    12,    24,    25,    26,
      27,    50,    51,    52,     6,    18,    46,    48,    48,    48,
      22,    17,    54,    54,    54,    54,    54,    24,    25,    12,
      41,    19,    18,    53,    48,    54,    54,    54,     9,    10,
      43,    47,    41,    21,    22,    47,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    31,    31,    31,    32,    33,    33,
      34,    34,    35,    36,    37,    37,    38,    38,    39,    39,
      40,    41,    41,    42,    42,    42,    42,    42,    43,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     3,     6,     0,     3,
       1,     1,     4,     1,     0,     3,     2,     9,     0,     3,
       2,     0,     3,     1,     1,     4,     3,     1,     2,     3,
       0,     3,     3,     4,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     2,     1,     1,     2,     2,     2,     3,
       2,     3,     2,     3,     0,     3,     3,     1,     1,     1,
       5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* yyyAugNonterm: Start  */
#line 258 "oxout.y"
                {if(yyyYok)
		   {yyyDecorate(true);
		    yyyExecuteRRsection((yyvsp[0].yyyOxAttrbs).semEl->node);
		    yyyDoTraversals((yyvsp[0].yyyOxAttrbs).semEl->node);
		   }
		}
#line 1512 "y.tab.c"
    break;

  case 3: /* Start: Program  */
#line 269 "oxout.y"
{if(yyyYok){
yyyGenIntNode(1,1,1,4,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(1,1,0,6,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1523 "y.tab.c"
    break;

  case 4: /* Program: %empty  */
#line 282 "oxout.y"
{if(yyyYok){
yyyGenIntNode(2,0,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb7.out
#line 45 "parser.y"
 = newList();
#line 288 "oxout.y"
yyyAdjustINRC(2,0,6,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1538 "y.tab.c"
    break;

  case 5: /* Program: Program Selector ';'  */
#line 297 "oxout.y"
{if(yyyYok){
yyyGenIntNode(3,3,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(3,3,9,15,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1549 "y.tab.c"
    break;

  case 6: /* Program: Program Class ';'  */
#line 308 "oxout.y"
{if(yyyYok){
yyyGenIntNode(4,3,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(4,3,15,24,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1560 "y.tab.c"
    break;

  case 7: /* Selector: Type ID '(' OBJECT OptType ')'  */
#line 321 "oxout.y"
{if(yyyYok){
yyyGenIntNode(5,6,1,6,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(5,6,24,30,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(6,&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1571 "y.tab.c"
    break;

  case 8: /* OptType: %empty  */
#line 334 "oxout.y"
{if(yyyYok){
yyyGenIntNode(6,0,2,3,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyAdjustINRC(6,0,30,33,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1582 "y.tab.c"
    break;

  case 9: /* OptType: OptType ',' Type  */
#line 345 "oxout.y"
{if(yyyYok){
yyyGenIntNode(7,3,2,3,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(7,3,33,39,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1593 "y.tab.c"
    break;

  case 10: /* Type: INT  */
#line 358 "oxout.y"
{if(yyyYok){
yyyGenIntNode(8,1,1,2,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb2.type
#line 78 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 364 "oxout.y"
yyyAdjustINRC(8,1,39,42,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1608 "y.tab.c"
    break;

  case 11: /* Type: OBJECT  */
#line 373 "oxout.y"
{if(yyyYok){
yyyGenIntNode(9,1,1,2,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb2.type
#line 79 "parser.y"
 = newTypeWith(TYPE_OBJECT, TYPE_NONE);
#line 379 "oxout.y"
yyyAdjustINRC(9,1,42,45,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1623 "y.tab.c"
    break;

  case 12: /* Class: CLASS ID MemberStart END  */
#line 390 "oxout.y"
{if(yyyYok){
yyyGenIntNode(10,4,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb7.out
#line 84 "parser.y"
 = addDev(newList(),
#line 396 "oxout.y"
(yyval.yyyOxAttrbs).semEl->node->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 84 "parser.y"
, newType(), KIND_CLASS,
#line 400 "oxout.y"
(yyval.yyyOxAttrbs).semEl->node->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 84 "parser.y"
, "add Class with ID");
#line 404 "oxout.y"
yyyAdjustINRC(10,4,45,51,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(4,&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1646 "y.tab.c"
    break;

  case 13: /* MemberStart: OptMember  */
#line 415 "oxout.y"
{if(yyyYok){
yyyGenIntNode(11,1,2,5,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(11,1,51,57,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1657 "y.tab.c"
    break;

  case 14: /* OptMember: %empty  */
#line 428 "oxout.y"
{if(yyyYok){
yyyGenIntNode(12,0,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb7.out
#line 98 "parser.y"
 = newList();
#line 434 "oxout.y"
yyyAdjustINRC(12,0,57,60,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1672 "y.tab.c"
    break;

  case 15: /* OptMember: OptMember Member ';'  */
#line 443 "oxout.y"
{if(yyyYok){
yyyGenIntNode(13,3,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(13,3,60,69,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1683 "y.tab.c"
    break;

  case 16: /* Member: Type ID  */
#line 456 "oxout.y"
{if(yyyYok){
yyyGenIntNode(14,2,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(14,2,69,72,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1694 "y.tab.c"
    break;

  case 17: /* Member: Type ID '(' Par Pars ')' Stats Return END  */
#line 467 "oxout.y"
{if(yyyYok){
yyyGenIntNode(15,9,2,7,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-8].yyyOxAttrbs),&(yyvsp[-7].yyyOxAttrbs),&(yyvsp[-6].yyyOxAttrbs),&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb7.out
#line 114 "parser.y"
 = newList();
#line 473 "oxout.y"
yyyAdjustINRC(15,9,72,96,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-8].yyyOxAttrbs),&(yyvsp[-7].yyyOxAttrbs),&(yyvsp[-6].yyyOxAttrbs),&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(9,&(yyvsp[-8].yyyOxAttrbs),&(yyvsp[-7].yyyOxAttrbs),&(yyvsp[-6].yyyOxAttrbs),&(yyvsp[-5].yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1709 "y.tab.c"
    break;

  case 18: /* Pars: %empty  */
#line 484 "oxout.y"
{if(yyyYok){
yyyGenIntNode(16,0,4,10,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyAdjustINRC(16,0,96,102,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1720 "y.tab.c"
    break;

  case 19: /* Pars: Pars ',' Par  */
#line 495 "oxout.y"
{if(yyyYok){
yyyGenIntNode(17,3,4,10,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(17,3,102,117,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1731 "y.tab.c"
    break;

  case 20: /* Par: Type ID  */
#line 508 "oxout.y"
{if(yyyYok){
yyyGenIntNode(18,2,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(18,2,117,123,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1742 "y.tab.c"
    break;

  case 21: /* Stats: %empty  */
#line 521 "oxout.y"
{if(yyyYok){
yyyGenIntNode(19,0,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyAdjustINRC(19,0,123,126,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1753 "y.tab.c"
    break;

  case 22: /* Stats: Stats Stat ';'  */
#line 532 "oxout.y"
{if(yyyYok){
yyyGenIntNode(20,3,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(20,3,126,141,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1764 "y.tab.c"
    break;

  case 23: /* Stat: Return  */
#line 545 "oxout.y"
{if(yyyYok){
yyyGenIntNode(21,1,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(21,1,141,150,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1775 "y.tab.c"
    break;

  case 24: /* Stat: Conditions  */
#line 556 "oxout.y"
{if(yyyYok){
yyyGenIntNode(22,1,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(22,1,150,159,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1786 "y.tab.c"
    break;

  case 25: /* Stat: Type ID LEFTASSIGN Expr  */
#line 567 "oxout.y"
{if(yyyYok){
yyyGenIntNode(23,4,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(23,4,159,165,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(4,&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1797 "y.tab.c"
    break;

  case 26: /* Stat: ID LEFTASSIGN Expr  */
#line 578 "oxout.y"
{if(yyyYok){
yyyGenIntNode(24,3,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(24,3,165,171,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1808 "y.tab.c"
    break;

  case 27: /* Stat: Expr  */
#line 589 "oxout.y"
{if(yyyYok){
yyyGenIntNode(25,1,3,9,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(25,1,171,177,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1819 "y.tab.c"
    break;

  case 28: /* Return: RETURN Expr  */
#line 602 "oxout.y"
{if(yyyYok){
yyyGenIntNode(26,2,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(26,2,177,180,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1830 "y.tab.c"
    break;

  case 29: /* Conditions: COND OptGuarded END  */
#line 615 "oxout.y"
{if(yyyYok){
yyyGenIntNode(27,3,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(27,3,180,186,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1841 "y.tab.c"
    break;

  case 30: /* OptGuarded: %empty  */
#line 628 "oxout.y"
{if(yyyYok){
yyyGenIntNode(28,0,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyAdjustINRC(28,0,186,186,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 1852 "y.tab.c"
    break;

  case 31: /* OptGuarded: OptGuarded Guarded ';'  */
#line 638 "oxout.y"
{if(yyyYok){
yyyGenIntNode(29,3,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(29,3,186,198,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1863 "y.tab.c"
    break;

  case 32: /* Guarded: RIGHTASSIGN Stats ContinueOrBreak  */
#line 651 "oxout.y"
{if(yyyYok){
yyyGenIntNode(30,3,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(30,3,198,204,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1874 "y.tab.c"
    break;

  case 33: /* Guarded: Expr RIGHTASSIGN Stats ContinueOrBreak  */
#line 662 "oxout.y"
{if(yyyYok){
yyyGenIntNode(31,4,2,8,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(31,4,204,213,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(4,&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1885 "y.tab.c"
    break;

  case 34: /* ContinueOrBreak: CONTINUE  */
#line 675 "oxout.y"
{if(yyyYok){
yyyGenIntNode(32,1,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(32,1,213,213,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1896 "y.tab.c"
    break;

  case 35: /* ContinueOrBreak: BREAK  */
#line 685 "oxout.y"
{if(yyyYok){
yyyGenIntNode(33,1,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(33,1,213,213,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1907 "y.tab.c"
    break;

  case 36: /* Expr: Term  */
#line 697 "oxout.y"
{if(yyyYok){
yyyGenIntNode(34,1,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(34,1,213,219,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 1918 "y.tab.c"
    break;

  case 37: /* Expr: Negations Term  */
#line 708 "oxout.y"
{if(yyyYok){
yyyGenIntNode(35,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 240 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 714 "oxout.y"
yyyAdjustINRC(35,2,219,225,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1933 "y.tab.c"
    break;

  case 38: /* Expr: Term PlusTerm  */
#line 723 "oxout.y"
{if(yyyYok){
yyyGenIntNode(36,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 246 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 729 "oxout.y"
yyyAdjustINRC(36,2,225,234,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1948 "y.tab.c"
    break;

  case 39: /* Expr: Term MulTerm  */
#line 738 "oxout.y"
{if(yyyYok){
yyyGenIntNode(37,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 252 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 744 "oxout.y"
yyyAdjustINRC(37,2,234,243,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1963 "y.tab.c"
    break;

  case 40: /* Expr: Term OrTerm  */
#line 753 "oxout.y"
{if(yyyYok){
yyyGenIntNode(38,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 258 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 759 "oxout.y"
yyyAdjustINRC(38,2,243,252,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1978 "y.tab.c"
    break;

  case 41: /* Expr: Term '#' Term  */
#line 768 "oxout.y"
{if(yyyYok){
yyyGenIntNode(39,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 264 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 774 "oxout.y"
yyyAdjustINRC(39,3,252,261,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 1993 "y.tab.c"
    break;

  case 42: /* Expr: Term '>' Term  */
#line 783 "oxout.y"
{if(yyyYok){
yyyGenIntNode(40,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 270 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 789 "oxout.y"
yyyAdjustINRC(40,3,261,270,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2008 "y.tab.c"
    break;

  case 43: /* Expr: NEW ID  */
#line 798 "oxout.y"
{if(yyyYok){
yyyGenIntNode(41,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 274 "parser.y"
 = newTypeWith(TYPE_OBJECT, TYPE_NONE);
#line 804 "oxout.y"
yyyAdjustINRC(41,2,270,273,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2023 "y.tab.c"
    break;

  case 44: /* Negations: NOT  */
#line 815 "oxout.y"
{if(yyyYok){
yyyGenIntNode(42,1,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(42,1,273,273,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 2034 "y.tab.c"
    break;

  case 45: /* Negations: '-'  */
#line 825 "oxout.y"
{if(yyyYok){
yyyGenIntNode(43,1,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(43,1,273,273,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 2045 "y.tab.c"
    break;

  case 46: /* Negations: Negations NOT  */
#line 835 "oxout.y"
{if(yyyYok){
yyyGenIntNode(44,2,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(44,2,273,273,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2056 "y.tab.c"
    break;

  case 47: /* Negations: Negations '-'  */
#line 845 "oxout.y"
{if(yyyYok){
yyyGenIntNode(45,2,0,0,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(45,2,273,273,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2067 "y.tab.c"
    break;

  case 48: /* PlusTerm: '+' Term  */
#line 857 "oxout.y"
{if(yyyYok){
yyyGenIntNode(46,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 288 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 863 "oxout.y"
yyyAdjustINRC(46,2,273,279,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2082 "y.tab.c"
    break;

  case 49: /* PlusTerm: PlusTerm '+' Term  */
#line 872 "oxout.y"
{if(yyyYok){
yyyGenIntNode(47,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 293 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 878 "oxout.y"
yyyAdjustINRC(47,3,279,288,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2097 "y.tab.c"
    break;

  case 50: /* MulTerm: '*' Term  */
#line 889 "oxout.y"
{if(yyyYok){
yyyGenIntNode(48,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 301 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 895 "oxout.y"
yyyAdjustINRC(48,2,288,294,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2112 "y.tab.c"
    break;

  case 51: /* MulTerm: MulTerm '*' Term  */
#line 904 "oxout.y"
{if(yyyYok){
yyyGenIntNode(49,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 306 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 910 "oxout.y"
yyyAdjustINRC(49,3,294,303,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2127 "y.tab.c"
    break;

  case 52: /* OrTerm: OR Term  */
#line 921 "oxout.y"
{if(yyyYok){
yyyGenIntNode(50,2,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 314 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 927 "oxout.y"
yyyAdjustINRC(50,2,303,309,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(2,&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2142 "y.tab.c"
    break;

  case 53: /* OrTerm: OrTerm OR Term  */
#line 936 "oxout.y"
{if(yyyYok){
yyyGenIntNode(51,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 319 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 942 "oxout.y"
yyyAdjustINRC(51,3,309,318,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2157 "y.tab.c"
    break;

  case 54: /* RepExpr: %empty  */
#line 953 "oxout.y"
{if(yyyYok){
yyyGenIntNode(52,0,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyAdjustINRC(52,0,318,318,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(0);
}}
#line 2168 "y.tab.c"
    break;

  case 55: /* RepExpr: RepExpr ',' Expr  */
#line 963 "oxout.y"
{if(yyyYok){
yyyGenIntNode(53,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(53,3,318,327,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2179 "y.tab.c"
    break;

  case 56: /* Term: '(' Expr ')'  */
#line 976 "oxout.y"
{if(yyyYok){
yyyGenIntNode(54,3,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(54,3,327,333,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(3,&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2190 "y.tab.c"
    break;

  case 57: /* Term: NUM  */
#line 987 "oxout.y"
{if(yyyYok){
yyyGenIntNode(55,1,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 340 "parser.y"
 = newTypeWith(TYPE_INT, TYPE_NONE);
#line 993 "oxout.y"
yyyAdjustINRC(55,1,333,336,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 2205 "y.tab.c"
    break;

  case 58: /* Term: NULLTERM  */
#line 1002 "oxout.y"
{if(yyyYok){
yyyGenIntNode(56,1,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->yyyAttrbs.yyyAttrb11.type
#line 344 "parser.y"
 = newTypeWith(TYPE_OBJECT, TYPE_NONE);
#line 1008 "oxout.y"
yyyAdjustINRC(56,1,336,339,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 2220 "y.tab.c"
    break;

  case 59: /* Term: ID  */
#line 1017 "oxout.y"
{if(yyyYok){
yyyGenIntNode(57,1,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyAdjustINRC(57,1,339,342,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(1,&(yyvsp[0].yyyOxAttrbs));
}}
#line 2231 "y.tab.c"
    break;

  case 60: /* Term: ID '(' Expr RepExpr ')'  */
#line 1028 "oxout.y"
{if(yyyYok){
yyyGenIntNode(58,5,2,11,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
(yyval.yyyOxAttrbs).semEl->node->cL[3]->yyyAttrbs.yyyAttrb11.type
#line 355 "parser.y"
 = newType();
#line 1034 "oxout.y"
yyyAdjustINRC(58,5,342,354,(yyyOxAttrbs *)&(yyval.yyyOxAttrbs),&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
yyyDecorate(false);
yyyReclaimSemStkEls(5,&(yyvsp[-4].yyyOxAttrbs),&(yyvsp[-3].yyyOxAttrbs),&(yyvsp[-2].yyyOxAttrbs),&(yyvsp[-1].yyyOxAttrbs),&(yyvsp[0].yyyOxAttrbs));
}}
#line 2246 "y.tab.c"
    break;


#line 2250 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 361 "parser.y"




int main(void)
{
    int ret = yyparse();
    return ret;
}

#line 1053 "oxout.y"
/* The maximum size of the Ready Set. */
static long yyyRSmaxSize =        0L;
/* The maximum size of the postdecoration-traversal stack; */
/* needed for a depth-first traversal of the parse tree. */
static long yyyTravStackMaxSize = 1000L;

#define yyyLambdaSSAL (yyySSALC *) NULL
static yyySSALC *yyySSALCfreeList = yyyLambdaSSAL;



static yyyFT yyyRCIL[] = {
yyyR,0,1, 0,0,1, yyyR,1,0, yyyR,1,2, 0,0,1, yyyR,1,2,
0,0,1, 1,0,1, yyyR,0,1, 4,0,1, yyyR,1,1, yyyR,1,2,
0,0,1, yyyR,0,0, yyyR,0,0, yyyR,1,0, 2,0,1, yyyR,1,2,
0,0,1, yyyR,1,0, yyyR,1,2, 0,0,1, 1,0,1, yyyR,1,1,
yyyR,1,0, 3,0,1, 4,0,1, 4,2,2, 6,0,1, 6,2,1,
7,0,1, 7,1,1, yyyR,1,1, yyyR,3,1, yyyR,1,1, yyyR,3,2,
0,0,1, 0,2,1, 2,0,1, yyyR,1,2, yyyR,2,1, yyyR,1,1,
yyyR,1,1, 0,0,1, 0,2,1, 1,0,1, 1,2,1, yyyR,1,1,
0,0,1, 0,1,1, yyyR,1,1, 0,0,1, 0,1,1, yyyR,1,2,
3,0,1, yyyR,1,1, 2,0,1, yyyR,1,1, 0,0,1, 1,0,1,
1,0,1, 1,1,1, 0,0,1, 0,1,1, 1,0,1, 1,1,1,
1,0,1, 1,2,1, 0,0,1, 2,0,1, 2,2,1, yyyR,1,1,
0,0,1, yyyR,1,0, 1,0,1, yyyR,1,0, 0,0,1, 1,0,1,
yyyR,1,0, 0,0,1, 1,0,1, yyyR,1,0, 0,0,1, 1,0,1,
yyyR,1,0, 0,0,1, 2,0,1, yyyR,1,0, 0,0,1, 2,0,1,
yyyR,1,0, yyyR,1,0, 1,0,1, yyyR,1,0, 0,0,1, 2,0,1,
yyyR,1,0, 1,0,1, yyyR,1,0, 0,0,1, 2,0,1, yyyR,1,0,
1,0,1, yyyR,1,0, 0,0,1, 2,0,1, 0,0,1, 0,1,1,
2,0,1, yyyR,1,1, 1,0,1, yyyR,1,0, yyyR,1,0, yyyR,1,1,
yyyR,1,1, 2,0,1, 3,0,1, 3,1,0,
};

static short yyyIIIEL[] = {0,
0,2,3,7,11,18,19,23,25,27,
32,34,35,39,42,52,53,57,60,61,
65,67,69,74,78,80,83,87,88,92,
96,101,103,105,107,110,113,116,119,123,
127,130,132,134,137,140,143,147,150,154,
157,161,162,166,170,172,174,176,
};

static long yyyIIEL[] = {
0,1,3,5,7,9,10,10,12,14,16,16,
17,18,20,20,20,22,22,24,26,28,28,29,
30,30,31,31,33,33,35,37,37,39,41,43,
45,47,49,49,51,52,54,56,57,59,59,62,
66,66,69,71,71,75,79,83,83,86,89,90,
92,95,98,101,104,104,107,109,112,114,117,118,
120,120,122,125,127,127,129,132,134,136,136,138,
140,140,142,142,144,146,148,150,150,152,152,155,
155,157,159,159,162,162,162,162,162,162,164,166,
168,168,170,172,174,176,178,180,182,184,186,188,
190,192,192,194,196,198,198,200,202,202,204,204,
204,204,204,204,204,204,204,204,204,206,206,208,
210,212,212,214,216,216,218,220,222,222,224,226,
226,228,230,232,232,234,236,238,240,240,242,244,
244,246,246,248,248,250,250,252,254,256,258,258,
260,262,
};

static long yyyIEL[] = {
0,2,2,4,4,4,6,6,
6,8,10,14,14,14,16,16,
18,18,20,22,24,24,26,28,
28,30,30,30,32,34,34,34,
36,36,38,40,40,40,42,44,
44,46,46,46,48,48,50,52,
52,54,54,54,56,58,60,62,
62,68,68,68,68,70,72,72,
74,74,74,74,76,76,76,76,
78,78,80,80,82,82,84,84,
84,86,86,88,88,90,92,94,
94,94,98,100,102,104,104,104,
106,106,110,110,112,112,112,114,
114,118,118,120,120,120,124,124,
126,126,126,128,128,128,130,132,
134,136,136,140,140,140,140,140,
140,140,144,144,144,144,144,146,
146,146,146,148,150,150,150,150,
150,154,158,158,158,158,158,160,
162,162,162,162,166,168,168,168,
168,168,168,170,170,170,172,174,
174,174,174,178,178,178,178,178,
178,182,182,182,182,182,182,186,
186,186,186,186,186,190,190,190,
190,190,190,194,194,194,194,194,
194,194,194,194,194,196,196,196,
196,200,200,200,200,200,200,202,
202,202,202,206,206,206,206,206,
206,208,208,208,208,212,212,212,
212,212,212,212,212,216,218,218,
218,218,218,220,220,220,222,222,
222,222,222,224,224,226,228,234,
234,236,238,238,238,238,238,
};

static yyyFT yyyEntL[] = {
1,0,0,0,1,0,0,1,0,1,2,0,1,0,0,1,
0,1,5,0,0,0,0,0,0,0,0,1,1,0,0,1,
0,1,3,0,0,1,0,1,0,1,1,0,0,1,1,0,
2,0,0,1,0,1,0,1,0,1,0,1,4,0,8,1,
7,2,5,2,5,0,5,2,7,0,8,0,0,1,0,3,
1,0,1,2,3,0,0,3,0,1,0,3,0,1,0,1,
0,2,0,1,0,1,0,1,1,0,2,2,1,2,2,0,
0,1,0,1,1,0,1,1,0,1,1,0,1,1,4,0,
0,1,0,1,0,1,0,1,0,1,3,0,0,1,1,0,
2,0,2,0,2,1,2,0,1,0,2,1,1,1,2,0,
2,2,3,0,1,0,3,2,1,0,0,1,2,0,2,0,
1,0,2,0,1,0,2,0,1,0,3,0,1,0,3,0,
1,0,2,0,3,0,1,0,2,0,3,0,1,0,2,0,
3,0,1,0,3,0,1,0,1,1,2,0,0,1,0,1,
0,1,0,1,0,1,4,0,3,0,0,1,0,1,
};

/* GCC (and some other compilers) define '__attribute__', but */
/* just in case '__attribute__' isn't defined, make a dummy.  */
#if !(defined (__GNUC__) || defined (__attribute__))
#define __attribute__(p) /* nothing */
#endif

static __attribute__((__noreturn__)) void yyyfatal (const char *fmt, ...)
  {va_list ap;
   va_start (ap, fmt);
   (void) vfprintf (stderr, fmt, ap);
   va_end (ap);
   exit (EXIT_FAILURE);
#if defined (S_SPLINT_S)
   /*@notreached@*/ ;
#elif defined (lint)
   NOTE(NOTREACHED)
#elif defined (__GNUC__)
   __builtin_unreachable ();
#endif
  }



static void yyySignalEnts (yyyGNT *node, long startP, long stopP)
  {yyyGNT *dumNode;

   while (startP < stopP)
     {if (yyyEntL[startP]==0) dumNode = node;
      else dumNode = (node->cL)[yyyEntL[startP]-1];
      if ((--((dumNode->refCountList)[yyyEntL[startP +1]]))==0)
         {if (++yyyRSTop==yyyAfterRS)
             {/* reallocate 'yyyRS' data structure */
#if defined (__cplusplus)
              long oldRSmaxSize = yyyRSmaxSize;
              yyyRSmaxSize += 500L;
              try {
                 struct yyyRSitem *newRS =
                    new struct yyyRSitem [yyyRSmaxSize +1];
                 for (int i = 0; i < oldRSmaxSize; i++)
                    newRS [i] = yyyRS [i];
                 delete[] yyyRS; yyyRS = newRS;
              } catch (std::bad_alloc) {
                 yyyfatal ("error in Ox Ready Set space allocation\n");
              }
#else /* !defined (__cplusplus) */
              yyyRSmaxSize += 500L;
              if ((yyyRS =
                   (struct yyyRSitem *) realloc (yyyRS,
                                                 (size_t) ((size_t) (yyyRSmaxSize +1) * sizeof (struct yyyRSitem)))
                  )==(struct yyyRSitem *) NULL
                 )
                 yyyfatal ("realloc error in Ox Ready Set space allocation\n");
#endif /* !defined (__cplusplus) */
              yyyAfterRS = yyyRSmaxSize +1;
             }
          yyyRS[yyyRSTop].node = dumNode;
          yyyRS[yyyRSTop].whichSym = yyyEntL[startP];
          yyyRS[yyyRSTop].whichAttrb = yyyEntL[startP +1];
         }
      startP += 2;
     }
  }



static void yyyDecorate (bool pruning)
  {



#define yyyDECORfREQ 50



   static unsigned short intNodeCount = yyyDECORfREQ;
   if (--intNodeCount==0)
      intNodeCount = yyyDECORfREQ;
   else
      if (!pruning) return;
   while (yyyRSTop >= yyyRSBottom)
     {
yyyWST whichSym; yyyWAT whichAttrb;
yyyGNT *RSTopNode, *RSNode;
yyyParent RSTopParent;


RSTopParent = (RSTopNode = yyyRS[yyyRSTop].node)->parent;
RSNode = ((whichSym = (yyyRS[yyyRSTop].whichSym))!=0) ? RSTopParent.noderef : RSTopNode;
whichAttrb = yyyRS[yyyRSTop].whichAttrb;
yyyRSTop--;
switch (RSNode->prodNum) {
case 1:  /***Yacc rule 1***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb4.names
#line 38 "parser.y"
 =
#line 1269 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.out
#line 38 "parser.y"
;
#line 1273 "oxout.y"
yyySignalEnts(RSNode,0,2);
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 39 "parser.y"
 =
#line 1284 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb4.names
#line 39 "parser.y"
;
#line 1288 "oxout.y"
    break;
    }
  break;
  }
break;
case 2:  /***Yacc rule 2***/
  switch (whichSym) {
  }
break;
case 3:  /***Yacc rule 3***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb7.out
#line 49 "parser.y"
 = mergeDev(
#line 1306 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.out
#line 49 "parser.y"
,
#line 1310 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb6.out
#line 49 "parser.y"
, "merge Program with Selector");
#line 1314 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 50 "parser.y"
 =
#line 1324 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 50 "parser.y"
;
#line 1328 "oxout.y"
    break;
    }
  break;
  }
break;
case 4:  /***Yacc rule 4***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb7.out
#line 54 "parser.y"
 = mergeDev(
#line 1342 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.out
#line 54 "parser.y"
,
#line 1346 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb7.out
#line 54 "parser.y"
, "merge Program with Class");
#line 1350 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 55 "parser.y"
 =
#line 1360 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 55 "parser.y"
;
#line 1364 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 56 "parser.y"
 =
#line 1374 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 56 "parser.y"
;
#line 1378 "oxout.y"
    break;
    }
  break;
  }
break;
case 5:  /***Yacc rule 5***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb6.out
#line 63 "parser.y"
 = addDev(newList(),
#line 1392 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 63 "parser.y"
,
#line 1396 "oxout.y"
RSNode->cL[4]->yyyAttrbs.yyyAttrb3.typeOut
#line 63 "parser.y"
, KIND_SELECTOR,
#line 1400 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 63 "parser.y"
, "add Selector with ID") ;
#line 1404 "oxout.y"
    break;
    }
  break;
  case 5:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb3.typeIn
#line 62 "parser.y"
 = typeParamsAppend(
#line 1414 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 62 "parser.y"
, TYPE_OBJECT);
#line 1418 "oxout.y"
    break;
    }
  break;
  }
break;
case 6:  /***Yacc rule 6***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb3.typeOut
#line 69 "parser.y"
 =
#line 1432 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb3.typeIn
#line 69 "parser.y"
;
#line 1436 "oxout.y"
    break;
    }
  break;
  }
break;
case 7:  /***Yacc rule 7***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb3.typeOut
#line 74 "parser.y"
 = typeParamsAppend(
#line 1450 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb3.typeOut
#line 74 "parser.y"
,
#line 1454 "oxout.y"
RSNode->cL[2]->yyyAttrbs.yyyAttrb2.type
#line 74 "parser.y"
.type);
#line 1458 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb3.typeIn
#line 73 "parser.y"
 =
#line 1468 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb3.typeIn
#line 73 "parser.y"
;
#line 1472 "oxout.y"
    break;
    }
  break;
  }
break;
case 8:  /***Yacc rule 8***/
  switch (whichSym) {
  }
break;
case 9:  /***Yacc rule 9***/
  switch (whichSym) {
  }
break;
case 10:  /***Yacc rule 10***/
  switch (whichSym) {
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb5.namesIn
#line 85 "parser.y"
 = duplicate(
#line 1494 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 85 "parser.y"
);
#line 1498 "oxout.y"
    break;
    }
  break;
  }
break;
case 11:  /***Yacc rule 11***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb5.namesOut
#line 91 "parser.y"
 = mergeDev(
#line 1512 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb5.namesIn
#line 91 "parser.y"
,
#line 1516 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.out
#line 91 "parser.y"
, "merge MemberStart with OptMember");
#line 1520 "oxout.y"
yyySignalEnts(RSNode,42,44);
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 92 "parser.y"
 =
#line 1531 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb5.namesOut
#line 92 "parser.y"
;
#line 1535 "oxout.y"
    break;
    }
  break;
  }
break;
case 12:  /***Yacc rule 12***/
  switch (whichSym) {
  }
break;
case 13:  /***Yacc rule 13***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb7.out
#line 102 "parser.y"
 = mergeDev(
#line 1553 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.out
#line 102 "parser.y"
,
#line 1557 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb7.out
#line 102 "parser.y"
, "merge OptMember with Member");
#line 1561 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 103 "parser.y"
 =
#line 1571 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 103 "parser.y"
;
#line 1575 "oxout.y"
yyySignalEnts(RSNode,48,50);
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb7.in
#line 104 "parser.y"
 =
#line 1586 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb7.in
#line 104 "parser.y"
;
#line 1590 "oxout.y"
    break;
    }
  break;
  }
break;
case 14:  /***Yacc rule 14***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb7.out
#line 110 "parser.y"
 = addDev(newList(),
#line 1604 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 110 "parser.y"
,
#line 1608 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 110 "parser.y"
, KIND_CLASS_VARIABLE,
#line 1612 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 110 "parser.y"
, "add Classvariable with ID");
#line 1616 "oxout.y"
    break;
    }
  break;
  }
break;
case 15:  /***Yacc rule 15***/
  switch (whichSym) {
  case 4:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 115 "parser.y"
 = duplicate(
#line 1630 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb7.in
#line 115 "parser.y"
);
#line 1634 "oxout.y"
    break;
    }
  break;
  case 5:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb10.in
#line 116 "parser.y"
 =
#line 1644 "oxout.y"
RSNode->cL[3]->yyyAttrbs.yyyAttrb9.out
#line 116 "parser.y"
;
#line 1648 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb10.typeIn
#line 117 "parser.y"
 = typeParamsAppend(
#line 1654 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 117 "parser.y"
,
#line 1658 "oxout.y"
RSNode->cL[3]->yyyAttrbs.yyyAttrb9.type
#line 117 "parser.y"
.type);
#line 1662 "oxout.y"
    break;
    }
  break;
  case 7:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 118 "parser.y"
 =
#line 1672 "oxout.y"
RSNode->cL[4]->yyyAttrbs.yyyAttrb10.out
#line 118 "parser.y"
;
#line 1676 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 119 "parser.y"
 =
#line 1682 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 119 "parser.y"
;
#line 1686 "oxout.y"
    break;
    }
  break;
  case 8:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 120 "parser.y"
 =
#line 1696 "oxout.y"
RSNode->cL[6]->yyyAttrbs.yyyAttrb9.out
#line 120 "parser.y"
;
#line 1700 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 121 "parser.y"
 =
#line 1706 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 121 "parser.y"
;
#line 1710 "oxout.y"
    break;
    }
  break;
  }
break;
case 16:  /***Yacc rule 16***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb10.out
#line 128 "parser.y"
 =
#line 1724 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb10.in
#line 128 "parser.y"
;
#line 1728 "oxout.y"
    break;
    case 3:
RSTopNode->yyyAttrbs.yyyAttrb10.typeOut
#line 129 "parser.y"
 =
#line 1734 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb10.typeIn
#line 129 "parser.y"
;
#line 1738 "oxout.y"
    break;
    }
  break;
  }
break;
case 17:  /***Yacc rule 17***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb10.out
#line 136 "parser.y"
 =
#line 1752 "oxout.y"
RSNode->cL[2]->yyyAttrbs.yyyAttrb9.out
#line 136 "parser.y"
;
#line 1756 "oxout.y"
    break;
    case 3:
RSTopNode->yyyAttrbs.yyyAttrb10.typeOut
#line 137 "parser.y"
 = typeParamsAppend(
#line 1762 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb10.typeOut
#line 137 "parser.y"
,
#line 1766 "oxout.y"
RSNode->cL[2]->yyyAttrbs.yyyAttrb9.type
#line 137 "parser.y"
.type);
#line 1770 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb10.in
#line 133 "parser.y"
 =
#line 1780 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb10.in
#line 133 "parser.y"
;
#line 1784 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb10.typeIn
#line 134 "parser.y"
 =
#line 1790 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb10.typeIn
#line 134 "parser.y"
;
#line 1794 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 135 "parser.y"
 =
#line 1804 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb10.out
#line 135 "parser.y"
;
#line 1808 "oxout.y"
    break;
    }
  break;
  }
break;
case 18:  /***Yacc rule 18***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 143 "parser.y"
 = addDev(
#line 1822 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 143 "parser.y"
,
#line 1826 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 143 "parser.y"
,
#line 1830 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 143 "parser.y"
, KIND_PARAMETER,
#line 1834 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 143 "parser.y"
, "add Parameter with ID");
#line 1838 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 144 "parser.y"
 =
#line 1844 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 144 "parser.y"
;
#line 1848 "oxout.y"
    break;
    }
  break;
  }
break;
case 19:  /***Yacc rule 19***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 150 "parser.y"
 =
#line 1862 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 150 "parser.y"
;
#line 1866 "oxout.y"
    break;
    }
  break;
  }
break;
case 20:  /***Yacc rule 20***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 158 "parser.y"
 =
#line 1880 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb9.out
#line 158 "parser.y"
;
#line 1884 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 154 "parser.y"
 =
#line 1894 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 154 "parser.y"
;
#line 1898 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 155 "parser.y"
 =
#line 1904 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.type
#line 155 "parser.y"
;
#line 1908 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 156 "parser.y"
 =
#line 1918 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb9.out
#line 156 "parser.y"
;
#line 1922 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 157 "parser.y"
 =
#line 1928 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.type
#line 157 "parser.y"
;
#line 1932 "oxout.y"
    break;
    }
  break;
  }
break;
case 21:  /***Yacc rule 21***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 166 "parser.y"
 =
#line 1946 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 166 "parser.y"
;
#line 1950 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 164 "parser.y"
 =
#line 1960 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 164 "parser.y"
;
#line 1964 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 165 "parser.y"
 =
#line 1970 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.type
#line 165 "parser.y"
;
#line 1974 "oxout.y"
    break;
    }
  break;
  }
break;
case 22:  /***Yacc rule 22***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 172 "parser.y"
 =
#line 1988 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 172 "parser.y"
;
#line 1992 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 170 "parser.y"
 =
#line 2002 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 170 "parser.y"
;
#line 2006 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 171 "parser.y"
 =
#line 2012 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.type
#line 171 "parser.y"
;
#line 2016 "oxout.y"
    break;
    }
  break;
  }
break;
case 23:  /***Yacc rule 23***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 177 "parser.y"
 = addDev(duplicate(
#line 2030 "oxout.y"
RSNode->cL[3]->yyyAttrbs.yyyAttrb11.ids
#line 177 "parser.y"
),
#line 2034 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 177 "parser.y"
,
#line 2038 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb2.type
#line 177 "parser.y"
, KIND_VARIABLE,
#line 2042 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 177 "parser.y"
, "Type assignment ID in Stat");
#line 2046 "oxout.y"
    break;
    }
  break;
  case 4:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 176 "parser.y"
 =
#line 2056 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 176 "parser.y"
;
#line 2060 "oxout.y"
yyySignalEnts(RSNode,134,136);
    break;
    }
  break;
  }
break;
case 24:  /***Yacc rule 24***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 182 "parser.y"
 =
#line 2075 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 182 "parser.y"
;
#line 2079 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 181 "parser.y"
 =
#line 2089 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 181 "parser.y"
;
#line 2093 "oxout.y"
    break;
    }
  break;
  }
break;
case 25:  /***Yacc rule 25***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb9.out
#line 188 "parser.y"
 =
#line 2107 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 188 "parser.y"
 ;
#line 2111 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 187 "parser.y"
 =
#line 2121 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb9.in
#line 187 "parser.y"
 ;
#line 2125 "oxout.y"
    break;
    }
  break;
  }
break;
case 26:  /***Yacc rule 26***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 194 "parser.y"
 =
#line 2139 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 194 "parser.y"
;
#line 2143 "oxout.y"
    break;
    }
  break;
  }
break;
case 27:  /***Yacc rule 27***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 200 "parser.y"
 =
#line 2157 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 200 "parser.y"
;
#line 2161 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 201 "parser.y"
 =
#line 2167 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.type
#line 201 "parser.y"
;
#line 2171 "oxout.y"
    break;
    }
  break;
  }
break;
case 28:  /***Yacc rule 28***/
  switch (whichSym) {
  }
break;
case 29:  /***Yacc rule 29***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 208 "parser.y"
 =
#line 2189 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 208 "parser.y"
;
#line 2193 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 209 "parser.y"
 =
#line 2199 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.type
#line 209 "parser.y"
;
#line 2203 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb8.in
#line 210 "parser.y"
 =
#line 2213 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 210 "parser.y"
;
#line 2217 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb8.type
#line 211 "parser.y"
 =
#line 2223 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.type
#line 211 "parser.y"
;
#line 2227 "oxout.y"
    break;
    }
  break;
  }
break;
case 30:  /***Yacc rule 30***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 218 "parser.y"
 = duplicate(
#line 2241 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 218 "parser.y"
);
#line 2245 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 217 "parser.y"
 =
#line 2251 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.type
#line 217 "parser.y"
;
#line 2255 "oxout.y"
    break;
    }
  break;
  }
break;
case 31:  /***Yacc rule 31***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 222 "parser.y"
 =
#line 2269 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 222 "parser.y"
 ;
#line 2273 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb9.in
#line 224 "parser.y"
 = duplicate(
#line 2283 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.in
#line 224 "parser.y"
);
#line 2287 "oxout.y"
    break;
    case 2:
RSTopNode->yyyAttrbs.yyyAttrb9.type
#line 223 "parser.y"
 =
#line 2293 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb8.type
#line 223 "parser.y"
;
#line 2297 "oxout.y"
    break;
    }
  break;
  }
break;
case 34:  /***Yacc rule 34***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb11.type
#line 235 "parser.y"
 =
#line 2311 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb11.type
#line 235 "parser.y"
;
#line 2315 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 234 "parser.y"
 =
#line 2325 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 234 "parser.y"
;
#line 2329 "oxout.y"
    break;
    }
  break;
  }
break;
case 35:  /***Yacc rule 35***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 239 "parser.y"
 =
#line 2343 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 239 "parser.y"
;
#line 2347 "oxout.y"
    break;
    }
  break;
  }
break;
case 36:  /***Yacc rule 36***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 244 "parser.y"
 =
#line 2361 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 244 "parser.y"
;
#line 2365 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 245 "parser.y"
 =
#line 2375 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 245 "parser.y"
;
#line 2379 "oxout.y"
    break;
    }
  break;
  }
break;
case 37:  /***Yacc rule 37***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 250 "parser.y"
 =
#line 2393 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 250 "parser.y"
;
#line 2397 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 251 "parser.y"
 =
#line 2407 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 251 "parser.y"
;
#line 2411 "oxout.y"
    break;
    }
  break;
  }
break;
case 38:  /***Yacc rule 38***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 256 "parser.y"
 =
#line 2425 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 256 "parser.y"
;
#line 2429 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 257 "parser.y"
 =
#line 2439 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 257 "parser.y"
;
#line 2443 "oxout.y"
    break;
    }
  break;
  }
break;
case 39:  /***Yacc rule 39***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 262 "parser.y"
 =
#line 2457 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 262 "parser.y"
;
#line 2461 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 263 "parser.y"
 =
#line 2471 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 263 "parser.y"
;
#line 2475 "oxout.y"
    break;
    }
  break;
  }
break;
case 40:  /***Yacc rule 40***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 268 "parser.y"
 =
#line 2489 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 268 "parser.y"
;
#line 2493 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 269 "parser.y"
 =
#line 2503 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 269 "parser.y"
;
#line 2507 "oxout.y"
    break;
    }
  break;
  }
break;
case 41:  /***Yacc rule 41***/
  switch (whichSym) {
  }
break;
case 46:  /***Yacc rule 46***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 287 "parser.y"
 =
#line 2525 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 287 "parser.y"
;
#line 2529 "oxout.y"
    break;
    }
  break;
  }
break;
case 47:  /***Yacc rule 47***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 292 "parser.y"
 =
#line 2543 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 292 "parser.y"
;
#line 2547 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 294 "parser.y"
 =
#line 2557 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 294 "parser.y"
;
#line 2561 "oxout.y"
    break;
    }
  break;
  }
break;
case 48:  /***Yacc rule 48***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 300 "parser.y"
 =
#line 2575 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 300 "parser.y"
;
#line 2579 "oxout.y"
    break;
    }
  break;
  }
break;
case 49:  /***Yacc rule 49***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 305 "parser.y"
 =
#line 2593 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 305 "parser.y"
;
#line 2597 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 307 "parser.y"
 =
#line 2607 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 307 "parser.y"
;
#line 2611 "oxout.y"
    break;
    }
  break;
  }
break;
case 50:  /***Yacc rule 50***/
  switch (whichSym) {
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 313 "parser.y"
 =
#line 2625 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 313 "parser.y"
;
#line 2629 "oxout.y"
    break;
    }
  break;
  }
break;
case 51:  /***Yacc rule 51***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 318 "parser.y"
 =
#line 2643 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 318 "parser.y"
;
#line 2647 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 320 "parser.y"
 =
#line 2657 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 320 "parser.y"
;
#line 2661 "oxout.y"
    break;
    }
  break;
  }
break;
case 52:  /***Yacc rule 52***/
  switch (whichSym) {
  }
break;
case 53:  /***Yacc rule 53***/
  switch (whichSym) {
  case 1:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 327 "parser.y"
 =
#line 2679 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 327 "parser.y"
;
#line 2683 "oxout.y"
    break;
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb11.type
#line 328 "parser.y"
 =
#line 2689 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.type
#line 328 "parser.y"
;
#line 2693 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 329 "parser.y"
 =
#line 2703 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 329 "parser.y"
;
#line 2707 "oxout.y"
    break;
    }
  break;
  }
break;
case 54:  /***Yacc rule 54***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb11.type
#line 336 "parser.y"
 =
#line 2721 "oxout.y"
RSNode->cL[1]->yyyAttrbs.yyyAttrb11.type
#line 336 "parser.y"
;
#line 2725 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 335 "parser.y"
 =
#line 2735 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 335 "parser.y"
;
#line 2739 "oxout.y"
    break;
    }
  break;
  }
break;
case 55:  /***Yacc rule 55***/
  switch (whichSym) {
  }
break;
case 56:  /***Yacc rule 56***/
  switch (whichSym) {
  }
break;
case 57:  /***Yacc rule 57***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb11.type
#line 348 "parser.y"
 = getType(
#line 2761 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 348 "parser.y"
,
#line 2765 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb1.name
#line 348 "parser.y"
,
#line 2769 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb1.lineNr
#line 348 "parser.y"
);
#line 2773 "oxout.y"
    break;
    }
  break;
  }
break;
case 58:  /***Yacc rule 58***/
  switch (whichSym) {
  case 0:  /**/
    switch (whichAttrb) {
    case 1:
RSTopNode->yyyAttrbs.yyyAttrb11.type
#line 356 "parser.y"
 = getType(
#line 2787 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 356 "parser.y"
,
#line 2791 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb1.name
#line 356 "parser.y"
,
#line 2795 "oxout.y"
RSNode->cL[0]->yyyAttrbs.yyyAttrb1.lineNr
#line 356 "parser.y"
);
#line 2799 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 353 "parser.y"
 =
#line 2809 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 353 "parser.y"
;
#line 2813 "oxout.y"
    break;
    }
  break;
  case 4:  /**/
    switch (whichAttrb) {
    case 0:
RSTopNode->yyyAttrbs.yyyAttrb11.ids
#line 354 "parser.y"
 =
#line 2823 "oxout.y"
RSNode->yyyAttrbs.yyyAttrb11.ids
#line 354 "parser.y"
;
#line 2827 "oxout.y"
    break;
    }
  break;
  }
break;
} /* switch */

if (whichSym!=0) /* the just-solved instance was inherited. */
   {if (RSTopNode->prodNum!=0)
       {long iDum = yyyIIEL[yyyIIIEL[RSTopNode->prodNum]] + whichAttrb;
        yyySignalEnts (RSTopNode, yyyIEL[iDum],
                                  yyyIEL[iDum +1]
                      );
       }
   }
else     /* the just-solved instance was synthesized. */
   {if (!(RSTopNode->parentIsStack)) /* node has a parent. */
       {long iDum = yyyIIEL[yyyIIIEL[RSTopParent.noderef->prodNum] +
                          RSTopNode->whichSym
                         ] +
                  whichAttrb;
        yyySignalEnts (RSTopParent.noderef,
                       yyyIEL[iDum],
                       yyyIEL[iDum +1]
                      );
       }
    else   /* node is still on the stack--it has no parent yet. */
       {yyySSALC **pL = &(RSTopParent.stackref->solvedSAlist);
        yyySSALC *iDum;
        if (yyySSALCfreeList==yyyLambdaSSAL)
#if defined (__cplusplus)
            try {
               iDum = new yyySSALC;
            } catch (std::bad_alloc) {
               yyyfatal ("error in Ox Stack Solved List space allocation\n");
            }
#else
           {iDum = (yyySSALC *) malloc ((size_t) sizeof (yyySSALC));
            if (iDum==yyyLambdaSSAL)
               yyyfatal ("malloc error in Ox Stack Solved List space allocation\n");
           }
#endif
        else
           {iDum = yyySSALCfreeList;
            yyySSALCfreeList = yyySSALCfreeList->next;
           }
        iDum->next = *pL;
        iDum->attrbNum = (yyyWAT) whichAttrb;
        *pL = iDum;
       }
   }

     }
  }




#define yyyCondStg unsigned char conds;
#define yyyClearConds {travStack[travStkPtr].conds = 0;}
#define yyySetCond(n) {travStack[travStkPtr].conds |= (1<<(n));}
#define yyyCond(n) (((travStack[travStkPtr].conds & (1<<(n)))!=0)?1:0)



struct yyyTravStackItem {yyyGNT *node;
                         bool isReady;
                         yyyCondStg
                        };



static void yyyDoTraversals(yyyGNT *rootNode)
{struct yyyTravStackItem *travStack;
 long travStkPtr,afterTravStack;
 yyyGNT *travNode,**cLptr2;
 bool righttoleft=false; int pass;
 int i;

 if (!yyyYok) return;
 if ((travStack =
                 ((struct yyyTravStackItem *)
                  calloc((size_t)yyyTravStackMaxSize,
                         (size_t)sizeof(struct yyyTravStackItem)
                        )
                 )
     )
     ==
     (struct yyyTravStackItem *) NULL
    )
    yyyfatal("malloc error in Ox Traversal Stack allocation\n");

afterTravStack = yyyTravStackMaxSize;
#define yyyTSBottom 1L


for (int travN=0; travN<1; travN++) {
travStkPtr = 1L;
travStack[travStkPtr].node = rootNode;
travStack[travStkPtr].isReady = false;
yyyClearConds

while(travStkPtr >= yyyTSBottom)
  {travNode = travStack[travStkPtr].node;
   if (travStack[travStkPtr].isReady)
      {pass = 1;
       goto travSwitch;
popTravStack:
       travStkPtr--;
      }
   else
      {pass = 0;
       goto travSwitch;
pushTravStack:
       travStack[travStkPtr].isReady = true;
       if (travNode->prodNum!=0)
          {if (righttoleft)
             {cLptr2 = travNode->cL;
              i = travNode->cLlen;
              while ((i--)>0)
                {if (++travStkPtr == afterTravStack)
                    {/* realloc `travStack' data structure */
                     yyyTravStackMaxSize += 500L;
                     if ((travStack = (struct yyyTravStackItem *)
                          realloc(travStack,
                                  (size_t)((size_t)yyyTravStackMaxSize*sizeof(struct yyyTravStackItem)))
                         ) == (struct yyyTravStackItem *) NULL)
                        yyyfatal("malloc error in Ox Traversal Stack allocation\n");
                     afterTravStack = yyyTravStackMaxSize;
                    }
                 travStack[travStkPtr].node = *cLptr2;
                 travStack[travStkPtr].isReady = false;
                 yyyClearConds
                 cLptr2++;
                }
             } /* right to left */
          else  /* left to right */
             {i = travNode->cLlen;
              cLptr2 = travNode->cL + i;
              while ((i--)>0)
                {cLptr2--;
                 if (++travStkPtr == afterTravStack)
                    {/* realloc `travStack' data structure */
                     yyyTravStackMaxSize += 500L;
                     if ((travStack = (struct yyyTravStackItem *)
                          realloc(travStack,
                                  (size_t)((size_t)yyyTravStackMaxSize*sizeof(struct yyyTravStackItem)))
                         ) == (struct yyyTravStackItem *) NULL)
                        yyyfatal("malloc error in Ox Traversal Stack allocation\n");
                     afterTravStack = yyyTravStackMaxSize;
                    }
                  travStack[travStkPtr].node = *cLptr2;
                  travStack[travStkPtr].isReady = false;
                  yyyClearConds
                }
             } /* left to right */
          }
      } /* else */
   continue;
travSwitch:
				switch(travNode->prodNum)	{
case 1:  /***Yacc rule 1***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 2:  /***Yacc rule 2***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 3:  /***Yacc rule 3***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 4:  /***Yacc rule 4***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 5:  /***Yacc rule 5***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 6:  /***Yacc rule 6***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 7:  /***Yacc rule 7***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 8:  /***Yacc rule 8***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 9:  /***Yacc rule 9***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 10:  /***Yacc rule 10***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 11:  /***Yacc rule 11***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 12:  /***Yacc rule 12***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 13:  /***Yacc rule 13***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 14:  /***Yacc rule 14***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 15:  /***Yacc rule 15***/
			switch(pass)	{
				case 0:
righttoleft = false;
#if (__APPLE__ && __clang__ && defined (__apple_build_version__) && __clang_major__ > 11) || \
    (__linux__ && __GNUC__ > 6)
/* Apple Xcode 10 & 11 gcc (tested):
   warning: declaration does not declare anything
   GNU 4, 5 & 6 gcc (tested):
   error: expected primary-expression before '__attribute__'
 */
__attribute__((fallthrough));
#elif defined (S_SPLINT_S)
/*@fallthrough@*/
#elif defined (lint)
NOTE(FALLTHROUGH)
#endif
				case 1:
if (yyyCond(0) != pass) {
#line 122 "parser.y"
isVisible(
#line 3108 "oxout.y"
travNode->yyyAttrbs.yyyAttrb7.in
#line 122 "parser.y"
,
#line 3112 "oxout.y"
travNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 122 "parser.y"
, KIND_SELECTOR,
#line 3116 "oxout.y"
travNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 122 "parser.y"
);
#line 3120 "oxout.y"
}
				break;
					}

break;
case 16:  /***Yacc rule 16***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 17:  /***Yacc rule 17***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 18:  /***Yacc rule 18***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 19:  /***Yacc rule 19***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 20:  /***Yacc rule 20***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 21:  /***Yacc rule 21***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 22:  /***Yacc rule 22***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 23:  /***Yacc rule 23***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 24:  /***Yacc rule 24***/
			switch(pass)	{
				case 0:
righttoleft = false;
#if (__APPLE__ && __clang__ && defined (__apple_build_version__) && __clang_major__ > 11) || \
    (__linux__ && __GNUC__ > 6)
/* Apple Xcode 10 & 11 gcc (tested):
   warning: declaration does not declare anything
   GNU 4, 5 & 6 gcc (tested):
   error: expected primary-expression before '__attribute__'
 */
__attribute__((fallthrough));
#elif defined (S_SPLINT_S)
/*@fallthrough@*/
#elif defined (lint)
NOTE(FALLTHROUGH)
#endif
				case 1:
if (yyyCond(0) != pass) {
#line 183 "parser.y"
isVisibleForUse(
#line 3203 "oxout.y"
travNode->yyyAttrbs.yyyAttrb9.in
#line 183 "parser.y"
,
#line 3207 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.name
#line 183 "parser.y"
,
#line 3211 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.lineNr
#line 183 "parser.y"
);
#line 3215 "oxout.y"
}
				break;
					}

break;
case 25:  /***Yacc rule 25***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 26:  /***Yacc rule 26***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 27:  /***Yacc rule 27***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 28:  /***Yacc rule 28***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 29:  /***Yacc rule 29***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 30:  /***Yacc rule 30***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 31:  /***Yacc rule 31***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 32:  /***Yacc rule 32***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 33:  /***Yacc rule 33***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 34:  /***Yacc rule 34***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 35:  /***Yacc rule 35***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 36:  /***Yacc rule 36***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 37:  /***Yacc rule 37***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 38:  /***Yacc rule 38***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 39:  /***Yacc rule 39***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 40:  /***Yacc rule 40***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 41:  /***Yacc rule 41***/
			switch(pass)	{
				case 0:
righttoleft = false;
#if (__APPLE__ && __clang__ && defined (__apple_build_version__) && __clang_major__ > 11) || \
    (__linux__ && __GNUC__ > 6)
/* Apple Xcode 10 & 11 gcc (tested):
   warning: declaration does not declare anything
   GNU 4, 5 & 6 gcc (tested):
   error: expected primary-expression before '__attribute__'
 */
__attribute__((fallthrough));
#elif defined (S_SPLINT_S)
/*@fallthrough@*/
#elif defined (lint)
NOTE(FALLTHROUGH)
#endif
				case 1:
if (yyyCond(0) != pass) {
#line 275 "parser.y"
isVisible(
#line 3354 "oxout.y"
travNode->yyyAttrbs.yyyAttrb11.ids
#line 275 "parser.y"
,
#line 3358 "oxout.y"
travNode->cL[1]->yyyAttrbs.yyyAttrb1.name
#line 275 "parser.y"
, KIND_CLASS,
#line 3362 "oxout.y"
travNode->cL[1]->yyyAttrbs.yyyAttrb1.lineNr
#line 275 "parser.y"
);
#line 3366 "oxout.y"
}
				break;
					}

break;
case 42:  /***Yacc rule 42***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 43:  /***Yacc rule 43***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 44:  /***Yacc rule 44***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 45:  /***Yacc rule 45***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 46:  /***Yacc rule 46***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 47:  /***Yacc rule 47***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 48:  /***Yacc rule 48***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 49:  /***Yacc rule 49***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 50:  /***Yacc rule 50***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 51:  /***Yacc rule 51***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 52:  /***Yacc rule 52***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 53:  /***Yacc rule 53***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 54:  /***Yacc rule 54***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 55:  /***Yacc rule 55***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 56:  /***Yacc rule 56***/
			switch(pass)	{
				case 0:
righttoleft = false;
					}

break;
case 57:  /***Yacc rule 57***/
			switch(pass)	{
				case 0:
righttoleft = false;
#if (__APPLE__ && __clang__ && defined (__apple_build_version__) && __clang_major__ > 11) || \
    (__linux__ && __GNUC__ > 6)
/* Apple Xcode 10 & 11 gcc (tested):
   warning: declaration does not declare anything
   GNU 4, 5 & 6 gcc (tested):
   error: expected primary-expression before '__attribute__'
 */
__attribute__((fallthrough));
#elif defined (S_SPLINT_S)
/*@fallthrough@*/
#elif defined (lint)
NOTE(FALLTHROUGH)
#endif
				case 1:
if (yyyCond(0) != pass) {
#line 349 "parser.y"
isVisibleForUse(
#line 3498 "oxout.y"
travNode->yyyAttrbs.yyyAttrb11.ids
#line 349 "parser.y"
,
#line 3502 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.name
#line 349 "parser.y"
,
#line 3506 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.lineNr
#line 349 "parser.y"
);
#line 3510 "oxout.y"
}
				break;
					}

break;
case 58:  /***Yacc rule 58***/
			switch(pass)	{
				case 0:
righttoleft = false;
#if (__APPLE__ && __clang__ && defined (__apple_build_version__) && __clang_major__ > 11) || \
    (__linux__ && __GNUC__ > 6)
/* Apple Xcode 10 & 11 gcc (tested):
   warning: declaration does not declare anything
   GNU 4, 5 & 6 gcc (tested):
   error: expected primary-expression before '__attribute__'
 */
__attribute__((fallthrough));
#elif defined (S_SPLINT_S)
/*@fallthrough@*/
#elif defined (lint)
NOTE(FALLTHROUGH)
#endif
				case 1:
if (yyyCond(0) != pass) {
#line 357 "parser.y"
isVisible(
#line 3537 "oxout.y"
travNode->yyyAttrbs.yyyAttrb11.ids
#line 357 "parser.y"
,
#line 3541 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.name
#line 357 "parser.y"
, KIND_SELECTOR,
#line 3545 "oxout.y"
travNode->cL[0]->yyyAttrbs.yyyAttrb1.lineNr
#line 357 "parser.y"
);
#line 3549 "oxout.y"
}
				break;
					}

break;
								} /* switch */
   if (pass!=0) goto popTravStack; else goto pushTravStack;
  } /* while */
 } /* for */
} /* yyyDoTraversals */

static void yyyExecuteRRsection (yyyGNT *rootNode)
  {
   long cycleSum = 0;
   long nNZrc = 0;

   if (!yyyYok) return;
   yyyCheckUnsolvedInstTrav (rootNode, &nNZrc, &cycleSum);
   if (nNZrc>0)
      {
       (void) fputs ("\n\n\n**********\n", stderr);
       (void) fputs ("cycle detected in completed parse tree", stderr);
       (void) fputs (" after decoration.\n", stderr);
#if CYCLE_VERBOSE
       (void) fprintf (stderr, "number of unsolved attribute instances == %ld.\n",
                               nNZrc
                      );
       (void) fprintf (stderr, "total number of remaining dependencies == %ld.\n",
                               cycleSum
                      );
       (void) fputs ("average number of remaining dependencies\n", stderr);
       (void) fprintf (stderr, "  per unsolved instance == %f.\n",
                               ((float) (cycleSum) / (float) (nNZrc))
                      );
#endif
       (void) fprintf (stderr, "searching parse tree for %ld unsolved instances:\n",
                               nNZrc
                      );
       yyyUnsolvedInstSearchTravAux (rootNode);
      }
  } /* yyyExecuteRRsection */



static yyyWAT yyyLRCIL[2] = {0,1,
};



static void yyyGenIntNode (long ProdNum, int RHSlength, int Nattrbs,
#if defined (S_SPLINT_S)
                           /*@unused@*/
#endif
                           __attribute__((unused))
                           int typeNum, yyyOxAttrbs *val_OxAttrbs, ...)
  {
#if defined (lint)
   NOTE(ARGUNUSED(typeNum))
#endif
   yyySIT **LHSsemEl = &val_OxAttrbs->semEl;

#if defined (__cplusplus)
   try {
      (*LHSsemEl) = new yyySIT;
   } catch (std::bad_alloc) {
      yyyfatal ("error in Ox/Yacc semantic stack space allocation\n");
   }
   try {
      (*LHSsemEl)->node = new yyyGNT;
   } catch (std::bad_alloc) {
      yyyfatal ("error in Ox Semantic Node space allocation\n");
   }
#else /* !defined (__cplusplus) */
   (*LHSsemEl) = (yyySIT *) malloc ((size_t) sizeof (yyySIT));
   if (*LHSsemEl==(yyySIT *) NULL)
      yyyfatal ("malloc error in Ox/Yacc semantic stack space allocation\n");
   (*LHSsemEl)->node = (yyyGNT *) malloc ((size_t) sizeof (yyyGNT));
   if ((*LHSsemEl)->node==(yyyGNT *) NULL)
      yyyfatal ("malloc error in Ox Semantic Node space allocation\n");
#endif /* !defined (__cplusplus) */
   (*LHSsemEl)->solvedSAlist = yyyLambdaSSAL;
   (*LHSsemEl)->node->parent.stackref = (*LHSsemEl);
   (*LHSsemEl)->node->parentIsStack = true;
   (*LHSsemEl)->node->cLlen  = RHSlength;
   if (RHSlength>0)
#if defined (__cplusplus)
      try {
         (*LHSsemEl)->node->cL = new yyyGNT * [RHSlength];
      } catch (std::bad_alloc) {
         yyyfatal ("error in Ox Child List space allocation\n");
      }
#else /* !defined (__cplusplus) */
     {(*LHSsemEl)->node->cL =
            (yyyGNT **) calloc ((size_t)RHSlength, (size_t)sizeof (yyyGNT *));
      if ((*LHSsemEl)->node->cL==(yyyGNT **) NULL)
         yyyfatal ("calloc error in Ox Child List space allocation\n");
     }
#endif /* !defined (__cplusplus) */
   else
      (*LHSsemEl)->node->cL = (yyyGNT **) NULL;
   (*LHSsemEl)->node->refCountListLen = Nattrbs;
   if (Nattrbs>0)
#if defined (__cplusplus)
      try {
         (*LHSsemEl)->node->refCountList = new yyyRCT [Nattrbs];
         for (int i = 0; i < Nattrbs; i++)
            (*LHSsemEl)->node->refCountList [i] = 0;
      } catch (std::bad_alloc) {
         yyyfatal ("error in Ox Reference Count List space allocation\n");
      }
#else /* !defined (__cplusplus) */
     {(*LHSsemEl)->node->refCountList =
            (yyyRCT *) calloc ((size_t) Nattrbs, (size_t) sizeof (yyyRCT));
      if ((*LHSsemEl)->node->refCountList==(yyyRCT *) NULL)
         yyyfatal ("calloc error in Ox Reference Count List space allocation\n");
     }
#endif /* !defined (__cplusplus) */
   else
      (*LHSsemEl)->node->refCountList = (yyyRCT *) NULL;
   (*LHSsemEl)->node->prodNum = (yyyPNT)ProdNum;
   if (RHSlength>0)
     {va_list ap;
      va_start (ap, val_OxAttrbs);
      for (yyyWST i = 1; i <= RHSlength; i++)
        {yyyOxAttrbs *RHSattrbs = va_arg (ap, yyyOxAttrbs *);
         if (RHSattrbs != (yyyOxAttrbs *) NULL)
           {yyySIT *RHSsemEl = RHSattrbs->semEl;
            yyyGNT *gnpDum = (*LHSsemEl)->node->cL[i-1] = RHSsemEl->node;
            gnpDum->whichSym = i;
            gnpDum->parent.noderef = (*LHSsemEl)->node;
            gnpDum->parentIsStack = false;
           }
        }
      va_end (ap);
     }
  }



static void yyyReclaimSemStkEls (int RHSlength, ...)
  {if (RHSlength>0)
     {va_list ap;
      va_start (ap, RHSlength);
      for (yyyWST i = 1; i <= RHSlength; i++)
        {yyyOxAttrbs *RHSattrbs = va_arg (ap, yyyOxAttrbs *);
         if (RHSattrbs != (yyyOxAttrbs *) NULL)
           {yyySIT *RHSsemEl = RHSattrbs->semEl;
            RHSsemEl->node = (yyyGNT *) NULL;
#if defined (__cplusplus)
            delete RHSsemEl;
#else
            free (RHSsemEl);
#endif
           }
        }
      va_end (ap);
     }
  }



static void yyyAdjustINRC (long ProdNum, int RHSlength, long startP, long stopP, yyyOxAttrbs *val_OxAttrbs, ...)
  {yyySIT *LHSsemEl = val_OxAttrbs->semEl;
   yyySSALC *SSALptr,*SSALptrHead,**cPtrPtr;
   yyyGNT *gnpDum;
   long nextP;

   nextP = startP;
   while (nextP < stopP)
     {if (yyyRCIL[nextP]==yyyR)
         {(LHSsemEl->node->refCountList)[yyyRCIL[nextP +1]] = yyyRCIL[nextP+2];
         }
      else
         {(((LHSsemEl->node->cL)[yyyRCIL[nextP]])->refCountList)[yyyRCIL[nextP +1]] = yyyRCIL[nextP+2];
         }
      nextP += 3;
     }
   if (RHSlength>0)
     {long *pL = yyyIIEL + yyyIIIEL[ProdNum];
      long iTemp;
      va_list ap;
      va_start (ap, val_OxAttrbs);
      for (yyyWST i = 1; i <= RHSlength; i++)
        {yyyOxAttrbs *RHSattrbs = va_arg (ap, yyyOxAttrbs *);
         if (RHSattrbs != (yyyOxAttrbs *) NULL)
           {yyySIT *RHSsemEl = RHSattrbs->semEl;
            pL++;
            SSALptrHead = SSALptr = *(cPtrPtr = &(RHSsemEl->solvedSAlist));
            if (SSALptr != yyyLambdaSSAL)
              {*cPtrPtr = yyyLambdaSSAL;
               do
                 {iTemp = (*pL+SSALptr->attrbNum);
                  yyySignalEnts (LHSsemEl->node,
                                 yyyIEL[iTemp],
                                 yyyIEL[iTemp +1]
                                );
                  SSALptr = *(cPtrPtr = &(SSALptr->next));
                 }
               while (SSALptr != yyyLambdaSSAL);
               *cPtrPtr = yyySSALCfreeList;
               yyySSALCfreeList = SSALptrHead;
              }
           }
        }
      va_end (ap);
     }
   nextP = startP + 2;
   while (nextP < stopP)
     {if (yyyRCIL[nextP]==0)
         {if (yyyRCIL[nextP-2]==yyyR)
             {yyySSALC **pL = &(LHSsemEl->solvedSAlist);
              yyySSALC *iTemp;
              if (yyySSALCfreeList==yyyLambdaSSAL)
#if defined (__cplusplus)
                 try {
                    iTemp = new yyySSALC;
                 } catch (std::bad_alloc) {
                    yyyfatal ("error in Ox Stack Solved List space allocation\n");
                 }
#else /* !defined (__cplusplus) */
                 {iTemp = (yyySSALC *) malloc ((size_t) sizeof (yyySSALC));
                  if (iTemp==yyyLambdaSSAL)
                     yyyfatal ("malloc error in Ox Stack Solved List space allocation\n");
                 }
#endif /* !defined (__cplusplus) */
              else
                 {iTemp = yyySSALCfreeList;
                  yyySSALCfreeList = yyySSALCfreeList->next;
                 }
              iTemp->next = *pL;
              iTemp->attrbNum = yyyRCIL[nextP-1];
              *pL = iTemp;
             }
          else
             {if ((gnpDum = (LHSsemEl->node->cL)[yyyRCIL[nextP-2]])->prodNum!=0)
                 {long iTemp = yyyIIEL[yyyIIIEL[gnpDum->prodNum]] + yyyRCIL[nextP-1];
                  yyySignalEnts (gnpDum,
                                 yyyIEL[iTemp],
                                 yyyIEL[iTemp +1]
                                );
                 }
             }
         }
      nextP += 3;
     }
  }



void yyyGenLeaf (int nAttrbs,
#if defined (S_SPLINT_S)
                /*@unused@*/
#endif
                __attribute__((unused))
                 int typeNum, long startP, long stopP, YYSTYPE *lval)
  {
#if defined (lint)
   NOTE(ARGUNUSED(typeNum))
#endif
   yyySIT **LHSsemEl = &((yyyOxAttrbs *)lval)->semEl;
#if defined (__cplusplus)
   try {
      (*LHSsemEl) = new yyySIT;
   } catch (std::bad_alloc) {
      yyyfatal ("error in Ox/Yacc semantic stack space allocation\n");
   }
   try {
      (*LHSsemEl)->node = new yyyGNT;
   } catch (std::bad_alloc) {
      yyyfatal ("error in Ox Semantic Node space allocation\n");
   }
#else /* !defined (__cplusplus) */
   (*LHSsemEl) = (yyySIT *) malloc ((size_t) sizeof (yyySIT));
   if ((*LHSsemEl)==(yyySIT *) NULL)
      yyyfatal ("malloc error in Ox/Yacc semantic stack space allocation\n");
   (*LHSsemEl)->node = (yyyGNT *) malloc ((size_t) sizeof (yyyGNT));
   if ((*LHSsemEl)->node==(yyyGNT *) NULL)
      yyyfatal ("malloc error in Ox Semantic Node space allocation\n");
#endif /* !defined (__cplusplus) */
   (*LHSsemEl)->solvedSAlist = yyyLambdaSSAL;
   (*LHSsemEl)->node->parent.stackref = (*LHSsemEl);
   (*LHSsemEl)->node->parentIsStack = true;
   (*LHSsemEl)->node->cLlen = 0;
   (*LHSsemEl)->node->cL = (yyyGNT **) NULL;
   (*LHSsemEl)->node->refCountListLen = nAttrbs;
   if (nAttrbs>0)
     {yyyRCT *rcPdum;
#if defined (__cplusplus)
      try {
         rcPdum = (*LHSsemEl)->node->refCountList = new yyyRCT [nAttrbs];
      } catch (std::bad_alloc) {
         yyyfatal ("error in Ox Reference Count List space allocation\n");
      }
#else /* !defined (__cplusplus) */
      rcPdum = (*LHSsemEl)->node->refCountList =
               (yyyRCT *) calloc ((size_t) nAttrbs, (size_t) sizeof (yyyRCT));
      if (rcPdum==(yyyRCT *) NULL)
         yyyfatal ("calloc error in Ox Reference Count List space allocation\n");
#endif /* !defined (__cplusplus) */
      while (startP < stopP) rcPdum[yyyLRCIL[startP++]] = 0;
     }
   else
      (*LHSsemEl)->node->refCountList = (yyyRCT *) NULL;
   (*LHSsemEl)->node->prodNum = 0;
   (*LHSsemEl)->node->whichSym = 0;
  }



void yyyabort (void) {yyyYok = false;}




#define yyyLastProdNum 58


static int yyyProdsInd[] = {
   0,
   0,   2,   3,   7,  11,  18,  19,  23,  25,  27,
  32,  34,  35,  39,  42,  52,  53,  57,  60,  61,
  65,  67,  69,  74,  78,  80,  83,  87,  88,  92,
  96, 101, 103, 105, 107, 110, 113, 116, 119, 123,
 127, 130, 132, 134, 137, 140, 143, 147, 150, 154,
 157, 161, 162, 166, 170, 172, 174, 176,
 182,
};


static int yyyProds[][2] = {
{  26,   4},{  44,   7},{  44,   7},{  44,   7},{  44,   7},
{  42,   6},{  17,   0},{  44,   7},{  44,   7},{  45,   7},
{  17,   0},{  42,   6},{  32,   2},{  13,   1},{  18,   0},
{   1,   0},{  35,   3},{  20,   0},{  35,   3},{  35,   3},
{  35,   3},{  19,   0},{  32,   2},{  32,   2},{   2,   0},
{  32,   2},{   1,   0},{  45,   7},{   3,   0},{  13,   1},
{  40,   5},{   4,   0},{  40,   5},{  46,   7},{  46,   7},
{  46,   7},{  46,   7},{  47,   7},{  17,   0},{  47,   7},
{  32,   2},{  13,   1},{  47,   7},{  32,   2},{  13,   1},
{  18,   0},{  52,   9},{  55,  10},{  20,   0},{  53,   9},
{  48,   8},{   4,   0},{  55,  10},{  55,  10},{  55,  10},
{  19,   0},{  52,   9},{  52,   9},{  32,   2},{  13,   1},
{  53,   9},{  53,   9},{  53,   9},{  54,   9},{  17,   0},
{  54,   9},{  48,   8},{  54,   9},{  49,   8},{  54,   9},
{  32,   2},{  13,   1},{  15,   0},{  56,  11},{  54,   9},
{  13,   1},{  15,   0},{  56,  11},{  54,   9},{  56,  11},
{  48,   8},{   5,   0},{  56,  11},{  49,   8},{   6,   0},
{  50,   8},{   4,   0},{  50,   8},{  50,   8},{  50,   8},
{  51,   8},{  17,   0},{  51,   8},{  16,   0},{  53,   9},
{  93,   0},{  51,   8},{  56,  11},{  16,   0},{  53,   9},
{  93,   0},{  93,   0},{   7,   0},{  93,   0},{   8,   0},
{  56,  11},{  58,  11},{  56,  11},{  94,   0},{  58,  11},
{  56,  11},{  58,  11},{  60,  11},{  56,  11},{  58,  11},
{  61,  11},{  56,  11},{  58,  11},{  62,  11},{  56,  11},
{  58,  11},{  25,   0},{  58,  11},{  56,  11},{  58,  11},
{  24,   0},{  58,  11},{  56,  11},{  11,   0},{  13,   1},
{  94,   0},{   9,   0},{  94,   0},{  21,   0},{  94,   0},
{  94,   0},{   9,   0},{  94,   0},{  94,   0},{  21,   0},
{  60,  11},{  22,   0},{  58,  11},{  60,  11},{  60,  11},
{  22,   0},{  58,  11},{  61,  11},{  23,   0},{  58,  11},
{  61,  11},{  61,  11},{  23,   0},{  58,  11},{  62,  11},
{  10,   0},{  58,  11},{  62,  11},{  62,  11},{  10,   0},
{  58,  11},{  57,  11},{  57,  11},{  57,  11},{  19,   0},
{  56,  11},{  58,  11},{  18,   0},{  56,  11},{  20,   0},
{  58,  11},{  14,   0},{  58,  11},{  12,   0},{  58,  11},
{  13,   1},{  58,  11},{  13,   1},{  18,   0},{  56,  11},
{  57,  11},{  20,   0},
};


static int yyySortsInd[] = {
  0,
  0,  2,  3,  5,  6,  8,  9, 11, 13, 16,
 20,
 22,
};


static int yyySorts[] = {
   28,   29,   31,   33,   34,   37,   38,   39,   41,   43,
   41,   43,   31,   43,   41,   31,   43,   41,   33,   34,
   27,   31,
};



static const char *const yyyStringTab[] = {
"NIO","OBJECT","INT","CLASS","END",
"RETURN","COND","CONTINUE","BREAK","NOT",
"OR","NEW","NULLTERM","ID","NUM",
"LEFTASSIGN","RIGHTASSIGN","';'","'('","','",
"')'","'-'","'+'","'*'","'>'",
"'#'","Start","ids","name","lineNr",
0,"type","Type","typeIn","typeOut",
"OptType",0,"names","namesIn","namesOut",
"MemberStart","out","Selector","in","Program",
"Class","OptMember","Member","Return","Conditions",
"OptGuarded","Guarded","Par","Stats","Stat",
"Pars","Expr","RepExpr","Term","NotMinus",
"PlusTerm","MulTerm","OrTerm",0,"__y",
"error",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"ContinueOrBreak","Negations",
0,0,0,0,0,
};



#define yyySizeofProd(num) (yyyProdsInd[(num) +1] - yyyProdsInd[(num)])

#define yyyGSoccurStr(prodNum, symPos) \
   (yyyStringTab[yyyProds[yyyProdsInd[prodNum] + (symPos)][0]])

#define yyySizeofSort(num) (yyySortsInd[(num) +1] - yyySortsInd[(num)])

#define yyySortOf(prodNum, symPos) \
  (yyyProds[yyyProdsInd[(prodNum)] + (symPos)][1])

#define yyyAttrbStr(prodNum, symPos, attrbNum)                     \
  (yyyStringTab[yyySorts[yyySortsInd[yyySortOf(prodNum, symPos)] + \
                         (attrbNum)                                \
                        ]                                          \
               ]                                                   \
  )



static void yyyShowProd (int i)
  {int nSyms;

   nSyms = yyySizeofProd(i);
   for (int j = 0; j < nSyms; j++)
     {
      (void) fprintf (stderr, "%s", yyyGSoccurStr(i, j));
      if (j==0) (void) fputs (" : ", stderr); else (void) putc (' ', stderr);
     }
   (void) fputs (";\n", stderr);
  }



static void yyyCheckNodeInstancesSolved (yyyGNT *np)
  {int mysort, sortSize, prodNum, symPos;
   int nUnsolvedInsts = 0;
   bool inTerminalNode;

   if (np->prodNum!=0)
     {inTerminalNode = false;
      prodNum = np->prodNum;
      symPos = 0;
     }
   else
     {inTerminalNode = true;
      prodNum = np->parent.noderef->prodNum;
      symPos = np->whichSym;
     }
   mysort = yyySortOf(prodNum, symPos);
   sortSize = yyySizeofSort(mysort);
   for (int i = 0; i < sortSize; i++)
     if ((np->refCountList)[i]>0) nUnsolvedInsts += 1;
   if (nUnsolvedInsts>0)
     {(void) fprintf (stderr, "\nFound node that has %d unsolved attribute instance(s).\n",
                              nUnsolvedInsts
                     );
      (void) fprintf (stderr, "Node is labeled \"%s\".\n",
                              yyyGSoccurStr(prodNum, symPos));
      if (inTerminalNode)
        {(void) fputs ("Node is terminal.  Its parent production is:\n  ", stderr);
         yyyShowProd (prodNum);
        }
      else
        {(void) fputs ("Node is nonterminal.  ", stderr);
         if (!(np->parentIsStack))
           {(void) fprintf (stderr, "Node is %huth child in its parent production:\n  ",
                                    np->whichSym
                           );
            yyyShowProd (np->parent.noderef->prodNum);
           }
         (void) fputs ("Node is on left hand side of this production:\n  ", stderr);
         yyyShowProd (np->prodNum);
        }
      (void) fputs ("The following instances are unsolved:\n", stderr);
      for (int i = 0; i < sortSize; i++)
        if ((np->refCountList)[i]>0)
          (void) fprintf (stderr, "     %-16s still has %1hu dependencies.\n",
                                  yyyAttrbStr(prodNum, symPos, i),
                                  (np->refCountList)[i]
                         );
     }
  }



static void yyyCheckUnsolvedInstTrav (yyyGNT *pNode, long *nNZrc, long *cycleSum)
  {yyyGNT **cLpdum;
   yyyRCT *rcp;
   int i;

   /* visit the refCountList of each node in the tree, and sum the non-zero refCounts */
   rcp = pNode->refCountList;
   i = pNode->refCountListLen;
   while ((i--)>0)
      if ((*rcp++)>0) {*cycleSum += *(rcp -1); (*nNZrc)++;}
   cLpdum = pNode->cL;
   i = pNode->cLlen;
   while ((i--)>0)
     {
      yyyCheckUnsolvedInstTrav (*cLpdum, nNZrc, cycleSum);
      cLpdum++;
     }
  }



static void yyyUnsolvedInstSearchTravAux (yyyGNT *pNode)
  {yyyGNT **cLpdum;
   int i;

   yyyCheckNodeInstancesSolved (pNode);
   cLpdum = pNode->cL;
   i = pNode->cLlen;
   while ((i--)>0)
     {
      yyyUnsolvedInstSearchTravAux (*cLpdum);
      cLpdum++;
     }
  }



