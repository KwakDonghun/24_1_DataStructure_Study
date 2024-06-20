#include <iostream>
#include <string>
#include <vector>

using namespace std;

	pair<bool, int> vertices[10001]; //정점유무, degree
	bool graph[10001][10001];

	void insertvertex(int s) {
		if (vertices[s].first == true) {
			cout << "Exist\n";
			return;
		}
		vertices[s].first = true;
		vertices[s].second = 0;
	}
	void insertedge(int s, int d) {
		if (graph[s][d] == true) {
			cout << "Exist\n";
			return;
		}
		graph[s][d] = true;
		graph[d][s] = true;
		vertices[d].second++;
		vertices[s].second++;
	}
	void eraseedge(int s, int d) {
		if (graph[s][d] == false){
			cout << "None\n";
			return;
		}
		graph[s][d] = false;
		graph[d][s] = false;
		vertices[d].second--;
		vertices[s].second--;
	}
	void isadjacentodd(int s) {
		if (vertices[s].second % 2 != 0)
			cout << "True ";
		else
			cout << "False ";
		cout << vertices[s].second << '\n';
	}
	void minedgevertex() {
		int min_idx = 0;
		vertices[min_idx].second = 10001;
		for (int i = 1; i <= 10000; i++)
			if (vertices[i].first == true && vertices[min_idx].second > vertices[i].second)
				min_idx = i;
		if (min_idx == 0 || vertices[min_idx].second == 0)
			cout << -1 << '\n';
		else
			cout << min_idx << '\n';
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
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			eraseedge(s, d);
		}
		else if (cmd == "isAdjacentOdd") {
			cin >> s;
			isadjacentodd(s);
		}
		else if (cmd == "minEdgeVertex")
			minedgevertex();
	}
}