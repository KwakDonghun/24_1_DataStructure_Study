#include <iostream>
#include <vector>

using namespace std;

bool sync[501][501];
int graph[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, D, K, S;
	cin >> N >> M >> D;
	while (D--) {
		cin >> K >> S;
		sync[K][S] = sync[S][K] = true;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 1) {
				for (int k = 1; k <= N; k++) {
					if (k == i) continue;
					if (graph[i][k] == 0 && graph[j][k] == 1)
						graph[i][k] = graph[k][i] = 2;
				}
			}
		}
	}
	while (M--) {
		bool chk = false;
		cin >> K >> S;
		if (S == 1) {
			for (int i = 1; i <= N; i++) {
				if (graph[K][i] == 1 && sync[K][i] == false) {
					cout << i << ' ';
					chk = true;
				}
				else {
					for (int j = 1; j <= N; j++) {
						if (i != K && graph[K][j] == 1 && sync[i][j] == true) {
							cout << i << ' ';
							chk = true;
							break;
						}
					}
				}
			}
		}
		else if (S == 2) {
			for (int i = 1; i <= N; i++){
				if (graph[K][i] >= 1 && sync[K][i] == false) {
					cout << i << ' ';
					chk = true;
				}
				else {
					for (int j = 1; j <= N; j++) {
						if (i != K && graph[K][j] >= 1 && sync[i][j] == true) {
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