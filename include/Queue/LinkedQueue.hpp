#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include <iostream>
using namespace std;
template<typename T>

/**
 * @brief A generic implementation of a linked queue data structure.
 * 
 * @tparam T The type of elements stored in the queue.
 */
class LinkedQueue {
    public:
        /**
         * @brief Default constructor. Creates an empty queue.
         */
        LinkedQueue()=default;
        /**
         * @brief Copy constructor. Creates a deep copy of another queue.
         * 
         * @param rhs The queue to copy from.
         */
        LinkedQueue(const LinkedQueue<T>& rhs);
        /**
         * @brief Copy assignment operator. Assigns the contents of another queue to this one.
         * 
         * @param rhs The queue to copy from.
         * @return A reference to the updated queue.
         */
        LinkedQueue<T>& operator=(const LinkedQueue<T>& rhs);
        /**
         * @brief Adds an element to the end of the queue.
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
        bool empty() const;
        /**
         * @brief Destructor. Frees all dynamically allocated nodes.
         */
        ~LinkedQueue();
    private:
        /**
         * @brief Represents a single node in the queue.
         */
        struct Node {
            Node* next = nullptr;
            T data;
        };
        Node* first = nullptr;
        Node* last = nullptr;
        int count = 0;
    private:
        /**
         * @brief Removes all elements from the queue.
         */
        void clear();
        /**
         * @brief Swaps the contents of two node pointers.
         * 
         * @param a A reference to the first node pointer.
         * @param b A reference to the second node pointer.
         */
        void swap(Node*& first, Node*& last);
        
};

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& rhs) {
    try {
        Node* iter = rhs.first;
        while (iter) {
            enqueue(iter->data);
            iter = iter->next;
        }
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
}

template<typename T>
inline LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs) {
    if (this == &rhs) return *this;
    LinkedQueue<T> temp = rhs;
    swap(first, temp.first);
    swap(last, temp.last);

    int tempCount = count;
    count = temp.count;
    temp.count = tempCount;
    
    return *this;
}

template<typename T>
inline void LinkedQueue<T>::enqueue(const T& val) {
    Node* n = new Node {nullptr, val};
    if (!last) {
        first = last = n;
    } else {
        last->next = n;
        last = n;
    }
    ++count;
}

template<typename T>
inline void LinkedQueue<T>::dequeue() {
    Node* n = first;
    first = first->next;
    delete n;
    if (!first) last = nullptr;
    --count;
}

template<typename T>
inline T& LinkedQueue<T>::peek() {
    return first->data;
}

template<typename T>
inline const T& LinkedQueue<T>::peek() const {
    return first->data;
}

template<typename T>
inline bool LinkedQueue<T>::empty() const {
    return count == 0;
}

template<typename T>
inline void LinkedQueue<T>::clear() {
    while(!empty()) dequeue();
}

template<typename T>
inline void LinkedQueue<T>::swap(Node*& first, Node*& last) {
    Node* temp = first;
    first = last;
    last = temp;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue() {
    clear();
}

#endif