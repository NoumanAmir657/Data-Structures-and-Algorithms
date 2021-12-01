#ifndef CIR_LINKED_LIST
#define CIR_LINKED_LIST

class Node {
    public:
        Node(){
            next = 0;
        }
        Node(int value, Node *ptr = 0) {
            info = value;
            next = ptr;
        }
        int info;
        Node *next;
};

class CirLinkedList {
    public:
        CirLinkedList() {
            head = 0;
        }

        ~CirLinkedList();
        
        bool isEmpty() {
            return head == 0;
        }

        void addToHead(int);
        void printList() const;
        void deleteFromHead();

    private:
        Node *head;
};

#endif