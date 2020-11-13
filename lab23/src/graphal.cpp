#ifdef GRAPHAL_H
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

template<class W>
GraphAL<W>::GraphAL() {
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
    graph.resize(vertices);
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    std::pair<int, W> toAdd(end, weight);
    graph[start].push_back(toAdd);
    return true;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    for(auto i = graph[start].begin(); i != graph[start].end(); i++){
        if(i->first == end){
            graph[start].erase(i);
            return true;
        }
    }
    return false;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
    if(graph[start].empty()){
        return -1;
    }

    for (auto i = graph[start].begin(); i != graph[start].end(); i++) {
        if(i->first == end){
            return i->second;
        }
    }

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
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), const int node, std::set<int> &visited) {
    if(visited.find(node) != visited.end()) {
        return;
    }

    visit(node);
    visited.insert(node);

    for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
        depthFirstTraversal(visit, i->first, visited);
    }
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;

    for (int i = 0; i < graph.size(); i++) {
        depthFirstTraversal(visit, i, visited);
    }
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    std::queue<int> toVisit;
    std::set<int> visited;
    for(int i = 0; i < graph.size(); i++){
	toVisit.push(i);
	while(!toVisit.empty()){
	    int vertex = toVisit.front();
	    toVisit.pop();
	    if(visited.find(vertex) != visited.end()){
		continue;
	    }
	    visit(vertex);
	    visited.insert(vertex);
	    for(auto i = graph[vertex].begin(); i != graph[vertex].end(); i++){
		toVisit.push(i->second);
	    }
	}
    }
}

template <class W>
void GraphAL<W>::print() {
}

template<class W>
GraphAL<W>::~GraphAL() {
}

#endif
