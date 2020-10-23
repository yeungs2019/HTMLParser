#include "unity.h"
#include "hashtable.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    HashTable<int, int> ht(100);
    TEST_ASSERT(true == ht.insert(0, 512));
    TEST_ASSERT(true == ht.insert(100, 1025));
    TEST_ASSERT_EQUAL_INT(1025, ht[100]);
}

void test_no_dups(void) {
    HashTable<int, int> ht(100);
    TEST_ASSERT(true == ht.insert(0, 512));
    TEST_ASSERT(false == ht.insert(0, 1025));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_no_dups);
    return UNITY_END();
}