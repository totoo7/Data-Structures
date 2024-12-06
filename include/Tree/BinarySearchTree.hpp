#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

template<typename T>
class BinarySearchTree {
    private:
        struct Node {
            T value;
            Node* left = nullptr;
            Node* right = nullptr;
        };
        Node* root = nullptr;
    private:
        Node*& find(Node* n, const T& value) {
            if (!n) return false;
            if (n->value == value) return true;
            if (value < n->value) return find(n->left, value);
            else return find(n->right, value);
        }
    public:
        bool find(const T& value) {
            return find(root, value);
        }
        bool insert(const T& value) {
            Node*& pos = find(root, value);
            if (pos) return false;
            pos = new Node;
            pos->value = value;
            return true;
        }
};

#endif