#include <iostream>

class Node {
    public:
        Node *parent;
        Node *left;
        Node *right;
        int height;
        int key;

        Node() {
            parent = 0;
            left = 0;
            right = 0;
            height = 0;
        }
        Node(int value) {
            key = value;
            parent = 0;
            left = 0;
            right = 0;
            height = 0;
        }
};

class Tree {
    private:
        Node *root = 0;

        Node *insert(Node *node, int key){
            // if tree does not exist
            if (node == 0) {
                node = new Node(key);
            }

            else if(node->key < key) {
                node->right = insert(node->right, key);
                node->right->parent = node;
            }
            else {
                node->left = insert(node->left, key);
                node->left->parent = node;
            }

            return node;
        }

        void inorder(Node *node) {
            if (node == 0) {
                return ;
            }

            inorder(node->left);

            std::cout << node->key << " ";

            inorder(node->right);
        }

        Node *search(Node *node, int key) {
            if (node == 0){
                return 0;
            }
            else if(node->key == key) {
                return node;
            }
            else if(node->key < key) {
                return search(node->right, key);
            }
            else {
                return search(node->left, key);
            }
        }

        int findMin(Node *node) {
            if (node == 0) {
                return -1;
            }
            else if (node->left == 0) {
                return node->key;
            }
            else {
                return findMin(node->left);
            }
        }


        int findMax(Node *node) {
            if (node == 0) {
                return -1;
            }
            else if (node->right == 0) {
                return node->key;
            }
            else {
                return findMax(node->right);
            }
        }

        int successor(Node *node) {
            if (node->right != 0) {
                return findMin(node->right);
            }
            else {
                Node *parentNode = node->parent;
                Node *currentNode = node;

                while ((parentNode != 0) && (currentNode == parentNode->right)) {
                    currentNode = parentNode;
                    parentNode = currentNode->parent;
                }

                return parentNode == 0 ? -1 : parentNode->key;
            }
        }

        Node *remove(Node *node, int key) {
            if (node == 0) {
                return 0;
            }

            if (node->key == key) {
                if (node->left == 0 && node->right == 0) {
                    delete node;
                    node = 0;
                }
                else if (node->left == 0 && node->right != 0) {
                    node->right->parent = node->parent;

                    node = node->right;
                }
                else if (node->left != 0 && node->right == 0) {
                    node->left->parent = node->parent;

                    node = node->left;
                }
                else {
                    int successorKey = successor(node);

                    node->key = successorKey;

                    node->right = remove(node->right, successorKey);
                }
            }
            else if(node->key < key) {
                node->right = remove(node->right, key);
            }
            else {
                node->left = remove(node->left, key);
            }

            return node;
        }

        int height (Node *node, int count) {
            if (node == 0){
                return count;
            }
            ++count;

            return std::max(height(node->left, count), height(node->right, count));
        }
    
    public:
        void insert(int key) {
            root = insert(root, key);
        }

        void inorder() {
            inorder(root);
            std::cout << std::endl;
        }

        bool search(int key) {
            Node *result = search(root, key);
            return result == 0 ? false : true;
        }

        int findMin() {
            return findMin(root);
        }

        int findMax() {
            return findMax(root);
        }

        int height() {
            return height(root, 0);
        }
};

int main() {
    Tree *tree = new Tree();

    tree->insert(15);
    tree->insert(5);
    tree->insert(20);
    tree->insert(4);
    tree->insert(6);
    tree->insert(21);
    tree->insert(19);
    tree->insert(22);
    tree->insert(23);
    tree->insert(24);

    tree->inorder();
    tree->height();
    std::cout << "The height is: " << tree->height() << std::endl;
}