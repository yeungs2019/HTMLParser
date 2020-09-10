#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <stdlib.h>

class SLLNode {
    private:
        int data;
        SLLNode* nextNode;
    public:
        SLLNode(const int data, SLLNode *next) {
            this->data = data;
            this->nextNode = next;
        }
        int& getData() { return data; }
        SLLNode *getNext() { return nextNode; }
        void setNext(SLLNode *node) { this->nextNode = node; }
};

class SLL {
    private:
        SLLNode* head;
    public:
        SLL() { head = NULL; }
        void add(const int data);
        void insert(const int pos, const int data);
        bool contains(const int data);
        int getLength();
        int& operator[](const int pos);
        void remove(const int data);
        void print();
};

#endif
