#ifdef HASH_TABLE_H

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    return false;
}

template<class K, class V>
V& HashTable<K,V>::operator[](const K &key) {
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
