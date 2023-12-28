#include "asTree.h"

using namespace std;
ofstream out_file;
void open_output_file(const std::string &filename)
{
  out_file.open(filename);
  if (!out_file.is_open())
  {
    std::cerr << "Error open file:" << filename << std::endl;
  }
}

void write_to_output(const std::string &text)
{
//   std::cout << text;
  if (out_file.is_open())
  {
    out_file << text;
  }
}
astTree::astTree(Ast root):root(root){}
void astTree:: print(){
        if(! this->root){
            std::cout<<"parse not complete!\n";
            return;
        }
        open_output_file(OUTPUT_FILE);
        this->root->print("",1);
}




astNode::astNode(string name,string val,int line):
line(line),
name(name),
val(val){}

// print: dfs打印语法生成树节点信息
void astNode::print(string tab,int layer){
        std::string output_line;
        string grammar="Grammatical";
        string lexical="Lexical";
        //需要打印更多节点信息可以把这个if注释掉
        // if (this->childs.size()==0){
        if(!this->declByFlex){
            if(this->name!=this->val){
                output_line =tab + "source: (" + grammar + ") layer: (" + std::to_string(layer) + ") line: (" + std::to_string(this->line) + ") name: " + this->name + " val: " + this->val + "\n";
            // std::cout<<tab<<"[Grammatical unit] layer: ("<<layer<<") line: ("<<this->line<<") name: ("<<this->name<<") val: "<<this->val<<"\n";
            }else{
                output_line = tab + "source: (" + grammar + ") layer: (" + std::to_string(layer) + ") name: (" + this->name + ")\n";
            }
        }
        else {
            if(this->name!=this->val){
                output_line =tab + "source: (" + lexical + ") layer: (" + std::to_string(layer) + ") line: (" + std::to_string(this->line) + ") name: " + this->name + " val: " + this->val + "\n";
                // std::cout<<tab<<"[Lexical     unit] layer: ("<<layer<<") line: ("<<this->line<<") name: ("<<this->name<<") val: "<<this->val<<"\n";
            }
            else {
                output_line = tab + "source: (" + lexical + ") layer: (" + std::to_string(layer) + ") name: (" + this->name + ")\n";
                // std::cout<<tab<<"[Lexical     unit] layer: ("<<layer<<") name: ("<<this->name<<")\n";
            }
        }
        write_to_output(output_line);
        // }
        for (auto v:this->childs){
            v->print(tab+" ",layer+1);
        }
        // if(this->childs.size()==1){
        //     this->childs[0]->print(tab+" ",layer+1);
        // }
        // else if(this->childs.size()>1){
        //     if(!this->isRoot){
        //         for (auto v:this->childs){
        //             v->print(tab+" ",layer+1);
        //         }
        //     }
        //     else {
        //         for (auto v:this->childs){
        //             v->print(tab,layer);
        //         }
        //     }
        // }
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
    printf("AstNodeInfo: name:%s val:%s line:%d children's num:%ld\n",node->name.c_str(),node->val.c_str(),node->line,node->childs.size());
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

    while(node->childs.size()==1||node->childs.size()==2&&isSEMI(node->childs[1])){
        node=node->childs[0];
    }
}
void through_ArrayDef(Ast &node){
        int m=node->childs.size();
            for(int j=0;j<m;j++){
                Ast iter =node->childs[j];
                if(isNUMBER(iter)){
                    if(iter->childs.size()&&iter->childs[0]->name!="INT"){
                        if(DEBUG){
                            ++errorCnt;
                            printf("[ERR] at Line %d: Array length %s is not INT.\n",iter->line,iter->val.c_str());
                        }
                        break;
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
                if(isArrayDef(child)){
                    through_ArrayDef(child);
                }
            }
        }
        if (isIdent(iter)){
            Ast Type =node->childs[0];
            if(mp.find(iter->val)!=mp.end()){
                if(DEBUG){
                    ++errorCnt;
                    cout<<"[ERR] find duplicated node "<<iter->name<<" value "<<iter->val<<" at line :"<<iter->line<<endl;
                }
            }else if(func_map.find(iter->val)!=func_map.end()){
                if(DEBUG){
                    ++errorCnt;
                    cout<<"[ERR] redeclared function node "<<iter->name<<" value "<<iter->val<<" as variable at line :"<<iter->line<<endl;
                }

            }else{
                if(DEBUG){
                    // cout <<"set map <string,string> < "<<iter->val<<" , "<<iter->name<<" > at line: "<<iter->line<<"\n";
                    mp[iter->val]=make_pair(Type->val,iter->val);
                }
            }
        }else if (isVarDefGroup(iter)){
            through_VarDefGroup(iter,mp );
        }
     }
}
void through_FuncFparams(const Ast&node,string func_name,bool isDefined){
    for (auto iter:node->childs){
        if(isFuncFparams(iter))through_FuncFparams(iter,func_name,isDefined);
        if(isFuncFParam(iter)){
            if(!isDefined){
                // printf("function %s add a param %s\n",func_name.c_str(),iter->val.c_str());
                func_map[func_name].second.push_back(iter->val);
            }
        }
    }
}

void through_Block_Inner(const Ast &node,const string& type,bool& isLoop,bool &isReturn,unordered_map<string,pair<string,string>>&mp){
    int n=node->childs.size();
    if (node->name=="FuncDef"){
        printf("[ERR] declare function in the function at line : %d",node->line);
        return;
    }
    for (int i=0;i<n;i++){
        Ast child=node->childs[i];
        // through(child);
            if(isStmt(child)){
                string func_name;
                for(auto cc:child->childs){
                    through(cc);
                    if(isUnaryExp(cc)&&cc->childs.size()==4&&isFuncParamsGroup(cc->childs[2])){
                        func_name=cc->childs[0]->val;
                        vector<string>params;
                        Stringsplit(cc->childs[2]->val,",",params);
                        for(int j=0;j<params.size();j++){
                            //TODO:函数参数类型与数量检测
                            // if(DEBUG)cout<<"param : "<<params[j]<<" func: "<<func_name<<" size : "<<func_paramas[func_name].size()<<endl;
                        }
                    }

                }
            }
            if(isFOR(child)||isWHILE(child)){
                isLoop=true;
                continue;
            }else if(isRETURN(child)){
                isReturn=true;
                Ast exp = node->childs[i+1];
                through(exp);
                if (exp->name!=type){
                    if(DEBUG){
                        if(mp.find(exp->val)!=mp.end()){
                            if (mp[exp->val].first==type)continue;
                        }
                        ++errorCnt;
                        printf("[ERR] return value %s's type is not the same as function defined %s at line :%d\n",exp->val.c_str(),type.c_str(),exp->line);
                    }
                }
                continue;
            }else if((isCONTINUE(child)||isBREAK(child))&&!isLoop){
                if(DEBUG){
                    ++errorCnt;
                    printf("[ERR] loop control keywords %s out of loop control block at line: %d\n",child->val.c_str(),child->line);
                }
            }else if(isCB(child)){
                isLoop=false;
            }else if(isVarDecl(child)){
                // printf("get vardecl ");astChildInfo(child);
                auto variable=child->childs[1]->val;
                auto Type=child->childs[0]->val;
                mp[variable]=make_pair(Type,variable);
            }
            through_Block_Inner(child,type,isLoop,isReturn,mp);
    }
}
void through_Block(const Ast &node,const string& type,bool& isLoop,bool &isReturn ){
    unordered_map<string,pair<string,string>>mp;
    through_Block_Inner(node,type,isLoop,isReturn,mp);
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
            // if(DEBUG)astChildInfo(child);
            int m=child->childs.size();
            Ast Type,Func;
            Type=child->childs[0];
            Func=child->childs[1];
            if(func_set.find(Func->val)!=func_set.end()){
                if(DEBUG){
                    ++errorCnt;
                    printf("[ERR] redeclared function of %s at line %d\n",Func->val.c_str(),Func->line);
                }
            }else{
                if(DEBUG)func_set.insert(Func->val);
                func_map[Func->val]=make_pair(Type->val,vector<string>());
            }
            if(isFuncFparams(child->childs[3])){
                // if(DEBUG)cout<<"deal with function's params\n";
                through_FuncFparams(child->childs[3],Func->val,func_set.find(Func->val)!=func_set.end());
            }
            bool isLoop = false;
            bool returned = false;
            through_Block(child->childs[4],Type->val,isLoop,returned);
            if(DEBUG){
                if(!returned&&Type->val!="VOID"){
                    ++errorCnt;
                    printf("[ERR] return VOID is not the same as function defined %s\n",Type->val.c_str());
                }
            }
        }


    }
}
bool through_AddExp(const Ast &node,unordered_map<string,pair<string,string>>&mp){
    int n=node->childs.size();
    if(n==0)return false;
    Ast lval=node->childs[0];
    through(lval);
    if(isAddExp(lval)){
        return through_AddExp(lval,mp);
    }
    for(int k=2;k<n;k+=2){
        Ast rval=node->childs[k];
        through(rval);
        if(isIdent(lval)&&isIdent(rval)){
            if(mp[lval->val].first != mp[rval->val].first){
                ++errorCnt;
                printf("[ERR] variable arithmetic expressions mismatch at line: %d\n",lval->line);
                break;
            }
        }
    }
    return true;
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
                    through(child);
                    int m=child->childs.size();
                    if(m>0){
                        Ast lval=child->childs[0];
                        through(lval);
                        string type = mp[lval->val].first;
                        if(isAddExp(child)){
                            through_AddExp(child,mp);
                        }else {
                            for(int k=2;k<m;k+=2){
                                Ast rval=child->childs[k];
                                through(rval);
                                if(isIdent(lval)&&isIdent(rval)){
                                    if(mp[lval->val].first != mp[rval->val].first){
                                        ++errorCnt;
                                        printf("[ERR] variable arithmetic expressions mismatch at line: %d\n",lval->line);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (m==3){
                        Ast ident=child->childs[0];
                        Ast L=child->childs[1];
                        Ast R=child->childs[2];
                        if(L->name=="L"&&R->name=="R"&&func_map.find(ident->val)==func_map.end()){
                            errorCnt++;
                            printf("[ERR] use variable %s as function at line: %d\n",ident->val.c_str(),ident->line);
                        }
                    }
                    for(int j=0;j<m;j++){
                        Ast iter = child->childs[j];
                        through(iter);
                        if (isIdent(iter)){
                            if(mp.find(iter->val)==mp.end()||mp[iter->val].first==""){
                                if(func_set.find(iter->val)!=func_set.end()){
                                    ++errorCnt;
                                    printf("[ERR] use function %s as variable at line: %d\n",iter->val.c_str(),iter->line);
                                }
                                else {
                                    ++errorCnt;
                                    cout<<"[ERR] undefined variable "<<iter->val<<" at line: "<<iter->line<<endl;
                                }
                            }
                        }
                        if(isUnaryExp(iter)){
                            int k=iter->childs.size();
                            if (k==3){
                                Ast ident=iter->childs[0];
                                Ast L=iter->childs[1];
                                Ast R=iter->childs[2];
                                if(L->name=="L"&&R->name=="R"&&func_map.find(ident->val)==func_map.end()){
                                    errorCnt++;
                                    printf("[ERR] use variable %s as function at line: %d\n",ident->val.c_str(),ident->line);
                                }
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
            ++errorCnt;
            printf("[ERR] missing int main function\n");
        }
        // for (auto it:func_map){
        //     printf("defined function %s \n",it.first.c_str());
        // }
    }


    return ;
}
void check(const Ast& node){
    check_function(node);
    check_variable(node);

}
// semantic_check: 语法分析入口函数
bool astTree::semantic_check(){
    if(!this->root)return false;
    errorCnt=0;
    DEBUG=0;
    check(this->root);

    DEBUG=1;
    check(this->root);
    cout<<"get "<<errorCnt<<" errors\n";
    return false;
}
