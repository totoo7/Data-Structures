#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
    public:
        int size() const { return data.size(); }
        bool is_empty() const { return data.empty(); }
        void dequeue() { data.erase(data.begin()) }
        void enqueue(const T& val) { data.push_back(); }
        const T& peek() const { return data.front(); }
        T& peek() { return data.front(); }
    private:
        vector<T> data;
};

#endif