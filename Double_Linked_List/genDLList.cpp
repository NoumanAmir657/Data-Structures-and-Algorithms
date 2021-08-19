#include <iostream>
#include "genDLList.h"

void DoublyLinkedList::addToDLLTail(int value){
    if (tail != 0) { // check if list empty
        tail = new DLLNode(value, 0, tail);
        tail->prev->next = tail;
    }
    else {
        head = new DLLNode(value);
        tail = new DLLNode(value);
    }
}

int DoublyLinkedList::deleteFromDLLTail() {
    int value = tail->info;
    if (head == tail) {
        delete head;
        head = 0;
        tail = 0;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return value;
}

void DoublyLinkedList::printList() {
    DLLNode *temp;
    for (temp = head; temp != 0; temp = temp->next){
        std::cout << temp->info << '\n';
    }
}
