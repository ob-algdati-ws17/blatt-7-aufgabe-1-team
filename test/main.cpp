//
// Created by lorenz on 05.12.2017.
//
#include "gtest/gtest.h"
#include "../AVLTree/AVLTree.h"

int main(int argc, char **argv) {



    AVLTree *tree = new AVLTree();
    tree->insert(5);
    tree->insert(6);
    tree->insert(13);

    return 0;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}