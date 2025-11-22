#pragma once
#include "Stack.hpp"
#include "dArray.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class sortStation {
private:
    dArray inputStr;   
    dArray outputStr;  
    Stack stack;       
    std::string tokens[256]; 
    int tokenCount = 0;

   
    std::string funcs[2] = { "sin", "cos" };
    char operations[5] = { '+', '-', '*', '/', '^' };
    char highPriorityOps[3] = { '*', '/', '^' };
    char lowPriorityOps[2] = { '+', '-' };

    
    bool isNumber(const std::string& num) {
        try {
            std::stoi(num);
            return true;
        }
        catch (...) {
            return false;
        }
    }

    bool findInArr(const std::string& token, std::string* arr, int len) {
        for (int i = 0; i < len; i++) {
            if (token == arr[i]) return true;
        }
        return false;
    }

    bool findInArr(char token, char* arr, int len) {
        for (int i = 0; i < len; i++) {
            if (token == arr[i]) return true;
        }
        return false;
    }

    
    std::string getToken(int index) {
        if (index < 0 || index >= tokenCount) return "";
        return tokens[index];
    }

    
    int getOrAddToken(const std::string& tok) {
        for (int i = 0; i < tokenCount; i++) {
            if (tokens[i] == tok) return i;
        }
        tokens[tokenCount] = tok;
        return tokenCount++;
    }

    
    void sortStationAlgorithm() {
        for (int i = 0; i < inputStr.getSize(); ++i) {
            std::string token = getToken(inputStr[i]);

            if (isNumber(token)) {
                outputStr.pushBack(getOrAddToken(token));
            }
            else if (findInArr(token, funcs, 2)) {
                stack.push(getOrAddToken(token));
            }
            else if (findInArr(token[0], operations, 5)) {
                while (!stack.isEmpty()) {
                    std::string top = getToken(stack.peek());
                    if (findInArr(top[0], highPriorityOps, 3) ||
                        (findInArr(top[0], lowPriorityOps, 2) &&
                            findInArr(token[0], lowPriorityOps, 2))) {
                        outputStr.pushBack(stack.peek());
                        stack.pop();
                    }
                    else break;
                }
                stack.push(getOrAddToken(token));
            }
            else if (token == "(") {
                stack.push(getOrAddToken(token));
            }
            else if (token == ")") {
                while (!stack.isEmpty() && getToken(stack.peek()) != "(") {
                    outputStr.pushBack(stack.peek());
                    stack.pop();
                }
                if (!stack.isEmpty()) stack.pop();
                if (!stack.isEmpty()) {
                    std::string top = getToken(stack.peek());
                    if (findInArr(top, funcs, 2)) {
                        outputStr.pushBack(stack.peek());
                        stack.pop();
                    }
                }
            }
        }

        while (!stack.isEmpty()) {
            outputStr.pushBack(stack.peek());
            stack.pop();
        }
    }

public:
    sortStation(const std::string& mathString) {
        std::string token;
        for (char c : mathString) {
            if (c != ' ') {
                token.push_back(c);
            }
            else {
                if (!token.empty()) {
                    inputStr.pushBack(getOrAddToken(token));
                    token.clear();
                }
            }
        }
        if (!token.empty()) inputStr.pushBack(getOrAddToken(token));

        sortStationAlgorithm();
    }

    void printPostfix() {
        printf("Постфиксная форма: ");
        for (int i = 0; i < outputStr.getSize(); i++) {
            std::cout << getToken(outputStr[i]) << " ";
        }
        std::cout << "\n";
    }
};
