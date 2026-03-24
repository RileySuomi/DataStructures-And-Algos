#ifndef tree_h
#define tree_h

#include <iostream>
#include <stdexcept>
#include <stack>

namespace algorithm {

    template <typename T> // using template allows for generic programming, so we can use this tree for any data type. 

    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T d) : data(d), left(nullptr), right(nullptr) {}
    };

    template <typename T>

    /*
    A binary search tree (BST) is a data structure where each node has at most two children,
    and for each node, all elements in its left subtree are less than the node,
    and all elements in its right subtree are greater than the node.

    Could make a more basic binary tree that doesnt have the ordering property but this is more common and useful.
    And good practive for understanding trees in general.
    */

    class Tree {
        private:
        Node<T>* root;
        size_t count;

        // Helper function to find minimum node iteratively
        Node<T>* findMin(Node<T>* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        // Helper function to delete all nodes iteratively
        void deleteTree(Node<T>* node) {
            if (node == nullptr) return;
            std::stack<Node<T>*> s;
            s.push(node);
            while (!s.empty()) {
                Node<T>* current = s.top();
                s.pop();
                if (current->left) s.push(current->left);
                if (current->right) s.push(current->right);
                delete current;
            }
        }

        public:
        Tree() : root(nullptr), count(0) {}

        ~Tree() {
            deleteTree(root);
        }

        // Function to insert a value into the tree iteratively
        void insert(T data) {
            if (root == nullptr) {
                root = new Node<T>(data);
                count++;
                return;
            }
            Node<T>* current = root;
            Node<T>* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                } else if (data > current->data) {
                    current = current->right;
                } else {
                    return; // duplicate, do nothing
                }
            }
            if (data < parent->data) {
                parent->left = new Node<T>(data);
            } else {
                parent->right = new Node<T>(data);
            }
            count++;
        }

        // Function to remove a value from the tree iteratively
        void remove(T data) {
            if (root == nullptr) return;
            Node<T>* current = root;
            Node<T>* parent = nullptr;
            bool isLeftChild = false;
            // Find the node to remove and its parent
            while (current != nullptr && current->data != data) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    isLeftChild = true;
                } else {
                    current = current->right;
                    isLeftChild = false;
                }
            }

            if (current == nullptr) return; // not found
            // Case 1: No children
            if (current->left == nullptr && current->right == nullptr) {
                if (current == root) {
                    root = nullptr;
                } else if (isLeftChild) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                delete current;
                count--;
            }

            // Case 2: One child
            else if (current->left == nullptr) {
                if (current == root) {
                    root = current->right;
                } else if (isLeftChild) {
                    parent->left = current->right;
                } else {
                    parent->right = current->right;
                }
                delete current;
                count--;
            } else if (current->right == nullptr) {
                if (current == root) {
                    root = current->left;
                } else if (isLeftChild) {
                    parent->left = current->left;
                } else {
                    parent->right = current->left;
                }
                delete current;
                count--;
            }

            // Case 3: Two children
            else {
                // Find inorder successor (min in right subtree)
                Node<T>* successor = findMin(current->right);
                T val = successor->data;
                // Remove successor
                remove(val); // recursive call, but since it's the min, it will be case 1 or 2
                // Replace current's data with successor's data
                current->data = val;
            }
        }

        // Function to search for a value in the tree
        bool search(T data) {
            Node<T>* current = root;
            while (current != nullptr) {
                if (data == current->data) {
                    return true;
                } else if (data < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            return false;
        }

        // Function to get the size of the tree
        size_t size() {
            return count;
        }

        // Function to check if the tree is empty
        bool isEmpty() {
            return root == nullptr;
        }

        // Function to perform inorder traversal iteratively
        void inorderTraversal() {
            if (root == nullptr) return;
            std::stack<Node<T>*> s;
            Node<T>* current = root;
            while (current != nullptr || !s.empty()) {
                while (current != nullptr) {
                    s.push(current);
                    current = current->left;
                }
                current = s.top();
                s.pop();
                std::cout << current->data << " ";
                current = current->right;
            }
            std::cout << std::endl;
        }
    };

};

#endif
