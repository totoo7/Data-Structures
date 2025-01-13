#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include<iostream>
using namespace std;

/**
 * @brief A template-based Binary Search Tree implementation.
 * 
 * Provides basic operations such as insertion, deletion, search, height calculation, 
 * and in-order traversal printing. 
 * 
 * @tparam T The type of the elements stored in the Binary Search Tree. Must support comparison operators.
 */
template<typename T>
class BinarySearchTree {
    public:
        /**
         * @brief Default constructor.
         */
        BinarySearchTree()=default;;
        /**
         * @brief Copy constructor.
         * 
         * Creates a deep copy of another BinarySearchTree.
         * @param rhs The BinarySearchTree to copy.
         */
        BinarySearchTree(const BinarySearchTree<T>& rhs);
        /**
         * @brief Copy assignment operator.
         * 
         * Assigns the contents of another BinarySearchTree to this one.
         * @param rhs The BinarySearchTree to copy.
         * @return A reference to the current BinarySearchTree.
         */
        BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rhs);
        /**
         * @brief Searches for a value in the Binary Search Tree.
         * 
         * @param value The value to search for.
         * @return True if the value exists in the tree, otherwise false.
         */
        bool find(const T& value);
        /**
         * @brief Inserts a value into the Binary Search Tree.
         * 
         * @param value The value to insert.
         */
        void insert(const T& value);
        /**
         * @brief Removes a value from the Binary Search Tree.
         * 
         * @param value The value to remove.
         * @return True if the value was removed, otherwise false.
         */
        bool remove(const T& value);
        /**
         * @brief Calculates the height of the Binary Search Tree.
         * 
         * @return The height of the tree.
         */
        size_t height() const;
        /**
         * @brief Prints the values of the Binary Search Tree in in-order traversal.
         */
        void print() const;   
        /**
         * @brief Destructor.
         * 
         * Frees all allocated memory.
         */
        ~BinarySearchTree();
    private:
        struct Node {
            T value;
            Node* left = nullptr;
            Node* right = nullptr;
        };
        Node* root = nullptr;
    private:
        /**
         * @brief Recursively clears the Binary Search Tree.
         * 
         * @param root The root of the subtree to clear.
         */
        void clear(Node*& root); 
        /**
         * @brief Recursively searches for a value in the tree.
         * 
         * @param n The current node being searched.
         * @param value The value to search for.
         * @return True if the value is found, otherwise false.
         */
        bool find(Node* n, const T& value);
        /**
         * @brief Recursively creates a deep copy of a subtree.
         * 
         * @param root The root of the subtree to copy.
         * @return A pointer to the copied subtree.
         */
        Node* copy(Node* root);
        /**
         * @brief Recursively inserts a value into a subtree.
         * 
         * @param root The root of the subtree.
         * @param value The value to insert.
         */
        void insert(Node*& root, const T& value);
        /**
         * @brief Recursively removes a value from a subtree.
         * 
         * @param root The root of the subtree.
         * @param value The value to remove.
         * @return True if the value was removed, otherwise false.
         */
        bool remove(Node*& root, const T& value);
        /**
         * @brief Finds the node with the smallest value in a subtree.
         * 
         * @param root The root of the subtree.
         * @return A pointer to the node with the smallest value.
         */
        Node* get_min(Node*& root);
        /**
         * @brief Recursively calculates the height of a subtree.
         * 
         * @param root The root of the subtree.
         * @return The height of the subtree.
         */
        size_t height(const Node* root) const;
        /**
         * @brief Recursively performs in-order traversal and prints the values of a subtree.
         * 
         * @param root The root of the subtree.
         */
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