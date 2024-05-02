#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	node* parent;
	vector <node*> childlist;
	int size;
	int size_sum;
	int folder_num;
	int depth;
	node(int num, node* p) {
		folder_num = num;
		parent = p;
		depth = parent->depth + 1;
		size = size_sum = 0;
	}
	node(int num, int dep) {
		folder_num = num;
		parent = NULL;
		depth = dep;
		size = size_sum = 0;
	}
};

class Tree {
public:
	node* root;
	vector <node*> nodelist;
	node* find(int val) {
		for (auto i : nodelist)
			if (i->folder_num == val)
				return i;
		return NULL;
	}
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	void insert_folder(int par_val, int val) {
		if (find(par_val) == NULL || find(val) != NULL)
			return;
		node* parent = find(par_val);
		node* newnode = new node(val, parent);
		parent->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void insert_size(int folder, int val) {
		if (find(folder) == NULL)
			return;
		node* curnode = find(folder);
		curnode->size = val;
	}
	void sum_size(node* curnode) {
		for (auto i : curnode->childlist) {
			sum_size(i);
			curnode->size_sum += i->size_sum;
		}
		curnode->size_sum += curnode->size;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, node_count, args1, args2;
	cin >> node_count >> testcase;
	Tree tree;
	for (int i = 1; i < node_count; i++) {
		cin >> args1 >> args2;
		tree.insert_folder(args1, args2);
	}
	for (int i = 0; i < node_count; i++) {
		cin >> args1 >> args2;
		tree.insert_size(args1, args2);
	}
	tree.sum_size(tree.root);
	while (testcase--) {
		cin >> args1;
		if (tree.find(args1) != NULL)
			cout << tree.find(args1)->size_sum << '\n';
	}
}