#include <iostream>
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

int IntSLList::deleteFromTail() {
    int value = tail->info;

    if (head == tail) {
        delete head;
        head = 0;
        tail = 0;
    }
    else {
        IntSLLNode *temp;
        for (temp = head; temp->next != tail; temp = temp->next);
        delete tail;
        tail = temp;
        tail->next = 0;
    }
    return value;
}

void IntSLList::deleteNode(int value) {
    if (head != 0){ // if list not empty
        if (head == tail && value == head->info) { // if there is only one node in the list and that node's info value matched the value to delete
            delete head;
            head = 0;
            tail = 0;
        }
        else if (value == head->info) { // if there are more than one node in the list and the value to delete is the first node's value
            IntSLLNode *temp = head;
            head = head->next;
            delete temp;
        }
        else {
            IntSLLNode *pred, *temp;
            for (pred = head, temp = head->next; temp != 0 && !(temp->info == value); pred = pred->next, temp = temp->next);

            if (temp != 0) {
                pred->next = temp->next;
                if (temp == tail) {
                    tail = pred;
                }
                delete temp;
            }
        }
    }
}

bool IntSLList::isInList(int value) const {
    IntSLLNode *temp;
    for (temp = head; temp != 0 && !(temp->info == value); temp = temp->next);
    return temp != 0;
}

void IntSLList::printList() const {
    for (IntSLLNode *temp = head; temp != 0; temp = temp->next){
        std::cout << temp->info <<'\n';
    }
}

void IntSLList::printReverse() const {
    IntSLLNode *currentLast = tail;
    IntSLLNode *currentHead = head;

    while (currentHead != 0) {
        while(currentHead->next != currentLast){    
            currentHead = currentHead->next;
        }

        currentLast = currentHead;
        currentHead = head;
        std::cout <<  currentLast->next->info << '\n';

        if (currentHead == head && currentLast == head){
            currentHead = 0;
        }
        
    }  
}

void IntSLList::reverseLinkedList() {
    if (!IntSLList::isEmpty()){
        IntSLLNode *currentLast = tail;
        IntSLLNode *currentHead = head;

        while (currentHead != 0) {
            while (currentHead->next != currentLast){
                currentHead = currentHead->next;
            }
            //std::cout << currentHead->info << '\n';
            currentLast->next = currentHead;
            currentLast = currentHead;
            currentHead = head;

            if (currentHead == head && currentLast == head){
                currentHead->next = 0;
                currentHead = 0;
            }
        }

        IntSLLNode *temp = head;
        head = tail;
        tail = temp;
    }
    else {
        std::cout << "List is empty";
    } 
}

void IntSLList::deleteOdds() {
    IntSLLNode *temp = head;
    IntSLLNode *pre = head;

    if (!(IntSLList::isEmpty())){
        if ((head->info % 2) != 0) {
            head = head->next; //points to address of 2
        }

        temp = head;

        while (temp != 0) {
            if ((temp->info % 2) != 0){
                pre->next = temp->next;
                delete temp;
                temp = pre->next;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }
    }
}
