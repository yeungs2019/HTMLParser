#ifdef SLLIST_HPP

template<class T>
SLList<T>::SLList() {
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
}

template<class T>
SLList<T>::~SLList() {
}

template<class T>
bool SLList<T>::append(T val) {
    return false;
}

template<class T>
void SLList<T>::print() const {
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
    return 0;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, T &val) {
    return false;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
    return false;
}

template<class T>
T& SLList<T>::operator[](const int pos) {
}

template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
    return false;
}

#endif
