// 错误类型1：变量未声明
// 错误类型2：变量重复声明
// 错误类型4：函数重复定义（同样的函数名出现了不⽌⼀次定义）
// 错误类型10：return语句返回的类型与函数定义的返回类型不匹配
// 错误类型12：break语句不在循环体内
// 错误类型13：continue语句不在循环体内
// 特性1：⼀个SysY程序由单个⽂件构成，⽂件内容对应语法单元为CompUnit，其中必须存在⼀个标识符为main、⽆参数、返回类型为int的FuncDef（函数定义）
int main(){
    int a;
    return a;
}
void test(){
    int a;
}
int test(){
    int a;
    float b;
    i=5;
    while(true){
        break;
        continue;
    }
    break;
    continue;
    return "3.3";
}
// find duplicated node Ident value a at line :10
// undefined variable i at line: 19
// return type Ident is not the same as function defined INT at line :11
// redeclared function of test at line 16
// loop control keywords break out of loop control block at line: 24
// loop control keywords continue out of loop control block at line: 25
// return type STR is not the same as function defined INT at line :26
