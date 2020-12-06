#include<stdio.h>
#include<iostream>
#include<fstream>
#include<chrono>
#include "shortestPath.hpp"
#include "readGraph.hpp"
#include "BinaryHeap.hpp"

using namespace std;
using namespace std::chrono;

int main(int argC,char* args[]){
	if (argC != 5){
		cout << "Usage: ./<program_name> inputFile outputFile source_Name dest_Name" << endl;
	} else {
		ifstream fin(args[1]);
		int** adj = 0;
		double** weights = 0;
		int* lengths = 0;
		string* vLabels = 0;
		string** eLabels = 0;
		int v = readGraph(fin,adj,weights,lengths,vLabels,eLabels);

		double* dist = 0;
		int* prev = 0;

		int sourceIdx = 0;
		string source = args[3];

		while(vLabels[sourceIdx] != source){
			sourceIdx++;
		}

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		dijkstra(adj,weights,lengths,v,sourceIdx,dist,prev);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(t2-t1).count();
		cout << "Time taken to execute Dijkstra's Algorithm: " << duration << " microsecond" << ((duration == 1) ? "":"s") << endl;

		string dest = args[4];
		int destIdx = 0;

		while(vLabels[destIdx] != dest){
			destIdx++;
		}

		int* path = 0;
		for(int i = 0; i < v; i++){
			cout << "\n" << prev[i] << endl;
		}

		int pathSize = getPath(sourceIdx,destIdx,prev,path);

		ofstream fout(args[2]);
		fout << v << " " << pathSize << endl;
		for(int i = 0; i < v; i++){
			fout << vLabels[i] << endl;
		}

		for(int i = 0; i < pathSize-1; i++){
			fout << path[i] << " " << path[i+1] << " " << adj[path[i]][path[i+1]] << " " << eLabels[path[i]][path[i+1]] << endl;
		}

		//clean-up
		for(int i = 0; i < v; i++){
			delete[] eLabels[i];
			delete[] adj[i];
		}
		delete[] lengths;
		delete[] vLabels;
		delete[] eLabels;
		delete[] prev;
		delete[] dist;
		delete[] path;

		return 0;
	}
}