// 错误类型5：把变量当做函数调⽤，如对普通变量使⽤括号(...)或()运算符（当函数调⽤），
// 错误类型9：函数调⽤时参数个数或类型不匹配
void b(int a){}
void test(int a,int c,float){}
int main(){
    a();
    b=1;
    return 1;
}
// use variable a as function at line: 6
// use function b as variable at line: 7
