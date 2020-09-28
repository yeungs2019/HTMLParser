#ifdef SLLIST_HPP
#include<iostream>
#include "sllist.hpp"

template <class T>
SLList<T>::SLList(){
    head = NULL;
    tail = NULL;
}

template <class T>
T& SLList<T>::operator[](const int pos){
    SLLNode<T>* rover = head;
    for(int i = 0; i < pos; i++){
	rover = rover->getNext();
    }
    return rover->getData();
}
template <class T>
bool SLList<T>::append(const T &val){
    bool isAppend = false;
    SLLNode<T>* rover = new SLLNode<T>(val, NULL);
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
void SLList<T>::sort(){
    SLLNode<T>* rover = head;
    while(rover != NULL){
	SLLNode<T>* rover2 = rover;
	SLLNode<T>* rover3 = rover->getNext();
	while(rover3 != NULL){
	    if(rover2->getData() > rover3->getData()){
	        rover2 = rover3;
	    }
	    rover3 = rover3->getNext();
	}
	int x;
	x = rover->getData();
	rover->getData() = rover2->getData();
	rover2->getData() = x;
	rover = rover->getNext();
    }
}


#endif
