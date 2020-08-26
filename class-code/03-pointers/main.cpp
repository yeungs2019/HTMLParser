#include <stdio.h>
#include <iostream>

int add(const int a, const int b) {
    return a + b;
}

int infinite_recursion(const int a) {
    return infinite_recursion(a);
}

int main(int argc, char *argv[]) {
    int num;
    int *nums;
    int *nums2;
    int *nums3;
    int ary[100];
    float arr1[10][15];

    nums = new int[100];
    nums2 = new int[10];
    nums3 = new int[100];

    delete [] nums2;

    nums2 = new int[5];

    num = add(4, 5);
    num = add(4, num);
    *nums = num;

    *(nums + 1) = add(nums[0], 5); // Does the same as below
    nums[1] = add(nums[0], 5);     // Does the same as above
    nums[2] = add(nums[0], 5);

    std::cout << "num = " << num << "\n";
    std::cout << "&num = " << &num << "\n";
    std::cout << "nums = " << nums << "\n";
    std::cout << "nums + 100 = " << nums + 100 << "\n";
    std::cout << "*nums = " << *nums << "\n";
    std::cout << "*(nums + 1) = " << *(nums + 1) << "\n";
    std::cout << "nums[2] = " << nums[2] << "\n";
    std::cout << "ary = " << ary << "\n";
    std::cout << "arr1 = " << arr1 << "\n";
    std::cout << "arr1+1 = " << arr1+1 << "\n";

    delete [] nums;

    infinite_recursion(1);
}
