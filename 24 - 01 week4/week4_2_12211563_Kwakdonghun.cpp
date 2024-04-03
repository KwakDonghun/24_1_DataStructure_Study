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
		delete del;
		size--;
	}
	void plusfront(int n) {
		if (empty())
			return;
		front->val += n;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(nullptr);

	int t, n, input, score1, score2, hp, lastwin = 0;
	cin >> t;
	for (int j = t; j > 0; j--) {
		listqueue p1, p2;
		score1 = score2 = hp = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> input;
			p1.enqueue(input);
		}
		for (int i = 0; i < n; i++) {
			cin >> input;
			p2.enqueue(input);
		}
		for (int i = 1; i <= n; i++) {
			if (p1.getfront() > p2.getfront()) {
				score1++;
				cout << "Round" << i << ' ' << p1.getfront() << '>' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				hp = p1.getfront() - p2.getfront();
				p1.dequeue();
				p2.dequeue();
				p1.plusfront(hp);
				if (i == n)
					lastwin = 1;
			}
			else if (p1.getfront() < p2.getfront()) {
				score2++;
				cout << "Round" << i << ' ' << p1.getfront() << '<' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				hp = p2.getfront() - p1.getfront();
				p1.dequeue();
				p2.dequeue();
				p2.plusfront(hp);
				if (i == n)
					lastwin = 2;
			}
			else {
				cout << "Round" << i << ' ' << p1.getfront() << '=' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
				p1.dequeue();
				p2.dequeue();
				if (i == n)
					lastwin = 0;
			}
		}
		if (score1 > score2)
			cout << "Winner P1\n";
		else if (score2 > score1)
			cout << "Winner P2\n";
		else {
			if (lastwin == 0)
				cout << "Draw\n";
			else if (lastwin == 1)
				cout << "Winner P1\n";
			else if (lastwin == 2)
				cout << "Winner P2\n";
		}
	}
}



//class arrayqueue {
//private:
//	int* arr;
//	int capacity;
//	int size;
//	int front;
//	int rear;
//public:
//	arrayqueue(int c) {
//		capacity = c;
//		arr = new int[capacity];
//		size = 0;
//		front = rear = 0;
//	}
//	arrayqueue() {
//		capacity = 100;
//		arr = new int[capacity];
//		size = 0;
//		front = rear = 0;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		return false;
//	}
//	bool full() {
//		if (size == capacity)
//			return true;
//		return false;
//	}
//	int getsize() {
//		return size;
//	}
//	int getfront() {
//		if (empty())
//			return -1;
//		return arr[front];
//	}
//	int getrear() {
//		if (empty())
//			return -1;
//		return arr[rear - 1];
//	}
//	void enqueue(int v) {
//		if (capacity <= size) {
//			cout << "Full\n";
//			return;
//		}
//		arr[rear] = v;
//		rear = (rear + 1) % capacity;
//		size++;
//	}
//	void dequeue() {
//		if (empty()) {
//			cout << "Empty\n";
//			return;
//		}
//		front = (front + 1) % capacity;
//		size--;
//	}
//	void plusfront(int n) {
//		if (empty())
//			return;
//		arr[front] += n;
//	}
//};
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(nullptr);
//
//	int t, n, input, score1, score2, hp, lastwin = 0;
//	cin >> t;
//	for (int j = t; j > 0; j--) {
//		arrayqueue p1, p2;
//		score1 = score2 = hp = 0;
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> input;
//			p1.enqueue(input);
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> input;
//			p2.enqueue(input);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (p1.getfront() > p2.getfront()) {
//				score1++;
//				cout << "Round" << i << ' ' << p1.getfront() << '>' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
//				hp = p1.getfront() - p2.getfront();
//				p1.dequeue();
//				p2.dequeue();
//				p1.plusfront(hp);
//				if (i == n)
//					lastwin = 1;
//			}
//			else if (p1.getfront() < p2.getfront()) {
//				score2++;
//				cout << "Round" << i << ' ' << p1.getfront() << '<' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
//				hp = p2.getfront() - p1.getfront();
//				p1.dequeue();
//				p2.dequeue();
//				p2.plusfront(hp);
//				if (i == n)
//					lastwin = 2;
//			}
//			else {
//				cout << "Round" << i << ' ' << p1.getfront() << '=' << p2.getfront() << ' ' << score1 << ':' << score2 << '\n';
//				p1.dequeue();
//				p2.dequeue();
//				if (i == n)
//					lastwin = 0;
//			}
//		}
//		if (score1 > score2)
//			cout << "Winner P1\n";
//		else if (score2 > score1)
//			cout << "Winner P2\n";
//		else {
//			if (lastwin == 0)
//				cout << "Draw\n";
//			else if (lastwin == 1)
//				cout << "Winner P1\n";
//			else if (lastwin == 2)
//				cout << "Winner P2\n";
//		}
//	}
//}
