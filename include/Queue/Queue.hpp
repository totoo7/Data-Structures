#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief A simple implementation of a queue using a dynamic array (std::vector).
 * 
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class Queue {
    public:
        /**
         * @brief Returns the number of elements in the queue.
         * 
         * @return The size of the queue.
         */
        int size() const { return data.size(); }
        /**
         * @brief Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool is_empty() const { return data.empty(); }
        /**
         * @brief Removes the front element from the queue.
         */
        void dequeue() { data.erase(data.begin()); }
        /**
         * @brief Adds an element to the back of the queue.
         * 
         * @param val The value to enqueue.
         */
        void enqueue(const T& val) { data.push_back(val); }
        /**
         * @brief Provides access to the front element of the queue (const version).
         * 
         * @return A const reference to the front element.
         */
        const T& peek() const { return data.front(); }
        /**
         * @brief Provides access to the front element of the queue.
         * 
         * @return A reference to the front element.
         * @throws std::underflow_error If the queue is empty.
         */
        T& peek() { return data.front(); }
    private:
        vector<T> data;
};

#endif