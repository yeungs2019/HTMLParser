#ifdef HASH_TABLE_H
#include <stdio.h>

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    table.resize(size);
    load = loadFactor;
    //mSize = 0;    
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    //int index = hashcode(key);
    int hashIndex = hashcode(key);
    
    while(table[hashIndex].getInUse()){
	hashIndex++;
	if(hashIndex == table.size()){
	     hashIndex = 0;
	}
    }
    table[hashIndex].setKey(key);
    table[hashIndex].setData(val);
    table[hashIndex].setInUse(true);
    //print out the load
    load = (load + 1) / (table.size());

    return true;

}

template<class K, class V>
bool HashTable<K, V>::remove(const K &key){
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
    if(!table[hashIndex].getInUse()){
        return def;
    }
    return table[hashIndex].getData();
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    return load;
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
   table.clear();
}

template<class K, class V>
int HashTable<K, V>::hashcode(int key) {
    return key % table.size();
}

template<class K, class V>
int HashTable<K, V>::hashcode(const std::string &key) {
    // You need to do something else.
    int index = 0;
    
    return 0;
}

#endif
