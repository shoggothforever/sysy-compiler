#pragma once
#include<bits/stdc++.h>
using namespace std;
struct kvs{
	string key;
	set<string>projects;
};
class RM {
public:
	RM() = default;

public:
	vector<kvs>kvs_;
	vector<string>not_end_keys_;
	void get_kvs();
	void run();
	void clean();
	kvs split(string str);
	void get_not_end();
	bool check_all_end(string str);
	void rm_direct_recurse(int pos);
	string replace(string str, string ori, string another) {
		int pos = -1;
		while (str.find(ori) != -1) {
			pos = str.find(ori);
			str.replace(pos, ori.size(), another);
		}
		return str;
	}
};
