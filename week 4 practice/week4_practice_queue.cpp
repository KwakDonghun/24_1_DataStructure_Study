#include <iostream>
#include <string>

using namespace std;

class arrayqueue {
private:
	int* arr;
	int frontindex;
	int rearindex;
	int capacity;
	int size;
public:
	arrayqueue(int c) {
		capacity = c;
		arr = new int[capacity];
		frontindex = rearindex = 0;
		size = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	int getsize() {
		return size;
	}
	int front() {
		if (empty())
			return -1;
		return arr[frontindex];
	}
	void enqueue(int data) {
		if (size >= capacity)
			return;
		arr[rearindex] = data;
		rearindex = (rearindex + 1) % capacity;
		size++;
	}
	void dequeue() {
		if (empty())
			return;
		frontindex=(frontindex + 1) % capacity;
		size--;
	}
};
class node {
private:
	int data;
	node* next;
public:
	node(int val){
		data = val;
		next = NULL;
	}
	friend class listqueue;
};
class listqueue {
private:
	node* frontnode;
	node* rearnode;
	int size;
public:
	listqueue() {
		frontnode = NULL;
		rearnode = NULL;
		size = 0;
	}
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	int getsize() {
		return size;
	}
	int front() {
		if (empty())
			return -1;
		return frontnode->data;
	}
	void enqueue(int val) {
		node* newnode = new node(val);
		if (empty())
		{
			newnode = frontnode;
			frontnode->next = rearnode;
		}
		else {
			newnode = rearnode;
			rearnode = rearnode->next;
		}
		size++;
	}
	void dequeue() {
		if (empty())
			return;
		node* del = frontnode;
		frontnode = frontnode->next;
		delete del;
		size--;
	}
};