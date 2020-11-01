#ifdef PRIORITY_QUEUE_H
#include "priorityqueue.hpp"
#include <stdio.h>
#include <algorithm>

template<class T>
PriorityQueue<T>::PriorityQueue() {
    mSize = 0;
    std::vector<T> mVector;
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq) {
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    for(int i = 0; i < mSize; i++){
	mVector.pop_back();
    }
}

template<class T>
int PriorityQueue<T>::getLength() const{
    return mSize;
}

template<class T>
bool PriorityQueue<T>::isEmpty() const{
    return mVector.empty();
}

template<class T>
bool PriorityQueue<T>::push(const T &val){
     std::make_heap(mVector.begin(), mVector.end());
     mVector.push_back(val);
     std::push_heap(mVector.begin(), mVector.end());
     mSize++;
     return true;
}




#endif
