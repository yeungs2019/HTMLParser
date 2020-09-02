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
    TEST_ASSERT(countNegatives(ary, 0) == 0);
}

void test_simple(void) {
    int ary[] = {1, 2, 3, -5, -9, 0};
    TEST_ASSERT(countNegatives(ary, 6) == 2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_empty);
    RUN_TEST(test_simple);
    return UNITY_END();
}
