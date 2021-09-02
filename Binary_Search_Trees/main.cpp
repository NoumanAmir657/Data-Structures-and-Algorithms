#include <iostream>
#include "bst.h"

int main (){
    BST<int> b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(3);
    b.insert(7);

    // std::cout << b.search(20);
    b.inorder();
    std::cout << '\n';
    b.preorder();
    std::cout << '\n';
    b.postorder();

    std::cin.get();
    return 1;
}