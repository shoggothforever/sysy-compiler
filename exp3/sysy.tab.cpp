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
#line 3 "sysy.y"

    #include<cstdio>
    #include <cstdlib>
    #include <cstring>
    #include<ctype.h>
    #include<iostream>
    #include<vector>
    #include<string>
    using namespace std;
    #define YYDEBUG 1        //开启debug
    int yylex();			//调用词法分析器，每次返回一个TOKEN
    void yyerror(const char* msg)
    {
        // printf("Error type [%s] \n",msg);
        // printf("Error type [%s] at line [%d] : %s\n", yylineno,msg);
    }
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;

#line 92 "sysy.tab.cpp"

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
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_AND = 33,                       /* "&&"  */
  YYSYMBOL_OR = 34,                        /* "||"  */
  YYSYMBOL_Ident = 35,                     /* Ident  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_FLOAT = 37,                     /* FLOAT  */
  YYSYMBOL_VOID = 38,                      /* VOID  */
  YYSYMBOL_ILLEGAL_HEX_CONST = 39,         /* ILLEGAL_HEX_CONST  */
  YYSYMBOL_ILLEGAL_OCTAL_CONST = 40,       /* ILLEGAL_OCTAL_CONST  */
  YYSYMBOL_HEX_CONST = 41,                 /* HEX_CONST  */
  YYSYMBOL_OCTAL_CONST = 42,               /* OCTAL_CONST  */
  YYSYMBOL_INTNUM = 43,                    /* INTNUM  */
  YYSYMBOL_FLOATNUM = 44,                  /* FLOATNUM  */
  YYSYMBOL_SSS = 45,                       /* SSS  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_CompUnit = 49,                  /* CompUnit  */
  YYSYMBOL_Decl = 50,                      /* Decl  */
  YYSYMBOL_ConstDecl = 51,                 /* ConstDecl  */
  YYSYMBOL_BType = 52,                     /* BType  */
  YYSYMBOL_ConstDef = 53,                  /* ConstDef  */
  YYSYMBOL_ConstExpGroup = 54,             /* ConstExpGroup  */
  YYSYMBOL_ConstInitVal = 55,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValGroup = 56,         /* ConstInitValGroup  */
  YYSYMBOL_VarDecl = 57,                   /* VarDecl  */
  YYSYMBOL_VarDefGroup = 58,               /* VarDefGroup  */
  YYSYMBOL_VarDef = 59,                    /* VarDef  */
  YYSYMBOL_ArrayDef = 60,                  /* ArrayDef  */
  YYSYMBOL_InitVal = 61,                   /* InitVal  */
  YYSYMBOL_InitValGroup = 62,              /* InitValGroup  */
  YYSYMBOL_FuncDef = 63,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 64,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 65,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArray = 66,           /* FuncFParamArray  */
  YYSYMBOL_Block = 67,                     /* Block  */
  YYSYMBOL_BlockGroup = 68,                /* BlockGroup  */
  YYSYMBOL_BlockItem = 69,                 /* BlockItem  */
  YYSYMBOL_Stmt = 70,                      /* Stmt  */
  YYSYMBOL_Exp = 71,                       /* Exp  */
  YYSYMBOL_Cond = 72,                      /* Cond  */
  YYSYMBOL_LVal = 73,                      /* LVal  */
  YYSYMBOL_ArrayList = 74,                 /* ArrayList  */
  YYSYMBOL_Number = 75,                    /* Number  */
  YYSYMBOL_PrimaryExp = 76,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 77,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 78,                   /* UnaryOp  */
  YYSYMBOL_FuncParamsGroup = 79,           /* FuncParamsGroup  */
  YYSYMBOL_MulExp = 80,                    /* MulExp  */
  YYSYMBOL_AddExp = 81,                    /* AddExp  */
  YYSYMBOL_RelExp = 82,                    /* RelExp  */
  YYSYMBOL_EqExp = 83,                     /* EqExp  */
  YYSYMBOL_LAndExp = 84,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 85,                    /* LOrExp  */
  YYSYMBOL_StrExp = 86,                    /* StrExp  */
  YYSYMBOL_ConstExp = 87                   /* ConstExp  */
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
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

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
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
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
       0,   100,   100,   101,   102,   103,   104,   105,   106,   107,
     111,   112,   113,   115,   116,   118,   119,   121,   121,   122,
     123,   125,   126,   128,   130,   131,   133,   134,   135,   136,
     138,   139,   140,   142,   142,   143,   145,   146,   149,   150,
     152,   153,   156,   157,   158,   159,   162,   163,   166,   167,
     169,   170,   173,   174,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   190,   191,   194,   197,   198,
     200,   201,   203,   206,   209,   244,   248,   249,   250,   252,
     253,   254,   255,   257,   258,   259,   260,   260,   262,   263,
     264,   265,   267,   268,   269,   272,   273,   274,   275,   276,
     279,   280,   281,   284,   285,   288,   289,   292,   295,   296
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
  "WHILE", "FOR", "BREAK", "RETURN", "CONTINUE", "\"&&\"", "\"||\"",
  "Ident", "INT", "FLOAT", "VOID", "ILLEGAL_HEX_CONST",
  "ILLEGAL_OCTAL_CONST", "HEX_CONST", "OCTAL_CONST", "INTNUM", "FLOATNUM",
  "SSS", "'['", "']'", "$accept", "CompUnit", "Decl", "ConstDecl", "BType",
  "ConstDef", "ConstExpGroup", "ConstInitVal", "ConstInitValGroup",
  "VarDecl", "VarDefGroup", "VarDef", "ArrayDef", "InitVal",
  "InitValGroup", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncFParamArray", "Block", "BlockGroup", "BlockItem", "Stmt", "Exp",
  "Cond", "LVal", "ArrayList", "Number", "PrimaryExp", "UnaryExp",
  "UnaryOp", "FuncParamsGroup", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "StrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,    36,  -131,  -131,  -131,    21,  -131,    58,   -17,  -131,
    -131,    -8,  -131,  -131,  -131,    -8,     9,    51,  -131,    13,
      78,  -131,   273,   143,   101,    19,  -131,    46,    91,   324,
      45,  -131,  -131,  -131,  -131,   250,   324,    65,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,   331,
     104,    52,  -131,    90,    52,  -131,   102,   109,    94,     2,
    -131,   273,   324,    61,  -131,  -131,    60,  -131,  -131,   110,
      91,   324,  -131,  -131,    71,   119,   324,   287,   112,  -131,
     331,   331,   331,   331,   331,  -131,  -131,   174,  -131,   111,
      36,   109,  -131,   141,  -131,  -131,   122,  -131,  -131,   142,
     273,  -131,  -131,   148,  -131,  -131,     7,   324,  -131,  -131,
    -131,   104,   104,  -131,  -131,   149,   150,   158,   313,   159,
    -131,    46,  -131,   205,  -131,  -131,   160,   162,   124,  -131,
    -131,  -131,    91,  -131,  -131,  -131,  -131,   324,  -131,   157,
     331,   331,  -131,  -131,   161,  -131,  -131,  -131,  -131,   324,
     134,  -131,  -131,  -131,   167,    52,   155,    89,   163,   147,
     168,  -131,   179,   324,   152,   236,   331,   331,   331,   331,
     331,   331,   331,   331,   236,  -131,   154,   324,   176,    52,
      52,    52,    52,   155,   155,    89,   163,  -131,  -131,   175,
     236,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,    12,     0,     4,     6,     0,     7,
       2,     0,     1,     5,     3,     0,    26,     0,    24,     0,
       0,     9,     0,     0,     0,    28,    23,     0,     0,     0,
       0,     8,    83,    84,    85,     0,     0,    68,    72,    73,
      74,    75,   107,    27,    33,    77,    78,    79,    88,     0,
      92,    65,    66,     0,   108,   109,     0,     0,    42,     0,
      40,     0,     0,    26,    25,    20,     0,    14,    17,     0,
       0,     0,    34,    36,     0,     0,     0,     0,    69,    82,
       0,     0,     0,     0,     0,    32,    30,     0,    38,    43,
       0,     0,    29,     0,    18,    21,     0,    15,    13,     0,
       0,    35,    76,     0,    80,    86,     0,     0,    89,    90,
      91,    93,    94,    55,    48,     0,     0,     0,     0,     0,
      52,     0,    57,     0,    50,    53,     0,    77,     0,    41,
      39,    31,     0,    19,    16,    37,    70,     0,    81,     0,
       0,     0,    61,    63,     0,    62,    49,    51,    56,     0,
      44,    22,    87,    71,     0,    95,   100,   103,   105,    67,
       0,    64,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    58,    96,
      98,    97,    99,   101,   102,   104,   106,    60,    46,     0,
       0,    47,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,    28,  -131,     0,   192,  -131,   -55,  -131,  -131,
    -131,   181,  -131,   -32,  -131,   218,  -131,   136,  -131,   -38,
    -131,   106,  -130,   -22,    86,   -81,  -131,  -131,  -131,   -44,
    -131,  -131,    24,   -21,   -49,    62,    59,  -131,   -19,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,   120,     7,     8,    20,    30,    67,    96,     9,
      17,    18,    25,    43,    74,    10,    59,    60,   164,   122,
     123,   124,   125,   126,   154,    45,    78,    46,    47,    48,
      49,   106,    50,    51,   156,   157,   158,   159,    52,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    11,    54,    73,    55,    79,   127,    54,    54,    55,
      55,    95,    22,    44,    75,    98,    28,    56,    16,    88,
      90,    12,    61,    69,    58,   137,    91,    19,     6,    92,
      23,   138,    24,    13,    29,   178,   108,   109,   110,    44,
      62,    54,   127,    55,   187,    54,     1,    55,    70,    54,
      54,    55,    55,   130,   103,   105,    93,     2,     3,     4,
     192,    65,    83,    84,    22,    99,    71,    26,   135,    27,
      32,    33,     2,     3,     4,    34,    15,   151,    44,    66,
      94,    63,    23,    36,   127,   139,    76,   121,    77,   100,
      58,   101,    65,   127,    31,    37,   144,   170,   171,    38,
      39,    32,    33,    40,    41,    42,    34,   111,   112,   127,
      66,    54,    85,    55,    36,   152,    80,    81,    82,   155,
     155,   183,   184,   121,    86,    57,    37,   162,    87,    89,
      38,    39,    97,   107,    40,    41,    42,     2,     3,     4,
     132,   176,   133,   102,    53,   179,   180,   181,   182,   155,
     155,   155,   155,    32,    33,   189,     1,   128,    34,   166,
     167,   168,   169,   131,   134,   149,    36,     2,     3,     4,
     136,   150,   140,   141,   142,   145,   148,   161,    37,   153,
     163,   173,    38,    39,    32,    33,    40,    41,    42,    34,
     113,   165,   174,    87,   114,   175,   172,    36,   177,     1,
     115,   188,   116,   190,   117,   118,   119,    21,    64,    37,
       2,     3,     4,    38,    39,    32,    33,    40,    41,    42,
      34,   113,   191,    14,    87,   146,   129,   160,    36,   147,
       1,   115,   186,   116,   185,   117,   118,   119,     0,     0,
      37,     2,     3,     4,    38,    39,    32,    33,    40,    41,
      42,    34,   113,     0,     0,    87,     0,     0,     0,    36,
      32,    33,   115,     0,   116,    34,   117,   118,   119,    35,
      72,    37,     0,    36,     0,    38,    39,     0,     0,    40,
      41,    42,     0,    32,    33,    37,     0,     0,    34,    38,
      39,     0,    35,    40,    41,    42,    36,    32,    33,     0,
       0,     0,    34,     0,     0,     0,     0,     0,    37,     0,
      36,   104,    38,    39,     0,     0,    40,    41,    42,     0,
       0,     0,    37,    32,    33,     0,    38,    39,    34,   143,
      40,    41,    42,     0,    32,    33,    36,     0,     0,    34,
       0,    32,    33,     0,     0,     0,    34,    36,    37,     0,
       0,     0,    38,    39,    36,     0,    40,    41,    42,    37,
       0,     0,     0,    38,    39,     0,    37,    40,    41,    42,
      38,    39,     0,     0,    40,    41
};

static const yytype_int16 yycheck[] =
{
      22,     1,    23,    35,    23,    49,    87,    28,    29,    28,
      29,    66,     3,    35,    36,    70,     3,    23,    35,    57,
      18,     0,     3,    29,    24,    18,    24,    35,     0,    61,
      21,    24,    23,     5,    21,   165,    80,    81,    82,    61,
      21,    62,   123,    62,   174,    66,    25,    66,     3,    70,
      71,    70,    71,    91,    76,    77,    62,    36,    37,    38,
     190,     1,    10,    11,     3,    71,    21,    16,   100,    18,
      10,    11,    36,    37,    38,    15,    18,   132,   100,    19,
      20,    35,    21,    23,   165,   107,    21,    87,    23,    18,
      90,    20,     1,   174,    16,    35,   118,     8,     9,    39,
      40,    10,    11,    43,    44,    45,    15,    83,    84,   190,
      19,   132,    22,   132,    23,   137,    12,    13,    14,   140,
     141,   170,   171,   123,    22,    24,    35,   149,    19,    35,
      39,    40,    22,    21,    43,    44,    45,    36,    37,    38,
      18,   163,    20,    24,     1,   166,   167,   168,   169,   170,
     171,   172,   173,    10,    11,   177,    25,    46,    15,     4,
       5,     6,     7,    22,    22,     3,    23,    36,    37,    38,
      22,    47,    23,    23,    16,    16,    16,    16,    35,    22,
      46,    34,    39,    40,    10,    11,    43,    44,    45,    15,
      16,    24,    24,    19,    20,    16,    33,    23,    46,    25,
      26,    47,    28,    27,    30,    31,    32,    15,    27,    35,
      36,    37,    38,    39,    40,    10,    11,    43,    44,    45,
      15,    16,    47,     5,    19,    20,    90,   141,    23,   123,
      25,    26,   173,    28,   172,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    10,    11,    43,    44,
      45,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    23,
      10,    11,    26,    -1,    28,    15,    30,    31,    32,    19,
      20,    35,    -1,    23,    -1,    39,    40,    -1,    -1,    43,
      44,    45,    -1,    10,    11,    35,    -1,    -1,    15,    39,
      40,    -1,    19,    43,    44,    45,    23,    10,    11,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      23,    24,    39,    40,    -1,    -1,    43,    44,    45,    -1,
      -1,    -1,    35,    10,    11,    -1,    39,    40,    15,    16,
      43,    44,    45,    -1,    10,    11,    23,    -1,    -1,    15,
      -1,    10,    11,    -1,    -1,    -1,    15,    23,    35,    -1,
      -1,    -1,    39,    40,    23,    -1,    43,    44,    45,    35,
      -1,    -1,    -1,    39,    40,    -1,    35,    43,    44,    45,
      39,    40,    -1,    -1,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    36,    37,    38,    49,    50,    51,    52,    57,
      63,    52,     0,    50,    63,    18,    35,    58,    59,    35,
      53,    53,     3,    21,    23,    60,    16,    18,     3,    21,
      54,    16,    10,    11,    15,    19,    23,    35,    39,    40,
      43,    44,    45,    61,    71,    73,    75,    76,    77,    78,
      80,    81,    86,     1,    81,    86,    87,    24,    52,    64,
      65,     3,    21,    35,    59,     1,    19,    55,    87,    87,
       3,    21,    20,    61,    62,    71,    21,    23,    74,    77,
      12,    13,    14,    10,    11,    22,    22,    19,    67,    35,
      18,    24,    61,    87,    20,    55,    56,    22,    55,    87,
      18,    20,    24,    71,    24,    71,    79,    21,    77,    77,
      77,    80,    80,    16,    20,    26,    28,    30,    31,    32,
      50,    52,    67,    68,    69,    70,    71,    73,    46,    65,
      67,    22,    18,    20,    22,    61,    22,    18,    24,    71,
      23,    23,    16,    16,    71,    16,    20,    69,    16,     3,
      47,    55,    71,    22,    72,    81,    82,    83,    84,    85,
      72,    16,    71,    46,    66,    24,     4,     5,     6,     7,
       8,     9,    33,    34,    24,    16,    71,    46,    70,    81,
      81,    81,    81,    82,    82,    83,    84,    70,    47,    71,
      27,    47,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    86,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     4,     3,
       1,     1,     1,     4,     3,     3,     4,     1,     2,     3,
       1,     1,     3,     3,     1,     3,     1,     3,     2,     4,
       3,     4,     3,     1,     2,     3,     1,     3,     5,     6,
       1,     3,     1,     2,     4,     5,     3,     4,     2,     3,
       1,     2,     1,     1,     4,     1,     2,     1,     5,     7,
       5,     2,     2,     2,     3,     1,     1,     1,     1,     2,
       3,     4,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     4,     2,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     1,     1
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
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
#line 100 "sysy.y"
                  {printf("Funcdef successful!");}
#line 1453 "sysy.tab.cpp"
    break;

  case 4: /* CompUnit: Decl  */
#line 102 "sysy.y"
               {printf("Decl successful!");}
#line 1459 "sysy.tab.cpp"
    break;

  case 10: /* BType: INT  */
#line 111 "sysy.y"
        {}
#line 1465 "sysy.tab.cpp"
    break;

  case 13: /* ConstDef: Ident ConstExpGroup "=" ConstInitVal  */
#line 115 "sysy.y"
                                                  {}
#line 1471 "sysy.tab.cpp"
    break;

  case 14: /* ConstDef: Ident "=" ConstInitVal  */
#line 116 "sysy.y"
                                   {}
#line 1477 "sysy.tab.cpp"
    break;

  case 15: /* ConstExpGroup: "[" ConstExp "]"  */
#line 118 "sysy.y"
                                {}
#line 1483 "sysy.tab.cpp"
    break;

  case 16: /* ConstExpGroup: ConstExpGroup "[" ConstExp "]"  */
#line 119 "sysy.y"
                                             {}
#line 1489 "sysy.tab.cpp"
    break;

  case 20: /* ConstInitVal: error  */
#line 123 "sysy.y"
                    {}
#line 1495 "sysy.tab.cpp"
    break;

  case 21: /* ConstInitValGroup: ConstInitVal  */
#line 125 "sysy.y"
                                {}
#line 1501 "sysy.tab.cpp"
    break;

  case 22: /* ConstInitValGroup: ConstInitValGroup "," ConstInitVal  */
#line 126 "sysy.y"
                                                     {}
#line 1507 "sysy.tab.cpp"
    break;

  case 23: /* VarDecl: BType VarDefGroup ";"  */
#line 128 "sysy.y"
                                {}
#line 1513 "sysy.tab.cpp"
    break;

  case 24: /* VarDefGroup: VarDef  */
#line 130 "sysy.y"
                    {}
#line 1519 "sysy.tab.cpp"
    break;

  case 25: /* VarDefGroup: VarDefGroup "," VarDef  */
#line 131 "sysy.y"
                                    {}
#line 1525 "sysy.tab.cpp"
    break;

  case 26: /* VarDef: Ident  */
#line 133 "sysy.y"
               {}
#line 1531 "sysy.tab.cpp"
    break;

  case 27: /* VarDef: Ident "=" InitVal  */
#line 134 "sysy.y"
                               {}
#line 1537 "sysy.tab.cpp"
    break;

  case 28: /* VarDef: Ident ArrayDef  */
#line 135 "sysy.y"
                         {}
#line 1543 "sysy.tab.cpp"
    break;

  case 29: /* VarDef: Ident ArrayDef "=" InitVal  */
#line 136 "sysy.y"
                                        {}
#line 1549 "sysy.tab.cpp"
    break;

  case 32: /* ArrayDef: "[" error "]"  */
#line 140 "sysy.y"
                       {printf("invalid Arraydef: need argument in []\n");}
#line 1555 "sysy.tab.cpp"
    break;

  case 38: /* FuncDef: BType Ident "(" ")" Block  */
#line 149 "sysy.y"
                                  {}
#line 1561 "sysy.tab.cpp"
    break;

  case 41: /* FuncFParams: FuncFParams "," FuncFParam  */
#line 153 "sysy.y"
                                         {}
#line 1567 "sysy.tab.cpp"
    break;

  case 48: /* Block: "{" "}"  */
#line 166 "sysy.y"
            {}
#line 1573 "sysy.tab.cpp"
    break;

  case 49: /* Block: "{" BlockGroup "}"  */
#line 167 "sysy.y"
                         {}
#line 1579 "sysy.tab.cpp"
    break;

  case 50: /* BlockGroup: BlockItem  */
#line 169 "sysy.y"
                  {}
#line 1585 "sysy.tab.cpp"
    break;

  case 51: /* BlockGroup: BlockGroup BlockItem  */
#line 170 "sysy.y"
                              {}
#line 1591 "sysy.tab.cpp"
    break;

  case 55: /* Stmt: ";"  */
#line 178 "sysy.y"
               {}
#line 1597 "sysy.tab.cpp"
    break;

  case 65: /* Exp: AddExp  */
#line 190 "sysy.y"
           {(yyval.const_String_Val)=(yyvsp[0].const_String_Val); /*cout<<"analys Add expression\n";*/}
#line 1603 "sysy.tab.cpp"
    break;

  case 66: /* Exp: StrExp  */
#line 191 "sysy.y"
           {(yyval.const_String_Val)=(yyvsp[0].const_String_Val); /*cout<<"analys Str expression\n";*/}
#line 1609 "sysy.tab.cpp"
    break;

  case 67: /* Cond: LOrExp  */
#line 194 "sysy.y"
           {(yyval.const_String_Val)=(yyvsp[0].const_String_Val);}
#line 1615 "sysy.tab.cpp"
    break;

  case 72: /* Number: ILLEGAL_HEX_CONST  */
#line 203 "sysy.y"
                           {
                printf("Error type [%s] at line [%d] : Illegal hex number %s\n","Number",yylineno,yytext);
        }
#line 1623 "sysy.tab.cpp"
    break;

  case 73: /* Number: ILLEGAL_OCTAL_CONST  */
#line 206 "sysy.y"
                             {
                printf("Error type [%s] at line [%d] : Illegal octal number %s\n","Number" ,yylineno,yytext);
        }
#line 1631 "sysy.tab.cpp"
    break;

  case 74: /* Number: INTNUM  */
#line 209 "sysy.y"
                {
                (yyval.const_String_Val)=yytext;
                cout<<"GET INTNUM: "<< yytext <<endl;
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
                cout<<"get number value : "<<num<<endl;
        }
#line 1670 "sysy.tab.cpp"
    break;

  case 76: /* PrimaryExp: "(" Exp ")"  */
#line 248 "sysy.y"
                        {}
#line 1676 "sysy.tab.cpp"
    break;

  case 77: /* PrimaryExp: LVal  */
#line 249 "sysy.y"
                         {}
#line 1682 "sysy.tab.cpp"
    break;

  case 78: /* PrimaryExp: Number  */
#line 250 "sysy.y"
                         {}
#line 1688 "sysy.tab.cpp"
    break;

  case 79: /* UnaryExp: PrimaryExp  */
#line 252 "sysy.y"
                   {}
#line 1694 "sysy.tab.cpp"
    break;

  case 88: /* MulExp: UnaryExp  */
#line 262 "sysy.y"
                 {}
#line 1700 "sysy.tab.cpp"
    break;

  case 92: /* AddExp: MulExp  */
#line 267 "sysy.y"
               {}
#line 1706 "sysy.tab.cpp"
    break;

  case 95: /* RelExp: AddExp  */
#line 272 "sysy.y"
               {}
#line 1712 "sysy.tab.cpp"
    break;

  case 100: /* EqExp: RelExp  */
#line 279 "sysy.y"
               {}
#line 1718 "sysy.tab.cpp"
    break;

  case 103: /* LAndExp: EqExp  */
#line 284 "sysy.y"
              {}
#line 1724 "sysy.tab.cpp"
    break;

  case 105: /* LOrExp: LAndExp  */
#line 288 "sysy.y"
                {}
#line 1730 "sysy.tab.cpp"
    break;

  case 107: /* StrExp: SSS  */
#line 292 "sysy.y"
       {}
#line 1736 "sysy.tab.cpp"
    break;

  case 108: /* ConstExp: AddExp  */
#line 295 "sysy.y"
               {}
#line 1742 "sysy.tab.cpp"
    break;

  case 109: /* ConstExp: StrExp  */
#line 296 "sysy.y"
               {}
#line 1748 "sysy.tab.cpp"
    break;


#line 1752 "sysy.tab.cpp"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval, &yylloc);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 299 "sysy.y"

int main(int argc, char** argv){
    extern FILE* yyin;
    int cnt=0;
    vector<string>parsedFiles;
    if(argc >= 2){
        int i=1;
        while(i<argc){
                yylineno=1;
                if((yyin = fopen(argv[i], "r")) == NULL){
                printf("Can't open file %s\n", argv[1]);
                return 1;
                }else{
                printf("open file %s successfully\n",argv[1]);
                }
                bool flag=yyparse();
                if(!flag)parsedFiles.push_back(argv[i]);//解析无误
                        fclose(yyin);
                i++;
        }
        printf("\n\n\n");
        for (auto file:parsedFiles){
                cout<<file<<"sysy syntax correct!\n\n\n";
        }
    }
    else{
     yyparse();
    }
    return 0;
}
