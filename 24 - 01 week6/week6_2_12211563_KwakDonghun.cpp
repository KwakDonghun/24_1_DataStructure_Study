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
	void depth_com(int first_data, int second_data) {
		int first_idx = find(first_data, nodelist);
		int second_idx = find(second_data, nodelist);
		if (first_idx == -1 || second_idx == -1) {
			cout << "error\n";
			return;
		}
		node* first_node = nodelist[first_idx];
		node* second_node = nodelist[second_idx];
		cout << first_node->depth << ' ' << second_node->depth << ' ';
		int result = first_node->depth - second_node->depth;
		if (result > 0)
			cout << result << '\n';
		else
			cout << -result << '\n';
	}
	/* 
	//node 구조체에 depth가 없는 경우
	
	void depth_com(int first_data, int second_data) {
		int first_idx = find(first_data, nodelist);
		int second_idx = find(second_data, nodelist);
		if (first_idx == -1 || second_idx == -1) {
			cout << "error\n";
			return;
		}
		node* first_node = nodelist[first_idx];
		node* second_node = nodelist[second_idx];
		int first_depth = 0, second_depth = 0;
		node* curnode = first_node;
		while (1) {
			first_depth++;
			if (curnode->parent == root) 
				break;
			else
				curnode = curnode->parent;
		}
		curnode = second_node;
		while (1) {
			second_depth++;
			if (curnode->parent == root)
				break;
			else
				curnode = curnode->parent;
		}
		int result = first_depth - second_depth;
		cout << first_depth << ' ' << second_depth << ' ';
		if (result > 0)
			cout << result << '\n';
		else
			cout << -result << '\n';
	}
	*/
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, args1, args2;
	Tree tree;
	cin >> N >> M;
	while (N--) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	while (M--) {
		cin >> args1 >> args2;
		tree.depth_com(args1, args2);
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
	void depth_com(int first, int second) {
		node* first_node = find(first);
		node* second_node = find(second);
		if (first_node == NULL || second_node == NULL) {
			cout << "error\n";
			return;
		}
		int result = first_node->depth - second_node->depth;
		cout << first_node->depth << ' ' << second_node->depth << ' ';
		if (result > 0)
			cout << result << '\n';
		else
			cout << -result << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, args1, args2;
	Tree tree;
	cin >> N >> M;
	while (N--) {
		cin >> args1 >> args2;
		tree.insertnode(args1, args2);
	}
	while (M--) {
		cin >> args1 >> args2;
		tree.depth_com(args1, args2);
	}
}
*/