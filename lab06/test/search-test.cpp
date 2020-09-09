#include "unity.h"
#include "arrays.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_search(void) {
    int ary[] = {1,2,3,4,5,6};
    TEST_ASSERT(search(ary[3]) = 4);
}

void test_nonexistent(void){
	int ary[] = {NULL};
	TEST_ASSERT(search(ary, 0) == -1);
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_search);
    RUN_TEST(test_nonexistent);
    return UNITY_END();
}


