#include<iostream>
#include<fstream>
#include<stdio.h>
#include <stdlib.h> //used for strtol, which converts strings to ints
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main(int argC,char* args[]){
	if(argC != 5){
		cout << "Usage: ./<program_name> pNumber1 pNumber2 publicFile privateFile" << endl;
	} else {
		ReallyLongInt p(args[1]);
		ReallyLongInt q(args[2]);
		//unsigned long long p = strtol(args[1],NULL,0); //converts str -> int
		//unsigned long long q = strtol(args[2],NULL,0);
		bool passed = false;
		if(p > 100000 or q > 100000){
			cout << "At least one of the arguments given were too large. Primality is not being verified." << endl;
			passed = true;
		} else {
			passed = (isPrime(p) and isPrime(q)) ? true:false;
		}
		
		if(passed and (p*q >= 256)){
			ReallyLongInt n = p*q;
			ReallyLongInt t = (p-1)*(q-1);
			ReallyLongInt x;
			ReallyLongInt y;
			ReallyLongInt* px = &x;
			ReallyLongInt* py = &y;
			ReallyLongInt e(2);
			/*unsigned long long n = p*q;
			unsigned long long t = (p-1)*(q-1);
			long long x;
			long long y;
			long long* px = &x;
			long long* py = &y;
			int e = 2;*/
			while(extendedEuclid(e,t,px,py) != 1){
				e += 1;
			}
			if(x < 0){ // = d
				x += t;
			}
			
			ofstream public_file(args[3]);
			public_file << e << " " << n << endl;

			ofstream private_file(args[4]);
			private_file << x << " " << n << endl;

		} else{
			cout << "The numbers provided must both be prime numbers, and their product must be equal to or greater than 256. Please check your input and try again." << endl;
			return 1;
		}
	}
}