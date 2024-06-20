#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visit[1001];

void insert(int s, int d) {
	graph[s].push_back(d);
	graph[d].push_back(s);
}
void reset(int n) {
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}
void dfs(int v) {
	if (visit[v]) return;
	visit[v] = true;
	for (int adj : graph[v])
		dfs(adj);
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int adj : graph[cur]) {
			if (visit[adj]) continue;
			visit[adj] = true;
			q.push(adj);
		}
	}
}

int main() {
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		insert(a, b);
	}
	while (q--) {
		reset(n);
		cin >> a >> b;
		dfs(a);
		if (visit[b]) cout << "True\n";
		else cout << "False\n";
	}
}