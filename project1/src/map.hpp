#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <cstring>
using namespace std;
/*class mapNode{
    private:
	int ID;
	std::string stName;
	mapNode* nextNode;
    public:
	mapNode(const int data, std::string name, mapNode* next){
	    this->ID= data;
	    this->stName = name;
	    this->nextNode = next;*/
class Map{
    public:
        Map();
        /* Adds (inserts) val with the associated key.
         * Returns if successful or not.  (It is not successful if we are out of
         * memory, or if the key already exists.)
         */
        bool add(const char *key, int val);
    
        /* Searches for the key.  If found it sets ret to the correct val and
         * returns true.  Otherwise this function returns false.
         */
        bool get(const char *key, int &ret);
    
        /* Returns the size (memory consumed) by this data structure. */
        int size();
    
        /* Removes the current value from the Map AND frees up any memory that
         * it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const char *key);

	// prints the stuff
	void print() const;
    
        int howMany(const char *prefix);
    
        /* Frees all memory */
        ~Map();
    private:
	vector<string> sName;
	vector<int> studentID;
	//mapNode* head;
	//mapNode* tail;
};

#endif
