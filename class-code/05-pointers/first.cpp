#include <iostream>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int b = 300;
    int bb;
    int *a = &b;
    double *d = (double*) a;
    printf("b = %d\n", b);
    *d = 3.14159;

    printf("b = %d\n", b);

    return 0;
}
