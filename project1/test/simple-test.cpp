#include "unity.h"
#include "map.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int key;
    Map map;

    TEST_ASSERT(map.add("John Doe", 1234) == true);
    TEST_ASSERT(map.add("Mason Bradford", 1235) == true);
    TEST_ASSERT(map.add("Scott Winston", 1236) == true);

    TEST_ASSERT(map.get("John Doe", key) == true);
    TEST_ASSERT_EQUAL_INT(1234, key);

    TEST_ASSERT(map.get("Mason Bradford", key) == true);
    TEST_ASSERT_EQUAL_INT(1235, key);

    TEST_ASSERT(map.get("no one", key) == false);

    TEST_ASSERT(map.remove("John Doe") == true);
    TEST_ASSERT(map.get("John Doe", key) == false);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    return UNITY_END();
}
