#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
int visit[1001];
int cnt;

void insert(int s, int d) {
	graph[s].push_back(d);
	graph[d].push_back(s);
}
void bfs(int v) {
	queue<int> q;
	visit[v] = ++cnt;
	cout << v << ' ';
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int adj : graph[cur]) {
			if (visit[adj]) continue;
			visit[adj] = ++cnt;
			if (visit[adj] % 2 == 1) cout << adj << ' ';
			if(visit[adj])
			q.push(adj);
		}
	}
}
void reset(int n) {
	cnt = 0;
	for (int i = 1; i <= n; i++)
		visit[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		while (m--) {
			cin >> v1 >> v2;
			insert(v1, v2);
		}
		bfs(1);
		cout << '\n';
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		reset(n);
	}

}