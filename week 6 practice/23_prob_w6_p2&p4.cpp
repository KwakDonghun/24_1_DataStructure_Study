#include <iostream>
#include <string>
#include <vector>

using namespace std;

//23-prob-w6-p2&p4
class node {
public:
	int value;
	int depth;
	node* parent;
	vector<node*> children;
	node(node* p, int val) {
		value = val;
		parent = p;
		depth = parent->depth + 1;
	}
	node(int val, int dep) {
		depth = dep;
		value = val;
		parent = NULL;
	}
};

class tree {
public:
	vector<node*> nodelist;
	node* root;

	tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	node* findnode(int val) {
		for (auto Node : nodelist) {
			if (Node->value == val)
				return Node;
		}
		return NULL;
	}
	void insert(int parent_val, int val) {
		node* parentnode = findnode(parent_val);
		if (parentnode == NULL || findnode(val) != NULL) {
			cout << -1 << '\n';
			return;
		}
		node* newnode = new node(parentnode, val);
		parentnode->children.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void erase(int del_val) {
		node* delnode = findnode(del_val);
		if (delnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		for (auto Node : delnode->children) {
			delnode->parent->children.push_back(Node);
			Node->parent = delnode->parent;
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
		node* newnode = findnode(val);
		if (newnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		cout << newnode->parent->value << '\n';
	}
	void child(int val) {
		node* newnode = findnode(val);
		if (newnode == NULL || newnode->children.size() == 0) {
			cout << -1 << '\n';
			return;
		}
		for (auto Node : newnode->children) {
			cout << Node->value << ' ';
		}
		cout << '\n';
	}
	void depth_com(int node1, int node2) {
		node* com_node1 = findnode(node1);
		node* com_node2 = findnode(node2);
		if (com_node1 == NULL || com_node2 == NULL) {
			cout << -1 << '\n';
			return;
		}
		cout << com_node1->depth - com_node2->depth << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, args1, args2;
	cin >> N >> M;
	tree T;
	for (int i = 0; i < N; i++) {
		cin >> args1 >> args2;
		T.insert(args1, args2);
	}
	for (int i = 0; i < M; i++) {
		cin >> args1 >> args2;
		T.depth_com(args1, args2);
	}
}