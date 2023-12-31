%{
#include<stdio.h>
#include "astTree.h"
#include"sysy.tab.hpp"
#include<iostream>
using namespace std;

extern char* yytext;
extern int atoi();
extern double atof();
#define YY_TYPEDEF_YY_SIZE_T
#define YY_USER_ACTION
//#define RETURN_TOKEN(name) yylval.String=yytext;printf("%s:<%s,%d>\n",yytext,#name,name);return name;
#define RETURN_TOKEN(name) \
    yylval.node=NewAst(#name,#name,yylineno,0);\
    yylval.node->val=yytext;\
    yylval.node->declByFlex=true; \
    return name;

%}
%option noyywrap
%option yylineno
%option nounput
%option noinput

LETDIG [a-zA-Z0-9]
HEX_PREFIX          0x|0X
HEX_DIGIT           [0-9a-fA-F]
HEX_CONST           {HEX_PREFIX}{HEX_DIGIT}+
OCTAL_DIGIT         [0-7]
OCTAL_CONST         0[^xX]?{OCTAL_DIGIT}*
ILLEGAL_HEX_CONST   {HEX_PREFIX}{HEX_DIGIT}*[g-zG-Z]+{LETDIG}*
ILLEGAL_OCTAL_CONST  0([0-7]?([a-zA-Z]|[8-9])+[a-zA-Z0-9]*)|0[^xX0-7[];][a-zA-Z0-9]*

intnum [1-9][0-9]*|0[0-7]*|(0x|0X)[0-9a-fA-F]*
LETTER [a-zA-Z]

DIGIT            [0-9]+

DOT     \.
floatnum [0-9]+[Ee][0-9]+|[\-]?{DIGIT}+{DOT}{DIGIT}+
id [a-zA-Z_][a-zA-Z0-9]*


%s COMMENT
%s LINECOMMENT
%s PREPROCESS

%%

# {BEGIN(PREPROCESS);}
<PREPROCESS>.*
<PREPROCESS>"\n" {BEGIN(INITIAL);}
<PREPROCESS><<EOF>> {BEGIN(INITIAL);}

"/*" {BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>> {return 0;}
"//" {BEGIN(LINECOMMENT);}
<LINECOMMENT>.*
<LINECOMMENT>\n {BEGIN(INITIAL);}
<LINECOMMENT><<EOF>> {BEGIN(INITIAL);}

[ \t]   {}
\n  {}
\r\n {}
"int" RETURN_TOKEN(INT);
"float" RETURN_TOKEN(FLOAT);
"const" RETURN_TOKEN(CONST);
"void" RETURN_TOKEN(VOID);
"break" RETURN_TOKEN(BREAK);
"continue" RETURN_TOKEN(CONTINUE);
"return"    RETURN_TOKEN(RETURN);
"if"        RETURN_TOKEN(IF);
"else"      RETURN_TOKEN(ELSE);
"while"     RETURN_TOKEN(WHILE);
"for"       RETURN_TOKEN(FOR);
{ILLEGAL_HEX_CONST} {
    RETURN_TOKEN(ILLEGAL_HEX_CONST);
}
{ILLEGAL_OCTAL_CONST} {
    if(strlen(yytext)>2&&yytext[1]=='x'||yytext[1]=='X'){
        RETURN_TOKEN (INTNUM);
    }
    RETURN_TOKEN(ILLEGAL_OCTAL_CONST);}
{intnum} {
    RETURN_TOKEN(INTNUM);
    }
{floatnum}  RETURN_TOKEN(FLOATNUM);

"<"         RETURN_TOKEN(LT);
"<="        RETURN_TOKEN(LE);
">"         RETURN_TOKEN(GT);
">="        RETURN_TOKEN(GE);
"=="        RETURN_TOKEN(EQ);
"!="        RETURN_TOKEN(NE);
"="         RETURN_TOKEN(ASSIGN);
"+"         RETURN_TOKEN(ADD);
"-"         RETURN_TOKEN(SUB);
"*"         RETURN_TOKEN(MUL);
"/"         RETURN_TOKEN(DIV);
"%"         RETURN_TOKEN(MOD);
"!"         RETURN_TOKEN(NOT);
"&&"        RETURN_TOKEN(AND);
"||"        RETURN_TOKEN(OR);
";"         RETURN_TOKEN(SEMI);
":"         RETURN_TOKEN(COLON);
","         RETURN_TOKEN(COMMA);
"("         RETURN_TOKEN(L);
")"         RETURN_TOKEN(R);
"{"         RETURN_TOKEN(OB);
"}"         RETURN_TOKEN(CB);
"["         RETURN_TOKEN(LB);
"]"         RETURN_TOKEN(RB);
{id}        RETURN_TOKEN(Ident);

\"[^"]*\"                               RETURN_TOKEN(SSS);
'[^']*\'                                RETURN_TOKEN(SSS);
.                                       printf("Error type A [character] at line [%d] :Invalid character %c \n",yylineno,yytext[0]);
%%
