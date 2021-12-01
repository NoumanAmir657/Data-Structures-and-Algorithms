#include <iostream>
#include "queue.h"

template<class T, int size>
void CircularQueue<T, size>::enqueue(T value){
    if(!CircularQueue::isFull()){
        if (last == -1 || last == size - 1){
            storage[0] = value;
            if (first == -1){
                first = 0;
            }
            last = 0;
        }
        else {
            last++;
            storage[last] = value;
        }
    }
    else {
        std::cout << "The Queue is Full\n";
    }
}

template<class T, int size>
T CircularQueue<T, size>::dequeue(){
    if (!CircularQueue::isEmpty()){
        T temp = storage[first];
        if (first == last){
            first = -1;
            last = -1;
            return temp;
        }
        else if (first == size-1){
            first = 0;
            return temp;
        }
        else {
            first++;
            return temp;
        }
    }
    else {
        std::cout << "The queue is empty\n";
        return -1;
    }
}

template<class T, int size>
T CircularQueue<T, size>::firstElement() {
    return storage[first];
}

template class CircularQueue<int>;