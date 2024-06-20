#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visit[1001];
int cnt;

void insert(int v1, int v2) {
	graph[v1].push_back(v2);
	graph[v2].push_back(v1);
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = ++cnt;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int adj : graph[cur]) {
			if (visit[adj]) continue;
			visit[adj] = ++cnt;
			q.push(adj);
		}
	}
}
void clear(int n) {
	cnt = 0;
	for (int i = 1; i <= n; i++)
		visit[i] = 0;
}
int main() {
	int n, m, q, v1, v2;
	cin >> n >> m >> q;
	while (m--) {
		cin >> v1 >> v2;
		insert(v1, v2);
	}
	while (q--) {
		clear(n);
		cin >> v1 >> v2;
		bfs(v1);
		cout << visit[v2] << '\n';
	}
}