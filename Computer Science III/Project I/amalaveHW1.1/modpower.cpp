#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

unsigned long long modPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus){
	if (exponent == 1){
		return base;
	} else if (exponent == 0){
		return 1;
	} else {
		if (exponent%2 == 0){
			long long n = modPower(base,floor(exponent/2),modulus);
			return (n%modulus*n%modulus)%modulus;
		} else {
			long long n = modPower(base,floor(exponent/2),modulus);
			return (base%modulus*n%modulus*n%modulus)%modulus;
		}
	}
	//return (power(base,exponent) % modulus);
}

int main(){
	cout << modPower(2,2,3) << endl; //a
	cout << modPower(2,3,3) << endl; //b
	cout << modPower(12,12,123) << endl; //c
	cout << modPower(10,19,1019) << endl; //d
	cout << modPower(12345,1234567,123) << endl; //e
	cout << modPower(12345,1234567,123456789) << endl; //f
	cout << modPower(12345,123456789,12345) << endl; //g
	cout << modPower(12345,123456789,1234567891011) << endl; //h
	cout << modPower(4,2,0) << endl;
	return 0;
}

/*
RESULTS:

a) 1
b) 2
c) 66
d) 776
e) 66
f) 100842075
g) 0
h) 519170861217

*/