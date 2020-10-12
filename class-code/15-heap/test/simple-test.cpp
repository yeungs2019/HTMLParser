#include "unity.h"
#include "heap.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple1(void) {
    Heap heap;
    heap.add(10);
    heap.add(20);
    heap.add(30);
    TEST_ASSERT_EQUAL_INT(30, heap.removeFirst());
}

void test_simple2(void) {
    Heap heap;
    heap.add(10);
    heap.add(20);
    heap.add(30);
    TEST_ASSERT_EQUAL_INT(30, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(20, heap.removeFirst());
}

void test_complex1(void) {
    Heap heap;
    heap.add(10);
    heap.add(20);
    heap.add(30);
    heap.add(40);
    heap.add(50);
    heap.add(60);
    heap.add(70);
    heap.add(80);
    heap.add(90);
    TEST_ASSERT_EQUAL_INT(90, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(80, heap.removeFirst());
}

void test_complex2(void) {
    Heap heap;
    heap.add(10);
    heap.add(20);
    heap.add(30);
    heap.add(40);
    heap.add(50);
    heap.add(60);
    heap.add(70);
    heap.add(80);
    heap.add(90);
    TEST_ASSERT_EQUAL_INT(90, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(80, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(70, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(60, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(50, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(40, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(30, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(20, heap.removeFirst());
    TEST_ASSERT_EQUAL_INT(10, heap.removeFirst());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple1);
    RUN_TEST(test_simple2);
    RUN_TEST(test_complex1);
    RUN_TEST(test_complex2);
    return UNITY_END();
}
