#include <iostream>
#include "stack.h"

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == (capacity-1);
}

void Stack::push(int value){
    if (!Stack::isFull()){
        stackArray[top+1] = value;
        ++top;
        std::cout << value << " was pushed into the stack\n"; 
    }
    else {
        std::cout << "Stack is full\n";
    }
}

int Stack::pop() {
    if (!Stack::isEmpty()){
        return stackArray[top--];
    }
    else {
        return -1;
    }
}

int Stack::peek() {
    if (!Stack::isEmpty()){
        return stackArray[top];
    }
    else {
        return -1;
    }
}