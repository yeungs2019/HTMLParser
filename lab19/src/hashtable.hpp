#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>

template<class K, class V>
class HashNode {
    private:
        K key;
        V data;
        bool isInUse;
    public:
        HashNode() { isInUse = false; }
        HashNode(const K _key, const V _data) {
            key = _key;
            data = _data;
        }
        void setKey(K _key) { key = _key; }
        void setData(V _data) { data = _data; }
        void setInUse(bool _isInUse) { isInUse = _isInUse; }
        K& getKey() { return key; }
        V& getData() { return data; }
        bool getInUse() { return isInUse; }
};

/* HashTable via open addressing */
template<class K, class V>
class HashTable {
    private:
        //std::vector<std::list<HashNode<K, V> > > table;
        std::vector<HashNode<K, V> > table; // instantiate the vector of hashnodes
        V def;
	int mSize;
	float load;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size, const float loadFactor);

        /* Deconstructor shall free up memory */
        ~HashTable();

        /* Map key -> val.
         * Return true if sucessful (it is unique.)
         * Otheriwise return false.
         */
        bool insert(const K &key, const V &val);

        /* Print out the HashTable */
        void print() const;

        /* Remove the val associated with key.
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const K &key);

        /* Retrieves the V val that key maps to. */
        V& operator[](const K &key);

        float percentFull();
	int hashcode(int key);
	int hashcode(const std::string &key);

};

#include "hashtable.cpp"

#endif
