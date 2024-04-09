#include <iostream>
#include <string>
#include <vector>

using namespace std;

//landvibe_lecture
/*
class node {
public:
	node* parent;
	vector<node*> children;
	int val;
	int depth;
	node(node* p, int v) {
		parent = p;
		val = v;
		depth = p->depth + 1;
	}

	node(int v, int dep) {
		parent = NULL;
		val = v;
		depth = dep;
	}
};

class tree {
public:
	node* root;
	vector<node*>nodelist;

	tree() {
		root = new node(1, 0);
		nodelist.push_back(root);
	}
	node* findnode(int x) {
		for (auto Node : nodelist) {
			if (Node->val == x)
				return Node;
		}
		return NULL;
	}
	void insert(int parent_node, int val) {
		node* parentnode = findnode(parent_node);
		if (parentnode == NULL || findnode(val) != NULL) {
			cout << -1 << '\n';
			return;
		}
		node* newnode = new node(parentnode, val);
		parentnode->children.push_back(newnode);
		nodelist.push_back(newnode);
	}
	void erase(int val) {
		node* delnode = findnode(val);
		if (delnode == NULL) {
			cout << -1 << '\n';
			return;
		}
		//val이란 delnode가 없을 시 return
		
		for (auto Node : delnode->children) {
			delnode->parent->children.push_back(Node);
			Node->parent = delnode->parent;
		}
		//delnode의 children을 delnode의 parent의 children에 합류
		
		for (int i = 0; i < delnode->parent->children.size();i++) {
			if (delnode->parent->children[i] == delnode) {
				delnode->parent->children.erase(delnode->parent->children.begin() + i);
				break;
			}
		}
		//delnode의 parent의 children vector에서 delnode 삭제
		
		for (int i = 0; i < nodelist.size(); i++) {
			if (nodelist[i] == delnode){
				nodelist.erase(nodelist.begin() + i);
				break;
			}
		}
		//nodelist에서 delnode 삭제 
		
		delete delnode;
	}
	void parent(int val) {
		node* newnode = findnode(val);
		if (newnode == NULL) {
			cout << -1 << "\n";
			return;
		}
		cout << newnode->parent->val << '\n';
	}
	void child(int val) {
		node* newnode = findnode(val);
		if (newnode == NULL) {
			cout << -1 << "\n";
			return;
		}
		for (auto Node : newnode->children)
			cout << Node->val << ' ';
		cout <<'\n';
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	string cmd;
	cin >> t;
	tree* Tree = new tree();
	while (t--) {
		cin >> cmd;
		int arg1, arg2;
		if (cmd == "insert") {
			cin >> arg1 >> arg2;
			Tree->insert(arg1, arg2);
		}
		else if (cmd == "delete") {
			cin >> arg1;
			Tree->erase(arg1);
		}
		else if (cmd == "parent") {
			cin >> arg1;
			Tree->parent(arg1);
		}
		else if (cmd == "child") {
			cin >> arg1;
			Tree->child(arg1);
		}

	}
}
*/

//23-prob-w6-p1 & p3
/*
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
		if (parentnode == NULL || findnode(val)!=NULL) {
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
		for(auto Node:delnode->children){
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
		if (newnode == NULL || newnode->children.size()==0) {
			cout << -1 << '\n';
			return;
		}
		for (auto Node : newnode->children) {
			cout << Node->value << ' ';
		}
		cout << '\n';
	}
	void min_maxchild(int val) {
		int max = 0, min = 10001;
		node* newnode = findnode(val);
		if (newnode == NULL || newnode->children.size() < 2) {
			cout << -1 << '\n';
			return;
		}
		for (auto Node : newnode->children) {
			if (Node->value > max)
				max = Node->value;
			if (Node->value < min)
				min = Node->value;
		}
		cout << max + min << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, args1, args2;
	string cmd;
	cin >> testcase;
	tree T;
	for (int i = 0; i < testcase; i++) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> args1 >> args2;
			T.insert(args1, args2);
		}
		else if (cmd == "delete") {
			cin >> args1;
			T.erase(args1);
		}
		else if (cmd == "parent") {
			cin >> args1;
			T.parent(args1);
		}
		else if (cmd == "child") {
			cin >> args1;
			T.child(args1);
		}
		else if (cmd == "min_maxChild") {
			cin >> args1;
			T.min_maxchild(args1);
		}
	}
}
*/

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
	void depth_com(int node1, int node2){
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