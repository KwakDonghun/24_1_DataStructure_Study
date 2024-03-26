#include <iostream>
#include <string>

class vector {
private:
	int* arr;
	int index;
	int capacity;
	int f;
	int r;
public:
	vector(int c){
		capacity = c;
		arr = new int[capacity];
		index = -1;
		f = 0; //환형에서 index 0 인 곳
		r = 0; //환형에서 마지막 값 다음 index
	}
	int size() {
		return index + 1;
	}
	bool empty() {
		if (size() == 0)
			return true;
		else
			return false;
	}
	int at(int in) {
		if (in >= size())
			return -1;
		else
			return arr[in];
	}
	void insert(int i, int o) {
		if (i > size())
			return;
		if (size() + 1 > capacity) {
			int* arr2 = new int[2 * capacity];
			for (int j = 0; j < size(); j++) {
				arr2[j] = arr[(f + j) % capacity];
			}
			capacity *= 2;
			f = 0;
			r = size();
			arr = arr2; //class에 있는 arr의 주소값을 arr2로 교체하는 방법이 이게 맞는가? 
		}
		if (i == 0) {
			f = (f - 1 + capacity) % capacity;
			arr[f] = o;
			return;
		}

		// 보편적인 방법에서 insert 하는 법 기입
	}
	void erase(int in) {
		// 환형 방법에서 erase 하는 법 기입
	}
};

