#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
public:
	vector<int> pq;
	int root, last;
	void swap(int idx1, int idx2) {
		int temp = pq[idx1];
		pq[idx1] = pq[idx2];
		pq[idx2] = temp;
	}
	bool compare(int idx1, int idx2) {
		return pq[idx1] < pq[idx2];
	}
	heapPQ() {
		pq.clear();
		root = 1, last = 0;
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
	void push(int i) {
		last++;
		pq.push_back(i);
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
	void top() {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		cout << pq[root] << '\n';
	}
	void pop() {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		cout << pq[root] << '\n';
		pq[root] = pq[last];
		pq.erase(pq.begin() + last);
		last--;
		downheap(root);
	}
	void second_top() {
		if (last < 2) {
			cout << "Error\n";
			return;
		}
		else if (last == 2)
			cout << pq[2] << '\n';
		else {
			if (compare(2, 3)) cout << pq[2] << '\n';
			else cout << pq[3] << '\n';
		}
		
	}
};

int main() {
	int N, input;
	string cmd;
	heapPQ pq;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "empty") {
			if (pq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "size") {
			cout << pq.size() << '\n';
		}
		else if (cmd == "push") {
			cin >> input;
			pq.push(input);
		}
		else if (cmd == "pop") {
			pq.pop();
		}
		else if (cmd == "top") {
			pq.top();
		}
		else if (cmd == "second_top") {
			pq.second_top();
		}
	}
}