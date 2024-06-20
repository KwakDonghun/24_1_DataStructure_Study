#include <iostream>

using namespace std;

struct node {
	node* parent;
	node* left;
	node* right;
	int val;
	node() {
		parent = left = right = NULL;
		val = 0;
	}
	node(int val) {
		this->val = val;
		parent = left = right = new node;
	}
};

class BST {
public:
	node* root;
	int size;
	int count;
	BST() {
		count = size = 0;
		root = new node;
	}
	bool empty() { return (size == 0); }
	node* find(int v) {
		if (empty()) return nullptr;
		node* curnode = root; 
		while (curnode->val != v) {
			count++;
			if (curnode->val > v) {
				if (curnode->left->val == 0)
					break;
				curnode = curnode->left;
			}
			else {
				if (curnode->right->val == 0)
					break;
				curnode = curnode->right;
			}
		}
		return curnode;
	}
	void search(int v) {
		if (empty()) {
			cout << "empty\n"; 
			return;
		}
		count = 0;
		node* curnode = root;
		while (curnode->val != v) {
			count++;
			if (curnode->val > v) {
				if (curnode->left->val == 0)
					break;
				curnode = curnode->left;
			}
			else {
				if (curnode->right->val == 0)
					break;
				curnode = curnode->right;
			}
		}
		if (curnode->val == v)
			count++;
		cout << count << '\n';
	}
	void insert(int k) {
		count = 0;
		node* newnode = new node(k);
		if (empty())
			root = newnode;
		else {
			node* parnode = find(k);
			if (parnode->val > k)
				parnode->left = newnode;
			else
				parnode->right = newnode;
			newnode->parent = parnode;
		}
		size++;
		cout << count << '\n';
	}
	void parent(int k) {
		node* curnode = find(k);
		if (empty() || curnode->val != k) {
			cout << -1 << '\n';
			return;
		}
		if (curnode->parent->val == 0)
			cout << -2 << '\n';
		else
			cout << curnode->parent->val << '\n';
	}
	void child(int k) {
		node* curnode = find(k);
		if (empty() || curnode->val != k ) {
			cout << -1 << '\n';
			return;
		}
		if (curnode->right->val == 0)
			cout << -2 << '\n';
		else
			cout << curnode->right->val << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input;
	string cmd;
	cin >> T;
	while (T--) {
		cin >> N;
		BST bst;
		while (N--) {
			cin >> cmd;
			if (cmd == "insert") {
				cin >> input;
				bst.insert(input);
			}else if (cmd == "search") {
				cin >> input;
				bst.search(input);
			}else if (cmd == "parent") {
				cin >> input;
				bst.parent(input);
			}else if (cmd == "child") {
				cin >> input;
				bst.child(input);
			}
		}
	}
}