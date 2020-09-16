#include "unity.h"
#include "testme.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    TEST_ASSERT_EQUAL_INT(10, 10);
    TEST_ASSERT(10 == 10);
}

void test_p1p() {
    TEST_ASSERT_EQUAL_INT(2, test1p1());
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_p1p);
    return UNITY_END();
}
