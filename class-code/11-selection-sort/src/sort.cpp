#include <stdio.h>

void print(int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}

void selection_sort(int *ary, const int size) {
    if (size < 2) { return; }

    // lets find the minimum number
    int minIndex = 0;
    for (int i = 0; i < size; i++){
       if (ary[minIndex] > ary[i]) {
           minIndex = i;
       }
    }

    // Now swap the minimum number with the correct location
    int temp = ary[0];
    ary[0] = ary[minIndex];
    ary[minIndex] = temp;

    //print(ary, size);

    selection_sort(ary + 1, size - 1);
}

void selection_sort_iter(int *ary, const int size) {
    for (int pos = 0; pos < size - 1; pos++) {
        // lets find the minimum number
        int minIndex = pos;
        for (int i = pos + 1; i < size; i++){
           if (ary[minIndex] > ary[i]) {
               minIndex = i;
           }
        }

        // Now swap the minimum number with the correct location
        int temp = ary[pos];
        ary[pos] = ary[minIndex];
        ary[minIndex] = temp;
        //print(ary, size);
    }
}
