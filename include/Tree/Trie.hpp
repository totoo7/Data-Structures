#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Trie
 * @brief A class that represents a Trie (prefix tree) data structure.
 * 
 * This class provides operations for inserting, removing, checking if a word
 * exists, printing all words in the Trie, and providing autocomplete suggestions.
 */
class Trie {
    private:
        /**
         * @struct TrieNode
         * @brief A structure that represents each node in the Trie.
         * 
         * Each node contains an array of child nodes and a flag indicating
         * if the node is the end of a word.
         */
        struct TrieNode {
            TrieNode* children[26] = { nullptr };
            bool is_final = false;
            TrieNode()=default;
        };
        TrieNode* root;
    public:
        /**
         * @brief Constructs a Trie object.
         * 
         * Initializes the root node of the Trie.
         */
        Trie();
        /**
         * @brief Deleted copy constructor.
         * 
         * Copying a Trie object is not supported.
         */
        Trie(const Trie& rhs) = delete;
         /**
         * @brief Deleted copy assignment operator.
         * 
         * Assigning a Trie object is not supported.
         */
        Trie& operator=(const Trie& rhs) = delete;
        /**
         * @brief Inserts a word into the Trie.
         * 
         * @param word The word to insert into the Trie.
         */
        void insert(const string& word);
        /**
         * @brief Removes a word from the Trie.
         * 
         * @param word The word to remove from the Trie.
         * @return true if the word was successfully removed, false otherwise.
         */
        bool remove(const string& word);
        /**
         * @brief Checks if a word exists in the Trie.
         * 
         * @param word The word to check for.
         * @return true if the word exists, false otherwise.
         */
        bool contains(const string& word);
        /**
         * @brief Prints all words in the Trie.
         * 
         * @param current_word The current prefix to print.
         */
        void print(const string& current_word) const;
        /**
         * @brief Provides autocomplete suggestions for a given prefix.
         * 
         * @param prefix The prefix to autocomplete.
         */
        void autocomplete(const string& prefix);
        /**
         * @brief Destructor that clears the Trie and deallocates memory.
         */
        ~Trie();
    private:
        /**
         * @brief Clears all nodes in the Trie recursively.
         * 
         * @param root The node to start clearing from.
         */
        void clear(TrieNode* root);
        /**
         * @brief Helper function to print all words starting from a given node.
         * 
         * @param root The node to start printing from.
         * @param current_word The current prefix.
         */
        void print(TrieNode* root, const string& current_word) const;
        /**
         * @brief Helper function to provide autocomplete suggestions starting from a node.
         * 
         * @param root The node to start autocomplete from.
         * @param prefix The prefix to autocomplete.
         */
        void autocomplete(TrieNode* root, const string& prefix);
        /**
         * @brief Searches for the node that matches the given prefix.
         * 
         * @param root The node to start searching from.
         * @param prefix The prefix to search for.
         * @return The node corresponding to the end of the prefix, or nullptr if not found.
         */
        TrieNode* start_with(TrieNode* root, const string& prefix);
};

#endif