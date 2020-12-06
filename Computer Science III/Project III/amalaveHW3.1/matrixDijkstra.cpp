#include<stdio.h>
#include<iostream>
#include<fstream>
#include<chrono>
#include "shortestPath.hpp"
#include "readGraph.hpp"

using namespace std;
using namespace std::chrono;

int main(int argC,char* args[]){
	if (argC != 5){
		cout << "Usage: ./<program_name> inputFile outputFile source_Name dest_Name" << endl;
	} else {
		ifstream fin(args[1]);
		double** matrix = 0;
		string* vLabels = 0;
		string** eLabels = 0;
		int v = readGraph(fin,matrix,vLabels,eLabels);

		double* dist = 0;
		int* prev = 0;

		int sourceIdx = 0;
		string source = args[3];

		while(vLabels[sourceIdx] != source){
			sourceIdx++;
		}

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		dijkstra(matrix,v,sourceIdx,dist,prev);
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
		fout << v << " " << pathSize-1 << endl; //pathSize will be 1 larger, because I'm including the final vertex as part of the path...
		for(int i = 0; i < v; i++){
			fout << vLabels[i] << endl;
		}

		for(int i = 0; i < pathSize-1; i++){ //#edges = pathSize-1
			fout << path[i] << " " << path[i+1] << " " << matrix[path[i]][path[i+1]] << " " << eLabels[path[i]][path[i+1]] << endl;
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

		return 0;
	}
}