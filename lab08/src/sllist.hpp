#ifndef SLLIST_HPP
#define SLLIST_HPP

/* SLL = Singly Linked List */
template<class T>
class SLList {
    private:
        /* Class exercise to fill in. */
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
        bool append(T val);

        /* Insert val at position pos.
         * Return true if successful (it can be placed.)
         * Otherwise return false.
         */
        bool insert(const int pos, T &val);

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

/* Since SLList is templated, we include the .cpp
 * Templated classes are not generated until utilized (or explicitly declared.)
 */

#include "sllist.cpp"

#endif
