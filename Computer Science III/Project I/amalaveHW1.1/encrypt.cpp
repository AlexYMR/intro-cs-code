#include<stdio.h>
#include<iostream>
#include<fstream>
#include "numberTheory.h"
using namespace std;

int main(int argC,char* args[]){
	if (argC != 4){
		cout << "Usage: ./<program_name> public_key_file inputFile outputFile" << endl;
	} else {
		ifstream fin(args[1]);
		long long e;
		long long n;
		fin >> e;
		fin >> n;

		ifstream plain(args[2]);
		ofstream fout(args[3]);

		char c;
		while(plain.get(c)){
			fout << modPower(c,e,n) << endl;
		}
	}
}