//
// Created by lorenz on 05.12.2017.
//

#include "AVLTree.h"
#include <iostream>

/**
 * Just a function to check if Googletests are working
 */
bool AVLTree::testTesting() {
    return true;
}

AVLTree::Node::Node(const int k) : key(k), left(nullptr), right(nullptr), prev(nullptr) {}

AVLTree::Node::Node(const int k, AVLTree::Node *l, AVLTree::Node *r) : key(k), left(l), right(r) {}

/**
 *  Checks if the tree is empty
 * @return true if the tree is empty and false if there is at least one element
 */

bool AVLTree::isEmpty() {
    return root == nullptr;
}

/**
 * Used for testing the balance of every node.
 * @param root -> the root element the balance is checked
 * @return -> true if every balance is <2 and >-2
 */
bool AVLTree::checkBalance(Node *root) {
    {
        int lh; /* for height of left subtree */
        int rh; /* for height of right subtree */

        /* If tree is empty then return true */
        if (root == NULL)
            return 1;

        /* Get the height of left and right sub trees */
        lh = height(root->left);
        rh = height(root->right);

        if (abs(lh - rh) <= 1 &&
            checkBalance(root->left) &&
            checkBalance(root->right))
            return 1;

        /* If we reach here then tree is not height-balanced */
        return 0;
    }
}

/**
 * returns the root of the tree
 * @return the root nde
 */
AVLTree::Node *AVLTree::getRoot() {
    return root;
}

/**
 * searches for a given value. If it is found in the tree true is beeing returned
 * @param value -> the value to search for
 * @return true if found and false if not
 */


bool AVLTree::search(const int value) const {
    if (root == nullptr)
        return false;
    if (root->key == value)
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

/////////////////////////////////////////////////////////////////////////
/////////                    Insert                             /////////
/////////////////////////////////////////////////////////////////////////

/**
 * The start of the insert routine.
 * At first the position pointer is moved through the tree. It's aim is to reach
 * the place where the new Node will be added.
 * If the right position is found the node gets added and the balances of the tree will be calculated
 * @param value -> the key to add to the AVL Tree
 */


void AVLTree::insert(const int value) {
    auto pos = root;

    if (root == nullptr) {
        auto newNode = new Node(value);
        root = newNode;
        root->balance = 0;
        return;
    }

    while (true) {
        if (pos == nullptr || pos->key == value)
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

/**
 * This method is called after the new Node is added.
 * The positionpointer runs from the new Node to the root.
 * Depending of the side (right or left) the positionpointer is coming
 * the balance will be increased or decreased by 1
 * @param newElement -> the newly added element
 */

void AVLTree::calcBalance(AVLTree::Node *newElement) {
    auto pos = newElement;
    while (pos != root) {
        if (pos == pos->prev->left) {
            pos->prev->balance--;
        } else {
            pos->prev->balance++;
        }
        if (pos->prev->balance == 0)
            break;
        pos = pos->prev;
    }
    upin(newElement);
}

/**
 * Used to get the height of the left and the right son
 * @param node -> element the height should be calculated at
 * @return the height of element
 */
int AVLTree::height(AVLTree::Node *node) {
    if (node == nullptr)
        return 0;
    else {
        auto left = height(node->left) + 1;
        auto right = height(node->right) + 1;
        if (right >= left)
            return right;
        else
            return left;
    }
}

/**
 * checks if the tree is a valid AVL tree.
 * depending of the balances rotations are called
 * @param newElement -> the newly added element
 */
void AVLTree::upin(AVLTree::Node *newElement) {
    auto pos = newElement;
    auto prevPos = newElement->prev;

    while (pos != root) {
        if (prevPos->balance == 2 && pos->balance == 1) {
            rotateLeft(prevPos);

        }
        if (prevPos->balance == 2 && pos->balance == -1) {
            rotateRight(pos);
            rotateLeft(prevPos);
        }
        if (prevPos->balance == -2 && pos->balance == 1) {
            rotateLeft(pos);
            rotateRight(prevPos);
        }
        if (prevPos->balance == -2 && pos->balance == -1) {
            rotateRight(prevPos);

        }
        prevPos = prevPos->prev;
        if (pos->prev != nullptr)
            pos = pos->prev;
        else
            break;
    }
}

/**
 *  makes a left rotate
 * afterwards the heights are checked and balances are calculated
 * @param pos -> the node to rotate
 */

void AVLTree::rotateLeft(AVLTree::Node *pos) {
    auto helper = pos->right;
    auto helper2 = helper->left;
    auto prevHelper = pos->prev;
    pos->right = helper2;
    if (helper2 != nullptr)
        helper2->prev = pos;

    helper->left = pos;
    if (pos != root) {
        if (prevHelper->right == pos)
            prevHelper->right = helper;
        else
            prevHelper->left = helper;
    }

    pos->prev = helper;


    if (pos == root) {
        helper->prev = nullptr;
        root = helper;
    } else {
        helper->prev = prevHelper;
    }

    if (helper->right != nullptr)
        helper->right->balance = height(helper->right->right) - height(helper->right->left);

    if (helper->left != nullptr)
        helper->left->balance = height(helper->left->right) - height(helper->left->left);
    helper->balance = height(helper->right) - height(helper->left);
    auto balHelper = helper;
    while (balHelper != root) {
        balHelper->balance = height(balHelper->right) - height(balHelper->left);
        balHelper = balHelper->prev;
    }

    balHelper->balance = height(balHelper->right) - height(balHelper->left);

}

/**
 * makes a right rotate
 * afterwards the heights are checked and balances are calculated
 * @param pos -> the node to rotate
 */
void AVLTree::rotateRight(AVLTree::Node *pos) {
    auto helper = pos->left;
    auto helper2 = helper->right;
    auto prevHelper = pos->prev;
    pos->left = helper2;
    if (helper2 != nullptr)
        helper2->prev = pos;

    helper->right = pos;
    if (pos != root) {
        if (prevHelper->right == pos)
            prevHelper->right = helper;
        else
            prevHelper->left = helper;
    }
    pos->prev = helper;


    if (pos == root) {
        helper->prev = nullptr;
        root = helper;
    } else {
        helper->prev = prevHelper;
    }

    if (helper->right != nullptr)
        helper->right->balance = height(helper->right->right) - height(helper->right->left);

    if (helper->left != nullptr)
        helper->left->balance = height(helper->left->right) - height(helper->left->left);
    helper->balance = height(helper->right) - height(helper->left);
    auto balHelper = helper;
    while (balHelper != root) {
        balHelper->balance = height(balHelper->right) - height(balHelper->left);
        balHelper = balHelper->prev;
    }

    balHelper->balance = height(balHelper->right) - height(balHelper->left);
}

/////////////////////////////////////////////////////////////////////////
/////////                    Delete                             /////////
/////////////////////////////////////////////////////////////////////////


/**
 * Entrypoint to remove a Node.
 * First it searches for the Node with the same value as submitted.
 * Afterwards the Node gets deleted and upout gets called.
 * @param value -> the value to delete
 */
void AVLTree::remove(Node *startElement, const int value) {

    //check if Tree is empty
    if (root == nullptr) {
        return;
    }

    if (root->right == nullptr && root->left == nullptr && root->key == value) {
        root = nullptr;
        return;
    }


    auto pos = startElement;

    //Searching for the Node to delete
    while (pos->key != value) {
        if (pos->key == value)
            break;

        if (value > pos->key) {
            if (pos->right != nullptr)
                pos = pos->right;
            else
                return;
        } else {
            if (pos->left != nullptr)
                pos = pos->left;
            else
                return;
        }
    }


    //First Case: Node to delete has no sons
    ///////////////////////////////////////////////////////////////////////////////////////////////
    if (pos->left == nullptr && pos->right == nullptr) {
        removeTwoLeaves(pos, value);
        return;
    }

    //Case 2: node to delete has one son
    ///////////////////////////////////////////////////////////////////////////////////////////////
    if ((pos->right != nullptr && pos->left == nullptr) || pos->right == nullptr && pos->left != nullptr) {
        removeOneLeaves(pos, value);
        return;
    }

    //Case 3: node to delete has two sons
    ///////////////////////////////////////////////////////////////////////////////////////////////
    if (pos->right != nullptr && pos->left != nullptr) {
        removeNoLeaves(pos, value);
    }
}

/**
 * remove when the node to delete has two leaves
 * @param pos -> the node to delete
 * @param value -> value of the node to delete
 */
void AVLTree::removeTwoLeaves(Node *pos, const int value) {
    if (pos == root) {
        root = nullptr;
        delete pos;
        return;
    }
    //pos is right son of it's parent
    if (pos == pos->prev->right) {
        pos->prev->balance--;

        //parent of pos to delete has a left son => no height changes, no rotation needed
        if (pos->prev->balance == -1) {
            pos->prev->right = nullptr;
            delete (pos);
            return;
        }
        //parent of pos only had it's right son, which got deleted => change in height => rotation might be needed
        if (pos->prev->balance == 0) {
            pos->prev->right = nullptr;
            auto helper = pos->prev;
            delete pos;
            upout(helper, value);
            return;
        }

        //parent of pos has a left son with another left son => rotation needed
        if (pos->prev->balance == -2) {
            pos->prev->balance = -1;
            upout(pos, value);
            pos->prev->right = nullptr;
            auto helper = pos->prev;
            delete pos;
            return;
        }
    } else { //node to delete is left son
        pos->prev->balance++;
        //parent of pos has 1 right son => no change in height => no rotation needed
        if (pos->prev->balance == 1) {
            pos->prev->left = nullptr;
            delete (pos);
            return;
        }

        //parent of pos has no right son => height got changed => rotation needed
        if (pos->prev->balance == 0) {
            auto helper = pos->prev;
            helper->left = nullptr;
            delete (pos);
            upout(helper, value);
            return;
        }

        //parent of pos has a son with a son on right side 0> rotation definitly needed
        if (pos->prev->balance == 2) {
            pos->prev->balance = 1;
            upout(pos, value);
            auto helper = pos->prev;
            helper->left = nullptr;
            delete (pos);
            return;
        }
    }
}

/**
 * remove when the node to delete has one leaves
 * @param pos -> the node to delete
 * @param value -> value of the node to delete
 */
void AVLTree::removeOneLeaves(Node *pos, const int value) {
    //son is on the right side
    if (pos->right != nullptr) {
        if (pos == root) {
            root = pos->right;
            root->prev = nullptr;
            root->balance = 0;
            return;
        }

        int helper = pos->key;
        pos->key = pos->right->key;
        pos->right->key = helper;
        delete (pos->right);
        pos->right = nullptr;
        pos->balance = 0;
        upout(pos, value);
        return;
    }

    //son is on the left side
    if (pos->left != nullptr) {
        if (pos == root) {
            root = pos->left;
            root->prev = nullptr;
            root->balance = 0;
            return;
        }
        pos->balance = 0;
        int helper = pos->key;
        pos->key = pos->left->key;
        pos->left->key = helper;
        delete (pos->left);
        pos->left = nullptr;
        upout(pos, value);
        return;
    }

}

/**
 * remove when the node to delete has two sons
 * @param pos -> the node to delete
 * @param value -> value of the node to delete
 */
void AVLTree::removeNoLeaves(Node *pos, const int value) {
//find symetric follower
    auto symFollower = pos->right;
    while (symFollower->left != nullptr) {
        symFollower = symFollower->left;
    }

    //change value of pos to delete and symFollower
    int helper = pos->key;
    pos->key = symFollower->key;
    symFollower->key = helper;

    //entfernen des symFollowers mit dem key von pos. Ab hier kommen nur noch Case 1 oder Case 2 in Frage.
    remove(pos->right, helper);
}

/**
 * Checks the height and rotates if needed
 * @param node -> the parent of the deleted node
 * @param value -> the key of the deleted node
 */
void AVLTree::upout(AVLTree::Node *node, const int value) {
    auto pos = node;
    //Abbruchbedingung für Rekursion
    if(pos==root){
        return;
    }

    //pos ist linker Nachfolger von Parent
    if(pos->prev->left == pos) {
        //Fall 1.1: parent of pos has balance -1 => set parent balance = 0 and call upout
        if(pos->prev->balance == -1) {
            pos->prev->balance = 0;
            upout(pos->prev, value);
        }
        //Fall 1.2: balance of parent is 0 => set parent balance = 1 and finish
        else {
            if (pos->prev->balance == 0) {
                pos->prev->balance = 1;
                return;
            }else{
                //Fall 1.3: balance of parent is 1
                if(pos->prev->balance == 1) {
                    //Fall 1.3.1: balance of parents left son is 0
                    if(pos->prev->right->balance == 0) {
                        rotateLeft(pos->prev);
                        pos->prev->balance = 1;
                        pos->prev->prev->balance = -1;
                    }else{
                        //Fall 1.3.2: balance of parents left son is 1
                        if(pos->prev->right->balance == 1) {
                            rotateLeft(pos->prev);
                            pos->prev->balance++;
                            pos->prev->prev->balance++;
                            upout(pos->prev->prev, value);

                            return;
                        }else{
                            //Fall 1.3.3: balance of parents right son is -1
                            if(pos->prev->right->balance == -1) {
                                rotateRight(pos->prev->right);
                                rotateLeft(pos->prev);
                                pos->prev->balance++;
                                pos->prev->prev->balance++;
                                upout(pos->prev->prev, value);
                                return ;
                            }
                        }
                    }
                }
            }

        }
    }else{
        //Fall 2: pos is right son

        //Fall 2.1: parent of pos has balance 1 => set parent balance = 0 and call upout
        if(pos->prev->balance == 1) {
            pos->prev->balance = 0;
            upout(pos->prev, value);
        }else{
            if(pos->prev->balance == 0) {
                pos->prev->balance = -1;
                return ;
            }else{
                if(pos->prev->balance == -1) {
                    if(pos->prev->left->balance == 0) {
                        rotateRight(pos->prev);
                        pos->prev->balance = -1;
                        pos->prev->prev->balance = 1;
                    }else{
                        if(pos->prev->left->balance == -1) {
                            rotateRight(pos->prev);
                            pos->prev->balance--;
                            pos->prev->prev->balance--;
                            upout(pos->prev->prev, value);
                            return ;
                        }else{
                            if(pos->prev->left->balance == 1) {
                                rotateLeft(pos->prev->left);
                                rotateRight(pos->prev);
                                pos->prev->balance--;
                                pos->prev->prev->balance--;
                                upout(pos->prev->prev, value);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

}





/////////////////////////////////////////////////////////////////////////
/////////                    Traversal                          /////////
/////////////////////////////////////////////////////////////////////////

vector<int> *AVLTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *AVLTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *AVLTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *AVLTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfoger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }

    // Wurzel in vec
    vec->push_back(key);
    return vec;
}