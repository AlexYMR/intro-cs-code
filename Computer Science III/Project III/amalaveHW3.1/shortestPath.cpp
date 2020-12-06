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
			if(heap.contains(adj[n][k]) and (dist[n] + weights[n][k]) < heap.getPriority(adj[n][k])){
				heap.decreasePriority(adj[n][k],dist[n] + weights[n][k]);
				//cout << "prev[k]: " << prev[k] << " = " << n << endl;
				prev[k] = n;
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