#ifdef SPLAY_H
#define SPLAY_H
#include "splay.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

template <class T>
SplayTree<T>::SplayTree(){
   root = NULL;
}

template <class T>
void SplayTree<T>::copyTree(splayNode<T>* otRoot){
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
SplayTree<T>::SplayTree(const SplayTree<T> &tree){
    root = NULL;
    copyTree(tree.root);
}

template <class T>
splayNode<T>* SplayTree<T>::newNode(int key){
    splayNode<T>* Node = new splayNode<T>(key, NULL, NULL);
    Node->setData(key);
    //Node->getLeft() = Node->getRight() = NULL;
    Node->setLeft(NULL);
    Node->setRight(NULL);
    return Node;
}

template <class T>
splayNode<T>* SplayTree<T>::rightRotate(splayNode<T> *x){
    splayNode<T>* y = x->getLeft();
    x->setLeft(y->getRight());
    y->setRight(x);
    return y;
}

template <class T>
splayNode<T>* SplayTree<T>::leftRotate(splayNode<T> *x){
    splayNode<T>* y = x->getRight();
    x->setRight(y->getLeft());
    y->setLeft(x);
    return y;
}

template <class T>
splayNode<T>* SplayTree<T>::splay(splayNode<T>* root, int key){
    if(root == NULL || root->getData() == key){
	return root;
    }
    if(root->getData() > key){
	if(root->getLeft() == NULL){
	    return root;
	}
	if(root->getLeft()->getData() > key){
	    root->getLeft()->setLeft(splay(root->getLeft()->getLeft(), key));
	    root = rightRotate(root);
	}
	else if(root->getLeft()->getData() < key){
	    root->getLeft()->setRight(splay(root->getLeft()->getRight(), key));
	    if(root->getLeft()->getRight() != NULL){
		root->setLeft(leftRotate(root->getLeft()));
	    }
	}
	return (root->getLeft() == NULL)? root: rightRotate(root);
    }
    else{
	if(root->getRight() == NULL){
	    return root;
	}
	if(root->getRight()->getData() > key){
	    root->getRight()->setLeft(splay(root->getRight()->getLeft(), key));
	    if(root->getRight()->getLeft() != NULL){
		root->setRight(rightRotate(root->getRight()));
	    }
	}
	else if(root->getRight()->getData() < key){
	    root->getRight()->setRight(splay(root->getRight()->getRight(), key));
	    root = leftRotate(root);
	}
	return (root->getRight() == NULL)? root: leftRotate(root);
    }
}

template <class T>
splayNode<T>* SplayTree<T>::insert(splayNode<T>* root, int k){
    if(root == NULL){
	return newNode(k);
    }
    root = splay(root, k);
    if(root->getData() == k){
	return root;
    }

    splayNode<T>* newnode = newNode(k);

    if(root->getData() > k){
	newnode->setRight(root);
	newnode->setLeft(root->getLeft());
	root->setLeft(NULL);
    }
    else{
	newnode->setLeft(root);
	newnode->setRight(root->getRight());
	root->setRight(NULL);
    }
    return newnode;
}

template <class T>
void SplayTree<T>::put(const T &val){
    splayNode<T>* toadd = new splayNode<T>(val, NULL, NULL);
    splayNode<T>* rover = root;
    if(rover == NULL){
	root = toadd;
	return;
    }
    insert(root, val);
}

template <class T>
int SplayTree<T>::maxDepth(splayNode<T>* node){
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
int SplayTree<T>::getHeight(){
    return maxDepth(root);
}

template <class T>
bool SplayTree<T>::contains(const T &val) const{
    splayNode<T>* rover = root;
    while(rover != NULL){
	if(rover->getData() == val){
	    return true;
	}
	else{
	    if(rover->getData() < val){
		rover = rover->getRight();
	    }
	    else{
		rover = rover->getLeft();
	    }
	}
    }
    return false;
}

template<class T>
splayNode<T>* SplayTree<T>::deleteKey(splayNode<T>* root, int key){
    splayNode<T>* temp;
    if(!root){
	return NULL;
    }
    root = splay(root, key);
    if(key != root->getData()){
	return root;
    }
    if(!root->getLeft()){
	temp = root;
	root = root->getRight();
    }
    else{
	temp = root;
	root = splay(root->getLeft(), key);
	root->setRight(temp->getRight());
    }
    delete temp;
    //free(temp);
    return root;
}
template <class T>
bool SplayTree<T>::remove(const T &val){
    deleteKey(root, val);
}

template <class T>
std::string SplayTree<T>::inorderString(splayNode<T> *node, std::string &ret){
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
std::string SplayTree<T>::inorderString(){
    std::string result = "";
    result = inorderString(root, result);
    return result;
}

template <class T>
std::string SplayTree<T>::preorderString(splayNode<T> *node, std::string &ret){
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
std::string SplayTree<T>::preorderString(){
    std::string result = "";
    result = preorderString(root, result);
    return result;
}

template <class T>
std::string SplayTree<T>::postorderString(splayNode<T> *node, std::string &ret){
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
std::string SplayTree<T>::postorderString(){
    std::string result = "";
    result = postorderString(root, result);
    return result;
}

template <class T>
void SplayTree<T>::destroy(splayNode<T>* p){
    if(p != NULL){
	destroy(p->getLeft());
	destroy(p->getRight());
	delete p;
    }
}

template <class T>
SplayTree<T>::~SplayTree(){
    destroy(root);
}

#endif