#include "unity.h"
#include "array.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int ary[] = {32, 5, 9, 6, 75, 10, 201, 21};
    quick_sort(ary, 8);
    TEST_ASSERT_EQUAL_INT(5, ary[0]);
    TEST_ASSERT_EQUAL_INT(6, ary[1]);
    TEST_ASSERT_EQUAL_INT(9, ary[2]);
    TEST_ASSERT_EQUAL_INT(10, ary[3]);
    TEST_ASSERT_EQUAL_INT(21, ary[4]);
    TEST_ASSERT_EQUAL_INT(32, ary[5]);
    TEST_ASSERT_EQUAL_INT(75, ary[6]);
    TEST_ASSERT_EQUAL_INT(201, ary[7]);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    return UNITY_END();
}
