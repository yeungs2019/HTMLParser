#ifdef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <sstream>
#include <fstream>

template <class T>
BinaryTree<T>::BinaryTree(){
    root = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
    root = NULL;
    copyTree(tree.root);
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
BSTNode<T>* BinaryTree<T>::newNode(int key){
    BSTNode<T>* node = new BSTNode<T>(key, NULL, NULL);
    node->height = 1; // new node added at the leaf
    return node;
}

template <class T>
BSTNode<T>* BinaryTree<T>::rightRotate(BSTNode<T>* y){
    BSTNode<T>* x = y->getLeft();
    BSTNode<T>* T2 = x->getRight();

    // Perform rotation
    x->setRight(y);
    y->setLeft(T2);
    // Update heights
    y->height = max(gHeight(y->getLeft()), gHeight(y->getRight())) + 1;
    x->height = max(gHeight(x->getLeft()), gHeight(x->getRight())) + 1;

    // return the new root
    return x;
}

template <class T>
BSTNode<T>* BinaryTree<T>::leftRotate(BSTNode<T>* x){
    BSTNode<T>* y = x->getRight();
    BSTNode<T>* T2 = y->getLeft();

    //Perform rotation
    y->setLeft(x);
    x->setRight(T2);

    // Update Heights
    x->height = max(gHeight(x->getLeft()), gHeight(x->getRight())) + 1;
    y->height = max(gHeight(y->getLeft()), gHeight(y->getRight())) + 1;

    // return new root
    return y;
}

template <class T>
int BinaryTree<T>::getBalance(BSTNode<T>* N){
    if(N == NULL){
	return 0;
    }
    return gHeight(N->getLeft()) - gHeight(N->getRight());
}

template <class T>
BSTNode<T>* BinaryTree<T>::insert(BSTNode<T>* node, int key){
    if(node == NULL){
	return(newNode(key));
    }
    if(key < node->getData()){
	//node->getLeft() = insert(node->getLeft(), key);
	node->setLeft(insert(node->getLeft(), key));
    }
    else if(key > node->getData()){
	//node->getRight() = insert(node->getRight(), key);
	node->setRight(insert(node->getRight(), key));
    }
    else{ // no equal keys
	return node;
    }
    // update the height of the ancestor node
    node->height = 1 + max(gHeight(node->getLeft()), 
	gHeight(node->getRight()));

    // get balancing act going
    int balance = getBalance(node);

    if(balance > 1 && key < node->getLeft()->getData()){
	return rightRotate(node);
    }
    if(balance < -1 && key > node->getRight()->getData()){
	return leftRotate(node);
    }
    if(balance > 1 && key > node->getLeft()->getData()){
	node->setLeft(leftRotate(node->getLeft()));
	return rightRotate(node);
    }
    if(balance < -1 && key < node->getRight()->getData()){
	node->setRight(rightRotate(node->getRight()));
	return leftRotate(node);
    }
    return node;
}

template <class T>
void BinaryTree<T>::put(const T &val){
    BSTNode<T>* toadd = new BSTNode<T>(val, NULL, NULL);
    BSTNode<T>* rover = root;
    if(rover == NULL){
	root = toadd;
	return;
    }
    insert(root, val);
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
std::string BinaryTree<T>::inorderString(BSTNode<T> *node, std::string &ret){
   std::ostringstream oss;
   if(node == NULL){
       return ret;
   }
   else{
       inorderString(node->getLeft(), ret);
       oss << node->getData() << " ";
       ret+= oss.str();
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
std::string BinaryTree<T>::preorderString(BSTNode<T>* node, std::string &ret){
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
std::string BinaryTree<T>::postorderString(BSTNode<T>* node, std::string &ret){
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
int BinaryTree<T>::max(int a, int b){
    return (a > b)? a : b;
}

template <class T>
int BinaryTree<T>::getHeight(){
    return maxDepth(root);
}

template <class T>
int BinaryTree<T>::gHeight(BSTNode<T>* N){
    if(N == NULL)
	return 0;
    return N->height;
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
	    }
	    else{
		rover = rover->getLeft();
	    }
	}
    }
    return false;
}

template <class T>
BSTNode<T>* BinaryTree<T>::minValueNode(BSTNode<T>* node){
    BSTNode<T>* current = node;
    while(current->getLeft() != NULL){
	current = current->getLeft();
    }
    return current;
}

template <class T>
BSTNode<T>* BinaryTree<T>::deleteNode(BSTNode<T>* root, int key){
    if(root == NULL){
	return root;
    }
    if(key < root->getData()){
	root->setLeft(deleteNode(root->getLeft(), key));
    }
    else if(key > root->getData()){
	root->setRight(deleteNode(root->getRight(), key));
    }
    else{
	if((root->getLeft() == NULL) || (root->getRight() == NULL)){
	    BSTNode<T>* temp = root->getLeft() ? root->getLeft() : root->getRight();
	    if(temp == NULL){
		temp = root;
		root = NULL;
	    }
	    else{
		*root = *temp; 
	    }
	    delete temp;
	    //free(temp);
	}
	else{
	    BSTNode<T>* temp = minValueNode(root->getRight());
	    root->setData(temp->getData());
	    root->setRight(deleteNode(root->getRight(), temp->getData()));
	}
    }
    if(root == NULL){
        return root;
    }
    root->height = 1 + max(gHeight(root->getLeft()), gHeight(root->getRight()));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->getLeft()) >= 0){
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->getLeft()) < 0){
	root->setLeft(leftRotate(root->getLeft()));
	return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->getRight()) <= 0){
	return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->getRight()) > 0){
	root->setRight(rightRotate(root->getLeft()));
	return leftRotate(root);
    }
    return root;
}

template <class T>
bool BinaryTree<T>::remove(const T &val){
    deleteNode(root, val);
}

template <class T>
void BinaryTree<T>::destroy(BSTNode<T>* p){
    if(p != NULL){
	destroy(p->getLeft());
	destroy(p->getRight());
	delete p;
    }
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    destroy(root);
}

#endif
