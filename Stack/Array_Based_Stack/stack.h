#ifndef STACK
#define STACK

template <class T>
class Stack {
    public:
        Stack() {
            top = -1;
        }
        bool isEmpty() const;
        bool isFull() const;
        void push(T);
        T pop();
        T peek();
    
    private:
        const int capacity = 100;
        T stackArray[100];
        int top;
};

#endif