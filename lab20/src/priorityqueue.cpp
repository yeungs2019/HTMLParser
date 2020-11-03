#ifdef PRIORITY_QUEUE_H
#include "priorityqueue.hpp"
#include <stdio.h>
#include <algorithm>

template<class T>
PriorityQueue<T>::PriorityQueue() {
    //mSize = 0;
    //std::vector<T> mVector;
    std::make_heap(mVector.begin(), mVector.end());
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq) {
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    /*for(int i = 0; i < mSize; i++){
	mVector.pop_back();
    }*/
    mVector.clear();
}

template<class T>
int PriorityQueue<T>::getLength() const{
    return mVector.size();
}

template<class T>
bool PriorityQueue<T>::isEmpty() const{
    return mVector.empty();
}

template<class T>
bool PriorityQueue<T>::push(const T &val){
     //std::make_heap(mVector.begin(), mVector.end());
     mVector.push_back(val);
     std::push_heap(mVector.begin(), mVector.end());
     //mSize++;
     return true;
}

template<class T>
T PriorityQueue<T>::pop(){
    //std::make_heap(mVector.begin(), mVector.end());
    T mVal = mVector.front();
    std::pop_heap(mVector.begin(), mVector.end());
    mVector.resize(mVector.size() - 1);
    return mVal;
}

template<class T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T> &pq) const{
    if(pq.getLength() != mVector.size()){
	return false;
    }
    for(int i = 0; i < mVector.size(); i++){
	if(pq[i] != mVector[i]){
	    return false;
	}
    }
    return true;
}



#endif
