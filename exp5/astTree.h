#pragma once
#include <cstring>
#include<iostream>
#include<string>
#include<cstdarg>
#include<unordered_map>
#include<vector>
using std::string;
using std::vector;
using std::unordered_map;



typedef class astNode{
public:
    int line;
    int scopeLevel;
    string name;
    string val;
    vector<astNode*>childs;
    bool declByFlex;
    bool isRoot;
    union{
        int intval;
        float floatval;
        bool boolval;
        string stringval;
    };

    astNode(string name,string val,int line);
    void print(string tab,int layer);
    friend bool operator== (const astNode&a ,const astNode&b){
        return a.name==b.name&&a.val==b.val;
    }

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
    bool semantic_check();
}* AstTree;
AstTree NewTree(Ast root);


/*------------------------------------------SEMANTIC CHECK FUNCTION-----------------------------------------------*/
#define _TYPE_VARIABLE "variable"
#define _TYPE_FUNCTION "function"
#define _TYPE_MAIN "main_function"
#define _TYPE_LVAL "LVal"
bool isNewScopeType(Ast node);
bool isID(astNode* node);
bool check_variable(const Ast& node,unordered_map<string,string>&mp);

