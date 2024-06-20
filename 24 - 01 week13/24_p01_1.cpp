#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	int idx;
	vertex(int idx) {
		this->idx = idx;
	}
};
class graph {
public:
	int N;
	vertex* find(int idx) {
		return list[idx];
	}
	vector<vertex*> list;
	vector<vector<bool>> matrix;
	graph(int N) {
		this->N = N;
		list.resize(N + 1, NULL);
		matrix.resize(N + 1, vector<bool>(N + 1, false));
	}
	void insertVertex(int s) {
		if (find(s) != NULL) {
			cout << "Exist\n";
			return;
		}
		vertex* newvertex = new vertex(s);
		list[s] = newvertex;
	}
	void insertEdge(int s, int d) {
		if (matrix[s][d]) {
			cout << "Exist\n";
			return;
		}
		matrix[s][d] = matrix[d][s] = true;
	}
	void eraseVertex(int s) {
		vertex* erase = find(s);
		for (int i = 1; i <= N; i++) {
			matrix[i][s] = matrix[s][i] = false;
		}
		delete list[s];
		list[s] = NULL;
	}
	void eraseEdge(int s, int d) {
		if(!matrix[s][d]){
			cout << "None\n";
			return;
		}
		matrix[s][d] = matrix[d][s] = false;
	}
	void isAdjacent(int s, int d) {
		int deg_s = 0, deg_d = 0;
		if (matrix[s][d])
			cout << "True ";
		else
			cout << "False ";
		for (int i = 1; i <= N; i++) {
			if (matrix[s][i] == true)
				deg_s++;
			if (matrix[d][i] == true)
				deg_d++;
		}
		if (deg_s > deg_d)
			cout << d << '\n';
		else if (deg_s < deg_d)
			cout << s << '\n';
		else {
			if (s < d)
				cout << s << '\n';
			else
				cout << d << '\n';
		}
	}
	void minVertexInfo() {
		int min_idx = 10001, min_cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (list[i] == NULL) continue;
			if (min_idx > i) min_idx = i;
		}
		if (min_idx == 10001) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 1; i <= N; i++)
			if (matrix[i][min_idx])
				min_cnt++;
		cout << min_idx << ' ' << min_cnt << '\n';
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, s, d;
	string cmd;
	cin >> T;
	graph g(10000);
	while (T--) {
		cin >> cmd;
		if (cmd == "insertVertex") {
			cin >> s;
			g.insertVertex(s);
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			g.insertEdge(s, d);
		}
		else if (cmd == "eraseVertex") {
			cin >> s;
			g.eraseVertex(s);
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			g.eraseEdge(s, d);
		}
		else if (cmd == "isAdjacent") {
			cin >> s >> d;
			g.isAdjacent(s, d);
		}
		else if (cmd == "minVertexInfo") {
			g.minVertexInfo();
		}
	}
}