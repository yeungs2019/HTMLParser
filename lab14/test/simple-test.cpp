#include "unity.h"
#include "binarytree.hpp"

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
void test_height(void){
    BinaryTree<int> bst;
    bst.add(7);
    bst.add(9);
    bst.add(4);
    bst.add(1);
    bst.add(5);
    TEST_ASSERT(bst.getHeight() == 3);
}
void test_height2(void){
    BinaryTree<int> bst;
    TEST_ASSERT(bst.getHeight() == 0);
}
void test_single(void){
    BinaryTree<int> bst;
    bst.add(1);
    TEST_ASSERT(bst.getHeight() == 1);
}
int main(void) {
    UNITY_BEGIN();
   // RUN_TEST(test_simple);
   RUN_TEST(test_height);
   RUN_TEST(test_height2);
   RUN_TEST(test_single);
    return UNITY_END();
}
