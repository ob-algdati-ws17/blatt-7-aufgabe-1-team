//
// Created by lorenz on 05.12.2017.
//

#include "AVLTree.h"

bool AVLTree::testTesting() {
    return true;
}

AVLTree::Node::Node(const int k) : key(k) {}

AVLTree::Node::Node(const int k, AVLTree::Node *l, AVLTree::Node *r) : key(k), left(l), right(r) {}

AVLTree::~BinTree() {

}

bool AVLTree::search(const int value) const {
    if(root->key == value)
        return true;

    auto pos = root;

    while (true) {
        if (value < pos->key) {
            if (pos->left == nullptr)
                return false;
            else
                pos = pos->left;
        } else {
            if (pos->right == nullptr)
                return false;
            else
                pos = pos->right;
        }
        if (pos->key == value)
            return true;

    }
}

void AVLTree::insert(const int) {

}

void AVLTree::remove(const int) {

}
