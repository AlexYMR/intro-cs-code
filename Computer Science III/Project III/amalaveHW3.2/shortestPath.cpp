#include "shortestPath.hpp"

void dijkstra(const double* const* matrix,int numVertices,int source,double*& dist,int*& prev){
	prev = new int[numVertices];
	dist = new double[numVertices];
	bool* contains = new bool[numVertices];

	for(int i = 0; i < numVertices; i++){
		prev[i] = 0;
		dist[i] = numeric_limits<double>::infinity();
		contains[i] = false;
	}
	
	int n = source;
	dist[n] = 0;
	contains[n] = true;

	for(int i = 1; i < numVertices; i++){
		for(int k = 0; k < numVertices; k++){
			if(!contains[k] and (dist[n] + matrix[n][k]) < dist[k]){
				dist[k] = dist[n] + matrix[n][k];
				prev[k] = n;
			}
		}

		double min = numeric_limits<double>::infinity();
		for(int k = 0; k < numVertices; k++){
			if(!contains[k] and dist[k] < min){
				n = k;
				min = dist[k];
			}
		}
		contains[n] = true;
	}

	delete[] contains;

}

//NOT WORKING AS INTENDED
void dijkstra(const int* const* adj,const double* const* weights,const int* lengths,int numVertices,int source,double*& dist,int*& prev){
	//int** adj
	//double** weights
	//int* lengths
	//int numVertices
	//int source

	prev = new int[numVertices];
	dist = new double[numVertices];

	for(int i = 0; i < numVertices; i++){
		prev[i] = 0;
		dist[i] = numeric_limits<double>::infinity();
	}

	BinaryHeap heap(dist,numVertices);
	heap.decreasePriority(source,0);
	int n = heap.getMin();
	dist[n] = 0;

	for(int i = 1; i < numVertices; i++){
		for(int k = 0; k < lengths[n]; k++){
			/*cout << "n: " << n << endl;
			cout << "k: " << k << endl;
			cout << "weights[n][k]: " << weights[i][k] << endl;*/
			cout << "old dist[n] + weights[n][k]: " << dist[n] + weights[n][k] << endl;
			if(heap.contains(adj[n][k]) && (dist[n] + weights[n][k]) < heap.getPriority(adj[n][k])){
				heap.decreasePriority(adj[n][k],dist[n] + weights[n][k]);
				cout << "dist[n] + weights[n][k]: " << dist[n] + weights[n][k] << endl;
				cout << heap.getPriority(adj[n][k]) << endl;
				cout << "n: " << n << endl;
				cout << "k: " << k << endl;
				cout << "lengths[n]: " << lengths[n] << endl;
				cout << "i: " << i << endl;
				prev[adj[n][k]] = n;
			}
		}
		n = heap.getMin();
		dist[n] = heap.getPriority(n);
		heap.popMin();
	}
}

int getPath(int source,int dest,const int* prev,int*& path){
	int currentIdx = dest;
	stack<int> s;
	
	s.push(dest);//the last vertex visited will be dest
	while(currentIdx != source){
		s.push(prev[currentIdx]);
		currentIdx = prev[currentIdx];
	}

	int pathSize = s.size();
	path = new int[pathSize];

	int idx = 0;
	while(!s.empty()){
		path[idx] = s.top();
		s.pop();
		idx++;
	}

	return pathSize;
}

int bellmanFord(const int* const* edges,const double* weights,int numVertices,int numEdges,int source,double*& dist,int*& prev){
	//finds shortest path from source to all other vertices
	//returns -1 if no negative cycles are found, otherwise returns index of a vertex that was updated
	
	//int** edges
	//double* weights
	//int numVertices
	//int numEdges
	//int source
	//double* dist
	//int* prev

	prev = new int[numVertices];
	dist = new double[numVertices];

	for(int i = 0; i < numVertices; i++){
		prev[i] = 0;
		dist[i] = numeric_limits<double>::infinity();
	}

	dist[source] = 0;

	for(int i = 1; i < numVertices; i++){
		for(int e = 0; e < numEdges; e++){
			if(dist[edges[e][0]] + weights[e] < dist[edges[e][1]]){
				dist[edges[e][1]] = dist[edges[e][0]] + weights[e];
				prev[edges[e][1]] = edges[e][0];
			}
		}
	}

	//check for negative cycles
	int vertex = -1;
	for(int e = 0; e < numEdges; e++){
		if(dist[edges[e][0]] + weights[e] < dist[edges[e][1]]){
			vertex = edges[e][0];
			dist[edges[e][1]] = dist[edges[e][0]] + weights[e];
			prev[edges[e][1]] = edges[e][0];
		}
	}

	return vertex;
}

int getCycle(int vertex,const int* prev,int numVertices,int*& cycle){
	int currentIdx = vertex;
	bool seenVertices[numVertices];
	for(int i = 0; i < numVertices; i++){
		seenVertices[i] = false;
	}

	stack<int> s;
	while(!seenVertices[currentIdx]){
		s.push(prev[currentIdx]);
		seenVertices[currentIdx] = true;
		currentIdx = prev[currentIdx];
	}
	s.push(prev[currentIdx]);//add end of cycle

	int cycleSize = s.size();
	cycle = new int[cycleSize];

	int idx = 0;
	while(!s.empty()){
		cycle[idx] = s.top();
		s.pop();
		idx++;
	}

	return cycleSize;
}