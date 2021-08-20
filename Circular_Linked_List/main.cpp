#include <iostream>
#include "circularLinkedList.h"

int main() {
    CirLinkedList list;
    list.addToHead(1);
    list.addToHead(2);
    list.addToHead(3);
    list.addToHead(4);
    list.addToHead(5);
    list.deleteFromHead();
    list.deleteFromHead();
    list.deleteFromHead();
    list.deleteFromHead();
    list.deleteFromHead();

    list.printList();

    std::cin.get();
    return 0;
}