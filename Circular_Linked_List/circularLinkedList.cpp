#include <iostream>
#include "circularLinkedList.h"

CirLinkedList::~CirLinkedList() {
    for (Node *p; !CirLinkedList::isEmpty(); ){
        p = head->next;
        if (p == head){
            head = 0;
            p = 0;
        }
        else {
            delete head;
            head = p;
        }
    }
}

void CirLinkedList::addToHead(int value) {
    if (CirLinkedList::isEmpty()){
        head = new Node(value);
        head->next = head;
    }
    else {
        Node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        head = new Node(value, head);
        temp->next = head;
    }
}

void CirLinkedList::printList() const {
    if (head == 0){
      std::cout << "The list is empty\n";  
    }
    else {
        Node *temp = head;

        std::cout << temp->info << '\n';
        temp = temp->next;

        while (temp != head){
            std::cout << temp->info << '\n';
            temp = temp->next;
        }
    }
}

void CirLinkedList::deleteFromHead() {
    Node *temp = head;

    if (temp->next == head){
        delete head;
        head = 0;
        temp = 0;
    }
    else {
        while (temp->next != head){
            temp = temp->next;
        }

        temp->next = head->next;
        delete head;
        head = temp->next;
    }
}