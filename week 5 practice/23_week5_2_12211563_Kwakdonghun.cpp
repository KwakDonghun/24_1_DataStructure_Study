#include <iostream>
#include <string>

using namespace std;

class node {
public:
	int val;
	node* next;
	node* prev;
	node(int v) {
		val = v;
		next = prev = NULL;
	}
};

class doublylist {
private:
	node* header;
	node* trailer;
	int size;
	node* p;
public:
	doublylist() {

		header = new node(0);
		trailer = new node(0);
		header->next = trailer;
		trailer->prev = header;
		begin();
		header->prev = trailer->next = NULL;
		size = 0;
	}
	bool empty() {
		return (size == 0);
	}
	void begin() {
		p = header->next;
	}
	void end() {
		p = trailer;
	}
	void insert(int e) {
		node* newnode = new node(e);
		newnode->next = p;
		newnode->prev = p->prev;
		p->prev->next = newnode;
		p->prev = newnode;
		size++;
	}
	void erase() {
		if (empty())
		{
			cout << "empty\n";
			return;
		}
		if (p == trailer)
			return;
		node* del = p;
		del->prev->next = del->next;
		del->next->prev = del->prev;
		begin();
		delete del;
		size--;
	}
	void nextp() {
		if (p == trailer)
			return;
		p = p->next;
	}
	void prevp() {
		if (p == header->next)
			return;
		p = p->prev;
	}
	void findmultiple(int e) {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		int correct_index = 0;
		begin();
		for (int index = 0; index < size; index++) {
			if ((p->val) % e == 0) {
				cout << index << ' ';
				correct_index++;
			}
			nextp();
		}
		if (correct_index == 0) {
			cout << -1 << '\n';
			return;
		}
		cout << '\n';
	}

	int pval() {
		if (empty())
			return -1;
		return p->val;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case, N, input, command;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		doublylist game;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			game.insert(input);
		}
		game.begin();
		cin >> command;
		for (int j = 0; j < command; j++) {
			cin >> input;
			if (input > 0) {
				for (int k = 0; k < input; k++)
					game.nextp();
			}
			else {
				for (int k = 0; k < (-input); k++)
					game.prevp();
			}
			input = game.pval();
			if (input > 0) {
				for (int k = 0; k < input; k++)
					game.nextp();
			}
			else {
				for (int k = 0; k < (-input); k++)
					game.prevp();
			}
		}
		cout << game.pval() << '\n';
	}
}