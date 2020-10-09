#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>

using namespace std;
template <class T>
BinaryTree<T>::BinaryTree(){ 
    root = NULL;
}

template <class T>
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
    if(tree.root == NULL){
	root = NULL;
    }
    else{
	copyTree(root, tree.root);
    }
}
template <class T>
void BinaryTree<T>::put(BSTNode<T> *rover, BSTNode<T> *newNode){
 
}
template <class T>
void BinaryTree<T>::put(const T &val){
 
}

template <class T>
int BinaryTree<T>::maxDepth(BSTNode<T>* node){
    if(!node){
	return 0;
    }
    else{
	int lefty;
        lefty = maxDepth(node->getLeft());
	int righty;
	righty = maxDepth(node->getRight());
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
    //BSTNode<T>* rover = root;
    return maxDepth(root);
}
template <class T>
void BinaryTree<T>::add(const int val){
    BSTNode<T>* toadd = new BSTNode<T>(val, NULL, NULL);
    BSTNode<T>* rover = root;
    if(root = NULL){
	root = toadd;
	return;
    }
    while(rover != NULL){
	if(rover->getData() > val){
	    if(rover->getLeft() == NULL){
		rover->setLeft(toadd);
		return;
	    }
	    rover = rover->getLeft();
	}
	else{
	    if(rover->getRight() == NULL){
		rover->setRight(toadd);
		return;
	    }
	    rover = rover->getRight();
	}
    }
}

template <class T>
void BinaryTree<T>::destroy(BSTNode<T>* p){
    if(p != NULL){
	destroy(p->getLeft());
	destroy(p->getRight());
	delete p;
	p = NULL;
    }
}
template<class T>
BinaryTree<T>::~BinaryTree(){
    destroy(root);
}
#endif
