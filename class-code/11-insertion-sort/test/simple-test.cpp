#include "unity.h"
#include "sort.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int ary[] = {9001, -10, 37, 42, 0, 7, 15, 64};
    insertion_sort(ary, 8);
    TEST_ASSERT_EQUAL_INT(-10, ary[0]);
    TEST_ASSERT_EQUAL_INT(0, ary[1]);
    TEST_ASSERT_EQUAL_INT(7, ary[2]);
    TEST_ASSERT_EQUAL_INT(15, ary[3]);
    TEST_ASSERT_EQUAL_INT(37, ary[4]);
    TEST_ASSERT_EQUAL_INT(42, ary[5]);
    TEST_ASSERT_EQUAL_INT(64, ary[6]);
    TEST_ASSERT_EQUAL_INT(9001, ary[7]);
}

void test_simple_iter(void) {
    int ary[] = {9001, -10, 37, 42, 0, 7, 15, 64};
    insertion_sort_iter(ary, 8);
    TEST_ASSERT_EQUAL_INT(-10, ary[0]);
    TEST_ASSERT_EQUAL_INT(0, ary[1]);
    TEST_ASSERT_EQUAL_INT(7, ary[2]);
    TEST_ASSERT_EQUAL_INT(15, ary[3]);
    TEST_ASSERT_EQUAL_INT(37, ary[4]);
    TEST_ASSERT_EQUAL_INT(42, ary[5]);
    TEST_ASSERT_EQUAL_INT(64, ary[6]);
    TEST_ASSERT_EQUAL_INT(9001, ary[7]);
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_simple_iter);
    return UNITY_END();
}
