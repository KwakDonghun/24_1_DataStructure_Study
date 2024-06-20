#include <iostream>

using namespace std;

struct node {
	node* parent;
	node* left;
	node* right;
	int val;
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
	int size;
	int* arr;
	int idx;
	BST() {
		root = new node;
		size = idx = 0;
		arr = new int[10001];
	}
	bool empty() { return(size == 0); }
	node* find(int k) {
		if (empty()) return NULL;
		node* curnode = root;
		while (curnode->val != k) {
			if (curnode->val > k) {
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
	void remove(int k) {
		node* delnode = find(k);
		node* parnode = delnode->parent;
		if (delnode->right->val == 0 || delnode->left->val == 0) {
			node* child = (delnode->left->val == 0) ? delnode->right : delnode->left;
			if (delnode == root)
				root = child;
			else {
				if (parnode->left == delnode)
					parnode->left = child;
				else
					parnode->right = child;
			}
			child->parent = parnode;
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
		delete delnode;
		size--;
	}
	void min(int k) {
		idx = 0;
		inorder(root);
		cout << arr[k - 1] << '\n';
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
			}else if (cmd == "delete") {
				cin >> input;
				bst.remove(input);
			}else if (cmd == "min") {
				cin >> input;
				bst.min(input);
			}
		}
	}
}