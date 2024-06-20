#include <iostream>
#include <string>

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
	node(int val) {
		this->val = val;
		parent = left = right = new node();
	}
};

class BST {
public:
	node* root;
	int size;
	int list[10001];
	int idx;

	BST() {
		root = new node;
		size = idx =0;
	}
	bool empty() { return (size == 0); }
	int getsize() { return size; }
	node* find(node* n, int val) {
		if (empty()) return NULL;
		if (val < n->val) {
			if (n->left->val == 0)
				return n;
			return find(n->left, val);
		}
		else if (val == n->val)
			return n;
		else {
			if (n->right->val == 0)
				return n;
			return find(n->right, val);
		}
	}
	void put(int k) {
		node* newnode = new node(k);
		if (empty()) {
			root = newnode;	
		}
		else {
			node* parent = find(root,k);
			if (k < parent->val)
				parent->left = newnode;
			else
				parent->right = newnode;
			newnode->parent = parent;
		}
		size++;
	}
	void erase(int val) {
		node* delnode = find(root,val);
		node* parnode = delnode->parent;
		
		if (delnode->left->val == 0 || delnode->right->val == 0) { //case 1: 삭제할 노드 v의 자식이 하나라도 leaf 인 경우
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
		else { //삭제할 노드 v의 두 자식이 모두 internal node 일 경우
			node* succ = delnode->right;
			node* succpar = delnode;
			while (succ->left->val != 0) {
				succpar = succ;
				succ = succ->left;
			}
			if (succ == succpar->left)
				succpar->left = succ->right;
			else
				succpar->right = succ->right;
			delnode->val = succ->val;
			delnode = succ; 
		}
		size--;
		delete delnode;
	}
	int depth(node* n) {
		if (n == root)
			return 0;
		else {
			return depth(n->parent) + 1;
		}
	}
	int height(node* n) {
		if (n->val == 0)
			return -1;
		int lHeight = height(n->left);
		int rHeight = height(n->right);
		return ((lHeight > rHeight) ? lHeight : rHeight) + 1;
	}
	int min(int v) {
		idx = 0;
		inorder(root);
		return list[v-1];
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
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	int n;
	cin >> n;
	BST bst;
	while (n--) {
		cin >> str;
		int x;
		if (str == "insert") {
			cin >> x;
			bst.put(x);
			cout << bst.depth(bst.find(bst.root, x)) << '\n';
		}
		else if (str == "delete") {
			cin >> x;
			cout << bst.depth(bst.find(bst.root, x)) << '\n';
			bst.erase(x);
		}
		else if (str == "min") {
			cin >> x;
			cout << bst.min(x)<< '\n';
		}
		else if (str == "height") {
			cin >> x;
			cout << bst.height(bst.find(bst.root, x)) << '\n';
		}
	}
}
