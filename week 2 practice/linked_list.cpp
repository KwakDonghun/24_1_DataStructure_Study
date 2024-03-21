#include <iostream>

using namespace std;

class node1 {
private:
	int val;
	node1* next;

public:
	node1(int v) {
		val = v;
		next = NULL;
	}

	node1() {
		val = 0;
		next = NULL;
	}
	void setnext(node1* n) {
		this->next = n;
	}
	node1* getnext() {
		return next;
	}
	int getval() {
		return val;
	}

	friend class linkedlist;
};

class linkedlist {
private:
	int size=0;
	node1* head;
	node1* tail;
public:
		
	void print() {
		if (head == NULL) {
			cout << "empty" << '\n';
			return;
		}
		node1* newnode = head;
		while (true) {
			cout << newnode->getval() << ' ';
			if (newnode->getnext() != NULL) {
				newnode = newnode->getnext();
			}
			else
				break;
		}
		cout << '\n';
	}
	void addfront(int x) {
		node1* newnode = new node1(x);
		if (head == NULL) {
			head = tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
		size++;
	}
	void removefront() {
		if (head == NULL) {
			cout << "empty" << '\n';
			return;
		}
		cout << head->val << '\n';
		head = head->next;
		size--;
	}
	void update(int i, int x) {
		if (i < 0 || i >= size) {
			cout << "error\n";
			return;
		}
		node1* newnode = head;
		for (int j = 0; j < i; j++) {
			newnode = newnode->next;
		}
		newnode->val = x;
	}
	void min() {
		if (head == NULL) {
			cout << "empty" << '\n';
			return;
		}
		node1* newnode = head;
		int n=0, mini=10001;
		for (int i = 0; i < size; i++) {
			if (mini > newnode->val){
				n = i;
				mini = newnode->val;
			}
			newnode = newnode->next;
		}

		cout << n << ' ' << mini << '\n';
	}
};
/*
int main() {
	int n, x, j;
	string s;
	linkedlist l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Print") {
			l.print();
			continue;
		}
		else if (s == "AddFront") {
			cin >> x;
			l.addfront(x);
			continue;
		}
		else if (s == "RemoveFront") {
			l.removefront();
			continue;
		}
		else if (s == "Update") {
			cin >> j >> x;
			l.update(j, x);
			continue;
		}
		else if (s == "Min") {
			l.min();
			continue;
		}
	}
}
*/

class node2 {
private:
	int val;
	node2* next;
	node2* prev;

public:
	node2(int v) {
		val = v;
		next = NULL;
		prev = NULL;
	}

	node2() {
		val = 0;
		next = NULL;
		prev = NULL;
	}
	void setnext(node2* n) {
		this->next = n;
	}
	node2* getnext() {
		return next;
	}
	void setprev(node2* n) {
		this->prev = n;
	}
	node2* getprev() {
		return prev;
	}
	int getval() {
		return val;
	}

	friend class doublylinkedlist;
};

class doublylinkedlist {
private:
	node2* header;
	node2* trailer;
	int size = 0;
public:
	doublylinkedlist() {
		size = 0;
		header = new node2;
		trailer = new node2;
		header->val = trailer->val = 0;
		header->next = trailer;
		trailer->prev = trailer;
	}
	bool empty() {
		if (size <= 0)
			return true;
		else
			return false;
	}
	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node2* newnode = header->next;
		for (int i = 0; i < size; i++) {
			cout << newnode->val << ' ';
			newnode = newnode->next;
		}
		cout << '\n';
	}
	void insert(int i, int x) {
		node2* newnode = new node2;
		newnode->val = x;
		if (i<0 || i>size) {
			cout << "error\n";
			return;
		}
		if (i == 0) {
			newnode->next = header->next;
			newnode->prev = header;
			header->next->prev = newnode;
			header->next = newnode;
		}
		else if (size == i) {
			newnode->next = trailer;
			newnode->prev = trailer->prev;
			trailer->prev->next = newnode;
			trailer->prev = newnode;
		}
		else {
			node2* cur = header->next;
			for (int j = 1; j < i; j++)
				cur = cur->next;
			newnode->prev = cur;
			newnode->next = cur->next;
			cur->next->prev = newnode;
			cur->next = newnode;
		}
		size++;
	}
	void remove(int i) {
		if (empty()|| i>=size) {
			cout << "error\n";
			return;
		}
		else {
			node2* del = header->next;
			for (int j = 0; j < i; j++)
				del = del->next;
			del->prev->next = del->next;
			del->next->prev = del->prev;
			cout << del->val << '\n';
			delete del;
			size--;
		}
	}
	void removeall(int x) {
		int count = 0;
		if (empty()) {
			cout << "not found\n";
			return;
		}
		node2* cur = header->next;
		while (cur != NULL) {
			if (cur->val == x) {
				count++;
				size--;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				node2* del = cur;
				cur = cur->next;
				delete del;
				continue;
			}
			cur = cur->next;
		}
		if (count == 0)
			cout << "not found\n";
		else
			cout << count << '\n';
	}
	void neighbormax(int i) {
		if (empty() || i >= size) {
			cout << "error\n";
			return;
		}
		node2* cur = header->next;
		for (int j = 0; j < i; j++)
			cur = cur->next;
		int max = cur->prev->val;
		if (max < cur->next->val)
			max = cur->next->val;

		cout << max << '\n';
	}
};

int main() {
	int n, x, j;
	string s;
	doublylinkedlist l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Print") {
			l.print();
			continue;
		}
		else if (s == "Insert") {
			cin >> j >> x;
			l.insert(j, x);
			continue;
		}
		else if (s == "Remove") {
			cin >> j;
			l.remove(j);
			continue;
		}
		else if (s == "RemoveAll") {
			cin >> x;
			l.removeall(x);
			continue;
		}
		else if (s == "NeighborMax") {
			cin >> j;
			l.neighbormax(j);
			continue;
		}
	}
}