#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include "binarytree.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

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
std::string BinaryTree<T>::inorderString(BSTNode<T> *node, std::string &ret){
    std::ostringstream oss;
    if(node == NULL){
	return ret;
    }
    else{
	inorderString(node->getLeft(), ret);
	oss << node->getData() << " ";
	ret += oss.str();
	inorderString(node->getRight(), ret);
	return ret;
    }
}
template <class T>
std::string BinaryTree<T>::inorderString(){
    std::string result = "";
    result = inorderString(root, result);
    return result;
}

template <class T>
std::string BinaryTree<T>::preorderString(BSTNode<T> *node, std::string &ret){
    std::ostringstream oss;
    if(node == NULL){
	return ret;
    }
    else{
	oss << node->getData() << " ";
	ret += oss.str();
	preorderString(node->getLeft(), ret);
	preorderString(node->getRight(), ret);
	return ret;
    }
}

template <class T>
std::string BinaryTree<T>::preorderString(){
    std::string result = "";
    result = preorderString(root, result);
    return result;
}

template <class T>
std::string BinaryTree<T>::postorderString(BSTNode<T> *node, std::string &ret){
    std::ostringstream oss;
    if(node == NULL){
	return ret;
    }
    else{
	postorderString(node->getLeft(), ret);
	postorderString(node->getRight(), ret);
	oss << node->getData() << " ";
	ret += oss.str();
	return ret;
    }
}

template <class T>
std::string BinaryTree<T>::postorderString(){
    std::string result = "";
    result = postorderString(root, result);
    return result;
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
bool BinaryTree<T>::contains(const T &val) const{
    BSTNode<T>* rover = root;
    while(rover != NULL){
	if(rover->getData() == val){
	    return true;
	}
	else{
	     if(rover->getData() < val){
	         rover = rover->getRight();
	        // return true;
	     }
	     else{
	    	 rover = rover->getLeft();
	    	// return true;
	     }
   	}
    }
    return false;
}

template <class T>
bool BinaryTree<T>::remove(BSTNode<T>* rover, const T &val){
    BSTNode<T>* toDelete = NULL;
    if(rover == NULL){
	return false;
    }
    if(rover->getRight() != NULL && val == rover->getRight()->getData()){
	toDelete = rover->getRight();
	if(toDelete->getRight() == NULL && toDelete->getLeft() == NULL){
	    delete toDelete;
	    rover->setRight(NULL);
	    return true;
	}
	if(toDelete->getLeft() == NULL){
	    rover->setRight(toDelete->getLeft());
	}
	else{
	    BSTNode<T>* temp = toDelete->getLeft();
	    while(temp->getRight() != NULL){
		temp = temp->getRight();
	    }
	    int tval = temp->getData();
	    toDelete->setData(tval);
	}
    }
    if(val > rover->getData()){
	rover = rover->getRight();
    }
    else{
	rover = rover->getLeft();
    }
    return remove(rover, val);
}
template <class T>
bool BinaryTree<T>::remove(const T &val){
    return remove(root, val);
}
template <class T>
int BinaryTree<T>::countInRange(BSTNode<T>* node, T min, T max) const{
    if(node == NULL){
	return 0;
    }
    if(node->getData() == max && node->getData() == min){
	return 1;
    }
    if(node->getData() <= max && node->getData() >= min){
	return 1 + countInRange(node->getLeft(), min, max) +
		countInRange(node->getRight(), min, max);
    }
    else if(node->getData() < max){
	return countInRange(node->getRight(), min, max);
    }
    else{
	return countInRange(node->getLeft(), min, max);
    }
}
template <class T>
int BinaryTree<T>::countInRange(T min, T max) const{
    return countInRange(root, min, max);
}

template <class T>
bool BinaryTree<T>::existsInRange(BSTNode<T>* node, T min, T max) const{
    BSTNode<T>* left = node->getLeft();
    BSTNode<T>* right = node->getRight();
    if(left != NULL && node->getData() > min){
	node = left;
	existsInRange(node, min, max);
	return true;
    }
    if(right != NULL && node->getData() < max){
	node = right;
	existsInRange(node, min, max);
	return true;
    }
}

template <class T>
bool BinaryTree<T>::existsInRange(T min, T max) const{
    if(root != NULL){
	existsInRange(root, min, max);
	return true;
    }
}

template <class T>
void BinaryTree<T>::inorderTraversal(BSTNode<T>* node, void (*visit) (T &item)) const{
    if(node != NULL){
	inorderTraversal(node->getLeft(), *visit);
	(*visit)(node->getData());
	inorderTraversal(node->getRight(), *visit);
    }
}

template <class T>
void BinaryTree<T>::inorderTraversal(void (*visit) (T &item)) const{
    inorderTraversal(root, *visit);   
}
template <class T>
T& BinaryTree<T>::lca(BSTNode<T>* node, const T& n1, const T& n2){
    /*if(node->getData() == NULL){
	return NULL;
    }*/
    if(node->getData() > n1 && node->getData() > n2){
	return lca(node->getLeft(), n1, n2);
    }
    if(node->getData() < n1 && node->getData() < n2){
	return lca(node->getRight(), n1, n2);
    }
    return node->getData();
}
template<class T>
T& BinaryTree<T>::lca(T& a, T& b){
    return lca(root, a, b);
}

template <class T>
void BinaryTree<T>::destroy(BSTNode<T>* p){
    if(p != NULL){
	destroy(p->getLeft());
	destroy(p->getRight());
	delete p;
	//p = NULL;
    }
}
template<class T>
BinaryTree<T>::~BinaryTree(){
    destroy(root);
}
#endif
