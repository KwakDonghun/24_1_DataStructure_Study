#include <iostream>

using namespace std;

struct node {
	int val;
	node* parent;
	node* left;
	node* right;
	node() {
		val = 0;
		parent = left = right = NULL;
	}
	node(int v) {
		val = v;
		parent = left = right = new node;
	}
};

class BST {
public:
	node* root;
	int size, count;
	BST() {
		root = new node;
		size = count = 0;
	}
	bool empty() { return (size == 0); }
	void search(int v) {
		count = 0;
		if (empty()) {
			cout << "empty\n";
			return;
		}
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
	node* find(int v) {
		if (empty()) return NULL;
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
	void insert(int v) {
		count = 0;
		node* curnode = new node(v);
		if (empty())
			root = curnode;
		else {
			node* parnode = find(v);
			if (parnode->val > v)
				parnode->left = curnode;
			else
				parnode->right = curnode;
			curnode->parent = parnode;
		}
		size++;
		cout << count << '\n';
	}
	
	void parent(int x) {
		node* curnode = find(x);
		if (empty() || curnode->val != x) {
			cout << -1 << '\n';
			return;
		}
		if (curnode->parent->val == 0) 
			cout << -2 << '\n';
		else 
			cout << curnode->parent->val << '\n';
	}
	
	void child(int x) {
		node* curnode = find(x);
		if (empty() || curnode->val != x) {
			cout << -1 << '\n';
			return;
		}
		if (curnode->left->val == 0)
			cout << -2 << '\n';
		else
			cout << curnode->left->val << '\n';
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
		BST bst;
		cin >> N;
		while (N--) {
			cin >> cmd;
			if (cmd == "insert") {
				cin >> input;
				bst.insert(input);
			}
			else if (cmd == "search") {
				cin >> input;
				bst.search(input);
			}
			else if (cmd == "parent") {
				cin >> input;
				bst.parent(input);
			}
			else if (cmd == "child") {
				cin >> input;
				bst.child(input);
			}
		}
	}
}