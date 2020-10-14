#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

template<class T>
class BSTNode{
    private:
       T data;
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
       T& getData() { return data; }
       BSTNode* getLeft() { return left; }
       BSTNode* getRight() { return right; }
       void setLeft(BSTNode* mLeft) { left = mLeft; }
       void setRight(BSTNode* mRight) { right = mRight; }
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
    public:

        /* Creates an empty binary tree. */
        BinaryTree();

        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);
	void copyTree(BSTNode<T>* otRoot);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         */
        void put(const T &val);

        /* Returns the height of the binary tree. */
        int getHeight();
	int maxDepth(BSTNode<T>* node);

        /* Returns true if an item exists in the Binary Tree */
	//bool contains_rec(BSTNode<T>* node, const int val);
        bool contains(const T &val) const;

        /* Removes a specific val from the Binary Tree.
         * Returns true if the value exists (and was removed.)
         * Otherwise, returns false.
         */
        bool remove(const T &val);
	bool remove(BSTNode<T>* rover, const T &val);

        /* This method returns true iff there is a value in the tree 
         * >= min and <= max.  In other words, it returns true if there
         * is an item in the tree in the range [min, max]
         */
        bool existsInRange(T min, T max) const;

        /* This is similar but it returns the number of items in the range. */
        int countInRange(T min, T max) const;

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string postorderString();

	/* Least common ancestor */
	T& lca(BSTNode<T>* node, const T& n1, const T& n2);
	T& lca(T& a, T& b);

        /* Does an inorder traversal of the Binary Search Tree calling
         * visit on each node.
         */
        void inorderTraversal(void (*visit) (T &item)) const;

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
