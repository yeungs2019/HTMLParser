#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>
#include <algorithm>

template<class T>
BinaryTree<T>::BinaryTree() {
}

/*template <class T>
int BinaryTree<T>::maxDepth(BSTNode* node){
    if(node == NULL){
	return 0;
    }
    else{
	return 1 + std::max(maxDepth(node->getLeft(), maxDepth(node->getRight())));
    }
}*/    
template <class T>
int BinaryTree<T>::getHeight(){
    BSTNode* temp;
    if(temp == NULL){
	return 0;
    }
    else{
	return 1 + std::max(temp->getLeft(), temp->getRight());
    }
}
template<class T>
BinaryTree<T>::~BinaryTree() {
}
#endif
