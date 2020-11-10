#include "unity.h"
#include "graphal.hpp"

#include <sstream>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    GraphAL<int> graphal(10);
    TEST_ASSERT(graphal.addEdge(0, 1, 10));
    TEST_ASSERT(graphal.adjacent(0, 1) == 10);
    TEST_ASSERT(graphal.adjacent(0, 2) == -1);
}

void test_remove(void) {
    GraphAL<int> graphal(10);
    TEST_ASSERT(graphal.addEdge(0, 1, 10));
    TEST_ASSERT(graphal.adjacent(0, 1) == 10);
    TEST_ASSERT(graphal.removeEdge(0, 1));
    TEST_ASSERT(graphal.adjacent(0, 1) == -1);
}

std::string test;

void print(int x) {
    std::ostringstream oss;
    oss << test << x;
    test = oss.str();
    printf("x = %d\n", x);
}

void test_depth(void) {
    GraphAL<int> graphal(10);
    TEST_ASSERT(graphal.addEdge(0, 1, 10));
    TEST_ASSERT(graphal.addEdge(0, 2, 10));
    TEST_ASSERT(graphal.addEdge(0, 3, 10));
    TEST_ASSERT(graphal.addEdge(1, 6, 10));
    TEST_ASSERT(graphal.addEdge(1, 7, 10));
    TEST_ASSERT(graphal.addEdge(2, 4, 10));
    TEST_ASSERT(graphal.addEdge(3, 1, 10));
    TEST_ASSERT(graphal.addEdge(3, 7, 10));
    TEST_ASSERT(graphal.addEdge(3, 3, 10));
    TEST_ASSERT(graphal.addEdge(4, 8, 10));
    TEST_ASSERT(graphal.addEdge(4, 1, 10));
    TEST_ASSERT(graphal.addEdge(4, 2, 10));
    TEST_ASSERT(graphal.addEdge(4, 9, 10));
    graphal.depthFirstTraversal(print);
    TEST_ASSERT(test == "0167248935");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_remove);
    RUN_TEST(test_depth);
    return UNITY_END();
}
