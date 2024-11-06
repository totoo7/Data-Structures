#include <iostream>
using namespace std;

template <typename T>
class LinkedStack {
    public:
        LinkedStack() = default;
        int size() const;
        bool is_empty() const;
        T& peek();
        const T& peek() const;
        void push_back(const T& val);
        void pop_back();
    private:
        struct Node {
            T data;
            Node* next = nullptr;
        };
        Node* top = nullptr;
        int count = 0;
};

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
}
