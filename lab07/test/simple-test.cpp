#include "unity.h"
#include "array.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int ary[] = {1, 2, 3, 4};

    Array<int> a(ary, 4);
    Array<int> a2(a);

    TEST_ASSERT(a.getLength() == 4);
    TEST_ASSERT(a2.getLength() == 4);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    return UNITY_END();
}
