#ifndef GRAPHAL_H
#define GRAPHAL_H

/* This class represents a weighted driected graph via an adjacency list.
 * Vertices are given an index, starting from 0 and ascending
 * Class W : W represent the weight that can be associacted with an edge.
 * We will not weight the vertices.
 */

template<class W>
class GraphAL {
    private:
        /* Class to begin filling out...*/
    public:
        /* Initialize an empty graph. */
        GraphAL();

        /* Initialize the Graph with a fixed number of vertices. */
        GraphAL(const int vertices);

        /* Deconstructor shall free up memory */
        ~GraphAL();

        /* Adds amt vertices to the graph. */
        void addVertices(int amt);

        /* Removes a vertex. 
         * return wheter sucessful or not
         */
        bool removeVertex(int idx);

        /* Adds an edge with weight W to the graph. */
        bool addEdge(const int start, const int end, const W &weight);

        /* 
         * Remove edge from graph.
         */
        bool removeEdge(const int start, const int end);

        void depthFirstTraversal(void (*visit)(const int node));
        void breadthFirstTraversal(void (*visit)(const int node));

        /*
         * Return adjacent weight from start to end (or -1 if they are
         * not adjacent.
         */
        W adjacent(const int start, const int end);

        /* Returns the TOTAL weight of the minimum spanning tree with the
         * given starting node.
         * You must use Prim’s MST.
         */
         W prims(const int start);

        /* Print out the Graph */
        void print();

};

#include "graphal.cpp"

#endif

