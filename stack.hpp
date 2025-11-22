#pragma once
#include "dArray.hpp"
#include <stdio.h>

class Stack {
private:
    dArray arr;

public:
    Stack() = default;

    bool isEmpty() {
        return arr.getSize() == 0;
    }

    void print() {
        if (isEmpty()) {
            printf("Стек пуст\n");
            return;
        }
        arr.print();
    }

    int length() {
        return arr.getSize();
    }

    void push(int value) {
        arr.pushBack(value);
    }

    void pop() {
        if (isEmpty()) {
            printf("Стек пуст\n");
            return;
        }
        arr.popBack();
    }

    int peek() {
        if (isEmpty()) {
            printf("Стек пуст\n");
        }
        return arr[arr.getSize() - 1];
    }

    

    

    
};
