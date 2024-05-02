#include <iostream>
#include <vector>
#include <string>

using namespace std;

class unsortedPQ {
private:
	vector <int> pq;
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
	int max() {
		int min_index = 0;
		for (int i = 0; i < pq.size(); i++)
			if (pq[min_index] < pq[i])
				min_index = i;
		return pq[min_index];
	}
	void removemax() {
		int max_index = 0;
		for (int i = 0; i < pq.size(); i++)
			if (pq[max_index] < pq[i])
				max_index = i;
		pq.erase(pq.begin() + max_index);
	}
	void sort(vector<int>& s) {
		if (empty()) return;
		int size = pq.size();
		s.clear();
		for (int i = 0; i < size; i++) {
			if (pq.size() <= 0) break;
			s.push_back(max());
			removemax();
		}
	}
};

int main() {
	int T, N, input;
	cin >> T;
	while (T--) {
		unsortedPQ pq;
		vector<int> s;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			s.push_back(input);
		}
		pq.insert(s);
		pq.sort(s);
		for (int i = 0; i < N; i++)
			cout << s[i] << ' ';
		cout << '\n';
		for (int i = 1; i < N; i++)
			cout << s[0] - s[i] << ' ';
		cout << '\n';
	}
}