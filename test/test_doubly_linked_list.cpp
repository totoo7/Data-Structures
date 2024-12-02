#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "LinkedList/DoublyLinkedList.hpp"

TEST_CASE("DoublyLinkedList") {
    SECTION("Constructor creates an empty list") {
        DoublyLinkedList<int> list;
        REQUIRE(list.size() == 0);
        REQUIRE(list.empty() == true);
    }

    SECTION("push_back adds elements to the back") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        REQUIRE(list.size() == 3);
        REQUIRE(list.back() == 3);
    }

    SECTION("push_front adds elements to the front") {
        DoublyLinkedList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);

        REQUIRE(list.size() == 3);
        REQUIRE(list.front() == 3);
    }

    SECTION("pop_back removes elements from the back") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        list.pop_back();

        REQUIRE(list.size() == 2);
        REQUIRE(list.back() == 2);
    }

    SECTION("pop_front removes elements from the front") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        list.pop_front();

        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 2);
    }

    SECTION("insert inserts elements at a specific position") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(3);

        auto it = list.begin();
        ++it;
        list.insert(it, 2);

        REQUIRE(list.size() == 3);
        REQUIRE(list.front() == 1);
        REQUIRE(list.back() == 3);
        REQUIRE(*(++list.begin()) == 2);
    }

    SECTION("remove removes elements at a specific position") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        auto it = list.begin();
        ++it;
        list.remove(it);

        REQUIRE(list.size() == 2);
        REQUIRE(*(list.begin()) == 1);
        REQUIRE(*(++list.begin()) == 3);
    }

    SECTION("front returns the first element") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);

        REQUIRE(list.front() == 1);
    }

    SECTION("back returns the last element") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);

        REQUIRE(list.back() == 2);
    }

    SECTION("size returns the correct number of elements") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        REQUIRE(list.size() == 3);
    }

    SECTION("empty checks if the list is empty") {
        DoublyLinkedList<int> list;

        REQUIRE(list.empty() == true);

        list.push_back(1);
        REQUIRE(list.empty() == false);
    }

    SECTION("begin returns an iterator to the first element") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);

        auto it = list.begin();
        REQUIRE(*it == 1);
    }

    SECTION("end returns an iterator to the sentinel node") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);

        auto it = list.end();
        REQUIRE(it == list.end());
    }

    SECTION("iterator moves correctly") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        auto it = list.begin();
        REQUIRE(*it == 1);

        ++it;
        REQUIRE(*it == 2);

        ++it;
        REQUIRE(*it == 3);

        --it;
        REQUIRE(*it == 2);

        --it;
        REQUIRE(*it == 1);
    }

    SECTION("copy constructor copies elements correctly") {
        DoublyLinkedList<int> list1;
        list1.push_back(1);
        list1.push_back(2);
        list1.push_back(3);

        DoublyLinkedList<int> list2 = list1;

        REQUIRE(list2.size() == 3);
        REQUIRE(list2.front() == 1);
        REQUIRE(list2.back() == 3);
    }

    SECTION("assignment operator assigns correctly") {
        DoublyLinkedList<int> list1;
        list1.push_back(1);
        list1.push_back(2);
        list1.push_back(3);

        DoublyLinkedList<int> list2;
        list2 = list1;

        REQUIRE(list2.size() == 3);
        REQUIRE(list2.front() == 1);
        REQUIRE(list2.back() == 3);
    }

    SECTION("destructor frees memory correctly") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        REQUIRE_NOTHROW(list.pop_back());
    }

    SECTION("supports multiple types") {
        DoublyLinkedList<std::string> list;
        list.push_back("Hello");
        list.push_back("World");

        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == "Hello");
        REQUIRE(list.back() == "World");
    }

    SECTION("iterator equality checks") {
        DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);

        auto it1 = list.begin();
        auto it2 = list.begin();
        auto it3 = list.end();

        REQUIRE(it1 == it2);
        REQUIRE(it1 != it3);
    }
}
