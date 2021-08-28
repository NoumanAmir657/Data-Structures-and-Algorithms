#ifndef LINEAR_QUEUE
#define LINEAR_QUEUE

template<class T, int size = 10>
class LinearQueue {
    public:
        LinearQueue(){
            first = -1;
            last = -1;
        }

        void enqueue(T);
        T dequeue();
        bool isFull() {
            return last == size-1;
        }
        bool isEmpty(){
            return first == -1;
        }

    private:
        int first, last;
        T storage[size];
};

#endif