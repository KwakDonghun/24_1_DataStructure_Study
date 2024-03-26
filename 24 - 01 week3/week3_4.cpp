#include <iostream>
#include <string>

using namespace std;

class node {
private:
	node* next;
	char val;
public:
	node(char v) {
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
	int maxsize;
	liststack() {
		topnode = NULL;
		listsize = 0;
		maxsize = 0;
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
	char top() {
		if (empty())
			return -1;
		return topnode->val;
	}
	void push(char data) {
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		liststack ls;
		cin >> s;
		int size = s.size();
		for (int j = 0; j < size; j++) {
			if (s[j] >= '1' && s[j] <= '9')
				cout << s[j];
			else if (s[j] == '+' || s[j] == '-') {
				while (!ls.empty()) {
					cout << ls.top();
					ls.pop();
				}
				ls.push(s[j]);
			}
			else if (s[j] == '*') {
				while (!ls.empty() && ls.top() == '*')
				{
					cout << ls.top();
					ls.pop();
				}
				ls.push(s[j]);
			}
			if (ls.size() > ls.maxsize)
				ls.maxsize = ls.size();
			
		}
		while (!ls.empty()) {
			cout << ls.top();
			ls.pop();
		}
		cout << ' ' << ls.maxsize << '\n';
	}
}
