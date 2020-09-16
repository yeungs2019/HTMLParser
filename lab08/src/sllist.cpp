#ifdef SLLIST_HPP
#include<iostream>


template<class T>
SLList<T>::SLList() {
	head = NULL;
	tail = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
	SLLNode<T>* rover = sll.head;
	head = NULL;
	tail = NULL;
	for (int i = 0; i < sll.getLength(); i++){
		append(rover->getData());
		rover = rover->getNext();
	}
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
	SLLNode<T>* rover = head;
	int newLength = 0;
	while (rover != NULL){
		newLength++;
		rover = rover->getNext();
	}
	
	return newLength;
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
	/*SLLNode<T>* ro ver = NULL;
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
bool SLList<T>::insert(const int pos, const T &val) {
	SLLNode<T>* rover = new SLLNode<T>(val, NULL);
	SLLNode<T>* current = new SLLNode<T>(val, head);
	if (pos < 0 || pos > this->getLength()){
		std::cout << this->getLength();
		return false;
	}
	if (head == NULL && pos == this->getLength()){
                        append(val);
                        return true;

	}
	if (pos == 0){
      	                // adding node at pos
                        head = current;
                        return true;
                }
                else{
                        SLLNode<T>* newNode = head;
                        for (int i = 0; i < pos - 1; i++){
                                newNode = newNode->getNext();
                        }
                        rover->setNext(newNode->getNext());
                        newNode->setNext(rover);
                    	return true;

	}

}
/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
	SLLNode<T>* rover = head;
	SLLNode<T>* rover2 = NULL;
	while (rover != NULL && rover->getData() != val){
		rover2 = rover;
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
	SLLNode<T>* rover = head;
	for (int i = 0; i < pos; i++){
		rover = rover->getNext();
	}
	return rover->getData();
}

// returns the two lists if they are the same
template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
	SLLNode<T>* rover = head;
	SLLNode<T>* rover2 = list.head;
	if(this->getLength() != list.getLength()){
		return false;
	}
	if(this->head == NULL && list.head == NULL){
		return true;
	}
	while(rover2 != NULL){
		if(rover->getData() == rover2->getData()){
			rover = rover->getNext();
			rover2 = rover2->getNext();
		}
		else{
			return false;
		}
	}
   	return true;
}
// DOUBLY LINKED LIST PORTION
template<class T>
DLList<T>::DLList() {
        head = NULL;
        tail = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
DLList<T>::DLList(const DLList<T> &dll) {
        DLLNode<T>* rover = dll.head;
        head = NULL;
        tail = NULL;
        for (int i = 0; i < dll.getLength(); i++){
                append(rover->getData());
                rover = rover->getNext();
        }
}

// free the memory
template<class T>
DLList<T>::~DLList(){
        DLLNode<T>* rover = head;
        DLLNode<T>* toDelete = rover;
        while (rover != NULL){
                rover = rover->getNext();
                delete toDelete;
                toDelete = rover;
        }
}

// returns length of list
template<class T>
int DLList<T>::getLength() const {
        DLLNode<T>* rover = head;
        int newLength = 0;
        while (rover != NULL){
                newLength++;
                rover = rover->getNext();
        }

        return newLength;
}

// inserts a node to the end of list
template<class T>
bool DLList<T>::append(const T &val) {
        bool isAppend = false;
        DLLNode<T>* rover = new DLLNode<T>(val, NULL);
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
void DLList<T>::print() const {
        /*SLLNode<T>* ro ver = NULL;
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
bool DLList<T>::insert(const int pos, const T &val) {
        DLLNode<T>* rover = new DLLNode<T>(val, NULL);
        DLLNode<T>* current = new DLLNode<T>(val, head);
        if (pos < 0 || pos > this->getLength()){
                std::cout << this->getLength();
                return false;
        }
        if (head == NULL && pos == this->getLength()){
                        append(val);
                        return true;
        }
	 if (pos == 0){
                        // adding node at pos
                        head = current;
                        return true;
                }
                else{
                        DLLNode<T>* newNode = head;
                        for (int i = 0; i < pos - 1; i++){
                                newNode = newNode->getNext();
                        }
                        rover->setNext(newNode->getNext());
                        newNode->setNext(rover);
                        return true;
        }
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool DLList<T>::remove(const T &val) {
        DLLNode<T>* rover = head;
        DLLNode<T>* rover2 = NULL;
        while (rover != NULL && rover->getData() != val){
                rover2 = rover;
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
        }
        return true;
}

// retrieves the element at position pos
template<class T>
T& DLList<T>::operator[](const int pos) {
        DLLNode<T>* rover = head;
        for (int i = 0; i < pos; i++){
                rover = rover->getNext();
        }
        return rover->getData();
}

// returns the two lists if they are the same
template<class T>
bool DLList<T>::operator==(const DLList<T> &list) const {
        DLLNode<T>* rover = head;
        DLLNode<T>* rover2 = list.head;
        if(this->getLength() != list.getLength()){
                return false;
        }
        if(this->head == NULL && list.head == NULL){
                return true;
        }
        while(rover2 != NULL){
                if(rover->getData() == rover2->getData()){
                        rover = rover->getNext();
                        rover2 = rover2->getNext();
                }
                else{
                        return false;
                }
	}
	return true;
}


#endif
