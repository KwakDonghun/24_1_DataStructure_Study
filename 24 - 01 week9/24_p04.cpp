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
		if (lhs_count == rhs_count) return lhs < rhs; //자릿수 같을 때 왼쪽이 작으면 true
		else return (lhs_count > rhs_count ? true : false); //왼쪽 자릿수가 작으면 true
	}
};
class sortedPQ {
private:
	compare C;
	vector<int> pq;
public:
	int getsize() { return pq.size(); }
	bool empty() { return (getsize() == 0); }
	void push(vector<int> v) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			int j;
			for (j = 0; j < pq.size(); j++) {
				if (C(pq[j], v[0])) break;
			}
			pq.insert(pq.begin()+j, v[0]);
			v.erase(v.begin());
		}
	}
	int top() {
		if (empty()) return -1;
		return pq.back();
	}
	void pop() {
		if (empty()) return;
		pq.pop_back();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input;
	cin >> T;
	for (int j = 1; j <= T; j++) {
		vector<int> s;
		sortedPQ pq;
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