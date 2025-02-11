#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <string>
using namespace std;

class Trie {
    private:
        struct TrieNode {
            TrieNode* children[26] = { nullptr };
            bool is_final = false;
            TrieNode()=default;
        };
        TrieNode* root;
    public:
        Trie();
        Trie(const Trie& rhs) = delete;
        Trie& operator=(const Trie& rhs) = delete;
        void insert(const string& word);
        bool remove(const string& word);
        bool contains(const string& word);
        void print(const string& current_word) const;
        void autocomplete(const string& prefix);
        ~Trie();
    private:
        void clear(TrieNode* root);
        void print(TrieNode* root, const string& current_word) const;
        void autocomplete(TrieNode* root, const string& prefix);
        TrieNode* start_with(TrieNode* root, const string& prefix);
};

#endif