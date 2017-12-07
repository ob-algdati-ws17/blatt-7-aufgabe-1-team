//
// Created by lorenz on 05.12.2017.
//

#include "AVLTree.h"

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
        root->height = 1;
        return ;
    }

    while (true) {
        if (pos->key == value)
            return;
        if (value < pos->key) {
            if (pos->left == nullptr) {
                auto newNode = new Node(value);
                newNode->height = 1;
                newNode->prev = pos;
                pos->left = newNode;
                if(newNode->prev->right == nullptr) {
                    auto helperPos = newNode->prev;
                    while(helperPos != root) {
                        helperPos->height++;
                        helperPos = helperPos->prev;
                    }
                    helperPos->height++;
                }
                return;
            }
            pos = pos->left;
        } else {
            if (pos->right == nullptr) {
                auto newNode = new Node(value);
                newNode->height = 1;
                newNode->prev = pos;
                pos->right = newNode;
                if(newNode->prev->left == nullptr) {
                    auto helperPos = newNode->prev;
                    while(helperPos != root) {
                        helperPos->height++;
                        helperPos = helperPos->prev;
                    }
                    helperPos->height++;
                }
                return;
            }
            pos = pos->right;
        }
    }
}

void AVLTree::remove(const int) {

}
