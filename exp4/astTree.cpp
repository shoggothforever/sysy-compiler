#include "astTree.h"

 void astTree:: print(){
        if(! this->root){
            std::cout<<"parse not complete!\n";
            return;
        }
        std::cout<<"pre order print\n";
        std::cout<<"layer: "<<1<<" name:"<<root->name<<" val:"<<root->val<<"\n";
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
            tab=tab+"   ";
        for (auto v:this->childs){
            std::cout<<tab<<"layer: "<<layer<<" name:"<<v->name<<" val:"<<v->val<<"\n";
            v->print(tab,layer+1);
        }
}
Ast NewAst(string name,int line,int num,...){
    Ast node = new astNode(name,name,line);
    std::cout<<"create (key: "<<node->name<<" val: "<<node->val<<")\n";
    va_list list;
    va_start(list,num);
    Ast tmp;
    if (num>0){
        for(int i=0;i<num;i++){
        tmp=va_arg(list,Ast);
        std::cout<<"insert (key: "<<tmp->name<<" val: "<<tmp->val<<") into parent (" <<node->name<<")\n";
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
