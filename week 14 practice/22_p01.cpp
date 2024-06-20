#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visit[1001];
int cnt;

void insert(int s, int d) {
	graph[s].push_back(d);
	graph[d].push_back(s);
}
void dfs(int v) {
	if (visit[v]) return;
	visit[v] = ++cnt;
	if (visit[v] % 2 == 1) cout << v << ' ';
	for (int adj : graph[v])
		dfs(adj);
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
		dfs(1);
		cout << '\n';
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		reset(n);
	}
	
}