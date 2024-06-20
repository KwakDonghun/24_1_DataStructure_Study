#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	int idx;
	vertex(int idx) {
		this->idx = idx;
	}
};
class graph {
public:
	int N;
	vector<vector<int>> matrix;
	vector<bool> deny;
	graph(int N) {
		this->N = N;
		matrix.resize(N + 1, vector<int>(N + 1, 0));
		deny.resize(N + 1, false);
	}
	void solve(int k, int s, int n) {
		int rec_cnt = 0, rec_sco = 0;
		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (matrix[k][i] == 1 && deny[i] == false) {
					rec_cnt++;
					rec_sco += 2;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (matrix[k][i] >= 1 && deny[i] == false) {
					rec_cnt++;
					if (matrix[k][i] == 1)
						rec_sco += 2;
					else 
						rec_sco++;
				}
			}
		}
		if (rec_cnt == 0)
			cout << -1 << '\n';
		else
			cout << rec_cnt << ' ' << rec_sco << '\n';
	}

};

int main() {
	int n, m, d, k, s;
	graph g(500);
	cin >> n >> m >> d;
	while (d--) {
		cin >> k;
		g.deny[k] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g.matrix[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g.matrix[i][j] == 1) {
				for (int k = 1; k <= n; k++)
					if (k != i && g.matrix[k][i] == 0 && g.matrix[j][k] == 1)
						g.matrix[i][k] = g.matrix[k][i] = 2;
			}
		}
	}
	while (m--) {
		cin >> k >> s;
		g.solve(k, s, n);
	}
}
