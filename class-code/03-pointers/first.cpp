#include <stdio.h>
#include <iostream>

int add(const int a, const int b) {
    return a + b;
}

int main(int argc, char *argv[]) {
    int num;
    int *nums;

    nums = &num;
    num = add(4, 5);
    num = add(4, num);

    std::cout << "num = " << num << "\n";
    std::cout << "nums = " << nums << "\n";
    std::cout << "*nums = " << *nums << "\n";
    std::cout << "&nums = " << &nums << "\n";
}
