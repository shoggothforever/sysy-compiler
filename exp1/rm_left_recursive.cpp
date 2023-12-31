#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<fstream>
#include <set>
#include <algorithm>
class Grammar {
public:
    void addRule(const std::string& left, const std::vector<std::vector<std::string>>& rights) {
        for (auto& right:rights) {
            rules[left].push_back(right);
        }
    }
    void eliminateIndirectLeftRecursion() {
        eliminateLeftRecursion();
        for (auto& rule : rules) {
            std::vector<std::string> nonTerminalsToReplace;
            for (const auto& right : rule.second) {
                if (!right.empty() && rules.find(right.front()) != rules.end()) {
                    nonTerminalsToReplace.push_back(right.front());
                }
            }

            for (const auto& nt : nonTerminalsToReplace) {
                std::vector<std::vector<std::string>> newRights;
                for (const auto& right : rule.second) {
                    if (right.front() != nt) {
                        newRights.push_back(right);
                    }
                    else {
                        for (const auto& ntRight : rules[nt]) {
                            std::vector<std::string> expandedRight = ntRight;
                            expandedRight.insert(expandedRight.end(), right.begin() + 1, right.end());
                            newRights.push_back(expandedRight);
                        }
                    }
                }
                rule.second = newRights;
            }
        }
        eliminateLeftRecursion();
        
    }

    void eliminateLeftRecursion() {
        for (auto& rule : rules) {
            auto left = rule.first;
            std::vector<std::vector<std::string>> newRights;
            std::vector<std::vector<std::string>> recursiveRights;

            for (auto& right : rule.second) {
                if (right.front() == left) {
                    right.erase(right.begin()); // Remove leftmost symbol
                    right.push_back(left + "'"); // Append new non-terminal
                    recursiveRights.push_back(right);
                }
                else {
                    newRights.push_back(right);
                }
            }

            if (!recursiveRights.empty()) {
                //
                for (auto& newRight : newRights) {
                    newRight.push_back(left + "'");
                }
                //
                rules[left] = newRights;
                recursiveRights.push_back({ "ε" }); // Add epsilon rule
                rules[left + "'"] = recursiveRights;
            }
        }
    }
    
    void extractLeftCommonFactor() {
        for (auto& rule : rules) {
            std::map<std::string, std::vector<std::vector<std::string>>> commonPrefixes;
            //std::map<std::string, std::vector<std::vector<std::string>>> commonPrefixes=findCommonPrefixes(rule.second);
            for (auto& right : rule.second) {
                if (!right.empty()) {
                    commonPrefixes[right.front()].push_back(right);
                }
            }
            if (commonPrefixes.size() == rule.second.size()) {
                continue; // 没有公共前缀
            }

            std::vector<std::vector<std::string>> newRights;

            for (auto& p : commonPrefixes) {
                if (p.second.size() == 1) {
                    newRights.push_back(p.second.front());
                }
                else {
                    std::string newLeft = rule.first + "'";
                    newRights.push_back({ p.first, newLeft });
                    //std::vector<std::vector<std::string>> newRules;
                    for (auto& seq : p.second) {
                        std::vector<std::string> newSeq(seq.begin() + 1, seq.end());
                        if (newSeq.empty()) {
                            newSeq.push_back("ε");
                        }
                        rules[newLeft].push_back(newSeq);
                    }
                    //rules[newLeft].push_back(newRules);
                }
            }
            rule.second = newRights;
        }
}
    void printGrammar() {
        for (auto& rule : rules) {
            if (rule.second.size() != 0) {
                std::cout << rule.first << " -> ";
                bool first = true;
                for (auto& right : rule.second) {
                    if (!first) {
                        std::cout << " | ";
                    }
                    first = false;
                    for (auto& symbol : right) {
                        std::cout << symbol << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
    void eliminateDirectLeftRecursion(const std::string& nonTerminal) {
        auto it = rules.find(nonTerminal);
        if (it == rules.end()) return;

        std::vector<std::vector<std::string>> recursiveProductions;
        std::vector<std::vector<std::string>> nonRecursiveProductions;

        // 分类产生式为递归和非递归
        for (const auto& production : it->second) {
            if (!production.empty() && production[0] == nonTerminal) {
                std::vector<std::string> newProduction(production.begin() + 1, production.end());
                newProduction.push_back(nonTerminal + "'");
                recursiveProductions.push_back(newProduction);
            }
            else {
                nonRecursiveProductions.push_back(production);
            }
        }

        if (recursiveProductions.empty()) return; // 没有直接左递归

        // 构建新的产生式
        std::vector<std::vector<std::string>> newProductions;
        for (const auto& production : nonRecursiveProductions) {
            std::vector<std::string> newProduction = production;
            newProduction.push_back(nonTerminal + "'");
            newProductions.push_back(newProduction);
        }

        // 更新文法规则
        rules[nonTerminal] = newProductions;
        recursiveProductions.push_back({ "ε" }); // 添加 epsilon
        rules[nonTerminal + "'"] = recursiveProductions;
    }

    std::map<std::string, std::vector<std::vector<std::string>>> rules;
    void removeRedundantProductions() {
        std::set<std::string> usedNonTerminals;

        // 第一步：识别所有被使用的非终结符
        for (const auto& rule : rules) {
            for (const auto& production : rule.second) {
                for (const std::string& symbol : production) {
                    if (rules.find(symbol) != rules.end()) { // 如果是非终结符
                        usedNonTerminals.insert(symbol);
                    }
                }
            }
        }

        // 第二步：删除未被使用的产生式
        for (auto it = rules.begin(); it != rules.end(); ) {
            if (usedNonTerminals.find(it->first) == usedNonTerminals.end()) {
                it = rules.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    
};

void test_g1() {
    Grammar g;
    g.addRule("A", { {"A", "b"},{"a", "y"}, {"b"},{"g"} });
    g.addRule("B", { {"a","b"},{"a","y"} });
    std::cout << "Original Grammar:" << std::endl;
    g.printGrammar();
    g.eliminateIndirectLeftRecursion();
    std::cout << "Grammar after eliminating left recursion:" << std::endl;
    g.printGrammar();
    g.extractLeftCommonFactor();
    std::cout << "Grammar after extract left common factor:" << std::endl;
    g.printGrammar();
    g.removeRedundantProductions();
    std::cout << "Grammar remove redundant productions:" << std::endl;
    g.printGrammar();
}
void test_g2() {
    Grammar g;
    g.addRule("S", { {"A","c"},{"c"}});
    g.addRule("A", { {"B","b"},{"b"}});
    g.addRule("B", { {"S","a"},{"a"}});
    std::cout << "Original Grammar:" << std::endl;
    g.printGrammar();
    g.eliminateIndirectLeftRecursion();
    std::cout << "Grammar after eliminating left recursion:" << std::endl;
    g.printGrammar();
    g.extractLeftCommonFactor();
    std::cout << "Grammar after extract left common factor:" << std::endl;
    g.printGrammar();
    g.removeRedundantProductions();
    std::cout << "Grammar remove redundant productions:" << std::endl;
    g.printGrammar();
}
void test_g3() {
    Grammar g;

       g.addRule("F", { {"(","E",")"},{"i"} });
       g.addRule("E", { {"E","T","+"},{"E","T","-"},{"T"} });
       g.addRule("T", { {"T","F","*"},{"T","F","/"},{"F"} });


    std::cout << "Original Grammar:" << std::endl;
    g.printGrammar();
    g.eliminateIndirectLeftRecursion();
    std::cout << "Grammar after eliminating left recursion:" << std::endl;
    g.printGrammar();
    g.extractLeftCommonFactor();
    std::cout << "Grammar after extract left common factor:" << std::endl;
    g.printGrammar();
    g.removeRedundantProductions();
    std::cout << "Grammar remove redundant productions:" << std::endl;
    g.printGrammar();
}
int main() {

    test_g1();
    printf("\n");
    test_g2();
    printf("\n");
    test_g3();
    printf("\n");
    return 0;


}
