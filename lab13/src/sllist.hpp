#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <stdlib.h>

template <class T>
class SLLNode{
    private:
	int data;
	SLLNode* nextNode;
	//SLLNode* prevNode;
    public:
	SLLNode(const int data, SLLNode* next){
	    this->data = data;
	    this->nextNode = next;
	    //this->prevNode = prev;
	}
	int& getData() { return data; }
	SLLNode* getNext(){ return nextNode; }
	//SLLNode* getPrev(){ return prevNode; }
	void setNext(SLLNode* node) {this->nextNode = node;}
	//void setPrev(SLLNode* node2) {this->prevNode = node2;}
};

template <class T>
class SLList{
    private:
	SLLNode<T>* head;
	SLLNode<T>* tail;
    public:
	SLList();
	T& operator[](const int pos);
	bool append(const T &val);
	void sort();
};


#include "sllist.cpp"

#endif

