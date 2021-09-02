#include "bst.h"

// worst case time complexity is O(n)
template<class T>
T* BST<T>::search(Node<T> *p, const T &value) const{
    while (p != 0) {
        if (value == p->info) {
            return p->info;
        }
        else if (value < p->info){
            p = p->left;
        }
        else{
            p = p->right;
        }
    }
    return 0;
}

template class BST<int>;