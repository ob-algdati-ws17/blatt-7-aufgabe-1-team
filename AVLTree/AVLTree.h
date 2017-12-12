//
// Created by lorenz on 05.12.2017.
//

#ifndef BLATT_7_AUFGABE_1_TEAM_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAM_AVLTREE_H


class AVLTree {
private:
    struct Node{
        Node *left;
        Node *right;
        Node *prev;
        int key;
        int balance;

        Node(const int);
        Node(const int, Node *, Node *);

    };

    Node *root = nullptr;

public:

    bool isEmpty();

    bool testTesting();

    void calcBalance(Node*);

    void upin(Node*);

    void rotateLeft(Node*);

    void rotateRight(Node*);

    bool search(const int) const;

    void insert(const int);

    void remove(const int);
};


#endif //BLATT_7_AUFGABE_1_TEAM_AVLTREE_H
