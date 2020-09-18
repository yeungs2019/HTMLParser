#include "unity.h"
#include "array.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/*void test_simple(void) {
    TEST_ASSERT_EQUAL_INT(10, 1);
    TEST_ASSERT(10 == 0);
}
void test_sort(void) {
	int ary[] = {1, 3, 2, 6, 4};
	Array<int> a(ary, 5);
	TEST_ASSERT(a.bubbleSort();
}
void test_sort2(void) {
        int ary[] = {1, 2, 3, 4, 6};
        int ary2[] = {1, 2, 3, 4, 6};
        Array<int> a(ary, 5);
        Array<int> a2(ary2, 5);
        TEST_ASSERT(a.bubbleSort() == a2);
}
void test_sort3(void) {
        int ary[] = {1, 2, 3, 4, 6};
        int ary2[] = {1, 3, 6, 4, 2};
        Array<int> a(ary, 5);
        Array<int> a2(ary2, 5);
        TEST_ASSERT(a2.bubbleSort() == a);
}*/
void test_bsearch(void){
	int ary[] = {1, 3, 4, 5, 6, 12, 14, 56};
	Array<int>  a(ary, 8);
	TEST_ASSERT(a.binarySearch(4) == 2);
}
void test_notThere(void){
	int ary[] = {1, 3, 4, 5, 6, 12, 14, 56};
	Array<int> a(ary, 22);
	TEST_ASSERT(a.binarySearch(22) == -1);
}
void test_bsearch2(void){
	int ary[] = {56, 14, 12, 6, 5, 4, 3, 1};
	Array<int> a(ary, 8);
	TEST_ASSERT(a.binarySearch(4) == 5);
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
   // RUN_TEST(test_sort);
   // RUN_TEST(test_sort2);
   // RUN_TEST(test_sort3);
//    RUN_TEST(test_sort4);
    RUN_TEST(test_bsearch);
    RUN_TEST(test_notThere);
    RUN_TEST(test_bsearch2);
    return UNITY_END();
}
