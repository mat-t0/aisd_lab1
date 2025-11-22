#pragma once
#include <stdio.h>

class dArray {
private:
	int* data;
	int size = 0;
	int cap = 0;

public:
	dArray() {
		data = nullptr;
	}

	~dArray() {
		delete[] data;
	}

	dArray(int len) {
		cap = len;
		data = new int[cap];
	}

	dArray(int len, const int* arr, int lenarr) {
		cap = (len > lenarr) ? len : lenarr;
		data = new int[cap];
		size = 0;
		for (int i = 0; i < lenarr; i++) {
			data[size++] = arr[i];
		}
	}

	void print() const {
		for (int i = 0; i < size; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
	}

	int getSize() {
		return size;
	}

	int getCap() {
		return cap;
	}

	void resizeArr(int n = 0) {
		int newCap = (cap == 0) ? 1 : cap * 2; 
		if (n > 0 && newCap < cap + n) {
			newCap = cap + n;
		}

		int* arr = new int[newCap];
		for (int i = 0; i < size; i++) {
			arr[i] = data[i];
		}
		delete[] data;
		data = arr;
		cap = newCap;
	}

	void pushBack(int i) {
		if (size + 1 > cap) {
			resizeArr(1);
		}
		data[size++] = i;

	}

	void pushFront(int i) {
		if (size + 1 > cap) {
			resizeArr(1);
		}
		for (int j = size; j > 0; j--) {
			data[j] = data[j - 1];
		}
		data[0] = i;
		size++;
	}

	void popBack() {
		if (size > 0) size--;
	}

	void popFront() {
		if (size == 0) return;
		for (int i = 0; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void insertItem(int i, int dat) {
		if (i<0 || i>size) {
			printf("index out of range\n");
			return;
		}
		if (i == 0) {
			pushFront(dat);
			return;
		}
		if (i == size) {
			pushBack(dat);
			return;
		}
		
		if (size + 1 > cap) {
			resizeArr();
		}

		for (int j = size; j > i; j--) {
			data[j] = data[j - 1];
		}
		size++;
		data[i] = dat;
	}

	void delItem(int i) {
		if (i < 0 || i >= size) {
			printf("index out of range\n");
			return;
		}
		if (i == 0) {
			popFront();
			return;
		}
		if (i == size-1) {
			popBack();
			return;
		}
		
		for (int j = i; j < size - 1; j++) {
			data[j] = data[j + 1];
		}
		size--;
	}

	int& operator[](int i) {
		if (i < 0 || i >= size) {
			throw "Index out of range";
		}
		return data[i];
	}


};
