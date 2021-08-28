#include <iostream>
#include "queue.h"

template<class T, int size>
void LinearQueue<T, size>::enqueue(T value){
    if(!LinearQueue::isFull()){
        if (LinearQueue::isEmpty()){
            first++;
            storage[first] = value;
            last = first;
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

template class LinearQueue<int>;