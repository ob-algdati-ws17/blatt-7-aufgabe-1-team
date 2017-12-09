//
// Created by lorenz on 05.12.2017.
//

#include "AVLTree.h"
#include <iostream>

bool AVLTree::testTesting() {
    return true;
}

AVLTree::Node::Node(const int k) : key(k), left(nullptr), right(nullptr), prev(nullptr) {}

AVLTree::Node::Node(const int k, AVLTree::Node *l, AVLTree::Node *r) : key(k), left(l), right(r) {}



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

void AVLTree::insert(const int value) {
    auto pos = root;

    if(root == nullptr) {
        auto newNode = new Node(value);
        root = newNode;
        root->balance = 0;
        return ;
    }

    while (true) {
        if (pos->key == value)
            return;
        if (value < pos->key) {
            if (pos->left == nullptr) {
                auto newNode = new Node(value);
                newNode->prev = pos;
                pos->left = newNode;
                newNode->balance = 0;
                calcBalance(pos->left);
            }
            pos = pos->left;
        } else {
            if (pos->right == nullptr) {
            auto newNode = new Node(value);
            newNode->prev = pos;
            pos->right = newNode;
            newNode->balance = 0;
            calcBalance(pos->right);
            }
            pos = pos->right;
        }
    }
}

void AVLTree::calcBalance(AVLTree::Node *newElement) {
    auto pos = newElement;
    while(pos != root) {
        if (pos == pos->prev->left) {
            pos->prev->balance--;
        } else {
            pos->prev->balance++;
        }
        if(pos->prev->balance == 0)
            break;
        pos = pos->prev;
    }
    upin(newElement);
}

void AVLTree::upin(AVLTree::Node *newElement) {

}

void AVLTree::remove(const int) {

}
