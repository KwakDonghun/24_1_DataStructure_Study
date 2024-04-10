#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	int element;
	int depth;
	Node* parent;
	vector<Node*> children;
	Node(int ele, int dep) {
		parent = NULL;
		depth = dep;
		element = ele;
	}
	Node(Node* p, int ele) {
		parent = p;
		element = ele;
		depth = parent->depth+1;
	}
};

class Tree {
public:
	vector<Node*> nodelist;
	Node* root;
	Tree(){
		Node* root = new Node(1, 0);
		nodelist.push_back(root);
	}
	Node* findnode(int val) {
		for (auto node : nodelist) {
			if (node->element == val)
				return node;
		}
		return NULL;

	}
	void insert(int parent_val, int val) {
		Node* parent_node = findnode(parent_val);
		if (parent_node == NULL || findnode(val) != NULL) {
			cout << -1 << '\n';
			return;
		}
		Node* newnode = new Node(parent_node, val);
		parent_node->children.push_back(newnode);
		nodelist.push_back(newnode);
	}

	void erase(int val) {
		Node* delnode = findnode(val);
		if (delnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		for (auto node : delnode->children) {
			delnode->parent->children.push_back(node);
			node->parent = delnode->parent; // ±Ó∏‘¿Ω ¡÷¿«
		}
		for (int i = 0; i < delnode->parent->children.size(); i++) {
			if (delnode->parent->children[i] == delnode) {
				delnode->parent->children.erase(delnode->parent->children.begin() + i);
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
	void parent(int val) {
		Node* newnode = findnode(val);
		if (newnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		cout << newnode->parent->element << '\n';
	}
	void children(int val) {
		Node* newnode = findnode(val);
		if (newnode == NULL || newnode->children.size()==0) {
			cout << -1 << '\n';
			return;
		}
		for (auto node : newnode->children)
			cout << node->element << ' ';
		cout << '\n';
	}
	void maxchild(int val) {
		Node* newnode = findnode(val);
		if (newnode == NULL || newnode->children.size() == 0) {
			cout << -1 << '\n';
			return;
		}
		int max = 0;
		for (auto node : newnode->children) {
			if (max < node->element)
				max = node->element;
		}
		cout << max <<'\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, args1, args2;
	Tree tree;
	string cmd;
	cin >> testcase;
	while (testcase--) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> args1 >> args2;
			tree.insert(args1, args2);
		}
		else if (cmd == "delete") {
			cin >> args1;
			tree.erase(args1);
		}
		else if (cmd == "parent") {
			cin >> args1;
			tree.parent(args1);
		}
		else if (cmd == "child") {
			cin >> args1;
			tree.children(args1);
		}
		else if (cmd == "maxChild") {
			cin >> args1;
			tree.maxchild(args1);
		}
	}
}