
#include <iostream>

using namespace std;

template<typename T>

struct Node {
    T data;
    Node* next;

    Node(T element) : data(element), next(nullptr) {}
};

template<typename T>

/*
Simple linked list that just stores items in a list which are connected and have to be
accessed through their connections. Think like you hvae to go through 1st to get to 2nd and so on..
*/

class LinkedList {
    private:
    Node<T>* head;

    public:
    LinkedList() : head(nullptr) {}

    // funtion insert a new node to the beginning of the list

    void InsertBeginning (T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head -> newNode;
    }

    // function to inser a new node to the end of the list

    void InsertEnd (T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) { // empty linkedlist
            head = newNode;
        }
        else { // if not empty need to start from beginning and iterate until at end of list. Then add new item
            Node<T>* tmp = head;

            while (tmp->next != nullptr) { // condition that iterates until there is no "next" (the end)
            tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    // function to delete a specific value/data from the list. 
    // note : if there is an instance of duplicates, it will remove only the first instance
    // duplicates example : delete(55) and list contains 55->55->60

    void DeleteItem (T key) {
        Node<T>* nodeToDelete = nullptr;
        Node<T>* ptr = head;

        // if list is empty
        if (head == nullptr) { 
            return;
        }

        // if head is the node relating to key
        if (head->data == key) { 
            nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        // condition to navigate thru list to find key
        while (ptr->next != nullptr && ptr->next->data != key) {
            ptr = ptr->next; // iterative
        }

        // was never found so we return
        if (ptr->next == nullptr) { 
            return;
        }

        // else it was found when navigating so delete
        nodeToDelete = ptr->next;
        ptr->next = ptr->next->next;
        delete nodeToDelete;
    }

};