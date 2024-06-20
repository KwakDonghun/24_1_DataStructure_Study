#include <iostream>

using namespace std;

struct node {
	node* parent;
	node* right;
	node* left;
	int val;

	node() {
		parent = right = left = NULL;
		val = 0;
	}
	node(int v) {
		parent = right = left = new node();
		val = v;
	}
};

class Bst {
public:
	node* root;
	int size;
	int count;
	Bst() {
		root = new node();
		size = 0;
		count = 0;
	}
	bool empty() { return(size == 0); }
	node* find(int val) {  
		if (empty()) return NULL;
		node* curnode = root;
		while (curnode->val != val) {
			if (curnode->val > val) {
				if (curnode->left->val == 0)
					return curnode;
				curnode = curnode->left;
			}
			if (curnode->val < val) {
				if (curnode->right->val == 0)
					return curnode;
				curnode = curnode->right;
			}
		}
		return curnode;
	}
	void insert(int v) {
		node* newnode = new node(v);
		if (empty()) {
			root = newnode;
		}
		else {
			node* parnode = find(v);
			if (v < parnode->val)
				parnode->left = newnode;
			else
				parnode->right = newnode;
			newnode->parent = parnode;
		}
		size++;
	}
	int LeftSubtreeCount(node* n) {
		count = 0;
		if(n->left->val!=0)
			inorder(n->left);
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Bst bst;
	int N, M, input, args1, args2;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		bst.insert(input);
	}
	while (M--) {
		cin >> args1 >> args2;
		cout << bst.LeftSubtreeCount(bst.find(args1)) + bst.LeftSubtreeCount(bst.find(args2)) << '\n';
	}
}