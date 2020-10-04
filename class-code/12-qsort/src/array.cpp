#include <stdio.h>

void print(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quick_sort(int *array, const int size) {
    int pivot = array[0];
    int end;
    int smallIndex = 1; // smallIndex point the beginning of the upper list
                        // IE: the element after the last of the small list

    if (size < 2) { return; }

    for (int index = 1; index < size; index++) {
        if(pivot > array[index]) {
            int temp = array[index];
            array[index] = array[smallIndex];
            array[smallIndex] = temp;
            smallIndex++;
        } 
    }

    array[0] = array[smallIndex - 1];
    array[smallIndex - 1] = pivot;

    // We need to sort the left half
    quick_sort(array, smallIndex - 1);
    // We need to sort the right half
    quick_sort(array + smallIndex, size - smallIndex);
}
