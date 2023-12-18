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
        //需要打印更多节点信息可以把这个if注释掉
        // if (this->childs.size()==0){
        if(! this->declByFlex){
            std::cout<<tab<<"[Grammatical unit] layer: ("<<layer<<") line: ("<<this->line<<") name: ("<<this->name<<") val: "<<this->val<<"\n";
        }
        else {
            if(this->name=="Ident")std::cout<<tab<<"[Lexical     unit] layer: ("<<layer<<") line: ("<<this->line<<") name:"<<this->name<<" val:"<<this->val<<"\n";
            else {std::cout<<tab<<"[Lexical     unit] layer: ("<<layer<<") name:("<<this->name<<")\n";}
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
        // cout<<"insert (key: "<<tmp->name<<" val: "<<tmp->val<<") into parent (" <<node->name<<")\n";
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

/*------------------------------------------SEMANTIC CHECK Tools-----------------------------------------------*/
void through(Ast &node){
    while(node->childs.size()==1)node=node->childs[0];
}
void through_VarDefGroup(Ast &node,unordered_map<string,pair<string,string>>&mp){
    // cout<<"through_VarDefGroup"<<endl;
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast iter = node->childs[i];
        through(iter);
        if (isIdent(iter)){
            Ast Type =node->childs[0];
            if(mp.find(iter->val)!=mp.end()){
                cout<<"find duplicate node "<<iter->name<<" value "<<iter->val<<endl;
            }else{
                // cout <<"set map <string,string> < "<<iter->val<<" , "<<iter->name<<" >\n";
                mp[iter->val]=make_pair(Type->val,iter->val);
            }
        }else if (isVarDefGroup(iter)){
            through_VarDefGroup(iter,mp);
        }
     }
}
void through_Block(const Ast &node,const string& type,bool& isLoop,bool &isReturn){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        through(child);
            if(isFOR(child)){
                isLoop=true;
                continue;
            }
            if(isRETURN(child)){
                isReturn=true;
                Ast exp = node->childs[i+1];
                through(exp);
                if (exp->name!=type){
                    printf("return type %s is not the same as function defined %s at line :%d\n",exp->name.c_str(),type.c_str(),exp->line);
                }
                continue;
            }
            if((isCONTINUE(child)||isBREAK(child))&&!isLoop){
                printf("loop control keywords %s out of loop control block at line: %d\n",child->val.c_str(),child->line);
            }else if(isCB(child)){
                isLoop=false;
            }
            through_Block(child,type,isLoop,isReturn);
    }

}
void through_FuncDef(const Ast &node,unordered_map<string,pair<string,string>>&mp){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        if (isCompUnit(child)){
            through_FuncDef(child,mp);
            continue;
        }
        if(isFuncDef(child)){
            cout<<"check CompUnit\n";
        int m=child->childs.size();
        Ast Type,Func;
        Type=child->childs[0];
        Func=child->childs[1];
        if(mp.find(Func->val)!=mp.end()){
            printf("redeclared function of %s at line %d\n",Func->val.c_str(),Func->line);
        }
        mp[Func->val]=make_pair(Type->val,Func->val);
        bool isLoop = false;
        bool returned = false;
        through_Block(child->childs[4],Type->val,isLoop,returned);
        if(!returned&&Type->val!="VOID"){
           printf("return VOID is not the same as function defined %s\n",Type->val.c_str());
        }
        }

    }
}

/*------------------------------------------SEMANTIC CHECK STRUCTURE-----------------------------------------------*/


/*------------------------------------------SEMANTIC CHECK FUNCTION-----------------------------------------------*/
// semantic_check: 语法分析入口函数
bool astTree::semantic_check(){
    if(!this->root)return false;
    unordered_map<string,pair<string,string>>mp;
    check_variable(this->root,mp);
    check_function(this->root);
    return false;
}
// IsToken: 判断Token
#define IsToken(token) inline bool is##token(Ast& node) {return node->name==#token;}
IsTokens()
#undef IsToken

// check_variable 检查变量重复声明,变量未定义使用,变量赋值类型错误
void check_variable(const Ast& node,unordered_map<string,pair<string,string>>&mp){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        if(!isBLOCK(child)){
            if (isVarDecl(child)){
                through_VarDefGroup(child,mp);
                continue;
            }
            if (isStmt(child)){
                int m=child->childs.size();
                // cout<<"check Stmt childs size "<<m<<"\n";
                if(m==3){
                    // cout<<"get 3 childs\n";
                    Ast lval=child->childs[0];
                    through(lval);
                    Ast rval=child->childs[2];
                    through(rval);
                    if(isIdent(lval)&&isIdent(rval)){
                        if(mp[lval->val].first != mp[rval->val].first){
                            cout<<"mismatched variable assign "<<mp[lval->val].first<<" "<<lval->val<<" and "<<mp[rval->val].first<<" "<<rval->val<<" at line: "<<lval->line<<endl;
                        }
                    }
                }
                for(int j=0;j<m;j++){
                    Ast iter = child->childs[j];
                    through(iter);
                    if (isIdent(iter)){
                        if(mp.find(iter->val)==mp.end()){
                            cout<<"undefined variable "<<iter->val<<" at line: "<<iter->line<<endl;;
                        }
                    }
                }
            }
            check_variable(child,mp);
        }else{
            unordered_map<string,pair<string,string>> block_mp;
            check_variable(child,block_mp);
        }
    }
    return ;
}
// check_function 检查main函数是否正确定义,函数有无重复或者嵌套定义
void check_function(const Ast& node){
    unordered_map<string,pair<string,string>>mp;
    through_FuncDef(node,mp);
    if(mp["main"].first!="INT"){
        printf("miss int main function\n");
    }
    return ;
}
