#include <iostream>
#include <vector>
#include <string>

using namespace std;

class unsortedPQ {
private:
	vector<int> pq;
public:
	void insert(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++)
			pq.push_back(v[i]);
	}
	void solve() {
		vector<int> pq1, pq2;
		for (int i = 0; i < pq.size(); i++) {
			if (pq[i] % 2 == 0)
				pq1.push_back(pq[i]);
			else
				pq2.push_back(pq[i]);
		}
		int size1 = pq1.size(), size2 = pq2.size();
		for (int i = 0; i < size1; i++) {
			int min_index = 0;
			for (int j = 0; j < pq1.size(); j++) 
				if (pq1[min_index] > pq1[j])
					min_index = j;
			cout << pq1[min_index] << ' ';
			pq1.erase(pq1.begin() + min_index);
		}
		for (int i = 0; i < size2; i++) {
			int min_index = 0;
			for (int j = 0; j < pq2.size(); j++)
				if (pq2[min_index] > pq2[j])
					min_index = j;
			cout << pq2[min_index] << ' ';
			pq2.erase(pq2.begin() + min_index);
		}
		cout << '\n';
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
		pq.solve();
	}
}