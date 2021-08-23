#ifndef STACK
#define STACK

class Stack {
    public:
        Stack() {
            top = -1;
        }
        bool isEmpty() const;
        bool isFull() const;
        void push(int);
        int pop();
        int peek();
    
    private:
        const int capacity = 5;
        int stackArray[5];
        int top;
};

#endif