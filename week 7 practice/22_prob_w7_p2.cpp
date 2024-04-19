#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	int data;
	int depth;
	node* parent;
	int file_count;
	vector<node*> childlist;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
		this->depth = parent->depth + 1;
		file_count = 0;
	}
	node(int data, int depth) {
		this->data = data;
		this->parent = NULL;
		this->depth = depth;
		file_count = 0;
	}
};

class Tree {
public:
	int count;
	node* root;
	vector<node*> nodelist;
	node* find(int data) {
		for (auto i : nodelist)
			if (data == i->data)
				return i;
		return NULL;
	}
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
		count = 0;
	}
	void insertnode(int pardata, int data) {
		node* parent = find(pardata);
		if (parent == NULL || find(data) != NULL)
			return;
		node* newnode = new node(data, parent);
		parent->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void preorder(node* curnode) {
		cout << curnode->data << ' ';
		for (auto i : curnode->childlist)
			preorder(i);
	}

	void postorder(node* curnode) {
		for (auto i : curnode->childlist)
			postorder(i);
		cout << curnode->data << ' ';
	}

	void postorderP2(node* curnode) {
		for (auto i : curnode->childlist) {
			postorderP2(i);
			curnode->file_count += i->file_count;
		}
		if (curnode->childlist.empty())
			curnode->file_count++;
	}
};

//22 p2
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase, args1, args2, node_count;
	Tree tree;
	cin >> node_count >> testcase;
	while (--node_count) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	tree.postorderP2(tree.root);
	while (testcase--) {
		cin >> args1;
		cout << tree.find(args1)->file_count << '\n';
	}
}