#include<math.h>
#include<cmath>
#include<iostream>

using namespace std;

unsigned long long modPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus){
	if (exponent == 1){
		return base;
	} else {
		if (exponent%2 == 0){
			long long n = modPower(base,floor(exponent/2),modulus);
			return (n%modulus*n%modulus)%modulus;
		} else {
			long long n = modPower(base,floor(exponent/2),modulus);
			return (base%modulus*n%modulus*n%modulus)%modulus;
		}
	}
}

bool isPrime(unsigned long long num){
	if (num == 1 or num == 0){
		return false;
	} else{
		for (int i = 2;i < sqrt(num);i++){
			if (num % i == 0){
				return false;
			}
		}
		return true;
	}
}

unsigned long long GCD(unsigned long long a, unsigned long long b){
	if(b == 0){
		return a;
	} else{
		return GCD(b,a%b);
	}
}

unsigned long long extendedEuclid(unsigned long long a, unsigned long long b, long long* px, long long* py){
	if(b == 0){
		*px = 1;
		*py = 0;
		return a;
	} else{
		unsigned long long d = extendedEuclid(b,a%b,px,py);
		long long xprime = *py;
		long long yprime = *px - *py * (a/b);
		*px = xprime;
		*py = yprime;
		return d;
	}
}

/*int main(){
	cout << "5,2: " << GCD(5,2) << endl;
	cout << "6,2: " << GCD (6,2) << endl;
	cout << "40,10: " << GCD (40,10) << endl;
	cout << "33,4: " << GCD(33,4) << endl;
	cout << "------ EXTENDED ------" << endl;
	long long x;
	long long y;
	long long* px = &x;
	long long* py = &y;
	cout << "5,2: " << extendedEuclid(5,2,px,py) << " = 5("<< x << ") + 2(" << y << ") = " << GCD(5,2) << endl;
	cout << "6,2: " << extendedEuclid(6,2,px,py) << " = 6("<< x << ") + 2(" << y << ") = " << GCD(6,2) << endl;;
	cout << "40,10: " << extendedEuclid(40,10,px,py) << " = 40("<< x << ") + 10(" << y << ") = " << GCD(40,10) << endl;;
	cout << "33,4: " << extendedEuclid(33,4,px,py) << " = 33("<< x << ") + 4(" << y << ") = " << GCD(33,4) << endl;;
	return 0;
}*/

