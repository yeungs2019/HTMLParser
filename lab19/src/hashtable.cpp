#ifdef HASH_TABLE_H

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    table.resize(size);
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int hashIndex = key % table.size();

    while (table[hashIndex].getInUse()) {
        hashIndex++;
        if (hashIndex == table.size()){
            hashIndex = 0;
        }
    }

    // hashIndex should be the value to set!
    table[hashIndex].setKey(key);
    table[hashIndex].setData(val);
    table[hashIndex].setInUse(true);

    return true;
}

template<class K, class V>
V& HashTable<K,V>::operator[](const K &key) {
    int hashIndex = hashcode(key) % table.size();

    // Lets first get a valid hashIndex!
    while (table[hashIndex].getKey() != key && table[hashIndex].getInUse()) {
        hashIndex++;
        if (hashIndex == table.size()){
            hashIndex = 0;
        }
    }

    if (!table[hashIndex].getInUse()) {
        return def;
    }

    return table[hashIndex].getData();
    //return def;
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
