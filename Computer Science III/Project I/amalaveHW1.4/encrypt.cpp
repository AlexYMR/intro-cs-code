#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include "numberTheory.h"
using namespace std;

int main(int argC,char* args[]){
	if (argC != 4){
		cout << "Usage: ./<program_name> public_key_file inputFile outputFile" << endl;
	} else {
		ifstream fin(args[1]);
		string s1;
		string s2;
		fin >> s1;
		fin >> s2;

		ReallyLongInt e(s1);
		ReallyLongInt n(s2);

		ifstream plain(args[2]);
		ofstream fout(args[3]);

		char c;
		while(plain.get(c)){
			ReallyLongInt cInt(c);
			fout << modPower(cInt,e,n) << endl;
		}
	}
}