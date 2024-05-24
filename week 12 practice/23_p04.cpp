#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define present 1
#define absent 2
#define available 3

class entry {
public:
	int Id, Class;
	string name;
	int valid;
	entry() {
		valid = no_item;
		Id = Class = 0;
		name = "";
	}
	entry(int X, int C, string s) {
		name = s;
		Id = X;
		Class = C;
		valid = absent;
	}
};
class hashtable {
public:
	entry* nametable;
	entry* idtable;
	int capacity;
	int pow(int a, int n) {
		int result = 1;
		for (int i = 0; i < n; i++)
			result *= a;
		return result;
	}
	int toInt(string s) {
		int result = 0;
		int strlen = s.length();
		for (int i = 0; i < strlen; i++)
			result += ((s[i] - 'a') * pow(26, i));
		return result;
	}
	int hash(int idx) {
		return idx % capacity;
	}
	hashtable() {
		capacity = 500009;
		nametable = new entry[capacity];
		idtable = new entry[capacity];
	}
	void add(int x, int c, string s) {
		int idx = hash(x);
		int cnt = 1;
		while (idtable[idx].valid != no_item && idtable[idx].valid != available && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		entry* newent = new entry(x, c, s);
		idtable[idx] = *newent;
		idx = hash(toInt(s));
		cnt = 1;
		while (nametable[idx].valid != no_item && nametable[idx].valid!=available && cnt <= capacity) {
			idx = hash(idx + 1);
			cnt++;
		}
		nametable[idx] = *newent;
	}
	void erase(int x) {
		int idx = hash(x);
		int cnt = 1;
		while (idtable[idx].valid != no_item && cnt <= capacity) {
			if (idtable[idx].Id == x) {
				cout << idtable[idx].name << ' ' << idtable[idx].Class << '\n';
				idtable[idx].valid = available;
				break;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		string s = idtable[idx].name;
		idx = hash(toInt(s));
		while (nametable[idx].name != s)
			idx = hash(idx + 1);
		nametable[idx].valid = available;
	}
	string search_name(int x) {
		int idx = hash(x);
		int cnt = 1;
		while (idtable[idx].valid != no_item && cnt <= capacity) {
			if (idtable[idx].Id == x)
				return idtable[idx].name;
			idx = hash(idx + 1);
			cnt++;
		}
	}
	void change(int x, int c) {
		int idx = hash(x);
		while (idtable[idx].Id != x) {
			idx = hash(idx + 1);
		}
		idtable[idx].Class = c;
		string n = idtable[idx].name;
		idx = hash(toInt(n));
		while (nametable[idx].name != n) {
			idx = hash(idx + 1);
		}
		nametable[idx].Class = c;

	}
	void present_stu(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (nametable[idx].valid != no_item && cnt <= capacity) {
			if (nametable[idx].name == s) {
				nametable[idx].valid = present;
				cout << nametable[idx].Id << ' ' << nametable[idx].Class << '\n';
				
				int id = nametable[idx].Id;
				idx = hash(id);
				while (idtable[idx].Id != id)
					idx = hash(idx + 1);
				idtable[idx].valid = present;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		
		cout << "Invalid\n";
	}
	void absent_stu(string s) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (nametable[idx].valid != no_item && cnt <= capacity) {
			if (nametable[idx].name == s) {
				nametable[idx].valid = absent;
				cout << nametable[idx].Id << ' ' << nametable[idx].Class << '\n';

				int id = nametable[idx].Id;
				idx = hash(id);
				while (idtable[idx].Id != id)
					idx = hash(idx + 1);
				idtable[idx].valid = absent;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "Invalid\n";
	}
	int getpresentsize() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++)
			if (nametable[i].valid == present)
				cnt++;
		return cnt;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, id, cla;
	string cmd, name;
	hashtable* hs = new hashtable;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> id >> cla >> name;
			hs->add(id, cla, name);
		}
		else if (cmd == "name") {
			cin >> id;
			cout << hs->search_name(id) <<'\n';
		}
		else if (cmd == "delete") {
			cin >> id;
			hs->erase(id);
		}
		else if (cmd == "change") {
			cin >> id >> cla;
			hs->change(id, cla);
		}
		else if (cmd == "present") {
			cin >> name;
			hs->present_stu(name);
		}
		else if (cmd == "absent") {
			cin >> name;
			hs->absent_stu(name);
		}
	}
	cout << hs->getpresentsize() << '\n';
}