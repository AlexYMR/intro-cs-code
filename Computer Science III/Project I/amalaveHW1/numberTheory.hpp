#ifndef NUMTHEORY_H
#define NUMTHEORY_H

#include "numberTheory.tpp"

template<class X>
bool isPrime(const X& num);

template<class X>
X modPower(const X& base,const X& exponent,const X& modulus);

template<class X>
X extendedEuclid(const X& a,const X& b, X* x, X* y);

/*unsigned long long modPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus);

bool isPrime(unsigned long long num);

unsigned long long extendedEuclid(unsigned long long a, unsigned long long b, long long* px, long long* py);

unsigned long long GCD(unsigned long long a, unsigned long long b);*/

#endif