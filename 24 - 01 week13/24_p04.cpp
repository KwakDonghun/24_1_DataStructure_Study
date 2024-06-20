#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];
bool deny[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, d, k, s;
	cin >> n >> m >> d;
	while (d--) {
		cin >> k;
		deny[k] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1) {
				for (int k = 1; k <= n; k++) {
					if (graph[i][k] == 0 && graph[j][k] == 1 && i != k)
						graph[i][k] = graph[k][i] = 2;
				}
			}
		}
	while (m--) {
		cin >> k >> s;
		int cnt = 0, score = 0;
		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] == 1 && !deny[i]) {
					cnt++;
					score += 2;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] >= 1 && !deny[i]) {
					cnt++;
					if (graph[k][i] == 1)
						score += 2;
					else if (graph[k][i])
						score += 1;
				}
			}
		}
		if (cnt == 0)
			cout << -1 << '\n';
		else
			cout << cnt << ' ' << score << '\n';
	}
}