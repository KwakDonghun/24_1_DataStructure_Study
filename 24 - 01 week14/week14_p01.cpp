#include <iostream>
#include <vector>

using namespace std;

struct vertex {
public:
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
	graph() {
		adj_list.clear();
	}
	int getidx(vector<vertex*>& list, int v) {
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if (list[i]->val == v)
				return i;
		}
		return -1;
	}
	vertex* find(int v) {
		int idx = getidx(adj_list, v);
		if (idx == -1) return NULL;
		return adj_list[idx];
	}
	void insertV(int v) {
		if (find(v) != NULL) {
			cout << "ERRORCODE 01\n";
			return;
		}
		vertex* newver = new vertex(v);
		adj_list.push_back(newver);
	}
	void insertE(int s, int d) {
		vertex* src = find(s);
		vertex* dst = find(d);
		if (src == NULL || dst == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		if (getidx(src->adj_vertex, d) != -1) {
			cout << "ERRORCODE 02\n";
			return;
		}
		src->adj_vertex.push_back(dst);
		dst->adj_vertex.push_back(src);
	}
	void eraseV(int v) {
		vertex* delver = find(v);
		if (delver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		for (vertex* i : delver->adj_vertex)
			i->adj_vertex.erase(i->adj_vertex.begin() + getidx(i->adj_vertex, v));
		adj_list.erase(adj_list.begin() + getidx(adj_list, v));
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
		src->adj_vertex.erase(src->adj_vertex.begin() + getidx(src->adj_vertex,d));
		dst->adj_vertex.erase(dst->adj_vertex.begin() + getidx(dst->adj_vertex, s));
	}
	void printAdjS(int v) {
		vertex* curver = find(v);
		if (curver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		int sum = 0, cnt = 0;
		for (vertex* i : curver->adj_vertex) {
			sum += i->val;
			cnt++;
		}
		cout << cnt << ' ' << sum << '\n';
	}
	void printAdjM(int v) {
		vertex* curver = find(v);
		if (curver == NULL) {
			cout << "ERRORCODE 03\n";
			return;
		}
		int min_id = 1000001;
		for (vertex* i : curver->adj_vertex) {
			if (i->val < min_id)
				min_id = i->val;
		}
		if (min_id == 1000001) cout << -1 << '\n';
		else cout << min_id << '\n';
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
		else if (cmd == "InsertVertex"){
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
		else if (cmd == "PrintAdjSum") {
			cin >> id >> s;
			gid[id].printAdjS(s);
		}
		else if (cmd == "PrintAdjMin") {
			cin >> id >> s;
			gid[id].printAdjM(s);
		}
	}
}