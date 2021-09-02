#include <iostream>
#include "bst.h"

int main (){
    BST<int> b;
    b.insert(5);
    b.insert(3);
    b.insert(2);
    b.insert(6);
    b.insert(7);

    // std::cout << b.search(20);
    /*
    b.inorder();
    std::cout << '\n';
    b.MorrisInorder();
    std::cout << '\n';
    b.preorder();
    std::cout << '\n';
    b.postorder();
    */

    b.findAndDeleteByMerging(3);
    b.preorder();
    std::cin.get();
    return 1;
}