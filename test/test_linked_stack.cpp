#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Stack/LinkedStack.hpp"

TEST_CASE("LinkedStack") {
    SECTION("Default Constructor") {
        LinkedStack<int> stack;
        REQUIRE(stack.size() == 0);
        REQUIRE(stack.is_empty());
    }

    SECTION("Push and Size") {
        LinkedStack<int> stack;
        stack.push_back(10);
        REQUIRE(stack.size() == 1);
        REQUIRE(!stack.is_empty());
        REQUIRE(stack.peek() == 10);

        stack.push_back(20);
        REQUIRE(stack.size() == 2);
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Pop and Size") {
        LinkedStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);
        REQUIRE(stack.size() == 2);

        stack.pop_back();
        REQUIRE(stack.size() == 1);
        REQUIRE(stack.peek() == 10);

        stack.pop_back();
        REQUIRE(stack.is_empty());
    }

    SECTION("Peek Access") {
        LinkedStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        REQUIRE(stack.peek() == 20);

        stack.pop_back();
        REQUIRE(stack.peek() == 10);
    }

    SECTION("Const Peek Access") {
        const LinkedStack<int> stack;
        LinkedStack<int> modifiableStack;
        modifiableStack.push_back(10);
        modifiableStack.push_back(20);

        REQUIRE(modifiableStack.peek() == 20);
    }

    SECTION("Is Empty Check") {
        LinkedStack<int> stack;
        REQUIRE(stack.is_empty());

        stack.push_back(10);
        REQUIRE(!stack.is_empty());

        stack.pop_back();
        REQUIRE(stack.is_empty());
    }

    SECTION("Copy Constructor") {
        LinkedStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        LinkedStack<int> copiedStack(stack);
        REQUIRE(copiedStack.size() == 2);
        REQUIRE(copiedStack.peek() == 20);
    }

    SECTION("Copy Assignment Operator") {
        LinkedStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        LinkedStack<int> copiedStack;
        copiedStack = stack;
        REQUIRE(copiedStack.size() == 2);
        REQUIRE(copiedStack.peek() == 20);
    }

    SECTION("Self Assignment") {
        LinkedStack<int> stack;
        stack.push_back(10);
        stack.push_back(20);

        stack = stack;
        REQUIRE(stack.size() == 2);
        REQUIRE(stack.peek() == 20);
    }

    SECTION("Multiple Push and Pop") {
        LinkedStack<int> stack;
        for (int i = 1; i <= 5; ++i) {
            stack.push_back(i);
        }

        REQUIRE(stack.size() == 5);

        for (int i = 5; i > 0; --i) {
            REQUIRE(stack.peek() == i);
            stack.pop_back();
        }

        REQUIRE(stack.is_empty());
    }

    SECTION("Copy Constructor with Empty Stack") {
        LinkedStack<int> stack;
        LinkedStack<int> copiedStack(stack);
        REQUIRE(copiedStack.is_empty());
    }

    SECTION("Copy Assignment Operator with Empty Stack") {
        LinkedStack<int> stack;
        LinkedStack<int> copiedStack;
        copiedStack = stack;
        REQUIRE(copiedStack.is_empty());
    }
}
