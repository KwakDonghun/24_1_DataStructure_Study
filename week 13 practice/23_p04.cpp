#include <iostream>
#include <vector>

using namespace std;

bool deny[501];
int graph[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, D, M, input, K , S;
	cin >> N >> M >> D ;
	while (D--) {
		cin >> input;
		deny[input] = true;
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
		cin >> K >> S;
		bool check = false;
		if (S == 1) {
			for (int i = 1; i <= N; i++) {
				if (graph[K][i] == 1 && deny[i] == false) {
					cout << i << ' ';
					check = true;
				}
			}
		}
		else {
			for (int i = 1; i <= N; i++) {
				if (graph[K][i] >= 1 && deny[i] == false) {
					cout << i << ' ';
					check = true;
				}
			}
		}
		if (check == false)
			cout << 0 << ' ';
		cout << '\n';
	}
}