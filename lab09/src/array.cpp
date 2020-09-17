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
Array<T>::~Array() {
	delete ptrArr;
}

#endif
