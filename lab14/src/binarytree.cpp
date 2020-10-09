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
void BinaryTree<T>::copyTree(BSTNode<T>* otRoot){
    if(otRoot == NULL){
	return;
    }
    else{
    	put(otRoot->getData());
	//ctRoot = new BSTNode<T>;
	//ctRoot->getData() = otRoot->getData();
	copyTree(otRoot->getLeft());
	copyTree(otRoot->getRight());
    }
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
	root = NULL;
	copyTree(tree.root);
}
template <class T>
void BinaryTree<T>::put(BSTNode<T> *rover, BSTNode<T> *newNode){
     if(rover == NULL || newNode == NULL){
	 return;
     }
     if(rover->getData() < newNode->getData()){
	 if(rover->getRight() == NULL){
	     rover->setRight(newNode);
	     return;
	 }
	 put(rover->getRight(), newNode);
     }
     else if(rover->getData() > newNode->getData()){
	 if(rover->getLeft() == NULL){
	     rover->setLeft(newNode);
	     return;
	 }
	 put(rover->getLeft(), newNode);
     }

}
template <class T>
void BinaryTree<T>::put(const T &val){
     BSTNode<T>* toadd = new BSTNode<T>(val, NULL, NULL);
     BSTNode<T>* rover = root;
     if(rover == NULL){
         root = toadd;
	 return;
     }
     put(root, toadd);

}

template <class T>
int BinaryTree<T>::maxDepth(BSTNode<T>* node){
    if(node == NULL){
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
