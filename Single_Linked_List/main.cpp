#include <iostream.>
#include "intSLList.h"


int main() {
    IntSLList list;
    list.addToHead(5);
    list.addToTail(10);
    list.addToTail(15);
    list.addToTail(25);
    list.addToTail(35);
    list.addToTail(45);
    list.addToTail(55);

    list.reverseLinkedList();
    list.printList();
    


    std::cin.get(); 
    return 0;
}