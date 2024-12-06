/**
 * @file DoublyLinkedList.hpp
 * @brief A generic doubly linked list implementation with an iterator.
 * @tparam T Type of the elements stored in the list.
 */

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Implements a doubly linked list with support for iteration, insertion, removal, and traversal.
 * 
 * @tparam T Type of the elements stored in the list.
 */
template<typename T>
class DoublyLinkedList {
private:
    /**
     * @struct Node
     * @brief Represents a node in the doubly linked list.
     */
    struct Node {
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node sentinel;
    size_t count = 0;
public:
    /**
     * @struct Iterator
     * @brief A bidirectional iterator for the DoublyLinkedList.
     */
    struct Iterator {
    private:
        Node* current = nullptr;
    public:
        friend class DoublyLinkedList;
        /**
         * @brief Constructs an iterator pointing to a given node.
         * @param n Pointer to the node.
         */
        Iterator(Node* n);
        /**
         * @brief Advances the iterator to the next node (prefix).
         * @return Reference to the updated iterator.
         */
        Iterator& operator++();
        /**
         * @brief Advances the iterator to the next node (postfix).
         * @return Copy of the iterator before advancing.
         */
        Iterator operator++(int);
        /**
         * @brief Moves the iterator to the previous node (prefix).
         * @return Reference to the updated iterator.
         */
        Iterator& operator--();
        /**
         * @brief Moves the iterator to the previous node (postfix).
         * @return Copy of the iterator before moving.
         */
        Iterator operator--(int);
        /**
         * @brief Checks if two iterators are not equal.
         * @param rhs Iterator to compare against.
         * @return True if iterators are not equal, false otherwise.
         */
        bool operator!=(const Iterator& rhs) const;
        /**
         * @brief Checks if two iterators are equal.
         * @param rhs Iterator to compare against.
         * @return True if iterators are equal, false otherwise.
         */
        bool operator==(const Iterator& rhs) const;
        /**
         * @brief Dereferences the iterator to access the data.
         * @return Reference to the data in the current node.
         */
        T& operator*();
        /**
         * @brief Dereferences the iterator to access the data (const).
         * @return Const reference to the data in the current node.
         */
        const T& operator*() const;
        /**
         * @brief Accesses the data in the current node through a pointer.
         * @return Pointer to the data.
         */
        T* operator->();
        /**
         * @brief Accesses the data in the current node through a pointer (const).
         * @return Const pointer to the data.
         */
        const T* operator->() const;
    };
public:
    /**
     * @brief Constructs an empty doubly linked list.
     */ 
    DoublyLinkedList();
    /**
     * @brief Constructs a copy of another doubly linked list.
     * @param rhs Reference to the list to copy.
     */
    DoublyLinkedList(const DoublyLinkedList<T>& rhs);
    /**
     * @brief Assigns the contents of another list to this list.
     * @param rhs Reference to the list to copy.
     * @return Reference to this list.
     */
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
    /**
     * @brief Adds an element to the end of the list.
     * @param val Value to add.
     */
    void push_back(const T& val);
    /**
     * @brief Adds an element to the front of the list.
     * @param val Value to add.
     */
    void push_front(const T& val);
    /**
     * @brief Inserts a value at a specific position in the list.
     * @param where Iterator pointing to the insertion position.
     * @param value Value to insert.
     * @return Iterator to the newly inserted element.
     */
    Iterator insert(Iterator where, const T& value);
    /**
     * @brief Removes the last element of the list.
     */
    void pop_back();
    /**
     * @brief Removes the first element of the list.
     */
    void pop_front();
    /**
     * @brief Removes an element at a specific position.
     * @param where Iterator pointing to the element to remove.
     * @return Iterator to the next element after the removed one.
     */
    Iterator remove(Iterator where);
    /**
     * @brief Accesses the first element of the list.
     * @return Reference to the first element.
     */
    T& front();
    /**
     * @brief Accesses the first element of the list (const).
     * @return Const reference to the first element.
     */
    const T& front() const;
    /**
     * @brief Accesses the last element of the list.
     * @return Reference to the last element.
     */
    T& back();
    /**
     * @brief Accesses the last element of the list (const).
     * @return Const reference to the last element.
     */
    const T& back() const;
    /**
     * @brief Gets the number of elements in the list.
     * @return Size of the list.
     */
    size_t size() const;
    /**
     * @brief Checks if the list is empty.
     * @return True if the list is empty, false otherwise.
     */
    bool empty() const;
    /**
     * @brief Returns an iterator to the beginning of the list.
     * @return Iterator to the first element.
     */    
    Iterator begin();
    /**
     * @brief Returns an iterator to the end of the list.
     * @return Iterator to the sentinel node.
     */
    Iterator end();
    /**
     * @brief Destructor. Cleans up all allocated memory.
     */
    ~DoublyLinkedList();
private:
    /**
     * @brief Inserts a node before a given position.
     * @param where Node before which the new node will be inserted.
     * @param n Node to insert.
     */
    void insertBefore(Node* where, Node* n);
    /**
     * @brief Removes a node from the list.
     * @param n Node to remove.
     * @return Pointer to the removed node.
     */
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
    DoublyLinkedList<T> temp = rhs;
    while (!empty()) pop_back();
    for (Node* curr = temp.sentinel.next; curr != &temp.sentinel; curr = curr->next) {
            push_back(curr->data);
    }
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