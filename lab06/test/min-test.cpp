#include "unity.h"
#include "arrays.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_empty() {
    int ary[] = {};
    TEST_ASSERT(findMinOdd(ary, 0) == -1);
}

void test_simple(void) {
    int ary[] = {1, 2, 3, -5, -9, 0};
    TEST_ASSERT(findMinOdd(ary, 6) == -9);
}

void test_positives(void) {
    int ary[] = {1, 2, 19,  5,  9, 0};
    TEST_ASSERT(findMinOdd(ary, 6) == 1);
}
void test_evens(void) {
	int ary[] = {2, 4, -2, 6};
	TEST_ASSERT(findMinOdd(ary, 4) == -1);
}
void test_low(void){
	int ary[] = {1, -3, 5};
	TEST_ASSERT(findMinOdd(ary, 3) == -3);
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_empty);
    RUN_TEST(test_simple);
    RUN_TEST(test_positives);
    RUN_TEST(test_evens);
    RUN_TEST(test_low);
    return UNITY_END();
}
