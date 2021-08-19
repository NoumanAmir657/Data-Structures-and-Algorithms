#include <iostream>
#include "genDLList.h"

int main() {
    DoublyLinkedList list;
    list.addToDLLTail(1);
    list.addToDLLTail(3);
    list.addToDLLTail(4);
    list.addToDLLTail(5);
    list.addToDLLTail(6);
    
    list.printList();
    //list.deleteFromDLLTail();

    std::cin.get();
    return 0;
}