#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sortedPQ {
private:
	vector<int> pq;
public:
	sortedPQ() {
		pq.clear();
	}
	void insert(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			pq.push_back(v[i]);
			for (int j = pq.size()-1; j > 0 ; j--) {
				if (pq[j-1] > pq[j]) {
					int temp = pq[j];
					pq[j] = pq[j - 1];
					pq[j - 1] = temp;
				}
			}
		}
	}
	void removemin() {
		if (pq.size() == 0) return;
		pq.erase(pq.begin());
	}
	int min() {
		if (pq.size() == 0) return -1;
		return pq[0];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input;
	cin >> T;
	while (T--) {
		cin >> N;
		sortedPQ pq;
		vector<int> s;
		for (int i = 0; i < N; i++) {
			cin >> input;
			s.push_back(input);
		}
		pq.insert(s);
		for (int i = 0; i < N; i++) {
			cout << pq.min() << ' ';
			pq.removemin();
		}
		cout << '\n';
	}
}