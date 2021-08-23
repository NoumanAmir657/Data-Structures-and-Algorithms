#include <iostream>
#include "stack.h"

bool Stack::isEmpty() const {
    return pointer == 0;
}

void Stack::push(int value) {
    if (Stack::isEmpty()){
        pointer = new Node(value);

        std::cout << value << " was pushed to the Stack\n";
    }
    else {
        Node *temp = new Node(value);
        temp->next = pointer;
        pointer = temp;

        std::cout << value << " was pushed to the Stack\n";
    }
}

int Stack::pop() {
    if (Stack::isEmpty()){
        std::cout << "Stack is empty\n";
        return -1;
    }
    else {
        Node *temp = pointer;
        int value = pointer->info;
        pointer = pointer->next;
        delete temp;
        std::cout << value << " was poped from the stack\n";
        return value;
    }
}