#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define is_item 1
#define available 2

struct entry {
	int key, valid;
	string value;
	entry() {
		key = 0;
		value = "";
		valid = available;
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
	int divisor;
	int hash1(int key) {
		return key % capacity;
	}
	int hash2(int key) {
		return divisor - (key % divisor);
	}
	hashtable(int n, int m) {
		capacity = n;
		divisor = m;
		table = new entry[capacity];
	}
	void put(int k, string s) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid == is_item && cnt <= capacity) {
			idx = hash1(idx + hash2(k));
			cnt++;
		}
		if (cnt > capacity) {
			cout << -1 << '\n';
		}
		else {
			table[idx] = entry(k, s);
			cout << hash1(k)<< ' ' << idx << '\n';
		}
	}
	void erase(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].valid == is_item && table[idx].key == k) {
				table[idx].erase();
				cout << table[idx].value << '\n';
				return;
			}
			idx = hash1(idx + hash2(k));
			cnt++;
		}
		cout << "None\n";
	}
	string find(int k) {
		int idx = hash1(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].valid == is_item && table[idx].key == k)
				return table[idx].value;
			idx = hash1(idx + hash2(k));
			cnt++;
		}
		return "None";
	}
	void vacant() {
		int result = 0;
		for (int i = 0; i < capacity; i++)
			if (table[i].valid != is_item)
				result++;
		cout << result << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, k, N, M;
	string cmd, s;
	cin >> T >> N >> M;
	hashtable* hs = new hashtable(N,M);
	while (T--) {
		cin >> cmd;
		if (cmd == "put") {
			cin >> k >> s;
			hs->put(k, s);
		}
		else if (cmd == "find") {
			cin >> k;
			cout << hs->find(k) << '\n';
		}
		else if (cmd == "erase") {
			cin >> k;
			hs->erase(k);
		}
		else if (cmd == "vacant") {
			hs->vacant();
		}
	}

}
