#include <iostream>
#include <string>

using namespace std;

class node {
private:
	int val;
	node* next;
public:
	node() {
		val = 0;
		next = NULL;
	}
	node(int x) {
		val = x;
		next = nullptr;
	}

	friend class singlylinkedlist;
};

class singlylinkedlist {
private:
	node* head;
	node* tail;
	int size;

public:
	singlylinkedlist() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	void append(int v) {
		node* newnode = new node(v);
		if (empty())
			head = tail = newnode;
		else {
			tail->next = newnode;
			tail = newnode;
		}
		size++;

		print();
	}
	void deletion(int idx) {
		if (idx < 0 || idx >= size || empty()) {
			cout << -1 << '\n';
			return;
		}
		node* cur = head;
		if (idx == 0) {
			if (size == 1)
				head = tail = NULL;
			else
				head = head->next;
		}
		else {
			node* pre = head;
			for (int j = 0; j < idx; j++) {
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			if (cur == tail)
				tail = pre;
		}
		cout << cur->val << '\n';
		delete cur;
		size--;
	}
	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* cur = head;
		while (cur != NULL) {
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << '\n';
	}
	void sum() {
		int s = 0;
		if (empty()) {
			cout << 0 << '\n';
			return;
		}
		node* cur = head;
		while (cur != NULL) {
			s += cur->val;
			cur = cur->next;
		}
		cout << s << '\n';
	}
	void aftermin(int idx) {
		if (idx < 0 || idx >= size || empty()) {
			cout << "error\n";
			return;
		}
		node* cur = head;
		for (int i = 0; i < idx; i++)
			cur = cur->next;
		int min = cur->val;
		while (cur != NULL) {
			if (min > cur->val)
				min = cur->val;
			cur = cur->next;
		}
		cout << min << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, idx, x;
	cin >> n;
	string s;
	singlylinkedlist li;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Append") {
			cin >> x;
			li.append(x);
		}
		else if (s == "AfterMin") {
			cin >> idx;
			li.aftermin(idx);
		}
		else if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Print") {
			li.print();
		}
		else if (s == "Sum") {
			li.sum();
		}
	}
}