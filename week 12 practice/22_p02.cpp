#include <iostream>
#include <string>

using namespace std;

#define no_item 0
#define log_in 1
#define log_out 2

class entry {
public:
	string id;
	string pw;
	int valid;
	entry() {
		id = pw = "";
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
		capacity = 200003;
		table = new entry[capacity];
	}
	void signup(string s, string p) {
		int idx = hash(toInt(s));
		int cnt = 1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == s) {
				cout << "Invalid\n";
				return;
			}
			idx = hash(idx + 1);
			cnt++;
		}
		entry* newent = new entry(s, p);
		table[idx] = *newent;
		cout << "Submit\n";
	}
	void login(string s, string p) {
		int idx = hash(toInt(s));
		int cnt=1;
		while (table[idx].valid != no_item && cnt <= capacity) {
			if (table[idx].id == s) {
				if (table[idx].pw != p) {
					cout << "Invalid\n";
					return;
				}
				else {
					if (table[idx].valid == log_in) {
						cout << "Quit\n";
						return;
					}
					else if(table[idx].valid == log_out){
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
	void logout(string s) {
		int idx = hash(toInt(s));
		while (table[idx].valid == log_in) {
			if (table[idx].id == s) {
				cout << "Submit\n";
				table[idx].valid = log_out;
				return;
			}
			idx = hash(idx + 1);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string id, pw, cmd;
	hashtable* hs = new hashtable;
	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "signup") {
			cin >> id >> pw;
			hs->signup(id, pw);
		}
		else if (cmd == "login") {
			cin >> id >> pw;
			hs->login(id, pw);
		}
		else if (cmd == "logout") {
			cin >> id;
			hs->logout(id);
		}
	}
}