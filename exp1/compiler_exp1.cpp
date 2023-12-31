

#include "nfa.h"
#include "rm_recurse.h"
using std::cout;
void test_1_2() {
    //输入不包含"."只包含"*","|","()"的正则表达式
//string re = "(bison|yacc)*(taby|tabl)gcc";
    //string re = "(a|b)*(a|b)";
    //string re = "(a|b)*(a|b)";
    string re = "(a|b)*(aa|b)";
    nfa* atbot = new nfa("bot", re);
    atbot->build();
    dfa* DFA = new dfa(atbot);
    DFA->build();
    DFA->get_min_dfa();
    auto dot = DFA->dfa_to_dot(re);
    std::ofstream ofile("D:\\desktop\\draft\\dfa1.dot");
    ofile << dot;
    ofile.close();
    cout << dot << "\n";
    //dot -Tpng ./dfa1.dot -o dfa1.png
    //open dfa1.png
}

void test_3() {
    RM builder;
    builder.run();
}
int main()
{
    test_1_2();
    test_3();


}
