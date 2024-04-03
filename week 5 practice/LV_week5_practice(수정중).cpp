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
		header->next = trailer;
		trailer->prev = header;
		p = header;
		header->prev = trailer->next = NULL;
		size = 0;
	}
	bool empty() {
		return (size == 0);
	}
	node* begin() {
		return header->next;
	}
	node* end() {
		return trailer;
	}
	void insert(int e) {
		node* newnode = new node(e);
		if (p == header) {

		}
	}
	void erase() {
		if (p == trailer)
			return;
		if (empty())
		{
			cout << "empty\n";
			return;
		}
		node* del = p;
		del->prev->next = del->next;
		del->next->prev = del->prev;
		p = begin();
		delete del;
		size--;
	}
	void nextp() {
		if (p == trailer)
			return;
		p = p->next;
	}
	void prevp() {
		if (p == header)
			return;
		p = p->prev;
	}
	void findmultiple(int e) {

	}
};