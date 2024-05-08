#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
private:
	vector<int> pq;
	int last_idx;
	int root_idx;
	bool compare(int idx1, int idx2) {
		return pq[idx1] <= pq[idx2];
	}
	void swap(int idx1, int idx2) {
		int temp = pq[idx1];
		pq[idx1] = pq[idx2];
		pq[idx2] = temp;
	}
public:
	heapPQ(){
		pq.clear();
		last_idx = 0;
		root_idx = 1;
		pq.push_back(0);
	}
	bool empty() { return (last_idx == 0); }
	int size() { return last_idx; }
	void upheap(int index) {
		if (index == root_idx)
			return;
		int par_idx = index / 2;
		if (compare(index,par_idx)) {
			swap(index, par_idx);
			upheap(par_idx);
		}
	}
	void downheap(int idx) {
		int lchild = 2 * idx, rchild = 2 * idx + 1;
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
	void insert(int i) {
		last_idx++;
		pq.push_back(i);
		upheap(last_idx);
	}
	int pop() {
		if (empty()) return -1;
		int root = pq[1];
		pq[1] = pq[last_idx];
		pq.erase(pq.begin() + last_idx);
		last_idx--;
		downheap(root_idx);
		return root;
	}
	int top() {
		if (empty()) return -1;
		return pq[1];
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