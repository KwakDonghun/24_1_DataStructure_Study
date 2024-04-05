#include <iostream>
#include <string>

using namespace std;

class node {
	node* next;
	node* prev;
	string data;
	node(string val) {
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
	node* position;
public:
	linkedlist() {
		header = new node(" ");
		trailer = new node(" ");
		n = 0;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		position = header->next;
	}
	bool empty() {
		return (n == 0);
	}
	void up(int x) {
		if (empty())
			return;
		for (int i = 0; i < x; i++) {
			if (position == header->next)
				break;
			position = position->prev;
		}
	}
	void down(int x) {
		if (empty())
			return;
		for (int i = 0; i < x; i++) {
			if (position == trailer->prev)
				break;
			position = position->next;
		}
	}
	void cut() {
		if (empty())
			return;
		node* del = position;
		if (position == trailer->prev)
			position = del->prev;
		else
			position = del->next;
		del->next->prev = del->prev;
		del->prev->next = del->next;
		delete del;
		n--;
	}
	void append(string name) {
		node* newnode = new node(name);
		if (empty()) {
			newnode->next = trailer;
			newnode->prev = header;
			header->next = newnode;
			trailer->prev = newnode;
		}
		else {
			newnode->next = position->next;
			newnode->prev = position;
			position->next->prev = newnode;
			position->next = newnode;
		}
		position = newnode;
		n++;
	}
	void print() {
		if (n <= 0) {
			cout << "And Then There Were None\n";
		}
		else {
			node* cur = header->next;
			for (int i = 0; i < n; i++) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << '\n';
		}
	}
	void position_reset(int idx) {
		position = header->next;
		down(idx);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, N, M, K, input;
	string name, command;
	cin >> testcase;
	for (int j = 0; j < testcase; j++) {
		linkedlist list;
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			cin >> name;
			list.append(name);
		}
		list.position_reset(K);
		for (int i = 0; i < M; i++) {
			cin >> command;
			if (command == "up") {
				cin >> input;
				list.up(input);
			}
			else if (command == "down") {
				cin >> input;
				list.down(input);
			}
			else if (command == "cut") {
				list.cut();
			}
			else if (command == "append") {
				cin >> name;
				list.append(name);
			}
		}
		list.print();
	}
}