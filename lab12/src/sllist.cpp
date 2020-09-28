#ifdef SLLIST_HPP
#include<iostream>

template <class T>
SLList<T>::SLList(){
    head = NULL;
    tail = NULL;
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
