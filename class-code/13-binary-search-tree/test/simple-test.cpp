#include "unity.h"
#include "BST.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    BST bst;
    bst.add(3);
    TEST_ASSERT_EQUAL(true, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(13));
}

void test_simple2(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    bst.add(3);
    TEST_ASSERT_EQUAL(true, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(13));
}

void test_simple3(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(4));
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    bst.add(4);
    bst.add(3);
    bst.add(5);
    TEST_ASSERT_EQUAL(true, bst.contains(3));
    TEST_ASSERT_EQUAL(true, bst.contains(4));
    TEST_ASSERT_EQUAL(true, bst.contains(5));
    TEST_ASSERT_EQUAL(false, bst.contains(13));
}

void test_simple4(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(4));
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    TEST_ASSERT_EQUAL(false, bst.contains(6));
    bst.add(4);
    bst.add(3);
    bst.add(5);
    bst.add(6);
    TEST_ASSERT_EQUAL(true, bst.contains(3));
    TEST_ASSERT_EQUAL(true, bst.contains(4));
    TEST_ASSERT_EQUAL(true, bst.contains(5));
    TEST_ASSERT_EQUAL(true, bst.contains(6));
    TEST_ASSERT_EQUAL(false, bst.contains(13));
    bst.print();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_simple2);
    RUN_TEST(test_simple3);
    RUN_TEST(test_simple4);
    return UNITY_END();
}
