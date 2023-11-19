#pragma once
#include <cstring>
#include<iostream>
#include<string>
#include<cstdarg>
#include<vector>
using std::string;
using std::vector;

typedef class astNode{
public:
    int line;
    string name;
    string val;
    vector<astNode*>childs;
    bool declByFlex;
    union{
        int intval;
        float floatval;
        bool boolval;
        string stringval;
    };

    astNode(string name,string val,int line);
    void print(string tab,int layer);


}* Ast;
Ast NewAst(string name,int line,int num,...);
Ast NewAst(string name,string val,int line,int num,...);

#define RETURNRCSTRINGS()\
RETURNRCSTRING(Success) \
RETURNRCSTRING(InvalidSymbol) \
RETURNRCSTRING(InvalidArrayDef) \
RETURNRCSTRING(NumberError) \
RETURNRCSTRING(MissingSemi) \
RETURNRCSTRING(UndefinedError)
enum RC{
    #define RETURNRCSTRING(name)name,
    RETURNRCSTRINGS()
    #undef RETURNRCSTRING
};
string rc_string(RC rc);
//根结点
typedef class astTree{
public:
    Ast root;
    RC rc;
    vector<Ast> nodes;
    astTree()=default;
    astTree(Ast root):root(root){}
    void print();
}* AstTree;
AstTree NewTree(Ast root);




