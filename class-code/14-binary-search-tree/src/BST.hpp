#ifndef BST_HPP
#define BST_HPP

class BSTNode {
    private:
        int data;
        BSTNode* left;
        BSTNode* right;
    public:
        BSTNode(const int _data, BSTNode *_left, BSTNode *_right) {
            data = _data;
            left = _left;
            right = _right;
        }
        int getData() { return data; }
        void setData(const int val) { data = val; }
        BSTNode* getLeft() { return left; }
        BSTNode* getRight() { return right; }
        void setLeft(BSTNode *_left) { left = _left; }
        void setRight(BSTNode *_right) { right = _right; }
};

class BST {
    private:
        BSTNode* root;
        bool contains_rec(BSTNode *node, const int val);
        bool remove_rec(BSTNode *node, const int val);
        void print(BSTNode *node);
    public:
        BST();
        void add(const int val);
        bool contains(const int val);
        void print();
        bool remove(const int val);
};

#endif
