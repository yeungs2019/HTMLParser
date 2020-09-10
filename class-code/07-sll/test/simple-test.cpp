#include "unity.h"
#include "sllist.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    SLL sll;
    sll.add(1);
    TEST_ASSERT(sll[0] == 1);
}

void test_contains(void) {
    SLL sll;
    sll.add(1);
    TEST_ASSERT(sll.contains(1));
    TEST_ASSERT(!sll.contains(2));
}

void test_length(void) {
    SLL sll;
    TEST_ASSERT(sll.getLength() == 0);
    sll.add(1);
    TEST_ASSERT(sll.getLength() == 1);
    sll.add(2);
    TEST_ASSERT(sll.getLength() == 2);
    for (int i = 0; i < 100; i++) {
        sll.add(i + 100);
    }
    TEST_ASSERT(sll.getLength() == 102);
}

void test_insert(void) {
    SLL sll;
    sll.insert(0, 1);
    TEST_ASSERT(sll.contains(1));
    TEST_ASSERT(!sll.contains(2));
    sll.insert(0, 2);
    sll.insert(1, 3);
    sll.insert(3, 4);
    TEST_ASSERT(sll[0] == 2);
    TEST_ASSERT(sll[1] == 3);
    TEST_ASSERT(sll[2] == 1);
    TEST_ASSERT(sll[3] == 4);
}

void test_delete(void) {
    SLL sll;
    sll.insert(0, 1);
    sll.insert(0, 2);
    sll.insert(1, 3);
    sll.insert(3, 4);
    TEST_ASSERT(sll[0] == 2);
    TEST_ASSERT(sll[1] == 3);
    TEST_ASSERT(sll[2] == 1);
    TEST_ASSERT(sll[3] == 4);
    sll.remove(3);
    TEST_ASSERT(sll[0] == 2);
    TEST_ASSERT(sll[1] == 1);
    TEST_ASSERT(sll[2] == 4);
    sll.remove(2);
    TEST_ASSERT(sll[0] == 1);
    TEST_ASSERT(sll[1] == 4);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_contains);
    RUN_TEST(test_length);
    RUN_TEST(test_delete);
    return UNITY_END();
}
