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

void DoublyLinkedList::swapNodes(int x, int y) {
    if (DoublyLinkedList::isInList(x) && DoublyLinkedList::isInList(y)){
        DLLNode *temp;
        for (temp = head; temp != 0 && !(temp->info == x); temp = temp->next);
        
        DLLNode *temp2;
        for (temp2 = head; temp2 != 0 && !(temp2->info == y); temp2 = temp2->next);

        DLLNode *swap = 0;
        
        if (temp == head || temp2 == head){
            if (temp == head){
                swap = head; //swap store head address
                head = temp2->prev->next; // the second value predecessor next is saved into head
                temp2->prev->next = swap; // the second value predecessor next points to head now

                swap = temp->prev;
                temp->prev = temp2->prev;
                temp2->prev = swap;

                swap = temp->next;
                temp->next = temp2->next;
                temp2->next = swap;
            }
            else if (temp2 == head){
                swap = head; //swap store head address
                head = temp->prev->next; // the second value predecessor next is saved into head
                temp->prev->next = swap; // the second value predecessor next points to head now

                swap = temp->prev;
                temp->prev = temp2->prev;
                temp2->prev = swap;

                swap = temp->next;
                temp->next = temp2->next;
                temp2->next = swap;
            }
        }
        else {
            if (temp == tail){
                tail = temp2;
            }

            else if(temp2 == tail) {
                tail = temp;
            }

            swap = temp->prev->next;
            temp->prev->next = temp2->prev->next;
            temp2->prev->next = swap;

            swap = temp->prev;
            temp->prev = temp2->prev;
            temp2->prev = swap;

            swap = temp->next;
            temp->next = temp2->next;
            temp2->next = swap;
        }
    }
    else {
        std::cout << "Not in the List \n";
    }
}

void DoublyLinkedList::groupNodes() {
    DLLNode *temp = head;
    DLLNode *current = head;
    DLLNode *pre = head;
    DLLNode *swap = 0;
    DLLNode *swap2 = 0;
    bool found;

    if (!DoublyLinkedList::isEmpty()){
        while (current != 0){
            found = true;
            while (found) {
                if (current->next != 0){
                    if ((current->next->info % 2) != 0){
                        pre = current;
                        current = current->next;
                        found = false;
                    }
                    else {
                        pre = current;
                        current = current->next;
                        if (current == tail){
                            current = 0;
                            found = false;
                        }
                    }
                }
                else {
                    found = false;
                }
            }
            if (current != 0 && pre != head){
                swap = temp->next;
                temp->next = pre->next;
                swap2 = current->next;
                current->next = swap;
                pre->next = swap2;

                pre->prev = current;
                current->prev = temp;

                temp = current;
                current = current->next;
            }
            else if (pre == head){
                temp = current;
            }
        }
    }
}