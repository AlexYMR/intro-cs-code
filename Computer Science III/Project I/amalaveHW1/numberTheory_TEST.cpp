#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
#include<cmath>

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the modPower function..."){ // Very large values return errors. No lead on solution.
		cout << "\nTesting the modPower function...";
		ReallyLongInt s(10);
		ReallyLongInt d(19);
		ReallyLongInt e(1019);
		REQUIRE(modPower(2,2,3) == 1);
		REQUIRE(modPower(2,3,3) == 2);
		REQUIRE(modPower(12,12,123) == 66);
		REQUIRE(modPower(s,d,e) == 776);
		REQUIRE(modPower(12345,1234567,123) == 66);
		REQUIRE(modPower((unsigned long long)12345,(unsigned long long)1234567,(unsigned long long)123456789) == 100842075); //modPower function used to produce good results for this; not anymore
		ReallyLongInt x("12345");
		ReallyLongInt y("1234567");
		ReallyLongInt z("123456789");
		REQUIRE(modPower(x,y,z) == 100842075);
		REQUIRE(modPower(12345,123456789,12345) == 0);
		REQUIRE(modPower(123,123,1) == 0);
		ReallyLongInt x2("12345");
		ReallyLongInt y2("123456789");
		ReallyLongInt z2("1234567891011");
		ReallyLongInt ans2("519170861217");
		REQUIRE(modPower(x2,y2,z2) == ans2);
		//Mod 0 is supposed to be undefined; the terminal outputs "Floating point exception (core dumped)
		//Signed integers do not work, nor do decimals, since modPower does not accept signed integers, or float values, as parameters	
		cout << "PASSED!" << endl;
	}
	
	SECTION("Testing the isPrime function..."){
		cout << "\nTesting the isPrime function...";
		REQUIRE(isPrime(0) == false);
		REQUIRE(isPrime(1) == false);
		REQUIRE(isPrime(2) == true);
		REQUIRE(isPrime(23) == true);
		REQUIRE(isPrime(18) == false);
		REQUIRE(isPrime(673487) == true);
		//
		ReallyLongInt x(123456789);
		ReallyLongInt y(10928);
		ReallyLongInt z(89);
		REQUIRE(isPrime(x) == false);
		REQUIRE(isPrime(y) == false);
		REQUIRE(isPrime(z) == true);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the extendedEuclid function..."){
		cout << "\nTesting the extendedEuclid function...";
		long long x;
		long long y;
		long long* px = &x;
		long long* py = &y;
		ReallyLongInt x1;
		ReallyLongInt y1;
		ReallyLongInt* px1 = &x1;
		ReallyLongInt* py1 = &y1;
		REQUIRE(extendedEuclid((long long)5,(long long)2,px,py) == 1);
		REQUIRE(extendedEuclid((long long)6,(long long)2,px,py) == 2);
		REQUIRE(extendedEuclid((long long)40,(long long)10,px,py) == 10);
		REQUIRE(extendedEuclid((long long)33,(long long)4,px,py) == 1);

		ReallyLongInt n(12345);
		ReallyLongInt m(123);
		x1 = n;
		y1 = m;
		REQUIRE(extendedEuclid(x1,y1,px1,py1) == 3); //this one doesn't work either
		cout << "PASSED!" << endl;;
	}
}