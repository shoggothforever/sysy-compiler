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
#line 2 "sysy.y"

    #include<cstdio>
    #include <cstdlib>
    #include <cstring>
    #include<ctype.h>
    #include<iostream>
    #include<vector>
    #include<deque>
    #include<string>
    #include "astTree.h"
    using namespace std;
    #define YYDEBUG 1
    int yylex();
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;
    #define ASTREE tree
    int yyerror(astTree* tree, const char*msg){
        // tree->print();
        // fprintf(stderr, "Error type B at Line %d, %s ,cause: %s\n", yylineno, msg,rc_string(tree->rc).c_str());
        return 1;
    }
    /* Pass the argument to yyparse through to yylex. */
    #define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
    #define COUT(name) {cout<<"parse grammar "<<(#name)<<endl;};





#line 103 "sysy.tab.cpp"

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

#include "sysy.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* "="  */
  YYSYMBOL_LT = 4,                         /* "<"  */
  YYSYMBOL_LE = 5,                         /* "<="  */
  YYSYMBOL_GT = 6,                         /* ">"  */
  YYSYMBOL_GE = 7,                         /* ">="  */
  YYSYMBOL_EQ = 8,                         /* "=="  */
  YYSYMBOL_NE = 9,                         /* "!="  */
  YYSYMBOL_ADD = 10,                       /* "+"  */
  YYSYMBOL_SUB = 11,                       /* "-"  */
  YYSYMBOL_MUL = 12,                       /* "*"  */
  YYSYMBOL_DIV = 13,                       /* "/"  */
  YYSYMBOL_MOD = 14,                       /* "%"  */
  YYSYMBOL_NOT = 15,                       /* "!"  */
  YYSYMBOL_SEMI = 16,                      /* ";"  */
  YYSYMBOL_COLON = 17,                     /* ":"  */
  YYSYMBOL_COMMA = 18,                     /* ","  */
  YYSYMBOL_OB = 19,                        /* "{"  */
  YYSYMBOL_CB = 20,                        /* "}"  */
  YYSYMBOL_LB = 21,                        /* "["  */
  YYSYMBOL_RB = 22,                        /* "]"  */
  YYSYMBOL_L = 23,                         /* "("  */
  YYSYMBOL_R = 24,                         /* ")"  */
  YYSYMBOL_CONST = 25,                     /* CONST  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_AND = 33,                       /* "&&"  */
  YYSYMBOL_OR = 34,                        /* "||"  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_FLOAT = 36,                     /* FLOAT  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_ILLEGAL_HEX_CONST = 38,         /* ILLEGAL_HEX_CONST  */
  YYSYMBOL_ILLEGAL_OCTAL_CONST = 39,       /* ILLEGAL_OCTAL_CONST  */
  YYSYMBOL_HEX_CONST = 40,                 /* HEX_CONST  */
  YYSYMBOL_OCTAL_CONST = 41,               /* OCTAL_CONST  */
  YYSYMBOL_INTNUM = 42,                    /* INTNUM  */
  YYSYMBOL_FLOATNUM = 43,                  /* FLOATNUM  */
  YYSYMBOL_STR = 44,                       /* STR  */
  YYSYMBOL_Ident = 45,                     /* Ident  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_CompUnit = 47,                  /* CompUnit  */
  YYSYMBOL_Decl = 48,                      /* Decl  */
  YYSYMBOL_ConstDecl = 49,                 /* ConstDecl  */
  YYSYMBOL_BType = 50,                     /* BType  */
  YYSYMBOL_ConstDef = 51,                  /* ConstDef  */
  YYSYMBOL_ConstExpGroup = 52,             /* ConstExpGroup  */
  YYSYMBOL_ConstInitVal = 53,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValGroup = 54,         /* ConstInitValGroup  */
  YYSYMBOL_VarDecl = 55,                   /* VarDecl  */
  YYSYMBOL_VarDefGroup = 56,               /* VarDefGroup  */
  YYSYMBOL_VarDef = 57,                    /* VarDef  */
  YYSYMBOL_ArrayDef = 58,                  /* ArrayDef  */
  YYSYMBOL_InitVal = 59,                   /* InitVal  */
  YYSYMBOL_InitValGroup = 60,              /* InitValGroup  */
  YYSYMBOL_FuncDef = 61,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 62,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 63,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArray = 64,           /* FuncFParamArray  */
  YYSYMBOL_Block = 65,                     /* Block  */
  YYSYMBOL_BlockGroup = 66,                /* BlockGroup  */
  YYSYMBOL_BlockItem = 67,                 /* BlockItem  */
  YYSYMBOL_Stmt = 68,                      /* Stmt  */
  YYSYMBOL_Exp = 69,                       /* Exp  */
  YYSYMBOL_Cond = 70,                      /* Cond  */
  YYSYMBOL_LVal = 71,                      /* LVal  */
  YYSYMBOL_ArrayList = 72,                 /* ArrayList  */
  YYSYMBOL_Number = 73,                    /* Number  */
  YYSYMBOL_PrimaryExp = 74,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 75,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 76,                   /* UnaryOp  */
  YYSYMBOL_FuncParamsGroup = 77,           /* FuncParamsGroup  */
  YYSYMBOL_MulExp = 78,                    /* MulExp  */
  YYSYMBOL_AddExp = 79,                    /* AddExp  */
  YYSYMBOL_RelExp = 80,                    /* RelExp  */
  YYSYMBOL_EqExp = 81,                     /* EqExp  */
  YYSYMBOL_LAndExp = 82,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 83,                    /* LOrExp  */
  YYSYMBOL_StrExp = 84,                    /* StrExp  */
  YYSYMBOL_ConstExp = 85                   /* ConstExp  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   142,   148,   154,   160,   161,   162,   163,
     167,   168,   169,   171,   178,   186,   187,   189,   190,   191,
     192,   194,   197,   201,   208,   210,   211,   213,   214,   215,
     216,   219,   220,   221,   226,   227,   228,   230,   231,   234,
     243,   254,   255,   263,   264,   265,   266,   269,   270,   273,
     279,   288,   289,   292,   293,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   317,   318,   321,   324,   325,   328,
     329,   332,   336,   341,   378,   386,   387,   388,   391,   392,
     393,   394,   397,   398,   399,   401,   402,   405,   406,   407,
     408,   411,   412,   413,   416,   417,   418,   419,   420,   423,
     424,   425,   428,   429,   432,   433,   436,   439,   440
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
  "\"end of file\"", "error", "\"invalid token\"", "\"=\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"==\"", "\"!=\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\"!\"", "\";\"", "\":\"", "\",\"", "\"{\"",
  "\"}\"", "\"[\"", "\"]\"", "\"(\"", "\")\"", "CONST", "IF", "ELSE",
  "WHILE", "FOR", "BREAK", "CONTINUE", "RETURN", "\"&&\"", "\"||\"", "INT",
  "FLOAT", "VOID", "ILLEGAL_HEX_CONST", "ILLEGAL_OCTAL_CONST", "HEX_CONST",
  "OCTAL_CONST", "INTNUM", "FLOATNUM", "STR", "Ident", "$accept",
  "CompUnit", "Decl", "ConstDecl", "BType", "ConstDef", "ConstExpGroup",
  "ConstInitVal", "ConstInitValGroup", "VarDecl", "VarDefGroup", "VarDef",
  "ArrayDef", "InitVal", "InitValGroup", "FuncDef", "FuncFParams",
  "FuncFParam", "FuncFParamArray", "Block", "BlockGroup", "BlockItem",
  "Stmt", "Exp", "Cond", "LVal", "ArrayList", "Number", "PrimaryExp",
  "UnaryExp", "UnaryOp", "FuncParamsGroup", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "StrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,    45,  -157,  -157,  -157,    29,  -157,    41,     2,  -157,
    -157,    31,  -157,  -157,  -157,    31,    10,    56,  -157,    13,
      89,  -157,   387,   340,    65,    16,  -157,  -157,    62,    93,
     401,    17,  -157,  -157,  -157,  -157,   351,   401,  -157,  -157,
    -157,  -157,  -157,    64,  -157,  -157,  -157,  -157,  -157,  -157,
     412,    97,    25,  -157,    92,    25,  -157,    98,   105,    83,
       3,  -157,   387,   401,    20,  -157,  -157,   304,  -157,  -157,
     108,    93,   401,  -157,  -157,    75,   109,   401,   376,   127,
    -157,   412,   412,   412,   412,   412,  -157,  -157,   190,  -157,
     129,    45,   105,  -157,   141,  -157,  -157,    78,  -157,  -157,
     143,   387,  -157,  -157,   146,  -157,  -157,     4,   401,  -157,
    -157,  -157,    97,    97,  -157,  -157,  -157,   128,   149,    44,
      67,   315,  -157,    62,   151,   229,  -157,  -157,    68,   166,
     153,  -157,  -157,  -157,    93,  -157,  -157,  -157,  -157,   401,
    -157,   158,   412,   412,  -157,  -157,  -157,  -157,  -157,  -157,
      74,  -157,  -157,  -157,  -157,  -157,   401,   152,  -157,  -157,
    -157,   160,    25,   138,   110,   159,   163,   161,  -157,  -157,
      76,   401,   177,   268,   412,   412,   412,   412,   412,   412,
     412,   412,   268,  -157,  -157,   180,   401,   172,    25,    25,
      25,    25,   138,   138,   110,   159,  -157,  -157,   181,   268,
    -157,  -157
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,    12,     0,     4,     6,     0,     7,
       2,     0,     1,     5,     3,     0,    27,     0,    25,     0,
       0,     9,     0,     0,     0,    29,    24,    23,     0,     0,
       0,     0,     8,    92,    93,    94,     0,     0,    81,    82,
      83,    84,   116,    77,    28,    34,    86,    87,    88,    97,
       0,   101,    74,    75,     0,   117,   118,     0,     0,    43,
       0,    41,     0,     0,    27,    26,    20,     0,    14,    17,
       0,     0,     0,    35,    37,     0,     0,     0,     0,    78,
      91,     0,     0,     0,     0,     0,    33,    31,     0,    39,
      44,     0,     0,    30,     0,    18,    21,     0,    15,    13,
       0,     0,    36,    85,     0,    89,    95,     0,     0,    98,
      99,   100,   102,   103,    58,    57,    49,     0,     0,     0,
       0,     0,    53,     0,     0,     0,    51,    54,     0,    86,
       0,    42,    40,    32,     0,    19,    16,    38,    79,     0,
      90,     0,     0,     0,    67,    66,    69,    68,    71,    70,
       0,    62,    50,    52,    60,    59,     0,    45,    22,    96,
      80,     0,   104,   109,   112,   114,    76,     0,    73,    72,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    55,     0,     0,    63,   105,   107,
     106,   108,   110,   111,   113,   115,    65,    47,     0,     0,
      48,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,    73,  -157,     0,   189,  -157,   -64,  -157,  -157,
    -157,   179,  -157,   -30,  -157,   203,  -157,   120,  -157,   -53,
    -157,    87,  -156,   -22,    71,   -76,  -157,  -157,  -157,   -20,
    -157,  -157,    42,   -21,   -32,    37,    38,  -157,   -19,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,   122,     7,     8,    20,    31,    68,    97,     9,
      17,    18,    25,    44,    75,    10,    60,    61,   172,   124,
     125,   126,   127,   128,   161,    46,    79,    47,    48,    49,
      50,   107,    51,    52,   163,   164,   165,   166,    53,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    11,    55,    96,    56,    89,    74,    99,    55,    55,
      56,    56,   129,    22,    45,    76,    29,   187,    57,    62,
      71,    91,   139,    22,    59,    70,   196,    92,   140,    12,
      80,    23,    93,    24,    30,    84,    85,    63,    72,   132,
      45,    23,    55,   201,    56,   144,    55,    16,    56,   129,
      55,    55,    56,    56,     1,   104,   106,    26,    94,    15,
     145,   109,   110,   111,     2,     3,     4,   100,   146,   154,
     158,   137,    27,     6,    28,   168,    19,   183,    13,    45,
       2,     3,     4,   147,   155,    77,   141,    78,   123,    58,
     169,    59,   184,   101,    66,   102,   134,   129,   135,   150,
       2,     3,     4,    33,    34,    32,   129,    64,    35,    81,
      82,    83,    67,    55,    86,    56,    37,   159,   178,   179,
      87,   162,   162,   129,    88,   123,   112,   113,    90,     1,
      98,    38,    39,   103,   170,    40,    41,    42,    43,     2,
       3,     4,   174,   175,   176,   177,   192,   193,   108,   185,
     130,   142,   151,   188,   189,   190,   191,   162,   162,   162,
     162,   -61,   -61,   133,   198,   136,   -61,   -61,   138,   156,
     -61,   -61,   143,   171,   -61,   157,   -61,   -61,   -61,   -61,
     160,   -61,   -61,   -61,   173,   182,   -61,   -61,   -61,   -61,
     -61,   114,   180,   -61,   -61,   -61,   -61,   181,   186,   199,
      33,    34,   197,   200,    21,    35,   115,    65,    14,    88,
     116,   131,   153,    37,   167,     1,   117,   194,   118,   195,
     119,   120,   121,     0,     0,     2,     3,     4,    38,    39,
     114,     0,    40,    41,    42,    43,     0,     0,     0,    33,
      34,     0,     0,     0,    35,   115,     0,     0,    88,   152,
       0,     0,    37,     0,     1,   117,     0,   118,     0,   119,
     120,   121,     0,     0,     2,     3,     4,    38,    39,   114,
       0,    40,    41,    42,    43,     0,     0,     0,    33,    34,
       0,     0,     0,    35,   115,     0,     0,    88,     0,     0,
       0,    37,     0,     0,   117,     0,   118,     0,   119,   120,
     121,     0,     0,     0,     0,    66,    38,    39,     0,     0,
      40,    41,    42,    43,    33,    34,   148,     0,     0,    35,
       0,     0,     0,    67,    95,    33,    34,    37,     0,     0,
      35,   149,     0,     0,     0,     0,     0,     0,    37,     0,
       0,    54,    38,    39,     0,     0,    40,    41,    42,    43,
      33,    34,     0,    38,    39,    35,     0,    40,    41,    42,
      43,    33,    34,    37,     0,     0,    35,     0,     0,     0,
      36,    73,     0,     0,    37,     0,     0,     0,    38,    39,
       0,     0,    40,    41,    42,    43,    33,    34,     0,    38,
      39,    35,     0,    40,    41,    42,    43,    33,    34,    37,
     105,     0,    35,     0,     0,     0,    36,     0,     0,     0,
      37,    33,    34,     0,    38,    39,    35,     0,    40,    41,
      42,    43,    33,    34,    37,    38,    39,    35,     0,    40,
      41,    42,    43,     0,     0,    37,     0,     0,     0,    38,
      39,     0,     0,    40,    41,    42,    43,     0,     0,     0,
      38,    39,     0,     0,    40,    41,     0,    43
};

static const yytype_int16 yycheck[] =
{
      22,     1,    23,    67,    23,    58,    36,    71,    29,    30,
      29,    30,    88,     3,    36,    37,     3,   173,    23,     3,
       3,    18,    18,     3,    24,    30,   182,    24,    24,     0,
      50,    21,    62,    23,    21,    10,    11,    21,    21,    92,
      62,    21,    63,   199,    63,     1,    67,    45,    67,   125,
      71,    72,    71,    72,    25,    77,    78,     1,    63,    18,
      16,    81,    82,    83,    35,    36,    37,    72,     1,     1,
     134,   101,    16,     0,    18,     1,    45,     1,     5,   101,
      35,    36,    37,    16,    16,    21,   108,    23,    88,    24,
      16,    91,    16,    18,     1,    20,    18,   173,    20,   121,
      35,    36,    37,    10,    11,    16,   182,    45,    15,    12,
      13,    14,    19,   134,    22,   134,    23,   139,     8,     9,
      22,   142,   143,   199,    19,   125,    84,    85,    45,    25,
      22,    38,    39,    24,   156,    42,    43,    44,    45,    35,
      36,    37,     4,     5,     6,     7,   178,   179,    21,   171,
      21,    23,     1,   174,   175,   176,   177,   178,   179,   180,
     181,    10,    11,    22,   186,    22,    15,    16,    22,     3,
      19,    20,    23,    21,    23,    22,    25,    26,    27,    28,
      22,    30,    31,    32,    24,    24,    35,    36,    37,    38,
      39,     1,    33,    42,    43,    44,    45,    34,    21,    27,
      10,    11,    22,    22,    15,    15,    16,    28,     5,    19,
      20,    91,   125,    23,   143,    25,    26,   180,    28,   181,
      30,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
       1,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    25,    26,    -1,    28,    -1,    30,
      31,    32,    -1,    -1,    35,    36,    37,    38,    39,     1,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    26,    -1,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,     1,    38,    39,    -1,    -1,
      42,    43,    44,    45,    10,    11,     1,    -1,    -1,    15,
      -1,    -1,    -1,    19,    20,    10,    11,    23,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,     1,    38,    39,    -1,    -1,    42,    43,    44,    45,
      10,    11,    -1,    38,    39,    15,    -1,    42,    43,    44,
      45,    10,    11,    23,    -1,    -1,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    -1,    -1,    38,    39,
      -1,    -1,    42,    43,    44,    45,    10,    11,    -1,    38,
      39,    15,    -1,    42,    43,    44,    45,    10,    11,    23,
      24,    -1,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      23,    10,    11,    -1,    38,    39,    15,    -1,    42,    43,
      44,    45,    10,    11,    23,    38,    39,    15,    -1,    42,
      43,    44,    45,    -1,    -1,    23,    -1,    -1,    -1,    38,
      39,    -1,    -1,    42,    43,    44,    45,    -1,    -1,    -1,
      38,    39,    -1,    -1,    42,    43,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    35,    36,    37,    47,    48,    49,    50,    55,
      61,    50,     0,    48,    61,    18,    45,    56,    57,    45,
      51,    51,     3,    21,    23,    58,     1,    16,    18,     3,
      21,    52,    16,    10,    11,    15,    19,    23,    38,    39,
      42,    43,    44,    45,    59,    69,    71,    73,    74,    75,
      76,    78,    79,    84,     1,    79,    84,    85,    24,    50,
      62,    63,     3,    21,    45,    57,     1,    19,    53,    85,
      85,     3,    21,    20,    59,    60,    69,    21,    23,    72,
      75,    12,    13,    14,    10,    11,    22,    22,    19,    65,
      45,    18,    24,    59,    85,    20,    53,    54,    22,    53,
      85,    18,    20,    24,    69,    24,    69,    77,    21,    75,
      75,    75,    78,    78,     1,    16,    20,    26,    28,    30,
      31,    32,    48,    50,    65,    66,    67,    68,    69,    71,
      21,    63,    65,    22,    18,    20,    22,    59,    22,    18,
      24,    69,    23,    23,     1,    16,     1,    16,     1,    16,
      69,     1,    20,    67,     1,    16,     3,    22,    53,    69,
      22,    70,    79,    80,    81,    82,    83,    70,     1,    16,
      69,    21,    64,    24,     4,     5,     6,     7,     8,     9,
      33,    34,    24,     1,    16,    69,    21,    68,    79,    79,
      79,    79,    80,    80,    81,    82,    68,    22,    69,    27,
      22,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    81,    82,    82,    83,    83,    84,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     4,     3,
       1,     1,     1,     4,     3,     3,     4,     1,     2,     3,
       1,     1,     3,     3,     3,     1,     3,     1,     3,     2,
       4,     3,     4,     3,     1,     2,     3,     1,     3,     5,
       6,     1,     3,     1,     2,     4,     5,     3,     4,     2,
       3,     1,     2,     1,     1,     4,     4,     1,     1,     2,
       2,     1,     2,     5,     7,     5,     2,     2,     2,     2,
       2,     2,     3,     3,     1,     1,     1,     1,     2,     3,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       4,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     1
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
        yyerror (tree, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, tree); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, astTree* tree)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (tree);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, astTree* tree)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, tree);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, astTree* tree)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), tree);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, tree); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, astTree* tree)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (tree);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (astTree* tree)
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: FuncDef  */
#line 135 "sysy.y"
                  {
                // COUT(CompUnit);
                (yyval.node)=NewAst("CompUnit",yylineno,1,(yyvsp[0].node));
                (yyval.node)->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=(yyval.node);
                }
#line 1491 "sysy.tab.cpp"
    break;

  case 3: /* CompUnit: CompUnit FuncDef  */
#line 142 "sysy.y"
                           {
                (yyval.node)=NewAst("CompUnit",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));
                (yyval.node)->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=(yyval.node);
        }
#line 1502 "sysy.tab.cpp"
    break;

  case 4: /* CompUnit: Decl  */
#line 148 "sysy.y"
               {
                (yyval.node)=NewAst("CompUnit",yylineno,1,(yyvsp[0].node));
                (yyval.node)->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=(yyval.node);
                }
#line 1513 "sysy.tab.cpp"
    break;

  case 5: /* CompUnit: CompUnit Decl  */
#line 154 "sysy.y"
                        {
                (yyval.node)=NewAst("CompUnit",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));
                (yyval.node)->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=(yyval.node);
        }
#line 1524 "sysy.tab.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 160 "sysy.y"
                {(yyval.node)=NewAst("Decl",yylineno,1,(yyvsp[0].node));}
#line 1530 "sysy.tab.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 161 "sysy.y"
              {(yyval.node)=NewAst("Decl",yylineno,1,(yyvsp[0].node));}
#line 1536 "sysy.tab.cpp"
    break;

  case 8: /* ConstDecl: CONST BType ConstDef ";"  */
#line 162 "sysy.y"
                                     {(yyval.node)=NewAst("Decl",yylineno,3,(yyvsp[-3].String),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1542 "sysy.tab.cpp"
    break;

  case 9: /* ConstDecl: ConstDecl "," ConstDef  */
#line 163 "sysy.y"
                                   {(yyval.node)=NewAst("Decl",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1548 "sysy.tab.cpp"
    break;

  case 10: /* BType: INT  */
#line 167 "sysy.y"
        {(yyval.node)=NewAst("BType","INT",yylineno,0);}
#line 1554 "sysy.tab.cpp"
    break;

  case 11: /* BType: FLOAT  */
#line 168 "sysy.y"
             {(yyval.node)=NewAst("BType","FLOAT",yylineno,0);}
#line 1560 "sysy.tab.cpp"
    break;

  case 12: /* BType: VOID  */
#line 169 "sysy.y"
            {(yyval.node)=NewAst("BType","VOID",yylineno,0);}
#line 1566 "sysy.tab.cpp"
    break;

  case 13: /* ConstDef: Ident ConstExpGroup "=" ConstInitVal  */
#line 171 "sysy.y"
                                                  {
        (yyval.node)=NewAst("ConstDef",yylineno,4,
        (yyvsp[-3].node),
        (yyvsp[-2].node),
        (yyvsp[-1].String),
        (yyvsp[0].node));
        }
#line 1578 "sysy.tab.cpp"
    break;

  case 14: /* ConstDef: Ident "=" ConstInitVal  */
#line 178 "sysy.y"
                                   {
        (yyval.node)=NewAst("ConstDef",yylineno,3,
        (yyvsp[-2].node),
        (yyvsp[-1].String),
        (yyvsp[0].node));
        }
#line 1589 "sysy.tab.cpp"
    break;

  case 15: /* ConstExpGroup: "[" ConstExp "]"  */
#line 186 "sysy.y"
                                {(yyval.node)=NewAst("ConstExpGroup",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1595 "sysy.tab.cpp"
    break;

  case 16: /* ConstExpGroup: ConstExpGroup "[" ConstExp "]"  */
#line 187 "sysy.y"
                                             {(yyval.node)=NewAst("ConstExpGroup",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1601 "sysy.tab.cpp"
    break;

  case 17: /* ConstInitVal: ConstExp  */
#line 189 "sysy.y"
                        {(yyval.node)=NewAst("ConstInitVal",yylineno,1,(yyvsp[0].node));}
#line 1607 "sysy.tab.cpp"
    break;

  case 18: /* ConstInitVal: "{" "}"  */
#line 190 "sysy.y"
                  {(yyval.node)=NewAst("ConstInitVal",yylineno,2,(yyvsp[-1].String),(yyvsp[0].String));}
#line 1613 "sysy.tab.cpp"
    break;

  case 19: /* ConstInitVal: "{" ConstInitValGroup "}"  */
#line 191 "sysy.y"
                                     {(yyval.node)=NewAst("ConstInitVal",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1619 "sysy.tab.cpp"
    break;

  case 20: /* ConstInitVal: error  */
#line 192 "sysy.y"
                {}
#line 1625 "sysy.tab.cpp"
    break;

  case 21: /* ConstInitValGroup: ConstInitVal  */
#line 194 "sysy.y"
                                 {
        // COUT(ConstInitValGroup);
}
#line 1633 "sysy.tab.cpp"
    break;

  case 22: /* ConstInitValGroup: ConstInitValGroup "," ConstInitVal  */
#line 197 "sysy.y"
                                             {
                // COUT(ConstInitValGroup);
        }
#line 1641 "sysy.tab.cpp"
    break;

  case 23: /* VarDecl: BType VarDefGroup ";"  */
#line 201 "sysy.y"
                                {

        (yyval.node)=NewAst("VarDecl",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].String));


        }
#line 1652 "sysy.tab.cpp"
    break;

  case 24: /* VarDecl: BType VarDefGroup error  */
#line 208 "sysy.y"
                                 {yyclearin; fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1658 "sysy.tab.cpp"
    break;

  case 25: /* VarDefGroup: VarDef  */
#line 210 "sysy.y"
                    {(yyval.node)=NewAst("VarDefGroup",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 1664 "sysy.tab.cpp"
    break;

  case 26: /* VarDefGroup: VarDefGroup "," VarDef  */
#line 211 "sysy.y"
                                     {(yyval.node)=NewAst("VarDefGroup",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1670 "sysy.tab.cpp"
    break;

  case 27: /* VarDef: Ident  */
#line 213 "sysy.y"
               {(yyval.node)=NewAst("VarDef",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 1676 "sysy.tab.cpp"
    break;

  case 28: /* VarDef: Ident "=" InitVal  */
#line 214 "sysy.y"
                               {(yyval.node)=NewAst("VarDef",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1682 "sysy.tab.cpp"
    break;

  case 29: /* VarDef: Ident ArrayDef  */
#line 215 "sysy.y"
                         {(yyval.node)=NewAst("VarDef",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));}
#line 1688 "sysy.tab.cpp"
    break;

  case 30: /* VarDef: Ident ArrayDef "=" InitVal  */
#line 216 "sysy.y"
                                        {(yyval.node)=NewAst("VarDef",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1694 "sysy.tab.cpp"
    break;

  case 31: /* ArrayDef: "[" ConstExp "]"  */
#line 219 "sysy.y"
                         {(yyval.node)=NewAst("ArrayDef",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1700 "sysy.tab.cpp"
    break;

  case 32: /* ArrayDef: ArrayDef "[" ConstExp "]"  */
#line 220 "sysy.y"
                                    {(yyval.node)=NewAst("ArrayDef",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1706 "sysy.tab.cpp"
    break;

  case 33: /* ArrayDef: "[" error "]"  */
#line 221 "sysy.y"
                       {
                fprintf(stderr,"Error type B [%s] at line [%d] : need arguments in []\n",rc_string(RC::InvalidArrayDef).c_str(),yylineno);
                return 1;
        }
#line 1715 "sysy.tab.cpp"
    break;

  case 34: /* InitVal: Exp  */
#line 226 "sysy.y"
              {(yyval.node)=NewAst("InitVal",yylineno,1,(yyvsp[0].node));}
#line 1721 "sysy.tab.cpp"
    break;

  case 35: /* InitVal: "{" "}"  */
#line 227 "sysy.y"
                   {(yyval.node)=NewAst("InitVal",yylineno,2,(yyvsp[-1].String),(yyvsp[0].String));}
#line 1727 "sysy.tab.cpp"
    break;

  case 36: /* InitVal: "{" InitValGroup "}"  */
#line 228 "sysy.y"
                               {(yyval.node)=NewAst("InitVal",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1733 "sysy.tab.cpp"
    break;

  case 37: /* InitValGroup: InitVal  */
#line 230 "sysy.y"
                      {(yyval.node)=NewAst("InitValGroup",yylineno,1,(yyvsp[0].node));}
#line 1739 "sysy.tab.cpp"
    break;

  case 38: /* InitValGroup: InitValGroup "," InitVal  */
#line 231 "sysy.y"
                                   {(yyval.node)=NewAst("InitValGroup",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1745 "sysy.tab.cpp"
    break;

  case 39: /* FuncDef: BType Ident "(" ")" Block  */
#line 234 "sysy.y"
                                  {
        (yyval.node)=NewAst("FuncDef",(yyvsp[-3].node)->val,yylineno,5,
                (yyvsp[-4].node),
                (yyvsp[-3].node),
                (yyvsp[-2].String),
                (yyvsp[-1].String),
                (yyvsp[0].node));

        }
#line 1759 "sysy.tab.cpp"
    break;

  case 40: /* FuncDef: BType Ident "(" FuncFParams ")" Block  */
#line 243 "sysy.y"
                                               {
                (yyval.node)=NewAst("FuncDef",(yyvsp[-4].node)->val,yylineno,6,
                (yyvsp[-5].node),
                (yyvsp[-4].node),
                (yyvsp[-3].String),
                (yyvsp[-2].node),
                (yyvsp[-1].String),
                (yyvsp[0].node));

        }
#line 1774 "sysy.tab.cpp"
    break;

  case 41: /* FuncFParams: FuncFParam  */
#line 254 "sysy.y"
                         {(yyval.node)=NewAst("FuncFparams",yylineno,1,(yyvsp[0].node));}
#line 1780 "sysy.tab.cpp"
    break;

  case 42: /* FuncFParams: FuncFParams "," FuncFParam  */
#line 255 "sysy.y"
                                         {
                (yyval.node)=NewAst("FuncFparams",yylineno,3,
                (yyvsp[-2].node),
                (yyvsp[-1].String),
                (yyvsp[0].node));
        }
#line 1791 "sysy.tab.cpp"
    break;

  case 43: /* FuncFParam: BType  */
#line 263 "sysy.y"
               {(yyval.node)=NewAst("FuncFParam",yylineno,1,(yyvsp[0].node));}
#line 1797 "sysy.tab.cpp"
    break;

  case 44: /* FuncFParam: BType Ident  */
#line 264 "sysy.y"
                      {(yyval.node)=NewAst("FuncFParam",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));}
#line 1803 "sysy.tab.cpp"
    break;

  case 45: /* FuncFParam: BType Ident "[" "]"  */
#line 265 "sysy.y"
                              {(yyval.node)=NewAst("FuncFParam",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].String));}
#line 1809 "sysy.tab.cpp"
    break;

  case 46: /* FuncFParam: BType Ident "[" "]" FuncFParamArray  */
#line 266 "sysy.y"
                                              {(yyval.node)=NewAst("FuncFParam",yylineno,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1815 "sysy.tab.cpp"
    break;

  case 47: /* FuncFParamArray: "[" Exp "]"  */
#line 269 "sysy.y"
                            {(yyval.node)=NewAst("FuncFParamArray",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1821 "sysy.tab.cpp"
    break;

  case 48: /* FuncFParamArray: FuncFParamArray "[" Exp "]"  */
#line 270 "sysy.y"
                                              {(yyval.node)=NewAst("FuncFParamArray",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1827 "sysy.tab.cpp"
    break;

  case 49: /* Block: "{" "}"  */
#line 273 "sysy.y"
            {
        (yyval.node)=NewAst("BLOCK",yylineno,2,
        (yyvsp[-1].String),
        (yyvsp[0].String));

        }
#line 1838 "sysy.tab.cpp"
    break;

  case 50: /* Block: "{" BlockGroup "}"  */
#line 279 "sysy.y"
                         {
        (yyval.node)=NewAst("BLOCK",yylineno,3,
        (yyvsp[-2].String),
        (yyvsp[-1].node),
        (yyvsp[0].String));

        }
#line 1850 "sysy.tab.cpp"
    break;

  case 51: /* BlockGroup: BlockItem  */
#line 288 "sysy.y"
                  {(yyval.node)=NewAst("BlockGroup",yylineno,1,(yyvsp[0].node));}
#line 1856 "sysy.tab.cpp"
    break;

  case 52: /* BlockGroup: BlockGroup BlockItem  */
#line 289 "sysy.y"
                              {(yyval.node)=NewAst("BlockGroup",yylineno,2,(yyvsp[-1].node), (yyvsp[0].node));}
#line 1862 "sysy.tab.cpp"
    break;

  case 53: /* BlockItem: Decl  */
#line 292 "sysy.y"
              {(yyval.node)=NewAst("BlockItem",yylineno,1,(yyvsp[0].node));}
#line 1868 "sysy.tab.cpp"
    break;

  case 54: /* BlockItem: Stmt  */
#line 293 "sysy.y"
               {(yyval.node)=NewAst("BlockItem",yylineno,1,(yyvsp[0].node));}
#line 1874 "sysy.tab.cpp"
    break;

  case 55: /* Stmt: LVal "=" Exp ";"  */
#line 296 "sysy.y"
                     {(yyval.node)=NewAst("Stmt",yylineno,3,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node));}
#line 1880 "sysy.tab.cpp"
    break;

  case 56: /* Stmt: LVal "=" Exp error  */
#line 297 "sysy.y"
                         { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1886 "sysy.tab.cpp"
    break;

  case 57: /* Stmt: ";"  */
#line 298 "sysy.y"
               {(yyval.node)=NewAst("Stmt",yylineno,1,(yyvsp[0].String));}
#line 1892 "sysy.tab.cpp"
    break;

  case 58: /* Stmt: error  */
#line 299 "sysy.y"
                { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1898 "sysy.tab.cpp"
    break;

  case 59: /* Stmt: Exp ";"  */
#line 300 "sysy.y"
                 {(yyval.node)=NewAst("Stmt",yylineno,2,(yyvsp[-1].node),(yyvsp[0].String));}
#line 1904 "sysy.tab.cpp"
    break;

  case 60: /* Stmt: Exp error  */
#line 301 "sysy.y"
                    { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1910 "sysy.tab.cpp"
    break;

  case 61: /* Stmt: Block  */
#line 302 "sysy.y"
               {(yyval.node)=NewAst("Stmt",yylineno,1,(yyvsp[0].node));}
#line 1916 "sysy.tab.cpp"
    break;

  case 62: /* Stmt: Block error  */
#line 303 "sysy.y"
                      { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1922 "sysy.tab.cpp"
    break;

  case 63: /* Stmt: IF "(" Cond ")" Stmt  */
#line 304 "sysy.y"
                               {(yyval.node)=NewAst("Stmt",yylineno,5,(yyvsp[-4].String),(yyvsp[-3].String),(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1928 "sysy.tab.cpp"
    break;

  case 64: /* Stmt: IF "(" Cond ")" Stmt ELSE Stmt  */
#line 305 "sysy.y"
                                         {(yyval.node)=NewAst("Stmt",yylineno,4,(yyvsp[-6].String),(yyvsp[-5].String),(yyvsp[-4].node),(yyvsp[-3].String));}
#line 1934 "sysy.tab.cpp"
    break;

  case 65: /* Stmt: WHILE "(" Cond ")" Stmt  */
#line 306 "sysy.y"
                                  {(yyval.node)=NewAst("Stmt",yylineno,5,(yyvsp[-4].String),(yyvsp[-3].String),(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 1940 "sysy.tab.cpp"
    break;

  case 66: /* Stmt: BREAK ";"  */
#line 307 "sysy.y"
                    {(yyval.node)=NewAst("Stmt",yylineno,2,(yyvsp[-1].String),(yyvsp[0].String));}
#line 1946 "sysy.tab.cpp"
    break;

  case 67: /* Stmt: BREAK error  */
#line 308 "sysy.y"
                      { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1952 "sysy.tab.cpp"
    break;

  case 68: /* Stmt: CONTINUE ";"  */
#line 309 "sysy.y"
                       {(yyval.node)=NewAst("Stmt",yylineno,2,(yyvsp[-1].String),(yyvsp[0].String));}
#line 1958 "sysy.tab.cpp"
    break;

  case 69: /* Stmt: CONTINUE error  */
#line 310 "sysy.y"
                         { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1964 "sysy.tab.cpp"
    break;

  case 70: /* Stmt: RETURN ";"  */
#line 311 "sysy.y"
                     {(yyval.node)=NewAst("Stmt",yylineno,2,(yyvsp[-1].String),(yyvsp[0].String));}
#line 1970 "sysy.tab.cpp"
    break;

  case 71: /* Stmt: RETURN error  */
#line 312 "sysy.y"
                       { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1976 "sysy.tab.cpp"
    break;

  case 72: /* Stmt: RETURN Exp ";"  */
#line 313 "sysy.y"
                         {(yyval.node)=NewAst("Stmt",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 1982 "sysy.tab.cpp"
    break;

  case 73: /* Stmt: RETURN Exp error  */
#line 314 "sysy.y"
                           { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
#line 1988 "sysy.tab.cpp"
    break;

  case 74: /* Exp: AddExp  */
#line 317 "sysy.y"
           {(yyval.node)=NewAst("Exp",yylineno,1,(yyvsp[0].node));}
#line 1994 "sysy.tab.cpp"
    break;

  case 75: /* Exp: StrExp  */
#line 318 "sysy.y"
            {(yyval.node)=NewAst("Exp",yylineno,1,(yyvsp[0].node));}
#line 2000 "sysy.tab.cpp"
    break;

  case 76: /* Cond: LOrExp  */
#line 321 "sysy.y"
           {(yyval.node)=NewAst("Cond",yylineno,1,(yyvsp[0].node));}
#line 2006 "sysy.tab.cpp"
    break;

  case 77: /* LVal: Ident  */
#line 324 "sysy.y"
          {(yyval.node)=NewAst("LVal",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2012 "sysy.tab.cpp"
    break;

  case 78: /* LVal: Ident ArrayList  */
#line 325 "sysy.y"
                      {(yyval.node)=NewAst("LVal",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));}
#line 2018 "sysy.tab.cpp"
    break;

  case 79: /* ArrayList: "[" Exp "]"  */
#line 328 "sysy.y"
                     {(yyval.node)=NewAst("ArrayList",yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 2024 "sysy.tab.cpp"
    break;

  case 80: /* ArrayList: ArrayList "[" Exp "]"  */
#line 329 "sysy.y"
                                 {(yyval.node)=NewAst("ArrayList",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 2030 "sysy.tab.cpp"
    break;

  case 81: /* Number: ILLEGAL_HEX_CONST  */
#line 332 "sysy.y"
                           {
                fprintf(stderr,"Error type A [%s] at line [%d] : Illegal hex number %s\n","Number",yylineno,yytext);
                return 1;
        }
#line 2039 "sysy.tab.cpp"
    break;

  case 82: /* Number: ILLEGAL_OCTAL_CONST  */
#line 336 "sysy.y"
                             {
                fprintf(stderr,"Error type A [%s] at line [%d] : Illegal octal number %s\n","Number" ,yylineno,yytext);
                return 1;
        }
#line 2048 "sysy.tab.cpp"
    break;

  case 83: /* Number: INTNUM  */
#line 341 "sysy.y"
                {
                // cout<<"GET INT: "<< yytext <<endl;
                string s = yytext;

                long long num=0;
                int n=s.size();
                if(s[0]=='0'){
                        if(s[1]=='x'||s[1]=='X'){
                                // cout<<"hex:"<<endl;
                                for(int i=2;i<n;i++){
                                        int code;
                                        if(s[i]>='a'&&s[i]<='f')code=s[i]-87;
                                        if(s[i]>='A'&&s[i]<='F')code=s[i]-65;
                                        else code=s[i]-48;
                                        num=num*16+code;
                                }
                        }else {
                                // printf("oct\n");
                                for(int i=1;i<n;i++){
                                        int code=s[i]-48;
                                        num=num*8+code;
                                }
                        }

                }
                else {
                        // printf("dec\n");
                        for(int i=0;i<n;i++){
                                int code=s[i]-48;
                                num=num*10+code;
                        }
                }
                // cout<<"get number value : "<<num<<endl;
                (yyval.node)=NewAst("NUMBER",s,yylineno,1,NewAst("INT",std::to_string(num),yylineno,0));
                (yyval.node)->intval=num;
        }
#line 2089 "sysy.tab.cpp"
    break;

  case 84: /* Number: FLOATNUM  */
#line 378 "sysy.y"
                  {
                (yyval.node)=NewAst("NUMBER",yylineno,1,NewAst("FLOAT",yylineno,0));
                (yyval.node)->val=yytext;
                (yyval.node)->floatval=atof(yytext);
       }
#line 2099 "sysy.tab.cpp"
    break;

  case 85: /* PrimaryExp: "(" Exp ")"  */
#line 386 "sysy.y"
                        {(yyval.node)=NewAst("PrimaryExp",(yyvsp[-1].node)->val,yylineno,3,(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 2105 "sysy.tab.cpp"
    break;

  case 86: /* PrimaryExp: LVal  */
#line 387 "sysy.y"
                         {(yyval.node)=NewAst("PrimaryExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2111 "sysy.tab.cpp"
    break;

  case 87: /* PrimaryExp: Number  */
#line 388 "sysy.y"
                        {(yyval.node)=NewAst("PrimaryExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2117 "sysy.tab.cpp"
    break;

  case 88: /* UnaryExp: PrimaryExp  */
#line 391 "sysy.y"
                   {(yyval.node)=NewAst("UnaryExp",yylineno,1,(yyvsp[0].node));}
#line 2123 "sysy.tab.cpp"
    break;

  case 89: /* UnaryExp: Ident "(" ")"  */
#line 392 "sysy.y"
                          {(yyval.node)=NewAst("UnaryExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].String));}
#line 2129 "sysy.tab.cpp"
    break;

  case 90: /* UnaryExp: Ident "(" FuncParamsGroup ")"  */
#line 393 "sysy.y"
                                          {(yyval.node)=NewAst("UnaryExp",yylineno,4,(yyvsp[-3].node),(yyvsp[-2].String),(yyvsp[-1].node),(yyvsp[0].String));}
#line 2135 "sysy.tab.cpp"
    break;

  case 91: /* UnaryExp: UnaryOp UnaryExp  */
#line 394 "sysy.y"
                            {(yyval.node)=NewAst("UnaryExp",yylineno,2,(yyvsp[-1].node),(yyvsp[0].node));}
#line 2141 "sysy.tab.cpp"
    break;

  case 92: /* UnaryOp: "+"  */
#line 397 "sysy.y"
            {(yyval.node)=NewAst("UnaryOp",yylineno,1,(yyvsp[0].String));}
#line 2147 "sysy.tab.cpp"
    break;

  case 93: /* UnaryOp: "-"  */
#line 398 "sysy.y"
              {(yyval.node)=NewAst("UnaryOp",yylineno,1,(yyvsp[0].String));}
#line 2153 "sysy.tab.cpp"
    break;

  case 94: /* UnaryOp: "!"  */
#line 399 "sysy.y"
              {(yyval.node)=NewAst("UnaryOp",yylineno,1,(yyvsp[0].String));}
#line 2159 "sysy.tab.cpp"
    break;

  case 95: /* FuncParamsGroup: Exp  */
#line 401 "sysy.y"
                     {(yyval.node)=NewAst("FuncParamsGroup",yylineno,1,(yyvsp[0].node));}
#line 2165 "sysy.tab.cpp"
    break;

  case 96: /* FuncParamsGroup: FuncParamsGroup "," Exp  */
#line 402 "sysy.y"
                                  {(yyval.node)=NewAst("FuncParamsGroup",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2171 "sysy.tab.cpp"
    break;

  case 97: /* MulExp: UnaryExp  */
#line 405 "sysy.y"
                 {(yyval.node)=NewAst("MulExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2177 "sysy.tab.cpp"
    break;

  case 98: /* MulExp: MulExp "*" UnaryExp  */
#line 406 "sysy.y"
                             {(yyval.node)=NewAst("MulExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2183 "sysy.tab.cpp"
    break;

  case 99: /* MulExp: MulExp "/" UnaryExp  */
#line 407 "sysy.y"
                             {(yyval.node)=NewAst("MulExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2189 "sysy.tab.cpp"
    break;

  case 100: /* MulExp: MulExp "%" UnaryExp  */
#line 408 "sysy.y"
                             {(yyval.node)=NewAst("MulExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2195 "sysy.tab.cpp"
    break;

  case 101: /* AddExp: MulExp  */
#line 411 "sysy.y"
               {(yyval.node)=NewAst("AddExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2201 "sysy.tab.cpp"
    break;

  case 102: /* AddExp: AddExp "+" MulExp  */
#line 412 "sysy.y"
                           {(yyval.node)=NewAst("AddExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2207 "sysy.tab.cpp"
    break;

  case 103: /* AddExp: AddExp "-" MulExp  */
#line 413 "sysy.y"
                           {(yyval.node)=NewAst("AddExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2213 "sysy.tab.cpp"
    break;

  case 104: /* RelExp: AddExp  */
#line 416 "sysy.y"
               {(yyval.node)=NewAst("RelExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2219 "sysy.tab.cpp"
    break;

  case 105: /* RelExp: RelExp "<" AddExp  */
#line 417 "sysy.y"
                         {(yyval.node)=NewAst("RelExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2225 "sysy.tab.cpp"
    break;

  case 106: /* RelExp: RelExp ">" AddExp  */
#line 418 "sysy.y"
                         {(yyval.node)=NewAst("RelExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2231 "sysy.tab.cpp"
    break;

  case 107: /* RelExp: RelExp "<=" AddExp  */
#line 419 "sysy.y"
                         {(yyval.node)=NewAst("RelExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2237 "sysy.tab.cpp"
    break;

  case 108: /* RelExp: RelExp ">=" AddExp  */
#line 420 "sysy.y"
                         {(yyval.node)=NewAst("RelExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2243 "sysy.tab.cpp"
    break;

  case 109: /* EqExp: RelExp  */
#line 423 "sysy.y"
               {(yyval.node)=NewAst("EqExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2249 "sysy.tab.cpp"
    break;

  case 110: /* EqExp: EqExp "==" RelExp  */
#line 424 "sysy.y"
                          {(yyval.node)=NewAst("EqExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2255 "sysy.tab.cpp"
    break;

  case 111: /* EqExp: EqExp "!=" RelExp  */
#line 425 "sysy.y"
                           {(yyval.node)=NewAst("EqExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2261 "sysy.tab.cpp"
    break;

  case 112: /* LAndExp: EqExp  */
#line 428 "sysy.y"
              {(yyval.node)=NewAst("LAndExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2267 "sysy.tab.cpp"
    break;

  case 113: /* LAndExp: LAndExp "&&" EqExp  */
#line 429 "sysy.y"
                            {(yyval.node)=NewAst("LAndExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2273 "sysy.tab.cpp"
    break;

  case 114: /* LOrExp: LAndExp  */
#line 432 "sysy.y"
                {(yyval.node)=NewAst("LOrExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2279 "sysy.tab.cpp"
    break;

  case 115: /* LOrExp: LOrExp "||" LAndExp  */
#line 433 "sysy.y"
                            {(yyval.node)=NewAst("LOrExp",yylineno,3,(yyvsp[-2].node),(yyvsp[-1].String),(yyvsp[0].node));}
#line 2285 "sysy.tab.cpp"
    break;

  case 116: /* StrExp: STR  */
#line 436 "sysy.y"
       {(yyval.node)=NewAst("StrExp",(yyvsp[0].node)->val,yylineno,1,(yyvsp[0].node));}
#line 2291 "sysy.tab.cpp"
    break;

  case 117: /* ConstExp: AddExp  */
#line 439 "sysy.y"
               {(yyval.node)=NewAst("ConstExp",yylineno,1,(yyvsp[0].node));}
#line 2297 "sysy.tab.cpp"
    break;

  case 118: /* ConstExp: StrExp  */
#line 440 "sysy.y"
                {(yyval.node)=NewAst("ConstExp",yylineno,1,(yyvsp[0].node));}
#line 2303 "sysy.tab.cpp"
    break;


#line 2307 "sysy.tab.cpp"

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
  *++yylsp = yyloc;

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
      yyerror (tree, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, tree);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, tree);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (tree, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, tree);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, tree);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 448 "sysy.y"

