#ifndef STACK
#define STACK

class Node {
    public:
        Node() {
            next = 0;
        }
        Node(int value, Node *ptr = 0){
            info = value;
            next = ptr;
        }
        int info;
        Node *next;
};

class Stack {
    public:
        Stack() {
            pointer = 0;
        }

        bool isEmpty() const;
        void push(int);
        int pop();
        int peek();

    private:
        Node *pointer;
};

#endif