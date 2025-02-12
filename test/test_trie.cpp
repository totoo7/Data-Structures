#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Trie.hpp"

TEST_CASE("Trie") {
    SECTION("Default Constructor and Empty Trie Check") {
        Trie trie;
        REQUIRE_FALSE(trie.contains("test"));
    }
    
    SECTION("Insert and Contains") {
        Trie trie;
        trie.insert("hello");
        REQUIRE(trie.contains("hello"));
        REQUIRE_FALSE(trie.contains("hell"));
        REQUIRE_FALSE(trie.contains("world"));
    }
    
    SECTION("Remove Word") {
        Trie trie;
        trie.insert("test");
        REQUIRE(trie.contains("test"));
        REQUIRE(trie.remove("test"));
        REQUIRE_FALSE(trie.contains("test"));
        REQUIRE_FALSE(trie.remove("test"));
    }
    
    SECTION("Remove with Prefix Overlap") {
        Trie trie;
        trie.insert("test");
        trie.insert("testing");
        REQUIRE(trie.contains("test"));
        REQUIRE(trie.contains("testing"));
        REQUIRE(trie.remove("test"));
        REQUIRE_FALSE(trie.contains("test"));
        REQUIRE_FALSE(trie.contains("testing"));
    }
    
    SECTION("Autocomplete Suggestions") {
        Trie trie;
        trie.insert("car");
        trie.insert("cat");
        trie.insert("cart");
        trie.insert("dog");
        trie.autocomplete("ca");
    }
}
