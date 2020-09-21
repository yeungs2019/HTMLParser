#include "unity.h"
#include "stack.hpp"

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

void test_length(void){
    Stack<int> stack;
    TEST_ASSERT(stack.getLength() == 0);
}
void test_empty(void){
    Stack<int> stack;
    TEST_ASSERT(stack.isEmpty());
}
void test_push(void){
    Stack<int> stack;
    TEST_ASSERT(stack.push(1));
}
void test_append(void){
    Stack<int> stack;
    TEST_ASSERT(stack.append(3));
}
/*void test_pop(void){
    Stack<int> stack;
    //stack.push(10);
    TEST_ASSERT(stack.pop());
}*/


int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_length);
    RUN_TEST(test_empty);
    RUN_TEST(test_push);
    RUN_TEST(test_append);
    //RUN_TEST(test_pop);
    return UNITY_END();
}
