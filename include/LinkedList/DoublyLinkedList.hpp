#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node sentinel;
    size_t count = 0;
public:
    struct Iterator {
    private:
        Node* current = nullptr;
    public:
        friend class DoublyLinkedList;
        Iterator(Node* n);
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator!=(const Iterator& rhs) const;
        bool operator==(const Iterator& rhs) const;
        T& operator*();
        const T& operator*() const;
        T* operator->();
        const T* operator->() const;
    };
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& rhs);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
    void push_back(const T& val);
    void push_front(const T& val);
    Iterator insert(Iterator where, const T& value);
    void pop_back();
    void pop_front();
    Iterator remove(Iterator where);
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    size_t size() const;
    bool empty() const;
    Iterator begin();
    Iterator end();
    void splice();
    void merge();  
    ~DoublyLinkedList();
private:
    void insertBefore(Node* where, Node* n);
    Node* remove(Node* n);
};

template<typename T>
inline DoublyLinkedList<T>::Iterator::Iterator(Node* n) : current(n) {}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
    Iterator temp(*this);
    current = current->next;
    return temp;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
    current = current->prev;
    return *this;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
    Iterator temp(*this);
    current = current->prev;
    return temp;
}

template<typename T>
inline bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
    return !(*this == rhs);
}

template<typename T>
inline bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
    return current == rhs.current;
}

template<typename T>
inline T& DoublyLinkedList<T>::Iterator::operator*() {
    return current->data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::Iterator::operator*() const {
    return current->data;
}

template<typename T>
inline T* DoublyLinkedList<T>::Iterator::operator->() {
    return &current->data;
}

template<typename T>
inline const T* DoublyLinkedList<T>::Iterator::operator->() const {
    return &current->data;
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() {
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) {
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;

    try {
        for (Node* curr = rhs.sentinel.next; curr != &rhs.sentinel; curr = curr->next) {
            push_back(curr->data);
        }
    } catch (...) {
        while (!empty()) pop_back();
        throw;
    }
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
    if (this == &rhs) return *this;
    DoublyLinkedList<T> temp(rhs);

    std::swap(sentinel.next, temp.sentinel.next);
    std::swap(sentinel.prev, temp.sentinel.prev);

    if (sentinel.next != &sentinel) sentinel.next->prev = &sentinel;
    if (sentinel.prev != &sentinel) sentinel.prev->next = &sentinel;

    if (temp.sentinel.next != &temp.sentinel) temp.sentinel.next->prev = &temp.sentinel;
    if (temp.sentinel.prev != &temp.sentinel) temp.sentinel.prev->next = &temp.sentinel;

    std::swap(count, temp.count);

    return *this;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T& val) {
    Node* n = new Node{val};
    insertBefore(&sentinel, n);
    ++count;
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(const T& val) {
    Node* n = new Node{val};
    insertBefore(sentinel.next, n);
    ++count;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::insert(Iterator where, const T& value) {
    Node* n = new Node{value};
    insertBefore(where.current, n);
    ++count;
    return Iterator(n);
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back() {
    Node* n = remove(sentinel.prev);
    --count;
    delete n;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front() {
    Node* n = remove(sentinel.next);
    --count;
    delete n;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::remove(Iterator where) {
    Node* n = remove(where.current);
    Iterator result(n->next);
    --count;
    delete n;
    return result;
}

template<typename T>
inline T& DoublyLinkedList<T>::front() {
    return sentinel.next->data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::front() const {
    return sentinel.next->data;
}

template<typename T>
inline T& DoublyLinkedList<T>::back() {
    return sentinel.prev->data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::back() const {
    return sentinel.prev->data;
}

template<typename T>
inline size_t DoublyLinkedList<T>::size() const {
    return count;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const {
    return count == 0;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
    return Iterator(sentinel.next);
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
    return Iterator(&sentinel);
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!empty()) pop_back();
}

template<typename T>
inline void DoublyLinkedList<T>::insertBefore(Node* where, Node* n) {
    n->prev = where->prev;
    n->next = where;
    n->prev->next = n;
    n->next->prev = n;
}

template<typename T>
inline typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::remove(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    return n;
}

#endif