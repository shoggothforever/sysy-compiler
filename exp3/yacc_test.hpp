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

#ifndef YY_YY_YACC_TEST_HPP_INCLUDED
# define YY_YY_YACC_TEST_HPP_INCLUDED
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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    CHAR = 261,                    /* CHAR  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    DO = 265,                      /* DO  */
    FOR = 266,                     /* FOR  */
    GOTO = 267,                    /* GOTO  */
    RETURN = 268,                  /* RETURN  */
    CONTINUE = 269,                /* CONTINUE  */
    BREAK = 270,                   /* BREAK  */
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    ENUM = 273,                    /* ENUM  */
    CONST = 274,                   /* CONST  */
    OCTAL_CONST = 275,             /* OCTAL_CONST  */
    ILLEGAL_OCTAL_CONST = 276,     /* ILLEGAL_OCTAL_CONST  */
    HEX_CONST = 277,               /* HEX_CONST  */
    ILLEGAL_HEX_CONST = 278,       /* ILLEGAL_HEX_CONST  */
    DEC_CONST = 279,               /* DEC_CONST  */
    ID = 280,                      /* ID  */
    UNEXPECTED = 281,              /* UNEXPECTED  */
    OPERATOR = 282,                /* OPERATOR  */
    COMPARISON = 283,              /* COMPARISON  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    UMINUS = 286                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "test.y"

    char*      string

#line 99 "yacc_test.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TEST_HPP_INCLUDED  */
