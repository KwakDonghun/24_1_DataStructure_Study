#include <iostream>
#include <string>

using namespace std;

class node {
private:
	node* next;
	int val;
public:
	node(int v) {
		next = NULL;
		val = v;
	}
	friend class liststack;
};

class liststack {
private:
	node* topnode;
	int listsize;
public:
	liststack() {
		topnode = NULL;
		listsize = 0;
	}
	bool empty() {
		if (listsize == 0)
			return true;
		else
			return false;
	}
	int size() {
		return listsize;
	}
	int top() {
		if (empty())
			return -1;
		return topnode->val;
	}
	void push(int data) {
		node* newnode = new node(data);
		if (empty())
		{
			topnode = newnode;
		}
		else {
			newnode->next = topnode;
			topnode = newnode;
		}
		listsize++;
	}
	void pop(int x) {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < x; i++) {
			if (empty())
				break;
			node* del = topnode;
			cout << topnode->val << ' ';
			topnode = topnode->next;
			delete del;
			listsize--;
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;
	liststack a;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "size") {
			cout << a.size() << '\n';
		}
		else if (s == "empty") {
			if (a.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "top") {
			cout << a.top() << '\n';
		}
		else if (s == "push") {
			cin >> x;
			a.push(x);
		}
		else if (s == "pop") {
			cin >> x;
			a.pop(x);
		}
	}
}