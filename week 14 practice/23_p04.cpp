#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
bool visit[101];

void insert(int v1, int v2) {
	graph[v1].push_back(v2);
}

void bfs(int v) {
	int min = 101;
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int front = q.front();
		if (min > front) min = front;
		q.pop();
		for (int adj : graph[front]) {
			if (visit[adj]) continue;
			q.push(adj);
			visit[adj] = true;
		}
	}
	cout << min << '\n';
}

void reset(int n) {
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}

int main() {
	int t, n, m, q, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m >> q;
		while (m--) {
			cin >> v1 >> v2;
			insert(v1, v2);
		}
		while (q--) {
			cin >> v1;
			bfs(v1);
			reset(n);
		}
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
		}
	}
}