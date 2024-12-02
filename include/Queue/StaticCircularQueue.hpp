#ifndef STATIC_CIRCULAR_QUEUE_HPP
#define STATIC_CIRCULAR_QUEUE_HPP

#include <iostream>
using namespace std;

/**
 * @brief A static circular queue implementation using a fixed-size array.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template<class T>
class StaticCircularQueue {
    public:
        /**
         * @brief Constructs a circular queue with a specified capacity.
         * 
         * @param size The maximum number of elements the queue can hold (default: 16).
         */
        StaticCircularQueue(size_t size = 16);
        /**
         * @brief Copy constructor.
         * 
         * @param rhs The queue to copy from.
         */
        StaticCircularQueue(const StaticCircularQueue<T>& rhs);
        /**
         * @brief Copy assignment operator.
         * 
         * @param rhs The queue to assign from.
         * @return A reference to the assigned queue.
         */
        StaticCircularQueue& operator=(const StaticCircularQueue<T>& rhs);
        /**
         * @brief Adds an element to the back of the queue.
         * 
         * @param val The value to enqueue.
         */
        void enqueue(const T& val);
        /**
         * @brief Removes the front element from the queue.
         */
        void dequeue();
        /**
         * @brief Provides access to the front element of the queue.
         * 
         * @return A reference to the front element.
         */
        T& peek();
        /**
         * @brief Provides access to the front element of the queue (const version).
         * 
         * @return A const reference to the front element.
         */
        const T& peek() const;
        /**
         * @brief Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool is_empty() const;
        /**
         * @brief Checks if the queue is full.
         * 
         * @return True if the queue is full, false otherwise.
         */
        bool is_full() const;
        /**
         * @brief Destructor that releases the allocated memory.
         */
        ~StaticCircularQueue();
    private:    
        /**
         * @brief Swaps two pointers.
         * 
         * @param a Pointer to the first element.
         * @param b Pointer to the second element.
         */
        void swap(T*& a, T*& b);
    private:
        T* data = nullptr;
        size_t first, last = 0;
        const size_t size;
};

template<typename T>
inline StaticCircularQueue<T>::StaticCircularQueue(size_t size) : size(size+1) {
    try {
        data = new T[size+1];
        first = 0;
        last = 0;
    } catch (std::bad_alloc &e) {
        delete[] data;
        throw;
    }
}

template<typename T>
inline StaticCircularQueue<T>::StaticCircularQueue(const StaticCircularQueue<T>& rhs) : size(rhs.size) {
    try {
        data = new T[rhs.size];
        first = last = 0;
        for (size_t pos = rhs.first; pos != rhs.last; pos = (pos+1) % size)
            enqueue(rhs.data[pos]);
    } catch (std::bad_alloc &e) {
        delete[] data;
        throw;
    }
}

template<typename T>
inline StaticCircularQueue<T>& StaticCircularQueue<T>::operator=(const StaticCircularQueue<T>& rhs) {
    if (this == &rhs) return *this;

    StaticCircularQueue<T> temp = rhs;
    swap(data, temp.data);

    size_t temp_first = first;
    first = temp.first;
    temp.first = temp_first;

    size_t temp_last = last;
    last = temp.last;
    temp.last = last;

    return *this;
}

template<typename T>
inline void StaticCircularQueue<T>::enqueue(const T& val) {
    data[last] = val;
    last = (last+1) % size;
}

template<typename T>
inline void StaticCircularQueue<T>::dequeue() {
    first = (first+1) % size;
}

template<typename T>
inline T& StaticCircularQueue<T>::peek() {
    return data[first];
}

template<typename T>
inline const T& StaticCircularQueue<T>::peek() const {
    return data[first];
}

template<typename T>
inline bool StaticCircularQueue<T>::is_empty() const {
    return first == last;
}

template<typename T>
inline bool StaticCircularQueue<T>::is_full() const {
    return (last+1) % size == first;
}

template<typename T>
inline void StaticCircularQueue<T>::swap(T*& a, T*& b) {
    T* temp = a;
    a = b;
    b = temp;
}

template<typename T>
inline StaticCircularQueue<T>::~StaticCircularQueue() { 
    delete[] data; 
}

#endif