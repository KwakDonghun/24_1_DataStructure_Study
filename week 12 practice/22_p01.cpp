#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define available 1
#define is_item 2



class entry {
public:
	int key;
	string value;
	int valid;
	entry() {
		key = 0;
		value = "";
		valid = no_item;
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
	int hash(int idx) {
		return idx % capacity;
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
		table[idx].key = k;
		table[idx].value = s;
		table[idx].valid = is_item;
		cout << cnt << '\n';

	}
	void erase(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].key == k&&table[idx].valid == is_item) {
				cout << table[idx].value << '\n';
				table[idx].valid = available;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "None\n";
	}
	string find(int k) {
		int idx = hash(k);
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].key == k && table[idx].valid == is_item) {
				return table[idx].value;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		return "None";
	}
	int vacant() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++)
			if (table[i].valid != is_item)
				cnt++;
		return cnt;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, k;
	cin >> T >> N;
	string cmd, s;
	hashtable* hs = new hashtable(N);
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
			cout << hs->find(k) << '\n';
		}
		else if (cmd == "vacant") {
			cout << hs->vacant() << '\n';
		}
	}
}