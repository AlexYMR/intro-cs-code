#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cmath>
#include<chrono>
#include "shortestPath.hpp"
#include "readGraph.hpp"

using namespace std;
using namespace std::chrono;

int main(int argC,char* args[]){
	if (argC != 6){
		cout << "Usage: ./<program_name> inputFile outputFile source_Currency target_Currency transaction_Fee" << endl;
	} else {
		ifstream fin(args[1]);
		double fee = stod(args[5]);
		int e = 0;
		int** edges = 0;
		double* weights = 0;
		string* vLabels = 0;
		string* eLabels = 0;
		int v = readGraph(fin,edges,weights,e,vLabels,eLabels);

		//convert weights to log form
		for(int i = 0; i < e; i++){
			//cout << "\nprior weights[i]: " << weights[i] << endl;
			weights[i] = -log(weights[i]*(1-fee));
			//cout << "\nweights[i]: " << weights[i] << endl;
		}

		double* dist = 0;
		int* prev = 0;

		int sourceIdx = 0;
		string source = args[3];

		while(vLabels[sourceIdx] != source){
			sourceIdx++;
		}

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		int vertex = bellmanFord(edges,weights,v,e,sourceIdx,dist,prev);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(t2-t1).count();
		cout << "Time taken to execute Bellman-Ford Algorithm: " << duration << " microsecond" << ((duration == 1) ? "":"s") << endl;

		if(vertex == -1){
			string dest = args[4];
			int destIdx = 0;

			while(vLabels[destIdx] != dest){
				destIdx++;
			}

			int* path = 0;
			int pathSize = getPath(sourceIdx,destIdx,prev,path);

			ofstream fout(args[2]);
			fout << v << " " << pathSize-1 << endl;//I add the last vertex to the path
			for(int i = 0; i < v; i++){
				fout << vLabels[i] << endl;
			}

			double pathRate = 1;
			for(int i = 0; i < pathSize-1; i++){
				fout << path[i] << " " << path[i+1] << " ";
				int k = 0;
				while(edges[k][0] != path[i] or edges[k][1] != path[i+1]){
					k++;
				}
				fout << exp(-weights[k]) << " " << eLabels[k] << endl;
				pathRate *= exp(-weights[k]);
			}
			cout << "Effective exchange rate: " << pathRate << endl;
			delete[] path;

		} else{
			cout << "Arbitrage opportunity detected" << endl;
			int* cycle = 0;
			int cycleSize = getCycle(vertex,prev,v,cycle);

			ofstream fout("negativeCycle.txt");
			fout << v << " " << cycleSize-1 << endl;
			for(int i = 0; i < v; i++){
				fout << vLabels[i] << endl;
			}
			double cycleRate = 1;
			for(int i = 0; i < cycleSize-1; i++){
				fout << cycle[i] << " " << cycle[i+1] << " ";
				int k = 0;
				while(edges[k][0] != cycle[i] or edges[k][1] != cycle[i+1]){
					k++;
				}
				fout << exp(-weights[k]) << " " << eLabels[k] << endl;
				cycleRate *= exp(-weights[k]);
			}
			cout << "Effective exchange rate: " << cycleRate << endl;

			delete[] cycle;
		}

		//clean-up
		for(int i = 0; i < v; i++){
			delete[] edges[i];
		}
		delete[] edges;
		delete[] weights;
		delete[] vLabels;
		delete[] eLabels;
		delete[] prev;
		delete[] dist;

		return 0;
	}
}