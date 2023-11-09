#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<char, vector<string>> Grammar; // 假设 Grammar 是一个从非终结符映射到产生式的列表的映射
/* FIRST集的映射 */
map<char, set<char>> FIRST; // FIRST集的映射

/* 检查字符串是否包含空字符串 */
bool containsEpsilon(const set<char> &s)
{
    return s.find('$') != s.end();
}

/* 计算单个非终结符的FIRST集 */
void computeFirst(char symbol)
{
    // 如果已经计算过，直接返回
    if (FIRST.find(symbol) != FIRST.end())
        return;

    // 非终结符的产生式列表
    const auto &productions = Grammar[symbol];
    // 初始化FIRST集
    FIRST[symbol] = set<char>();

    for (const string &production : productions)
    {
        for (int i = 0; i < production.length(); ++i)
        {
            char beta = production[i];
            // 如果是终结符或者是空字符串，直接加入到FIRST集
            if (islower(beta) || beta == '$' || beta == '+' || beta == '*' || beta == '(' || beta == ')' || beta == '-' || beta == '/')
            {
                FIRST[symbol].insert(beta);
                break; // 退出循环
            }
            else
            {
                // 否则，计算非终结符beta的FIRST集
                computeFirst(beta);
                // 将FIRST(beta) - {ε} 加入到FIRST(symbol)
                for (char terminal : FIRST[beta])
                {
                    if (terminal != '$')
                    {
                        FIRST[symbol].insert(terminal);
                    }
                }
                // 如果FIRST(beta)不包含ε，停止
                if (!containsEpsilon(FIRST[beta]))
                    break;
                // 如果是最后一个符号，并且包含ε，则将ε加入到FIRST(symbol)
                if (i == production.length() - 1 && containsEpsilon(FIRST[beta]))
                {
                    FIRST[symbol].insert('$');
                }
            }
        }
    }
}

/* 计算整个文法的FIRST集 */
void computeFirstSets()
{
    for (const auto &nonterminal : Grammar)
    {
        computeFirst(nonterminal.first);
    }
}

/* 打印FIRST集 */
void printFirstSets()
{
    for (const auto &entry : FIRST)
    {
        cout << "FIRST(" << entry.first << ") = { ";
        for (char terminal : entry.second)
        {
            cout << terminal << " ";
        }
        cout << "}" << endl;
    }
}

int main()
{
    // 假定的文法输入
    Grammar['S'] = {"aBE"};
    Grammar['B'] = {"b", "$"};
    Grammar['E'] = {"eS", "f"};
    // S -> aBE
    // B -> b | ε
    // E -> eS | f


    computeFirstSets();
    printFirstSets();

    return 0;
}
