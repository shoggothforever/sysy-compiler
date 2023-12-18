#! /bin/bash
# bison -d sysy.y
# flex sysy.l
# gcc lex.yy.c sysy.tab.c -lfl -ly -o parser

flex SysY.l
gcc lex.yy.c -lyl
cat test.c|./a.out

bison -d --output yacc_test.cpp test.y
flex --outfile lex_test.cpp --header-file=test.tab.h test.l
g++ lex_test.cpp yacc_test.cpp -lfl
