#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

template<class T>
class BSTNode{
    private:
       T data;
       //T height;
       BSTNode* left;
       BSTNode* right;
    public:
       BSTNode(const T mData, BSTNode* mLeft, BSTNode* mRight){
           data = mData;
           left = mLeft;
           right = mRight;
           /*this->data = mData;
           this->left = mLeft;
           this->right = mRight;*/
       }
       T height;
       T& getData() { return data; }
       BSTNode* getLeft() { return left; }
       BSTNode* getRight() { return right; }
       void setLeft(BSTNode* mLeft) { left = mLeft; }
       void setRight(BSTNode* mRight) { right = mRight; }
       void setData(T mData) { data = mData; }
};

template<class T>
class BinaryTree {
    private:
	BSTNode<T>* root;
        /* You fill in private member data. */

        /* Recommended, but not necessary helper function. */
        void put(BSTNode<T> *rover, BSTNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        std::string inorderString(BSTNode<T> *node, std::string &ret);
	std::string preorderString(BSTNode<T> *node, std::string &ret);
	std::string postorderString(BSTNode<T> *node, std::string &ret);
    public:

        /* Creates an empty binary tree. */
        BinaryTree();

        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);
	void copyTree(BSTNode<T>* otRoot);

	/* These are the nodes from the AVL tree*/
	BSTNode<T>* newNode(int key);
	BSTNode<T>* rightRotate(BSTNode<T>* y);
	BSTNode<T>* leftRotate(BSTNode<T>* x);

	/* get balance factor of node N */
	int getBalance(BSTNode<T>* N);

	/* Recursive function for put*/
	BSTNode<T>* insert(BSTNode<T>* node, int key);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         */
        void put(const T &val);
	/* Max utility function */
	int max(int a, int b);

        /* Returns the height of the binary tree. */
        int getHeight();
	int maxDepth(BSTNode<T>* node);
	int gHeight(BSTNode<T>* N);

        /* Returns true if an item exists in the Binary Tree */
	//bool contains_rec(BSTNode<T>* node, const int val);
        bool contains(const T &val) const;

        /* Removes a specific val from the Binary Tree.
         * Returns true if the value exists (and was removed.)
         * Otherwise, returns false.
         */
	BSTNode<T>* minValueNode(BSTNode<T>* node);
	BSTNode<T>* deleteNode(BSTNode<T>* root, int key);
        bool remove(const T &val);

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string postorderString();

        /* Always free memory. */
	void destroy(BSTNode<T>* p);
        ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "binarytree.cpp"

#endif
