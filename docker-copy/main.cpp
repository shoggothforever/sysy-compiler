// 添加了部分语义解析的功能代码
#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include "asTree.h"
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
                auto tree=make_unique<astTree>();
                tree->root=NULL;
                yylineno=1;
                if((yyin = fopen(argv[i], "r")) == NULL){
                    printf("Can't open file %s\n", argv[1]);
                return 1;
                }else{
                    printf("open file %s successfully\n",argv[1]);
                }
                bool flag=yyparse(tree.get());
                if(!flag){
                        parsedFiles.push_back(argv[i]);//解析无误
                        parsedTrees.push_back(tree.get());
                }
                if(tree->root){
                    // 遍历AST
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
        auto tree=std::make_unique<astTree>();
        tree->root=nullptr;
        bool flag=yyparse(tree.get());
        if(!flag)tree->print();
    }
    return 0;
}
