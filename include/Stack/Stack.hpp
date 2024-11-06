#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
    private:
        vector<T> data;
    public:
        int size() const { return data.size(); }
        bool is_empty() const { return data.empty(); }
        void pop_back() { data.pop_back(); }
        void push_back(const T& val) { data.push_back(); }
        T& top() { return data.back(); }
};

#endif