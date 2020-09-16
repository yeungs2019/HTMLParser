#ifdef SLLIST_HPP
#include<iostream>


template<class T>
SLList<T>::SLList() {
	head = NULL;
	tail = NULL;
	length = 0;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
	SLLNode<T>* rover = sll.head;
	sll.append(head);
}

// free the memory
template<class T>
SLList<T>::~SLList(){
	SLLNode<T>* rover = head;
	SLLNode<T>* toDelete = rover;
	while (rover != NULL){
		rover = rover->getNext();
		delete toDelete;
		toDelete = rover;
	}
}

// returns length of list
template<class T>
int SLList<T>::getLength() const {
	return length;
}

// inserts a node to the end of list
template<class T>
bool SLList<T>::append(const T &val) {
	bool isAppend = false;
	SLLNode<T>* rover = new SLLNode<T>(val, NULL);
	if (head == NULL) {
		head = rover;
		tail = rover;
	}
	else{
		tail->setNext(rover);
		tail = rover;
	}
	isAppend = true;
   	return isAppend;
}

// prints out SLL
template<class T>
void SLList<T>::print() const {
	/*SLLNode<T>* rover = NULL;
	rover = head;
	while(rover != NULL) {
		std::cout << rover->getData() << ",";
		rover = rover->nextNode;
	}*/
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, T &val) {
	/*bool isFound = false;
	SLLNode<T>* rover = head;
	if (rover == NULL){
		SLLNode<T>* newNode = new SLLNode<T>(val, NULL);
		
	
    return false;*/
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
	bool isFound = false;
	SLLNode<T>* rover = head;
	SLLNode<T>* rover2 = NULL;
	while (rover != NULL){
		if (rover->getData() != val) {
			rover2 = rover;
		}
		rover = rover->getNext();
	}
	if (rover == NULL){
		return false;
	}
	else{
		if (rover == head){
			head = rover->getNext();
			if (rover->getNext() == NULL){
				tail == NULL;
			}
			delete rover;
		}
		else if (rover->getNext() == NULL){
			tail = rover2;
			rover2 = NULL;
			delete rover;
		}
		else {
			rover2->getNext() == rover->getNext();
			delete rover;
		}
		//return true;
	}
	return true;
}

// retrieves the element at position pos
template<class T>
T& SLList<T>::operator[](const int pos) {
	//return head[pos];
}

// returns the two lists if they are the same
template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
	SLLNode<T>* rover = head;
	SLLNode<T>* rover2 = list.head;
	int temp;
	if(this->getLength() != list.getLength()){
		return false;
	}
	while(rover != NULL && rover2 != NULL){
		if(rover->getData() == rover2->getData()){
			temp++;
			rover = rover->getNext();
			rover2 = rover2->getNext();
		}
		else{
			return false;
		}
	}
	if(temp == list.getLength()){
		return true;
	}
   	return false;
}

#endif
