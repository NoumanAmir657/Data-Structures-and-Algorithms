#include "bst.h"

// worst case time complexity is O(n)
template<class T>
T BST<T>::search(Node<T> *p, const T &value) const{
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
template<class T>
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

// an algorithm for traversing a binary search tree without using stack
template<class T>
void BST<T>::MorrisInorder(){
    Node<T> *p = root, *temp;

    while (p != 0){
        if (p->left == 0){
            visit(p);
            p = p->right;
        }
        else {
            temp = p->left;
            while(temp->right != 0 && temp->right != p){
                temp = temp->right;
            }
            
            if(temp->right == 0){
                temp->right = p;
                p = p->left;
            }
            else {
                visit(p);
                temp->right = 0;
                p = p->right;
            }
        }
    }
}

template<class T>
void BST<T>::insert(const T& value){
    Node<T> *p = root, *prev = 0;

    while(p != 0){
        prev = p;
        if (value < p->info){
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if(root == 0){
        root = new Node<T>(value);
    }
    else if(value < prev->info){
        prev->left = new Node<T>(value);
    }
    else {
        prev->right = new Node<T>(value);
    }
}

// deleting bst
template<class T>
void BST<T>::clear(Node<T> *p){
    if (p != 0){
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

// deletion of node from binary tree
// 1) deletion by merging
template<class T>
void BST<T>::deleteByMerging(Node<T>*& node){
    Node<T> *temp = node;
    if (node->right == 0){
        node = node->left;
    }
    else if(node->left == 0){
        node = node->right;
    }
    else {
        temp = node->left;
        while(temp->right != 0){
            temp = temp->right;
        }
        temp->right = node->right;
        temp = node;
        node = node->left;
    }
    delete temp;
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T &value) {
    Node<T> *node = root, *prev = 0;
    while (node != 0){
        if (node->info == value){
            break;
        }
        prev = node;
        if (value < node->info){
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    
    if (node != 0 && node->info == value){
        if (node == root){
            deleteByMerging(root);
        }
        else if(prev->left == node){
            deleteByMerging(prev->left);
        }
        else {
            deleteByMerging(prev->right);
        }
    }
    else if (root != 0){
        std::cout << value << " is not in the tree\n";
    }
    else {
        std::cout << "The tree is empty\n";
    }
}

template class BST<int>;