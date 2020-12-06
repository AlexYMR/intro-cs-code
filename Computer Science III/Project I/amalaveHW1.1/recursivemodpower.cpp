#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

unsigned long long power(unsigned long long base, unsigned long long exponent){
	//should return base^exponent
	if (exponent == 1){
		return base;
	} else {
		if (exponent%2 == 0){
			long long n = power(base,floor(exponent/2));
			return n*n;
		} else {
			long long n = power(base,floor(exponent/2));
			return base*n*n;
		}
	}
}

unsigned long long modPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus){
	return (power(base,exponent) % modulus);
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
	return 0;
}