#include <iostream.>
#include "intSLList.h"


int main() {
    IntSLList list;
    list.addToHead(5);
    list.addToTail(10);
    list.addToTail(15);
    std::cout << list.isInList(20);
    list.deleteNode(10);
    list.deleteFromHead();
    list.deleteFromTail();
    list.printList();

    if(!list.isEmpty()){
        std::cout << list.deleteFromHead();
    }
    


    std::cin.get(); 
    return 0;
}