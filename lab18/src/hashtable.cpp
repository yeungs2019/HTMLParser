#ifdef HASH_TABLE_H
#include <iostream>
#include <algorithm>
#include <iterator>
#include "hashtable.hpp"

template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
    //std::vector<std::list<HashNode<K, V> > > *table;
    //table = new std::vector<std::list<HashNode<K, V> > >(size);
    table.resize(size);
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key) % table.capacity();
    HashNode<K, V> toadd(key, val);
    table[index].push_front(toadd);
    return true;
}

template<class K, class V>
V& HashTable<K, V>::operator[](const K &key) {
    int index = hashcode(key) % table.capacity();

    for (auto i = table[index].begin(); i != table[index].end(); i++) {
        if ((i)->getKey() == key) {
            return i->getData();
        }
    }

    return def;
}

template<class K, class V>
void HashTable<K, V>::print() {
    for (int i = 0; i < table.capacity(); i++) {
        std::cout << "[" << i << "]:";
        for (auto j = table[i].begin(); j != table[i].end(); j++) {
            std::cout << "{ " << j->getKey() << ", " << j->getData() << "}";
        }
        std::cout << "\n";
    }
}
template<class K, class V>
bool HashTable<K, V>::remove(const K &key){
    /*std::vector<std::list<HashNode<K, V> > >::iterator it;
    for(auto it = table.begin(); it != table.end(); it++){
	if(find((*it).begin(), (*it).end(), key) != (*it).end()){
	    (*it).pop_back();
	}
	return true;
    }*/
    int index = hashcode(key) % table.size();
    for(auto i = table[index].begin(); i != table[index].end(); i++){
	if(i->getKey() == key){
	    table[index].erase(i);
	    return true;
	}
    }
    return false;
}
int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
