#ifdef GRAPHAM_H

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#define INT_MAX (-1)
template<class W>
GraphAM<W>::GraphAM() {
    graph.resize(0);
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
    graph.resize(vertices);
    for(int i = 0; i < vertices; i++){
	graph[i].resize(vertices);
	for(int j = 0; j < vertices; j++){
	    graph[i][j] = INT_MAX;
	}
	graph[i][i] = 0;
    }
}

template<class W>
int GraphAM<W>::addVertices(const int vertices) {
    int bigW = graph.size();
    int bigH = graph[0].size(); 
    graph.resize(bigW + vertices);
    for(int i = 0; i < vertices + bigW; i++){
	graph[i].resize(bigW + vertices);
    }
    for(int i = bigW; i < graph.size(); i++){
	for(int j = 0; j < graph[i].size(); i++){
	     graph[i][j] = INT_MAX;
	}
	graph[i][i] = 0;
    }
    for(int i = 0; i < graph.size(); i++){
	for(int j = bigH; j < graph[i].size(); i++){
	    graph[i][j] = INT_MAX;
	}
	graph[i][i] = 0;
    }
    return bigW;
	
}

template<class W>
bool GraphAM<W>::removeVertex(int idx) {
    if(graph.size() == 0){
	return false;
    }
    if(idx < 0 || idx >= graph.size()){
	return false;
    }
    for(int i = idx; i < graph.size() - 1; i++){
	for(int j = 0; j < graph.size() - 1; j++){
	    graph[i][j] = graph[i + 1][j + 1];
	}
	graph[i][i] = graph[i + 1][i + 1];
    }
    graph.resize(graph.size() - 1);
    for (unsigned int i = 0; i < graph.size(); i++){
	graph[i].resize(graph[i].size() - 1);
    }
    return true;

}

template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
    /*std::pair<int, W> toAdd(end, weight);
    graph[start].push_back(toAdd);
    return true;*/
    if(graph.size() == 0){
	return false;
    }
    if(start == end){
	return false;
    }
    if((start >= 0 && start < graph.size()) && (end >= 0 && end < graph[start].size())){
	if(graph[start][end] != INT_MAX){
 	    return false;
	}
	graph[start][end] = weight;
	return true;
    }
    return false;

}

template<class W>
bool GraphAM<W>::removeEdge(const int start, const int end) {
    /*for(auto i = graph[start].begin(); i != graph[start].end(); i++){
	if(i->first == end){
	    graph[start].erase(i);
	    return true;
	}
    }
    return false;*/
    if(graph.size() == 0){
	return false;
    }
    if(start == end){
	return false;
    }
    if(graph[start][end] == INT_MAX){
	return false;
    }
    if((start >= 0 && start < graph.size()) && (end >= 0 && end < graph[start].size())){
       graph[start][end] = INT_MAX;
       return true;
    }
    return false;

}

template<class W>
W GraphAM<W>::adjacent(const int start, const int end) {
    if((start >= 0 && start < graph.size() && end >= 0) && (end < graph[start].size())){
        if(graph[start][end] != INT_MAX){
            return graph[start][end];
	}
    }
    return -1;
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node), std::vector<std::vector<int>> &graph, std::set<int> &visited, int vertex) {
   if(visited.find(vertex) != visited.end()){
	return;
   }
   visited.insert(vertex);
   (*visit)(vertex);
   for(unsigned int i = 0; i < graph[vertex].size(); i++){
	if(graph[vertex][i] > 0 && graph[vertex][i] < INT_MAX){
	    depthFirstTraversal(visit, graph, visited, i);
	}
   }
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;
    for(unsigned int i = 0; i < graph.size(); i++){
	depthFirstTraversal(visit, graph, visited, i);
    }
}

template<class W>
void GraphAM<W>::breadthFirstTraversal(void (*visit)(const int node)) {
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

template<class W>
W GraphAM<W>::dijkstraShortestPath(const int start, const int end){
    W tempW = 0;
    std::vector<std::pair<W, int> > toVisit;
    std::set<int> visited;
    std::pair<W, int> temp;

    temp.first = tempW;
    temp.second = start;
    toVisit.push_back(temp);
    while(!toVisit.empty()){
	std::pair<W, int> curr = toVisit.front();
	int vtx = curr.second;
	toVisit.erase(toVisit.begin());
	if(graph[vtx][end] > 0 && graph[vtx][end] != INT_MAX){
	    return curr.first + graph[vtx][end];
	}
	if(visited.find(vtx) != visited.end()){
	    continue;
	}
	visited.insert(vtx);
	for(int i = 0; i < graph[vtx].size(); i++){
	    if(graph[vtx][i] > 0 && graph[vtx][i] != INT_MAX){
		temp.first = graph[vtx][i] + curr.first;
		temp.second = i;
		toVisit.push_back(temp);
	    }
	}
    }
}


template<class W>
void GraphAM<W>::print() const {
}

template<class W>
GraphAM<W>::~GraphAM() {
    graph.clear();
}

#endif
