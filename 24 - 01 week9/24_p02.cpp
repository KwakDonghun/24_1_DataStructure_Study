#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& rhs) {
		int lhs_count = 0; int rhs_count = 0;
		int lhs_val = lhs, rhs_val = rhs;
		while (1) {
			if (lhs_val % 10 == lhs_val) break;
			else {
				lhs_val /= 10;
				lhs_count++;
			}
		}
		while (1) {
			if (rhs_val % 10 == rhs_val) break;
			else {
				rhs_val /= 10;
				rhs_count++;
			}
		}
		if (lhs_count == rhs_count) return lhs > rhs;
		else return (lhs_count < rhs_count ? true : false);
	}
};
class unsortedPQ {
private:
	compare C;
	vector<int> pq;
public:
	int getsize() { return pq.size(); }
	bool empty() { return (getsize() == 0); }
	void push(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++)
			pq.push_back(v[i]);
	}
	int top() {
		if (empty()) return -1;
		int idx = 0;
		for (int i = 0; i < pq.size(); i++)
			if (C(pq[i], pq[idx]))
				idx = i;
		return pq[idx];
	}
	void pop() {
		if (empty()) return;
		int idx = 0;
		for (int i = 0; i < pq.size(); i++)
			if (C(pq[i], pq[idx]))
				idx = i;
		pq.erase(pq.begin() + idx);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input;
	cin >> T;
	for(int j = 1; j <= T; j++) {
		vector<int> s;
		unsortedPQ pq;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			s.push_back(input);
		}
		pq.push(s);
		cout << "Case #" << j << ".\n";
		for (int i = 0; i < N; i++) {
			cout << pq.top() << ' ';
			pq.pop();
		}
		cout << '\n';
	}
}