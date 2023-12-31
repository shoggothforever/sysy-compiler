#include "astTree.h"

 void astTree:: print(){
        if(! this->root){
            std::cout<<"parse not complete!\n";
            return;
        }
        std::cout<<"pre order print\n";
        if(!root->declByFlex){
                std::cout<<"[Grammatical unit] layer: ("<<1<<") line: ("<<root->line<<") name: ("<<root->name<<") val: "<<root->val<<"\n";
        }
        // std::cout<<"layer: "<<1<<" name:"<<root->name<<" val:"<<root->val<<"\n";
        this->root->print("",2);
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
void astNode::print(string tab,int layer){
        if (this->childs.size()==0){
            if(! this->declByFlex){
                std::cout<<tab<<"[Grammatical unit] layer: ("<<layer<<") line: ("<<this->line<<") name: ("<<this->name<<") val: "<<this->val<<"\n";
            }
            else {
                if(this->name=="Ident")std::cout<<tab<<"[Lexical unit] layer: ("<<layer<<") line: ("<<this->line<<") name:"<<this->name<<" val:"<<this->val<<"\n";
                else {std::cout<<tab<<"[Lexical unit] layer: ("<<layer<<") name:("<<this->name<<")\n";}
            }
        }
        else if(this->childs.size()==1){
             this->childs[0]->print(tab,layer);
        }
        else{
            for (auto v:this->childs){
                v->print(tab+"  ",layer+1);
            }
        }
}
Ast NewAst(string name,int line,int num,...){
    Ast node = new astNode(name,name,line);
    // std::cout<<"create (key: "<<node->name<<" val: "<<node->val<<")\n";
    va_list list;
    va_start(list,num);
    Ast tmp;
    if (num>0){
        for(int i=0;i<num;i++){
        tmp=va_arg(list,Ast);
        // std::cout<<"insert (key: "<<tmp->name<<" val: "<<tmp->val<<") into parent (" <<node->name<<")\n";
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
        tmp=va_arg(list,Ast);
        node->childs.push_back(tmp);
    }

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
