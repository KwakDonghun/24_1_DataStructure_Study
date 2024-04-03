#include <iostream>
#include <string>

using namespace std;

class arrayqueue {
private:
	int* arr;
	int capacity;
	int size;
	int front;
	int rear;
public:
	arrayqueue(int c) {
		capacity = c;
		arr = new int[capacity];
		size = 0;
		front = rear = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	bool full() {
		if (size == capacity)
			return true;
		return false;
	}
	int getsize() {
		return size;
	}
	int getfront() {
		if (empty())
			return -1;
		return arr[front];
	}
	int getrear() {
		if (empty())
			return -1;
		return arr[rear - 1];
	}
	void enqueue(int v) {
		if (capacity <= size) {
			cout << "Full\n";
			return;
		}
		arr[rear] = v;
		rear = (rear + 1) % capacity;
		size++;
	}
	void dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		cout << arr[front] << '\n';
		front = (front + 1) % capacity;
		size--;
	}
	void rearnsum(int num) {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		if (num > size) {
			cout << "error\n";
			return;
		}
		int sum = 0;
		for (num; num > 0; num--) {
			sum += arr[(rear - num + capacity)%capacity];
		}
		cout << sum << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(nullptr);

	int t, n, x;
	string s;
	cin >> n >> t;
	arrayqueue q(n);
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
		else if (s == "front") {
			if (q.getfront() == -1)
				cout << "Empty\n";
			else
				cout << q.getfront() << '\n';
		}
		else if (s == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
		else if (s == "full") {
			if (q.full())
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (s == "rearNsum") {
			cin >> x;
			q.rearnsum(x);
		}
	}
}