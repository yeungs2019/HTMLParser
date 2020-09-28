#include <stdio.h>

void print(int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}

void insertion_sort(int *ary, const int size) {
    int afterPos; // the position after where the element should go.
    if (size < 2) { return; }

    // We assume that this sorts
    insertion_sort(ary, size - 1);

    // Now we add the next element
    // We need to add ary[size-1] to the list.
    for(afterPos = 0; afterPos < size; afterPos++) {
        if(ary[size - 1] < ary[afterPos] ) {
            break;
        }
    }
    
    int temp = ary[size - 1];

    for(int i = size - 1; i > afterPos; i--) {
        ary[i] = ary[i - 1];
    }

    ary[afterPos] = temp;
    print(ary, size);
}

void insertion_sort_iter(int *ary, const int size) {
    int afterPos; // the position after where the element should go.
    if (size < 2) { return; }


    for (int subSize = 2; subSize <= size; subSize++) {
        // Now we add the next element
        // We need to add ary[size-1] to the list.
        for(afterPos = 0; afterPos < subSize; afterPos++) {
            if(ary[subSize - 1] < ary[afterPos] ) {
                break;
            }
        }
    
        int temp = ary[subSize - 1];

        for(int i = subSize - 1; i > afterPos; i--) {
            ary[i] = ary[i - 1];
        }

        ary[afterPos] = temp;
        print(ary, size);
    }
}
