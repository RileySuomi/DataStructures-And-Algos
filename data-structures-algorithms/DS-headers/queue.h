#ifndef queue.h
#define queue.h

#include <iostream>
#include <stdexcept>

namespace algorithm {

    template <typename T>

    struct Node {
        public:
        T data;
        Node* next;

        Node(T d) : data(d), next(nullptr) {}
    };

    template <typename T>

    /*
    A queue goes by the rules of FIFO (first in first out)
    So nodes get added to the back but taken from the front
    works like a how people stand in a line 
    */ 

    class Queue {
        private:
        Node* front, rear;
        size_t count;

        public:
        Queue() : front(nullptr), rear(nullptr) {}

        ~Queue() {
            while (!isEmpty) {
                dequeue();
            }
        }

        // function to add an object to the queue

        void enqueue (T data){
            // create this new Node to throw in queue
            Node<T>* newNode = new Node<T>(data);
            if (isEmpty()) { // basically if its the first node, assgned to front and rear
                rear = front = newNode;
            }
            else{ // if not empty then new node we are queue needs to be the rear
            rear->next = newNode; // links the CURRENT last node to the new Node added
            rear = newNode; // now UPDATES the rear to this newly queued node
            }
            count++;

        }

        // function to take one from the front

        void dequeue () {
            if (isEmpty()) {
                throw std:cerr("Underflow, Empty Queue")
            }
            Node<T>* tmp = front; // create a new tmp to act as a clone
            front = front->next // now move the front
            if (front == nullptr) {
                rear = nullptr;
            }
            delete tmp; // make sure to delete for no memory leaks
            count--; // count decreases when we take the front out
        }

        T peek() {
            if (isEmpty()) {
                throw std:cerr("Underflow, Empty Queue")
            }
            return front->data;
        }

        bool isEmpty () {
            return front == nullptr;
        }

        size_t size () {
            return count;
        }
    };

};

#endif
