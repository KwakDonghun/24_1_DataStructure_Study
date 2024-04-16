#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	node* parent;
	vector <node*> childlist;
	int depth;
	int value;
	node(int val, node* p) {
		value = val;
		parent = p;
		depth = parent->depth + 1;
	}
	node(int val, int dep) {
		parent = NULL;
		depth = dep;
		value = val;
	}
};

class Tree {
public:
	vector <node*> nodelist;
	node* root;
	node* find(int data) {
		for (auto i : nodelist)
			if (i->value == data)
				return i;
		return NULL;
	}
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	void insertnode(int par_data, int data) {
		node* parentNode = find(par_data);
		if (parentNode == NULL || find(data) != NULL)
			return;
		node* newnode = new node(data, parentNode);
		nodelist.push_back(newnode);
		parentNode->childlist.push_back(newnode);
	}
	void deletenode(int data) {
		if (find(data) == NULL)
			return;
		node* delnode = find(data);
		vector <node*>& delparchild = delnode->parent->childlist;
		for (auto i : delnode->childlist) {
			delparchild.push_back(i);
			i->parent = delnode->parent;
		}
		for (int i = 0; i < delparchild.size(); i++) {
			if (delparchild[i] == delnode) {
				delparchild.erase(delparchild.begin() + i);
				break;
			}
		}
		for (int i = 0; i < nodelist.size(); i++) {
			if (nodelist[i] == delnode) {
				nodelist.erase(nodelist.begin() + i);
				break;
			}
		}
		delete delnode;
	}
	void preorder(node* curnode) {
		cout << curnode->value << ' ';
		for (auto i : curnode->childlist)
			preorder(i);
	}
	void folder_count(int size, node* curnode) {
		if (curnode->childlist.empty() && curnode->depth == size) {
			cout << curnode->value << ' ';
		}
		for (auto i : curnode->childlist)
			folder_count(size, i);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, args1, args2;
	cin >> N >> M;
	Tree tree;
	while (--N) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	while (M--) {
		int count = 0;
		cin >> args1;
		for (auto i : tree.nodelist) {
			if (i->childlist.empty() && i->depth == args1)
				count++;
		}
		if (count > 0)
			tree.folder_count(args1, tree.root);
		else
			cout << -1;
		cout << '\n';
	}
}