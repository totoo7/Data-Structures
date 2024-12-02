#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "LinkedList/LinkedList.hpp"

TEST_CASE("LinkedList") {
    SECTION("Default constructor") {
        LinkedList<int> list;
        REQUIRE(list.is_empty());
        REQUIRE(list.size() == 0);
    }

    SECTION("push_front and front") {
        LinkedList<int> list;
        list.push_front(10);
        REQUIRE_FALSE(list.is_empty());
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 10);

        list.push_front(20);
        REQUIRE(list.front() == 20);
        REQUIRE(list.size() == 2);
    }

    SECTION("push_end and back") {
        LinkedList<int> list;
        list.push_end(30);
        REQUIRE_FALSE(list.is_empty());
        REQUIRE(list.size() == 1);
        REQUIRE(list.back() == 30);

        list.push_end(40);
        REQUIRE(list.back() == 40);
        REQUIRE(list.size() == 2);
    }

    SECTION("push_at") {
        LinkedList<int> list;
        list.push_end(10);
        list.push_end(20);
        list.push_end(40);

        list.push_at(2, 30); // Insert at index 2
        REQUIRE(list.size() == 4);
        REQUIRE(list.at(2) == 30);
        REQUIRE(list.back() == 40);
    }

    SECTION("pop_front and is_empty") {
        LinkedList<int> list;
        list.push_front(10);
        list.push_front(20);
        REQUIRE(list.size() == 2);

        list.pop_front();
        REQUIRE(list.front() == 10);
        REQUIRE(list.size() == 1);

        list.pop_front();
        REQUIRE(list.is_empty());
        REQUIRE(list.size() == 0);
    }

    SECTION("pop_end") {
        LinkedList<int> list;
        list.push_end(10);
        list.push_end(20);
        REQUIRE(list.size() == 2);

        list.pop_end();
        REQUIRE(list.back() == 10);
        REQUIRE(list.size() == 1);

        list.pop_end();
        REQUIRE(list.is_empty());
        REQUIRE(list.size() == 0);
    }

 SECTION("Iterator begins at the first element") {
        LinkedList<int> list;
        list.push_end(1);
        list.push_end(2);
        list.push_end(3);

        auto it = list.begin();
        REQUIRE(*it == 1);
    }

    SECTION("Incrementing iterator through the list") {
        LinkedList<int> list;
        list.push_end(1);
        list.push_end(2);
        list.push_end(3);

        auto it = list.begin();
        REQUIRE(*it == 1);

        ++it;
        REQUIRE(*it == 2);

        ++it;
        REQUIRE(*it == 3);

        // ++it;
        // REQUIRE(it == list.end());
    }

    SECTION("Iterator comparison (== and !=)") {
        LinkedList<int> list;
        list.push_end(1);
        list.push_end(2);

        auto it = list.begin();
        auto endIt = list.end();

        REQUIRE(it != endIt); // Iterator should not be at end
        ++it; // Move to the second element
        REQUIRE(it != endIt); // Still not at the end

        ++it; // Move to end()
        REQUIRE(it == endIt); // Should now be at end
    }

    SECTION("Empty list iterator behaves correctly") {
        LinkedList<int> list;
        auto it = list.begin();
        auto endIt = list.end();

        REQUIRE(it == endIt); // For an empty list, begin() == end()
    }

    SECTION("Const iterator supports read-only access") {
        LinkedList<int> list;
        list.push_end(1);
        list.push_end(2);
        list.push_end(3);

        const LinkedList<int>& constList = list;
        auto it = constList.c_begin();

        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
    }

    SECTION("Iterator traversal with multiple operations") {
        LinkedList<int> list;
        list.push_end(1);
        list.push_end(2);
        list.push_end(3);
        list.push_end(4);

        auto it = list.begin();
        REQUIRE(*it == 1);

        ++it;
        REQUIRE(*it == 2);

        ++it;
        REQUIRE(*it == 3);

        ++it;
        REQUIRE(*it == 4);

        ++it;
        REQUIRE(it == list.end());
    }

    SECTION("Const iterator with a single element list") {
        LinkedList<int> list;
        list.push_end(42);

        const LinkedList<int>& constList = list;
        auto it = constList.c_begin();

        REQUIRE(*it == 42);
        ++it;
        REQUIRE(it == constList.c_end());
    }

    SECTION("Copy constructor") {
        LinkedList<int> list1;
        list1.push_end(10);
        list1.push_end(20);

        LinkedList<int> list2 = list1;
        REQUIRE(list2.size() == list1.size());
        REQUIRE(list2.front() == list1.front());
        REQUIRE(list2.back() == list1.back());
    }

    SECTION("Assignment operator") {
        LinkedList<int> list1;
        list1.push_end(10);
        list1.push_end(20);

        LinkedList<int> list2;
        list2 = list1;

        REQUIRE(list2.size() == list1.size());
        REQUIRE(list2.front() == list1.front());
        REQUIRE(list2.back() == list1.back());
    }
}