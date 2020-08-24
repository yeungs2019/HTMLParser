#include <iostream>
#include <stdio.h>

void rehelloagain();

int main(int argc, char *argv[]) {
    int *nums = new int[100];

    //printf("Hello!\n");

    //rehelloagain();

    for (int i = 0; i < 100; i++) {
        nums[i] = i;
    }

    printf("freeing memory and exiting!\n");

    delete [] nums;
    
    return 0;
}
