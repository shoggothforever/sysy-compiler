/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYSY_TAB_HPP_INCLUDED
# define YY_YY_SYSY_TAB_HPP_INCLUDED
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
    ASSIGN = 258,                  /* "="  */
    LT = 259,                      /* "<"  */
    LE = 260,                      /* "<="  */
    GT = 261,                      /* ">"  */
    GE = 262,                      /* ">="  */
    EQ = 263,                      /* "=="  */
    NE = 264,                      /* "!="  */
    ADD = 265,                     /* "+"  */
    SUB = 266,                     /* "-"  */
    MUL = 267,                     /* "*"  */
    DIV = 268,                     /* "/"  */
    MOD = 269,                     /* "%"  */
    NOT = 270,                     /* "!"  */
    SEMI = 271,                    /* ";"  */
    COLON = 272,                   /* ":"  */
    COMMA = 273,                   /* ","  */
    OB = 274,                      /* "{"  */
    CB = 275,                      /* "}"  */
    LB = 276,                      /* "["  */
    RB = 277,                      /* "]"  */
    L = 278,                       /* "("  */
    R = 279,                       /* ")"  */
    CONST = 280,                   /* CONST  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    WHILE = 283,                   /* WHILE  */
    FOR = 284,                     /* FOR  */
    BREAK = 285,                   /* BREAK  */
    RETURN = 286,                  /* RETURN  */
    CONTINUE = 287,                /* CONTINUE  */
    AND = 288,                     /* "&&"  */
    OR = 289,                      /* "||"  */
    INT = 290,                     /* INT  */
    FLOAT = 291,                   /* FLOAT  */
    VOID = 292,                    /* VOID  */
    ILLEGAL_HEX_CONST = 293,       /* ILLEGAL_HEX_CONST  */
    ILLEGAL_OCTAL_CONST = 294,     /* ILLEGAL_OCTAL_CONST  */
    HEX_CONST = 295,               /* HEX_CONST  */
    OCTAL_CONST = 296,             /* OCTAL_CONST  */
    INTNUM = 297,                  /* INTNUM  */
    FLOATNUM = 298,                /* FLOATNUM  */
    SSS = 299,                     /* SSS  */
    Ident = 300                    /* Ident  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "sysy.y"

struct astNode *                node;
struct astTree *                tree;
char *                          String;
int                             const_Int_Val;
float                           const_Float_Val;

#line 117 "sysy.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (astTree* tree);


#endif /* !YY_YY_SYSY_TAB_HPP_INCLUDED  */
