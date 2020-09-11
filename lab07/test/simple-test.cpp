#include "unity.h"
#include "array.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int ary[] = {1, 2, 3, 4};

    Array<int> a(ary, 4);
    Array<int> a2(a);

    TEST_ASSERT(a.getLength() == 4);
    TEST_ASSERT(a2.getLength() == 4);

}
void test_index(void){
	int ary[] = {1, 2, 3, 4};
	Array<int> a(ary, 3);
	TEST_ASSERT(a.indexOf(3) == 2);

}
void test_nonindex(void){
	int ary[] = {1, 3, 2, 5, 8};
	Array<int> a(ary, 10);
	TEST_ASSERT(a.indexOf(10) == -1);
}
void test_remove(void){
	int ary[] = {2, 4, 5, 6, 19};
	Array<bool> a(ary, 5);
	TEST_ASSERT(a.remove(5));
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_index);
    RUN_TEST(test_nonindex);
    return UNITY_END();
}
