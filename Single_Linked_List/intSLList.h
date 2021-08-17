#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode {
    public:
        IntSLLNode(){
            next = 0;
        }
        IntSLLNode(int value, IntSLLNode *ptr = 0){
            info = value;
            next = ptr;
        }
        int info;
        IntSLLNode *next;
};

class IntSLList {
    public:
        IntSLList() {
            head = 0;
            tail = 0;
        }
        ~IntSLList();

        int isEmpty() {
            return head == 0;
        }

        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);
        bool isInList(int) const;
        void printList() const;
        void printReverse() const;
        void reverseLinkedList();
        void deleteOdds();
        void groupingNodes();
        void swapNodes(int, int);
    
    private:
        IntSLLNode *head, *tail;
};

#endif