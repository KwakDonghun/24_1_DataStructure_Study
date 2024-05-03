#include <iostream>
#include <vector>
#include <string>

using namespace std;

class unsortedPQ {
private:
	vector <int> pq;
public:
	void insert(vector<int> s) {
		int size = s.size();
		for (int i = 0; i < size; i++)
			pq.push_back(s[i]);
	}
	void removemax() {
		if (pq.size() == 0) return;
		int max_index = 0;
		for (int i = 0; i < pq.size(); i++)
			if (pq[max_index] < pq[i])
				max_index = i;
		pq.erase(pq.begin() + max_index);
	}
	int max() {
		if (pq.size() == 0) return -1;
		int max_index = 0;
		for (int i = 0; i < pq.size(); i++)
			if (pq[max_index] < pq[i])
				max_index = i;
		return pq[max_index];
	}
	void solve() {
		vector<int> pq1, pq2;
		for (int i = 0; i < pq.size(); i++) {
			if (pq[i] % 2 != 0)
				pq1.push_back(pq[i]);
			else
				pq2.push_back(pq[i]);
		}
		int pq1_size = pq1.size();
		for (int j = 0; j < pq1_size; j++) {
			int max_index = 0;
			for (int i = 0; i < pq1.size(); i++) {
				if (pq1[max_index] < pq1[i])
					max_index = i;
			}
			cout << pq1[max_index] << ' ';
			pq1.erase(pq1.begin() + max_index);
		}
		int pq2_size = pq2.size();
		for (int j = 0; j < pq2_size; j++) {
			int max_index = 0;
			for (int i = 0; i < pq2.size(); i++) {
				if (pq2[max_index] < pq2[i])
					max_index = i;
			}
			cout << pq2[max_index] << ' ';
			pq2.erase(pq2.begin() + max_index);
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
		cin >> N;
		unsortedPQ pq;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			cin >> input;
			v.push_back(input);
		}
		pq.insert(v);
		pq.solve();
	}
}