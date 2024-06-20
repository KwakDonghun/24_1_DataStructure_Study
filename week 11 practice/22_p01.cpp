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
	int LeftSubtreeCount(int k) {
		node* curnode = find(k);
		count = 0;
		if (curnode->left->val != 0) {
			inorder(curnode->left);
		}
		return count;
	}
	void inorder(node* n) {
		if (n->left->val != 0)
			inorder(n->left);
		count++;
		if (n->right->val != 0)
			inorder(n->right);
	}
};

int main() {
	int N, M, input, args;
	BST bst;
	cin >> N >> M;
	while (N--) {
		cin >> input;
		bst.insert(input);
	}
	while (M--) {
		cin >> args;
		cout << bst.LeftSubtreeCount(args) << '\n';
	}
}