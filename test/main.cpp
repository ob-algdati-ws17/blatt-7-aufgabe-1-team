//
// Created by lorenz on 05.12.2017.
//
#include "gtest/gtest.h"
#include "../AVLTree/AVLTree.h"
#include "stdlib.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    AVLTree *tree = new AVLTree();

    int randInt = 0;
    for(int i = 0; i < 200; i++)
    {
        randInt = rand() % 1000;
        tree->insert(randInt);

    }

    for(int m = 0; m < 200; m++)
    {
        randInt = rand() % 1000;
        tree->remove(tree->getRoot(), randInt);

    }

    return 0;



    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();












}