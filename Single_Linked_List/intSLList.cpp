#include <iostream.h>
#include "intSLList.h"

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ){
        p = head->next; // give address in head to p
        delete head; // delete current head
        head = p; // assign the address of next node into head
        //the loop continues till it has deleted every node
    }
}

void IntSLList::addToHead(int value) {
    head = new IntSLLNode(value, head); // create new Node and assign it to head
    // head is now the new node

    // check if list was empty before
    if (tail == 0){
        // if it was empty, then head and tail both point to the same node
        tail = head;
    }
}

void IntSLList::addToTail(int value) {
    // check if list is empty or not
    if (tail != 0) {
        tail->next = new IntSLLNode(value); // new node created
        tail = tail->next; // tail now points to new node
    }
    else {
        head = new IntSLLNode(value);
        tail = head;
    }
}

int IntSLList::deleteFromHead(){
    int value = head->info; // assign value in head to variable value
    IntSLLNode *temp = head; // temp contains the address of the first node now
    if (head == tail) { // if only one node in the list
        head = 0;
        tail = 0;
    }
    else {
        head = head->next; // head now points to second node in the list
    }
    delete temp; // delete temp
    return value; //return deleted value
}