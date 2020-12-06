#include<stdio.h>
#include<iostream>
#include<fstream>
//#include<chrono>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
using namespace std;
//using namespace std::chrono;

int main(int argC,char* args[]){
	if (argC != 4){
		cout << "Usage: ./<program_name> private_key_file inputFile outputFile" << endl;
	} else {
		ifstream priv(args[1]);
		string s1;
		string s2;
		priv >> s1;
		priv >> s2;

		ReallyLongInt d(s1);
		ReallyLongInt n(s2);

		ifstream encFile(args[2]);
		ofstream fout(args[3]);

		string y;
		// chars are 0 to 256, must convert ReallyLongInt into character
		encFile >> y;
		ReallyLongInt st(y);
		while(!encFile.eof()){
			st = y;
			//high_resolution_clock::time_point t1 = high_resolution_clock::now();
			ReallyLongInt s = modPower(st,d,n);
			//high_resolution_clock::time_point t2 = high_resolution_clock::now();
			//auto duration = duration_cast<microseconds>(t2-t1).count();
			//cout << "Time to execute modPower: " << duration << endl;
			//-- With 40 digit key, takes about a second per character
			long long c = s.toLongLong();
			fout << (char)c;
			encFile >> y;
		}
	}
}