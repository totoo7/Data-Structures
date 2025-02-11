#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include "Vector/Vector.hpp"
using namespace std;

template<typename T>
class Heap {
    public:
        Heap(size_t k = 2);
        Heap(const Heap<T>& rhs) = default;
        Heap<T>& operator=(const Heap<T>& rhs) = default;
        void insert(const T& value);
        T get_min();
        void remove_min();
        bool is_empty() const;
        int size() const;
        void print() const;
        ~Heap() = default;
    private:
        size_t parent(size_t index);
        size_t child(size_t index, size_t j);
        void heapify_up(size_t index);
        void heapify_down(size_t index);
    private:
        Vector<T> data;
        size_t k;
};

template<typename T>
inline Heap<T>::Heap(size_t k) : k(k) {}

template<typename T>
inline void Heap<T>::insert(const T& value) {
    data.push_back(value);
    int index = data.size()-1;
    heapify_up(index);
}

template<typename T>
inline T Heap<T>::get_min() {
    return data[0];
}

template<typename T>
inline void Heap<T>::remove_min() {
    data[0] = data.back();
    data.pop_back();
    heapify_down(0);
}

template<typename T>
inline bool Heap<T>::is_empty() const {
    return data.empty();
}

template<typename T>
inline int Heap<T>::size() const {
    return data.size();
}

template<typename T>
inline void Heap<T>::print() const {
    for (size_t i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<typename T>
inline size_t Heap<T>::parent(size_t index) {
    return (index-1)/k;
}

template<typename T>
inline size_t Heap<T>::child(size_t index, size_t j) {
    return k * index + j;
}

template<typename T>
inline void Heap<T>::heapify_up(size_t index) {
    while (index > 0 && data[index] < data[parent(index)]) {
        swap(data[index], data[parent(index)]);
        index = parent(index);
    }
}

template<typename T>
inline void Heap<T>::heapify_down(size_t index) {
    size_t min = index;
    for (int i = 1; i <= k; i++) {
        size_t child_index = child(index, i);
        if (child_index < data.size() && data[child_index] < data[min]) {
            min = child_index;
        }
    }
    if (min != index) {
        swap(data[index], data[min]);
        heapify_down(min);
    }
}

#endif