#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    SLList<int> sll;

    sll.append(1);
    cout << "Append a 5 " << sll.append(5) << endl;
    sll.remove(2);
    cout << "Remove a 2 " << sll.remove(2) << endl;

}

