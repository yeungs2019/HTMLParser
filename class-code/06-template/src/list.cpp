#ifndef LIST_CPP
#define LIST_CPP

#include "list.hpp"
#include <iostream>

template<class T>
void List<T>::print_first() {
    std::cout << stuff[0] << "\n";
}

#endif
