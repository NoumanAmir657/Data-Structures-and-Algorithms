#include <iostream>
#include "genDLList.h"

int main() {
    DoublyLinkedList list;
    list.addToDLLTail(5);
    list.printList();
    //list.deleteFromDLLTail();

    std::cin.get();
    return 0;
}