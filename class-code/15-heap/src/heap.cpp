#include "heap.hpp"
#include <stdio.h>

Heap::Heap() {
    size = 100;
    arr = new int[size];
    heapSize = 0;
}

static void print(const int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Heap::add(const int val) {
    int currentIndex = heapSize;
    int parentIndex = (heapSize - 1) / 2;

    arr[currentIndex] = val;
    heapSize++;

    while(arr[currentIndex] > arr[parentIndex] && currentIndex > 0) {
        int temp = arr[currentIndex];
        arr[currentIndex] = arr[parentIndex];
        arr[parentIndex] = temp;

        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }

    print(arr, heapSize);
    
}

int Heap::removeFirst() {
    int temp = arr[heapSize - 1];
    arr[heapSize - 1] = arr[0];
    arr[0] = temp;
    heapSize  -= 1;

    printf("after swap, before sift\n");
    print(arr, heapSize);

    int currentIndex = 0;
    int leftIndex = 2 * currentIndex + 1;
    int rightIndex = 2 * currentIndex + 2;

    while (currentIndex < heapSize) {
        if(leftIndex < heapSize 
                && arr[leftIndex] > arr[currentIndex]
                && (rightIndex >= heapSize || arr[leftIndex] > arr[rightIndex])) {
            int temp = arr[leftIndex];
            arr[leftIndex] = arr[currentIndex];
            arr[currentIndex] = temp;
            currentIndex = leftIndex;
        }
        else if (rightIndex < heapSize) {
            int temp = arr[rightIndex];
            arr[rightIndex] = arr[currentIndex];
            arr[currentIndex] = temp;
            currentIndex = rightIndex;
        } 
        else {
            break;
        }
        leftIndex = 2 * currentIndex + 1;
        rightIndex = 2 * currentIndex + 2;
    }

    printf("after sift\n");
    print(arr, heapSize);

    return arr[heapSize];
}
