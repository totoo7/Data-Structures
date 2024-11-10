#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP

#include <iostream>
using namespace std;

template<class T>
class StaticStack {
    public:
        StaticStack(size_t size = 16);
        StaticStack(const StaticStack<T>& rhs);
        StaticStack& operator=(const StaticStack<T>& rhs);
        void push_back(const T& val);
        void pop_back();
        T& peek();
        const T& peek() const;
        bool is_empty() const;
        bool is_full() const;
        ~StaticStack();
    private:
        T* data = nullptr;
        size_t top = 0;
        const size_t size;
};

template<typename T>
inline StaticStack<T>::StaticStack(size_t size) : data(new T[size]), size(size) {}

template<typename T>
inline StaticStack<T>::StaticStack(const StaticStack<T>& rhs) : data(new T[rhs.size]), size(rhs.size) {
    while (top < rhs.top) push_back(rhs.data[top]);
}

template<typename T>
inline StaticStack<T>& StaticStack<T>::operator=(const StaticStack<T>& rhs) {
    if (this == &rhs) return *this;
    top = 0;
    while (top < rhs.top) push_back(rhs.data[top]);
    return *this;
}

template<typename T>
inline void StaticStack<T>::push_back(const T& val) {
    data[top++] = val;
}

template<typename T>
inline void StaticStack<T>::pop_back() {
    top--;
}

template<typename T>
inline T& StaticStack<T>::peek() {
    return data[top-1];
}

template<typename T>
inline const T& StaticStack<T>::peek() const {
    return data[top-1];
}

template<typename T>
inline bool StaticStack<T>::is_empty() const {
    return top == 0;
}

template<typename T>
inline bool StaticStack<T>::is_full() const {
    return top == size;
}

template<typename T>
inline StaticStack<T>::~StaticStack() { delete[] data; }

#endif