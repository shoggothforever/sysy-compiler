%option noyywrap
%{
#include<string.h>
#include<stdio.h>
#define YY_USER_ACTION
#include "test.tab.h"
extern int atoi();
extern double atof();
#define RETURN_TOKEN(name) return name;
#define RETURN_INT_TOKEN(name) printf("<##name,%d>",name);return name;
#define RETURN_CHAR_TOKEN(name) printf("<##name,%s>",#name);return name;
%}
/* 不区分大小写  */



WHITE_SAPCE      [\ \t\b\f]

KEYWORD             if|else|while|break|continue|return|for|goto
COMPARISON          "=="|"!="|"<>"|">"|"<"|">="|"<="
NONZERO             [1-9]
DIGIT               [0-9]
LETTER              [A-Za-z]
OCTAL_DIGIT         [0-7]
OCTAL_CONST         0{OCTAL_DIGIT}*
ILLEGAL_OCTAL_CONST 0[0-9a-wy-zA-WY-Z]({LETTER}|{DIGIT})*
HEX_PREFIX          0x|0X
HEX_DIGIT           [0-9a-fA-F]
HEX_CONST           {HEX_PREFIX}{HEX_DIGIT}+
ILLEGAL_HEX_CONST   {HEX_PREFIX}({LETTER}|{DIGIT})*
NONDIGIT            {LETTER}|"_"

DEC_CONST           {NONZERO}{DIGIT}*
COMMENT1            "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"
COMMENT2            "//".*
ID                  {NONDIGIT}({DIGIT}|{NONDIGIT})*
DOT              \.
QUOTE            [\'\"]
%x STR
%%

","                     |
";"                     |
"("                     |
")"                     |
"["                     |
"]"                     |
"{"                     |
"}"                     |
"+"                     |
"-"                     |
"*"                     |
"/"                     |
"="                     |
"!"                     |
"%"                     {printf("%c",yytext[0]);return yytext[0];}
INT                     RETURN_INT_TOKEN(INT)
FLOAT                   RETURN_TOKEN(FLOAT)
VOID                    RETURN_TOKEN(VOID)
CHAR                    RETURN_CHAR_TOKEN(CHAR)
IF                      RETURN_TOKEN(IF)
ELSE                    RETURN_TOKEN(ELSE)
WHILE                   RETURN_TOKEN(WHILE)
DO                      RETURN_TOKEN(DO)
FOR                     RETURN_TOKEN(FOR)
GOTO                    RETURN_TOKEN(GOTO)
RETURN                  RETURN_TOKEN(RETURN)
CONTINUE                RETURN_TOKEN(CONTINUE)
BREAK                   RETURN_TOKEN(BREAK)
SWITCH                  RETURN_TOKEN(SWITCH)
CASE                    RETURN_TOKEN(CASE)
ENUM                    RETURN_TOKEN(ENUM)
CONST                   RETURN_TOKEN(CONST)
{OCTAL_CONST}           RETURN_TOKEN(OCTAL_CONST)
{ILLEGAL_OCTAL_CONST}   RETURN_TOKEN(ILLEGAL_OCTAL_CONST)
{HEX_CONST}             RETURN_TOKEN(HEX_CONST)
{ILLEGAL_HEX_CONST}     RETURN_TOKEN(ILLEGAL_HEX_CONST)
{DEC_CONST}             RETURN_TOKEN(DEC_CONST)
{ID}                    RETURN_TOKEN(ID)

{COMPARISON}            RETURN_TOKEN(COMPARISON)

"&&"                    RETURN_TOKEN(AND)
"||"                    RETURN_TOKEN(OR)
{COMMENT1}|{COMMENT2}   { }
[ \t\n]                 { }



.                       RETURN_TOKEN(UNEXPECTED)

%%

