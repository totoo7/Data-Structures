#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Vector/Vector.hpp"

TEST_CASE("Vector") {
    SECTION("Default Constructor") {
        Vector<int> vec;
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());
    }

    SECTION("Push Back and Size") {
        Vector<int> vec;
        vec.push_back(10);
        REQUIRE(vec.size() == 1);
        REQUIRE(!vec.empty());
        REQUIRE(vec[0] == 10);

        vec.push_back(20);
        REQUIRE(vec.size() == 2);
        REQUIRE(vec[1] == 20);
    }

    SECTION("Pop Back") {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        REQUIRE(vec.size() == 2);

        vec.pop_back();
        REQUIRE(vec.size() == 1);
        REQUIRE(vec.back() == 10);

        vec.pop_back();
        REQUIRE(vec.empty());
    }

    SECTION("Front and Back Access") {
        Vector<std::string> vec;
        vec.push_back("first");
        vec.push_back("last");

        REQUIRE(vec.front() == "first");
        REQUIRE(vec.back() == "last");
    }

    SECTION("Contains Function") {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);

        REQUIRE(vec.contains(10));
        REQUIRE(!vec.contains(30));
    }

    SECTION("Copy Constructor") {
        Vector<int> vec1;
        vec1.push_back(10);
        vec1.push_back(20);

        Vector<int> vec2(vec1);
        REQUIRE(vec2.size() == 2);
        REQUIRE(vec2[0] == 10);
        REQUIRE(vec2[1] == 20);
    }

    SECTION("Copy Assignment Operator") {
        Vector<int> vec1;
        vec1.push_back(10);
        vec1.push_back(20);

        Vector<int> vec2;
        vec2 = vec1;

        REQUIRE(vec2.size() == 2);
        REQUIRE(vec2[0] == 10);
        REQUIRE(vec2[1] == 20);
    }

    SECTION("Operator[] Access") {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);

        REQUIRE(vec[0] == 10);
        REQUIRE(vec[1] == 20);

        vec[0] = 30;
        REQUIRE(vec[0] == 30);
    }

    SECTION("Iterator Functionality") {
        Vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        auto it = vec.begin();
        REQUIRE(*it == 1);

        ++it;
        REQUIRE(*it == 2);

        it++;
        REQUIRE(*it == 3);

        REQUIRE(it != vec.end());
        ++it;
        REQUIRE(it == vec.end());
    }
     SECTION("operator* dereference") {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        auto it = vec.begin();
        REQUIRE(*it == 10);
        
        ++it;
        REQUIRE(*it == 20);
        
        ++it;
        REQUIRE(*it == 30);
    }

    SECTION("Dynamic Resizing") {
        Vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i);
        }

        REQUIRE(vec.size() == 10);
        for (int i = 0; i < 10; ++i) {
            REQUIRE(vec[i] == i);
        }
    }
}