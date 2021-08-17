#include <iostream.>
#include "intSLList.h"


int main() {
    IntSLList list;
    list.addToHead(1);
    list.addToTail(3);
    list.addToTail(4);
    list.addToTail(5);
    list.addToTail(6);
    list.sortedInsertion(-1);
    list.sortedInsertion(9);
    list.sortedInsertion(8);
    list.sortedInsertion(2);
    list.sortedInsertion(7);

    //list.reverseLinkedList();
    //list.deleteOdds();
    //list.groupingNodes();
    //list.swapNodes(1,6);    
    list.printList();
    


    std::cin.get(); 
    return 0;
}