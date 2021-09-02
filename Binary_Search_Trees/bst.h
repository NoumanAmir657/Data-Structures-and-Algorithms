#include <queue>
#include <stack>
#include <iostream>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<class T>
class Stack : public std::stack<T> {
    public:
        T pop() {
            T temp = std::stack<T>::top();
            std::stack<T>::pop();
            return temp;
        }
};

template<class T>
class Queue : public std::queue<T> {
    public:
        T dequeue() {
            T temp = std::queue<T>::front();
            std::queue<T>::pop();
            return temp;
        }
        void enqueue(const T& value){
            std::queue<T>::push(value);
        }
};

template<class T>
class Node {
    public:
        Node() {
            left = 0;
            right = 0;
        }
        Node(const T& e, Node<T> *l = 0, Node<T> *r = 0){
            info = e;
            left = l;
            right = r;
        }
        T info;
        Node<T> *left, *right;
};

template<class T>
class BST {
    public:
        BST() {
            root = 0;
        }
        ~BST() {
            clear();
        }
        void clear(){
            // clear(root);
            root = 0;
        }
        bool isEmpty() const {
            return root == 0;
        }
        void preorder() {
            preorder(root);
        }
        void inorder() {
            inorder(root);
        }
        void postorder() {
            postorder(root);
        }
        T search(const T& value) const {
            return search(root, value);
        }

        void breadthFirst();
        void iterativePreorder();
        void iterativeInorder();
        void iterativePostOrder();
        void MorrisInorder();
        void insert(const T&);
        void deleteByMerging(Node<T>*&);
        void findAndDeleteByMerging(Node<T>*&);
        void deleteByCopying(Node<T>*&);
        void balance(T*, int, int);

    protected:
        Node<T> *root;
        void clear(Node<T>*);
        T search(Node<T>*, const T&) const;
        void preorder(Node<T>*);
        void inorder(Node<T>*);
        void postorder(Node<T>*);
        virtual void visit(Node<T>* p){
            std::cout << p->info << ' ';
        }
};



#endif