#pragma once
#include <map>
#include <utility>
#include<iostream>
#include<fstream>
#include <string.h>
#include<string>
#include <stack>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
#define PII pair<int,int>
#define PCI pair<char,int>
#define VPI vector<PII>
#define VPC vector<PCI>

static vector<VPI>INIT_GRAPH{ {} };
#define DEFINE_ENUMS() \
ENUM(UNDEFINED) \
ENUM(ZERO_ANY_MATCH)\
ENUM(ONE_ANY_MATCH)\
ENUM(ZERO_ONE_MATCH)\
ENUM(ANY_CHAR)\
ENUM(HEAD_MATCH)\
ENUM(BACK_MATCH)\
ENUM(OR)\
ENUM(LBRACE)\
ENUM(RBRACE)\
ENUM(AND)

const char AND_CHAR = '_';

using state = int;
template<typename T>
bool operator==(vector<T>a,vector<T>b) {
	if (a.size() != b.size())return false;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}
struct vector_hash {
	std::size_t operator()(std::vector<int> vec) const {
		std::size_t seed = vec.size();
		for (auto& i : vec) {
			seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};
int find(vector<int>& v, int x);
class nfa
{	
public: 

	nfa() = default;
	nfa(string name, string regex);
	string name_;
	string regex_;
	string regex_post_;
	state start_, end_;
	vector<VPI>graph_;
	int iterator;
	virtual bool build();
	virtual int next();
	struct char_hash {
		std::size_t operator()(char ch) const {
			size_t seed = 0;
			seed ^= ch + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
	std::unordered_set<int>chs;
private:
	string regex_to_postfix(string regex);
	string regex_post() { return regex_post_; }



};


enum class REGEX_OP_TYPE {
	UNDEFINED = 'x',
	ZERO_ANY_MATCH = '*',
	ONE_ANY_MATCH = '+',
	ZERO_ONE_MATCH = '?',
	ANY_CHAR = '.',
	HEAD_MATCH = '^',
	BACK_MATCH = '$',
	OR = '|',
	LBRACE = '(',
	RBRACE = ')',
	AND = AND_CHAR,			  ///< '_'
};
enum class REGEX_OP_PRIORITY {
#define PRI(name,pri) name##_PRIORITY=pri ,
	PRI(UNDEFINED,-1)
	PRI(ZERO_ANY_MATCH,3)\
	PRI(ONE_ANY_MATCH,4)\
	PRI(ZERO_ONE_MATCH,4)\
	PRI(ANY_CHAR,5)\
	PRI(HEAD_MATCH,6)\
	PRI(BACK_MATCH,7)\
	PRI(OR,1)\
	PRI(LBRACE,0)\
	PRI(RBRACE,0)\
	PRI(AND,2)
#undef PRI
};
REGEX_OP_PRIORITY regex_op_priority(char op);
bool priority_lt(char l_op, char r_op);
class dfa :public nfa
{
public:
	dfa() = default;
	dfa(string name, string regex);
	dfa(nfa* nfa);
	void print();
	bool build();
	std::unordered_map<int, VPC>dfa_graph_;
	std::unordered_map<int, VPC>min_dfa_graph_;
	void dfs_move(int num,char ch, vector<int>& v,vector<bool>&vis);
	std::unordered_map<int, VPC> get_min_dfa();
	string dfa_to_dot(string name);
	void print_dfa(std::unordered_map<int, VPC>&graph);
private:
	nfa nfa_;

	std::unordered_set<vector<int>,vector_hash>state_set_;
	std::unordered_map<int,vector<int>>state_map_;
	std::unordered_map<vector<int>,int, vector_hash>state_map_reverse_;
};

