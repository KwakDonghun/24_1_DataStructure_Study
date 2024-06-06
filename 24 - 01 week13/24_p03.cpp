#include <iostream>
#include <vector>

using namespace std;

pair <bool, int> vertex[10001];
bool graph[10001][10001];

void insertV(int s) {
	if (vertex[s].first) {
		cout << "Exist\n";
		return;
	}
	vertex[s].first = true;
	vertex[s].second = 0;
}
void insertE(int s, int d) {
	if (graph[s][d]) {
		cout << "Exist\n";
		return;
	}
	graph[s][d] = graph[d][s] = true;
	vertex[s].second++;
	vertex[d].second++;
}
void eraseV(int s) {
	for (int i = 1; i < 10001; i++) {
		if (graph[s][i]) {
			vertex[i].second--;
			graph[i][s] = graph[s][i] = false;
		}
	}
	vertex[s].first = false;
}
void eraseE(int s, int d) {
	if (!graph[s][d]) {
		cout << "None\n";
		return;
	}
	graph[s][d] = graph[d][s] = false;
	vertex[s].second--;
	vertex[d].second--;
}
void isAdjacent(int s, int d) {
	if (graph[s][d])
		cout << "True ";
	else
		cout << "False ";
	if (vertex[s].second < vertex[d].second)
		cout << d << '\n';
	else if (vertex[s].second > vertex[d].second)
		cout << s << '\n';
	else {
		if (s < d)
			cout << d << '\n';
		else
			cout << s << '\n';
	}
}
void maxV() {
	int max = 0;
	for (int i = 10000; i >= 1; i--) {
		if (vertex[i].first) {
			max = i;
			break;
		}
	}
	if (max == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << max << ' ' << vertex[max].second << '\n';
	}
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
			insertV(s);
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			insertE(s, d);
		}
		else if (cmd == "eraseVertex") {
			cin >> s;
			eraseV(s);
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			eraseE(s, d);
		}
		else if (cmd == "isAdjacent") {
			cin >> s >> d;
			isAdjacent(s, d);
		}
		else if (cmd == "maxVertexInfo") {
			maxV();
		}
	}
}