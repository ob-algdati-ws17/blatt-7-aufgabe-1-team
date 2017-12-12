//
// Created by lorenz on 05.12.2017.
//

#include "testAVLTree.h"
#include <iostream>

using namespace std;


TEST(AVLTest, Check_if_testing_works) {
    AVLTree tree;
    EXPECT_TRUE(tree.testTesting());
}

// empty list
TEST(AVLTest, Test_EmptyList) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
}

/*
TEST(AVLTest, SearchTest_NoElementInAVLTree) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(0, tree.search(6));
}
 */

// insert and search
TEST(AVLTest, SearchTest_OneElementInAVLTree) {
    AVLTree tree;
    tree.insert(3);
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(1, tree.search(3));
}

// search test two elements in AVLTree
TEST(AVLTest, SearchTest_TwoElementsInAVLTree) {
    AVLTree tree;
    tree.insert(2);
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(1, tree.search(2));
    tree.insert(3);
    EXPECT_EQ(1, tree.search(3));
    EXPECT_EQ(0, tree.search(5));
}

// insert two elements with same Key
TEST(AVLTest, InsertTest_TwoSameElementsInAVLTree) {
    AVLTree tree;
    tree.insert(4);
    tree.insert(4);
    EXPECT_EQ(1, tree.search(4));
}

