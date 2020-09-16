#include "unity.h"
#include "sllist.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/*void test_simple(void) {
    TEST_ASSERT_EQUAL_INT(10, 1);
    TEST_ASSERT(10 == 0);
}*/
/*void test_length(void) {
    SLList<int> sll;
    TEST_ASSERT(sll.getLength() == 0);
}*/
void test_remove(void) {
    SLList<int> sll;
    TEST_ASSERT(sll.remove(2));
}


int main(void) {
    UNITY_BEGIN();
   // RUN_TEST(test_simple);
    RUN_TEST(test_remove);
    return UNITY_END();
}
