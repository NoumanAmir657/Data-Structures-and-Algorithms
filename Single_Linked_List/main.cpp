#include <iostream.>
#include "intSLList.h"


int main() {
    IntSLList list;
    list.addToHead(2);
    list.addToTail(6);
    list.addToTail(3);
    list.addToTail(4);
    list.addToTail(5);
    list.addToTail(7);
    list.addToTail(8);
    list.addToTail(9);

    //list.reverseLinkedList();
    //list.deleteOdds();
    list.groupingNodes();
    //list.swapNodes(1,6);    
    list.printList();
    


    std::cin.get(); 
    return 0;
}