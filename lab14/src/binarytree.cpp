#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>
#include <list>

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
    BSTNode* root;
    if(root == NULL){
	return 0;
    }
    std::list queue;
    queue.push_back(root);
    BSTNode* front = NULL;
    int height = 0;
    while(!queue.empty()){
	int size = queue.size();
	while(size--){
	    front = queue.front();
	    queue.pop_front();
	    if(front->getLeft()){
		queue.push_back(front->getLeft());
	    }
	    if(front->getRight()){
		queue.push_back(front->getRight());
	    }
	}
	height++;
    }
    return height;
}
template<class T>
BinaryTree<T>::~BinaryTree() {
}
#endif
