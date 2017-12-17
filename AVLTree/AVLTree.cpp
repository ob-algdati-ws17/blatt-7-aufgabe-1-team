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

bool AVLTree::isEmpty() {
    if(root == nullptr)
        return true;
    else
        return false;

}

bool AVLTree::search(const int value) const {
    if(root == nullptr)
        return false;
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

int AVLTree::height(AVLTree::Node *node) {
    if(node== nullptr)
        return 0;
    else {
        auto left = height(node->left) + 1;
        auto right = height(node->right) + 1;
        if(right >= left)
            return right;
        else
            return left;
    }
}

void AVLTree::upin(AVLTree::Node *newElement) {
    auto pos = newElement;
    auto prevPos = newElement->prev;

    while(pos != root) {
        if(prevPos->balance == 2 && pos->balance == 1){
            rotateLeft(prevPos);

        }
        if(prevPos->balance == 2 && pos->balance == -1){
            rotateRight(pos);
            rotateLeft(prevPos);
        }
        if(prevPos->balance == -2 && pos->balance == 1){
            rotateLeft(pos);
            rotateRight(prevPos);
        }
        if(prevPos->balance == -2 && pos->balance == -1){
            rotateRight(prevPos);

        }
        prevPos = prevPos->prev;
        if(pos->prev != nullptr)
            pos = pos->prev;
        else
            break;
    }
}

void AVLTree::rotateLeft(AVLTree::Node *pos) {
    auto helper = pos->right;
    auto helper2 = helper->left;
    auto prevHelper = pos->prev;
    pos->right = helper2;
    if(helper2 != nullptr)
        helper2->prev = pos;

    helper->left = pos;
    if(pos != root) {
        if(prevHelper->right == pos)
            prevHelper->right = helper;
        else
            prevHelper->left = helper;
    }

    pos->prev = helper;


    if(pos == root) {
        helper->prev = nullptr;
        root = helper;
    } else {
        helper->prev = prevHelper;
    }

    helper->balance = height(helper->right) - height(helper->left);
    helper->right->balance = height(helper->right->right) - height(helper->right->left);
    helper->left->balance = height(helper->left->right) - height(helper->left->left);

}

void AVLTree::rotateRight(AVLTree::Node *pos) {
    auto helper = pos->left;
    auto helper2 = helper->right;
    auto prevHelper = pos->prev;
    pos->left = helper2;
    if(helper2 != nullptr)
        helper2->prev = pos;

    helper->right = pos;
    if(pos != root) {
        if(prevHelper->right == pos)
            prevHelper->right = helper;
        else
            prevHelper->left = helper;
    }
    pos->prev = helper;


    if(pos == root) {
        helper->prev = nullptr;
        root = helper;
    } else {
        helper->prev = prevHelper;
    }

    helper->right->balance = height(helper->right->right) - height(helper->right->left);
    helper->left->balance = height(helper->left->right) - height(helper->left->left);
    helper->balance = height(helper->right) - height(helper->left);
    auto balHelper = helper;
    while(balHelper != root) {
        balHelper->balance = height(balHelper->right) - height(balHelper->left);
        balHelper = balHelper->prev;
    }

    balHelper->balance = height(balHelper->right) - height(balHelper->left);
}

void AVLTree::remove(const int) {

}

/*
 * Traversal
 */

vector<int> *AVLTree::preorder() const {
    if(root == nullptr)
        return nullptr;
    return  root->preorder();
}

vector<int> *AVLTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if(left != nullptr){
        auto left_vec = left->preorder();
        vec->insert(vec->end(),left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if(right != nullptr){
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return  vec;
}

vector<int> *AVLTree::inorder() const {
    if(root == nullptr)
        return nullptr;
    return  root->inorder();
}

vector<int> *AVLTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if(left != nullptr){
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec-> begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if(right != nullptr){
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::postorder() const {
    if(root == nullptr)
        return nullptr;
    return  root->postorder();
}

vector<int> *AVLTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfoger in vec
    if(left != nullptr){
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if(right != nullptr){
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }

    // Wurzel in vec
    vec->push_back(key);
    return  vec;
}