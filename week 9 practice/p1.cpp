#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PriorityQueue {
private:
	int size;
	vector <int> pq;
public:
	PriorityQueue() {
		pq.clear();
		size = 0;
	}
	void insert(vector<int>& S) { //삽입정렬
		 size = S.size();
		 pq.push_back(S[0]);
		 for (int i = 1; i < size; i++) {
			 pq.push_back(S[i]);
			 for (int j = i; j > 0; j--) {
				 if (pq[j-1] > pq[j]) {
					 int temp = pq[j];
					 pq[j] = pq[j - 1];
					 pq[j - 1] = temp;
				 }
			 }
		 }
		 S = pq;
	}
};
int main() {
	int T, N, input;
	cin >> T;
	while (T--) {
		PriorityQueue PQ;
		cin >> N;
		vector <int> s;
		for (int i = 0; i < N; i++) {
			cin >> input;
			s.push_back(input);
		}
		PQ.insert(s);
		for (int i = 0; i < N; i++)
			cout << s[i] << ' ';
		cout << '\n';
		for (int i = 1; i < N; i++)
			cout << s[0] + s[i] << ' ';
		cout << '\n';
	}
}