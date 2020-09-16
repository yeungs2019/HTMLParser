#include "unity.h"
#include "stack.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    IntStack stack;
    stack.push(10);
    TEST_ASSERT_EQUAL_INT(10, stack.top());
    stack.push(15);
    TEST_ASSERT_EQUAL_INT(15, stack.top());
}

void test_pop(void) {
    IntStack stack;
    stack.push(10);
    TEST_ASSERT_EQUAL_INT(10, stack.top());
    stack.push(15);
    TEST_ASSERT_EQUAL_INT(15, stack.top());
    stack.pop();
    TEST_ASSERT_EQUAL_INT(10, stack.top());
}

void test_stress(void) {
    IntStack stack;
    for (int i = 0; i < 1000000; i++) {
        stack.push(i);
        TEST_ASSERT_EQUAL_INT(i, stack.top());
    }
    for (int i = 999999; i >= 0; i--) {
        TEST_ASSERT_EQUAL_INT(i, stack.top());
        stack.pop();
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_pop);
    RUN_TEST(test_stress);
    return UNITY_END();
}
