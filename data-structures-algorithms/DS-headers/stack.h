
#ifndef stack_h
#define stack_h

#include <iostream>
#include <stdexcept>

namespace algorithm {


    template<typename T> // template (for the node) allows for generic programming

    // since using link list need to set up node format

    struct Node {
        T data; // data help in node
        Node* next; // ptr to next node .. will help make easier to add and delete things in stack 
    };
    
    template<typename T> // template (for the stack) allows for generic programming

    class Stack {
    private:
        size_t count; // the current size of stack
        Node<t>* top; // ptr to top
    public:
        Stack() : count(0) {} 
       
        ~Stack() { 
            while (top != nullptr) // while the top isnt "nothing"
            {
                pop(); // pop (remove top)
            }
            
        }

        // simple function to check if the stack is empty or not

        bool isEmpty () const{
            return count == 0;
        }

        // push function in a stack, adds an element to the stack (adds to the top)

        void push (const T& data) {
            Node<T>* newnode = new Node<T>(data); // create a ptr of new object puttin on stack
            Node->next = top; // need to set current tops data to next
            top = newnode // now new top is the newnode
            count++; // size of stack increased
        }

        // pop function in a stack, removes the top element from the stack

        void pop() {

            if (top == nullptr) { // if nothing on top, stack is empty
                throw std:cerr << "underflow error, stack is empty" << std:endl;
                return;
            }
            Node<T>* temp = top;  // need to create a temp holder to track tops data
            top = top->next; // the new top of stack is going to be the next node
            delete temp; // delete temp node (old top)
            count--; // size of stack decreases
        }

        // peek function in a stack, retrieves the data thats in the top element of stack 

        void peek() {
            if (top == nullptr) {
                throw std:cerr << "underflow error, stack is empty" << std:endl;
            }
            return top->data; // using the top node of the stack, "peek" at the data
        }

        // simple function that returns the size of the stack 

        size_t size() const {
            return count;
        }

    };
    

    

}

#endif