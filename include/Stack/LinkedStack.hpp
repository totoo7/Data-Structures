#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <iostream>
using namespace std;

/**
 * @brief A generic implementation of a linked stack data structure.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class LinkedStack {
    public:
        /**
         * @brief Default constructor.
         */
        LinkedStack() = default;
        /**
         * @brief Copy constructor.
         * 
         * @param rhs The stack to copy from.
         */
        LinkedStack(const LinkedStack<T>& rhs);
        /**
         * @brief Copy assignment operator.
         * 
         * @param rhs The stack to assign from.
         * @return A reference to the assigned stack.
         */
        LinkedStack<T>& operator=(const LinkedStack<T>& rhs);
        /**
         * @brief Returns the number of elements in the stack.
         * 
         * @return The size of the stack.
         */
        int size() const;
        /**
         * @brief Checks if the stack is empty.
         * 
         * @return True if the stack is empty, false otherwise.
         */
        bool is_empty() const;
        /**
         * @brief Provides access to the top element of the stack.
         * 
         * @return A reference to the top element.
         */
        T& peek();
        /**
         * @brief Provides access to the top element of the stack (const version).
         * 
         * @return A const reference to the top element.
         */
        const T& peek() const;
        /**
         * @brief Pushes an element onto the stack.
         * 
         * @param val The value to push onto the stack.
         */
        void push_back(const T& val);
        /**
         * @brief Removes the top element from the stack.
         * 
         */
        void pop_back();
        /**
         * @brief Destructor that clears the stack and releases memory.
         */
        ~LinkedStack();
    private:
        /**
         * @brief Clears the stack, releasing all allocated memory.
         */
        void clear();
        /**
         * @brief Copies the elements from another stack.
         * 
         * @param rhs The stack to copy from.
         */
        void copy(const LinkedStack<T>& rhs);
    private:
        /**
         * @brief A structure representing a node in the linked stack.
         */
        struct Node {
            T data;
            Node* next = nullptr;
        };
        Node* top = nullptr;
        int count = 0;
};

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& rhs) {
    try {
        copy(rhs);
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs) {
    if (this == &rhs) return *this;
    clear();
    copy(rhs);
    return *this;
}

template<typename T>
inline int LinkedStack<T>::size() const { return count; }


template<typename T>
inline bool LinkedStack<T>::is_empty() const { return size() == 0; }

template<typename T>
inline T& LinkedStack<T>::peek() { return top->data; }

template<typename T>
inline const T& LinkedStack<T>::peek() const { return top->data; }

template<typename T>
inline void LinkedStack<T>::push_back(const T& val) {
    Node* n = new Node();
    n->data = val;
    n->next = top;
    top = n;
    ++count;
}

template<typename T>
inline void LinkedStack<T>::pop_back() {
    Node* n = top;
    top = top->next;
    delete n;
    --count;
}

template<typename T>
inline void LinkedStack<T>::clear() {
    while (!is_empty()) {
        pop_back();
    }
}

template<typename T>
inline void LinkedStack<T>::copy(const LinkedStack<T> &rhs) {
    if (!rhs.top) return;

    top = new Node {rhs.top->data, nullptr};
    Node* prev = top;
    Node* rhsCurrent = rhs.top->next;
    while (rhsCurrent) {
        prev->next = new Node {rhsCurrent->data, nullptr};
        prev = prev->next;
        rhsCurrent = rhsCurrent->next;
    }
    count = rhs.size();
}

template <typename T>
inline LinkedStack<T>::~LinkedStack() {
    clear();
}

#endif