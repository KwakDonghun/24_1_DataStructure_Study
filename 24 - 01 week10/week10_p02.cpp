#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
public:
	vector<int> pq;
	int root = 1, last;
	bool compare(int lhs, int rhs) {
		if (pq[lhs] % 2 == pq[rhs] % 2) {
			if (pq[lhs] % 2 == 1)
				return pq[lhs] > pq[rhs];
			else
				return pq[lhs] < pq[rhs];
		}
		else {
			return pq[lhs] % 2 == 1;
		}
	}
	void swap(int lhs, int rhs) {
		int temp = pq[lhs];
		pq[lhs] = pq[rhs];
		pq[rhs] = temp;
	}
	heapPQ() {
		pq.clear();
		last = 0;
		pq.push_back(0);
	}
	bool empty() { return (last == 0); }
	int size() { return last; }
	void upheap(int idx) {
		if (idx == root) return;
		int par = idx / 2;
		if (compare(idx, par)) {
			swap(idx, par);
			upheap(par);
		}
	}
	void push(int v) {
		last++;
		pq.push_back(v);
		upheap(last);
	}
	void downheap(int idx) {
		int lchild = 2 * idx, rchild = 2 * idx + 1;
		if (rchild <= last) {
			int prior;
			compare(lchild, rchild) ? prior = lchild : prior = rchild;
			if (compare(prior, idx)) {
				swap(prior, idx);
				downheap(prior);
			}
		}
		else if (lchild <= last) {
			if (compare(lchild, idx)) {
				swap(lchild, idx);
				downheap(lchild);
			}
		}
	}
	int top() {
		if (empty()) return -1;
		return pq[root];
	}
	int pop() {
		if (empty()) return -1;
		int top_val = top();
		pq[root] = pq[last];
		pq.pop_back();
		last--;
		downheap(root);
		return top_val;
	}
};
int main() {
	int T, N, input;
	cin >> T;
	while (T--) {
		heapPQ pq;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			pq.push(input);
		}
		for (int i = 0; i < N; i++) {
			cout << pq.pop() << ' ';
		}
		cout << '\n';
	}
}