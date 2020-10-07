#include <iostream>

void print(int val) {
    printf("My value is %d\n", val);
}

static int sum = 0;

void find_sum(int val) {
    sum += val;
}

void execute_function(void (*func) (int val)) {
    for (int i = 0; i < 100; i++) {
        func(i);
    }
}

int main(int argc, char *argv[]) {
    execute_function(print);
    execute_function(find_sum);
    printf("sum = %d\n", sum);
    return 0;
}
