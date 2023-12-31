OBJS=lex.yy.o sysy.tab.o asTree.o main.o
CC=g++
CFLAGS=-Wall -g
NAME="parse"
CLEAN_LIST=*.o lex.yy.cpp sysy.tab.h sysy.tab.cpp sysy.tab.hpp ast_output ast_output.txt
$(NAME): $(OBJS)
	$(CC) $^ -lfl $(CFLAGS) -o $(NAME)
sysy.tab.cpp sysy.tab.hpp: sysy.y asTree.h
	bison -d --output sysy.tab.cpp $<
lex.yy.cpp: sysy.l sysy.tab.hpp asTree.h
	flex --outfile lex.yy.cpp $<
clean:
	rm -f $(CLEAN_LIST) $(NAME)
