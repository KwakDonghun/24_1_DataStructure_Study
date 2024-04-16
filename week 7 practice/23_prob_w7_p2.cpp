#include <iostream>
#include <string>
#include <vector>

using namespace std;

//23 p2
struct node {
	node* parent;
	vector <node*> childlist;
	int depth;
	int folder_num;
	int value;
	int value_sum;
	node(int num, node* p) {
		value = value_sum = 0;
		parent = p;
		folder_num = num;
		depth = parent->depth + 1;
	}
	node(int num, int dep) {
		parent = NULL;
		depth = dep;
		value = value_sum = 0;
		folder_num = num;
	}
};

class Tree {
public:
	vector <node*> nodelist;
	node* root;
	node* find(int data) {
		for (auto i : nodelist)
			if (i->folder_num == data)
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
	void postorder_sum(node* curnode) {
		for (auto i : curnode->childlist) {
			postorder_sum(i);
			curnode->value_sum += i->value_sum;
		}
		curnode->value_sum += curnode->value;
	}
	void file_size(int num, int size) {
		if (find(num) == NULL)
			return;
		find(num)->value = size;
	}
	void postorder_search(int standard_size, node* curnode) {
		for (auto i : curnode->childlist)
			postorder_search(standard_size, i);
		if (curnode->value_sum >= standard_size)
			cout << curnode->folder_num << ' ';
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int args1, args2, node_count, standard_size;
	Tree tree;
	cin >> node_count >> standard_size;
	for (int i = 1; i < node_count; i++) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	for (int i = 0; i < node_count; i++) {
		cin >> args1 >> args2;
		tree.file_size(args1, args2);
	}
	tree.postorder_sum(tree.root);
	tree.postorder_search(standard_size,tree.root);
}
