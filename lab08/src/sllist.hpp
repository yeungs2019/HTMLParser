#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <stdlib.h>
/*SLLNode class*/
template<class T>
class SLLNode {
	private:
		 int data;
		 SLLNode* nextNode;
	public:
		 SLLNode (const int data, SLLNode *next){
			 this->data = data;
			 this->nextNode = next;
		 }
		 int& getData() { return data; }
		 SLLNode *getNext() { return nextNode; }
		 void setNext(SLLNode *node) {this->nextNode = node; }
};

/* SLL = Singly Linked List */
template<class T>
class SLList {
    private:
	    SLLNode<T>* head;
	    SLLNode<T>* tail;
	   
    public:

        /* Empty constructor shall create an empty Linked List! */
        SLList();

        /* Do a deep copy of sll into the this.
         * Note: This one uses a reference to a Singly Linked List!
         */
        SLList(const SLList<T> &sll);

        /* Deconstructor shall free up memory */
        ~SLList();

        /* Return the current length of the Singly Linked List */
        int getLength() const;

        /* Insert at the end of the list.*/
        bool append(const T &val);

        /* Insert val at position pos.
         * Return true if successful (it can be placed.)
         * Otherwise return false.
         */
        bool insert(const int pos, const T &val);

        /* Print out the Singly Linked List */
        void print() const;

        /* Remove the first instance of val
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const T &val);

        /* Retrieves the element at position pos */
        T& operator[](const int pos);

        /* Returns if the two lists contain the same elements in the
         * same order.*/
        bool operator==(const SLList<T> &list) const;
};
/*Doubly linked list node*/
template<class T>
class DLLNode {
        private:
                 int data;
                 DLLNode* nextNode;
		 DLLNode* prevNode;
        public:
                 DLLNode (const int data, DLLNode *next){
                         this->data = data;
                         this->nextNode = next;
                 }
                 int& getData() { return data; }
                 DLLNode *getNext() { return nextNode; }
		 DLLNode *getPrev() { return prevNode; }
                 void setNext(DLLNode *node) {this->nextNode = node; }
		 void setPrev(DLLNode *node) {this->prevNode = node; }
};

template<class T>
class DLList {
    private:
            DLLNode<T>* head;
            DLLNode<T>* tail;

    public:

        /* Empty constructor shall create an empty Linked List! */
        DLList();

        /* Do a deep copy of sll into the this.
         * Note: This one uses a reference to a Singly Linked List!
         */
        DLList(const DLList<T> &dll);

        /* Deconstructor shall free up memory */
        ~DLList();

        /* Return the current length of the Singly Linked List */
        int getLength() const;

        /* Insert at the end of the list.*/
        bool append(const T &val);

        /* Insert val at position pos.
         * Return true if successful (it can be placed.)
         * Otherwise return false.
         */
        bool insert(const int pos, const T &val);

        /* Print out the Singly Linked List */
        void print() const;

        /* Remove the first instance of val
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const T &val);

        /* Retrieves the element at position pos */
        T& operator[](const int pos);

        /* Returns if the two lists contain the same elements in the
         * same order.*/
        bool operator==(const DLList<T> &list) const;
};

/* Since SLList is templated, we include the .cpp
 * Templated classes are not generated until utilized (or explicitly declared.)
 */

#include "sllist.cpp"

#endif
