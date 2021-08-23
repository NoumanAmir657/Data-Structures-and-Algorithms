#include <iostream>
#include "stack.h"

int main (){
    Stack stack;
    //std::cout << stack.isEmpty();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    std::cout << stack.pop() << " was poped from the stack\n";
    std::cout << stack.pop() << " was poped from the stack\n";
    std::cout << stack.pop() << " was poped from the stack\n";
    std::cout << stack.pop() << " was poped from the stack\n";
    stack.push(10);
    stack.push(11);
    std::cout << stack.pop() << " was poped from the stack\n";
    std::cout << "Value at the top of the stack is " << stack.peek();
    
    std::cin.get();
    return 1;
}