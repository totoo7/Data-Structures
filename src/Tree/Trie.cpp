#include "Trie.hpp"

Trie::Trie() {
    root = new TrieNode;
}

void Trie::insert(const string& word) {
    TrieNode* node = root;
    size_t it = 0;
    while (word[it] != '\0') {
        if (!node->children[word[it]- 'a'])
            node->children[word[it] - 'a'] = new TrieNode();

        node = node->children[word[it]- 'a'];
        ++it;
    }
    node->is_final = true;
}

bool Trie::remove(const string& word) {
    if (!root || !contains(word)) return false;

    TrieNode* current = root;
    TrieNode* last_final = nullptr;
    size_t last_final_index = 0;
    size_t i = 0;

    while (i < word.length()) {
        if (current->is_final && i + 1 < word.length()) {
            last_final = current;
            last_final_index = word[i] - 'a';
        }
        current = current->children[word[i] - 'a'];
        ++i;
    }

    if (!last_final) {
        clear(root);
        root = new TrieNode();
    } else {
        clear(last_final->children[last_final_index]);
        last_final->children[last_final_index] = nullptr;
    }

    return true;
}

Trie::TrieNode* Trie::start_with(TrieNode* root, const string& prefix) {
    if (!root) return nullptr;
    size_t i = 0;
    while (prefix[i] != '\0') {
        if (root->children[prefix[i] - 'a'] == nullptr)
            return nullptr;
        root = root->children[prefix[i] - 'a'];
        ++i;
    }
    return root;
}

bool Trie::contains(const string& word) {
    if (!root) return false;
    TrieNode* temp = start_with(root, word);
    return temp != nullptr && temp->is_final;
}

void Trie::print(TrieNode* root, const string& current_word) const {
    if (!root) return;
    if (root->is_final) cout << current_word << endl;
    for (size_t i = 0; i < 26; ++i) {
        if (root->children[i])
            print(root->children[i], current_word + (char)('a' + i)); 
    }
}

void Trie::print(const string& current_word = "") const {
    print(root, current_word);
}

void Trie::autocomplete(TrieNode* root, const string& prefix) {
    root = start_with(root, prefix);
    print(root, prefix);
}

void Trie::autocomplete(const string& prefix) {
    autocomplete(root, prefix);
}

void Trie::clear(TrieNode* root) {
    if (!root) return;
    for (size_t i = 0; i < 26; ++i) {
        clear(root->children[i]);
    }
    delete root;
}

Trie::~Trie() {
    clear(root);
}