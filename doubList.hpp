#pragma once
#include <stdio.h>

class dList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
		Node(int d) : data(d), next(nullptr), prev(nullptr) {}
	};

	Node* head;
	Node* tail;
	int size;

public:
	dList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~dList() {
		delList();
	}

	void delList() {

		Node* curr = head;
        while (curr != 0) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = tail = nullptr;
        size = 0;
	}

	int lenList() {
		return size;
		
	}

	void printList() {
		if (head == nullptr) {
			printf("Список пуст\n");
		}
		else {
			while (head != nullptr) {
				printf("%d ", head->data);
				head = head->next;
			}
			printf("\n");
		}
	}

	void pushBack(int dat) {
		Node* curr = new Node(dat);
		if (head == nullptr) {
			head = tail = curr;
		}
		else {
			tail->next = curr;
			curr->prev = tail;
			tail = curr;
		}
		size++;
	}

	void pushFront(int dat) {
		Node* curr = new Node(dat);
		if (head == nullptr) {
			head = tail = curr;
		}
		else {
			head->prev = curr;
			curr->next = head;
			head = curr;
		}
		size++;
	}

	void popBack() {
		if (tail == nullptr) {
			printf("Список пуст\n");
			return;
		}
		Node* curr = tail;
		tail = tail->prev;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
			delete curr;
		size--; 
		
	}

	void popFront() {
		if (head == nullptr) {
			printf("Список пуст\n");
			return;
		}
		Node* curr = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete curr;
		size--;
	}

	void insertItem(int index, int data) { //нумерация элементов с 1
		if (index < 1 || index > size + 1) {
			printf("Некорректный индекс\n");
			return;
		}

		if (index == 1) {
			pushFront(data);
			return;
		}
		if (index == size + 1) {
			pushBack(data);
			return;
		}

		Node* curr = head;
		for (int i = 1; i < index - 1; ++i) {
			curr = curr->next;
		}
		Node* node = new Node(data);
		node->next = curr->next;
		node->prev = curr;
		curr->next->prev = node;
		curr->next = node;

		size++;
	}

	void delItem(int index) {
		if (index < 1 || index > size) {
			printf("Некорректный индекс\n");
			return;
		}

		if (index == 1) {
			popFront();
			return;
		}
		if (index == size) {
			popBack();
			return;
		}

		Node* curr = head;
		for (int i = 1; i < index; ++i) {
			curr = curr->next;
		}
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;

		size--;
	}

};
