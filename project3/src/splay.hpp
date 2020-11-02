#ifndef SPLAY_H
#define SPLAY_H

#include <string>

template <class T>
class splayNode{
    private:
	T data;
	splayNode* left;
	splayNode* right;
    public:
	splayNode(const T mData, splayNode* mLeft, splayNode* mRight){
	    data = mData;
	    left = mLeft;
	    right = mRight;
	}
	T& getData() { return data; }
	splayNode* getLeft() { return left; }
	splayNode* getRight() { return right; }
	void setLeft(splayNode* mLeft) { left = mLeft; }
	void setRight(splayNode* mRight) { right = mRight; }
	void setData(T mData) {data = mData; }
};

template <class T>
class SplayTree{
    private:
	splayNode<T>* root;
	  /* Recommended, but not necessary helper function. */
        void put(splayNode<T> *rover, splayNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        std::string inorderString(splayNode<T> *node, std::string &ret);
        std::string preorderString(splayNode<T> *node, std::string &ret);
        std::string postorderString(splayNode<T> *node, std::string &ret);

    public:
	/* Creates an empty binary tree */
	SplayTree();

	/*Does a deep copy of the tree. */
	SplayTree(const SplayTree<T> &tree);
	void copyTree(splayNode<T>* otRoot);

	/* Extra helpers */
	splayNode<T>* splay(splayNode<T>* root, int key);
	splayNode<T>* leftRotate(splayNode<T> *x);
	splayNode<T>* rightRotate(splayNode<T> *x);
	splayNode<T>* newNode(int key);

	/* Add a given value to the Binary Tree
	 * Must maintain ordering!
	 */
	splayNode<T>* insert(splayNode<T>* root, int k);
	void put(const T &val);

	/* Returns the height of the binary tree. */
	int maxDepth(splayNode<T>* node);
	int getHeight();

	/*returns true if an item exists in the Binary Tree. */
	bool contains(const T &val) const;

	/* Removes a specific val from the Binary Tree 
	 * Returns true if the value exists (and was removed.)
	 * Otherwise, returns false
	 */
	splayNode<T>* deleteKey(splayNode<T>* root, int key);
	bool remove (const T &val);
	
	/*Returns a string representation of the binary Tree in order. */
	std::string inorderString();

	/*Returns a string representation of the binary Tree in order. */
	std::string preorderString();

	/*Returns a string representation of the binary Tree in order. */
	std::string postorderString();

	/*Always free memory. */
	void destroy(splayNode<T>* p);
	~SplayTree();
};
/* Since SplayTree is templated, we include .cpp.
 * Templated classes are not implemented until utilized (or explicitly
 * declared)
 */
#include "splay.cpp"

#endif

