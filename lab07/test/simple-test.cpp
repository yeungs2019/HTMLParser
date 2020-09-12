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
	Array<int> a(ary, 5);
	TEST_ASSERT(a.remove(2));
}
void test_remove2(void){
	int ary[] = {1};
	Array<int> a(ary, 1);
	TEST_ASSERT(a.remove(0));
}
void test_same(void){
	int ary[] = {1, 2, 3};
	int ary2[] = {1, 2, 3};
	Array<int> a(ary, 3);
	Array<int> a2(ary2, 3);
	TEST_ASSERT(a == a2);
}
void test_dif(void){
	int ary[] = {1, 2, 3, 4, 5, 6};
	int ary2[] = {1, 2, 4, 5, 6, 7};
	Array<int> a(ary, 6);
	Array<int> a2(ary2, 6);
	TEST_ASSERT(a == a2);
}
void test_dif2(void){
	int ary[] = {1, 2, 3, 4};
	int ary2[] = {1, 2, 4};
	Array<int> a(ary, 4);
	Array<int> a2(ary2, 3);
	TEST_ASSERT(a == a2);
}
void test_dif3(void){
	int ary[] = {1, 2, 3, 4, 5, 6};
	int ary2[] = {1};
	Array<int> a(ary, 6);
	Array<int> a2(ary2, 1);
	TEST_ASSERT(a == a2);
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_index);
    RUN_TEST(test_nonindex);
    RUN_TEST(test_remove);
    RUN_TEST(test_remove2);
    RUN_TEST(test_same);
    RUN_TEST(test_dif);
    RUN_TEST(test_dif2);
    RUN_TEST(test_dif3);
    return UNITY_END();
}
