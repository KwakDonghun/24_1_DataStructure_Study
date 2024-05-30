#include <iostream>
#include <vector>

using namespace std;

pair<bool, int> vertex[10001];
bool graph[10001][10001];

void insertEdge(int s, int d) {
	if (graph[s][d] == true) {
		cout << "Exist\n";
		return;
	}
	graph[s][d] = graph[d][s] = true;
	vertex[s].second++;
	vertex[d].second++;
}
void insertVertex(int s) {
	vertex[s].first = true;
	vertex[s].second = 0;
}
void eraseEdge(int s, int d) {
	if (graph[s][d] == false) {
		cout << "None\n";
		return;
	}
	graph[s][d] = graph[d][s] = false;
	vertex[s].second--;
	vertex[d].second--;
}
void SumAdjacentNode(int s) {
	int sum = 0;
	for (int i = 1; i <= 10000; i++)
		if (graph[s][i])
			sum += i;
	if (sum > 0)
		cout << sum << '\n';
	else
		cout << "None\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, s, d;
	string cmd;
	cin >> T >> N;
	while (N--) {
		cin >> s;
		insertVertex(s);
	}
	while (T--) {
		cin >> cmd;
		if (cmd == "insertEdge") {
			cin >> s >> d;
			insertEdge(s, d);
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			eraseEdge(s, d);
		}
		else if (cmd == "SumAdjacentNode") {
			cin >> s;
			SumAdjacentNode(s);
		}
	}
}