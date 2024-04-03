#include <iostream>
#include <string>

using namespace std;

class node {
public:
	int val;
	node* next;
	node(int v) {
		val = v;
		next = nullptr;
	}
};

class listqueue {
private:
	node* front;
	node* rear;
	int size;
public:
	listqueue() {
		size = 0;
		front = rear = NULL;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	int getsize() {
		return size;
	}
	int getfront() {
		if (empty())
			return -1;
		return front->val;
	}
	int getrear() {
		if (empty())
			return -1;
		return rear->val;
	}
	void enqueue(int v) {
		node* newnode = new node(v);
		if (size == 0) {
			front = rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
		size++;
	}
	void dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		node* del = front;
		front = front->next;
		cout << del->val << '\n';
		delete del;
		size--;
	}
	void frontnsum(int n) {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		if (n > size) {
			cout << "error\n";
			return;
		}
		int sum = 0;
		node* cur = front;
		for (int i = 0; i < n; i++) {
			sum += cur->val;
			cur = cur->next;
		}
		cout << sum << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(nullptr);

	int t, x;
	string s;
	listqueue q;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "size") {
			cout << q.getsize() << '\n';
		}
		else if (s == "isEmpty") {
			if (q.empty())
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (s == "rear") {
			if (q.getrear() == -1)
				cout << "Empty\n";
			else
				cout << q.getrear() << '\n';
		}
		else if (s == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
		else if (s == "frontNsum") {
			cin >> x;
			q.frontnsum(x);
		}
	}
}
