#ifndef STACK_H
#define STACK_H
#include <list>
template<class T>
class stackNode {
    private:
	int data;
	stackNode* nextNode;
    public:
	stackNode (const int data, stackNode* next){
		this->data = data;
		this->nextNode = next;
	}
	int& getData() { return data; }
	stackNode* getNext() { return nextNode; }
	void setNext(stackNode* node) {this->nextNode = node; }
};

template<class T>
class Stack {
    private:
        stackNode<T>* head;
	stackNode<T>* tail;
    public:
        /* Empty constructor shall create an empty Stack! */
        Stack();
        /* Do a deep copy of stack into the this.
         * Note: This one uses a reference to a Stack!
         */
        Stack(const Stack<T> &stack);
        /* Deconstructor shall free up memory */
        ~Stack();
        /* Return the current length (number of items) in the stack */
        int getLength() const;
        /* Returns true if the stack is empty. */
        bool isEmpty() const;
        /* Print out the Stack */
        void print() const;
	/* appends node at end of list (only for deep copy*/
	bool append(const T &val);
        /* Pushes the val to the top of the stack. */
        bool push(const T &val);
        /* Returns the top element from the stack. */
        T& top();
        /* Removes the top element from the stack. */
        void pop();
        /* Returns if the two stacks contain the same elements in the
         * same order.
         */
        bool operator==(const Stack<T> &stack) const;
};

#include "stack.cpp"

#endif
