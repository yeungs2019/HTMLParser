#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
#include <stdio.h>

// Empty constructor
template <class T>
Stack<T>::Stack() {
    head = NULL;
    tail = NULL;
}

// Deep copy please
template <class T>
Stack<T>::Stack(const Stack<T> &stack) {
    stackNode<T>* rover = stack.head;
    head = NULL;
    for (int i = 0; i < stack.getLength(); i++){
	append(rover->getData());
	rover = rover->getNext();
    }
}
        
// Free memory
template <class T>
Stack<T>::~Stack() {
    stackNode<T>* rover = head;
    stackNode<T>* toDelete = rover;
    while (rover != NULL){
        rover = rover->getNext();
	toDelete = rover;
	delete rover;
    }
}

// return current length in stack
template <class T>
int Stack<T>::getLength() const {
    stackNode<T>* rover = head;
    int newLength = 0;
    while (rover != NULL){
        newLength++;
	rover = rover->getNext();
    }
    return newLength;
}
template <class T>
bool Stack<T>::append(const T &val){
   bool isAppend = false;
   stackNode<T>* rover = new stackNode<T>(val, NULL);
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

// returns true if stack is empty
template <class T>
bool Stack<T>::isEmpty() const{
    stackNode<T>* rover = head;
    if(rover == NULL){
        return true;
    }
    return false;
}

// print out stack
template <class T>
void Stack<T>::print() const{
}

// pushes the val to top of stack
template <class T>
bool Stack<T>::push(const T &val) {
    //bool isPush = false; 
    stackNode<T>* rover = new stackNode<T>(val, NULL);
    //stackNode<T>* top = NULL;
    /*while(rover != NULL && rover->getData() != val){
	rover = rover->getNext();
	top = rover;
	isPush = true;
    }*/
    /*if (top == NULL){
	//printf("This is the top's value %d\n", top);
	//print();
        top = rover;
	printf("This is the top's value %d\n", top);
        print();

	printf("This is rover's %d\n", rover);
	print();
	return true;
    }
    else{
	top = rover->getNext();
	printf("This is new top %d\n", top);
	print();
        top = rover;
	printf("This is new rover %d\n", rover);
	print();
	return true;
    }*/	
    //return isPush;
    /*rover->getData() = val;
    rover->getNext() = top;
    top = rover;
    return true;*/
    rover->setNext(head);
    head = rover;
}

// returns the top element from the stack
template <class T>
T& Stack<T>::top() {
    /*if (head == NULL){
        return NULL;
    }
    stackNode<T>* temp = head;
    while(temp->getNext() != NULL){
	temp = temp->getNext();
    }
    temp = temp->getData();
    return temp;*/
    /*if(!isEmpty()){
       head = head->getData();
       return head;
    }*/   
    if (head != NULL){
        return head->getData();
    }    
}

// removes top element from stack
template <class T>
void Stack<T>::pop() {
   //stackNode<T>* top = head;
   stackNode<T>* temp = NULL;
   /*int tempData;
   if (top == NULL){
           return;
   }
   else{
	   tempData = top->getData();
	   top = top->getNext();
	   delete temp;
   }*/
   if (head != NULL){
       temp = head;
       head = head->getNext();
       delete temp;
   }
   else{
       return;
   }
}

// returns if two stacks contain same elements in same order
template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const{
    stackNode<T>* rover = head;
    stackNode<T>* rover2 = stack.head;
    if (this->getLength() != stack.getLength()){
        return false;
    }
    if (this->head == NULL && stack.head == NULL){
	return true;
    }
    while(rover != NULL && rover2 != NULL){
	if(rover->getData() == rover2->getData()){
	    rover = rover->getNext();
	    rover2 = rover2->getNext();
	}
    	else{
	    return false;
	}
    }
}

#endif
