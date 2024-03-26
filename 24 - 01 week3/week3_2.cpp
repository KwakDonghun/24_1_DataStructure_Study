#include <iostream>
#include <string>

using namespace std;

class arraystack {
private:
	int* arr;
	int capacity;
	int topindex;
public:
	arraystack(int c) {
		capacity = c;
		arr = new int[capacity];
		topindex = -1;
	}
	arraystack() {
		capacity = 100;
		arr = new int[capacity];
		topindex = -1;
	}
	bool empty() {
		if (topindex == -1)
			return true;
		else
			return false;
	}
	int size() {
		return topindex + 1;
	}
	int top() {
		if (empty())
			return -1;
		else
			return arr[topindex];
	}
	void push(int data) {
		if (capacity <= size()) {
			cout << "FULL\n";
			return;
		}
		arr[++topindex] = data;
	}
	void pop() {
		if (empty())
			return;
		topindex--;
	}
};

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
	void pop() {
		if (empty())
			return;
		node* del = topnode;
		topnode = topnode->next;
		delete del;
		listsize--;
	}
};
/*
// linked list stack

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		liststack ls;
		cin >> s >> k;
		int size = s.size();
		for (int j = 0; j < size; j++) {
			if (s[j] >= '1' && s[j] <= '9')
				ls.push(s[j] - '0');
			else if (s[j] == '+' || s[j] == '-' || s[j] == '*') {
				int second = ls.top();
				ls.pop();
				int first = ls.top();
				ls.pop();
				if (s[j] == '+') {
					ls.push(first + second);
				}
				else if (s[j] == '-') {
					ls.push(first - second);
				}
				else if (s[j] == '*') {
					ls.push(first * second);
				}
			}
		}
		if(ls.top()<0)
			cout << (-ls.top())% k << '\n';
		else
			cout << ls.top() % k << '\n';

		ls.pop();
	}
}*/

//array stack

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, mod;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		arraystack as;
		cin >> s >> mod;
		int size = s.size();
		for (int j = 0; j < size; j++) {
			if (s[j] >= '1' && s[j] <= '9')
				as.push(s[j] - '0');
			else if (s[j] == '*' || s[j] == '+' || s[j] == '-') {
				int second = as.top();
				as.pop();
				int first = as.top();
				as.pop();
				if (s[j] == '+')
					as.push(first + second);
				if (s[j] == '-')
					as.push(first - second);
				if (s[j] == '*')
					as.push(first * second);
			}
		}
		if (as.top() > 0)
			cout << as.top() % mod << '\n';
		else
			cout << -as.top() % mod << '\n';
	}
}