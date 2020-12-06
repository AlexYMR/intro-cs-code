#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include "shortestPath.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the dijkstra function"){
		cout << "\nTesting the dijkstra function...";

		ifstream fin("graph.txt");
		double** matrix = 0;
		string* vLabels = 0;
		string** eLabels = 0;
		int v = readGraph(fin,matrix,vLabels,eLabels);

		double* dist = 0;
		int* prev = 0;

		int source = 2;
		dijkstra(matrix,v,source,dist,prev);

		
		cout << "\nVertex " << source << ": " << vLabels[source] << endl;
		for(int k = 0; k < v; k++){
			cout << "The shortest distance from " << vLabels[source] << " to " << vLabels[k] << " is: " << dist[k] << endl;
		}

		int* path = 0;
		int dest = 1;
		int pathSize = getPath(source,dest,prev,path);

		REQUIRE(pathSize == 3);

		cout << "The shortest path from " << vLabels[source] << " to " << vLabels[dest] << " is: " << endl;
		for(int i = 0; i < pathSize; i++){
			 cout << vLabels[path[i]] << ((i==pathSize-1) ? "":", ");
		}

		//clean-up
		for(int i = 0; i < v; i++){
			delete[] eLabels[i];
			delete[] matrix[i];
		}
		delete[] vLabels;
		delete[] matrix;
		delete[] eLabels;
		delete[] prev;
		delete[] dist;
		delete[] path;

		cout << "\nPASSED!" << endl;
	}

	SECTION("Testing the bellmanFord function"){
		cout << "\nTesting the bellmanFord function...";

		//const int* const* edges,const double* weights,int numVertices,int numEdges,int source,double*& dist,int*& prev);
		ifstream fin("graph.txt");
		int** edges = 0;
		string* vLabels = 0;
		string* eLabels = 0;
		double* weights = 0;
		int numEdges = 0;
		int v = readGraph(fin,edges,weights,numEdges,vLabels,eLabels);

		double* dist = 0;
		int* prev = 0;

		int source = 2;
		int negativeCycle = bellmanFord(edges,weights,v,numEdges,source,dist,prev);

		cout << "\nVertex " << source << ": " << vLabels[source] << endl;
		for(int k = 0; k < v; k++){
			cout << "The shortest distance from " << vLabels[source] << " to " << vLabels[k] << " is: " << dist[k] << endl;
		}

		int* path = 0;
		int dest = 1;
		int pathSize = getPath(source,dest,prev,path);

		REQUIRE(pathSize == 3);

		cout << "The shortest path from " << vLabels[source] << " to " << vLabels[dest] << " is: " << endl;
		for(int i = 0; i < pathSize; i++){
			 cout << vLabels[path[i]] << ((i==pathSize-1) ? "":", ");
		}

		//clean-up
		for(int i = 0; i < numEdges; i++){
			delete[] edges[i];
		}
		delete[] vLabels;
		delete[] weights;
		delete[] edges;
		delete[] eLabels;
		delete[] prev;
		delete[] dist;
		delete[] path;

		cout << "\nPASSED!" << endl;
	}
}