#include<iostream>
#include<fstream>
#include<stdio.h>
#include <stdlib.h> //used for strtol, which converts strings to ints
#include "numberTheory.h"

using namespace std;

int main(int argC,char* args[]){
	if(argC != 5){
		cout << "Usage: ./<program_name> pNumber1 pNumber2 publicFile privateFile" << endl;
	} else {
		unsigned long long p = strtol(args[1],NULL,0); //converts str -> int
		unsigned long long q = strtol(args[2],NULL,0);
		if(isPrime(p) and isPrime(q) and (p*q >= 256)){
			ofstream public_file(args[3]);
			ofstream private_file(args[4]);
			unsigned long long n = p*q;
			unsigned long long t = (p-1)*(q-1);
			long long x;
			long long y;
			long long* px = &x;
			long long* py = &y;
			int e = 2;
			while(extendedEuclid(e,t,px,py) != 1){
				e = e + 1;
			}
			if(x < 0){ // = d
				//cout << "x = " << x << endl;
				x = x+t;
				//cout << "x+t = " << x << endl;
			}
			public_file << e << " " << n << endl;
			private_file << x << " " << n << endl;

		} else{
			cout << "The numbers provided must both be prime numbers, and their product must be equal to or greater than 256. Please check your input and try again." << endl;
			return 1;
		}
	}
}