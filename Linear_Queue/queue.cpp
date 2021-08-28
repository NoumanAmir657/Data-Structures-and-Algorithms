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

template<class T, int size>
T LinearQueue<T, size>::dequeue(){
    if (!LinearQueue::isEmpty()){
        if (first == last){
            T temp = storage[first];
            first = -1;
            last = -1;
            return temp;
        }
        else {
            T temp = storage[first];
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
T LinearQueue<T, size>::firstElement() {
    return storage[first];
}

template class LinearQueue<int>;