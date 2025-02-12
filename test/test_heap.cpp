#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Heap.hpp"

TEST_CASE("Heap") {
    SECTION("Default Constructor and Empty Check") {
        Heap<int> heap;
        REQUIRE(heap.is_empty());
        REQUIRE(heap.size() == 0);
    }
    
    SECTION("Insert and Get Min") {
        Heap<int> heap;
        heap.insert(10);
        REQUIRE(heap.get_min() == 10);
        heap.insert(5);
        REQUIRE(heap.get_min() == 5);
        heap.insert(15);
        REQUIRE(heap.get_min() == 5);
    }
    
    SECTION("Remove Min") {
        Heap<int> heap;
        heap.insert(10);
        heap.insert(5);
        heap.insert(15);
        REQUIRE(heap.get_min() == 5);
        heap.remove_min();
        REQUIRE(heap.get_min() == 10);
        heap.remove_min();
        REQUIRE(heap.get_min() == 15);
        heap.remove_min();
        REQUIRE(heap.is_empty());
    }
    
    SECTION("Heap Ordering with Multiple Inserts") {
        Heap<int> heap;
        heap.insert(20);
        heap.insert(15);
        heap.insert(30);
        heap.insert(5);
        heap.insert(10);
        REQUIRE(heap.get_min() == 5);
        heap.remove_min();
        REQUIRE(heap.get_min() == 10);
        heap.remove_min();
        REQUIRE(heap.get_min() == 15);
    }
    
    SECTION("Copy Constructor") {
        Heap<int> heap;
        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        Heap<int> copiedHeap(heap);
        REQUIRE(copiedHeap.size() == heap.size());
        REQUIRE(copiedHeap.get_min() == heap.get_min());
    }
    
    SECTION("Copy Assignment Operator") {
        Heap<int> heap;
        heap.insert(10);
        heap.insert(5);
        Heap<int> copiedHeap;
        copiedHeap = heap;
        REQUIRE(copiedHeap.size() == heap.size());
        REQUIRE(copiedHeap.get_min() == heap.get_min());
    }
    
    SECTION("Self Assignment") {
        Heap<int> heap;
        heap.insert(10);
        heap.insert(5);
        heap = heap;
        REQUIRE(heap.size() == 2);
        REQUIRE(heap.get_min() == 5);
    }
}
