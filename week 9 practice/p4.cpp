#include <iostream>
#include <string>
#include <vector>

using namespace std;

class unsortedPQ {
private:
	vector <int> pq;
	vector <int> pq1, pq2;
public:
	unsortedPQ() {
		pq.clear();
	}
	bool empty() { return(pq.size() == 0); }
	void insert(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++)
			pq.push_back(v[i]);
	}
	void sort(vector<int>& s) {
		if (empty()) return;
		int size = pq.size();
		s.clear();
		for (int i = 0; i < size; i++) {
			if (pq[i] % 5 == 0) {
				pq1.push_back(pq[i]);
			}
			else
				pq2.push_back(pq[i]);
		}
		int size1 = pq1.size(), size2 = pq2.size();
		for (int i = 0; i < size2; i++) {
			int min_index = 0;
			for (int j = 0; j < size2-i; j++) {
				if (pq2[min_index] > pq2[j])
					min_index = j;
			}
			s.push_back(pq2[min_index]);
			pq2.erase(pq2.begin() + min_index);
		}
		for (int i = 0; i < size1; i++) {
			int min_index = 0;
			for (int j = 0; j < size1 - i; j++) {
				if (pq1[min_index] > pq1[j])
					min_index = j;
			}
			s.push_back(pq1[min_index]);
			pq1.erase(pq1.begin() + min_index);
		}
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
		vector<int> s;
		unsortedPQ pq;
		for (int i = 0; i < N; i++) {
			cin >> input;
			s.push_back(input);
		}
		pq.insert(s);
		pq.sort(s);
		for (int i = 0; i < N; i++)
			cout << s[i] << ' ';
		cout << '\n';
	}
}