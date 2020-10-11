#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"

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
bool BinaryTree<T>::contains_rec(BSTNode<T>* node, const int val){
    if(node == NULL){
	return false;
    }
    if(node->getData() == val){
	return true;
    }
    if(node->getData() < val){
	return contains_rec(node->getRight(), val);
    }
    else{
	return contains_rec(node->getLeft(), val);
    }
}
template <class T>
bool BinaryTree<T>::contains(const T &val) const{
    return contains_rec(root, val);
}
template <class T>
void BinaryTree<T>::destroy(BSTNode<T>* p){
    if(p != NULL){
	destroy(p->getLeft());
	destroy(p->getRight());
	delete p;
    }
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}
#endif
