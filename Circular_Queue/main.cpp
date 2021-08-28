#include <iostream>
#include "queue.h"

int main() {
    CircularQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();
    q.enqueue(11);
    q.enqueue(12);

    std::cout << q.firstElement() << '\n';

    std::cin.get();
    return 1;
}