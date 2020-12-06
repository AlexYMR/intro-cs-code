#include "readGraph.hpp"

int readGraph(ifstream& fin,double**& matrix,string*& vLabels,string**& eLabels){
	string s1;
	string s2;
	fin >> s1;
	fin >> s2;
	int v = stoi(s1);
	int e = stoi(s2);
	
	matrix = new double*[v];
	vLabels = new string[v];
	eLabels = new string*[v];

	for(int i = 0; i < v; i++){
		double* tab = new double[v];
		string* tab2 = new string[v];
		for(int k = 0; k < v; k++){
			tab[k] = (k == i) ? 0:numeric_limits<double>::infinity();
			tab2[k] = "";
		}
		matrix[i] = tab;
		eLabels[i] = tab2;
		fin >> vLabels[i];
	}

	for(int i = 0; i < e; i++){
		string source;
		string dest;
		string weight;
		string roadName;
		fin >> source;
		fin >> dest;
		fin >> weight;
		fin >> roadName;
		int sourceIndex = stoi(source);
		int destinationIndex = stoi(dest);
		double numWeight = stod(weight);
		matrix[sourceIndex][destinationIndex] = numWeight;
		eLabels[sourceIndex][destinationIndex] = roadName;
	}

	return v;
}

int readGraph(ifstream& fin,int**& adj,double**& weights,int*& lengths,string*& vLabels,string**& eLabels){
	string s1;
	string s2;
	fin >> s1;
	fin >> s2;
	int v = stoi(s1);
	int e = stoi(s2);

	adj = new int*[v];
	weights = new double*[v];
	lengths = new int[v];
	vLabels = new string[v];
	eLabels = new string*[v];

	for(int i = 0; i < v; i++){
		fin >> vLabels[i];
	}

	int currentSource = 0;
	int currentCount = 0;
	queue<int> curSource;
	queue<int> curDest;
	queue<double> curWeights;
	queue<string> cur_eLabels;
	for(int i = 0; i < e; i++){
		string source;
		string dest;
		string weight;
		string roadName;
		fin >> source;
		fin >> dest;
		fin >> weight;
		fin >> roadName;

		int sourceIndex = stoi(source);
		if(sourceIndex > currentSource){
			lengths[currentSource] = currentCount;

			adj[currentSource] = new int[currentCount];
			int idx = 0;
			while(!curDest.empty()){
				adj[currentSource][idx] = curDest.front();
				curDest.pop();
				idx++;
			}
			
			weights[currentSource] = new double[currentCount];
			idx = 0;
			while(!curWeights.empty()){
				weights[currentSource][idx] = curWeights.front();
				curWeights.pop();
				idx++;
			}

			eLabels[currentSource]= new string[currentCount];
			idx = 0;
			while(!cur_eLabels.empty()){
				eLabels[currentSource][idx] = cur_eLabels.front();
				cur_eLabels.pop();
				idx++;
			}

			currentCount = 0;
			currentSource += 1;
		}

		currentCount++;

		int destinationIndex = stoi(dest);
		double numWeight = stod(weight);
		
		curDest.push(destinationIndex);
		curWeights.push(numWeight);
		cur_eLabels.push(roadName);
	}

	lengths[currentSource] = currentCount;

	adj[currentSource] = new int[currentCount];
	int idx = 0;
	while(!curDest.empty()){
		adj[currentSource][idx] = curDest.front();
		curDest.pop();
		idx++;
	}
	
	weights[currentSource] = new double[currentCount];
	idx = 0;
	while(!curWeights.empty()){
		weights[currentSource][idx] = curWeights.front();
		curWeights.pop();
		idx++;
	}

	eLabels[currentSource]= new string[currentCount];
	idx = 0;
	while(!cur_eLabels.empty()){
		eLabels[currentSource][idx] = cur_eLabels.front();
		cur_eLabels.pop();
		idx++;
	}

	

	return v;
}

int readGraph(ifstream& fin, int**& edgeList,double*& weights,int& numEdges,string*& vLabels,string*& eLabels){
	string s1;
	string s2;
	fin >> s1;
	fin >> s2;
	int v = stoi(s1);
	int e = stoi(s2);

	numEdges = e;
	edgeList = new int*[e]; //contains a bunch of tuples representing edges
	weights = new double[e]; //contains weights associated with edges
	eLabels = new string[e]; //contains eLabels associated with edges in edgeList
	vLabels = new string[v];

	for(int i = 0; i < v; i++){
		fin >> vLabels[i];
	}

	for(int i = 0; i < e; i++){
		string source;
		string dest;
		string weight;
		string roadName;
		fin >> source;
		fin >> dest;
		fin >> weight;
		fin >> roadName;

		int sourceIndex = stoi(source);
		int destinationIndex = stoi(dest);
		double numWeight = stod(weight);

		int* edge = new int[2];
		edge[0] = sourceIndex;
		edge[1] = destinationIndex;
		edgeList[i] = edge;

		weights[i] = numWeight;

		eLabels[i] = roadName;
	}

	return v;
}