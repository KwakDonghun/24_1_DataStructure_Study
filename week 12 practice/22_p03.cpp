#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define available 1
#define is_item 2

class entry {
public:
	int key, valid;
	string value;
	entry() {
		key = valid = no_item;
		value = "";
	}
	entry(int k, string s) {
		key = k;
		value = s;
		valid = is_item;
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
	int hash(int k, int j) {
		return (hash1(k) + j * hash2(k)) % capacity;
	}
	hashtable(int N, int M) {
		this->M = M;
		capacity = N;
		table = new entry[capacity];
	}
	void put(int k, string s) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid == is_item && cnt <= capacity)
			idx = hash(k, cnt++);
		entry* newent = new entry(k, s);
		table[idx] = *newent;
		cout << cnt <<'\n';
	}
	void erase(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].key == k && table[idx].valid == is_item) {
				cout << table[idx].value << '\n';
				table[idx].valid = available;
				return;
			}
			idx = hash(k, cnt++);
		}
		cout << "None\n";
	}
	void find(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].key == k && table[idx].valid == is_item) {
				cout << table[idx].value << '\n';
				return;
			}
			idx = hash(k, cnt++);
		}
		cout << "None\n";
	}
	void vacant() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++)
			if (table[i].valid != is_item)
				cnt++;
		cout << cnt << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, k;
	string cmd, s;
	cin >> T >> N >> M;
	hashtable* hs = new hashtable(N, M);
	while (T--) {
		cin >> cmd;
		if (cmd == "put") {
			cin >> k >> s;
			hs->put(k, s);
		}
		else if (cmd == "erase") {
			cin >> k;
			hs->erase(k);
		}
		else if (cmd == "find") {
			cin >> k;
			hs->find(k);
		}
		else if (cmd == "vacant") {
			hs->vacant();
		}
	}
}