#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
private:
	vector <int> pq;
	int root_idx, last_idx;
	bool compare(int idx1, int idx2) {
		return pq[idx1] >= pq[idx2];
	}
	void swap(int idx1, int idx2) {
		int temp = pq[idx1];
		pq[idx1] = pq[idx2];
		pq[idx2] = temp;
	}
	int count;
public:
	heapPQ() {
		pq.clear();
		root_idx = 1;
		last_idx = count = 0;
		pq.push_back(0);
	}
	bool empty() { return (last_idx == 0); }
	int size() { return last_idx; }
	void upheap(int idx) {
		if (idx == root_idx)
			return;
		int par_idx = idx / 2;
		if (compare(idx, par_idx)) {
			swap(idx, par_idx);
			upheap(par_idx);
		}
	}
	void downheap(int idx) {
		int rchild = 2 * idx + 1, lchild = 2 * idx;
		if (rchild <= last_idx) {
			int prior;
			if (compare(lchild, rchild)) prior = lchild;
			else prior = rchild;
			if (compare(prior, idx)) {
				swap(prior, idx);
				downheap(prior);
			}
		}
		else if (lchild <= last_idx) {
			if (compare(lchild, idx)) {
				swap(lchild, idx);
				downheap(lchild);
			}
		}
	}
	void insert(int e) {
		last_idx++;
		pq.push_back(e);
		upheap(last_idx);
	}
	int pop() {
		if (empty()) return -1;
		int root = pq[root_idx];
		pq[root_idx] = pq[last_idx];
		pq.erase(pq.begin() + last_idx);
		last_idx--;
		downheap(root_idx);
		return root;
	}
	int top() {
		if (empty()) return -1;
		return pq[root_idx];
	}
	void solve(int P) {
		if (size() <= 2 && top() > P) {
			cout << "False\n";
			return;
		}
		else if (top() <= P) {
			cout << count << '\n';
			preorder(root_idx);
			cout << '\n';
			return;
		}
		else {
			count++;
			int max = pop();
			pop();
			int min = pop();
			insert((max + min) / 2);
			solve(P);
		}
	}
	void preorder(int idx) {
		int lchild = 2 * idx;
		int rchild = 2 * idx + 1;
		cout << pq[idx] << ' ';
		if (lchild <= last_idx)
			preorder(lchild);
		if (rchild <= last_idx)
			preorder(rchild);
	}
};

int main() {
	int T, N, P, input;
	cin >> T;
	while (T--) {
		heapPQ pq;
		cin >> N >> P;
		for (int i = 0; i < N; i++) {
			cin >> input;
			pq.insert(input);
		}
		pq.solve(P);
	}
}