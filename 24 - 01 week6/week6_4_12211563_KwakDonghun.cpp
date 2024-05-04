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
		int result = first_node->depth + second_node->depth;
		cout << first_node->depth << ' ' << second_node->depth << ' ' << result << '\n';
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
