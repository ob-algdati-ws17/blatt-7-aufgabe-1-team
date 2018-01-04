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
    tree->insert(55);
    tree->insert(5);
    tree->insert(60);
    tree->insert(6);
    tree->insert(4);
    tree->insert(50);
    tree->insert(7);
    tree->insert(57);


    tree->remove(10);

    return 0;

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





}