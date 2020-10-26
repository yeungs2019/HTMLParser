#include <stdio.h>
#include <iostream>
#include "hashtable.hpp"

int main(int argc, char *argv[]) {
    HashTable<int, int> table(100, .75);

    for (int i = 0; i < 40; i++) {
        table.insert(i, i+100);
    }

    std::cout << table.percentFull() << "\n";
    return 0;
}
