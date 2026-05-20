#ifndef set_h
#define set_h

#include <iostream>
#include <stdexcept>

namespace algorithm {

    template<typename T> // template (for the node) allows for generic programming

    // since using link list need to set up node format

    struct Node {
        T data; // data held in node
        Node* next; // ptr to next node .. will help make easier to add and delete things in set
        
        Node(const T& val) : data(val), next(nullptr) {} // constructor for node
    };
    
    template<typename T> // template (for the set) allows for generic programming

    class Set {
    private:
        size_t count; // the current size of set
        Node<T>* head; // ptr to head of linked list
        
        // helper function to find a node with given data
        Node<T>* findNode(const T& data) const {
            Node<T>* current = head;
            while (current != nullptr) {
                if (current->data == data) {
                    return current;
                }
                current = current->next;
            }
            return nullptr;
        }
        
    public:
        Set() : count(0), head(nullptr) {} 
       
        ~Set() { 
            while (head != nullptr) // while the head isnt "nothing"
            {
                remove(head->data); // remove each element
            }
        }

        // simple function to check if the set is empty or not

        bool isEmpty() const {
            return count == 0;
        }

        // insert function in a set, adds an element to the set (no duplicates allowed)

        void insert(const T& data) {
            // check if element already exists (sets don't allow duplicates)
            if (findNode(data) != nullptr) {
                return; // element already in set, do nothing
            }
            
            Node<T>* newnode = new Node<T>(data); // create a ptr of new object putting in set
            newnode->next = head; // link new node to current head
            head = newnode; // now new head is the newnode
            count++; // size of set increased
        }

        // remove function in a set, removes an element from the set

        void remove(const T& data) {
            if (head == nullptr) { // if nothing in set
                throw std::runtime_error("remove error, set is empty");
            }
            
            // check if head is the element to remove
            if (head->data == data) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                count--;
                return;
            }
            
            // search for element in the rest of the list
            Node<T>* current = head;
            while (current->next != nullptr) {
                if (current->next->data == data) {
                    Node<T>* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    count--;
                    return;
                }
                current = current->next;
            }
            
            throw std::runtime_error("remove error, element not found in set");
        }

        // contains function in a set, checks if element exists in set

        bool contains(const T& data) const {
            return findNode(data) != nullptr;
        }

        // simple function that returns the size of the set 

        size_t size() const {
            return count;
        }

    };

}

#endif
