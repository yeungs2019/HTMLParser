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
    stack.push(10);
    TEST_ASSERT(stack.top());
}
void test_append(void){
    Stack<int> stack;
    TEST_ASSERT(stack.append(3));
}

void test_pop(void){
    Stack<int> stack;
    stack.push(10);
    TEST_ASSERT(stack.top());
    stack.push(15);
    TEST_ASSERT(stack.top());
    stack.pop();
}
void test_pop2(void){
    Stack<int> stack;
    stack.push(10);
    TEST_ASSERT(stack.top());
    stack.push(15);
    TEST_ASSERT(stack.top());
    stack.push(2);
    TEST_ASSERT(stack.top());
    stack.pop();
}
void test_pop3(void){
    Stack<int> stack;
    stack.push(3);
    TEST_ASSERT(stack.top());
    stack.push(19);
    TEST_ASSERT(stack.top());
    stack.push(20);
    TEST_ASSERT(stack.top());
    stack.pop();
}
void test_stress(void){
    Stack<int> stack;
    for (int i = 0; i < 1000000; i++){
        stack.push(i);
	TEST_ASSERT(stack.top());
    }
    for (int i = 999999; i >= 0; i--){
	TEST_ASSERT(stack.top());
	stack.pop();
    }
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_length);
    RUN_TEST(test_empty);
    RUN_TEST(test_push);
    RUN_TEST(test_append);
    RUN_TEST(test_pop);
    RUN_TEST(test_pop2);
    RUN_TEST(test_pop3);
    RUN_TEST(test_stress);
    return UNITY_END();
}
