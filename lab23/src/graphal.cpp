#ifdef GRAPHAL_H
#include <iostream>

template<class W>
GraphAL<W>::GraphAL() {
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    return false;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    return false;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
    return -1;
}

/* Removes a vertex. 
 * return wheter sucessful or not
 */
template<class W>
bool GraphAL<W>::removeVertex(int idx) {
    return false;
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
}

template <class W>
void GraphAL<W>::print() {
}

template<class W>
GraphAL<W>::~GraphAL() {
}

#endif
