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
void test_length(void) {
    SLList<int> sll;
    TEST_ASSERT(sll.getLength() == 0);
}
void test_remove(void) {
    SLList<int> sll;
    TEST_ASSERT(!(sll.remove(2)));
}
void test_remove2(void){
    SLList<int> sll;
    TEST_ASSERT(!(sll.remove(1)));
}
void test_remove3(void){
    SLList<int> sll;
    sll.append(7);
    TEST_ASSERT(sll.remove(7));
}
void test_remove4(void){
    SLList<int> sll;
    sll.append(5);
    TEST_ASSERT(!(sll.remove(7)));
}
void test_remove5(void){
    SLList<int> sll;
    sll.append(7);
    TEST_ASSERT(!(sll.remove(5)));
}
void test_remove6(void){
    SLList<int> sll;
    sll.append(777);
    TEST_ASSERT(sll.remove(777));
}

void test_append(void){
    SLList<int> sll;
    TEST_ASSERT(sll.append(1));
}
void test_equals(void){
    SLList<int> sll;
    SLList<int> sll2;
    TEST_ASSERT(sll == sll2);
}
void test_notEqual(void){
	SLList<int> sll;
	sll.append(7);
	SLList<int> sll2;
	TEST_ASSERT(!(sll == sll2));
}
void test_notEqu(void){
	SLList<int> sll;
	sll.append(1);
	SLList<int> sll2;
	sll2.append(2);
	TEST_ASSERT(!(sll == sll2));
}

void test_yesE(void){
	SLList<int> sll;
        sll.append(3);
        SLList<int> sll2;
        sll2.append(3);
        TEST_ASSERT(sll == sll2);
}
void test_noE(void){
        SLList<int> sll;
        sll.append(52);
        SLList<int> sll2;
        sll2.append(3);
        TEST_ASSERT(!(sll == sll2));
}
/*void test_insert(void){
	SLList<int> sll;
	sll.append(1);
	TEST_ASSERT(sll.insert(1, 3));
}
void test_insert2(void){
        SLList<int> sll;
       	sll.append(5);
        TEST_ASSERT(!sll.insert(6, 3));
}*/
void test_overflow(void){
	SLList<int> sll;
	sll.append(1);
	sll.append(2);
	sll.append(3);
	sll.append(4);
	sll.append(5);
	TEST_ASSERT(sll.remove(3));
}
void test_overflow2(void){
        SLList<int> sll;
        sll.append(1);
        sll.append(2);
        sll.append(3);
        sll.append(4);
        sll.append(5);
        TEST_ASSERT(!(sll.remove(10)));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_length);
    RUN_TEST(test_remove);
    RUN_TEST(test_remove2);
    RUN_TEST(test_remove3);
    RUN_TEST(test_remove4);
    RUN_TEST(test_remove5);
    RUN_TEST(test_remove6);
    RUN_TEST(test_append);
    RUN_TEST(test_equals);
    RUN_TEST(test_notEqual);
    RUN_TEST(test_notEqu);
    RUN_TEST(test_yesE);
    RUN_TEST(test_noE);
    RUN_TEST(test_overflow);
    RUN_TEST(test_overflow2);
   // RUN_TEST(test_insert);
   // RUN_TEST(test_insert2);
    return UNITY_END();
}
