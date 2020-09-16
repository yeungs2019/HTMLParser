#include "stack.hpp"
#include <stdlib.h>

IntStack::IntStack() {
    memSize = 100;
    arr = new int[memSize];
    stackLength = 0;
}

void IntStack::copy(int *ar, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = ar[i];
    }
}

void IntStack::doubleSize() {
    int *old_arr = arr;
    memSize *= 2;
    arr = new int[memSize];
    copy(old_arr, memSize / 2);
}

void IntStack::push(const int val) {
    if(stackLength >= memSize){
        doubleSize();
    }
    arr[stackLength] = val;
    stackLength++;
}

int IntStack::top() {
    return arr[stackLength - 1];
}

void IntStack::pop() {
    stackLength--;
}

