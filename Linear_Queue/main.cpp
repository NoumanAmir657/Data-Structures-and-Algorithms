#include <iostream>
#include "queue.h"

int main() {
    LinearQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(25);
    q.enqueue(26);
    q.enqueue(27);
    q.enqueue(30);

    std::cout << q.firstElement() << '\n';

    std::cin.get();
    return 1;
}