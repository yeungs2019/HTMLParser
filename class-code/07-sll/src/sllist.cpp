#include "sllist.hpp"
#include <stdlib.h>
#include <iostream>

void SLL::add(const int data) {
    SLLNode *newNode = new SLLNode(data, NULL);
    newNode->setNext(head);
    head = newNode;
}

int SLL::getLength() {
    SLLNode* rover = head;
    int currentLength = 0;
    
    while(rover != NULL) {
        currentLength++;
        // Use the -> operator to use functions on pointers
        // Use the . operator to call members and functions on objects
        rover = rover->getNext();
        //rover = *(rover).getNext();
    }

    return currentLength;
}

void SLL::print() {
    for (SLLNode *rover = head; rover != NULL; rover = rover->getNext()) {
        std::cout << rover->getData() << ", ";
    }
    std::cout << "\n";
}

void SLL::insert(const int pos, const int data) {
    if (pos == 0) { 
        add(data); 
        return;
    }
    // Lets validate pos!
    if (pos < 0 || pos > getLength()) {
        return;
    }
    
    SLLNode* rover = head;
    for (int i = 0; i < pos - 1; i++) {
        rover = rover->getNext();
    }
    SLLNode* nodeToAdd = new SLLNode(data, NULL);
    nodeToAdd->setNext(rover->getNext());
    rover->setNext(nodeToAdd);
    
}

bool SLL::contains(const int data) {
    
    for (SLLNode *rover = head; rover != NULL; rover = rover->getNext()) {
       if(rover->getData() == data)
           return true;
    }

    return false;
}

void SLL::remove(const int data) {
    SLLNode *prev = NULL;
    SLLNode *toDelete = NULL;
    //First find data (if it exists!)
    for (SLLNode *rover = head; rover != NULL; rover = rover->getNext()) {
       if(rover->getData() == data) {
           toDelete = rover;
           break;
       }
       prev = rover;
    }

    // Check if data was in there.
    if (toDelete == NULL) { return; }

    // Now we KNOW data is in the list AND toDelete is pointing to it.
    // Change prev->next to point to toDelete->next element
    if (prev != NULL) {
        prev->setNext(toDelete->getNext());
    } else {
        head = toDelete->getNext();
    }

    delete toDelete;
}

int& SLL::operator[](const int pos) {
    SLLNode* rover = head;

    for (int i = 0; i < pos; i++) {
        rover = rover->getNext();
    }

    return rover->getData();
}
