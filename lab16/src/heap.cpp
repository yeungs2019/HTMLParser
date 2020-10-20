#ifdef HEAP_H
#include "heap.hpp"
#include <cmath>
#include<iostream>
#include <algorithm>

template<class T>
Heap<T>::Heap(const int len) {
    mLen = len;
    mArray = new T[mLen];
    mPos = 0;
}

template<class T>
void Heap<T>::insert(const T& element) {
    mArray[mPos] = element;

    int cpos = mPos;
    int parent = (cpos - 1) / 2;

    while (cpos > 0 && mArray[parent] < mArray[cpos]) {
        T temp = mArray[parent];
        mArray[parent] = mArray[cpos];
        mArray[cpos] = temp;
        cpos = parent;
        parent = (cpos -1)/2;
    }

    mPos++;
}

template<class T>
T& Heap<T>::removeFirst() {
    mPos--;
    T temp = mArray[0];
    mArray[0] = mArray[mPos];
    mArray[mPos] = temp;
    int cpos = 0;
    int lchild = 2 * cpos + 1;
    int rchild = 2 * cpos + 2; 

    while (cpos < mPos) {
        if ((mPos == rchild && mArray[cpos] < mArray[lchild])
                || (mPos > rchild && mArray[cpos] < mArray[lchild] && mArray[lchild] > mArray[rchild])) {
            temp = mArray[lchild];
            mArray[lchild] = mArray[cpos];
            mArray[cpos] = temp;
            cpos = lchild;

        } else if(mArray[cpos] < mArray[rchild] && mPos > rchild) {
            temp = mArray[rchild];
            mArray[rchild] = mArray[cpos];
            mArray[cpos] = temp;
            cpos = rchild;
        } else {
            break;
            //cpos = mPos + 1; // force the while loop to end
        }

        lchild = 2 * cpos + 1;
        rchild = 2 * cpos + 2; 
    }

    return mArray[mPos];
}

template<class T>
T& Heap<T>::operator[](const int pos) {
    return mArray[pos];
}

template <class T>
int Heap<T>::getHeight(int x){
    return ceil(log2(x + 1)) - 1;
}
template <class T>
int Heap<T>::getHeight(){
    return getHeight(mLen);
}

template<class T>
int Heap<T>::getSize() {
}

template<class T>
T* Heap<T>::heapSort() {
    T* newArray = new T[mLen]; 
    T x = 0;
    int size = mLen; 
    for(int i = 0; i < size; i++){
	x = this->removeFirst();
        newArray[i] = x;
    }
    
    T temp;
    T min;
    for(int k = 0; k < size; k++){
	min = k;
	for(int j = k; j < size; j++){
	   if(newArray[j] < newArray[min]){
		min = j;
	   }
	}
	temp = newArray[k];
	newArray[k] = newArray[min];
	newArray[min] = temp;
    }    
    return newArray;
}

template<class T>
Heap<T>::~Heap() {
    delete[] mArray;
    mLen = 0;
    mPos = 0;
}

template<class T>
void Heap<T>::print() {
}
#endif
