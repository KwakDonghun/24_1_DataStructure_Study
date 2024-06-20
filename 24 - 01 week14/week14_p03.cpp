#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	int val;
	vector<vertex*> adj_vertex;
	vertex(int v) {
		val = v;
		adj_vertex.clear();
	}
};
class graph {
public:
	vector<vertex*> adj_list;
	int getidx(vector<vertex*>& list, int s) {
		int size = list.size();
		for (int i = 0; i < size; i++)
			if (list[i]->val == s)
				return i;
		return -1;
	}
	vertex* find(int s) {
		int idx = getidx(adj_list,s);
		if (idx == -1) return NULL;
		else return adj_list[idx];
	}
	void insertV(int s) {
		if (find(s) != NULL) {
			cout << "ERRORCODE 01\n";
			return;
		}
		vertex* newver = new vertex(s);
		adj_list.push_back(newver);
	}
	void insertE(int s, int d) {
		vertex* src = find(s);
		vertex* dst = find(d);
		if(src == NULL || dst == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		if(getidx(src->adj_vertex, d) != -1) {
			cout << "ERRORCODE 02\n";
			return;
		}
		src->adj_vertex.push_back(dst);
		dst->adj_vertex.push_back(src);
	}
	void eraseV(int s) {
		vertex* delver = find(s);
		if(delver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		for (vertex* adj : delver->adj_vertex)
			adj->adj_vertex.erase(adj->adj_vertex.begin() + getidx(adj->adj_vertex, s));
		adj_list.erase(adj_list.begin() + getidx(adj_list, s));
		delete delver;
	}
	void eraseE(int s, int d) {
		vertex* src = find(s);
		vertex* dst = find(d);
		if (src == NULL || dst == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		if (getidx(src->adj_vertex, d) == -1) {
			cout << "ERRORCODE 04\n";
			return;
		}
		dst->adj_vertex.erase(dst->adj_vertex.begin() + getidx(dst->adj_vertex, s));
		src->adj_vertex.erase(src->adj_vertex.begin() + getidx(src->adj_vertex, d));
	}
	void PrintAdjC(int s) {
		int cnt = 0;
		vertex* curver = find(s);
		if(curver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		for (vertex* adj : curver->adj_vertex)
			cnt++;
		cout << cnt << '\n';
	}
	void PrintAdjM(int s) {
		int min = 1000001, max = -1;
		vertex* curver = find(s);
		if (curver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		for (vertex* adj : curver->adj_vertex) {
			if (adj->val > max) max = adj->val;
			if (adj->val < min) min = adj->val;
		}
		if (max == -1) cout << -1 << '\n';
		else cout << min << ' ' << max << '\n';
	}
};

int main() {
	int N, id, s, d;
	string cmd;
	graph gid[101];
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "Graph") {
			cin >> id;
		}
		else if (cmd == "InsertVertex") {
			cin >> id >> s;
			gid[id].insertV(s);
		}
		else if (cmd == "InsertEdge") {
			cin >> id >> s >> d;
			gid[id].insertE(s, d);
		}
		else if (cmd == "EraseVertex") {
			cin >> id >> s;
			gid[id].eraseV(s);
		}
		else if (cmd == "EraseEdge") {
			cin >> id >> s >> d;
			gid[id].eraseE(s, d);
		}
		else if (cmd == "PrintAdjCount") {
			cin >> id >> s;
			gid[id].PrintAdjC(s);
		}
		else if (cmd == "PrintAdjMinMax") {
			cin >> id >> s;
			gid[id].PrintAdjM(s);
		}
	}
}