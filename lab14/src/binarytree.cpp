#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}

template<class T>
void BinaryTree<T>::copyTree(BSTNode<T>* &ctRoot, BSTNode<T>* otRoot){
    if(otRoot == NULL){
	ctRoot = NULL;
    }
    else{
	ctRoot = new BSTNode<T>;
	ctRoot->getData() = otRoot->getData();
	copyTree(ctRoot->getLeft(), otRoot->getLeft());
	copyTree(ctRoot->getRight(), otRoot->getRight());
    }
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
    //BSTNode* rover = tree.root;
    //root = NULL;
    if(tree.root == NULL){
	root = NULL;
    }
    else{
	copyTree(root, tree.root);
    }
}

template <class T>
void BinaryTree<T>::put(const T &val){
    
}
/*template <class T>
int BinaryTree<T>::max(int x, int y) {
    if(x >= y){
	return x;
    }
    else{
	return y;
    }
}*/

template <class T>
int BinaryTree<T>::maxDepth(BSTNode<T>* node){
    if(node == NULL){
	return 0;
    }
    else{
	int lefty = maxDepth(node->getLeft());
	int righty = maxDepth(node->getRight());
	if(lefty > righty){
	    return 1 + lefty;
	}
	else{
	    return 1 + righty;
	}
    }
}   
template <class T>
int BinaryTree<T>::getHeight(){
    return maxDepth(root);   
}
template<class T>
BinaryTree<T>::~BinaryTree() {
}
#endif
