#include <iostream>
#include "genDLList.h"

DoublyLinkedList::~DoublyLinkedList() {
    for (DLLNode *p; !isEmpty();){
        p = head->next; // give address in head to p
        delete head; // delete current head
        head = p; // assign the address of next node into head
        //the loop continues till it has deleted every node
    }
}

void DoublyLinkedList::addToDLLTail(int value){
    if (!DoublyLinkedList::isEmpty()) { // check if list empty
        tail = new DLLNode(value, 0, tail);
        tail->prev->next = tail;
    }
    else {
        head = new DLLNode(value);
        tail = head;
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

void DoublyLinkedList::insertAtFront(int value) {
    if (!DoublyLinkedList::isEmpty()){
        head = new DLLNode(value, head, 0);
        head->next->prev = head;
    }
    else {
        head = new DLLNode(value);
        tail = head;
    }
}
