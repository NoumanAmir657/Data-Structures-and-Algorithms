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

void DoublyLinkedList::insertSorted(int value) {
    if (!DoublyLinkedList::isEmpty()){
        if (value < head->info){
            DoublyLinkedList::insertAtFront(value);    
        }
        else{
            DLLNode *temp = head->next;

            while (temp != 0){
                if (temp->info > value){
                    DLLNode *newNode = new DLLNode(value, temp, temp->prev);
                    temp->prev->next = newNode;
                    temp->prev = newNode;

                    temp = 0;
                }
                else if (temp == tail && tail->info < value){
                    DoublyLinkedList::addToDLLTail(value);
                }
                else {
                    temp = temp->next;
                }
            }
        }
    }
    else {
        DoublyLinkedList::insertAtFront(value);
    }
}

bool DoublyLinkedList::isInList(int value) {
    DLLNode *temp;
    for (temp = head; temp != 0 && !(temp->info == value); temp = temp->next);
    return temp != 0;
}

int DoublyLinkedList::deleteFromHead() {
    if (!DoublyLinkedList::isEmpty()){
        int value = head->info;
        DLLNode *temp = head;

        if (head->next != 0){ // gives error because if head->next is 0 then there is no head->next->prev
            head->next->prev = 0;
        }
        if (head == tail){ // to check whether this is the last element in the list
            tail  = 0;
        }
        
        head =  head->next;
        delete temp;
        return value;
    }
    else {
        std::cout << "The list is empty\n";
        return -1;
    }
}

void DoublyLinkedList::deleteNode(int value) {
    if (!DoublyLinkedList::isEmpty()){ // if list not empty
        if (head == tail && value == head->info) { // if there is only one node in the list and that node's info value matched the value to delete
            delete head;
            head = 0;
            tail = 0;
        }
        else if (value == head->info) { // if there are more than one node in the list and the value to delete is the first node's value
            DLLNode *temp = head;
            head->next->prev = 0;
            head = head->next;
            delete temp;
        }
        else {
            DLLNode *temp;
            for (temp = head->next; temp != 0 && !(temp->info == value); temp = temp->next);

            if (temp != 0) {
                temp->prev->next = temp->next;
                
                if (temp != tail) {
                    temp->next->prev = temp->prev;
                }
                else {
                    tail = temp->prev;
                }
                delete temp;
            }
        }
    }
    else {
        std::cout << "The list is empty\n";
    }
}

void DoublyLinkedList::reverseList() {
    if (!DoublyLinkedList::isEmpty()){
        DLLNode *current = head;
        DLLNode *p = head;
        DLLNode *temp = 0;

        while (current != 0){
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
    else {
        std::cout << "The list is empty\n";
    }
}