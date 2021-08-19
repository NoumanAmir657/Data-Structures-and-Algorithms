#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class DLLNode {
    public:
        DLLNode() {
            next = 0;
            prev = 0;
        }
        DLLNode(int value, DLLNode *n = 0, DLLNode *p = 0){
            info = value;
            next = n;
            prev = p;
        }
        int info;
        DLLNode *next, *prev;
};

class DoublyLinkedList {
    public:
        DoublyLinkedList() {
            head = 0;
            tail = 0;
        }
        ~DoublyLinkedList();

        bool isEmpty() {
            return head == 0 ? true : false;
        }

        void addToDLLTail(int);
        int deleteFromDLLTail();
        void printList();
        void insertAtFront(int);
        void insertSorted(int);

    protected:
        DLLNode *head, *tail;
};

#endif