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

void test_put(void){
    BinaryTree<int> bst;
    //SplayTree<int> bst;
    bst.put(2);
    bst.put(3);
    bst.put(4);
    //TEST_ASSERT(bst.contains(2) == true);
}
void test_contains(void){
    BinaryTree<int> bst;
    //SplayTree<int>bst;
    bst.put(1);
    TEST_ASSERT(bst.contains(1) == true);
    TEST_ASSERT(bst.contains(3) == false);
}
void test_non(void){
    BinaryTree<int> bst;
    //SplayTree<int> bst;
    TEST_ASSERT(bst.contains(1) == false);
}
void test_remove(void){
    BinaryTree<int> bst;
    //SplayTree<int> bst;
    bst.put(2);
    bst.put(3);
    //TEST_ASSERT(bst.contains(2) == true);
    //TEST_ASSERT(bst.contains(3) == true);
    TEST_ASSERT(bst.remove(3) == true);
    TEST_ASSERT(bst.remove(5) == false);
    TEST_ASSERT(bst.contains(3) == false);
    TEST_ASSERT(bst.contains(2) == true);
    //TEST_ASSERT(bst.contains(3) == true);
    //TEST_ASSERT(bst.contains(2) == false);
}
void test_height(void){
    BinaryTree<int> bst;
    //SplayTree<int> bst;
    bst.put(1);
    bst.put(2);
    bst.put(3);
    bst.put(4);
    bst.put(5);
    TEST_ASSERT(bst.getHeight() == 3);
}

int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_simple);
    RUN_TEST(test_put);
    RUN_TEST(test_contains);
    RUN_TEST(test_non);
    RUN_TEST(test_remove);
    RUN_TEST(test_height);
    return UNITY_END();
}
