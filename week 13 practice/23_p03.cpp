#include <iostream>
#include <vector>

using namespace std;

pair<bool, int> vertex[10001];
bool graph[10001][10001];

void insertvertex(int s) {
	if (vertex[s].first == true) {
		cout << "Exist\n";
		return;
	}
	vertex[s].first = true;
	vertex[s].second = 0;
}
void insertedge(int s, int d) {
	if (graph[s][d] == true) {
		cout << "Exist\n";
		return;
	}
	graph[s][d] = true;
	graph[d][s] = true;
	vertex[s].second++;
	vertex[d].second++;
}
void erasevertex(int s) {
	vertex[s].first = false;
	vertex[s].second = 0;
	for (int i = 0; i < 10001; i++){
		if (graph[i][s]){
			vertex[i].second--;
			graph[i][s] = graph[s][i] = false;
		}
	}
}
void isadjacenteven(int s) {
	if (vertex[s].second % 2 == 0) 
		cout << "True ";
	else
		cout << "False ";
	cout << vertex[s].second << '\n';
}
void maxedgevertex() {
	int max_idx = 0;
	vertex[max_idx].second = -1;
	for (int i = 0; i < 10001; i++) {
		if (vertex[i].first == true && vertex[max_idx].second < vertex[i].second)
			max_idx = i;
	}
	if (max_idx == 0 || vertex[max_idx].second == 0)
		cout << -1 << '\n';
	else
		cout << max_idx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, s, d;
	string cmd;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "insertVertex") {
			cin >> s;
			insertvertex(s);
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			insertedge(s, d);
		}
		else if (cmd == "eraseVertex") {
			cin >> s;
			erasevertex(s);
		}
		else if (cmd == "isAdjacentEven") {
			cin >> s;
			isadjacenteven(s);
		}
		else if (cmd == "maxEdgeVertex")
			maxedgevertex();
	}
}