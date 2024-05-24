#include <iostream>

using namespace std;

#define no_item 0
#define available 1
#define is_item 2

class entry {
public:
	int key;
	int valid;
	string value;
	entry() {
		key = 0;
		value = "";
		valid = no_item;
	}
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		this->valid = is_item;
	}
	bool isitem() {
		return this->valid == is_item;
	}
	bool noitem() {
		return this->valid == no_item;
	}
	void erase() {
		this->valid = available;
	}
};

class hashtable {
public:
	entry* table;
	int capacity;
	int hash(int key) {
		return key % capacity;
	}
	hashtable(int n) {
		table = new entry[n];
		capacity = n;
	}
	void put(int k, string s) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].isitem() && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		entry* e = new entry(k, s);
		table[idx] = *e;
		cout << cnt + idx << '\n';
	}
	void erase(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (!table[idx].noitem() && cnt <= capacity) {
			if (table[idx].isitem() && table[idx].key == k) {
				cout << table[idx].value << '\n';
				table[idx].erase();
				return;
			}
			idx = hash(idx + 1);
		}	
		cout << "None\n";
	}
	string find(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (!table[idx].noitem() && cnt <= capacity) {
			if (table[idx].isitem() && table[idx].key == k)
				return table[idx].value;
			idx = hash(idx + 1);
			cnt++;
		}
		return "None";
	}
	int vacant() {
		int count = 0;
		for (int i = 0; i < capacity; i++)
			if (!table[i].isitem())
				count++;
		return count;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, input;
	string cmd, value;
	cin >> t >> n;
	hashtable* ht = new hashtable(n);
	while (t--) {
		cin >> cmd;
		if (cmd == "put") {
			cin >> input >> value;
			ht->put(input, value);
		}
		else if (cmd == "erase") {
			cin >> input;
			ht->erase(input);
		}
		else if (cmd == "find") {
			cin >> input;
			cout << ht->find(input) << '\n';
		}
		else if (cmd == "vacant") {
			cout << ht->vacant() << '\n';
		}
	}
}