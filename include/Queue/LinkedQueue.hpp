#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include <iostream>
using namespace std;
template<typename T>
class LinkedQueue {
    public:
        LinkedQueue()=default;
        LinkedQueue(const LinkedQueue<T>& rhs);
        LinkedQueue<T>& operator=(const LinkedQueue<T>& rhs);
        void enqueue(const T& val); 
        void dequeue();
        T& peek();
        const T& peek() const;
        bool empty() const;
        ~LinkedQueue();
    private:
        struct Node {
            Node* next = nullptr;
            T data;
        };
        Node* first = nullptr;
        Node* last = nullptr;
        int count = 0;
    private:
        void clear();
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