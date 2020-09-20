#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

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
    if(head == NULL){
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
    stackNode<T>* top = NULL;
    /*while(rover != NULL && rover->getData() != val){
	rover = rover->getNext();
	top = rover;
	isPush = true;
    }*/
    if (top == NULL){
        top = rover;
	return true;
    }
    else{
	top = rover->getNext();
        top = rover;
	return true;
    }	
    //return isPush;
}

// returns the top element from the stack
template <class T>
T& Stack<T>::top() {
}

// removes top element from stack
template <class T>
void Stack<T>::pop() {
}

// returns if two stacks contain same elements in same order
template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const{
}

#endif
