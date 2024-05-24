#include <iostream>
#include <string>

using namespace std;

#define NOITEM 0
#define PRESENT 1
#define ABSENT 2
#define AVAILABLE 3

class entry {
public:
	int id, valid;
	string name;
	entry() {
		id = valid = NOITEM;
		name = "";
	}
	entry(int X, string S) {
		id = X;
		name = S;
		valid = ABSENT;
	}
};

class hashtable {
public:
	int capacity;
	entry* id_table;
	entry* name_table;
	int pow(int a, int n) {
		int result = 1;
		for (int i = 0; i < n; i++)
			result *= a;
		return result;
	}
	int toInt(string s) {
		int result = 0;
		for (int i = 0; i < s.length(); i++)
			result += ((s[i] - 'a') * pow(26, i));
		return result;
	}
	int hash(int k) {
		return k % capacity;
	}
	hashtable() {
		capacity = 200003;
		id_table = new entry[capacity];
		name_table = new entry[capacity];
	}
	void add(int x, string s) {
		entry* newent = new entry(x, s);
		int idx = hash(x);
		int cnt = 1;
		while ((id_table[idx].valid != NOITEM && id_table[idx].valid != AVAILABLE) && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		id_table[idx] = *newent;
		idx = hash(toInt(s));
		cnt = 1;
		while ((name_table[idx].valid != NOITEM && name_table[idx].valid != AVAILABLE) && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		name_table[idx] = *newent;
	}
	void erase(int x) {
		int idx = hash(x);
		while (id_table[idx].id!=x)
			idx = hash(idx + 1);
		id_table[idx].valid = AVAILABLE;
		string s = id_table[idx].name;
		idx = hash(toInt(s));
		while (name_table[idx].name != s)
			idx = hash(idx + 1);
		name_table[idx].valid = AVAILABLE;
	}
	void getname(int x) {
		int idx = hash(x);
		while (id_table[idx].id != x)
			idx = hash(idx + 1);
		cout << id_table[idx].name << '\n';
	}
	void present(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (name_table[idx].valid != NOITEM && cnt <= capacity) {
			if (name_table[idx].name == s && (name_table[idx].valid == PRESENT || name_table[idx].valid == ABSENT)) {
				name_table[idx].valid = PRESENT;
				int id = name_table[idx].id;
				idx = hash(id);
				while (id_table[idx].id != id)
					idx = hash(idx + 1);
				id_table[idx].valid = PRESENT;
				cout << id_table[idx].id << '\n';
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "Invalid\n";
	}
	void absent(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (name_table[idx].valid != NOITEM && cnt <= capacity) {
			if (name_table[idx].name == s && (name_table[idx].valid == PRESENT || name_table[idx].valid == ABSENT)) {
				name_table[idx].valid = ABSENT;
				int id = name_table[idx].id;
				idx = hash(id);
				while (id_table[idx].id != id)
					idx = hash(idx + 1);
				id_table[idx].valid = ABSENT;
				cout << id_table[idx].id << '\n';
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "Invalid\n";
	}
	void present_student_cnt(){
		int cnt = 0;
		for (int i = 0; i < capacity; i++) 
			if (name_table[i].valid == PRESENT)
				cnt++;
		cout << cnt << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x;
	string s, cmd;
	hashtable* hs = new hashtable;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> x >> s;
			hs->add(x, s);
		}
		else if (cmd == "delete") {
			cin >> x;
			hs->erase(x);
		}
		else if (cmd == "name") {
			cin >> x;
			hs->getname(x);
		}
		else if (cmd == "present") {
			cin >> s;
			hs->present(s);
		}
		else if (cmd == "absent") {
			cin >> s;
			hs->absent(s);
		}
	}
	hs->present_student_cnt();
}