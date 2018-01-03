//
// Created by lorenz on 05.12.2017.
//
#include "gtest/gtest.h"
#include "../AVLTree/AVLTree.h"

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


    AVLTree *tree = new AVLTree();
    tree->insert(10);
    tree->insert(5);
    tree->insert(17);
    tree->insert(20);
    tree->insert(9);
    tree->insert(2);
    tree->insert(12);
    tree->insert(30);
    tree->insert(3);
    tree->insert(11);
    tree->insert(15);
    tree->insert(13);
    tree->insert(18);
    tree->insert(33);

    tree->remove(9);


    return 0;


}