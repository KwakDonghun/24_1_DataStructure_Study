#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define log_out 1
#define log_in 2

class entry {
public:
	string id;
	string pw;
	int valid;
	entry() {
		id = "";
		pw = "";
		valid = no_item;
	}
	entry(string id, string pw) {
		this->id = id;
		this->pw = pw;
		valid = log_out;
	}
};

class hashtable {
public:
	entry* table;
	int capacity;
	
	int hash(int idx) {
		return idx % capacity;
	}
	int pow(int j, int k) {
		int result = 1;
		for (int i = 0; i < k; i++)
			result *= j;
		return result;
	}
	int toInt(string s) {
		int strlen = s.length();
		int result = 0;
		for (int i = 0; i < strlen; i++)
			result += (pow(26, i) * (s[i] - 'a'));
		return result;
	}
	hashtable() {
		capacity = 500009;
		table = new entry[capacity];
	}
	void signup(string id, string pw) {
		int idx = hash(toInt(id));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == id)
			{
				cout << "Invalid " << table[idx].pw << '\n';
				return;
			}
			idx = hash(idx+1);
			cnt++;
		}
		entry* newID = new entry(id, pw);
		table[idx] = *newID;
		cout << "Submit\n";
	}
	void login(string id, string pw) {
		int idx = hash(toInt(id));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == id ) {
				if (table[idx].pw != pw) {
					cout << "Invalid\n";
					return;
				}
				else {
					if (table[idx].valid == log_in) {
						cout << "Quit\n";
						return;
					}
					else if (table[idx].valid == log_out) {
						cout << "Submit\n";
						table[idx].valid = log_in;
						return;
					}
				}
			}
			idx = hash(idx + 1);
			cnt++;
		}
		cout << "Invalid\n";
	}
	void logout(string id) {
		int idx = hash(toInt(id));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == id)
			{
				cout << "Submit\n";
				table[idx].valid = log_out;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
	}
	void change(string id, string pw) {
		int idx = hash(toInt(id));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == id)
			{
				cout << "Submit\n";
				table[idx].pw = pw;
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
	}
};

int main() {
	int t;
	cin >> t;
	hashtable* ht = new hashtable();
	while (t--) {
		string cmd;
		string id, pw;
		cin >> cmd;
		if (cmd == "signup") {
			cin >> id >> pw;
			ht->signup(id, pw);
		}
		else if (cmd == "login") {
			cin >> id >> pw;
			ht->login(id, pw);
		}
		else if (cmd == "logout") {
			cin >> id;
			ht->logout(id);
		}
		else if (cmd == "change") {
			cin >> id >> pw;
			ht->change(id, pw);
		}
	}
}