#include "unity.h"
#include "map.hpp"
#include <string>
#include <cstring>
void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    int key;
    Map map;

    TEST_ASSERT(map.add("John Doe", 1234) == true);
    TEST_ASSERT(map.add("Mason Bradford", 1235) == true);
    TEST_ASSERT(map.add("Scott Winston", 1236) == true);

    TEST_ASSERT(map.get("John Doe", key) == true);
    TEST_ASSERT_EQUAL_INT(1234, key);

    TEST_ASSERT(map.get("Mason Bradford", key) == true);
    TEST_ASSERT_EQUAL_INT(1235, key);

    TEST_ASSERT(map.get("no one", key) == false);

    TEST_ASSERT(map.remove("John Doe") == true);
    TEST_ASSERT(map.get("John Doe", key) == false);
}

void test_add(void){
    int key;
    Map map;
    TEST_ASSERT(map.add("John Williams", 1234) == true);
    TEST_ASSERT(map.add("Dangerous Jackelope", 4093) == true);
}
void test_get(void){
    int key;
    Map map;
    //key = 12343253;
    TEST_ASSERT(map.add("Dangerous Mena", 12345678));
    TEST_ASSERT(map.get("Dangerous Mena", key) == true);
    //TEST_ASSERT_EQUAL_INT(12423243, key);
    //TEST_ASSERT(map.get("Dr lin", key) == false);
}
void test_get2(void){
    int key;
    Map map;
    TEST_ASSERT(map.get("Dr Lin", key) == false);
}
void test_remove(void){
    int key;
    Map map;
    TEST_ASSERT(map.add("Marshall Eggnoodle", 4637822));
    TEST_ASSERT(map.remove("Marshall Eggnoodle"));
    TEST_ASSERT(map.remove("no one") == false);
    TEST_ASSERT(map.get("Marshall Eggnoodle", key) == false);
}
void test_prefix(void){
    int key;
    Map map;
    TEST_ASSERT(map.add("Marshall Eggnoodle", 4637822));
    TEST_ASSERT(map.add("Joe Eggnoodle", 4637822));
    TEST_ASSERT(map.add("John Eggnoodle", 4637822));
    TEST_ASSERT(map.add("Jonathan Eggnoodle", 4637822));
    TEST_ASSERT(map.add("Popo Eggnoodle", 4637822));
    TEST_ASSERT(map.howMany("Jo") == 3);
}
void test_prefixN(void){
    int key;
    Map map;
    TEST_ASSERT(map.add("Marshall Eggnoodle", 34567890));
    TEST_ASSERT(map.add("Dodo Eggnoodle", 34567890));
    TEST_ASSERT(map.add("Paul Eggnoodle", 34567890));
    TEST_ASSERT(map.howMany("Jo") == 0);
}
void test_getSpeed(void){
    int key;
    Map map;
    //key = 12343253;
    TEST_ASSERT(map.add("Dangerous Mena", 12345678));
    TEST_ASSERT(map.get("Dangerous Mena", key) == true);
    TEST_ASSERT(map.add("Dangerous Jackie", 65473890));
    TEST_ASSERT(map.get("Dangerous Jackie", key) == true);
    TEST_ASSERT(map.add("Mr Popo", 57548930));
    TEST_ASSERT(map.get("Mr Popo", key) == true);
    TEST_ASSERT(map.add("Master Jackiechan", 34567890));
    TEST_ASSERT(map.get("Master Jackiechan", key) == true);
    TEST_ASSERT(map.add("Bigfoot Everywhere", 768594485));
    TEST_ASSERT(map.get("Bigfoot Everywhere", key) == true);
    TEST_ASSERT(map.add("Super Zenoeraserman", 66278239));
    TEST_ASSERT(map.get("Super Zenoeraserman", key) == true);
    TEST_ASSERT(map.add("Mario Luigui", 52678343));
    TEST_ASSERT(map.get("Mario Luigui", key) == true);
    TEST_ASSERT(map.add("Nessie Bird", 689382820));
    TEST_ASSERT(map.get("Nessie Bird", key) == true);
    TEST_ASSERT(map.add("Misaka Mikoto", 574839));
    TEST_ASSERT(map.get("Misaka Mikoto", key) == true);
}
void test_size(void){
    int key;
    Map map;
    TEST_ASSERT(map.add("Joe Does", 1234));
    //TEST_ASSERT(map.add("Joe Doeee", 1234));
    //TEST_ASSERT(map.add("Joe Dowasdfe", 1234));
    //TEST_ASSERT(map.add("Joe Doeasdf", 1234));
    //TEST_ASSERT(map.add("Joe Doeetewdt", 1234));

    TEST_ASSERT(map.size() == 13);
}
/*void test_stress(void){
   int key;
   Map map;
   for(int i = 0; i < 1000000; i++){
      map.add("Mr Danger", 748392);
      TEST_ASSERT(map.get(i));
   }
}*/
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_add);
    RUN_TEST(test_get);
    RUN_TEST(test_get2);
    RUN_TEST(test_remove);
    RUN_TEST(test_prefix);
    RUN_TEST(test_prefixN);
    RUN_TEST(test_getSpeed);
    RUN_TEST(test_size);
   // RUN_TEST(test_stress);
    return UNITY_END();
}
