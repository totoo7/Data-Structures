#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "LinkedQueue.hpp"

TEST_CASE("LinkedQueue") {
    LinkedQueue<int> queue;

    SECTION("Queue should be empty initially") {
        REQUIRE(queue.empty() == true);
    }

    SECTION("Enqueue should add elements to the queue and peek should return the front element") {
        queue.enqueue(10);
        REQUIRE(queue.empty() == false);
        REQUIRE(queue.peek() == 10);

        queue.enqueue(20);
        REQUIRE(queue.peek() == 10);
    }

    SECTION("Dequeue should remove the front element from the queue") {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.dequeue();
        REQUIRE(queue.peek() == 20);

        queue.dequeue();
        REQUIRE(queue.empty() == true);
    }

    SECTION("Peek (const version) should return the front element without modifying the queue") {
        queue.enqueue(10);
        queue.enqueue(20);
        const LinkedQueue<int>& constQueue = queue;
        REQUIRE(constQueue.peek() == 10);
    }

    SECTION("Copy constructor should create a deep copy of the queue") {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        
        LinkedQueue<int> queueCopy(queue);
        REQUIRE(queueCopy.peek() == 10);
        queueCopy.dequeue();
        REQUIRE(queueCopy.peek() == 20);
    }

    SECTION("Copy assignment operator should copy the contents of another queue") {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        
        LinkedQueue<int> queueAssigned;
        queueAssigned = queue;
        REQUIRE(queueAssigned.peek() == 10);
        queueAssigned.dequeue();
        REQUIRE(queueAssigned.peek() == 20);
    }

    SECTION("Enqueue and dequeue single element") {
        queue.enqueue(42);
        REQUIRE(queue.peek() == 42);
        queue.dequeue();
        REQUIRE(queue.empty() == true);
    }

    SECTION("Enqueue and dequeue multiple elements") {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);

        REQUIRE(queue.peek() == 10);
        queue.dequeue();
        REQUIRE(queue.peek() == 20);

        queue.dequeue();
        REQUIRE(queue.peek() == 30);
        queue.dequeue();
        REQUIRE(queue.peek() == 40);

        queue.dequeue();
        REQUIRE(queue.empty() == true);
    }

    SECTION("Enqueueing same element multiple times") {
        queue.enqueue(50);
        queue.enqueue(50);
        queue.enqueue(50);
        REQUIRE(queue.peek() == 50);

        queue.dequeue();
        REQUIRE(queue.peek() == 50);

        queue.dequeue();
        REQUIRE(queue.peek() == 50);

        queue.dequeue();
        REQUIRE(queue.empty() == true);
    }
}