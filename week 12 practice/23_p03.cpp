#include <iostream>
#include <string>

using namespace std;

#define no_item 0;
#define available 1;
#define is_item 2;

class entry {
public:
	int valid;
	int key;
	string value;
	entry() {
		valid = no_item;
		value = "";
		key = 0;
	}
	entry(int key, string value) {
		this->valid = is_item;
		this->key = key;
		this->value = value;
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
	int M;
	int hash1(int k) {
		return k % capacity;
	}
	int hash2(int k) {
		return M - (k % M);
	}
	hashtable(int n, int m) {
		capacity = n;
		M = m;
		table = new entry[capacity];
	}
	void put(int k, string s) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].isitem() && cnt <= capacity) {
			idx = (hash1(k) + cnt * hash2(k)) % capacity;
			cnt++;
		}
		entry* e = new entry(k, s);
		table[idx] = *e;
		cout << cnt + idx << '\n';
	}
	void erase(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (!table[idx].noitem() && cnt <= capacity) {
			if (table[idx].isitem() && table[idx].key == k) {
				cout << table[idx].value << '\n';
				table[idx].erase();
				return;
			}
			idx = (hash1(k) + cnt * hash2(k)) % capacity;
		}
		cout << "None\n";
	}
	string find(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (!table[idx].noitem() && cnt <= capacity) {
			if (table[idx].isitem() && table[idx].key == k)
				return table[idx].value;
			idx = (hash1(k) + cnt * hash2(k)) % capacity;
		}
		return "None";
	}
	int vacant() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++)
			if (!table[i].isitem())
				cnt++;
		return cnt;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, input;
	string cmd, value;
	cin >> T >> N >> M;
	hashtable* hs = new hashtable(N, M);
	while (T--) {
		cin >> cmd;
		if (cmd == "put") {
			cin >> input >> value;
			hs->put(input, value);
		}
		else if (cmd == "erase") {
			cin >> input;
			hs->erase(input);
		}
		else if (cmd == "find") {
			cin >> input;
			cout << hs->find(input) << '\n';
		}
		else if (cmd == "vacant") {
			cout << hs->vacant() << '\n';
		}
	}
}