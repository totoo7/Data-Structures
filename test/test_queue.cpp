#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Queue.hpp"

TEST_CASE("Queue") {

    SECTION("Default Constructor") {
        Queue<int> q;
        REQUIRE(q.is_empty() == true);
        REQUIRE(q.size() == 0);
    }

    SECTION("Enqueue operation") {
        Queue<int> q;
        q.enqueue(10);
        REQUIRE(q.is_empty() == false);
        REQUIRE(q.size() == 1);
        REQUIRE(q.peek() == 10);

        q.enqueue(20);
        REQUIRE(q.size() == 2);
        REQUIRE(q.peek() == 10);  // Front element should still be 10
    }

    SECTION("Dequeue operation") {
        Queue<int> q;
        q.enqueue(10);
        q.enqueue(20);

        q.dequeue();
        REQUIRE(q.size() == 1);
        REQUIRE(q.peek() == 20);

        q.dequeue();
        REQUIRE(q.is_empty() == true);
    }

    SECTION("Peek operation (const and non-const)") {
        Queue<int> q;
        q.enqueue(10);
        q.enqueue(20);
        
        REQUIRE(q.peek() == 10);
        const Queue<int>& const_q = q;
        REQUIRE(const_q.peek() == 10);
    }

    SECTION("Size operation") {
        Queue<int> q;
        REQUIRE(q.size() == 0);
        q.enqueue(1);
        q.enqueue(2);
        REQUIRE(q.size() == 2);
        q.dequeue();
        REQUIRE(q.size() == 1);
    }

    SECTION("Empty check on queue") {
        Queue<int> q;
        REQUIRE(q.is_empty() == true);
        q.enqueue(5);
        REQUIRE(q.is_empty() == false);
        q.dequeue();
        REQUIRE(q.is_empty() == true);
    }

    SECTION("Multiple enqueue and dequeue") {
        Queue<int> q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);

        REQUIRE(q.size() == 4);
        q.dequeue();
        REQUIRE(q.peek() == 2);
        q.dequeue();
        REQUIRE(q.peek() == 3);
        q.dequeue();
        REQUIRE(q.peek() == 4);
        q.dequeue();
        REQUIRE(q.is_empty() == true);
    }
}