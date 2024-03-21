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
	void del(int e) {
		node* pre = head;
		node* cur = head;
		for (int i = 0; i < size; i++) {
			if (cur->val == e) {
				if (i == 0) {
					head = cur->next;
				}
				else {
					pre->next = cur->next;
				}
				size--;
				delete cur;
				return;
			}
			pre = cur;
			cur = cur->next;
		}
	}
	void search(int v) {
		node* cur = head;
		for (int i = 0; i < size; i++) {
			if (cur->val == v) {
				cout << i << '\n';
				return;
			}
			cur = cur->next;
		}
	}
	void merge(singlylinkedlist* l1, singlylinkedlist* l2) {
		head = l1->head;
		node* cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = l2->head;
		while (cur->next != NULL)
			cur = cur->next;
		tail = cur;
		cur = head;
		size = l1->size + l2->size;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, input, y, e, v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		singlylinkedlist l1, l2, lm;
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> input;
			l1.append(input);
		}
		cin >> y;
		for (int j = 0; j < y; j++) {
			cin >> input;
			l1.append(input);
		}
		lm.merge(&l1, &l2);
		lm.print();
		cin >> e;
		lm.del(e);
		lm.print();
		cin >> v;
		lm.search(v);
	}
}