#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Stack/StaticStack.hpp"

TEST_CASE("StaticStack") {
    SECTION("Default Constructor") {
        StaticStack<int> stack;
        REQUIRE(stack.is_empty());
        REQUIRE(stack.is_full() == false);
    }

    SECTION("Push and Size") {
        StaticStack<int> stack;
        stack.push_back(10);
        REQUIRE(stack.peek() == 10);
        REQUIRE(stack.is_empty() == false);
        REQUIRE(stack.is_full() == false);
        
        stack.push_back(20);
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Pop and Size") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);
        REQUIRE(stack.peek() == 20);

        stack.pop_back();
        REQUIRE(stack.peek() == 10);
        REQUIRE(stack.is_full() == false);

        stack.pop_back();
        REQUIRE(stack.is_empty());
    }

    SECTION("Peek Access") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Const Peek Access") {
        StaticStack<int> modifiableStack;
        modifiableStack.push_back(10);
        modifiableStack.push_back(20);
        const StaticStack<int> stack = modifiableStack;
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Is Empty Check") {
        StaticStack<int> stack;
        REQUIRE(stack.is_empty());

        stack.push_back(10);
        REQUIRE(!stack.is_empty());

        stack.pop_back();
        REQUIRE(stack.is_empty());
    }

    SECTION("Is Full Check") {
        StaticStack<int> stack(2);
        REQUIRE(stack.is_full() == false);

        stack.push_back(10);
        stack.push_back(20);
        REQUIRE(stack.is_full() == true);

        stack.pop_back();
        REQUIRE(stack.is_full() == false);
    }

    SECTION("Copy Constructor") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        StaticStack<int> copiedStack(stack);
        REQUIRE(copiedStack.peek() == 20);
        REQUIRE(copiedStack.is_empty() == false);
        REQUIRE(copiedStack.is_full() == false);
    }

    SECTION("Copy Assignment Operator") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        StaticStack<int> copiedStack;
        copiedStack = stack;
        REQUIRE(copiedStack.peek() == 20);
        REQUIRE(copiedStack.is_empty() == false);
        REQUIRE(copiedStack.is_full() == false);
    }

    SECTION("Self Assignment") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        stack = stack;
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Size After Clear") {
        StaticStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);
        while (!stack.is_empty()) {
            stack.pop_back();
        }

        REQUIRE(stack.is_empty());
    }

    SECTION("Copy Constructor with Empty Stack") {
        StaticStack<int> stack;
        StaticStack<int> copiedStack(stack);
        REQUIRE(copiedStack.is_empty());
    }

    SECTION("Copy Assignment Operator with Empty Stack") {
        StaticStack<int> stack;
        StaticStack<int> copiedStack;
        copiedStack = stack;
        REQUIRE(copiedStack.is_empty());
    }
}
