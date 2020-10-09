#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include "map.hpp"
#include <algorithm>

Map::Map() {
/*   studentID = 0;
    sName = "";*/
    std::sort(sName.begin(), sName.end());
    std::sort(studentID.begin(), studentID.end());
}
/* Adds (inserts) val with the associated key.
* Returns if successful or not.  (It is not successful if we are out of
* memory, or if the key already exists.)
*/
bool Map::add(const char *key, int val) {
    // this checks if there is a student name or not
    if(key != NULL){
	studentID.push_back(val);
	//print();
	sName.push_back(key);
	//print();
	return true;
    }
    return false;
}
/* Searches for the key.  If found it sets ret to the correct val and
* returns true.  Otherwise this function returns false.
*/

bool Map::get(const char *key, int &ret) {
    /*if(key != NULL){
	for (int i = 0; i < sName.size(); i++){
		//print();
	    if(sName[i] == key){
		//print();
		ret = studentID[i];
		//print();
		return true;
	    }
    	}
    }*/
    int sizeLength = sName.size();
    int left = 0;
    int right = sizeLength;
    int middle = (left + right) / 2;
    if(sName.size() == 0){
	return false;
    }
    while(left < right){
	//int middle = sName.size() / 2;
	if(sName[middle] == key){
	    ret = studentID[middle];
	    return true;
	}
	if(key < sName[middle]){
	    right = middle;
	    middle = (left + right) / 2;
            ret = studentID[middle];
	    return true;
	}
	if(key > sName[middle]){
	    left = middle + 1;
	    middle = (left + right) / 2;
	    ret = studentID[middle];
	    return true;
	}
    }
    return false;
}
void Map::print() const{
    for(int i = 0; i < sName.size(); i++){
	cout << sName[i] << endl;
	cout << studentID[i] << endl;
    }
}
// return size of data structure
int Map::size() {
    //return sName.size();
    //check sizeof(studentID) + sizeof(sName)
    //return studentID.size() + sName.size();
    //return sizeof(studentID) + sizeof(sName);
    int temp;
    for(int i = 0; i < sName.size(); i++){
	temp += sName[i].length() + 1;
    }
    //return temp;
    return (studentID.size() * 4) + temp;
}
/* Removes the current value from the Map AND frees up any memory that
 * * it can.
 * Returns true if there was something to remove, false otherwise.
*/

bool Map::remove(const char *key) {
    if(key == NULL){
	return false;
    }
    for (int i = 0; i < sName.size(); i++){
	if(sName[i] == key){
	    studentID.erase(studentID.begin() + i);
	    sName.erase(sName.begin() + i);
	    return true;
	}
   }
    /*if(key != NULL){
	sName.erase(key);
	return true;
    }*/
    return false;
}
// Returns the number of names with a given prefix.
// EX: If we have {John, Jonathan, Paul, Mark, Luke, Joanna} then
// howMany("Jo") == 3;
int Map::howMany(const char *prefix) {
    string stringLength = prefix;
    if(sName.empty()){
	return 0;
    }
    int temp = 0;
    for(int i = 0; i < sName.size(); i++){
	if(sName[i].substr(0, stringLength.length()) == prefix){
	    temp++;
	}
    }
    return temp;
    /*string stringLength = prefix;
    int sizeLength = sName.size();
    int left = 0;
    int right = sizeLength;
    int middle = (left + right) / 2;
    int temp;
    if(sName.empty()){
	return 0;
    }
    while(left < right){
	if(sName[middle].substr(stringLength.length() == prefix){
	    temp++;
	}
	if(sName[middle].substr(stringLength.length() < prefix)){
	    left = middle + 1;
	    middle = (left + right) / 2;
    	    temp++;
	}
	if(sName[middle].substr(stringLength.lenght() > prefix)){
	    right = middle;
	    middle = (left + right) / 2;
	    temp++;
	}
    }
    return temp;*/
}

Map::~Map() {
    sName.clear();
    studentID.clear();
}


