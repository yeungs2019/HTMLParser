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
	i++
    }
    return noEquality;
}
/*template <class T>
void Array<T>::msort(T *list, const int len) {
}*/
template <class T>
void Array<T>::qsort(){
    int start;
    int end;
    int temp = ptrArr[(start + end) / 2];
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
    //qSort(ptrArr, end + 1, end);
}

template <class T>
void Array<T>::msort() {
}
template <class T>
void Array<T>::sort() {
}

template <class T>
Array<T>::~Array() {
    delete ptrArr;
}

#endif
