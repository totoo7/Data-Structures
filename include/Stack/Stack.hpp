#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief A stack implementation using a `std::vector` as the underlying container.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack {
    public:
        /**
         * @brief Returns the number of elements in the stack.
         * 
         * @return The size of the stack.
         */
        int size() const { return data.size(); }
        /**
         * @brief Checks if the stack is empty.
         * 
         * @return True if the stack is empty, false otherwise.
         */
        bool is_empty() const { return data.empty(); }
        /**
         * @brief Removes the top element from the stack.
         */
        void pop_back() { data.pop_back(); }
        /**
         * @brief Adds an element to the top of the stack.
         * 
         * @param val The value to push onto the stack.
         */
        void push_back(const T& val) { data.push_back(val); }
        /**
         * @brief Provides access to the top element of the stack (const version).
         * 
         * @return A const reference to the top element.
         */
        const T& peek() const { return data.back(); }
        /**
         * @brief Provides access to the top element of the stack.
         * 
         * @return A reference to the top element.
         */
        T& peek() { return data.back(); }
    private:
        vector<T> data;
};

#endif