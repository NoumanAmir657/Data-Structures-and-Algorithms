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

class AVL {
    private:
        Node *root;
        
        int getHeight(Node *node) {
            return node == 0 ? -1 : node->height;
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


        Node * rotateLeft(Node *node) {
            Node *balancedNode = node->right;

            balancedNode->parent = node->parent;
            node->parent = balancedNode;

            node->right = balancedNode->left;

            if (balancedNode->left != 0) {
                balancedNode->left->parent = node;
            }

            balancedNode->left = node;

            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            balancedNode->height = std::max(getHeight(balancedNode->left), getHeight(balancedNode->right)) + 1;

            return balancedNode;
            
        }
        Node * rotateRight(Node *node) {
            Node *balancedNode = node->left;

            balancedNode->parent = node->parent;
            node->parent = balancedNode;

            node->left = balancedNode->right;

            if (balancedNode->right != 0) {
                balancedNode->right->parent = node;
            }

            balancedNode->right = node;

            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            balancedNode->height = std::max(getHeight(balancedNode->left), getHeight(balancedNode->right)) + 1;

            return balancedNode;
        }

        Node *insert(Node *node, int key){
            if (node == 0) {
                node = new Node(key);
            }
            else if (node->key < key) {
                node->right = insert(node->right, key);
                node->right->parent = node;
            }
            else {
                node->left = insert(node->left, key);
                node->left->parent = node;
            }

            int balance = getHeight(node->left) - getHeight(node->right);

            if (balance == 2){
                int balance2 = getHeight(node->left->left) - getHeight(node->left->right);
                if (balance2 == 1){
                    node = rotateRight(node);
                }
                else {
                    node->left = rotateLeft(node->left);
                    node = rotateRight(node);
                }
            }
            else if (balance == -2){
                int balance2 = getHeight(node->right->left) - getHeight(node->right->right);
                if (balance2 == -1) {
                    node = rotateLeft(node);
                }
                else {
                    node->right = rotateRight(node->right);
                    node = rotateLeft(node);
                }
            }

            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            return node;
        }

        void preorder(Node *node) {
            if (node != 0){
                std::cout << node->key << " ";
                preorder(node->left);
                preorder(node->right);
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

            if (node != 0) {
                int balance = getHeight(node->left) - getHeight(node->right);

                if (balance == 2) {
                    int balance2 = getHeight(node->left->left) - getHeight(node->left->right);

                    if (balance2 == 1) {
                        node = rotateRight(node);
                    }
                    else {
                        node->left = rotateLeft(node->left);
                        node = rotateRight(node);
                    }
                }
                else if (balance == -2) {
                    int balance2 = getHeight(node->right->left) - getHeight(node->right->right);

                    if (balance2 == -1) {
                        node = rotateLeft(node);
                    }
                    else {
                        node->right = rotateRight(node->right);
                        node = rotateLeft(node);
                    }
                }

                node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            }

            return node;
        }

    public:
        AVL () {
            root = 0;
        }

        void insert(int value) {
            root = insert(root, value);
        }

        void preorder() {
            preorder(root);
        }

        void remove(int value) {
            root = remove(root, value);
        }
};

int main() {
    AVL *avl = new AVL();

    avl->insert(15);
    avl->insert(5);
    avl->insert(20);
    avl->insert(4);

    avl->remove(20);
    
    avl->preorder();
}