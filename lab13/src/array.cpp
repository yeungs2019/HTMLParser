/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
    ptrArr = new T[size];
    fitSize = size;
    for(int i = 0; i < size; i++){
        ptrArr[i] = array[i];
    }
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
    ptrArr = new T[list.fitSize];
    fitSize = list.fitSize;
    for(int i = 0; i < fitSize; i++){
        ptrArr[i] = list.ptrArr[i];
    }
}
// return the length
template <class T>
int Array<T>::getLength() const{
     return fitSize;
}
template <class T>
int Array<T>::indexOf(const T &value){
    for(int i = 0; i < fitSize; i++){
	if(ptrArr[i] == value){
	    return i;
	}
    }
    return -1;
}
template <class T>
bool Array<T>::remove(const int index){
    bool found = false;
    if(index >= index && index < fitSize){
	for(int i = index; i < fitSize; i++){
 	    ptrArr[i] == ptrArr[i + 1];
	}
	found = true;
	fitSize--;
    }
    return found;
}
template <class T>
T& Array<T>::operator[](const int pos){
    return ptrArr[pos];
}
template <class T>
bool Array<T>::operator==(Array<T> &list) const{
    bool noEquality = false;
    if(this->getLength() != list.getLength()){
	return false;
    }
    for (int i = 0; i < fitSize; i++){
	if(ptrArr[i] == list[i]){
	    noEquality = true;
	}
	else if(ptrArr[i] < list[i]){
	    noEquality = false;
	}
	else if(ptrArr[i] > list[i]){
	    noEquality = false;
	}
	else if(ptrArr[i] < list[i - 1]){
	    noEquality = false;
	}
	i++;
    }
    return noEquality;
}
/*template <class T>
void Array<T>::merge(T* list, const int) {
}*/
/*template <class T>
int Array<T>::partition(int *a, int start, int end){
   int pivot = a[end];
   int pIndex = start;
   for(int i = start; i < end; i++){
	if(a[i] < pivot){
	    std::swap(a[i], a[pIndex]);
	    pIndex++;
	}
   }
   std::swap(a[pIndex], a[end]);
   return pIndex;
}
template <class T>
void Array<T>::qsort(){
    int start;
    int end;
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;
    while(top >= 0){
    	end = stack[top--];
	start = stack[top--];
	int pivotIndex = partition(ptrArr, start, end);
	if (pivotIndex - 1 > start){
	    stack[++top] = start;
	    stack[++top] = pivotIndex - 1;
	}
	if(pivotIndex + 1 < end){
	    stack[++top] = pivotIndex + 1;
	    stack[++top] = end;
	}
    }
}*/

template <class T>
void Array<T>::qsort(){
    int size = this->getLength();
    int left = 0;
    int right = size;
    int pivot = ptrArr[(left + right) / 2];
    int temp;
    if(size <= 0){
	return;
    }
    while(left <= right){
	while(ptrArr[left] < pivot){
	    left++;
	}
	while(ptrArr[right] > pivot){
	    right--;
	}
	if(left <= right){
	    /*temp = ptrArr[left];
	    ptrArr[left] = ptrArr[right];
	    ptrArr[right] = temp;*/
	    std::swap(ptrArr[left], ptrArr[right]);
	    left++;
	    right--;
	 }
      }
}

	

    /*int temp = ptrArr[(start + end) / 2];
    //int temp2 = (start + end) / 2;
    int rov;
    while(start < end){
	while(ptrArr[end] > temp){
	    end--;
	}
	while(ptrArr[start] <= temp && start <= end){
	    start++;
	}
	if(start < end){
	    rov = ptrArr[end];
	    ptrArr[end] = ptrArr[start];
	    ptrArr[start] = rov;
	}
    }
    ptrArr[end] = temp;
    //qSort(ptrArr, start, end - 1);
    //qSort(ptrArr, end + 1, end);*/
//}

/*template <class T>
void Array<T>::merge(int *ptrArr, int low, int high, int middle) {
    //int size = this->getLength();
    int i;
    int j;
    int k;
    int temp[end - start + 1];
    int i = low;
    int j = middle + 1;
    int k = 0;
    while(i <= middle && j <= high){
	if(ptrArr[i] < ptrArr[j]){
	    temp[k] = ptrArr[i];
	    k++;
	    i++;
	}
	else{
	    temp[k] = ptrArr[j];
	    k++;
	    j++;
	}
    }
    while(i <= middle){
	temp[k] = ptrArr[i];
	k++;
	i++;
    }
    while(j <= high){
	temp[k] = ptrArr[j];
	k++;
	j++;
    }
    for(i = low; i <= high i++){
	ptrArr[i] = temp[i - low];
    }
}*/
template <class T>
int Array<T>::min(int x, int y){ return (x<y)? x :y; }

template <class T>
void Array<T>::merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++){
	L[i] = a[l + i];
    }
    for(j = 0; j < n2; j++){
	R[j] = a[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = 1;
    while(i < n1 && j < n2){
	if(L[i] <= R[j]){
	    a[k] = L[i];
	    i++;
	}
	else{
	    a[k] = R[j];
	    j++;
	}
	k++;
    }
    while(i < n1){
	a[k] = L[i];
	i++;
	k++;
    }
    while(j < n2){
        a[k] = R[j];
	j++;
	k++;
    }
}
template <class T>
void Array<T>::msort(){
    int curr;
    int left;
    int size = (sizeof(ptrArr) / sizeof(ptrArr[0]) - 1);
    for(curr = 1; curr <= size - 1; curr = 2 * curr){
	for(left = 0; left < size - 1; left += 2 * curr){
	     int mid = min(left + curr - 1, size + 1);
	     //int mid = left + curr -1;
	     int right = min(left + 2*curr - 1, size+ 1);
	     merge(ptrArr, left, mid, right);
	}
    }
}

/*
template <class T>
void Array<T>::merge(int *a, int *t, int from, int mid, int to){
    int k = from;
    int i = from;
    int j = mid + 1;
    while(i <= mid && j <= to){
	if(a[i] < a[j]){
	    t[k++] = a[i++];
	}
	else{
	    t[k++] = a[j++];
	}
    }
    while(i < N && i <= mid){
         t[k++] = a[i++];
    }
    for(i = from; i <= to; i++){
	 a[i] = t[i];
    }
}
template <class T>
void Array<T>::msort(){
    int high, low;
    int *temp;
    for(int m = 1; m <= high - low; m = 2*m){
	for(int i = low; i < high; i += 2*m){
	     int from = i;
	     int mid = i + m - 1;
	     int to = min(i + 2*m - 1, high);
	     merge(ptrArr, temp, from, mid, to);
	}
    }
}*/

template <class T>
void Array<T>::sort() {
}

template <class T>
Array<T>::~Array() {
    delete ptrArr;
}

#endif
