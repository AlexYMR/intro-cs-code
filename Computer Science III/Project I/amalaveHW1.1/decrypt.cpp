#include<stdio.h>
#include<iostream>
#include<fstream>
#include "numberTheory.h"
using namespace std;

int main(int argC,char* args[]){
	if (argC != 4){
		cout << "Usage: ./<program_name> private_key_file inputFile outputFile" << endl;
	} else {
		ifstream fin(args[1]);
		long long d;
		long long n;
		fin >> d;
		fin >> n;

		ifstream encFile(args[2]);
		ofstream fout(args[3]);

		int y;
		encFile >> y;
		while(!encFile.eof()){
			fout << (char)modPower(y,d,n);
			encFile >> y;
		}
	}
}