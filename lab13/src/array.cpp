/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>

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
	    temp = ptrArr[left];
	    ptrArr[left] = ptrArr[right];
	    ptrArr[right] = temp;
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
void Array<T>::merge(int *a, int size, int low, int high, int mid){
    int i, j, k;
    int *c = new int[size];
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high){
	if(a[i] < a[j]){
	    c[k] = a[i];
	    k++;
	    i++;
	}
	else{
	    c[k] = a[j];
	    k++;
	    j++;
	}
    }
    while(i <= mid){
	c[k] = a[i];
	k++;
	i++;
    }
    while(j <= high){
        c[k] = a[j];
	k++;
	j++;
    }
    for(i = low; i < k; i++){
	a[i] = c[i];
    }
}
template <class T>
void Array<T>::msort(){
    int mid;
    int size = this->getLength();
    int low;
    int high;
    for(int i = 2; i <= size; i *= 2){
	for(int x = 0; x < size; x += i){
	    int newHigh;
	    if(x + i - 1 < size - 1){
		newHigh = x + i - 1;
	    }
	    else{
		mid = (newHigh - low) / 2;
		merge(ptrArr, size, x, newHigh, mid);
	    }
	}
	return;
    }	
}
template <class T>
void Array<T>::sort() {
}

template <class T>
Array<T>::~Array() {
    delete ptrArr;
}

#endif
