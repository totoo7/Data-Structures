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
        void clear();
        void copy(const LinkedQueue<T>& rhs);
    private:
        struct Node {
            Node* next = nullptr;
            T data;
        };
        Node* first = nullptr;
        Node* last = nullptr;
        int count = 0;
};

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& rhs) {
    try {
        copy(rhs);
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
}

template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs) {
    if (this == &rhs) return *this;
    clear();
    copy(rhs);
    return *this;
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& val) {
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
void LinkedQueue<T>::dequeue() {
    Node* n = first;
    first = first->next;
    delete n;
    if (!first) last = nullptr;
    --count;
}

template<typename T>
T& LinkedQueue<T>::peek() {
    return first->data;
}

template<typename T>
const T& LinkedQueue<T>::peek() const {
    return first->data;
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return count == 0;
}

template<typename T>
void LinkedQueue<T>::clear() {
    while(!empty()) dequeue();
}

template<typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& rhs) {
    Node* iter = rhs.first;
    while (iter) {
        enqueue(iter->data);
        iter = iter->next;
    }
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

#endif