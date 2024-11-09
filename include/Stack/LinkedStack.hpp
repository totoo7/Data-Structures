#include <iostream>
using namespace std;

template <typename T>
class LinkedStack {
    public:
        LinkedStack() = default;
        LinkedStack(const LinkedStack<T>& rhs);
        LinkedStack<T>& operator=(const LinkedStack<T>& rhs);
        int size() const;
        bool is_empty() const;
        T& peek();
        const T& peek() const;
        void push_back(const T& val);
        void pop_back();
        ~LinkedStack();
    private:
        void clear();
        void copy(const LinkedStack<T>& rhs);
    private:
        struct Node {
            T data;
            Node* next = nullptr;
        };
        Node* top = nullptr;
        int count = 0;
};

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& rhs) : top(nullptr) {
    try {
        copy(rhs);
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs) {
    if (this == &rhs) return *this;
    try {
        clear();
        copy(rhs);
    } catch (std::bad_alloc &ex) {
        clear();
        throw;
    }
    return *this;
}

template<typename T>
inline int LinkedStack<T>::size() const { return count; }


template<typename T>
inline bool LinkedStack<T>::is_empty() const { return size() == 0; }

template<typename T>
inline T& LinkedStack<T>::peek() { return top->data; }

template<typename T>
inline const T& LinkedStack<T>::peek() const { return top->data; }

template<typename T>
inline void LinkedStack<T>::push_back(const T& val) {
    Node* n = new Node();
    n->data = val;
    n->next = top;
    top = n;
    ++count;
}

template<typename T>
inline void LinkedStack<T>::pop_back() {
    Node* n = top;
    top = top->next;
    delete n;
    --count;
}

template<typename T>
void LinkedStack<T>::clear() {
    while (!is_empty()) {
        Node* n = top;
        top = top->next;
        delete n;
        --count;
    }
}

template<typename T>
void LinkedStack<T>::copy(const LinkedStack<T> &rhs) {
    if (rhs.top) {
            top = new Node {rhs.top->data, nullptr};
            Node* prev = top;
            Node* rhsCurrent = rhs.top->next;
            while (rhsCurrent) {
                prev->next = new Node {rhsCurrent->data, nullptr};
                prev = prev->next;
                rhsCurrent = rhsCurrent->next;
            }
    }
    count = rhs.size();
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}
