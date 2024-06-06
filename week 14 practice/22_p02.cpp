#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
bool visit[101];
int Min = 101;

void insert(int v1, int v2) {
	graph[v1].push_back(v2);
	graph[v2].push_back(v1);
}
void dfs(int v) {
	if (visit[v]) return;
	if (Min > v) Min = v;
	visit[v] = true;
	for (int adj : graph[v])
		dfs(adj);
}
void reset(int n) {
	Min = 101;
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, k, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		while (m--) {
			cin >> v1 >> v2;
			insert(v1, v2);
		}
		while (k--) {
			cin >> v1;
			dfs(v1);
			cout << Min << '\n';
			reset(n);
		}
		for (int i = 1; i <= n; i++)
			graph[i].clear();
	}
}