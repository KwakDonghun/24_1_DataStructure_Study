#include <iostream>
#include <string>
#include <vector>

using namespace std;

class unsortedPQ {
private:
	vector<int> pq;
public:
	unsortedPQ() {
		pq.clear();
	}
	void insert(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			pq.push_back(v[i]);
			for (int j = pq.size() - 1; j > 0; j--) {
				if (pq[j - 1] < pq[j]) {
					int temp = pq[j - 1];
					pq[j - 1] = pq[j];
					pq[j] = temp;
				}
			}
		}
	}
	int max() {
		if (pq.empty()) return -1;
		return pq[0];
	}
	void removemax() {
		if (pq.empty()) return;
		pq.erase(pq.begin());
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input;
	cin >> T;
	while (T--) {
		unsortedPQ pq;
		vector<int> v;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			v.push_back(input);
		}
		pq.insert(v);
		for (int i = 0; i < N; i++) {
			cout << pq.max() << ' ';
			pq.removemax();
		}
		cout << '\n';
	}
}