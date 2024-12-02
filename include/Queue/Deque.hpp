#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
using namespace std;

/**
 * @class Deque
 * @brief A class that implements a double-ended queue (Deque).
 * 
 * A deque (double-ended queue) is a linear data structure that allows elements to be added or removed from both ends.
 * This implementation dynamically resizes when the deque reaches capacity, ensuring efficient usage of memory.
 * 
 * @tparam T The type of elements stored in the deque.
 */
template<typename T>
class Deque {
    public:
        /**
         * @brief Default constructor for the Deque class.
         * 
         * Initializes the deque with an initial capacity and allocates memory for storage.
         */
        Deque();
        /**
         * @brief Copy constructor for the Deque class.
         * 
         * @param rhs The deque to copy from.
         */
        Deque(const Deque<T>& rhs);
        /**
         * @brief Assignment operator for the Deque class.
         * 
         * Assigns the contents of one deque to another using the copy-and-swap idiom.
         * @param rhs The deque to assign from.
         * @return A reference to the assigned deque.
         */
        Deque<T>& operator=(const Deque<T>& rhs);
        /**
         * @brief Adds an element to the back of the deque.
         * 
         * If the deque is full, the underlying array is resized before adding the element.
         * @param value The element to add to the back of the deque.
         */
        void push_back(const T& value);
        /**
         * @brief Adds an element to the front of the deque.
         * 
         * If the deque is full, the underlying array is resized before adding the element.
         * @param value The element to add to the front of the deque.
         */
        void push_front(const T& value);
        /**
         * @brief Removes the element at the back of the deque.
         */
        void pop_back();
        /**
         * @brief Removes the element at the front of the deque.
         */
        void pop_front();
        /**
         * @brief Returns the number of elements currently in the deque.
         * 
         * @return The number of elements in the deque.
         */
        size_t size() const;
        /**
         * @brief Checks if the deque is empty.
         * 
         * @return True if the deque is empty, false otherwise.
         */
        bool empty() const;
        /**
         * @brief Returns a reference to the element at the front of the deque.
         * 
         * @return A reference to the element at the front of the deque.
         */
        T& front();
        /**
         * @brief Returns a constant reference to the element at the front of the deque.
         * 
         * @return A constant reference to the element at the front of the deque.
         */
        const T& front() const;
        /**
         * @brief Returns a reference to the element at the back of the deque.
         * 
         * @return A reference to the element at the back of the deque.
         */
        T& back();
        /**
         * @brief Returns a constant reference to the element at the back of the deque.
         * 
         * @return A constant reference to the element at the back of the deque.
         */
        const T& back() const;
        /**
         * @brief Destructor for the Deque class.
         * 
         * Frees the dynamically allocated memory used by the deque.
         */
        ~Deque();
    private:
        /**
         * @brief Resizes the internal array to accommodate more elements.
         * 
         * Doubles the capacity of the deque and moves existing elements to the new array.
         */
        void resize();
    private:
        T* data;
        size_t count = 0;
        size_t capacity = 2;
        size_t head = 0;
        size_t tail = 0;
};

template<typename T>
Deque<T>::Deque() {
    try {
        data = new T[capacity];
    } catch (std::bad_alloc& e) {
        delete[] data;
        throw;
    }
}

template<typename T>
Deque<T>::Deque(const Deque<T>& rhs) {
    try {
        data = new T[rhs.capacity];
        count = rhs.count;
        capacity = rhs.capacity;
        head = rhs.head;
        tail = rhs.tail;
        for (size_t i = 0; i < count; i++) 
            data[(head + i) % capacity] = rhs.data[(rhs.head + i) % rhs.capacity];
    } catch (std::bad_alloc& e) {
        delete[] data;
        throw;
    }
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& rhs) {
    if (this == &rhs) return *this;
    Deque<T> temp = rhs;
    std::swap(data, temp.data);
    std::swap(count, temp.count);
    std::swap(capacity, temp.capacity);
    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    return *this;
}

template<typename T>
void Deque<T>::push_back(const T& value) {
    if (count == capacity) {
        resize();
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
}

template<typename T>
void Deque<T>::push_front(const T& value) {
    if (count == capacity) {
        resize();
    }
    head = (head == 0) ? capacity - 1 : head - 1;
    data[head] = value;
    count++;
}

template<typename T>
void Deque<T>::pop_back() {
    tail = (tail == 0) ? capacity - 1 : tail - 1;
    count--;
}

template<typename T>
void Deque<T>::pop_front() {
    head = (head + 1) % capacity;
    count--;
}

template<typename T>
size_t Deque<T>::size() const {
    return count;
}

template<typename T>
bool Deque<T>::empty() const {
    return count == 0;
}

template<typename T>
T& Deque<T>::front() {
    return data[head];
}

template<typename T>
const T& Deque<T>::front() const {
    return data[head];
}

template<typename T>
T& Deque<T>::back() {
    size_t back_index = (tail == 0) ? capacity - 1 : tail - 1;
    return data[back_index];
}

template<typename T>
const T& Deque<T>::back() const {
    size_t back_index = (tail == 0) ? capacity - 1 : tail - 1;
    return data[back_index];
}

template<typename T>
void Deque<T>::resize() {
    size_t new_capacity = capacity * 2;
    T* temp = new T[new_capacity];
    
    for (size_t i = 0; i < count; i++) {
        temp[i] = data[(head + i) % capacity];
    }
    
    delete[] data;
    data = temp;
    head = 0;
    tail = count;
    capacity = new_capacity;
}

template<typename T>
Deque<T>::~Deque() {
    delete[] data;
}

#endif