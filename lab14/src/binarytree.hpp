#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

template<class T>
class BSTNode{
    private:
       int data;
       BSTNode* left;
       BSTNode* right;
    public:
       BSTNode(const int mData, BSTNode* mLeft, BSTNode* mRight){
           /*data = mData;
           left = mLeft;
           right = mRight;*/
	   this->data = mData;
	   this->left = mLeft;
	   this->right = mRight;
       }
       int& getData() { return data; }
       BSTNode* getLeft() { return left; }
       BSTNode* getRight() { return right; }
       void setLeft(BSTNode* mLeft) { this->left = mLeft; }
       void setRight(BSTNode* mRight) { this->right = mRight; }
};


template<class T>
class BinaryTree {
    private:
	BSTNode<T>* root;
        /* Recommended, but not necessary helper function. */
        void put(BSTNode<T> *rover, BSTNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        //std::string inorderString(BinaryTreeNode<T> *node, std::string &ret);
    public:

        /* Creates an empty binary tree. */
        BinaryTree();

        /* Does a deep copy of the tree. */
	void copyTree(BSTNode<T>* &ctRoot, BSTNode<T>* otRoot);
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);
	int maxDepth(BSTNode<T>* node);
	int max(int x, int y) const; 
        /* Returns the height for the binary tree. */
        int getHeight();

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Return the lowest common ancestor (LCA) of two values.
         * The LCA is the most immediate parent of both values.  For example:
         *      4
         *    /   \
         *   2     8
         *  / \   / \
         * 1   3 6   10
         * LCA(1, 3) = 2
         * LCA(1, 2) = 2
         * LCA(1, 6) = 4
         */
        T& lca(T& a, T& b);

        /* Always free memory. */
        ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "binarytree.cpp"

#endif
