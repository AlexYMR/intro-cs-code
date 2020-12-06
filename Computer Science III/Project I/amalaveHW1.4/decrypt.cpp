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
		string s1;
		string s2;
		fin >> s1;
		fin >> s2;

		ReallyLongInt d(s1);
		ReallyLongInt n(s2);

		ifstream encFile(args[2]);
		ofstream fout(args[3]);

		ReallyLongInt y;
		encFile >> y;
		while(!encFile.eof()){
			ReallyLongInt s = modPower(y,d,n);
			long long c = s.toLongLong();
			fout << (char)c;
			encFile >> y;
		}
	}
}