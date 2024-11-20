#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;

template <typename T>
class Vector {
    public:
        class Iterator {
            public:
                Iterator();
                Iterator(Vector<T>* vector);
                Iterator(Vector<T>* vector, size_t index);
                T& operator*();
                T* operator->();
                const T* operator->() const;
                T& operator[](size_t index);
                Iterator& operator++();
                Iterator operator++(int);
                bool operator!=(const Iterator& rhs) const;
                bool operator==(const Iterator& rhs) const;
            private:
                Vector<T>* pointer;
                size_t index;
        };
    public: 
        Vector();
        Vector(const Vector<T>& rhs);
        Vector<T>& operator=(const Vector<T>& rhs);
        void push_back(const T& val);
        void pop_back();
        size_t size() const;
        bool empty() const;
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        bool contains(const T& val) const;
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        ~Vector();
    private:
        void clear();
        void swap(T*& a, T*& b);
    private:
        T* data = nullptr;
        size_t count = 0;
        size_t capacity = 2;
};

template<typename T>
inline Vector<T>::Iterator::Iterator() : 
    pointer(nullptr), index(0) {}

template<typename T>
inline Vector<T>::Iterator::Iterator(Vector<T>* vector) : 
    pointer(vector), index(0) {}

template<typename T>
inline Vector<T>::Iterator::Iterator(Vector<T>* vector, size_t index) : 
    pointer(vector), index(index) {}

template<typename T>
inline T& Vector<T>::Iterator::operator*() {
    return (*pointer)[index];
}

template<typename T>
inline T* Vector<T>::Iterator::operator->() {
    return &((*pointer)[index]);
}

template<typename T>
inline const T* Vector<T>::Iterator::operator->() const {
    return &((*pointer)[index]);
}

template<typename T>
inline T& Vector<T>::Iterator::operator[](size_t index) {
    return (*pointer)[this->index + index];
}

template<typename T>
inline Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
inline Vector<T>::Iterator Vector<T>::Iterator::operator++(int) {
    Iterator temp(*this);
    ++(*this);
    return temp;
}

template<typename T>
inline bool Vector<T>::Iterator::operator!=(const Iterator& rhs) const {
    return index != rhs.index;
}

template<typename T>
inline bool Vector<T>::Iterator::operator==(const Iterator& rhs) const {
    return index == rhs.index;
}

template<typename T>
inline Vector<T>::Vector() {
    try {
        data = new T[capacity];
    } catch (std::bad_alloc& e){
        clear();
        throw;
    }
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& rhs) {
    try {
        for (size_t i = 0; i < rhs.size(); i++) {
            push_back(rhs[i]);
        }
    } catch (std::bad_alloc& e) {
        clear();
        throw;
    }
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
    if (this == &rhs) return *this;
    Vector<T> temp = rhs;
    swap(data, temp.data);

    size_t tempCount = count;
	count = temp.count;
	temp.count = tempCount;

	size_t tempCapacity = capacity;
	capacity = temp.capacity;
	temp.capacity = tempCapacity;

    return *this;
}

template<typename T>
inline void Vector<T>::push_back(const T& val) {
    if (size() == capacity) {
        T* temp = new T[capacity * 2];
        for (size_t i = 0; i < capacity; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        capacity *= 2;
        data = temp;
    }
    data[count++] = val;
}

template<typename T>
inline void Vector<T>::pop_back() {
    count--;
}

template<typename T>
inline size_t Vector<T>::size() const {
    return count;
}
        
template<typename T>
inline bool Vector<T>::empty() const {
    return count == 0;
}

template<typename T>
inline T& Vector<T>::front() {
    return data[0];
}

template<typename T>
inline const T& Vector<T>::front() const {
    return data[0];
}

template<typename T>
inline T& Vector<T>::back() {
    return data[count-1];
}

template<typename T>
inline const T& Vector<T>::back() const {
    return data[count-1];
}

template<typename T>
inline bool Vector<T>::contains(const T& val) const {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == val) return true;
    }
    return false;
}

template<typename T>
inline T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
inline const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template<typename T>
inline void Vector<T>::clear() {
    delete[] data;
    capacity = 0;
    count = 0;
}

template <typename T>
inline void Vector<T>::swap(T*& a, T*& b)
{
	T* temp = a;
	a = b;
	b = temp;
}

template<typename T>
inline Vector<T>::~Vector() {
    clear();
}

#endif