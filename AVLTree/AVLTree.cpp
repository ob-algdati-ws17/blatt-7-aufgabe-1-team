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
 * searches for a given value. If it is found in the tree true is beeing returned
 * @param value -> the value to search for
 * @return true if found and false if not
 */


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

    if(root == nullptr) {
        auto newNode = new Node(value);
        root = newNode;
        root->balance = 0;
        return ;
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

/**
 * Used to get the height of the left and the right son
 * @param node -> element the height should be calculated at
 * @return the height of element
 */
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

/**
 * checks if the tree is a valid AVL tree.
 * depending of the balances rotations are called
 * @param newElement -> the newly added element
 */
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

    if(helper->right != nullptr)
        helper->right->balance = height(helper->right->right) - height(helper->right->left);

    if(helper->left != nullptr)
    helper->left->balance = height(helper->left->right) - height(helper->left->left);
    helper->balance = height(helper->right) - height(helper->left);
    auto balHelper = helper;
    while(balHelper != root) {
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

    if(helper->right != nullptr)
        helper->right->balance = height(helper->right->right) - height(helper->right->left);

    if(helper->left != nullptr)
        helper->left->balance = height(helper->left->right) - height(helper->left->left);
    helper->balance = height(helper->right) - height(helper->left);
    auto balHelper = helper;
    while(balHelper != root) {
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
void AVLTree::remove(const int value) {
    //check if Tree is empty
    if(root == nullptr) {
        return ;
    }

    if(root->right == nullptr && root->left == nullptr && root->key == value) {
        root = nullptr;
        return ;
    }


    auto pos = root;

    //Searching for the Node to delete
    while(pos->key != value) {
        if(pos->key == value)
             break;

        if(value > pos->key) {
            if(pos->right != nullptr)
                pos = pos->right;
            else
                return ;
        }else{
            if(pos->left != nullptr)
                pos=pos->left;
            else
                return ;
        }
    }

    //First Case: Node to delete has no leaves
    if(pos->left == nullptr && pos->right == nullptr) {
        if(pos == pos->prev->right) {
            auto balHelper = pos->prev;
            pos->prev->right = nullptr;
            delete pos;
            upout(balHelper, value);
        }else {
            auto balHelper = pos->prev;
            pos->prev->left = nullptr;
            delete pos;
            upout(balHelper, value);
        }
    }else{
        //Second Case: Node to delete has one leave

        if(pos->right != nullptr && pos->left == nullptr) {
            if(pos == root) {
                root = pos->right;
                pos->right->prev = nullptr;
                root->balance = height(root->right)-height(root->left);
                delete pos;
                return ;
            }
            if(pos == pos->prev->right) {
                auto balHelper = pos->prev;
                pos->prev->right = pos->right;
                pos->right->prev = pos->prev;
                delete pos;
                upout(balHelper, value);
            }else {
                auto balHelper = pos->prev;
                pos->prev->left = pos->right;
                pos->right->prev = pos->prev;
                delete pos;
                upout(balHelper, value);
            }
        }

        if(pos->right == nullptr && pos->left != nullptr) {
            if(pos == root) {
                root = pos->left;
                pos->left->prev = nullptr;
                root->balance = height(root->right)-height(root->left);
                delete pos;
                return ;
            }
            if(pos == pos->prev->right) {
                auto balHelper = pos->prev;
                pos->prev->right = pos->left;
                pos->left->prev = pos->prev;
                delete pos;
                upout(balHelper, value);
            }else {
                auto balHelper = pos->prev;
                pos->prev->left = pos->left;
                pos->left->prev = pos->prev;
                delete pos;
                upout(balHelper, value);
            }
        }

        //Third Case: Node to delete has two leaves
        if(pos->right != nullptr && pos->left != nullptr) {
            auto symFollower = pos->right;
            while(symFollower->left != nullptr)
                symFollower = symFollower->left;

            //SymFollower has right son
            if(symFollower->right != nullptr) {
                symFollower->right->prev = symFollower->prev;
                symFollower->prev->left = symFollower->right;
            }

            auto balHelper = symFollower->prev;

            //SymFollower is right son of position to delete
            if(symFollower->prev == pos) {
                balHelper = pos->prev;

                if(pos != root) {
                    if (pos == pos->prev->right)
                        pos->prev->right = symFollower;
                    else
                        pos->prev->left = symFollower;
                }else {
                    root = symFollower;
                }

                symFollower->prev = pos->prev;

                if(pos->left != nullptr) {
                    symFollower->left = pos->left;
                    pos->left->prev = symFollower;
                }

                auto posHelper = balHelper;
                while(posHelper != nullptr){
                    posHelper->balance = height(posHelper->right) - height(posHelper->left);
                    posHelper = posHelper->prev;
                }
                upout(balHelper, value);
                return ;
            }

            //SymFollower is NOT right son of position to delete
            if(symFollower->prev != pos) {

                if(pos != root) {
                    if (pos == pos->prev->right)
                        pos->prev->right = symFollower;
                    else
                        pos->prev->left = symFollower;
                }else {
                    root = symFollower;
                }

                symFollower->prev->left = nullptr;

                symFollower->prev = pos->prev;

                if(pos->right != nullptr) {
                    symFollower->right = pos->right;
                    pos->right->prev = symFollower;
                }

                if(pos->left != nullptr)
                    symFollower->left = pos->left;
                    pos->left->prev = symFollower;
            }


            auto posHelper = balHelper;
            while(posHelper != nullptr){
                posHelper->balance = height(posHelper->right) - height(posHelper->left);
                posHelper = posHelper->prev;
            }
            upout(balHelper, value);
        }
    }
}

/**
 * Checks the height and rotates if needed
 * @param node -> the parent of the deleted node
 * @param value -> the key of the deleted node
 */
void AVLTree::upout(AVLTree::Node *node, const int value) {

    // Calculating the new balances from the parent of the deleted node to the root

    auto pos = node;
    while(pos != root) {
        pos->balance = height(pos->right) - height(pos->left);
        pos = pos->prev;
    }

    pos = node;



    while(pos != nullptr) {
        if(pos->balance == 2 || pos->balance == -2) {
            if(value > pos->key) {
                if(pos->left->balance == 0 || pos->left->balance == 1) {
                    rotateLeft(pos->left);
                    rotateRight(pos);
                    break;
                }else{
                    rotateRight(pos);
                    break;
                }
            } else{
                if(pos->right->balance == 0 || pos->right->balance == 1) {
                    rotateLeft(pos);
                    break;
                }else{
                    rotateRight(pos->right);
                    rotateLeft(pos);
                    break;
                }
            }
        }else{
            pos = pos->prev;
        }
    }

    while(pos != nullptr) {
        if (pos->balance < 0) {
            auto helper = pos->left;
            if(height(helper->left) > height(helper->right)) {
                rotateRight(pos);
            }else{
                rotateLeft(pos);
                rotateRight(pos->prev);
            }
        }else{
            if(pos->balance > 1) {
                auto helper = pos->right;
                if (height(helper->right) >= height(helper->left)) {
                    rotateLeft(pos);
                } else {
                    rotateRight(pos);
                    rotateLeft(pos->prev);
                }
            }
        }
        pos = pos->prev;
    }
}





/////////////////////////////////////////////////////////////////////////
/////////                    Traversal                          /////////
/////////////////////////////////////////////////////////////////////////

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