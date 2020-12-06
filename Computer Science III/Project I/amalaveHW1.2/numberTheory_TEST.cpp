#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "numberTheory.h"

using namespace std;

TEST_CASE("Initiating test..."){
	cout << "Initiating test..." << endl;
	SECTION("Testing the modPower function..."){
		cout << "Testing the modPower function..." << endl;
		REQUIRE(modPower(2,2,3) == 1);
		REQUIRE(modPower(2,3,3) == 2);
		REQUIRE(modPower(12,12,123) == 66);
		REQUIRE(modPower(10,19,1019) == 776);
		REQUIRE(modPower(12345,1234567,123) == 66);
		REQUIRE(modPower(12345,1234567,123456789) == 100842075);
		REQUIRE(modPower(12345,123456789,12345) == 0);
		REQUIRE(modPower(123,123,1) == 0);
		REQUIRE(modPower(12345,123456789,1234567891011) == 519170861217);
		//Mod 0 is supposed to be undefined; the terminal outputs "Floating point exception (core dumped)
		//Signed integers do not work, nor do decimals, since modPower does not accept signed integers, or float values, as parameters	
	}

	SECTION("Testing the isPrime function..."){
		cout << "Testing the isPrime function..." << endl;
		REQUIRE(isPrime(0) == false);
		REQUIRE(isPrime(1) == false);
		REQUIRE(isPrime(2) == true);
		REQUIRE(isPrime(23) == true);
		REQUIRE(isPrime(18) == false);
		REQUIRE(isPrime(673487) == true);
	}

	SECTION("Testing the extendedEuclid function..."){
		cout << "Testing the extendedEuclid function..." << endl;
		long long x;
		long long y;
		long long* px = &x;
		long long* py = &y;
		REQUIRE(extendedEuclid(5,2,px,py) == GCD(5,2));
		REQUIRE(extendedEuclid(6,2,px,py) == GCD(6,2));
		REQUIRE(extendedEuclid(40,10,px,py) == GCD(40,10));
		REQUIRE(extendedEuclid(33,4,px,py) == GCD(33,4));
	}
}