#include <iostream>

using namespace std;

struct node {
	node* parent;
	node* right;
	node* left;
	int val;
	node() {
		val = 0;
		parent = right = left = NULL;
	}
	node(int v) {
		val = v;
		parent = right = left = new node();
	}
};

class BST {
public:
	int size;
	node* root;
	int count;
	BST() {
		size = count = 0;
		root = new node();
	}
	bool empty() { return (size == 0); }
	node* find(int x) {
		if (empty()) return NULL;
		node* curnode = root;
		while (curnode->val != x) {
			if (curnode->val > x) {
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
	int RightSubtreeCount(int k) {
		node* curnode = find(k);
		count = 0;
		if (curnode->right->val != 0) {
			inorder(curnode->right);
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
	int N, M, input, args1, args2;
	BST bst;
	cin >> N >> M;
	while (N--) {
		cin >> input;
		bst.insert(input);
	}
	while (M--) {
		cin >> args1 >> args2;
		int result = bst.RightSubtreeCount(args1) - bst.RightSubtreeCount(args2);
		if (result > 0)
			cout << result << '\n';
		else
			cout << -result << '\n';
	}
}