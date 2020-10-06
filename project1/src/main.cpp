#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include "map.hpp"
using namespace std;

int main(int argc, char *argv[]) {
   Map vec;
   int key;
    
   //vec.add("Dangerous Jackelope", 12345678);
   //vec.print();
   //vec.add("Dr West", 34245234);
   //vec.print();
   //vec.add("Nyhmdas Patrick", 87387078); 
   //vec.print();
   key = 2534234;
   vec.get("Dangerous Jack", key);
   vec.print();
   key = 73893487;
   vec.get("Dr West", key);
   vec.print();
   key = 72333332;
   vec.get("Richard tech", key);
   vec.print();
   return 0;
   
}

