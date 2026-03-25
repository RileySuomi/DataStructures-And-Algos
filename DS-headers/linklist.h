#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class - a simple singly linked list implementation with basic operations
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Insert at the beginning
    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at the end
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    // Search for a value
    bool search(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Get size
    int getSize() {
        return size;
    }

    // Check if empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Display the list
    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Clear the list
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

#endif // LINKLIST_H
