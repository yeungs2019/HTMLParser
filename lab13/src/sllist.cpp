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
    
}
    




#endif
