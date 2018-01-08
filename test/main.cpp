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
    tree->insert(55);
    tree->insert(2);
    tree->insert(40);
    tree->insert(57);
    tree->insert(43);



    vector <int> *i = tree->preorder();
    for (auto elem = i->begin(); elem != i->end(); elem++) {
        cout << *elem << endl;
    }

    tree->remove(57);



    cout << endl;
    i = tree->preorder();
    for (auto elem = i->begin(); elem != i->end(); elem++) {
        cout << *elem << endl;
    }

    return 0;





}