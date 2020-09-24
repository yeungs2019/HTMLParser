#include "unity.h"
#include "sort.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int ary[] = {13, 6, 8, 19, 21, 14, 9001, 42};
    selection_sort(ary, 8);
    TEST_ASSERT_EQUAL_INT(6, ary[0]);
    TEST_ASSERT_EQUAL_INT(8, ary[1]);
    TEST_ASSERT_EQUAL_INT(13, ary[2]);
    TEST_ASSERT_EQUAL_INT(14, ary[3]);
    TEST_ASSERT_EQUAL_INT(19, ary[4]);
    TEST_ASSERT_EQUAL_INT(21, ary[5]);
    TEST_ASSERT_EQUAL_INT(42, ary[6]);
    TEST_ASSERT_EQUAL_INT(9001, ary[7]);
}

void test_simple_iter(void) {
    int ary[] = {13, 6, 8, 19, 21, 14, 9001, 42};
    selection_sort_iter(ary, 8);
    TEST_ASSERT_EQUAL_INT(6, ary[0]);
    TEST_ASSERT_EQUAL_INT(8, ary[1]);
    TEST_ASSERT_EQUAL_INT(13, ary[2]);
    TEST_ASSERT_EQUAL_INT(14, ary[3]);
    TEST_ASSERT_EQUAL_INT(19, ary[4]);
    TEST_ASSERT_EQUAL_INT(21, ary[5]);
    TEST_ASSERT_EQUAL_INT(42, ary[6]);
    TEST_ASSERT_EQUAL_INT(9001, ary[7]);
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_simple_iter);
    return UNITY_END();
}
