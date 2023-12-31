#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

class Node
{
public:
	string left;
	vector<string> right;
	Node() {}
	Node(string _left, vector<string>_right)
	{
		left = _left;
		right = _right;
	}
};

vector<Node> grammarVec;
vector<string> notend;
vector<set<string>> firstSet;

map<string, int> mp;

int cnt = 0;
Node mySplit(string s)//将输入的字符串分割成左右两部分
{
	string left;
	vector<string> right;
	left.clear();
	right.clear();
	left = s[0];
	string temp = "";
	for (int i = 3; i < s.size(); ++i)
	{
		if (s[i] == '|')
		{
			right.push_back(temp);
			temp = "";
			continue;
		}
		temp += s[i];
	}
	if (temp != "") right.push_back(temp);
	Node ret;
	ret.left = left;
	ret.right = right;
	return ret;
}

bool isNotend(string str)
{
	if (str[0] >= 'A' && str[0] <= 'Z') return true;
	return false;
}

void getNotend()//存储非终结符号
{
	notend.clear();
	vector<string> temp;
	for (int i = 0; i < grammarVec.size(); ++i)
	{
		temp.push_back(grammarVec[i].left);
		mp[grammarVec[i].left] = cnt++;
	}
	firstSet.resize(cnt);
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		cout << *iter << " ";
		notend.push_back(*iter);
	}
	cout << "\n";
}

void getInput()
{
	cout << "若一个非终结符号可以推出多个结果，请直接以|进行分隔\n";
	cout << "输入产生式，以$为结束标志:\n";
	string s;
	while (cin >> s)
	{
		if (s == "$") break;
		Node sentence = mySplit(s);
		grammarVec.push_back(sentence);
	}
}

void test(set<string> target)
{
	for (auto x: target)
	{
		cout << x << " ";
	}
	cout << "\n";
}

void getFirst(vector<Node>::iterator targetNode)
{
	string origNotend = (*targetNode).left;
	for (vector<string>::iterator it = (*targetNode).right.begin(); it != (*targetNode).right.end(); ++it)
	{
		string str = (*it).substr(0, 1);
		if (!isNotend(*it)) 
		{
			firstSet[mp[origNotend]].insert(str);
		}
		
		else
		{
			set<string> tempSet;
			for (vector<Node>::iterator it2 = grammarVec.begin(); it2 != grammarVec.end(); ++it2)
			{
				if ((*it2).left == str)
				{
					getFirst(it2);
					string targetNotend = (*it2).left;
					set_union( firstSet[mp[targetNotend]].begin(), firstSet[mp[targetNotend]].end(), tempSet.begin(), tempSet.end(), inserter(tempSet, tempSet.begin()));
					test(tempSet);
				}
			}
			set_union(tempSet.begin(), tempSet.end(), firstSet[mp[origNotend]].begin(), firstSet[mp[origNotend]].end(), inserter(firstSet[mp[origNotend]], firstSet[mp[origNotend]].begin()));
		}
	}
}

void getAllFirst()
{
	for (vector<Node>::iterator targetNode = grammarVec.begin(); targetNode != grammarVec.end(); ++targetNode)
	{
		getFirst(targetNode);
	}
}

void outPut()
{
	for (vector<Node>::iterator targetNode = grammarVec.begin(); targetNode != grammarVec.end(); ++targetNode)
	{
		string targetNotend = (*targetNode).left;
		cout << targetNotend << "'s first set:{";
		set<string>::iterator it = firstSet[mp[targetNotend]].begin();
		cout << *it;
		it++;
		for (it;it!=firstSet[mp[targetNotend]].end();++it)
		{
			cout << " " << *it;
		}
		cout << "}\n";
	}
}

int main()
{
	getInput();
	getNotend();
	getAllFirst();
	outPut();
	return 0;
}