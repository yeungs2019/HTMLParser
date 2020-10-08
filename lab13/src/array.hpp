#ifndef ARRAY_H:
#define ARRAY_H

template <class T>
class Array {
    private:
	T* ptrArr;
	int fitSize;
    public:
    /* Do a deep copy of the array into the list.
     * Note: This one uses a pointer!
     */
    Array(const T *array, const int size);
    /* Do a deep copy of the array into the list
     * Note: This one uses a reference to a List!
     */
    Array(const Array<T> &list);

    /* Return the current length of the array */
    int getLength() const;

    /* Returns the index in the array where value is found.  
     * Return -1 if value is not present in the array.
     */
    int indexOf(const T &value);

    /* Removes an item at position index by shifting later elements left.
     * Returns true iff 0 <= index < size.
     */
    bool remove(const int index);

    /* Retrieves the element at position pos */
    T& operator[](const int pos);

    /* Returns if the two lists contain the same elements in the
     * same order.
     */
    bool operator==(Array<T> &list) const;

    void qsort();
    void qsorts(T* array, const int size);
    //int partition(int *a, int start, int end);
    //void msort(int *ptrArr, int low, int high)
    int min(int x, int y);
    void msort();
    void merge(int *a, int l, int m, int r);
    //void merge(int *a, int *t, int from, int mid, int to);
    //void merge(int *a, int l, int m, int r);
    //void merge(int *a, int size, int low, int high, int mid);
    //void merge(int *ptrArr, int low, int high, int middle);
    void sort();

    /* Free any memory used! */
    ~Array();
};

/* Since Array is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly declared).
 */
#include "array.cpp"

#endif
