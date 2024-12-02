#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Queue/Deque.hpp" // Adjust the include path as per your project structure

TEST_CASE("Deque") {
    SECTION("Constructor creates an empty deque") {
        Deque<int> deque;
        REQUIRE(deque.size() == 0);
        REQUIRE(deque.empty() == true);
    }

    SECTION("push_back adds elements to the back") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        REQUIRE(deque.size() == 3);
        REQUIRE(deque.back() == 3);
    }

    SECTION("push_front adds elements to the front") {
        Deque<int> deque;
        deque.push_front(1);
        deque.push_front(2);
        deque.push_front(3);

        REQUIRE(deque.size() == 3);
        REQUIRE(deque.front() == 3);
    }

    SECTION("pop_back removes elements from the back") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        deque.pop_back();

        REQUIRE(deque.size() == 2);
        REQUIRE(deque.back() == 2);
    }

    SECTION("pop_front removes elements from the front") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        deque.pop_front();

        REQUIRE(deque.size() == 2);
        REQUIRE(deque.front() == 2);
    }

    SECTION("front returns the first element") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);

        REQUIRE(deque.front() == 1);
    }

    SECTION("back returns the last element") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);

        REQUIRE(deque.back() == 2);
    }

    SECTION("size returns the correct number of elements") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        REQUIRE(deque.size() == 3);
    }

    SECTION("empty checks if the deque is empty") {
        Deque<int> deque;

        REQUIRE(deque.empty() == true);

        deque.push_back(1);
        REQUIRE(deque.empty() == false);
    }

    SECTION("supports multiple types") {
        Deque<std::string> deque;
        deque.push_back("Hello");
        deque.push_front("World");

        REQUIRE(deque.size() == 2);
        REQUIRE(deque.front() == "World");
        REQUIRE(deque.back() == "Hello");
    }

    SECTION("supports bidirectional traversal") {
        Deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        REQUIRE(deque.front() == 1);
        deque.pop_front();
        REQUIRE(deque.front() == 2);

        REQUIRE(deque.back() == 3);
        deque.pop_back();
        REQUIRE(deque.back() == 2);
    }

    SECTION("assignment operator assigns correctly") {
        Deque<int> deque1;
        deque1.push_back(1);
        deque1.push_back(2);
        deque1.push_back(3);

        Deque<int> deque2;
        deque2 = deque1;

        REQUIRE(deque2.size() == 3);
        REQUIRE(deque2.front() == 1);
        REQUIRE(deque2.back() == 3);
    }

    SECTION("copy constructor copies elements correctly") {
        Deque<int> deque1;
        deque1.push_back(1);
        deque1.push_back(2);
        deque1.push_back(3);

        Deque<int> deque2 = deque1;

        REQUIRE(deque2.size() == 3);
        REQUIRE(deque2.front() == 1);
        REQUIRE(deque2.back() == 3);
    }
}
