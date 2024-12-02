#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP

#include <iostream>
using namespace std;

/**
 * @brief A static stack implementation with a fixed size.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template<class T>
class StaticStack {
    public:
        /**
         * @brief Constructs a stack with the specified size.
         * 
         * @param size The size of the stack (default is 16).
         */
        StaticStack(size_t size = 16);
        /**
         * @brief Copy constructor for the stack.
         * 
         * @param rhs The stack to copy from.
         */
        StaticStack(const StaticStack<T>& rhs);
        /**
         * @brief Assignment operator for the stack.
         * 
         * @param rhs The stack to assign.
         * @return A reference to the current stack.
         */
        StaticStack& operator=(const StaticStack<T>& rhs);
        /**
         * @brief Pushes an element onto the stack.
         * 
         * @param val The value to push onto the stack.
         */
        void push_back(const T& val);
        /**
         * @brief Pops the top element from the stack.
         */
        void pop_back();
        /**
         * @brief Returns a reference to the top element of the stack.
         * 
         * @return A reference to the top element.
         */
        T& peek();
        /**
         * @brief Returns a const reference to the top element of the stack.
         * 
         * @return A const reference to the top element.
         */
        const T& peek() const;
        /**
         * @brief Checks if the stack is empty.
         * 
         * @return True if the stack is empty, false otherwise.
         */
        bool is_empty() const;
        /**
         * @brief Checks if the stack is full.
         * 
         * @return True if the stack is full, false otherwise.
         */
        bool is_full() const;
        /**
         * @brief Destructor for the stack, releases the allocated memory.
         */
        ~StaticStack();
    private:
        T* data = nullptr;
        size_t top = 0;
        const size_t size;
};

template<typename T>
inline StaticStack<T>::StaticStack(size_t size) : data(new T[size]), size(size) {}

template<typename T>
inline StaticStack<T>::StaticStack(const StaticStack<T>& rhs) : data(new T[rhs.size]), size(rhs.size) {
    while (top < rhs.top) push_back(rhs.data[top]);
}

template<typename T>
inline StaticStack<T>& StaticStack<T>::operator=(const StaticStack<T>& rhs) {
    if (this == &rhs) return *this;
    top = 0;
    while (top < rhs.top) push_back(rhs.data[top]);
    return *this;
}

template<typename T>
inline void StaticStack<T>::push_back(const T& val) {
    data[top++] = val;
}

template<typename T>
inline void StaticStack<T>::pop_back() {
    top--;
}

template<typename T>
inline T& StaticStack<T>::peek() {
    return data[top-1];
}

template<typename T>
inline const T& StaticStack<T>::peek() const {
    return data[top-1];
}

template<typename T>
inline bool StaticStack<T>::is_empty() const {
    return top == 0;
}

template<typename T>
inline bool StaticStack<T>::is_full() const {
    return top == size;
}

template<typename T>
inline StaticStack<T>::~StaticStack() { delete[] data; }

#endif