#include "BST.hpp"
#include <stdlib.h>
#include <stdio.h>

BST::BST() {
    root = NULL;
}

void BST::add(const int val) {
    BSTNode *toadd = new BSTNode(val, NULL, NULL);
    BSTNode *rover = root;

    if (root == NULL) {
        root = toadd;
        return;
    }

    while (rover != NULL){
        if(rover->getData() > val){
            if (rover->getLeft() == NULL) {
                rover->setLeft(toadd);
                return;
            } 
            rover = rover->getLeft();
        }
        else{
            if (rover->getRight() == NULL) {
                rover->setRight(toadd);
                return;
            }
            rover = rover->getRight();
        }
    }
}

bool BST::contains_rec(BSTNode *node, const int val) {
    if (node == NULL) { return false; }

    if (node->getData() == val) { return true; }

    if (node->getData() < val) {
        return contains_rec(node->getRight(), val);
    } else {
        return contains_rec(node->getLeft(), val);
    }
}

bool BST::contains(const int val) {
    return contains_rec(root, val);
    /*
    BSTNode *rover = root;

    while (rover != NULL){
        if(rover->getData() == val){
            return true;
        }
        else {
            if (rover->getData() < val) {
                rover = rover->getRight();
            } 
            else {
                rover = rover->getLeft();
            }
        }
    }

    return false;
    */
}

void BST::print(BSTNode *node) {
    if (node == NULL) { return; }

    print(node->getLeft());
    printf("%d ", node->getData());
    print(node->getRight());
}

void BST::print() {
    print(root);
}