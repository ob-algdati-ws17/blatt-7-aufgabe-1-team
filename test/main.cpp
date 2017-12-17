//
// Created by lorenz on 05.12.2017.
//
#include "gtest/gtest.h"
#include "../AVLTree/AVLTree.h"

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    AVLTree *tree = new AVLTree();
    tree->insert(5);
    tree->insert(6);
    tree->insert(13);
    tree->insert(12);
    tree->insert(11);
    tree->insert(10);


    return 0;


}