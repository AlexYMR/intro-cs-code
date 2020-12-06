#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "ReallyLongInt.h"
#include<cmath>

using namespace std;

TEST_CASE("Initiating test..."){

	SECTION("Testing the ReallyLongInt default constructor..."){
		cout << "\nTesting the default constructor...";
		ReallyLongInt myNum;
		REQUIRE(myNum.toString() == "0");
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt string constructor..."){
		cout << "\nTesting the string constructor...";
		string t1 = "001234";
		string t2 = "1234";
		string t3 = "01023";
		string t4 = "00001";
		string t5 = "-1234";
		string t6 = "-001234";
		string t7 = "-0";
		ReallyLongInt myNum1(t1);
		ReallyLongInt myNum2(t2);
		ReallyLongInt myNum3(t3);
		ReallyLongInt myNum4(t4);
		ReallyLongInt myNum5(t5);
		ReallyLongInt myNum6(t6);
		ReallyLongInt myNum7(t7);
		REQUIRE(myNum1.toString() == "1234");
		REQUIRE(myNum2.toString() == "1234");
		REQUIRE(myNum3.toString() == "1023");
		REQUIRE(myNum4.toString() == "1");
		REQUIRE(myNum5.toString() == "-1234");
		REQUIRE(myNum6.toString() == "-1234");
		REQUIRE(myNum7.toString() == "0");
		cout << "PASSED!" << endl;
	}
	SECTION("Testing the ReallyLongInt integer constructor..."){
		cout << "\nTesting the integer constructor...";
		ReallyLongInt myNum1(0123); // should return 83 (base 10)
		ReallyLongInt myNum2(-0123);
		ReallyLongInt myNum3(-123);
		ReallyLongInt myNum4(84324023);
		ReallyLongInt myNum5(0);
		string numberString1 = myNum1.toString();
		string numberString2 = myNum2.toString();
		string numberString3 = myNum3.toString();
		string numberString4 = myNum4.toString();
		string numberString5 = myNum5.toString();
		REQUIRE(numberString1 == "83");
		REQUIRE(numberString2 == "-83");
		REQUIRE(numberString3 == "-123");
		REQUIRE(numberString4 == "84324023");
		REQUIRE(numberString5 == "0");
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt copy constructor..."){
		cout << "\nTesting the copy constructor...";
		ReallyLongInt myNum_1(0123); // should return 83 (base 10)
		ReallyLongInt myNum_2(-0123);
		ReallyLongInt myNum_3(-123);
		ReallyLongInt myNum_4(84324023);
		ReallyLongInt myNum_5(0);
		//--
		ReallyLongInt myNum1(myNum_1);
		ReallyLongInt myNum2(myNum_2);
		ReallyLongInt myNum3(myNum_3);
		ReallyLongInt myNum4(myNum_4);
		ReallyLongInt myNum5(myNum_5);
		//--
		string numberString1 = myNum1.toString();
		string numberString2 = myNum2.toString();
		string numberString3 = myNum3.toString();
		string numberString4 = myNum4.toString();
		string numberString5 = myNum5.toString();
		REQUIRE(numberString1 == "83");
		REQUIRE(numberString2 == "-83");
		REQUIRE(numberString3 == "-123");
		REQUIRE(numberString4 == "84324023");
		REQUIRE(numberString5 == "0");
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt equals operator..."){
		cout << "\nTesting the equals operator...";
		ReallyLongInt myNum1(123); // should return 83 (base 10)
		ReallyLongInt myNum2(-0123);
		ReallyLongInt myNum3(-83);
		ReallyLongInt myNum4(123);
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		ReallyLongInt myNum7(1);
		ReallyLongInt myNum8(11);
		//--
		REQUIRE(myNum1.equal(myNum2) == false);
		REQUIRE(myNum2.equal(myNum3) == true);
		REQUIRE(myNum4.equal(myNum1) == true);
		REQUIRE(myNum5.equal(myNum1) == false);
		REQUIRE(myNum5.equal(myNum6) == true);
		REQUIRE(myNum7.equal(myNum8) == false);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt greater operator..."){
		cout << "\nTesting the greater operator...";
		ReallyLongInt myNum1("123"); // should return 83 (base 10)
		ReallyLongInt myNum2("-123");
		ReallyLongInt myNum3("-3");
		ReallyLongInt myNum4("5");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		ReallyLongInt myNum7("68");
		ReallyLongInt myNum8("77");
		//--
		REQUIRE(myNum1.greater(myNum2) == true);
		REQUIRE(myNum3.greater(myNum2) == true);
		REQUIRE(myNum4.greater(myNum3) == true);
		REQUIRE(myNum5.greater(myNum3) == true);
		REQUIRE(myNum5.greater(myNum6) == false);
		REQUIRE(myNum7.greater(myNum8) == false);
		cout << "PASSED!" << endl;
	}
	/*
	SECTION("Testing the ReallyLongInt add operator..."){
		cout << "\nTesting the add operator...";
		ReallyLongInt myNum1("123"); // should return 83 (base 10)
		ReallyLongInt myNum2("-123");
		ReallyLongInt myNum3("-3");
		ReallyLongInt myNum4("5");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		//--
		REQUIRE(myNum1.add(myNum2) == true);
		REQUIRE(myNum3.add(myNum2) == true);
		REQUIRE(myNum4.add(myNum3) == true);
		REQUIRE(myNum5.add(myNum3) == true);
		REQUIRE(myNum5.add(myNum6) == false);
		REQUIRE(myNum7.add(myNum8) == false);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt sub operator..."){
		cout << "\nTesting the sub operator...";
		ReallyLongInt myNum1("123"); // should return 83 (base 10)
		ReallyLongInt myNum2("-123");
		ReallyLongInt myNum3("-3");
		ReallyLongInt myNum4("5");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		//--
		REQUIRE(myNum1.sub(myNum2) == true);
		REQUIRE(myNum3.sub(myNum2) == true);
		REQUIRE(myNum4.sub(myNum3) == true);
		REQUIRE(myNum5.sub(myNum3) == true);
		REQUIRE(myNum5.sub(myNum6) == false);
		REQUIRE(myNum7.sub(myNum8) == false);
		cout << "PASSED!" << endl;
	}
	*/ //Unable to finish these two functions...

}