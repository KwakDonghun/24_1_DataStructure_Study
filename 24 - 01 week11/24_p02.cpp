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
	int size, idx, count;
	int* arr;
	BST() {
		root = new node;
		idx = size = count = 0;
		arr = new int[10001];
	}
	bool empty() { return (size == 0); }
	node* find(int v) {
		if (empty()) return NULL;
		node* curnode = root;
		while (curnode->val != v) {
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
	}
	void remove(int v) {
		if (empty()) return;
		node* delnode = find(v);
		node* parnode = delnode->parent;
		if (delnode->left->val == 0 || delnode->right->val == 0) {
			node* child = (delnode->left->val == 0) ? delnode->right : delnode->left;
			if (delnode == root)
				this->root = child;
			else {
				if (parnode->left == delnode) {
					parnode->left = child;
				}
				else if (parnode->right == delnode) {
					parnode->right = child;
				}
				child->parent = parnode;
			}
		}
		else {
			node* succ = delnode->right;
			while (succ->left->val != 0)
				succ = succ->left;
			node* succpar = succ->parent;
			if (succpar->left == succ)
				succpar->left = succ->right;
			else
				succpar->right = succ->right;
			succ->right->parent = succpar;
			delnode->val = succ->val;
			delnode = succ;
		}
		size--;
		delete delnode;
	}
	int max(int k) {
		idx = 0;
		inorder(root);
		return arr[size-k];
	}
	void inorder(node* n) {
		if (n->left->val != 0)
			inorder(n->left);
		arr[idx++] = n->val;
		if (n->right->val != 0)
			inorder(n->right);
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
			}
			else if (cmd == "max") {
				cin >> input;
				cout << bst.max(input) << '\n';
			}
			else if (cmd == "delete") {
				cin >> input;
				bst.remove(input);
			}
		}
	}
}