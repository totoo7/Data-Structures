#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include<iostream>
using namespace std;

template<typename T>
class BinarySearchTree {
    public:
        BinarySearchTree()=default;;
        BinarySearchTree(const BinarySearchTree<T>& rhs);
        BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rhs);
        bool find(const T& value);
        void insert(const T& value);
        bool remove(const T& value);
        size_t height() const;
        void print() const;   
        ~BinarySearchTree();
    private:
        struct Node {
            T value;
            Node* left = nullptr;
            Node* right = nullptr;
        };
        Node* root = nullptr;
    private:
        void clear(Node*& root); 
        bool find(Node* n, const T& value);
        Node* copy(Node* root);
        void insert(Node*& root, const T& value);
        bool remove(Node*& root, const T& value);
        Node* get_min(Node*& root);
        size_t height(const Node* root) const;
        void print(const Node* root) const;
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& rhs) {
    try {
        root = copy(rhs.root);
    } catch(std::bad_alloc& e) {
        clear(root);
        throw;
    }
}

template<typename T>
inline BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rhs) {
    if (this == &rhs) return *this;
    BinarySearchTree<T> temp = rhs;
    std::swap(root, temp.root);
    return *this;
}

template<typename T>
inline void BinarySearchTree<T>::insert(Node*& root, const T& value) {
    if (!root) {
        root = new Node;
        root->value = value;
    } else {
        if (value < root->value) return insert(root->left, value);
        else return insert(root->right, value);
    }
}

template<typename T>
inline void BinarySearchTree<T>::insert(const T& value) {
    return insert(root, value);
}   

template<typename T>
inline void BinarySearchTree<T>::clear(Node*& root) {
    if (!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
    root = nullptr;
}

template<typename T>
inline bool BinarySearchTree<T>::find(const T& value) {
    return find(root, value);
}

template<typename T>
inline bool BinarySearchTree<T>::find(Node* n, const T& value) {
    if (!n) return false;
    if (n->value == value) return true;
    if (value < n->value) return find(n->left, value);
    else return find(n->right, value);
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::copy(Node* root) {
    if (!root) return nullptr;
    return new Node {root->value, copy(root->left), copy(root->right)};
}

template<typename T>
inline bool BinarySearchTree<T>::remove(const T& value) {
    return remove(root, value);
}

template<typename T>
inline bool BinarySearchTree<T>::remove(Node*& root, const T& value) {
    if (!root) return false;
    if (root->value == value) {
        Node* to_remove = root;
        if (!root->left) root = root->right;
        else if (!root->right) root = root->left;
        else {
            Node* min = get_min(root->right);
            min->left = root->left;
            min->right = root->right;
            root = min;
        }
        delete to_remove;
        return true;
    } else {
        if (value < root->value) return remove(root->left, value);
        else return remove(root->right, value);
    }
}

template<typename T>
inline typename BinarySearchTree<T>::Node* BinarySearchTree<T>::get_min(Node*& root) {
    if (!root) return nullptr;
    if (root->left) return get_min(root->left);
    Node* n = root;
    root = root->right;
    return n;
}

template<typename T>
inline size_t BinarySearchTree<T>::height(const Node* root) const {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

template<typename T>
inline size_t BinarySearchTree<T>::height() const {
    return height(root);
}

template<typename T>
inline void BinarySearchTree<T>::print(const Node* root) const {
    if (!root) return;
    print(root->left);
    cout << root->value << " ";
    print(root->right);
}

template<typename T>
inline void BinarySearchTree<T>::print() const {
    return print(root);
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree() {
    clear(root);
}

#endif