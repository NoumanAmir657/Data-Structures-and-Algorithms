#include <iostream>
#include "stack.h"


template <class T> bool Stack<T>::isEmpty() const {
    return top == -1;
}


template <class T> bool Stack<T>::isFull() const {
    return top == (capacity-1);
}


template <class T> void Stack<T>::push(T value){
    if (!Stack::isFull()){
        stackArray[top+1] = value;
        ++top;
        std::cout << value << " was pushed into the stack\n"; 
    }
    else {
        std::cout << "Stack is full\n";
    }
}


template <class T> T Stack<T>::pop() {
    if (!Stack::isEmpty()){
        std::cout << stackArray[top] << " was poped from the stack\n";
        return stackArray[top--];
    }
    else {
        std::cout << "Stack is empty\n";
        return -1;
    }
}

template <class T> T Stack<T>::peek() {
    if (!Stack::isEmpty()){
        return stackArray[top];
    }
    else {
        return -1;
    }
}

// template class Stack<int>;
template class Stack<char>;
