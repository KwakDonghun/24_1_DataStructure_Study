#include <iostream>
#include <string>

using namespace std;

/*
class arrayqueue {
private:
	int* arr;
	int frontindex;
	int rearindex;
	int capacity;
	int size;
public:
	arrayqueue(int c) {
		capacity = c;
		arr = new int[capacity];
		frontindex = rearindex = 0;
		size = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	int getsize() {
		return size;
	}
	int front() {
		if (empty())
			return -1;
		return arr[frontindex];
	}
	void enqueue(int data) {
		if (size >= capacity)
			return;
		arr[rearindex] = data;
		rearindex = (rearindex + 1) % capacity;
		size++;
	}
	void dequeue() {
		if (empty())
			return;
		frontindex=(frontindex + 1) % capacity;
		size--;
	}
};
class node {
private:
	int data;
	node* next;
public:
	node(int val){
		data = val;
		next = NULL;
	}
	friend class listqueue;
};
class listqueue {
private:
	node* frontnode;
	node* rearnode;
	int size;
public:
	listqueue() {
		frontnode = NULL;
		rearnode = NULL;
		size = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	int getsize() {
		return size;
	}
	int front() {
		if (empty())
			return -1;
		return frontnode->data;
	}
	void enqueue(int val) {
		node* newnode = new node(val);
		if (empty())
		{
			newnode = frontnode;
			frontnode->next = rearnode;
		}
		else {
			newnode = rearnode;
			rearnode = rearnode->next;
		}
		size++;
	}
	void dequeue() {
		if (empty())
			return;
		node* del = frontnode;
		frontnode = frontnode->next;
		delete del;
		size--;
	}
};
*/

//23_04_01
/*
class node {
public:
	int value;
	node* next;
	node(int val) {
		value = val;
		next = NULL;
	}
};
class listqueue {
private:
	int size;
	node* front;
	node* rear;
public:
	listqueue() {
		size = 0;
		front = NULL;
		rear = NULL;
	}
	int getsize() {
		return size;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	void getfront() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << front->value << '\n';
	}
	void getrear() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << rear->value << '\n';
	}
	void enqueue(int val) {
		node* newnode = new node(val);
		if (empty()) {
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
		cout << del->value << '\n';
		delete del;
		size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x;
	string s;
	listqueue q;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "size") {
			cout << q.getsize() <<'\n';
		}
		else if (s == "isEmpty") {
			if (q.empty())
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (s == "front") {
			q.getfront();
		}
		else if (s == "rear") {
			q.getrear();
		}
		else if (s == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}
*/
//23_04_02
/*
class node {
public:
	int value;
	node* next;
	node(int val) {
		value = val;
		next = NULL;
	}
};
class listqueue {
private:
	int size;
	node* front;
	node* rear;
public:
	listqueue() {
		size = 0;
		front = NULL;
		rear = NULL;
	}
	int getsize() {
		return size;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	int getfront() {
		if (empty()) {
			return -1;
		}
		return front->value;
	}
	void plusfront(int n) {
		if (empty())
			return;
		front->value = front->value + n;
	}
	void enqueue(int val) {
		node* newnode = new node(val);
		if (empty()) {
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
		delete del;
		size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		listqueue q1, q2;
		int score1=0, score2=0, lasthp;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			q1.enqueue(x);
		}
		for (int j = 0; j < n; j++) {
			cin >> x;
			q2.enqueue(x);
		}
		for (int j = 1; j <= n; j++) {
			if (q1.getfront() > q2.getfront()) {
				score1++;
				lasthp = q1.getfront() - q2.getfront();
				cout << "Round" << j << ' ' << q1.getfront() << '>' << q2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				q1.dequeue();
				q2.dequeue();
				q1.plusfront(lasthp);
			}else if (q1.getfront() < q2.getfront()) {
				score2++;
				lasthp = q2.getfront() - q1.getfront();
				cout << "Round" << j << ' ' << q1.getfront() << '<' << q2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				q1.dequeue();
				q2.dequeue();
				q2.plusfront(lasthp);
			}else if (q1.getfront() == q2.getfront()) {
				cout << "Round" << j << ' ' << q1.getfront() << '=' << q2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				q1.dequeue();
				q2.dequeue();
			}
		}
		if (score1 > score2)
			cout << "Winner P1\n";
		else if (score1 < score2)
			cout << "Winner P2\n";
		else
			cout << "Draw\n";
	}
}
*/
/*
class arrayqueue {
private:
	int capacity;
	int* arr;
	int size;
	int frontindex;
	int rearindex;
public:
	arrayqueue(int c) {
		capacity = c;
		size = 0;
		arr = new int[capacity];
		frontindex = 0;
		rearindex = 0;
	}
	void getsize() {
		cout << size << '\n';
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	bool full() {
		if (capacity <= size)
			return true;
		return false;
	}
	void front() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << arr[frontindex] << '\n';
	}
	void rear() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << arr[(rearindex - 1+capacity)%capacity] << '\n';
	}
	void enqueue(int val) {
		if (capacity <= size)
		{
			cout << "Full\n";
			return;
		}
		arr[rearindex] = val;
		rearindex = (rearindex + 1) % capacity;
		size++;
	}
	void dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << arr[frontindex] << '\n';
		frontindex = (frontindex + 1) % capacity;
		size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, x;
	string s;
	cin >> n >> t;
	arrayqueue q(n);
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "size") {
			q.getsize();
		}
		else if (s == "isEmpty") {
			if (q.empty())
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (s == "full") {
			if (q.full())
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
		else if (s == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}
*/

//23_04_04
class node {
public:
	int value;
	node* next;
	node(int val) {
		value = val;
		next = NULL;
	}
};
class listqueue {
private:
	int size;
	node* front;
	node* rear;
public:
	listqueue() {
		size = 0;
		front = NULL;
		rear = NULL;
	}
	int getsize() {
		return size;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	int getfront() {
		if (empty()) {
			return -1;
		}
		return front->value;
	}
	void plusfront(int n) {
		if (empty())
			return;
		front->value = front->value + n;
	}
	void enqueue(int val) {
		node* newnode = new node(val);
		if (empty()) {
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
		delete del;
		size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		listqueue q1, q2;
		int score1 = 0, score2 = 0, lasthp;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			q1.enqueue(x);
		}
		for (int j = 0; j < n; j++) {
			cin >> x;
			q2.enqueue(x);
		}
		for (int j = 1; j <= n; j++) {
			if (q1.getfront() > q2.getfront()) {
				score1++;
				lasthp = q1.getfront() - q2.getfront();
				cout << "Round" << j << " P1 " << lasthp << '\n';
				q1.dequeue();
				q2.dequeue();
				q2.plusfront(lasthp);
			}
			else if (q1.getfront() < q2.getfront()) {
				score2++;
				lasthp = q2.getfront() - q1.getfront();
				cout << "Round" << j << " P2 " << lasthp << '\n';
				q1.dequeue();
				q2.dequeue();
				q1.plusfront(lasthp);
			}
			else if (q1.getfront() == q2.getfront()) {
				cout << "Round" << j << " Draw\n";
				q1.dequeue();
				q2.dequeue();
			}
		}
		if (score1 > score2)
			cout << "Total score " << score1 << ':' << score2 << " Winner P1\n";
		else if (score1 < score2)
			cout << "Total score " << score1 << ':' << score2 << " Winner P2\n";
		else
			cout << "Total score " << score1 << ':' << score2 << " Draw\n";
	}
}