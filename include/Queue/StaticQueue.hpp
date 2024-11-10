#ifndef STATIC_QUEUE_HPP
#define STATIC_QUEUE_HPP

#include <iostream>
using namespace std;

template<class T>
class StaticQueue {
    public:
        StaticQueue(size_t size = 16);
        StaticQueue(const StaticQueue<T>& rhs);
        StaticQueue& operator=(const StaticQueue<T>& rhs);
        void enqueue(const T& val);
        void dequeue();
        T& peek();
        const T& peek() const;
        bool is_empty() const;
        bool is_full() const;
        ~StaticQueue();
    private:
        T* data = nullptr;
        size_t first, last = 0;
        const size_t size;
};

template<typename T>
inline StaticQueue<T>::StaticQueue(size_t size) : data(new T[size]), size(size) {}

template<typename T>
inline StaticQueue<T>::StaticQueue(const StaticQueue<T>& rhs) : data(new T[rhs.size]), size(rhs.size) {
    for (size_t pos = rhs.first; pos != rhs.last; pos = (pos+1) % size)
        enqueue(rhs.data[pos]);
}

template<typename T>
inline StaticQueue<T>& StaticQueue<T>::operator=(const StaticQueue<T>& rhs) {
    if (this == &rhs) return *this;
    first = last = 0;
    for (size_t pos = rhs.first; pos != rhs.last; pos = (pos+1) % size)
        enqueue(rhs.data[pos]);
    return *this;
}

template<typename T>
inline void StaticQueue<T>::enqueue(const T& val) {
    data[last] = val;
    last = (last+1) % size;
}

template<typename T>
inline void StaticQueue<T>::dequeue() {
    first = (first+1) % size;
}

template<typename T>
inline T& StaticQueue<T>::peek() {
    return data[first];
}

template<typename T>
inline const T& StaticQueue<T>::peek() const {
    return data[first];
}

template<typename T>
inline bool StaticQueue<T>::is_empty() const {
    return first == last;
}

template<typename T>
inline bool StaticQueue<T>::is_full() const {
    return (first+1) % size == last;
}

template<typename T>
inline StaticQueue<T>::~StaticQueue() { delete[] data; }

#endif