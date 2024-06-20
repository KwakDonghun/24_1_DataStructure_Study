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
	node(int v) {
		parent = left = right = new node;
		val = v;
	}
};

class BST {
public:
	int size;
	int count;
	int idx;
	int arr[10001];
	node* root;
	BST() {
		root = new node;
		count = size = 0;
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
	void insert(int k) {
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
	}
	int height(node* n) {
		if (n->val == 0)
			return -1;
		int lheight = height(n->left);
		int rheight = height(n->right);
		return (lheight > rheight) ? lheight + 1 : rheight + 1;
	}
	int depth(int k) {
		node* curnode = find(k);
		int count = 0;
		while (curnode != root) {
			count++;
			curnode = curnode->parent;
		}
		return count;
	}
	void erase(int k) {
		if (empty()) return;
		node* delnode = find(k);
		node* parnode = delnode->parent;
		if (delnode->left->val == 0 || delnode->right->val == 0) {
			node* child = (delnode->left->val == 0) ? delnode->right : delnode->left;
			if (delnode == root)
				this->root = new node;
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
			delnode->val = succ->val;
			delnode = succ;
		}
		size--;
		delete delnode;
	}
	int min(int k) {
		idx = 0;
		inorder(root);
		return arr[k - 1];
	}
	void inorder(node* n) {
		if (n->left->val != 0)
			inorder(n->left);
		arr[idx] = n->val;
		idx++;
		if (n->right->val != 0)
			inorder(n->right);
	}
};

int main() {
	int T, args;
	string cmd;
	BST bst;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> args;
			bst.insert(args);
			cout << bst.depth(args) << '\n';
		}
		else if (cmd == "delete") {
			cin >> args;
			cout << bst.depth(args) << '\n';
			bst.erase(args);
		}
		else if (cmd == "min") {
			cin >> args;
			cout << bst.min(args) << '\n';
		}
		else if (cmd == "height") {
			cin >> args;
			cout << bst.height(bst.find(args)) << '\n';
		}
	}
}