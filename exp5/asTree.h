#pragma once
#include <cstring>
#include<iostream>
#include<string>
#include<cstdarg>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::pair;

static unordered_map<string,vector<string>>func_paramas;
static unordered_map<string,vector<string>>func_params_type;
// key:函数名 value: pair<函数返回类型,vec<函数参数类型>>
static unordered_set<string>func_set;
static unordered_map<string,pair<string,vector<string>>>func_map;
static bool DEBUG = 0 ;
static int errorCnt=0;

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
/*------------------------------------------SEMANTIC CHECK STRUCTURE-----------------------------------------------*/




/*------------------------------------------SEMANTIC CHECK FUNCTION-----------------------------------------------*/
#define _TYPE_VARDECL "VarDecl"
#define _TYPE_VARIABLE "variable"
#define _TYPE_FUNCTION "FuncDef"
#define _TYPE_MAIN "main_function"
#define _TYPE_LVAL "LVal"

#define IsTokens()\
IsToken(BLOCK)\
IsToken(Decl)\
IsToken(VarDecl)\
IsToken(Ident)\
IsToken(NUMBER)\
IsToken(FuncDef)\
IsToken(FuncFparams)\
IsToken(FuncFParam)\
IsToken(CompUnit) \
IsToken(VarDef)\
IsToken(VarDefGroup)\
IsToken(BlockItem)\
IsToken(Stmt)\
IsToken(Exp)\
IsToken(UnaryExp)\
IsToken(AddExp)\
IsToken(FuncParamsGroup)\
IsToken(FOR)\
IsToken(RETURN)\
IsToken(CONTINUE)\
IsToken(WHILE)\
IsToken(BREAK)\
IsToken(CB)\
IsToken(SEMI)\
IsToken(ArrayDef)\



#define IsToken(token) inline bool is##token (Ast &node);
IsTokens()
#undef IsToken
void check_variable(const Ast& node);
void check_function(const Ast& node);
