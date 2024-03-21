#include <iostream>
#include <string>
using namespace std;

//quiz1
//class stack {
//private:
//	int capacity;
//	int size;
//	int* arr;
//	int topindex;
//public:
//	stack(int capa);
//	void empty();
//	void getsize();
//	void top();
//	void push(int data);
//	void pop();
//	void full();
//};
//
//stack::stack(int capa) {
//	this->capacity = capa;
//	arr = new int[capacity];
//	topindex = -1;
//}
//
//void stack::getsize() {
//	cout << size << '\n';
//}
//
//void stack::empty() {
//	if (size <= 0)
//		cout << 1<< '\n';
//	else
//		cout << 0<< '\n';
//}
//
//void stack::top() {
//	if (size == 0){
//		cout << -1 << '\n';
//		return;
//	}
//	cout << arr[topindex] << '\n';
//}
//
//void stack::push(int data) {
//	if (size+1 > capacity) {
//		cout << "FULL\n";
//		return;
//	}
//	topindex++;
//	size++;
//	arr[topindex] = data;
//}
//
//void stack::full() {
//	if (size > capacity)
//		cout << 1 << '\n';
//	else
//		cout << 0 << '\n';
//}
//
//void stack::pop() {
//	if (size == 0) {
//		cout << -1 << '\n';
//	}
//	else
//	{
//		size--;
//		cout << arr[topindex] << '\n';
//		topindex--;
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int t,n,x;
//	cin >> t >> n;
//	string s;
//	stack sl(t);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "size") {
//			sl.getsize();
//		}
//		else if (s == "empty") {
//			sl.empty();
//		}
//		else if (s == "top") {
//			sl.top();
//		}
//		else if (s == "push") {
//			cin >> x;
//			sl.push(x);
//		}
//		else if (s == "pop") {
//			sl.pop();
//		}
//		else if (s == "full") {
//			sl.full();
//		}
//	}
//}

//quiz 2
//class node {
//private:
//	node* next;
//	int val;
//public:
//	node(int value) {
//		val = value;
//		next = NULL;
//	}
//	void setnext(node* n) {
//		next = n;
//	}
//	int getval() {
//		return val;
//	}
//
//	friend class stack;
//};
//
//class stack {
//private:
//	node* top;
//	int size;
//public:
//	stack() {
//		top = NULL;
//		size = 0;
//	}
//	int getsize() {
//		return size;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//
//	void push(int x) {
//		node* n = new node(x);
//		if (size == 0) {
//			top = n;
//			size++;
//			return;
//		}
//		n->next = top;
//		top = n;
//		size++;
//	}
//	int gettop() {
//		if (empty())
//		{
//			return 0;
//		}
//		return top->val;
//	}
//	int pop() {
//		if (empty())
//		{
//			return 0;
//		}
//		node* newnode = top;
//		top = top->next;
//		delete newnode;
//		size--;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; i++) {
//		stack sl;
//		cin >> s;
//		int size = s.size();
//		int result = 0;
//		for (int j = 0; j < size; j++) {
//			if (s[j] >= '1' && s[j] <= '9')
//				sl.push(s[j]-'0');
//			else {
//				char first, second;
//				second = sl.gettop();
//				sl.pop();
//				first = sl.gettop();
//				sl.pop();
//				if (s[j] == '+') {
//					sl.push(first + second);
//				}
//				else if (s[j] == '-') {
//					sl.push(first - second);
//				}
//				else if (s[j] == '*')
//					sl.push(first * second);
//			}
//		}
//		if (sl.gettop() >= 0)
//			result = sl.gettop();
//		else
//			result = -sl.gettop();
//		int sum = 0;
//		while (result / 10 > 0) {
//			sum += (result % 10);
//			result /= 10;
//		}
//		sum += result;
//		cout << sum << '\n';
//	}
//}
 

//quiz 3
//class node {
//private:
//	node* next;
//	int val;
//public:
//	node(int value) {
//		val = value;
//		next = NULL;
//	}
//	void setnext(node* n) {
//		next = n;
//	}
//	int getval() {
//		return val;
//	}
//
//	friend class stack;
//};
//
//class stack {
//private:
//	node* top;
//	int size;
//public:
//	stack() {
//		top = NULL;
//		size = 0;
//	}
//	int getsize() {
//		return size;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//	void push(int x) {
//		node* n = new node(x);
//		if (size == 0) {
//			top = n;
//			size++;
//			return;
//		}
//		n->next = top;
//		top = n;
//		size++;
//	}
//	void gettop() {
//		if (empty())
//		{
//			cout << -1 << '\n';
//			return;
//		}
//		cout << top->val << '\n';
//	}
//	void pop() {
//		if (empty())
//		{
//			cout << -1 << '\n';
//			return;
//		}
//		cout << top->val << '\n';
//		node* newnode = top;
//		top = top->next;
//		delete newnode;
//		size--;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n,x;
//	cin >> n;
//	string s;
//	stack sl;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "size") {
//			cout << sl.getsize() << '\n';
//		}
//		else if (s == "empty") {
//			if (sl.empty())
//				cout << 1 << '\n';
//			else
//				cout << 0 << '\n';
//		}
//		else if (s == "top") {
//			sl.gettop();
//		}
//		else if (s == "push") {
//			cin >> x;
//			sl.push(x);
//		}
//		else if (s == "pop") {
//			sl.pop();
//		}
//	}
//}

//quiz 4
//class node {
//private:
//	node* next;
//	char val;
//public:
//	node(char value) {
//		val = value;
//		next = NULL;
//	}
//	void setnext(node* n) {
//		next = n;
//	}
//	friend class stack;
//};
//
//class stack {
//private:
//	node* top;
//	int size;
//	int emptystack;
//public:
//	stack() {
//		top = NULL;
//		size = 0;
//		emptystack = 0;
//	}
//	int getsize() {
//		return size;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//
//	void push(char x) {
//		node* n = new node(x);
//		if (size == 0) {
//			top = n;
//			size++;
//			return;
//		}
//		n->next = top;
//		top = n;
//		size++;
//	}
//	char gettop() {
//		if (empty())
//		{
//			return 0;
//		}
//		return top->val;
//	}
//	void pop() {
//		if (empty())
//			return;
//		node* newnode = top;
//		top = top->next;
//		delete newnode;
//		size--;
//		if (size == 0)
//			emptycountup();
//	}
//	int emptycount() {
//		return emptystack;
//	}
//	void emptycountup() {
//		emptystack++;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; i++) {
//		stack sl;
//		cin >> s;
//		int size = s.size();
//		int result = 0;
//		for (int j = 0; j < size; j++) {
//			if (s[j] >= '1' && s[j] <= '9') {
//				cout << s[j];
//			}
//			else if (s[j] == '+' || s[j] == '-') {
//				while (!sl.empty())
//				{
//					cout << sl.gettop();
//					sl.pop();
//				}
//				sl.push(s[j]);
//			}
//			else if (s[j] == '*') {
//				while (!sl.empty() && sl.gettop() == '*') {
//					cout << sl.gettop();
//					sl.pop();
//				}
//				sl.push(s[j]);
//			}
//		}
//		while (!sl.empty())
//		{
//			cout << sl.gettop();
//			sl.pop();
//		}
//		cout << ' ' << sl.emptycount() << '\n';
//	}
//}

//22- quiz 1

//class stack {
//private:
//	int* arr;
//	int capacity;
//	int topindex;
//	int size;
//public:
//	stack(int capa) {
//		capacity = capa;
//		arr = new int [capacity];
//		topindex = -1;
//		size = 0;
//	}
//
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//
//	int getsize() {
//		return size;
//	}
//
//	int top() {
//		if (empty())
//			return -1;
//		else {
//			return arr[topindex];
//		}
//	}
//
//	void push(int x) {
//		if (size >= capacity) {
//			cout << "FULL\n";
//			return;
//		}
//		size++;
//		topindex++;
//		arr[topindex] = x;
//	}
//
//	void pop() {
//		if (size == 0)
//			cout << -1 << '\n';
//		else {
//			cout << arr[topindex] << '\n';
//			size--;
//			topindex--;
//		}
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int t, n, x;
//	string s;
//	cin >> t >> n;
//	stack s1(t);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "size")
//			cout << s1.getsize() << '\n';
//		else if (s == "empty") {
//			if (s1.empty())
//				cout << 1 << '\n';
//			else
//				cout << 0 << '\n';
//		}
//		else if (s == "top") {
//			cout << s1.top() << '\n';
//		}
//		else if (s == "push") {
//			cin >> x;
//			s1.push(x);
//		}
//		else if (s == "pop") {
//			s1.pop();
//		}
//	}
//}

//22 - quiz 2
class node {
private:
	char val;
	node* next;
public:
	node(char c) {
		val = c;
		next = NULL;
	}
	void setnext(node* n) {
		next = n;
	}
	char getval() {
		return val;
	}
	friend class stack;
};

class stack {
private:
	int size;
	node* top;
public:
	stack() {
		size = 0;
		top = NULL;
	}
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	void push(char c) {
		node* newnode = new node(c);
		if (empty())
			top = newnode;
		else {
			newnode->next = top;
			top = newnode;
		}
		size++;
	}
	char gettop() {
		if (empty())
			return 0;
		else
			return top->val;
	}
	void pop() {
		if (empty())
			return;

		node* del = top;
		cout << gettop();
		top = top->next;
		delete del;
		size--;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		stack s1;
		int size = s.size();
		for (int j = 0; j < size; j++) {
			if (s[j] >= '1' && s[j] <= '9')
				cout << s[j];
			else if (s[j] == '+' || s[j] == '-') {
				while (!s1.empty()) 
					s1.pop();
				s1.push(s[j]);
			}
			else if (s[j] == '*') {
				while (!s1.empty() && s1.gettop() == '*')
					s1.pop();
				s1.push(s[j]);
			}
		}
		while (!s1.empty())
			s1.pop();
		cout << '\n';
	}
}

//22 - quiz 3
//class node {
//private:
//	int val;
//	node* next;
//public:
//	node() {
//		val = 0;
//		next = NULL;
//	}
//	node(int x) {
//		val = x;
//		next = NULL;
//	}
//	void setnext(node* n) {
//		this->next = n;
//	}
//
//	friend class stack;
//};
//
//class stack {
//private:
//	int size;
//	node* top;
//public:
//	stack() {
//		top = NULL;
//		size = 0;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//	int getsize() {
//		return size;
//	}
//	int gettop() {
//		if (empty())
//			return -1;
//		else
//			return top->val;
//	}
//	void push(int x) {
//		node* newnode = new node(x);
//		if (empty()) {
//			top = newnode;
//		}
//		else {
//			newnode->next = top;
//			top = newnode;
//		}
//		size++;
//	}
//
//	void pop() {
//		if (empty())
//		{
//			cout << -1 << '\n';
//			return;
//		}
//		cout << top->val << '\n';
//		node* del = top;
//		top = top->next;
//		delete del;
//		size--;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n, x;
//	cin >> n;
//	string s;
//	stack sl;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "size") {
//			cout << sl.getsize() << '\n';
//		}
//		else if (s == "empty") {
//			if (sl.empty())
//				cout << 1 << '\n';
//			else
//				cout << 0 << '\n';
//		}
//		else if (s == "top") {
//			cout << sl.gettop() << '\n';
//		}
//		else if (s == "push") {
//			cin >> x;
//			sl.push(x);
//		}
//		else if (s == "pop") {
//			sl.pop();
//		}
//	}
//}

//22- quiz 4
//class node {
//private:
//	int val;
//	node* next;
//public:
//	node(int x) {
//		val = x;
//		next = NULL;
//	}
//	node() {
//		val = 0;
//		next = NULL;
//	}
//	void setnext(node* n) {
//		next = n;
//	}
//
//	friend class stack;
//};
//
//class stack {
//private:
//	node* top;
//	int size;
//public:
//	stack() {
//		top = NULL;
//		size = 0;
//	}
//	bool empty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
//	}
//	int gettop() {
//		if (empty())
//			return 0;
//		else
//			return top->val;
//	}
//	void push(int x) {
//		node* newnode = new node(x);
//		if (empty())
//		{
//			top = newnode;
//		}
//		else {
//			newnode->next = top;
//			top = newnode;
//		}
//		size++;
//	}
//	void pop() {
//		if (empty())
//			return;
//		node* del = top;
//		top = top->next;
//		delete del;
//		size--;
//	}
//
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; i++) {
//		stack s1;
//		cin >> s;
//		int size = s.size();
//		for (int j = 0; j < size; j++) {
//			if (s[j] >= '1' && s[j] <= '9')
//				s1.push(s[j] - '0');
//			else if (s[j] == '+' || s[j] == '-' || s[j] == '*') {
//				int first, second;
//				second = s1.gettop();
//				s1.pop();
//				first = s1.gettop();
//				s1.pop();
//				if (s[j] == '+')
//					s1.push(first + second);
//				if (s[j] == '*')
//					s1.push(first * second);
//				if (s[j] == '-')
//					s1.push(first - second);
//			}
//		}
//		cout << s1.gettop() << '\n';
//	}
//}