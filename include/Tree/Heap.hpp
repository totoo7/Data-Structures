#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include "Vector/Vector.hpp"
using namespace std;

/**
 * @class Heap
 * @brief A k-ary heap implementation using a dynamic vector.
 *
 * @tparam T The type of elements stored in the heap.
 */
template<typename T>
class Heap {
    public:
        /**
         * @brief Constructs a k-ary heap with a given branching factor.
         * @param k The number of children each node can have (default is 2).
         */
        Heap(size_t k = 2);
        /**
         * @brief Default copy constructor.
         */
        Heap(const Heap<T>& rhs) = default;
        /**
         * @brief Default copy assignment operator.
         */
        Heap<T>& operator=(const Heap<T>& rhs) = default;
        /**
         * @brief Inserts a new element into the heap.
         * @param value The value to be inserted.
         */
        void insert(const T& value);
        /**
         * @brief Retrieves the minimum element in the heap.
         * @return The minimum element.
         */
        T get_min();
        /**
         * @brief Removes the minimum element from the heap.
         */
        void remove_min();
        /**
         * @brief Checks if the heap is empty.
         * @return True if the heap is empty, otherwise false.
         */
        bool is_empty() const;
        /**
         * @brief Gets the number of elements in the heap.
         * @return The size of the heap.
         */
        int size() const;
        /**
         * @brief Prints the contents of the heap.
         */
        void print() const;
        /**
         * @brief Default destructor.
         */
        ~Heap() = default;
    private:
        /**
         * @brief Returns the index of the parent of a given node.
         * @param index The index of the child node.
         * @return The index of the parent node.
         */
        size_t parent(size_t index);
        /**
         * @brief Returns the index of the j-th child of a given node.
         * @param index The index of the parent node.
         * @param j The child number (1-based index).
         * @return The index of the j-th child.
         */
        size_t child(size_t index, size_t j);
        /**
         * @brief Restores the heap property by moving an element up.
         * @param index The index of the element to move up.
         */
        void heapify_up(size_t index);
        /**
         * @brief Restores the heap property by moving an element down.
         * @param index The index of the element to move down.
         */
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