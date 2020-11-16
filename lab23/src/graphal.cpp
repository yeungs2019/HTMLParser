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
    if(vertices <= 0){
	return;
    }
    mAList.resize(vertices);
    for(int i = 0; i < vertices; i++){
	std::list<node_x> l;
	mAList.push_back(l);
    }
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    /*std::pair<int, W> toAdd(end, weight);
    graph[start].push_back(toAdd);
    return true;*/
    if(start < 0 || start >= mAList.size()){
	return false;
    }
    if(end < 0 || end >= mAList.size()){
	return false;
    }
    node_x node;
    node.mEndVertex = end;
    node.mWeight = weight;
    mAList[start].push_back(node);

    return true;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    /*for(auto i = graph[start].begin(); i != graph[start].end(); i++){
        if(i->first == end){
            graph[start].erase(i);
            return true;
        }
    }
    return false;*/
    if(start < 0 || start >= mAList.size()){
	return false;
    }
    if(end < 0 || end >= mAList.size()){
	return false;
    }
    bool found = false;
    for (typename std::list<node_x>::iterator it = mAList[start].begin(); it != mAList[start].end(); it++){
	if(it->mEndVertex == end){
	    found = true;
	    it = mAList[start].erase(it);
	}
    }
    return found;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
    mAList.resize(mAList.size() + amt);
    for(int i = 0; i < amt; i++){
	std::list<node_x> l;
	mAList.push_back(l);
    }
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
    if(start < 0 || start >= mAList.size()){
	return -1;
    }
    if(end < 0 || end >= mAList.size()) {
	return -1;
    }
    for(typename std::list<node_x>::iterator it = mAList[start].begin(); it != mAList[start].end(); it++){
	if(it->mEndVertex == end){
	    return it->mWeight;
	}
    }
    return -1;
}

/* Removes a vertex. 
 * return wheter sucessful or not
 */
template<class W>
bool GraphAL<W>::removeVertex(int idx) {
    if(idx < 0 || idx >= mAList.size()){
	return false;
    }
    for (int i = 0; i < mAList.size(); i++){
	if(i == idx){
	    continue;
	}
	while(removeEdge(i, idx)) {}
    }
    mAList[idx] = mAList[mAList.size() - 1];
    mAList.erase((mAList.end() - 1));
    mAList.resize(mAList.size() - 1);

    for (int i = 0; i < mAList.size(); i++){
	if(i == idx){
	    continue;
	}
	for(typename std::list<node_x>::iterator it = mAList[i].begin(); it != mAList[i].end(); it++){
	    if(it->mEndVertex == mAList.size()){
		it->mEndVertex = idx;
	    }
	}
	return true;
    }
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node),  bool *visited, const int cVertex) {
    if(!visited[cVertex]){
	visited[cVertex] = true;
	visit(cVertex);

	for(typename std::list<node_x>::iterator it = mAList[cVertex].begin(); it != mAList[cVertex].end(); it++){
	    depthFirstTraversal(visit, visited, it->mEndVertex);
	}
    }
    return;
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
    if(mAList.size() <= 0){
	return;
    }
    bool *visited = new bool[mAList.size()];
    for(int i = 0; i < mAList.size(); i++){
	visited[i] = false;
    }
    depthFirstTraversal(visit, visited, 0);
    delete[] visited;
    return;
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    if(mAList.size() <= 0){
	return;
    }
    bool *visited = new bool[mAList.size()];
    for(int i = 0; i < mAList.size(); i++){
	visited[i] = false;
    }
    std::queue<int> q;
    q.push(0);
    while(!q.empty()){
	int cVertex = q.front();
	q.pop();
	if(!visited[cVertex]){
	    visit(cVertex);
	    visited[cVertex] = true;

	    typename std::list<node_x>::iterator it = mAList[cVertex].begin();
	    for(; it != mAList[cVertex].end(); it++){
		q.push(it->mEndVertex);
	    }
	}
    }
    delete[] visited;
    return;
}

template <class W>
W GraphAL<W>::prims(const int start){
    std::list<int> visited;
    std::list<int> toVisit;
    std::list<node_x> edgesUsed;

    for(int i = 0; i < mAList.size(); i++){
	if(i == start){
	     visited.push_back(i);
	}
	else{
	    toVisit.push_back(i);
	}
    }
    while(!toVisit.empty()){
	std::list<node_x> validEdges;
	for(typename std::list<int>::iterator i = visited.begin(); i != visited.end(); i++){
	    for(typename std::list<node_x>::iterator it = mAList[*i].begin(); it != mAList[*i].end(); it++){
		for(typename std::list<int>::iterator j = toVisit.begin(); j != toVisit.end(); j++){
		    if(it->mEndVertex == *j){
			validEdges.push_back((*it));
		    }
		}
	    }
	}
	if(validEdges.size() == 0) break;

	node_x minEdge = *(validEdges.begin());
	for(typename std::list<node_x>::iterator i = validEdges.begin(); i != validEdges.end(); i++){
	    if(i->mWeight < minEdge.mWeight){
		minEdge = *i;
	    }
	}
	visited.push_back(minEdge.mEndVertex);
	for(typename std::list<int>::iterator it = toVisit.begin(); it != toVisit.end(); it++){
	    if(*it == minEdge.mEndVertex){
		toVisit.erase(it);
		break;
	    }
	}
	edgesUsed.push_back(minEdge);
    }
    if(edgesUsed.size() == 0){
	return 0;
    }
    W sum = 0;
    for(typename std::list<node_x>::iterator i = edgesUsed.begin(); i != edgesUsed.end(); i++){
	sum += i->mWeight;
    }
    return sum;
}
    


template <class W>
void GraphAL<W>::print() {
}

template<class W>
GraphAL<W>::~GraphAL() {
}

#endif
