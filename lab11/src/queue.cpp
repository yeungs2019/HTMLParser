#ifdef QUEUE_H
#include "queue.hpp"

//empty constructor
template <class T>
Queue<T>::Queue(){
    mSize = 0;
    std::list<T> mList;
    head = NULL;
    tail = NULL;
}

//deep copy please
template <class T>
Queue<T>::Queue(const Queue<T> &queue){
}

//free me
template <class T>
Queue<T>::~Queue(){
    for(int i = 0; i < mSize; i++){
        this->mList.pop_back();
    }
}

//return length
template <class T>
int Queue<T>::getLength() const{
    return mSize;
}

//is it empty?
template <class T>
bool Queue<T>::isEmpty() const{
    return this->mList.empty();
}

//print
template <class T>
void Queue<T>::print() const{
}

//push to end of queue
template <class T>
bool Queue<T>::push(const T &val){
   this->mList.push_back(val);
   mSize++;
   return true;
}

// returns first element from queue
template <class T>
T& Queue<T>::first(){
    return this->mList.front();
}

template <class T>
void Queue<T>::pop(){
    this->mList.pop_front();
    mSize--;
}

//returns if two queues contain same elements in same order
template <class T>
bool Queue<T>::operator==(const Queue<T> &queue) const{
    if(this->getLength() != queue.getLength()){
        return false;
    }
    std::list<T> copymList(this->mList);
    std::list<T> copyQueue(queue.mList);

    int length;
    T val1;
    T val2;
    length = queue.getLength();
    for (int i = 0; i < length; i++){
         val1 = copymList.front();
         val2 = copyQueue.front();
         copymList.pop_front();
         copyQueue.pop_front();
         if (val1 != val2){
             return false;
         }
    }
    return true;
}


/* Add a value to the queue with respect to priority.
 * For this function a lower number is a higher priority.
 * EX: If the Queue is of integers and is { 5, 10, 15} and I add 7, 
 * the new queue is { 5, 7, 10, 15}.
 */
template<class T>
void Queue<T>::addWithPriority(const T& val) {
    queueNode<T>* rover = head;
    if(rover == NULL){
        push(val);
	return;
    }
    for(int i = 0; i = mSize - 1; i++){
	rover = rover->getNext();
	if(val < rover->getData()){
	   queueNode<T>* rover2 = new queueNode<T>(val, rover->getNext());
	   rover->setNext(rover2);
	}
    }
}
 /* a 2D array with each cell having the following property
 *   0: Cell is open (passable)
 *  -1: Cell is a wall (unpassable)
 * > 0: Cell is a warp.
 * A warp is a value > 999999 and warps to the position 
 *    (<first three digits, second three digits).
 * Hence 1000 warps to (1, 0), and 203109 warps to (203, 109)
 * To get the x value: <cell>/1000
 * To get the y value: <cell>%1000
 */
template<class T>
int Queue<T>::getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey) {
}

#endif
