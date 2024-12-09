#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Queue/CircularQueue.hpp"

TEST_CASE("CircularQueue") {
    SECTION("Default Constructor") {
        CircularQueue<int> queue;
        REQUIRE(queue.empty());
    }

    SECTION("Enqueue and Size") {
        CircularQueue<int> queue;
        queue.enqueue(10);
        REQUIRE_FALSE(queue.empty());
        REQUIRE(queue.peek() == 10);

        queue.enqueue(20);
        REQUIRE(queue.peek() == 10);
    }

    SECTION("Dequeue") {
        CircularQueue<int> queue;

        queue.enqueue(10);
        queue.enqueue(20);
        REQUIRE(queue.peek() == 10);
        
        queue.dequeue();
        REQUIRE(queue.peek() == 20);

        queue.dequeue();
        REQUIRE(queue.empty());
    }

    SECTION("Resizing on Enqueue") {
        CircularQueue<int> queue;

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        REQUIRE(queue.peek() == 10);
        queue.dequeue();
        REQUIRE(queue.peek() == 20);
    }

    SECTION("Front Access") {
        CircularQueue<int> queue;
        queue.enqueue(42);
        const CircularQueue<int>& constQueue = queue;
        REQUIRE(constQueue.peek() == 42);
        REQUIRE(queue.peek() == 42);
    }

    SECTION("Copy Constructor") {
        CircularQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);

        CircularQueue<int> copiedQueue(queue);
        REQUIRE(copiedQueue.peek() == 10);

        copiedQueue.dequeue();
        REQUIRE(copiedQueue.peek() == 20);

        REQUIRE(queue.peek() == 10);
    }

    SECTION("Assignment Operator") {
        CircularQueue<int> queue1;
        queue1.enqueue(10);
        queue1.enqueue(20);

        CircularQueue<int> queue2;
        queue2.enqueue(30);

        queue2 = queue1;
        REQUIRE(queue2.peek() == 10);

        queue2.dequeue();
        REQUIRE(queue2.peek() == 20);

        REQUIRE(queue1.peek() == 10);
    }

    SECTION("Empty Check") {
        CircularQueue<int> queue;
        REQUIRE(queue.empty());

        queue.enqueue(10);
        REQUIRE_FALSE(queue.empty());

        queue.dequeue();
        REQUIRE(queue.empty());
    }
}
