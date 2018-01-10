//
// Created by lorenz on 05.12.2017.
//
#include "gtest/gtest.h"
#include "../AVLTree/AVLTree.h"
#include "stdlib.h"

int main(int argc, char **argv) {


    AVLTree *tree = new AVLTree();

    tree->insert(136);
    tree->insert(973);
    tree->insert(608);
    tree->insert(474);
    tree->insert(410);
    tree->insert(318);
    tree->insert(194);
    tree->insert(150);
    tree->insert(759);
    tree->insert(875);

    tree->remove(875);
    tree->remove(474);

    return 0;
/*
    srand(time(NULL));

    auto randInt = rand() % 1000;;
    AVLTree *tree = new AVLTree();
    for(int i = 0; i < 10; i++)
    {
        randInt = rand() % 1000;
        cout << randInt << endl;
        tree->insert(randInt);

    }
    cout << endl;
    for(int m = 0; m < 200; m++)
    {
        randInt = rand() % 1000;
        cout << randInt << endl;
        tree->remove(randInt);

    }

*/






}