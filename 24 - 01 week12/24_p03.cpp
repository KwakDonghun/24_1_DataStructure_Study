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
		key = valid = no_item;
		value = "";
	}
	entry(int k, string s) {
		key = k;
		value = s;
		valid = is_item;
	}
};
class hashtable {
public:
	int capacity;
	entry* table;
	int hash(int k) {
		return k % capacity;
	}
	hashtable(int n) {
		capacity = n;
		table = new entry[capacity];
	}
	void put(int k, string s) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].valid == is_item && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		if (table[idx].valid != is_item) {
			table[idx] = entry(k, s);
			cout << hash(k) << ' ' << idx << '\n';
			return;
		}
		cout << -1 << '\n';
	}
	void erase(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].valid == is_item && table[idx].key == k) {
				cout << table[idx].value << '\n';
				table[idx].valid = available;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "None\n";
	}
	void find(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].valid == is_item && table[idx].key == k) {
				cout << table[idx].value << '\n';
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "None\n";
	}
	void vacant() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++)
			if (table[i].valid != is_item)
				cnt++;
		cout << cnt << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, k, N;
	string cmd, s;
	cin >> T >> N ;
	hashtable* hs = new hashtable(N);
	while (T--) {
		cin >> cmd;
		if (cmd == "put") {
			cin >> k >> s;
			hs->put(k, s);
		}
		else if (cmd == "find") {
			cin >> k;
			hs->find(k);
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