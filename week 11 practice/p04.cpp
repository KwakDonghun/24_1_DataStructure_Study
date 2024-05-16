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
		val = v;
		parent = left = right = new node();
	}
};

class Bst {
public:
	node* root;
	int size;
	int idx;
	int list[10001];
	Bst(){
		root = new node();
		size = idx =0;
	}
	bool empty() { return(size == 0); }
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
	void insert(int x) {
		node* newnode = new node(x);
		if (empty())
			root = newnode;
		else {
			node* parnode = find(x);
			if (parnode->val > x)
				parnode->left = newnode;
			else
				parnode->right = newnode;
			newnode->parent = parnode;
		}
		size++;
	}
	void erase(int x) {
		node* delnode = find(x);
		node* parnode = delnode->parent;
		if (delnode->left->val == 0 || delnode->right->val == 0) {
			node* child = (delnode->left->val == 0) ? delnode->right : delnode->left;
			if (parnode->left == delnode)
				parnode->left = child;
			else
				parnode->right = child;
			child->parent = parnode;
		}
		else {
			node* succ = delnode->right;
			while (succ->left->val != 0) {
				succ = succ->left;
			}
			node* succpar = succ->parent;
			if (succpar->left == succ)
				succpar->left = succ->right;
			else
				succpar->right == succ->right;
			delnode->val = succ->val;
			delnode = succ;
		}
		size--;
		delete delnode;
	}
	int depth(int x) {
		node* curnode = find(x);
		int dep = 0;
		while (curnode != root) {
			dep++;
			curnode = curnode->parent;
		}
		return dep;
	}
	int height(node* n) {
		if (n->val == 0)
			return -1;
		int lheight = height(n->left);
		int rheight = height(n->right);
		return ((lheight > rheight) ? lheight + 1 : rheight + 1);
	}
	int max(int k) {
		idx = 0;
		inorder(root);
		return list[size - k];
	}
	void inorder(node* n) {
		if (n->left->val != 0)
			inorder(n->left);
		list[idx] = n->val;
		idx++;
		if (n->right->val != 0)
			inorder(n->right);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, input;
	string cmd;
	Bst bst;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> input;
			bst.insert(input);
			cout << bst.depth(input) << '\n';
		}
		else if (cmd == "delete") {
			cin >> input;
			cout << bst.depth(input) << '\n';
			bst.erase(input);
		}
		else if (cmd == "max") {
			cin >> input;
			cout << bst.max(input) << '\n';
		}
		else if (cmd == "height") {
			cin >> input;
			cout << bst.height(bst.find(input)) << '\n';
		}
	}
}