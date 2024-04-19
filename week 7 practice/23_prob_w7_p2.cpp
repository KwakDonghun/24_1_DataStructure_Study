#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	int size;
	int depth;
	int folder_num;
	int sum;
	node* parent;
	vector<node*> childlist;
	node(int folder, node* parent) {
		this->folder_num = folder;
		this->parent = parent;
		this->depth = parent->depth + 1;
		this->sum = 0;
		this->size = 0;
	}
	node(int folder, int depth) {
		this->folder_num = folder;
		this->parent = NULL;
		this->depth = depth;
		this->sum = 0;
		this->size = 0;
	}
};

class Tree {
public:
	int count;
	node* root;
	vector<node*> nodelist;
	node* find(int data) {
		for (auto i : nodelist)
			if (data == i->folder_num)
				return i;
		return NULL;
	}
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
		count = 0;
	}
	void insertnode(int pardata, int num) {
		node* parent = find(pardata);
		if (parent == NULL || find(num) != NULL)
			return;
		node* newnode = new node(num, parent);
		parent->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void insertsize(int folder_num, int size) {
		if (find(folder_num) == NULL)
			return;
		find(folder_num)->size = size;
	}
	void postorder_sum(node* curnode, int C) {
		for (auto i : curnode->childlist) {
			postorder_sum(i, C);
			curnode->sum += i->sum;
		}
		curnode->sum += curnode->size;
		if (curnode->sum > C) {
			cout << curnode->folder_num << ' ';
			count++;
		}
	}

};
//23 p2
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C, args1, args2;
	cin >> N >> C;
	Tree tree;
	for (int i = 0; i < N - 1; i++) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	for (int i = 0; i < N; i++) {
		cin >> args1 >> args2;
		tree.insertsize(args1, args2);
	}
	tree.postorder_sum(tree.root, C);
	if (tree.count == 0)
		cout << -1;
}