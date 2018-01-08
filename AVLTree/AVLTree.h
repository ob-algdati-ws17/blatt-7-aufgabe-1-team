//
// Created by lorenz on 05.12.2017.
//

#ifndef BLATT_7_AUFGABE_1_TEAM_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAM_AVLTREE_H

#include <vector>

using namespace std;


class AVLTree {
private:
    struct Node {
        Node *left;
        Node *right;
        Node *prev;
        int key;
        int balance;

        Node(const int);

        Node(const int, Node *, Node *);

        vector<int> *preorder() const; // Hauptreihenfolge
        vector<int> *inorder() const; // Symmetrische Reihenfolge
        vector<int> *postorder() const; // Nebenreihenfolge

    };

    Node *root = nullptr;

    /**
    * calculates the height of the (sub)tree
    */
    int height(Node *);

    /**
    * edits the balances after adding a new node
    */
    void calcBalance(Node *);

    /**
     * used for performing a left rotate
    */
    void rotateLeft(Node *);

    /**
     * used for performing a right rotate
     */
    void rotateRight(Node *);


    /**
     * checks if rotations are needed. Calls rotation functions if needed
     */
    void upin(Node *);

    /**
    * checks if rotations are needed after deletion
    */
    void upout(Node *, const int);


public:

    /**
     * verifies if the tree is empty. returns true if it's empty
     */
    bool isEmpty();

    /**
     * used to verify if googletests are working
     */
    bool testTesting();


    /**
     * returns true if a node with the given value is a node in the tree
     */
    bool search(const int) const;

    /**
     * entrypoint for insertion. adds the new node
     */
    void insert(const int);

    /**
     * entry point for deletion
     */
    void remove(const int);


    /**
     * returns the stored nodes in the tree
     */
    vector<int> *preorder() const; // Hauptreihenfolge

    /**
     * returns the stored nodes in the tree
    */
    vector<int> *inorder() const; // Symmetrische Reihenfolge

    /**
    * returns the stored nodes in the tree
    */
    vector<int> *postorder() const; // Nebenreihenfolge


};


#endif //BLATT_7_AUFGABE_1_TEAM_AVLTREE_H
