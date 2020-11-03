#ifdef HASH_TABLE_H
#include <stdio.h>

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    table.resize(size);
    load = loadFactor;
    mSize = 0;    
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key);
    int hashIndex = key % table.size();

    while (!table[hashIndex].getInUse()) {
        hashIndex++;
        hashIndex = hashIndex % table.size();
    }

    // hashIndex should be the value to set!
    table[hashIndex].setKey(key);
    table[hashIndex].setData(val);
    mSize++;
    table[hashIndex].setInUse(false);
    if(percentFull() > load){
	table.resize(table.size() * 2);
	int n = hashcode(key);
	int cryFace = n % hashcode(key);
	while(!table[cryFace].getInUse()){
	    cryFace++;
	    cryFace = cryFace % table.size();
	}
	table[cryFace].setKey(key);
	table[cryFace].setData(val);
	table[cryFace].setInUse(false);
    }
    return true;
}

template<class K, class V>
V& HashTable<K,V>::operator[](const K &key) {
    int hashIndex = hashcode(key) % table.size();

    // Lets first get a valid hashIndex!
    while (!table[hashIndex].getInUse()) {
        //hashIndex++;
        if (table[hashIndex].getKey() == key){
           return table[hashIndex].getData(); 
        }
	hashIndex++;
	hashIndex = hashIndex % table.size();
    }
    //return table[hashIndex].getData();
    return def;
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    return 0.0;
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
