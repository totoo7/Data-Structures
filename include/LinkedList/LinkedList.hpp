#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
    private:
        struct Node {
            Node* next = nullptr;
            T data;
            Node(Node* next_val, T data_val) : next(next_val), data(data_val) {}
        };
    public:
        class Iterator {
            public:
                T& operator*();
                const T& operator*() const;
                T* operator->();
                const T* operator->() const;
                Iterator& operator++();
                Iterator operator++(int);
                bool operator!=(const Iterator& rhs) const;
                bool operator==(const Iterator& rhs) const;
                friend class LinkedList<T>;
            protected:
                Iterator(LinkedList<T>::Node* node);
            protected:
                LinkedList<T>::Node* pointer;
        };
    public:
        LinkedList()=default;
        LinkedList(const LinkedList<T>& rhs);
        LinkedList<T>& operator=(const LinkedList<T>& rhs);
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        T& at(size_t index);
        const T& at(size_t index) const;
        bool is_empty() const;
        size_t size() const;
        void push_front(const T& val);
        void push_end(const T& val);
        void push_at(size_t index, const T& val);
        void push_after(Iterator iter, const T& val);
        void pop_front();
        void pop_end();
        void pop_at(size_t index);
        void pop_after(Iterator iter);
        Iterator begin();
        Iterator end();
        const Iterator c_begin() const;
        const Iterator c_end() const;
        void append(const LinkedList<T>& rhs);
        void reverse();
        void sort();
        bool is_sorted() const;
        ~LinkedList();
    private: 
        Node* head = nullptr;
        Node* tail = nullptr;
        size_t count = 0;
    private: 
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
inline LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    pointer = pointer->next;
    return *this;
}

template<typename T>
inline LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Iterator temp(*this);
    ++(*this);
    return temp;
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
    return pointer == rhs.pointer;
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
    return !(*this == rhs);
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
inline LinkedList<T>::Iterator LinkedList<T>::begin() {
    return LinkedList<T>::Iterator(head);
}

template<typename T>
inline LinkedList<T>::Iterator LinkedList<T>::end() {
    return LinkedList<T>::Iterator(nullptr);
}

template<typename T>
inline const LinkedList<T>::Iterator LinkedList<T>::c_begin() const {
    return LinkedList<T>::Iterator(head);
}

template<typename T>
inline const LinkedList<T>::Iterator LinkedList<T>::c_end() const {
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