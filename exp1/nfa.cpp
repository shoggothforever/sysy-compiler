#include "nfa.h"


nfa::nfa(string name, string regex)
	:name_(name),
	regex_(regex),
	start_(0),
	end_(0),
	iterator(0),
	regex_post_(regex_to_postfix(regex)),
	graph_(INIT_GRAPH)
{}

string nfa::regex_to_postfix(string regex) {
    string tmp;
    for (int i = 0; i < regex.size() - 1; i++) {
        tmp += regex[i];
        if (regex[i] != '('  && regex[i+1] != ')'&& regex[i] != '|' && regex[i + 1] != '|'
            && regex[i + 1] != '*') tmp += AND_CHAR;
    }
    tmp += regex.back();
	std::cout << regex_ << std::endl;
	std::cout << tmp << std::endl;
    std::stack<char>op_stack;
	string post_regex;
	for (auto c : tmp) {
		if (isalnum(c)) {
			post_regex += c;
			continue;
		}
		if (REGEX_OP_TYPE(c) == REGEX_OP_TYPE::LBRACE) {
			op_stack.push(c);
		}
		else if (REGEX_OP_TYPE(c) == REGEX_OP_TYPE::ZERO_ANY_MATCH
			|| REGEX_OP_TYPE(c) == REGEX_OP_TYPE::AND
			|| REGEX_OP_TYPE(c) == REGEX_OP_TYPE::OR){
			while (op_stack.size()) {
				if (priority_lt(op_stack.top(), c)){
					break;
				}
				else {
					post_regex += op_stack.top();
					op_stack.pop();
				}
			}
			op_stack.push(c);
		}
		else if(REGEX_OP_TYPE(c) == REGEX_OP_TYPE::RBRACE) {
			while (op_stack.size() && op_stack.top() != char(REGEX_OP_TYPE::LBRACE)) {
				post_regex += op_stack.top();
				op_stack.pop();
			}
			op_stack.pop();
		}
	}
	while (op_stack.size()) {
		post_regex += op_stack.top();
		op_stack.pop();
	}
	std::cout << post_regex << std::endl;
	return post_regex;
}
const char LINK = ' ';
int nfa::next() {
	graph_.push_back(VPI{});
	return ++iterator;
}
bool nfa::build() {
	bool res = true;
	std::stack<PII>edges;
	int source, destination;
	for (auto ch : regex_post_) {
		if (REGEX_OP_TYPE(ch) != REGEX_OP_TYPE::ZERO_ANY_MATCH && REGEX_OP_TYPE(ch) != REGEX_OP_TYPE::AND&& REGEX_OP_TYPE(ch) != REGEX_OP_TYPE::OR) {
			source = next();
			destination = next();
			edges.push(PII{ source,destination });
			graph_[source].push_back(make_pair(destination, ch));
			chs.insert(ch);
			continue;
		}
		switch (REGEX_OP_TYPE(ch)) {
		case REGEX_OP_TYPE::ZERO_ANY_MATCH: {
			PII edge = edges.top(); edges.pop();
			source = next();
			destination = next();
			edges.push(PII{ source,destination });
			graph_[source].push_back(PII{ edge.first,LINK });
			graph_[source].push_back(PII{ destination,LINK });
			graph_[edge.second].push_back(PII{ edge.first, LINK });
			graph_[edge.second].push_back(PII{ destination, LINK });
		}break;
		case REGEX_OP_TYPE::AND: {
			PII right = edges.top(); edges.pop();
			PII left = edges.top(); edges.pop();
			edges.push(PII{ left.first,right.second });
			graph_[left.second].push_back(PII{ right.first,LINK });
		}break;
		case REGEX_OP_TYPE::OR: {
			PII right = edges.top(); edges.pop();
			PII left = edges.top(); edges.pop();
			source = next();
			destination = next();
			edges.push(PII{ source,destination });
			graph_[source].push_back(PII{left.first, LINK });
			graph_[source].push_back(PII{right.first, LINK});
			graph_[left.second].push_back(PII{destination,LINK});
			graph_[right.second].push_back(PII{ destination,LINK});
		}break;
		default:break;
		}
	}
	start_ = edges.top().first;
	end_ = edges.top().second;
	cout << "start from:" << start_ << " end at:" << end_ << "\n";
	for (int i = 1; i <= iterator; i++) {
		for (auto edge : graph_[i]) {
			std::cout << i << "----" << char(edge.second) << "---->" << edge.first << "\n";
		}
	}
	return res;
}
REGEX_OP_PRIORITY regex_op_priority(char op) {
	switch (REGEX_OP_TYPE(op)) {
	#define ENUM(name) case REGEX_OP_TYPE::name : return REGEX_OP_PRIORITY::##name##_PRIORITY;
	DEFINE_ENUMS()
	#undef ENUM
	default:return REGEX_OP_PRIORITY::UNDEFINED_PRIORITY;
	}
}
bool priority_lt(char l_op, char r_op) {
	return (regex_op_priority(l_op) < regex_op_priority(r_op));
}
dfa::dfa(string name, string regex) :nfa_(nfa(name, regex)){}
dfa::dfa(nfa* nfa) {
	iterator=0;
	nfa_ = *nfa;
}
void dfa::print() {

}
bool dfa::build(){
	cout << "build dfa\n" ;
	//子集构造法
	std::queue<vector<int>>q;
	vector<int>v;
	v.push_back(nfa_.start_);
	int n = nfa_.iterator;
	vector<bool>vis(n + 1, false);
	dfs_move(nfa_.start_, LINK, v, vis);
	
	v.erase(std::unique(v.begin(), v.end()),v.end());
	sort(v.begin(), v.end());
	cout << "start state:\n";
	for (auto it : v)cout << it << " ";
	cout << std::endl;
	q.push(v);
	state_set_.insert(v);
	state_map_.insert(make_pair(++iterator, v));
	state_map_reverse_.insert(make_pair(v, iterator));
	while (q.size()) {
		vector<int>vec = q.front(); q.pop();
		cout << "get vec:";
		for (auto it : vec)cout << it << " "; cout << '\n';
		for (auto ch : nfa_.chs) {
			vector<int>next;
			vis = vector<bool>(n + 1, false);
			for (auto num : vec) {
				dfs_move(num, ch, next, vis);
			}

			cout << "use char " << char(ch) << " to  state:";
			for (auto it : next)cout << it << " ";
			cout << "\n";

			vis = vector<bool>(n + 1, false);
			vector<int>tmp = next;
			for (auto num : tmp) {
				dfs_move(num, LINK, next, vis);
			}
			next.erase(std::unique(next.begin(), next.end()), next.end());
			sort(next.begin(), next.end());
			int source = state_map_reverse_[vec];
			if (next.size()&&!state_set_.count(next)) {
				++iterator;

				cout << "------------------------------------\n";
				cout << "get new state:"<<iterator << std::endl;
				cout << "------------------------------------\n";

				state_set_.insert(next);
				state_map_.insert(make_pair(iterator, next));
				state_map_reverse_.insert(make_pair(next, iterator));
				q.push(next);
			}
			auto pos = state_map_reverse_.find(next);
			if (pos!= state_map_reverse_.end()) {
				dfa_graph_[source].push_back({ ch,pos->second});
			}
		}
	}
	cout<<"dfa state_size: "<< state_set_.size() << std::endl;
	cout << "dfa_graph size: " << dfa_graph_.size() << std::endl;
	for (auto it : dfa_graph_) {
		cout << "source:" << it.first << '\n';
		for (auto edge : it.second) {
			cout << "bridge: " << edge.first << " to state: " << edge.second << "\n";
			cout << "state set is : ";
			for (auto num : state_map_[edge.second])cout << num << " ";
			cout << '\n';
		}
	}
	return true;
}
void dfa::dfs_move(int num,char ch, vector<int>& next, vector<bool>& vis) {
	if (vis[num])return;
	vis[num] = true;
	for (auto [a, b] : nfa_.graph_[num]) {
		//cout << "num:" << num << "\n" << "graph size:" << nfa_.graph_[num].size() << "\n";
		if (ch == char(b)) {
			next.push_back(a);
			dfs_move(a, ch, next, vis);
		}
	}
}
int find(vector<int>& v, int x) {
	if (x == v[x])return x;
	return v[x] = find(v,v[x]);
}
std::unordered_map<int, VPC>dfa::get_min_dfa() {
	std::unordered_map<int, VPC >graph=dfa_graph_;
	int n = iterator;
	vector<VPC>v(n + 1);
	vector<int>f(n + 1, 0);
	vector<PII>mt;
	for (int i = 1; i <= n; i++)f[i] = i;
	for (auto node: graph) {
		v[node.first] = node.second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (v[i] == v[j]) {
				//cout << "node[" << i << "]==node[" << j << "]\n";
				mt.push_back({ i,j });
			}
		}
	}
	for (auto [a, b] : mt) {
		int fa = find(f, a);
		int fb = find(f, b);
		if (fa != fb) {
			if (fa < fb)f[fb] = fa;
			else f[fa] = f[fb];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != f[i]) {
			graph.erase(i);
			continue;
		}
		else {
			for (auto& [a, b] : graph[i]) {
				if (b<=n&&b != f[b]) {
					b = f[b];
				}
				else if(b>n)cout <<"b =="<<b<< "  out of range\n";
			}
		}
	}
	cout << "min_dfa_graph size:" << graph.size() << std::endl;
	print_dfa(graph);
	min_dfa_graph_ = graph;
	return graph;
}
void dfa::print_dfa(std::unordered_map<int, VPC>&graph) {
	for (auto it : graph) {
		cout << "source:" << it.first << '\n';
		for (auto [link, state] : it.second) {
			cout << "bridge: " << ((((char)link != ' ' ? std::string(1, link) : "empty"))) << " to state: " << state << "\n";
			//cout << "state set is : ";
			//for (auto num : state_map_[edge.second])cout << num << " ";
			cout << '\n';
		}
	}
}
string dfa::dfa_to_dot(string name) {
	string dot="digraph DFA {\n";
	dot += "label=\"" + name + "\";\n";
	dot += "rankdir=LR;\n";
	dot += "node [shape = circle];\n";
	dot += "start [shape=point];\n";
	for (auto it : min_dfa_graph_) {
		for (auto [link,state] : it.second) {
			dot += std::to_string(it.first);
			dot += " -> ";
			dot += std::to_string(state);
			dot += "[label = \"" + ((((char)link != ' ' ? std::string(1,link) : "empty"))) + "\"]; \n";
		}
	}
	dot+= "}\n";
	return dot;
}