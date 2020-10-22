#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <list>

template<class K, class V>
class HashNode {
    private:
        K key;
        V data;
    public:
        HashNode(const K _key, const V _data) {
            key = _key;
            data = _data;
        }
        K& getKey() { return key; }
        V& getData() { return data; }
};

/* HashTable via chaining */
template<class K, class V>
class HashTable {
    private:
        std::vector<std::list<HashNode<K, V> > > table;
        V def;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size);

        /* Deconstructor shall free up memory */
        ~HashTable();

        /* Map key -> val.
         * Return true if sucessful (it is unique.)
         * Otheriwise return false.
         */
        bool insert(const K &key, const V &val);

        /* Print out the HashTable */
        void print();

        /* Remove the val associated with key.
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const K &key);

        /* Retrieves the V val that key maps to. */
        V& operator[](const K &key);

};

int hashcode(int key);
int hashcode(const std::string &key);

#include "hashtable.cpp"

#endif
