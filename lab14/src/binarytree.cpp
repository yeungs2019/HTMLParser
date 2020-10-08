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

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
    //BSTNode* rover = tree.root;
    //root = NULL;
    if(tree.root == NULL){
	root = NULL;
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
	    return lefty + 1;
	}
	else{
	    return righty + 1;
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
