#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the readGraph function"){
		cout << "\nTesting adjacency matrix readGraph function...";

		ifstream fin("graph.txt");
		double** matrix = 0;
		string* vLabels = 0;
		string** eLabels = 0;
		int v = readGraph(fin,matrix,vLabels,eLabels);

		REQUIRE(v == 4);

		for(int i = 0; i < v; i++){
			cout << endl;
			for(int k = 0; k < v; k++){
				cout << matrix[i][k] << " ";
			}
		}

		cout << endl;

		for(int i = 0; i < v; i++){
			cout << "\nVertex " << i << ": " << vLabels[i] << endl;
			for(int k = 0; k < v; k++){
				if(eLabels[i][k] != ""){
					cout << "There is a road from " << vLabels[i] << " to " << vLabels[k] << ": " << eLabels[i][k];
				} else{
					cout << "There is no road from " << vLabels[i] << " to " << vLabels[k];
				}
				cout << endl;
			}
		}

		//clean-up
		for(int i = 0; i < v; i++){
			delete[] eLabels[i];
			delete[] matrix[i];
		}
		delete[] vLabels;
		delete[] matrix;
		delete[] eLabels;

		cout << "PASSED!" << endl;
	}

	SECTION("Testing the readGraph function"){
		cout << "\nTesting adjacency list readGraph function...\n";

		ifstream fin("graph.txt");
		int** adj = 0;
		double** weights = 0;
		int* lengths = 0;
		string* vLabels = 0;
		string** eLabels = 0;
		int v = readGraph(fin,adj,weights,lengths,vLabels,eLabels);

		REQUIRE(v == 4);
		REQUIRE(lengths[0] == 1);
		REQUIRE(lengths[1] == 1);
		REQUIRE(lengths[2] == 3);
		REQUIRE(lengths[3] == 1);

		for(int i = 0; i < v; i++){
			cout << "adj[" << i << "]: ";
			for(int k = 0; k < lengths[i]; k++){
				cout << adj[i][k] << " ";
			}
			cout << endl;
		}

		cout << endl;

		for(int i = 0; i < v; i++){
			cout << "weights[" << i << "]: ";
			for(int k = 0; k < lengths[i]; k++){
				cout << weights[i][k] << " ";
			}
			cout << endl;
		}

		cout << endl;

		for(int i = 0; i < v; i++){
			cout << "eLabels[" << i << "]: ";
			for(int k = 0; k < lengths[i]; k++){
				cout << eLabels[i][k] << " ";
			}
			cout << endl;
		}

		//clean-up
		for(int i = 0; i < v; i++){
			delete[] eLabels[i];
			delete[] weights[i];
			delete[] adj[i];
		}
		delete[] vLabels;
		delete[] adj;
		delete[] weights;
		delete[] eLabels;

		cout << "PASSED!" << endl;
	}
}