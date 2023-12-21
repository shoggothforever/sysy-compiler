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
inline void astInfo(const Ast& node){
    printf("AstNodeInfo: name:%s val:%s line:%d\n",node->name.c_str(),node->val.c_str(),node->line);
}
inline void astChildInfo(const Ast& node){
    printf("%s's childs info:\n",node->name.c_str());
    int m=node->childs.size();
    for(int i=0;i<m;i++)astInfo(node->childs[i]);
}
void Stringsplit(const string& str, const string& split, vector<string>& res)
{
	char* strc = new char[str.size() + 1];
	strcpy(strc, str.c_str());   // 将str拷贝到 char类型的strc中
	char* temp = strtok(strc, split.c_str());
	while (temp != NULL)
	{
		res.push_back(string(temp));
		temp = strtok(NULL, split.c_str());	// 下一个被分割的串
	}
	delete[] strc;
}

/*------------------------------------------SEMANTIC CHECK Tools-----------------------------------------------*/

void through(Ast &node){
    while(node->childs.size()==1)node=node->childs[0];
}
void through_ArrayDef(Ast &node){
        int m=node->childs.size();
            for(int j=0;j<m;j++){
                Ast iter =node->childs[j];
                while(iter->childs.size()==1){
                    iter=iter->childs[0];
                    if(isNUMBER(iter)){
                        if(iter->childs.size()&&iter->childs[0]->name!="INT"){
                            if(DEBUG)printf("Error type 7 at Line %d: %s is not an INT.\n",iter->line,iter->val.c_str());
                            break;
                        }
                    }
                }
        }
}
void through_VarDefGroup(Ast &node,unordered_map<string,pair<string,string>>&mp ){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast iter = node->childs[i];
        through(iter);
        if(isVarDef(iter)){
            for(auto child :iter->childs){
                if(isArrayDef(child))through_ArrayDef(child);
            }
        }
        if (isIdent(iter)){
            Ast Type =node->childs[0];
            if(mp.find(iter->val)!=mp.end()){
                if(DEBUG)cout<<"find duplicated node "<<iter->name<<" value "<<iter->val<<" at line :"<<iter->line<<endl;
            }else if(func_map.find(iter->val)!=func_map.end()){
                if(DEBUG)cout<<"redeclared function node "<<iter->name<<" value "<<iter->val<<" as variable at line :"<<iter->line<<endl;

            }else{
                // cout <<"set map <string,string> < "<<iter->val<<" , "<<iter->name<<" >\n";
                mp[iter->val]=make_pair(Type->val,iter->val);
            }
        }else if (isVarDefGroup(iter)){
            through_VarDefGroup(iter,mp );
        }
     }
}
void through_FuncFparams(const Ast&node,string func_name){
    for (auto iter:node->childs){
        if(isFuncFparams(iter))through_FuncFparams(iter,func_name);
        if(isFuncFParam(iter)){
            // printf("function %s add a param %s\n",func_name.c_str(),iter->val.c_str());
            func_map[func_name].second.push_back(iter->val);
        }
    }
}
void through_Block(const Ast &node,const string& type,bool& isLoop,bool &isReturn ){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        through(child);

            if(isStmt(child)){
                // astChildInfo(child);
                string func_name;
                for(auto cc:child->childs){

                    through(cc);

                    if(isUnaryExp(cc)&&cc->childs.size()==4&&isFuncParamsGroup(cc->childs[2])){
                        func_name=cc->childs[0]->val;
                        vector<string>params;
                        Stringsplit(cc->childs[2]->val,",",params);
                        for(int j=0;j<params.size();j++){
                            //TODO:
                            if(DEBUG)cout<<"param : "<<params[j]<<" func: "<<func_name<<" size : "<<func_paramas[func_name].size()<<endl;
                            // cout<<"param : "<<params[j]<<" type "<<mp[params[j]].first<<endl;
                        }
                    }

                }
            }
            if(isFOR(child)){
                isLoop=true;
                continue;
            }
            if(isRETURN(child)){
                isReturn=true;
                Ast exp = node->childs[i+1];
                through(exp);
                if (exp->name!=type){
                    if(DEBUG)printf("return type %s is not the same as function defined %s at line :%d\n",exp->name.c_str(),type.c_str(),exp->line);
                }
                continue;
            }
            if((isCONTINUE(child)||isBREAK(child))&&!isLoop){
                if(DEBUG)printf("loop control keywords %s out of loop control block at line: %d\n",child->val.c_str(),child->line);
            }else if(isCB(child)){
                isLoop=false;
            }
            through_Block(child,type,isLoop,isReturn );
    }
}
void through_FuncDef(const Ast &node ){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        if (isCompUnit(child)){
            through_FuncDef(child);
            continue;
        }
        if(isFuncDef(child)){
        int m=child->childs.size();
        Ast Type,Func;
        Type=child->childs[0];
        Func=child->childs[1];
        if(func_set.find(Func->val)!=func_set.end()){
            if(DEBUG)printf("redeclared function of %s at line %d\n",Func->val.c_str(),Func->line);
        }else{
            if(DEBUG)func_set.insert(Func->val);
            func_map[Func->val]=make_pair(Type->val,vector<string>());
        }
        if(isFuncFparams(child->childs[3]))through_FuncFparams(child->childs[3],Func->val);
        bool isLoop = false;
        bool returned = false;
        through_Block(child->childs[4],Type->val,isLoop,returned);
        if(DEBUG){
            if(!returned&&Type->val!="VOID"){
            printf("return VOID is not the same as function defined %s\n",Type->val.c_str());
            }
        }
        }


    }
}
void through_variable(const Ast&node,unordered_map<string,pair<string,string>>&mp){
    int n=node->childs.size();
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        if(!isBLOCK(child)){
            if (isVarDecl(child)){
                through_VarDefGroup(child,mp);
                continue;
            }
            if(DEBUG){
                if (isStmt(child)){
                    int m=child->childs.size();
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
            }
            through_variable(child,mp);
        }else{
            unordered_map<string,pair<string,string>> block_mp;
            through_variable(child,block_mp);
        }
    }
    return ;
}
/*------------------------------------------SEMANTIC CHECK STRUCTURE-----------------------------------------------*/


/*------------------------------------------SEMANTIC CHECK FUNCTION-----------------------------------------------*/

// IsToken: 判断Token
#define IsToken(token) inline bool is##token(Ast& node) {return node->name==#token;}
IsTokens()
#undef IsToken

// check_variable 检查变量重复声明,变量未定义使用,变量赋值类型错误
void check_variable(const Ast& node){
    unordered_map<string,pair<string,string>>mp;
    through_variable(node,mp);
}
// check_function 检查main函数是否正确定义,函数有无重复或者嵌套定义
void check_function(const Ast& node){
    through_FuncDef(node);
    if(DEBUG){
        if(func_map["main"].first!="INT"){
            printf("missing int main function\n");
        }
        for (auto it:func_map){
            printf("defined function %s \n",it.first.c_str());
        }
    }


    return ;
}
void check(const Ast& node){
    check_variable(node);
    check_function(node);

}
// semantic_check: 语法分析入口函数
bool astTree::semantic_check(){
    if(!this->root)return false;
    DEBUG=0;
    check(this->root);
    DEBUG=1;
    check(this->root);

    return false;
}
