#include <iostream.>
#include "intSLList.h"


int main() {
    IntSLList list;
    list.addToHead(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);
    list.addToTail(5);
    list.addToTail(6);

    //list.reverseLinkedList();
    //list.deleteOdds();
    //list.swapNodes(1,6); 
    list.reversalMN(0, 5);
    list.printList();
    


    std::cin.get(); 
    return 0;
}