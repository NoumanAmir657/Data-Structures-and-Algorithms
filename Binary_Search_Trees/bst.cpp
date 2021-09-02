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

// breadth first traversal: top-down left to right
template <class T>
void BST<T>::breadthFirst() {
    Queue<Node<T>*> queue;
    Node<T> *p = root;

    if (p != 0){
        queue.enqueue(p);
    }
    while (!queue.empty()){
        p = queue.dequeue();
        visit(p);
        if (p->left != 0){
            queue.enqueue(p->left);
        }
        if (p->right != 0){
            queue.enqueue(p->right);
        }
    }
}

// Depth First Traversal
// three tasks
// 1) V -> Visiting a node
// 2) L -> traversing the left subtree
// 3) R -> traversing the right subtree

// inorder -> LVR
template<class T>
void BST<T>::inorder(Node<T> *p){
    if (p != 0){
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

// preorder -> VLR
template<class T>
void BST<T>::preorder(Node<T> *p){
    if (p != 0){
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

// postorder -> LRV
template<class T>
void BST<T>::postorder(Node<T> *p){
    if (p != 0){
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template class BST<int>;