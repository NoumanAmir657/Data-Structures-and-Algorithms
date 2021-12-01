#include <iostream>
#include "stack.h"

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();


    std::cin.get();
    return 1;
}