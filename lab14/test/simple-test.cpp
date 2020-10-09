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
    bst.add(1);
    bst.add(2);
    bst.add(6);
    TEST_ASSERT(bst.getHeight() == 4);
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
void test_put(void){
    BinaryTree<int> bst;
    //bst.put(3);
    TEST_ASSERT(bst.put(3) == 3);
}
int main(void) {
    UNITY_BEGIN();
   // RUN_TEST(test_simple);
   RUN_TEST(test_height);
   RUN_TEST(test_height2);
   RUN_TEST(test_single);
   RUN_TEST(test_put);
    return UNITY_END();
}
