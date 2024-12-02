#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Queue/StaticCircularQueue.hpp"

TEST_CASE("StaticCircularQueue") {
    StaticCircularQueue<int> queue_default;
    REQUIRE(queue_default.is_empty());
    REQUIRE_FALSE(queue_default.is_full());

    SECTION("Enqueue and Dequeue") {
        StaticCircularQueue<int> queue(3);

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        REQUIRE_FALSE(queue.is_empty());
        REQUIRE(queue.is_full());

        REQUIRE(queue.peek() == 1);

        queue.dequeue();
        REQUIRE(queue.peek() == 2);
        queue.dequeue();
        REQUIRE(queue.peek() == 3);
        queue.dequeue();

        REQUIRE(queue.is_empty());
    }

    SECTION("Copy constructor") {
        StaticCircularQueue<int> queue(3);
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        StaticCircularQueue<int> queue_copy = queue;

        REQUIRE(queue_copy.peek() == 10);
        queue_copy.dequeue();
        REQUIRE(queue_copy.peek() == 20);
        queue_copy.dequeue();
        REQUIRE(queue_copy.peek() == 30);
        queue_copy.dequeue();
        REQUIRE(queue_copy.is_empty());
    }

    SECTION("Copy assignment operator") {
        StaticCircularQueue<int> queue1(3);
        queue1.enqueue(5);
        queue1.enqueue(15);
        queue1.enqueue(25);

        StaticCircularQueue<int> queue2(3);
        queue2.enqueue(100);
        queue2.enqueue(200);

        queue2 = queue1;

        REQUIRE(queue2.peek() == 5);
        queue2.dequeue();
        REQUIRE(queue2.peek() == 15);
        queue2.dequeue();
        REQUIRE(queue2.peek() == 25);
        queue2.dequeue();
        REQUIRE(queue2.is_empty());
    }

    SECTION("Queue is empty and full") {
        StaticCircularQueue<int> queue(3);

        REQUIRE(queue.is_empty());
        REQUIRE_FALSE(queue.is_full());

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        REQUIRE_FALSE(queue.is_empty());
        REQUIRE(queue.is_full());
    }

    SECTION("Peek non-const version") {
        StaticCircularQueue<int> queue(3);
        queue.enqueue(100);
        queue.enqueue(200);

        REQUIRE(queue.peek() == 100);

        queue.dequeue();
        REQUIRE(queue.peek() == 200);
    }

    SECTION("Test swapping") {
        StaticCircularQueue<int> queue1(3);
        queue1.enqueue(10);
        queue1.enqueue(20);

        StaticCircularQueue<int> queue2(3);
        queue2.enqueue(30);
        queue2.enqueue(40);

        queue1 = queue2;

        REQUIRE(queue1.peek() == 30);
        queue1.dequeue();
        REQUIRE(queue1.peek() == 40);
        queue1.dequeue();
        REQUIRE(queue1.is_empty());
    }

    SECTION("Handle large data") {
        StaticCircularQueue<int> queue(10000);
        for (int i = 0; i < 10000; i++) {
            queue.enqueue(i);
        }

        REQUIRE_FALSE(queue.is_empty());
        REQUIRE(queue.is_full());

        REQUIRE(queue.peek() == 0);
    }
}
