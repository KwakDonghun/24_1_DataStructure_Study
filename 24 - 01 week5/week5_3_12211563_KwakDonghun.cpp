#include <iostream>
#include <string>

using namespace std;

class node {
	node* next;
	node* prev;
	int data;
	node(int val) {
		data = val;
		next = prev = NULL;
	}

	friend class linkedlist;
};

class linkedlist {
private:
	node* header;
	node* trailer;
	int n;

public:
	linkedlist() {
		header = new node(0);
		trailer = new node(0);
		n = 0;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
	}
	bool empty() {
		return(n == 0);
	}
	void insert(int idx, int val) {
		if (idx<0 || idx>n) {
			cout << "out_of_range\n";
			return;
		}
		node* cur = header->next;
		for (int i = 0; i < idx; i++)
			cur = cur->next;
		node* newnode = new node(val);
		newnode->next = cur;
		newnode->prev = cur->prev;
		cur->prev->next = newnode;
		cur->prev = newnode;
		n++;
	}
	void erase(int idx) {
		if (idx < 0 || idx >= n) {
			cout << "out_of_range\n";
			return;
		}
		node* del = header->next;
		for (int i = 0; i < idx; i++)
			del = del->next;
		del->next->prev = del->prev;
		del->prev->next = del->next;
		delete del;
		n--;
	}
	void find(int x) {
		node* cur = trailer->prev;
		for (int i = 0; i < n; i++) {
			if (cur->data == x) {
				cout << i << '\n';
				return;
			}
			cur = cur->prev;
		}
		cout << "not_found\n";
	}
	void print(int m) {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		if (m == 0) {
			node* cur = header->next;
			for (int i = 0; i < n; i++) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << '\n';
		}
		else if (m == 1) {
			node* cur = trailer->prev;
			for (int i = 0; i < n; i++) {
				cout << cur->data << ' ';
				cur = cur->prev;
			}
			cout << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, idx, input;
	string command;
	linkedlist list;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> command;
		if (command == "insert") {
			cin >> idx >> input;
			list.insert(idx, input);
		}
		else if (command == "erase") {
			cin >> idx;
			list.erase(idx);
		}
		else if (command == "empty") {
			if (list.empty())
				cout << "true\n";
			else
				cout << "false\n";
		}
		else if (command == "find") {
			cin >> input;
			list.find(input);
		}
		else if (command == "print") {
			cin >> input;
			list.print(input);
		}
	}
}