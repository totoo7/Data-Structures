#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
    public:
        int size() const { return data.size(); }
        bool is_empty() const { return data.empty(); }
        void pop_back() { data.pop_back(); }
        void push_back(const T& val) { data.push_back(); }
        const T& peek() const { return data.back(); }
        T& peek() { return data.back(); }
    private:
        vector<T> data;
};

#endif