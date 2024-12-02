#include <catch2/catch_all.hpp>
#include "Queue/Deque.hpp"

TEST_CASE("Deque basic operations", "[deque]") {
    Deque<int> deque;

    SECTION("Push and pop from the front") {
        deque.push_front(1);
        deque.push_front(2);
        REQUIRE(deque.front() == 2);
        deque.pop_front();
        REQUIRE(deque.front() == 1);
    }

    SECTION("Push and pop from the back") {
        deque.push_back(3);
        deque.push_back(4);
        REQUIRE(deque.back() == 4);
        deque.pop_back();
        REQUIRE(deque.back() == 3);
    }
}