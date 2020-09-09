#include "unity.h"
#include "arrays.hpp"

void setUp(void){
}

void tearDown(void){
}

void test_empty() {
	int ary[] = {};
	TEST_ASSERT(search(ary, 0) == -1);
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_empty);
	return UNITY_END;
}

