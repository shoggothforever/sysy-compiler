%option noyywrap
%{
#include<stdio.h>
#include"sysy.tab.h"
%}
intnum [1-9][0-9]*|0[0-7]*|(0x|0X)[0-9a-fA-F]*
floatnum [0-9]+[Ee][0-9]+
id [a-zA-Z_][a-zA-Z0-9_]*

%s COMMENT        //多行注释
%s LINECOMMENT    //单行注释

%%

"/*"		{BEGIN(COMMENT);}
<COMMENT>"*/"  {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>>   {printf("Unterminated comment\n"); return 0;}
"//" {BEGIN(LINECOMMENT);}
<LINECOMMENT>.*
<LINECOMMENT>\n {BEGIN(INITIAL);}
<LINECOMMENT><<EOF>> {BEGIN(INITIAL);}

[ \t]					{;}		//忽略空白符
\n					    {}    //匹配到换行符，行数+1
"int"					{printf("<INT>");return (INT);} //添加副作用，输出以供我们调试。
"float"					{return (FLOAT);}
"const"                 {return (CONST);}
"void"                	{return (VOID);}
"break"					{return (BREAK);}
"continue"				{return (CONTINUE);}
"return"				{printf("<RETURN>");return (RETURN);}
"if" 					{printf("<IF>");return (IF);}
"else" 					{printf("<ELSE>");return (ELSE);}
"while" 				{return (WHILE);}
{intnum}				{printf("<INTNUM>");return (INTNUM);}
{floatnum}				{return (FLOATNUM);}
"<"					{return (LT);}
"<="				{return (LE);}
">"					{return (GT);}
">="				{return (GE);}
"=="				{return (EQ);}
"!="				{return (NE);}
"="					{printf("<ASSIGN>");return (ASSIGN);}
"+"					{return (ADD);}
"-"					{return (SUB);}
"*"					{return (MUL);}
"/"					{return (DIV);}
"%"					{return (MOD);}
"!"					{return (NOT);}
"&&"				{return (AND);}
"||"				{return (OR);}
";"					{return (SEMI);}
":"					{return (COLON);}
","					{return (COMMA);}
"("					{return (L);}
")"					{return (R);}
"{"					{return (OB);}
"}"					{return (CB);}
"["					{return (LB);}
"]"					{return (RB);}
{id}				{printf("<Ident>");return (Ident);}
%%

