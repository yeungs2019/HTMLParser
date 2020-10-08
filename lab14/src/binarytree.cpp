#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

template<class T>
BinaryTree<T>::BinaryTree() {
}

template <class T>
int BinaryTree<T>::max(int x, int y) {return (x > y ) ? x:y;}

template <class T>
int BinaryTree<T>::maxDepth(BSTNode* node){
    if(node == NULL){
	return 0;
    }
    else{
	return 1 + max(maxDepth(node->getLeft(), maxDepth(node->getRight())));
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
