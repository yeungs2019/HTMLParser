#ifdef SLLIST_HPP
#include<iostream>
#include "sllist.hpp"

template <class T>
SLList<T>::SLList(){
    //head = NULL;
    //tail = NULL;
}
template <class T>
int SLList<T>::getLength() const{
    SLLNode* rover = head;
    int newLength = 0;
    while(rover != NULL){
	newLength++;
	rover = rover->getNext();
    }
    return newLength;
}

template <class T>
T& SLList<T>::operator[](const int pos){
    SLLNode* rover = head;
    for(int i = 0; i < pos; i++){
	rover = rover->getNext();
    }
    return rover->getData();
}
template <class T>
bool SLList<T>::append(const T &val){
    bool isAppend = false;
    SLLNode* rover = new SLLNode(val, NULL);
    if (head == NULL){
	head = rover;
	tail = rover;
    }
    else{
	tail->setNext(rover);
	tail = rover;
    }
    isAppend = true;
    return isAppend;
}
template <class T>
void SLList<T>::merge(SLLNode** start1, SLLNode** end1, SLLNode** start2, SLLNode** end2){
    SLLNode* temp = NULL;
    if((*start1)->getData() > (*start2)->getData()){
	std::swap(*start1, *start2);
	std::swap(*end1, *end2);
    }

    SLLNode* astart = *start1 
    SLLNode* aend = *end1;
    SLLNode* bstart = *start2 
    SLLNode* bend = *end2;
    SLLNode* bendnext = (*end2)->getNext();
    while(astart != aend && bstart != bendnext){
	if(astart->getNext()->getData() > bstart->getData()){
	    temp = bstart->getNext();
	    bstart->getNext() = astart->getNext();
	    astart->getNext() = bstart;
	    bstart = temp;
	}
	astart = astart->getNext();
    }
    if(astart == aend){
	astart->getNext() = bstart;
    }
    else{
	*end2 = *end1;
    }
}
	
template <class T>
void SLList<T>::sort(){
    if(head == NULL){
        return;
    }
    SLLNode* start1 = NULL;
    SLLNode* end1 = NULL;
    SLLNode* start2 = NULL;
    SLLNode* end2 = NULL;
    SLLNode* prevend = NULL;
    int len = this->getLength();
    for(int gap = 1; gap < len; gap = gap * 2){
	start1 = head;
	while(start1){
	    bool isFirstIter = 0;
	    if(start1 == head){
		isFirstIter = 1;
	    }
	    int counter = gap;
	    end1 = start1;
	    while(--counter && end1->getNext()){
		end1 = end1->getNext();
	    }
	    start2 = end1->getNext();
	    if(!start2){
		break;
	    }
	    counter = gap;
	    end2 = start2;
	    while(--counter && end2->getNext()){
		end2 = end2->getNext();
	    }
	    SLLNode* temp = end2->getNext();
	    merge(&start1, &end1, &start2, &end2);
	    if(isFirstIter){
		head = start1;
	    }
	    else{
		prevend->getNext() = start1;
	    }
	    prevend = end2;
	    start1 = temp;
	}
	prevend->getNext() = start1;
    }
}
    




#endif
