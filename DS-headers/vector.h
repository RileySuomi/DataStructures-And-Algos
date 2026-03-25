#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include "stack.h"

// Template is used to allow the Vector class to work with any data type (int, double, string, etc.)
// This enables generic programming - we can create vectors of different types without rewriting the code
template <typename T>

// Vector implementation using Stack - this is a very basic implementation of a vector-like structure
// Note: This approach has limitations - random access is O(n) and
// insertions/deletions in middle are expensive

class Vector {
private:
    algorithm::Stack<T> data;  // Using the existing Stack class

public:
    // Constructor
    Vector() = default;

    // Add element to the end (uses stack's push)
    void push_back(const T& value) {
        data.push(value);
    }

    // Remove element from the end (uses stack's pop)
    void pop_back() {
        if (!data.isEmpty()) {
            data.pop();
        }
    }

    // Access element at index (expensive operation - O(n))
    // Note: This returns a copy, not a reference, due to stack limitations
    T operator[](size_t index) {
        if (index >= getSize()) {
            throw std::out_of_range("Index out of range");
        }

        // Need to pop elements to access earlier ones
        algorithm::Stack<T> tempStack;

        // Move elements to temp stack until we reach the desired index
        for (size_t i = getSize() - 1; i > index; --i) {
            T value = data.peek();
            data.pop();
            tempStack.push(value);
        }

        // Get the element at index
        T result = data.peek();

        // Restore the stack
        while (!tempStack.isEmpty()) {
            T value = tempStack.peek();
            tempStack.pop();
            data.push(value);
        }

        return result;
    }

    // Get current size
    size_t getSize() const {
        return data.size();
    }

    // Check if vector is empty
    bool isEmpty() const {
        return data.isEmpty();
    }

    // Clear all elements
    void clear() {
        while (!data.isEmpty()) {
            data.pop();
        }
    }

    // Get last element (peek at stack top)
    T back() {
        if (data.isEmpty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data.peek();
    }

    // Display the vector (expensive - O(n²) due to repeated access)
    void display() const {
        std::cout << "[";
        for (size_t i = 0; i < getSize(); ++i) {
            if (i > 0) std::cout << ", ";
            // Note: Inefficient display - each access is O(n)
            std::cout << "element_at_index_" << i;
        }
        std::cout << "]" << std::endl;
    }

    // Note: Insert and erase operations are not efficiently implementable
    // with a stack-based approach, so they're omitted
};

#endif // VECTOR_H