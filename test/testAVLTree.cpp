//
// Created by lorenz on 05.12.2017.
//

#include "testAVLTree.h"
#include <iostream>
#include "stdlib.h"

using namespace std;


TEST(AVLTest, Check_if_testing_works) {
    AVLTree tree;
    EXPECT_TRUE(tree.testTesting());
}


// empty tree
TEST(AVLTest, Test_EmptyList) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(nullptr, tree.preorder());
    EXPECT_EQ(nullptr, tree.inorder());
    EXPECT_EQ(nullptr, tree.postorder());
}

TEST(AVLTest, SearchTest_NoNodeInAVLTree) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(nullptr, tree.preorder());
    EXPECT_EQ(0, tree.search(6));
    EXPECT_EQ(nullptr, tree.inorder());
    EXPECT_EQ(0, tree.search(5));
    EXPECT_EQ(nullptr, tree.postorder());
    EXPECT_EQ(0, tree.search(7));
}

// insert and search
TEST(AVLTest, SearchTest_OneNodeInAVLTree) {
    AVLTree tree;
    tree.insert(3);
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(3));
    EXPECT_EQ(1, tree.search(3));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(3));
    EXPECT_EQ(0, tree.search(5));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(3));
    EXPECT_EQ(0, tree.search(7));
}

// search test two elements in AVLTree
TEST(AVLTest, SearchTest_TwoNodeInAVLTree) {
    AVLTree tree;
    tree.insert(2);
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(1, tree.search(2));
    tree.insert(3);
    EXPECT_EQ(1, tree.search(3));
    EXPECT_EQ(0, tree.search(5));
}

// insert two elements with same Key
TEST(AVLTest, InsertTest_TwoSameNodesInAVLTree) {
    AVLTree tree;
    tree.insert(4);
    tree.insert(4);
    EXPECT_EQ(1, tree.search(4));
}

TEST(AVLTest, Three_Nodes) {
    AVLTree tree;
    tree.insert(12213);
    tree.insert(215);
    tree.insert(123712);
    EXPECT_TRUE(tree.search(12213));
    EXPECT_TRUE(tree.search(123712));
    EXPECT_TRUE(tree.search(215));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(215, 123712, 12213));
}

TEST(AVLTest, Two_Nodes_Insert_Remove){
    AVLTree tree;
    tree.insert(94344);
    tree.insert(-2334);
    EXPECT_TRUE(tree.search(94344));
    EXPECT_TRUE(-2334);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(94344, -2334));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(-2334, 94344));
}

TEST(AVLTest, FiveThousand_Nodes_Insert){
    AVLTree tree;

    for(int i = 5; i < 5000; i++)
    {
        tree.insert(i);
    }

    for(int k = 0; k < 5; k++)
    {
        tree.insert(k);
    }

    for(int i = 0; i < 5000; i++)
    {
        EXPECT_TRUE(tree.search(i));
    }
}

TEST(AVLTest, One_Node_Insert_Remove){
    AVLTree tree;
    tree.insert(55789);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(55789));
    EXPECT_TRUE(tree.search(55789));
    tree.remove(tree.getRoot(), 55789);
    EXPECT_FALSE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
   EXPECT_FALSE(tree.search(-557));
}

TEST(AVLTest, Two_Node_Insert_Remove_SmallOne){
    AVLTree tree;
    tree.insert(55789);
    tree.insert(557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_TRUE(tree.search(557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, 557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    tree.remove(tree.getRoot(), 557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
}

TEST(AVLTest, Two_Node_Insert_Remove_BiggerOne){
    AVLTree tree;
    tree.insert(55789);
    tree.insert(557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_TRUE(tree.search(557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, 557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    tree.remove(tree.getRoot(), 55789);
    EXPECT_TRUE(tree.search(557));
    EXPECT_FALSE(tree.search(55789));
}


TEST(AVLTest, Two_Node_Insert_One_Negative_Remove_One){
    AVLTree tree;
      tree.insert(55789);
    tree.insert(-557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
    EXPECT_TRUE(tree.search(-557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, -557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(-557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(-557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(-557));
    tree.remove(tree.getRoot(), 55789);
    EXPECT_FALSE(tree.search(55789));
    EXPECT_TRUE(tree.search(-557));
}

TEST(AVLTest, Two_Node_Insert_Remove_Two){
    AVLTree tree;
    tree.insert(55789);
    tree.insert(557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_TRUE(tree.search(557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, 557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    tree.remove(tree.getRoot(), 557);
    tree.remove(tree.getRoot(), 55789);
    EXPECT_FALSE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
}

TEST(AVLTest, Two_Node_Insert_Remove_SameTwoTimes){
    AVLTree tree;
    tree.insert(55789);
    tree.insert(557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_TRUE(tree.search(557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, 557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    tree.remove(tree.getRoot(), 557);
    tree.remove(tree.getRoot(), 557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(557));
}

TEST(AVLTest, Two_Node_Insert_Remove_UnkownNode){
    AVLTree tree;
    tree.insert(55789);
    tree.insert(557);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_FALSE(tree.search(-557));
    EXPECT_TRUE(tree.search(557));
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(55789, 557));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(557, 55789));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(557, 55789));
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    tree.remove(tree.getRoot(), 400);
    EXPECT_TRUE(tree.search(55789));
    EXPECT_TRUE(tree.search(557));
    EXPECT_FALSE(tree.search(400));
}


TEST(AVLTest, Order_Of_Elemente_After_Root_Deletion){
    AVLTree tree;
    tree.insert(10);
    tree.insert(55);
    tree.insert(5);
    tree.insert(60);
    tree.insert(6);
    tree.insert(4);
    tree.insert(50);
    tree.insert(7);
    tree.insert(57);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 4, 6, 7, 55, 50, 60, 57));
    tree.remove(tree.getRoot(), 10);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(50, 5, 4, 6, 7, 57, 55, 60));
}

TEST(AVLTest, Order_Of_Elemente_After_Deletion_On_Left_Side){
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(17);
    tree.insert(20);
    tree.insert(9);
    tree.insert(2);
    tree.insert(12);
    tree.insert(3);

    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 3, 9, 17, 12, 20));
    tree.remove(tree.getRoot(), 9);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 3, 2, 5, 17, 12, 20));
}

TEST(AVLTest, Order_Of_Elemente_After_Deletion_On_Right_Side_with_Left_Right_Rotate){
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(55);
    tree.insert(2);
    tree.insert(40);
    tree.insert(57);
    tree.insert(43);

    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 55, 40, 43, 57));
    tree.remove(tree.getRoot(), 57);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 43, 40, 55));
}

TEST(AVLTest, Order_Of_Elemente_After_Deletion_On_Right_Side_with_Right_Rotate){
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(55);
    tree.insert(2);
    tree.insert(40);
    tree.insert(57);
    tree.insert(35);

    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 55, 40, 35, 57));
    tree.remove(tree.getRoot(), 57);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 40, 35, 55));
}

TEST(AVLTest, Order_Of_Elemente_After_Deletion_On_Right_Side_with_Left_Rotate){
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(55);
    tree.insert(2);
    tree.insert(40);
    tree.insert(57);
    tree.insert(60);

    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 55, 40, 57, 60));
    tree.remove(tree.getRoot(), 40);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 57, 55, 60));
}

TEST(AVLTest, Symfollower_Is_Right_Son){
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(55);
    tree.insert(2);
    tree.insert(40);
    tree.insert(57);


    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 55, 40, 57));
    tree.remove(tree.getRoot(), 55);
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(10, 5, 2, 57, 40));
}

TEST(AVLTest, Random_Node_Insert_Random_Remove){
    AVLTree tree;
    srand(time(NULL));
    int randInt = 0;
    for(int i = 0; i < 100; i++)
    {
        randInt = rand() % 1000;
        tree.insert(randInt);
        EXPECT_TRUE(tree.search(randInt));
    }
    for(int k = 0; k < 100; k++)
    {
        tree.search(rand() % 1000);
    }
    for(int m = 0; m < 100; m++)
    {
        randInt = rand() % 1000;
        tree.remove(tree.getRoot(), randInt);
        EXPECT_FALSE(tree.search(randInt));
    }

    for(int k = 0; k < 200; k++)
    {
        tree.search(rand() % 1000);
    }
}







