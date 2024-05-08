#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
private:
	int last_idx, root_idx;
	vector<int> pq;
	bool compare(int idx1, int idx2) {
		return pq[idx1] > pq[idx2];
	}
	void swap(int idx1, int idx2) {
		int temp = pq[idx1];
		pq[idx1] = pq[idx2];
		pq[idx2] = temp;
	}
public:
	heapPQ() {
		pq.clear();
		root_idx = 1;
		last_idx = 0;
		pq.push_back(0);
	}
	bool empty() { return (last_idx == 0); }
	int size() { return last_idx; }
	void upheap(int idx) {
		if (idx == root_idx)
			return;
		int par = idx / 2;
		if (compare(idx, par)) {
			swap(idx, par);
			upheap(par);
		}
	}
	void downheap(int idx) {
		int lchild = 2 * idx;
		int rchild = 2 * idx + 1;
		if (rchild <= last_idx) {
			int prior;
			if (compare(lchild, rchild))
				prior = lchild;
			else
				prior = rchild;
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
	void print() {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 1; i <= last_idx; i++)
			cout << pq[i] << ' ';
		cout << '\n';
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, args;
	string cmd;
	heapPQ pq;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "isEmpty") {
			if (pq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "size") {
			cout << pq.size() << '\n';
		}
		else if (cmd == "insert") {
			cin >> args;
			pq.insert(args);
		}
		else if (cmd == "pop") {
			cout << pq.pop() << '\n';
		}
		else if (cmd == "top") {
			cout << pq.top() << '\n';
		}
		else if (cmd == "print") {
			pq.print();
		}
	}
}