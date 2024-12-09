#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <iostream>
using namespace std;

/**
 * @brief A resizing circular queue implementation.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template<typename T>
class CircularQueue {
    public:
        /**
         * @brief Constructs a circular queue with a specified capacity.
         * Starting capacity is 2.
         */
        CircularQueue();
        /**
         * @brief Copy constructor.
         * 
         * @param rhs The queue to copy from.
         */
        CircularQueue(const CircularQueue<T>& rhs);
        /**
         * @brief Copy assignment operator.
         * 
         * @param rhs The queue to assign from.
         * @return A reference to the assigned queue.
         */
        CircularQueue<T>& operator=(const CircularQueue<T>& rhs);
        /**
         * @brief Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool empty() const;
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
         * @brief Destructor that releases the allocated memory.
         */
        ~CircularQueue();
    private:
        T* data = nullptr;
        size_t capacity = 2;
        size_t count = 0;
        size_t last, first = 0;
};

template <typename T>
inline CircularQueue<T>::CircularQueue() : count(0), first(0), last(), capacity(2)  {
    try {
        data = new T[capacity];
    } catch (std::bad_alloc& e) {
        delete[] data;
        throw;
    }
}

template <typename T>
inline CircularQueue<T>::CircularQueue(const CircularQueue<T>& rhs) {
    try {
        data = new T[capacity];
        count = rhs.count;
        capacity = rhs.capacity;
        first = 0;
        last = count;
        for(size_t i = 0; i < count; i++) {
            data[i] = rhs.data[(i + rhs.first) % capacity];
        }
    } catch (std::bad_alloc& e) {
        delete[] data;
        throw;
    }
}

template <typename T>
inline CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue<T>& rhs) {
    if (this == &rhs) return *this;
    CircularQueue<T> temp = rhs;
    std::swap(data, temp.data);

    size_t temp_first = first;
    first = temp.first;
    temp.first = temp_first;

    size_t temp_last = last;
    last = temp.last;
    temp.last = last;
    
    return *this;
}

template <typename T>
bool CircularQueue<T>::empty() const 
{
	return count == 0;
}

template <typename T>
void CircularQueue<T>::enqueue(const T& val) 
{
	if (count == capacity) {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            temp[i] = peek();
            dequeue();
        }

        first = 0;
        last = capacity;
        count = capacity;
        capacity *= 2;
        delete[] data;
        data = temp;
    }
	data[last] = val;
	(++last) %= capacity;
	count++;
}

template <typename T>
void CircularQueue<T>::dequeue() 
{
	count--;
	(++first) %= capacity;
}

template <typename T>
T& CircularQueue<T>::peek()
{
	return data[first];
}

template <typename T>
const T& CircularQueue<T>::peek() const
{
	return data[first];
}

template <typename T>
CircularQueue<T>::~CircularQueue() 
{
	delete[] data;
}

#endif