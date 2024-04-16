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
	void parent(int data) {
		node* searchnode = find(data);
		if (searchnode == NULL || searchnode == root)
			return;
		cout << searchnode->parent->value << '\n';
	}
	void child(int data) {
		node* searchnode = find(data);
		if (searchnode == nullptr || searchnode->childlist.empty())
			return;
		for (auto i : searchnode->childlist)
			cout << i->value << ' ';
		cout << '\n';
	}
	void preorder(node* curnode) {
		cout << curnode->value << ' ';
		for (auto i : curnode->childlist)
			preorder(i);
	}
	void postorder(node* curnode) {
		for (auto i : curnode->childlist)
			postorder(i);
		cout << curnode->value << ' ';
	}
	void inorder(node* curnode) {
		if (curnode->childlist[0] != NULL) // 왼쪽 자식
			inorder(curnode->childlist[0]);
		cout << curnode->value << ' ';
		if (curnode->childlist[1] != NULL) //오른쪽자식
			inorder(curnode->childlist[1]);
	}
};
