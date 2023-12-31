#include"rm_recurse.h"


void RM::clean() {

}
void RM::run() {
	get_kvs();
	get_not_end();
	int n = not_end_keys_.size();
	cout << "n:" << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int pi = -1, pj = -1;
			for (int k = 0; k < n; k++) {
				if (not_end_keys_[k] == kvs_[i].key) {
					pi = k;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (not_end_keys_[k] == kvs_[j].key) {
					pj = k;
					break;
				}
			}
			if (pi == -1 || pj == -1)continue;
			auto it = kvs_[pi].projects.begin();
			set<string>::iterator it2;
			set<string>tempset;
			for (it; it != kvs_[pi].projects.end(); it++)
			{
				string tempstr = *it;
				string ss;
				if (tempstr.find(not_end_keys_[j]) != -1)
				{
					for (it2 = kvs_[pj].projects.begin(); it2 != kvs_[pj].projects.end(); it2++)
					{
						ss = tempstr;
						tempset.insert(replace(ss, not_end_keys_[j], *it2));
					}

				}
			}
			vector<string>temv;
			for (it = kvs_[pi].projects.begin(); it != kvs_[pi].projects.end(); it++)
			{
				string str = *it;
				if (str.find(not_end_keys_[j]) != -1)
					temv.push_back(str);
			}
			for (int x = 0; x < temv.size(); x++)
			{
				it = kvs_[pi].projects.find(temv[x]);
				if (it != kvs_[pi].projects.end())
					kvs_[pi].projects.erase(it);
			}
			for (it = tempset.begin(); it != tempset.end(); it++)
				kvs_[pi].projects.insert(*it);
			rm_direct_recurse(pi);

		}

	}

	for (int i = 0; i < kvs_.size(); i++){
		cout << kvs_[i].key << "->";
		set<string>::iterator it = kvs_[i].projects.begin();
		int cnt = 0;
		for (it; it != kvs_[i].projects.end(); it++)
		{
			cout << *it;
			cnt++;
			if (cnt != kvs_[i].projects.size())
				cout << '|';
		}
		cout << endl;
	}
}
void RM::get_kvs() {
	cout<<"输入样例:\nS->Qc|c\nQ->Rb|b\nR->Sa|a\n";
	cout<<"以$为结束标志:\n";
	string str;
	while (cin >> str && str[0] != '$')
	{
		kvs_.push_back(split(str));
	}
}


kvs RM::split(string str)
{
	string key;
	set<string>projects;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '>')continue;
		if (str[i] == '-')
		{
			key = tmp;
			tmp = "";
			continue;
		}
		if (str[i] == '|')
		{
			projects.insert(tmp);
			tmp = "";
			continue;
		}
		tmp += str[i];
	}
	if (tmp != "")projects.insert(tmp);
	vector<kvs>ret;
	return { key,projects };
}
void RM:: get_not_end() {
	set<string>keys;
	for (auto kv : kvs_) {
		keys.insert(kv.key);
	}
	for (auto k : keys) {
		not_end_keys_.push_back(k);
	}
}
bool RM::check_all_end(string str){
	for (auto c : str) {
		if (c >= 65 && c<=90)return false;
	}
	return true;
}

void RM::rm_direct_recurse(int pos)
{
	set<string>::iterator it = kvs_[pos].projects.begin();

	bool flag = true;
	for (it; it != kvs_[pos].projects.end(); it++)
	{
		string str = *it;
		if ((str.find(kvs_[pos].key) == str.rfind(kvs_[pos].key) && str.find(kvs_[pos].key) == 0) || check_all_end(str))
			flag = true;
		else
		{
			flag = false;
			break;
		}

	}
	if (!flag)return;

	vector<string>va, vb;
	for (it = kvs_[pos].projects.begin(); it != kvs_[pos].projects.end(); it++)
	{
		string str = *it;
		if (str.find(kvs_[pos].key) == -1)
		{
			vb.push_back(str);
		}
		else
		{
			str.erase(0, kvs_[pos].key.size());
			va.push_back(str);
		}
	}
	kvs_[pos].projects.clear();
	for (int i = 0; i < vb.size(); i++)
	{
		kvs_[pos].projects.insert(vb[i] + kvs_[pos].key + "'");
	}

	set<string>ans;
	for (int i = 0; i < va.size(); i++)
	{
		ans.insert(va[i] + kvs_[pos].key + "'");
	}
	ans.insert("Σ");
	kvs_.push_back({ kvs_[pos].key + "'",ans });
}
