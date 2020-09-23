#ifdef QUEUE_H
#include "queue.hpp"
#include <stdio.h>

//empty constructor
template <class T>
Queue<T>::Queue(){
    mSize = 0;
    std::list<T> mList;
}

//deep copy please
template <class T>
Queue<T>::Queue(const Queue<T> &queue){
}

//free me
template <class T>
Queue<T>::~Queue(){
    for(int i = 0; i < mSize; i++){
	this->mList.pop_back();
    }
}

//return length
template <class T>
int Queue<T>::getLength() const{
    return mSize;
}

//is it empty?
template <class T>
bool Queue<T>::isEmpty() const{
    return this->mList.empty();
}

//print
template <class T>
void Queue<T>::print() const{
}

//push to end of queue
template <class T>
bool Queue<T>::push(const T &val){
   this->mList.push_front(val);
   mSize++;
   return true;
}

// returns first element from queue
template <class T>
T& Queue<T>::first(){
    return this->mList.front();
}

// removes first element form queue
template <class T>
void Queue<T>::pop(){
    this->mList.pop_back();
    mSize--;
}

//returns if two queues contain same elements in same order
template <class T>
bool Queue<T>::operator==(const Queue<T> &queue) const{
    /*if(this->mList.getLength() != queue.getLength()){
	return false;
    }*/
    std::list<T> copymList(this->mList);
    std::list<T> copyQueue(queue.mList);
    
    int length;
    T val1;
    T val2;
    length = queue.getLength();
    for (int i = 0; i < length; i++){
         val1 = copymList.front();
	 val2 = copyQueue.front();
	 copymList.pop_front();
	 copyQueue.pop_front();
	 if (val1 != val2){
             return false;
	 }
    }
    return true;
}
#endif
