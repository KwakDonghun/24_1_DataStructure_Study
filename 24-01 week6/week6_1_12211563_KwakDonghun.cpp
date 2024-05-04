#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	int data;
	int depth;
	node* parent;
	vector<node*> childlist;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
		this->depth = parent->depth + 1;
	}
	node(int data, int depth) {
		this->data = data;
		this->parent = NULL;
		this->depth = depth;
	}
};
class Tree {
private:
	node* root;
	vector<node*> nodelist;
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < static_cast<int>(list.size()); i++)
			if (list[i]->data == data)
				return i;
		return -1;
	}
public:
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	void insertnode(int pardata, int data) {
		int parindex = find(pardata, nodelist);
		if (parindex == -1 || find(data, nodelist) != -1) {
			cout << -1 << '\n';
			return;
		}
		node* parnode = nodelist[parindex];
		node* newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void deletenode(int data) {
		int index = find(data, nodelist);
		if (index == -1) {
			cout << -1 << '\n';
			return;
		}
		node* delnode = nodelist[index];
		vector <node*>& par_child = delnode->parent->childlist;
		for (auto i : delnode->childlist) {
			par_child.push_back(i);
			i->parent = delnode->parent;
		}
		for (int i = 0; i < static_cast<int>(par_child.size()); i++) {
			if (par_child[i] == delnode) {
				par_child.erase(par_child.begin() + i);
				break;
			}
		}
		for (int i = 0; i < static_cast<int>(nodelist.size()); i++) {
			if (nodelist[i] == delnode) {
				nodelist.erase(nodelist.begin() + i);
				break;
			}
		}
		delete delnode;
	}
	void printparent(int data) {
		int index = find(data, nodelist);
		if (index <= 0) {
			cout << -1 << '\n';
			return;
		}
		node* printnode = nodelist[index];
		cout << printnode->parent->data << '\n';
	}
	void printchild(int data) {
		int index = find(data, nodelist);
		if (index == -1 || nodelist[index]->childlist.empty()) {
			cout << -1 << '\n';
			return;
		}
		node* printnode = nodelist[index];
		for (auto i : printnode->childlist)
			cout << i->data << ' ';
		cout << '\n';
	}
	void min_maxchild(int data) {
		int index = find(data, nodelist);
		if (index == -1 || nodelist[index]->childlist.empty()) {
			cout << -1 << '\n';
			return;
		}
		else if (nodelist[index]->childlist.size() == 1) {
			cout << nodelist[index]->childlist[0]->data << '\n';
		}
		else {
			int max = 1, min = 10000;
			node* printnode = nodelist[index];
			for (auto i : printnode->childlist) {
				if (max < i->data)
					max = i->data;
				if (min > i->data)
					min = i->data;
			}
			cout << max + min << '\n';		
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, args1, args2;
	string cmd;
	Tree tree;
	cin >> testcase;
	while (testcase--) {
		cin >> cmd >> args1;
		if (cmd == "insert") {
			cin >> args2;
			tree.insertnode(args1, args2);
		}
		else if (cmd == "delete")
			tree.deletenode(args1);
		else if (cmd == "parent")
			tree.printparent(args1);
		else if (cmd == "child")
			tree.printchild(args1);
		else if (cmd == "min_maxChild")
			tree.min_maxchild(args1);
	}
}
/*
class Tree {
private:
	node* root;
	vector <node*> nodelist;
	node* find(int val) {
		for (auto i : nodelist)
			if (i->data == val)
				return i;
		return NULL;
	}
public:
	Tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	void insertnode(int pardata, int data) {
		node* parnode = find(pardata);
		node* newnode = find(data);
		if (parnode == NULL || newnode != NULL) {
			cout << -1 << '\n';
			return;
		}
		newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void deletenode(int data) {
		node* delnode = find(data);
		if (delnode == nullptr) {
			cout << -1 << '\n';
			return;
		}
		vector <node*>& delparchild = delnode->parent->childlist;
		for (auto i : delnode->childlist) {
			delparchild.push_back(i);
			i->parent = delnode->parent;
		}
		for (int i = 0; i < static_cast<int>(delparchild.size()); i++) {
			if (delparchild[i] == delnode) {
				delparchild.erase(delparchild.begin() + i);
				break;
			}
		}
		for (int i = 0; i < static_cast<int>(nodelist.size()); i++) {
			if (nodelist[i] == delnode) {
				nodelist.erase(nodelist.begin() + i);
				break;
			}
		}
		delete delnode;
	}
	void parent(int data) {
		node* printnode = find(data);
		if (printnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		cout << printnode->parent->data << '\n';
	}
	void child(int data) {
		node* printnode = find(data);
		if (printnode == NULL || printnode->childlist.empty()) {
			cout << -1 << '\n';
			return;
		}
		for (auto i : printnode->childlist)
			cout << i->data << ' ';
		cout << '\n';
	}
	void min_maxchild(int data) {
		node* printnode = find(data);
		if (printnode == NULL || printnode->childlist.empty()) {
			cout << -1 << '\n';
			return;
		}
		else if (printnode->childlist.size() == 1) {
			cout << printnode->childlist[0]->data << '\n';
			return;
		}
		else {
			int min = 10000, max = 0;
			for (auto i : printnode->childlist) {
				if (min > i->data)
					min = i->data;
				if (max < i->data)
					max = i->data;
			}
			cout << min + max << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, args1, args2;
	string cmd;
	Tree tree;
	cin >> testcase;
	while (testcase--) {
		cin >> cmd >> args1;
		if (cmd == "insert") {
			cin >> args2;
			tree.insertnode(args1, args2);
		}
		else if (cmd == "delete")
			tree.deletenode(args1);
		else if (cmd == "parent")
			tree.parent(args1);
		else if (cmd == "child")
			tree.child(args1);
		else if (cmd == "min_maxChild")
			tree.min_maxchild(args1);
	}
}
*/