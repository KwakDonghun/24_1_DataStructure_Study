#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, k, f;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];
	while (M--) {
		bool chk = false;
		cin >> k >> f;
		if (f == 0) {
			for (int i = 1; i <= N; i++) {
				if (i != k) {
					for (int j = 1; j <= N; j++) {
						if (graph[k][j] == 2 && graph[i][j] == 2 && graph[k][i] == 0) {
							cout << i << ' ';
							chk = true;
							break;
						}
					}
				}
			}
		}
		else if (f == 1) {
			for (int i = 1; i <= N; i++) {
				if (i != k) {
					for (int j = 1; j <= N; j++) {
						if (graph[k][j] == 2 && graph[i][j] == 1 &&  graph[k][i] == 0) {
							cout << i << ' ';
							chk = true;
							break;
						}
					}
				}
			}
		}
		if (chk == false)
			cout << 0;
		cout << '\n';
	}
}