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
	ptr = new T[size];
	fit = size;
	for (int i = 0; i < size; i++) {
		ptr[i] = *array[i];
	}
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
}

template <class T>
int Array<T>::getLength() const {
	for (int i = 0; i < fit; i++) {
		if (arr[i] == fit) {
			return fit;
		}
	}
	return 0;
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
}

template <class T>
Array<T>::~Array() {
}

#endif
