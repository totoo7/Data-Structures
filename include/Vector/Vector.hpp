#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;

/**
 * @brief A dynamic array-like container that provides random access to elements.
 * 
 * This class implements a custom vector which can store elements and automatically 
 * resize when it reaches its capacity. It also supports various container operations 
 * such as adding elements, removing elements, and accessing the elements using 
 * iterators or indices.
 * 
 * @tparam T The type of elements in the vector.
 */
template <typename T>
class Vector {
    public:
        /**
         * @brief Iterator class to allow iteration over elements in the Vector.
         * 
         * This class provides standard iterator functionality, including dereferencing, 
         * comparison, and incrementing.
         */
        class Iterator {
            public:
                /**
                 * @brief Dereference the iterator to get the current element.
                 * @return Reference to the element pointed to by the iterator.
                 */
                T& operator*();
                /**
                 * @brief Dereference the iterator to get the current element (const version).
                 * @return Constant reference to the element pointed to by the iterator.
                 */
                const T& operator*() const;
                /**
                 * @brief Access the element pointed to by the iterator using the arrow operator.
                 * @return Pointer to the element pointed to by the iterator.
                 */
                T* operator->();
                /**
                 * @brief Access the element pointed to by the iterator using the arrow operator (const version).
                 * @return Constant pointer to the element pointed to by the iterator.
                 */
                const T* operator->() const;
                /**
                 * @brief Access an element at a specific index from the iterator’s current position.
                 * @param index The index from the iterator’s current position.
                 * @return Reference to the element at the specified index.
                 */
                T& operator[](size_t index);
                /**
                 * @brief Prefix increment operator to move the iterator to the next element.
                 * @return Reference to the incremented iterator.
                 */
                Iterator& operator++();
                /**
                 * @brief Postfix increment operator to move the iterator to the next element.
                 * @return A copy of the iterator before incrementing.
                 */
                Iterator operator++(int);
                /**
                 * @brief Inequality comparison between two iterators.
                 * @param rhs The iterator to compare with.
                 * @return true if the iterators are not equal, false otherwise.
                 */
                bool operator!=(const Iterator& rhs) const;
                /**
                 * @brief Equality comparison between two iterators.
                 * @param rhs The iterator to compare with.
                 * @return true if the iterators are equal, false otherwise.
                 */
                bool operator==(const Iterator& rhs) const;
                friend class Vector<T>;
            protected:
                /**
                 * @brief Default constructor for the iterator.
                 */
                Iterator();
                /**
                 * @brief Constructor for the iterator given a pointer to the vector.
                 * @param vector Pointer to the vector to iterate over.
                 */
                Iterator(Vector<T>* vector);
                /**
                 * @brief Constructor for the iterator given a pointer to the vector and an initial index.
                 * @param vector Pointer to the vector to iterate over.
                 * @param index Initial index of the iterator.
                 */
                Iterator(Vector<T>* vector, size_t index);
            protected:
                Vector<T>* pointer;
                size_t index;
        };
    public: 
        /**
         * @brief Default constructor for the vector.
         * Initializes the vector with a default capacity of 2.
         */
        Vector();
        /**
         * @brief Copy constructor for the vector.
         * @param rhs The vector to copy.
         */
        Vector(const Vector<T>& rhs);
        /**
         * @brief Copy assignment operator for the vector.
         * @param rhs The vector to assign.
         * @return Reference to this vector.
         */
        Vector<T>& operator=(const Vector<T>& rhs);
        /**
         * @brief Adds an element to the end of the vector.
         * If the vector is full, it automatically resizes.
         * @param val The value to add to the vector.
         */
        void push_back(const T& val);
        /**
         * @brief Removes the last element from the vector.
         */
        void pop_back();
        /**
         * @brief Returns the number of elements in the vector.
         * @return The size of the vector.
         */
        size_t size() const;
        /**
         * @brief Checks if the vector is empty.
         * @return true if the vector is empty, false otherwise.
         */
        bool empty() const;
        /**
         * @brief Returns the first element in the vector.
         * @return Reference to the first element.
         */
        T& front();
        /**
         * @brief Returns the first element in the vector (const version).
         * @return Const reference to the first element.
         */
        const T& front() const;
        /**
         * @brief Returns the last element in the vector.
         * @return Reference to the last element.
         */
        T& back();
        /**
         * @brief Returns the last element in the vector (const version).
         * @return Const reference to the last element.
         */
        const T& back() const;
        /**
         * @brief Checks if the vector contains the specified value.
         * @param val The value to check for.
         * @return true if the vector contains the value, false otherwise.
         */
        bool contains(const T& val) const;
        /**
         * @brief Access an element by index.
         * @param index The index of the element to access.
         * @return Reference to the element at the specified index.
         */
        T& operator[](size_t index);
        /**
         * @brief Access an element by index (const version).
         * @param index The index of the element to access.
         * @return Const reference to the element at the specified index.
         */
        const T& operator[](size_t index) const;
        /**
         * @brief Returns an iterator to the first element in the vector.
         * @return An iterator to the first element.
         */
        Iterator begin();
        /**
         * @brief Returns an iterator to the past-the-end element in the vector.
         * @return An iterator to the past-the-end element.
         */
        Iterator end();
        /**
         * @brief Returns a constant iterator to the first element in the vector.
         * @return A constant iterator to the first element.
         */
        const Iterator c_begin() const;
        /**
         * @brief Returns a constant iterator to the past-the-end element in the vector.
         * @return A constant iterator to the past-the-end element.
         */
        const Iterator c_end() const;
        /**
         * @brief Destructor for the vector.
         * Releases the allocated memory for the data.
         */
        ~Vector();
    private:
        /**
         * @brief Clears the vector by deallocating memory and resetting the size and capacity.
         */
        void clear();
        /**
         * @brief Swaps two pointers.
         * @param a The first pointer.
         * @param b The second pointer.
         */
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
inline typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
inline typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int) {
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
        data = new T[rhs.capacity];
        count = rhs.count;
        capacity = rhs.capacity;
        for (size_t i = 0; i < count; i++) 
            data[i] = rhs.data[i];
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
    if (count == capacity) {
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
    for (size_t i = 0; i < count; i++) {
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
inline typename Vector<T>::Iterator Vector<T>::begin() {
    return Vector<T>::Iterator(this, 0);
}

template<typename T>
inline typename Vector<T>::Iterator Vector<T>::end() {
    return Vector<T>::Iterator(this, count);
}

template<typename T>
inline typename Vector<T>::Iterator const Vector<T>::c_begin() const {
    return Vector<T>::Iterator(this, 0);
}

template<typename T>
inline typename Vector<T>::Iterator const Vector<T>::c_end() const {
    return Vector<T>::Iterator(this, count);
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