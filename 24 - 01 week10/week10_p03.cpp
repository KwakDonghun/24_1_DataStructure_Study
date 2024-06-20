#include <iostream>
#include <vector>

using namespace std;

class heapPQ {
public:
	vector<int> pq;
	int root = 1, last;
	void swap(int idx1, int idx2) {
		int temp = pq[idx1];
		pq[idx1] = pq[idx2];
		pq[idx2] = temp;
	}
	bool compare(int idx1, int idx2) {
		return pq[idx1] > pq[idx2];
	}
	heapPQ() {
		pq.clear();
		last = 0;
		pq.push_back(0);
	}
	int size() { return last; }
	bool empty() { return (last == 0); }
	void upheap(int idx) {
		if (idx == root) return;
		int par = idx / 2;
		if (compare(idx, par)) {
			swap(idx, par);
			upheap(par);
		}
	}
	void push(int e) {
		last++;
		pq.push_back(e);
		upheap(last);
	}
	void downheap(int idx) {
		int lchild = 2 * idx;
		int rchild = 2 * idx + 1;
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
	int pop() {
		if (empty()) return -1;
		int top_val = pq[root];
		pq[root] = pq[last];
		pq.erase(pq.begin() + last);
		last--;
		downheap(root);
		return top_val;
	}
	int top() {
		if (empty()) return -1;
		return pq[root];
	}
	void second_top() {
		if (size() < 2) {
			cout << "Error\n";
			return;
		}
		int top_val = pq[root];
		pop();
		cout << top() << '\n';
		push(top_val);
	}
};

int main() {
	int N, input;
	string cmd;
	heapPQ pq;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "size") {
			cout << pq.size() << '\n';
		}
		else if (cmd == "empty") {
			if (pq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "push") {
			cin >> input;
			pq.push(input);
		}
		else if (cmd == "pop") {
			cout << pq.pop() << '\n';
		}
		else if (cmd == "top") {
			cout << pq.top() << '\n';
		}
		else if (cmd == "second_top") {
			pq.second_top();
		}
	}
}