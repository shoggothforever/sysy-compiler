#include "astTree.h"

using namespace std;

void astTree:: print(){
        if(! this->root){
            std::cout<<"parse not complete!\n";
            return;
        }
        std::cout<<"pre order print\n";
        this->root->print("",1);
    }
AstTree NewTree(Ast root){
    AstTree tree=new astTree(root);
    return tree;
}
class astNode;
astNode::astNode(string name,string val,int line):
line(line),
name(name),
val(val){}
// print: dfs打印语法生成树节点信息
void astNode::print(string tab,int layer){
        // if (this->childs.size()==0){
        if(! this->declByFlex){
            std::cout<<tab<<"[Grammatical unit] layer: ("<<layer<<") line: ("<<this->line<<") name: ("<<this->name<<") val: "<<this->val<<"\n";
        }
        else {
            if(this->name=="Ident")std::cout<<tab<<"[Lexical unit] layer: ("<<layer<<") line: ("<<this->line<<") name:"<<this->name<<" val:"<<this->val<<"\n";
            else {std::cout<<tab<<"[Lexical unit] layer: ("<<layer<<") name:("<<this->name<<")\n";}
        }
        // }
        if(this->childs.size()==1){
            this->childs[0]->print(tab,layer);
        }
        else if(this->childs.size()>1){
            if(!this->isRoot){
                for (auto v:this->childs){
                    v->print(tab+"  ",layer+1);
                }
            }
            else {
                for (auto v:this->childs){
                    v->print(tab,layer);
                }
            }
        }
}


Ast NewAst(string name,int line,int num,...){
    Ast node = new astNode(name,name,line);
    // cout<<"create (key: "<<node->name<<" val: "<<node->val<<")\n";
    va_list list;
    va_start(list,num);
    Ast tmp;
    if (num>0){
        for(int i=0;i<num;i++){
        tmp=va_arg(list,Ast);
        // cout<<"insert (key: "<<tmp->name<<" val: "<<tmp->val<<") into parent (" <<node->name<<")\n";
        node->childs.push_back(tmp);
        }
    }
    va_end(list);
    return node;
}

Ast NewAst(string name,string val,int line,int num,...){
    Ast node = new astNode(name,val,line);
    va_list list;
    va_start(list,num);
    Ast tmp;
    if (num>0){
        for(int i=0;i<num;i++){
        tmp=va_arg(list,Ast);
        node->childs.push_back(tmp);
        }
    }
    va_end(list);
    return node;
}
string rc_string(RC rc){
    switch (rc){
        #define RETURNRCSTRING(name)case name:return #name;
        RETURNRCSTRINGS()
        #undef RETURNRCSTRING
        default:return "UndefinedError";
    }
}

/*------------------------------------------SEMANTIC CHECK FUNCTION-----------------------------------------------*/
// semantic_check: 语法分析入口函数
bool astTree::semantic_check(){
    if(!this->root)return false;
    unordered_map<string,string>mp;
    check_variable(this->root,mp);

    return false;
}


inline bool isNewScopeType(Ast node){
    if (node->name== "BLOCK"){
        return true;
    }
    return false;
}
inline bool isID(Ast node){
    return node->name=="Ident";
}
//检查变量重复声明,变量未定义使用
bool check_variable(const Ast& node,unordered_map<string,string>&mp){
        int n=node->childs.size();
        for (int i=0;i<n;i++){
        Ast p=node->childs[i];
        if(!isNewScopeType(p)){
            if(isID(p)){
            if(mp.find(p->val)!=mp.end()){
                if(i>0&&node->childs[i-1]->name!=_TYPE_LVAL)cout<<"find duplicate node "<<p->name<<" value "<<p->val<<endl;
                // return false;
            }else{
                // cout <<"set map <string,string> < "<<p->val<<" , "<<p->name<<" >\n";
                mp[p->val]=p->name;
            }
            }
            if(p->name==_TYPE_LVAL){
                cout<<"get LVal "<<p->val<<endl;
                // cout<<mp[p->val]<<endl;
                if(mp.find(p->val)==mp.end()){
                    cout<<"find undefined node "<<p->name<<" value "<<p->val<<endl;
                }
            }
            check_variable(node,mp);
        }else{
            unordered_map<string,string> block_mp;
            check_variable(node,block_mp);
            }
        }
        return true;
}
