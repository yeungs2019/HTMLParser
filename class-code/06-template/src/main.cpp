#include <iostream>
#include "list.hpp"

template<class T>
T add(T a, T b) {
    T temp = a + b;
    return temp;
}


int main(int argc, char *argv[]) {
    List<int> l;
    List<std::string> ls;
    l.stuff[0] = 1234;
    ls.stuff[0] = "HELLO!!!!!!!!!!";
    // This function generate:
    /* int add (int a, int b) {
           return a + b;
       }
       */
    std::cout << "2 + 2 = " << add(2, 2) << "\n";
    // This function generate:
    /* double add (double a, double b) {
           return a + b;
       }
       */
    std::cout << "2.4 + 2.6 = " << add(2.4, 2.6) << "\n";
    std::cout << "2 + 3 = " << add(2, 3) << "\n";
    //std::cout << "'c' + 'd' = " << add("c", "d") << "\n";

    l.print_first();
    //std::cout << l.stuff[0] << "\n";
    //std::cout << ls.stuff[0] << "\n";
    return 0;
}
