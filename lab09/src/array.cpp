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
	ptrArr= new T[size];
	fitSize = size;
	for (int i = 0; i < size; i++){
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
        for (int i = 0; i < fitSize; i++) {
                ptrArr[i] = list.ptrArr[i];
        }
}

template <class T>
int Array<T>::getLength() const {
        return fitSize;
}

// Returns index in the array where value is found.
template <class T>
int Array<T>::search(const T &value){
        for (int i = 0; i < fitSize; i++) {
                if(ptrArr[i] == value){
                        return i;
                }
        }
        return -1;
}

// Removes an item at position index by shifting later elements left.
template <class T> // from https://stackoverflow.com/questions/879603/remove-an-array-element-and shift-the-remaining-ones
bool Array<T>::remove(const int index){
        bool found = false;
        if (index >= 0 && index < fitSize){
                for (int i = index; i < fitSize; i++){
                        ptrArr[i] = ptrArr[i+1];
                }
                found = true;
                fitSize--;
        }
        return found;
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
	return ptrArr[pos];
}

// Returns if the two lists contain the same elements in the same order
template <class T> // from https://stackoverflow.com/questions/12866413/comparing-arrays-for-equality-in-c
bool Array<T>::operator==(Array<T> &list) const {
        bool noEquality = false;
        if (this->getLength() != list.getLength()) {
                return false;
        }
        for (int i = 0; i < fitSize; i++){
                if (ptrArr[i] == list[i]) {
                        noEquality = true;
                }
                else if (ptrArr[i] < list[i]) {
                        noEquality = false;
                }
                else if (ptrArr[i] > list[i]){
                        noEquality = false;
                }
                else if (ptrArr[i] < list[i - 1]){
			 noEquality == false;
                }
                /*else if (!ptrArr[i] != list[i]){
                        noEquality == false;
                }
                else if (ptrArr[i] != !list[i]){
                        noEquality == false;
                }
                else if (!ptrArr[i] != !list[i]){
                        noEquality == false;
                }
                else if (ptrArr[i] == list[i + 1]){
                        noEquality == false;
                }*/

                i++;
        }
        return noEquality;
}

template <class T>
void Array<T>::bubbleSort() {
	int location;
	for(int i = 0; i < fitSize; i++){
		for (int j = i; j < fitSize; j++){
			if (ptrArr[i] > ptrArr[j]){
				location = ptrArr[i];
				ptrArr[i] = ptrArr[j];
				ptrArr[j] = location;
			}
		}
	}
}
template <class T>
void Array<T>::print()const{
	for (int i = 0; i < fitSize; i++){
		printf("%d ", ptrArr[i]);
	}
	printf("\n");
}
/*template<class T>
int Array<T>::retArray(T* arr, int size, T val){
	if (size <= 0){
		return -1;
	}
	int middle = size / 2;
	int even = (size + 1) % 2;
	if (arr[middle] = val){
		return middle;
	}
	if(arr[middle] > val){
		//return middle - 1;
		return retArray(arr, middle, val);
	}
	return middle + 1 + retArray(arr + (middle + 1), middle - even, val);
		
}*/
/*template <class T>
int Array<T>::retArray(T* arr, int beg, int end, T val){
	if (end > beg){
		return -1;
	}
	int middle = (beg + end) / 2;
	if(arr[middle] > val){
		return retArray(arr, beg, middle - 1, val);
	}
	else if (arr[middle] < val){
		return retArray(arr, middle + 1, end, val);
	}
	else{
		return middle;
	}
}*/
template <class T>
int Array<T>::binarySearch(const T &value) {
	int size = this->getLength();
	int left = 0;
	int right = size;
	int middle = (left + right) / 2;
	//int beg;
	//int end;
	if (size <= 0){
		return -1;
	}
	if (size == 1){
		return -1;
	}
	while(left < right){
		printf("Looking at %d\n", ptrArr[fitSize/2]);
		//printf("\n");
		print();
		//int middle = left + (right - left) / 2;
		if (ptrArr[middle] == value) {
                        return middle;
			//return left = middle + 1;
                }
		// printf("Look at the middle %d\n", ptrArr[middle]);
                // print();
	
                if (value < this->ptrArr[middle]){
			right = middle;
			middle = (left + right) / 2;
                        //return right;
			//return left = middle + 1;
                }
		printf("Look at the right %d\n", ptrArr[right]);
		printf("left %d\n", ptrArr[left]);
		print();
                if (value > this->ptrArr[middle]){
			left = middle + 1;
			middle = (left + right) / 2;
			//return right = middle - 1;
                }
		printf("Look at the left %d\n", ptrArr[left]);
		print();
	}
	return -1;
	//printf("exited while loop\n");
	//print();
	//retArray(ptrArr, fitSize, value);
}


template <class T>
Array<T>::~Array() {
	delete ptrArr;
}

#endif
