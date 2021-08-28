#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

template<class T, int size = 5>
class CircularQueue {
    public:
        CircularQueue(){
            first = -1;
            last = -1;
        }

        void enqueue(T);
        T dequeue();
        bool isFull() {
            return first == 0 && last == size-1 || first == last+1;
        }
        bool isEmpty(){
            return first == -1;
        }
        T firstElement();

    private:
        int first, last;
        T storage[size];
};

#endif