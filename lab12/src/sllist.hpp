#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <stdlib.h>

template <class T>
class SLLNode{
    private:
	int data;
	SLLNode* nextNode;
    public:
	SLLNode(const int data, SLLNode* next){
	    this->data = data;
	    this->nextNode = next;
	}
	int& getData() { return data; }
	SLLNode* getNext(){ return nextNode; }
	void setNext(SLLNode* node) {this->nextNode = node;}
};

template <class T>
class SLList{
    private:
	SLLNode<T>* head;
	SLLNode<T>* tail;
    public:
	SLList();
	void sort();
};


#include "sllist.cpp"

#endif

