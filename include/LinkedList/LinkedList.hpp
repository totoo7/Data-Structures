/**
 * @file LinkedList.hpp
 * @brief Templated singly linked list implementation with iterators.
 * 
 * This header file defines a generic `LinkedList` class that provides
 * functionality for creating and managing a singly linked list. It includes
 * support for forward iteration, element access, and various list operations.
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

/**
 * @class LinkedList
 * @brief A templated singly linked list class.
 * 
 * This class provides methods for managing a list of elements, supporting
 * basic operations such as insertion, deletion, and traversal.
 * 
 * @tparam T Type of the elements stored in the list.
 */
template<typename T>
class LinkedList {
    private:
        /**
         * @struct Node
         * @brief Represents a single node in the linked list.
         * 
         * Each node stores a value and a pointer to the next node.
         */    
        struct Node {
            Node* next = nullptr;
            T data;
            /**
             * @brief Constructs a Node with data and a pointer to the next node.
             * 
             * @param next_val Pointer to the next node.
             * @param data_val Data value to store in the node.
             */
            Node(Node* next_val, T data_val) : next(next_val), data(data_val) {}
        };
    public:
        /**
         * @class Iterator
         * @brief Iterator for traversing the linked list.
         */
        class Iterator {
            public:
                /**
                 * @brief Dereferences the iterator to access the element.
                 * @return Reference to the element.
                 */
                T& operator*();                
                /**
                 * @brief Dereferences the iterator to access the element (const version).
                 * @return Const reference to the element.
                 */
                const T& operator*() const;
                /**
                 * @brief Accesses the element via pointer.
                 * @return Pointer to the element.
                 */
                T* operator->();
                /**
                 * @brief Accesses the element via pointer (const version).
                 * @return Const pointer to the element.
                 */
                const T* operator->() const;
                /**
                 * @brief Pre-increment operator to move to the next element.
                 * @return Reference to the updated iterator.
                 */
                Iterator& operator++();
                /**
                 * @brief Post-increment operator to move to the next element.
                 * @return Copy of the iterator before incrementing.
                 */
                Iterator operator++(int);
                /**
                 * @brief Compares two iterators for inequality.
                 * @param rhs Iterator to compare with.
                 * @return `true` if the iterators are not equal, `false` otherwise.
                 */
                bool operator!=(const Iterator& rhs) const;
                /**
                 * @brief Compares two iterators for equality.
                 * @param rhs Iterator to compare with.
                 * @return `true` if the iterators are equal, `false` otherwise.
                 */
                bool operator==(const Iterator& rhs) const;
            private:
                friend class LinkedList<T>;
                /**
                 * @brief Constructs an iterator pointing to a specific node.
                 * @param node Pointer to the node.
                 */
                Iterator(LinkedList<T>::Node* node);
            private:
                LinkedList<T>::Node* pointer;
        };
    public:
        /**
         * @brief Default constructor.
         * Initializes an empty linked list.
         */
        LinkedList()=default;
        /**
         * @brief Copy constructor.
         * Copies the content of another linked list.
         * @param rhs LinkedList to copy.
         */
        LinkedList(const LinkedList<T>& rhs);
        /**
         * @brief Assignment operator.
         * Replaces the content with another linked list's content.
         * @param rhs LinkedList to copy.
         * @return Reference to the updated linked list.
         */
        LinkedList<T>& operator=(const LinkedList<T>& rhs);
        /**
         * @brief Accesses the first element.
         * @return Reference to the first element.
         */
        T& front();
        /**
         * @brief Accesses the first element (const version).
         * @return Const reference to the first element.
         */
        const T& front() const;
        /**
         * @brief Accesses the last element.
         * @return Reference to the last element.
         */
        T& back();
        /**
         * @brief Accesses the last element (const version).
         * @return Const reference to the last element.
         */
        const T& back() const;
        /**
         * @brief Accesses an element at a specific index.
         * @param index Index of the element.
         * @return Reference to the element.
         */
        T& at(size_t index);
        /**
         * @brief Accesses an element at a specific index (const version).
         * @param index Index of the element.
         * @return Const reference to the element.
         */
        const T& at(size_t index) const;
        /**
         * @brief Checks if the linked list is empty.
         * @return `true` if the list is empty, `false` otherwise.
         */
        bool is_empty() const;
        /**
         * @brief Returns the number of elements in the linked list.
         * @return Size of the linked list.
         */
        size_t size() const;
        /**
         * @brief Inserts an element at the front of the list.
         * @param val Element to insert.
         */
        void push_front(const T& val);
        /**
         * @brief Inserts an element at the end of the list.
         * @param val Element to insert.
         */
        void push_end(const T& val);
        /**
         * @brief Inserts an element at a specific index.
         * @param index Index to insert the element at.
         * @param val Element to insert.
         */
        void push_at(size_t index, const T& val);
        /**
         * @brief Inserts an element after a specific iterator.
         * @param iter Iterator pointing to the position after which to insert.
         * @param val Element to insert.
         */
        void push_after(Iterator iter, const T& val);
        /**
         * @brief Removes the first element from the list.
         */
        void pop_front();
        /**
         * @brief Removes the last element from the list.
         */
        void pop_end();
        /**
         * @brief Removes an element at a specific index.
         * @param index Index of the element to remove.
         */
        void pop_at(size_t index);
        /**
         * @brief Removes an element after a specific iterator.
         * @param iter Iterator pointing to the position after which to remove.
         */
        void pop_after(Iterator iter);
        /**
         * @brief Returns an iterator to the first element.
         * @return Iterator to the first element.
         */
        Iterator begin();
        /**
         * @brief Returns an iterator to the end (past-the-last element).
         * @return Iterator to the end.
         */
        Iterator end();
        /**
         * @brief Returns a const iterator to the first element.
         * @return Const iterator to the first element.
         */
        const Iterator c_begin() const;
        /**
         * @brief Returns a const iterator to the end (past-the-last element).
         * @return Const iterator to the end.
         */
        const Iterator c_end() const;
        void append(const LinkedList<T>& rhs);
        void reverse();
        void sort();
        bool is_sorted() const;
        /**
         * @brief Destructor. Cleans up all resources used by the linked list.
         */
        ~LinkedList();
    private: 
        Node* head = nullptr;
        Node* tail = nullptr;
        size_t count = 0;
    private: 
        // Utility functions
        void swap(Node*& a, Node*& b);
        void clear();
};

template<typename T>
inline LinkedList<T>::Iterator::Iterator(LinkedList<T>::Node* node) : pointer(node) {}

template<typename T>
inline T& LinkedList<T>::Iterator::operator*() {
    return pointer->data;
}

template<typename T>
inline const T& LinkedList<T>::Iterator::operator*() const {
    return pointer->data;
}

template<typename T>
inline T* LinkedList<T>::Iterator::operator->() {
    return &pointer->data;
}

template<typename T>
inline const T* LinkedList<T>::Iterator::operator->() const {
    return &pointer->data;
}

template<typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    pointer = pointer->next;
    return *this;
}

template<typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Iterator temp(*this);
    ++(*this);
    return temp;
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
    return !(*this == rhs);
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
    return pointer == rhs.pointer;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& rhs) {
    try {
        Node* iter = rhs.head;
        while (iter) {
            push_end(iter->data);
            iter = iter->next;
        }
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    if (this == &rhs) return *this;

    LinkedList<T> temp = rhs;

    swap(head, temp.head);
    swap(tail, temp.tail);

    int tempCount = count;
    count = temp.count;
    temp.count = tempCount;

    return *this;
}

template<typename T>
inline T& LinkedList<T>::front() {
    return at(0);
}

template<typename T>
inline const T& LinkedList<T>::front() const {
    return at(0);
}

template<typename T>
inline T& LinkedList<T>::back() {
    return at(size()-1);
}

template<typename T>
inline const T& LinkedList<T>::back() const {
    return at(size()-1);
}

template<typename T>
inline T& LinkedList<T>::at(size_t index) {
    if (index == size() - 1) return tail->data;

    Node* iter = head;
    for (size_t i = 0; i < index; i++, iter = iter->next);
    return iter->data; 
}

template<typename T>
inline const T& LinkedList<T>::at(size_t index) const {
    if (index == size() - 1) return tail->data;

    Node* iter = head;
    for (size_t i = 0; i < index; i++, iter = iter->next);
    return iter->data; 
}

template<typename T>
inline bool LinkedList<T>::is_empty() const {
    return count == 0;
}

template<typename T>
inline size_t LinkedList<T>::size() const {
    return count;
}

template<typename T>
inline void LinkedList<T>::push_front(const T& val) {
    push_at(0, val);
}

template<typename T>
inline void LinkedList<T>::push_end(const T& val) {
    push_at(size(), val);
}

template<typename T>
inline void LinkedList<T>::push_at(size_t index, const T& val) {
    if (index == 0) {
        head = new Node (head, val);
        if (is_empty()) tail = head;
    } else if (index == size()) {
        tail->next = new Node (nullptr, val);
        tail = tail->next;
    } else {
        Node* iter = head;
        for (size_t i = 0; i < index - 1; ++i, iter = iter->next);
        iter->next = new Node (iter->next, val);
    }
    ++count;
}

template<typename T>
inline void LinkedList<T>::push_after(Iterator iter, const T& val) {
    iter.pointer->next = new Node(iter.pointer->next, val);
    if (iter.pointer == tail) tail = iter.pointer->next;
    count++;
}

template<typename T>
inline void LinkedList<T>::pop_front() {
    pop_at(0);
}

template<typename T>
inline void LinkedList<T>::pop_end() {
    pop_at(size()-1);
}

template<typename T>
inline void LinkedList<T>::pop_at(size_t index) {
    Node* to_remove = head;
    if (index == 0) {
        head = head->next;
        if (!head) tail = nullptr;
    } else {
        Node* iter = head;
        for (size_t i = 0; i < index - 1; ++i, iter = iter->next);
        to_remove = iter->next;
        iter->next = to_remove->next;
        if (to_remove == tail) tail = iter;
    }
    delete to_remove;
    --count;
}

template<typename T>
inline void LinkedList<T>::pop_after(Iterator iter) {
    Node* to_remove = iter.pointer->next;
    iter.pointer->next = to_remove->next;
    if (to_remove == tail) tail = iter.pointer;
    delete to_remove;
    --count;
}

template<typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::begin() {
    return LinkedList<T>::Iterator(head);
}

template<typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::end() {
    return LinkedList<T>::Iterator(nullptr);
}

template<typename T>
inline typename LinkedList<T>::Iterator const LinkedList<T>::c_begin() const {
    return LinkedList<T>::Iterator(head);
}

template<typename T>
inline typename LinkedList<T>::Iterator const LinkedList<T>::c_end() const {
    return LinkedList<T>::Iterator(nullptr);
}

template<typename T>
inline void LinkedList<T>::append(const LinkedList<T>& rhs) {
    // TODO
}

template<typename T>
inline void LinkedList<T>::reverse() {
    // TODO
}

template<typename T>
inline void LinkedList<T>::sort() {
    // TODO
}

template<typename T>
inline bool LinkedList<T>::is_sorted() const {
    // TODO
    return false;
}

template<typename T>
inline void LinkedList<T>::swap(Node*& a, Node*&b) {
    Node* temp = a;
    a = b;
    b = temp;
}

template<typename T>
inline void LinkedList<T>::clear() {
    while (!is_empty()) pop_end();
}

template<typename T>
inline LinkedList<T>::~LinkedList() {
    clear();
}

#endif