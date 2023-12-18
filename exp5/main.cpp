// 添加了部分语义解析的功能代码
#include<cstdio>
#include <cstdlib>
#include <cstring>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<string>
#include "astTree.h"
using namespace std;

extern bool yyparse (AstTree tree);
extern FILE* yyin;
extern int yylineno;
int main(int argc, char** argv){
    Ast node;
    extern FILE* yyin;
    int cnt=0;
    vector<string>parsedFiles;
    vector<AstTree>parsedTrees;
    if(argc >= 2){
        int i=1;
        while(i<argc){
                AstTree tree=NewTree(NULL);
                tree->root=NULL;
                // while(tree->nodes.size())tree->nodes.pop_back();
                yylineno=1;
                if((yyin = fopen(argv[i], "r")) == NULL){
                printf("Can't open file %s\n", argv[1]);
                return 1;
                }else{
                printf("open file %s successfully\n",argv[1]);
                }
                // cout<<"initial tree address"<<tree<<endl;
                bool flag=yyparse(tree);
                if(!flag){
                        parsedFiles.push_back(argv[i]);//解析无误
                        parsedTrees.push_back(tree);
                }
                if(tree->root){
                    tree->print();
                    tree->semantic_check();
                }
                fclose(yyin);
                i++;
        }
        printf("\n\n\n");
        for (auto file:parsedFiles){
                cout<<file<<" sysy syntax correct!\n\n\n";
        }
    }
    else{
        AstTree tree=NewTree(NULL);
        tree->root=nullptr;
        bool flag=yyparse(tree);
        tree->print();

    }
    return 0;
}
