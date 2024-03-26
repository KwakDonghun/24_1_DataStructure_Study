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
	int popsum(int s) {
		if (empty())
			return -1;
		else {
			int sum = 0;
			for (int i = 0; i < s; i++) {
				sum += top();
				pop();
				if (empty())
					break;
			}
			return sum;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c, x;
	cin >> c >> n;
	arraystack a(c);
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
		else if (s == "popsum") {
			cin >> x;
			cout << a.popsum(x) << '\n';
		}
	}
}