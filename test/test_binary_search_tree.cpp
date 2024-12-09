#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Tree/BinarySearchTree.hpp"

TEST_CASE("BinarySearchTree") {
    SECTION("Default Constructor and Empty Tree") {
        BinarySearchTree<int> bst;
        REQUIRE_FALSE(bst.find(10));
    }

    SECTION("Insert and Find") {
        BinarySearchTree<int> bst;
        bst.insert(10);
        REQUIRE(bst.find(10));
        bst.insert(10);
        REQUIRE_FALSE(bst.find(20));
    }

    SECTION("Remove") {
        BinarySearchTree<int> bst;
        REQUIRE_FALSE(bst.remove(10));

        bst.insert(10);
        bst.insert(5);
        bst.insert(20);

        REQUIRE(bst.remove(5));
        REQUIRE_FALSE(bst.find(5));

        REQUIRE(bst.remove(10));
        REQUIRE_FALSE(bst.find(10));

        REQUIRE(bst.remove(20));
        REQUIRE_FALSE(bst.find(20));
    }

    SECTION("Tree Height") {
        BinarySearchTree<int> bst;
        REQUIRE(bst.height() == 0);

        bst.insert(10);
        REQUIRE(bst.height() == 1);

        bst.insert(5);
        bst.insert(20);
        REQUIRE(bst.height() == 2);

        bst.insert(3);
        REQUIRE(bst.height() == 3);
    }

    SECTION("Print Tree (In-Order Traversal)") {
        BinarySearchTree<int> bst;
        std::ostringstream oss;
        auto original_cout = std::cout.rdbuf(oss.rdbuf());

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);

        bst.print();
        std::cout.rdbuf(original_cout);

        REQUIRE(oss.str() == "5 10 15 ");
    }

    SECTION("Copy constructor") {
        BinarySearchTree<int> tree1;
        tree1.insert(10);
        tree1.insert(5);
        tree1.insert(15);
        tree1.insert(3);
        tree1.insert(7);
        tree1.insert(12);
        tree1.insert(17);

        BinarySearchTree<int> tree2(tree1);

        REQUIRE(tree2.find(10) == true);
        REQUIRE(tree2.find(5) == true);
        REQUIRE(tree2.find(15) == true);
        REQUIRE(tree2.find(3) == true);
        REQUIRE(tree2.find(7) == true);
        REQUIRE(tree2.find(12) == true);
        REQUIRE(tree2.find(17) == true);

        tree2.insert(20);
        REQUIRE(tree2.find(20) == true);
        REQUIRE(tree1.find(20) == false);

        tree2.remove(15);
        REQUIRE(tree2.find(15) == false);
        REQUIRE(tree1.find(15) == true);
    }

    SECTION("Assignment Operator") {
        BinarySearchTree<int> bst1;
        bst1.insert(10);
        bst1.insert(5);

        BinarySearchTree<int> bst2;
        bst2.insert(20);

        bst2 = bst1;

        REQUIRE(bst2.find(10));
        REQUIRE(bst2.find(5));
        REQUIRE_FALSE(bst2.find(20));

        bst1.remove(10);
        REQUIRE(bst2.find(10));
    }

    SECTION("Destructor") {
        BinarySearchTree<int>* bst = new BinarySearchTree<int>();
        bst->insert(10);
        delete bst;
    }
}