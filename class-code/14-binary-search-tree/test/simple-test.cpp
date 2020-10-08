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

void test_delete1(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(4));
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    TEST_ASSERT_EQUAL(false, bst.contains(6));
    bst.add(4);
    bst.add(3);
    bst.add(5);
    bst.add(6);
    TEST_ASSERT_EQUAL(true, bst.contains(6));
    bst.remove(6);
    TEST_ASSERT_EQUAL(false, bst.contains(6));
    bst.print();
}

void test_delete2(void) {
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
    bst.remove(3);
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(true, bst.contains(6));
    bst.print();
}

void test_delete3(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(4));
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    TEST_ASSERT_EQUAL(false, bst.contains(6));
    bst.add(4);
    bst.add(3);
    bst.add(5);
    bst.add(6);
    TEST_ASSERT_EQUAL(true, bst.contains(5));
    bst.remove(5);
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    TEST_ASSERT_EQUAL(true, bst.contains(6));
    bst.print();
}

void test_delete4(void) {
    BST bst;
    TEST_ASSERT_EQUAL(false, bst.contains(3));
    TEST_ASSERT_EQUAL(false, bst.contains(4));
    TEST_ASSERT_EQUAL(false, bst.contains(5));
    TEST_ASSERT_EQUAL(false, bst.contains(6));
    bst.add(4);
    bst.add(3);
    bst.add(10);
    bst.add(20);
    bst.add(8);
    bst.add(9);
    bst.add(6);
    bst.add(15);
    bst.add(30);
    TEST_ASSERT_EQUAL(true, bst.contains(10));
    bst.remove(10);
    TEST_ASSERT_EQUAL(false, bst.contains(10));
    TEST_ASSERT_EQUAL(true, bst.contains(6));
    TEST_ASSERT_EQUAL(true, bst.contains(30));
    bst.print();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_simple2);
    RUN_TEST(test_simple3);
    RUN_TEST(test_simple4);
    RUN_TEST(test_delete1);
    RUN_TEST(test_delete2);
    RUN_TEST(test_delete3);
    RUN_TEST(test_delete4);
    return UNITY_END();
}
