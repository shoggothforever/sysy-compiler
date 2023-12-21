OBJS=lex.yy.o sysy.tab.o asTree.o main.o
CC=g++
CFLAGS=-Wall -g
NAME="parsecpp"
CLEAN_LIST=lex.yy.o sysy.tab.o lex.yy.cpp sysy.tab.h sysy.tab.cpp
$(NAME): $(OBJS)
	$(CC) $^ -lfl $(CFLAGS) -o $(NAME)

sysy.tab.cpp sysy.tab.hpp: sysy.y asTree.h
	bison -d --output sysy.tab.cpp $<
lex.yy.cpp: sysy.l sysy.tab.hpp asTree.h
	flex --outfile lex.yy.cpp $<
clean:
	rm -f $(CLEAN_LIST) $(NAME)
