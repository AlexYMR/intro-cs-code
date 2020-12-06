#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "ReallyLongInt.hpp"
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
	
	SECTION("Testing the ReallyLongInt addition operator..."){
		cout << "\nTesting the addition operator...";
		ReallyLongInt myNum1("123");
		ReallyLongInt myNum2("1234");
		ReallyLongInt myNum3("999");
		ReallyLongInt myNum4("11");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		//--
		ReallyLongInt n1("1357");
		ReallyLongInt n2("2233");
		ReallyLongInt n3("2233");
		ReallyLongInt n4("0");
		ReallyLongInt n5("11");
		ReallyLongInt n6("1010");
		//--
		REQUIRE((myNum1.add(myNum2)).equal(n1) == true);
		REQUIRE((myNum2.add(myNum3)).equal(n2) == true);
		REQUIRE((myNum3.add(myNum2)).equal(n3) == true);
		REQUIRE((myNum5.add(myNum6)).equal(n4) == true);
		REQUIRE((myNum4.add(myNum5)).equal(n5) == true);
		REQUIRE((myNum3.add(myNum4)).equal(n6) == true);

		// Signed extension
		ReallyLongInt num1("5");
		ReallyLongInt num2("-10");
		//
		ReallyLongInt n7("-5");
		ReallyLongInt n8("-5");
		ReallyLongInt n9("-20");
		REQUIRE((num1+num2).equal(n7) == true);
		REQUIRE((num2+num1).equal(n8) == true);
		REQUIRE((num2+num2).equal(n9) == true);
		//
		ReallyLongInt x("1230367696");
		ReallyLongInt y("1600000000");
		REQUIRE((x+y) == 2830367696);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt subtraction operator..."){
		cout << "\nTesting the subtraction operator...";
		ReallyLongInt myNum1("123");
		ReallyLongInt myNum2("1234");
		ReallyLongInt myNum3("99");
		ReallyLongInt myNum4("11");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		ReallyLongInt myNum7("9000");
		ReallyLongInt myNum8("8999");
		ReallyLongInt myNum9("1");
		//--
		ReallyLongInt n("-1111");
		ReallyLongInt n2("1135");
		ReallyLongInt n3("-1135");
		ReallyLongInt n4("0");
		ReallyLongInt n5("11");
		ReallyLongInt n6("88");
		ReallyLongInt n7("1");
		ReallyLongInt n8("8999");
		//--
		REQUIRE((myNum1.sub(myNum2)).equal(n) == true);
		REQUIRE((myNum2.sub(myNum3)).equal(n2) == true);
		REQUIRE((myNum3.sub(myNum2)).equal(n3) == true);
		REQUIRE((myNum5.sub(myNum6)).equal(n4) == true);
		REQUIRE((myNum4.sub(myNum5)).equal(n5) == true);
		REQUIRE((myNum3.sub(myNum4)).equal(n6) == true);
		REQUIRE((myNum7.sub(myNum8)).equal(n7) == true);
		REQUIRE((myNum7.sub(myNum9)).equal(n8) == true);

		// Signed extension
		ReallyLongInt num1("5");
		ReallyLongInt num2("-10");
		//
		ReallyLongInt n9("15");
		ReallyLongInt n10("-15");
		ReallyLongInt n11("0");
		REQUIRE((num1-num2).equal(n9) == true);
		REQUIRE((num2-num1).equal(n10) == true);
		REQUIRE((num2-num2).equal(n11) == true);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt incremental operators..."){
		cout << "\nTesting the incremental operators...";
		ReallyLongInt n1("5");
		ReallyLongInt n2("10");
		//--
		ReallyLongInt ans1("10");
		ReallyLongInt ans2("5");
		ReallyLongInt ans3("15");
		ReallyLongInt ans4("5");
		ReallyLongInt ans5("6");
		ReallyLongInt ans6("6");
		ReallyLongInt ans7("5");
		ReallyLongInt ans8("5");
		ReallyLongInt ans9("6");
		ReallyLongInt ans10("5");
		ReallyLongInt ans11("5");
		ReallyLongInt ans12("6");
		ReallyLongInt ans13("50");
		ReallyLongInt ans14("50");
		//--
		REQUIRE((n1+n1) == ans1);
		REQUIRE((n2-n1) == ans2);
		n1 += n2;
		REQUIRE(n1 == ans3);
		ReallyLongInt x(10);
		n1 -= x;
		REQUIRE(n1 == ans4);
		ReallyLongInt y = ++n1;
		REQUIRE(n1 == ans5);
		REQUIRE(y == ans6);
		ReallyLongInt z = --n1;
		REQUIRE(n1 == ans7);
		REQUIRE(z == ans8);
		ReallyLongInt c = n1++;
		REQUIRE(n1 == ans9);
		REQUIRE(c == ans10);
		ReallyLongInt v = n1--;
		REQUIRE(n1 == ans11);
		REQUIRE(v == ans12);
		ReallyLongInt b = n1*n2;
		REQUIRE(b == ans13);
		n1 *= n2;
		REQUIRE(n1 == ans14);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt multiplication operator..."){
		cout << "\nTesting the multiplication operator...";
		ReallyLongInt myNum1("56");
		ReallyLongInt myNum2("34");
		ReallyLongInt myNum3("900");
		ReallyLongInt myNum4("3");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6;
		ReallyLongInt myNum7("4");
		//--
		ReallyLongInt n1("1904");
		ReallyLongInt n2("2700");
		ReallyLongInt n3("0");
		ReallyLongInt n4("0");
		ReallyLongInt n5("12");
		ReallyLongInt n6("136");
		//--
		REQUIRE((myNum1*myNum2) == n1);
		REQUIRE((myNum3*myNum4) == n2);
		REQUIRE((myNum5*myNum6) == n3);
		REQUIRE((myNum5*myNum3) == n4);
		REQUIRE((myNum4*myNum7) == n5);
		REQUIRE((myNum7*myNum2) == n6);

		// Signed extension
		ReallyLongInt num1("5");
		ReallyLongInt num2("-10");
		//
		ReallyLongInt n7("-50");
		ReallyLongInt n8("-50");
		ReallyLongInt n9("100");
		REQUIRE((num1*num2) == n7);
		REQUIRE((num2*num1) == n8);
		REQUIRE((num2*num2) == n9);
		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ReallyLongInt division operator..."){ //Just realized the program can convert ints -> ReallyLongInts implicitly... Oh well.
		cout << "\nTesting the division operator...";
		ReallyLongInt myNum1("51");
		ReallyLongInt myNum2("5");
		ReallyLongInt myNum3("100");
		ReallyLongInt myNum4("10");
		ReallyLongInt myNum5;
		ReallyLongInt myNum6("4");
		//--
		REQUIRE((myNum1/myNum2) == 10);
		REQUIRE((myNum1%myNum2) == 1);
		REQUIRE((myNum3/myNum4) == 10);
		REQUIRE((myNum3%myNum4) == 0);
		REQUIRE((myNum5/myNum3) == 0);
		REQUIRE((myNum4/myNum6) == 2);
		REQUIRE((myNum4%myNum6) == 2);
		
		// Signed extension
		ReallyLongInt num1("5");
		ReallyLongInt num2("-10");
		//
		REQUIRE((num1/num2) == 0);
		REQUIRE((num1%num2) == 5);
		REQUIRE((num2/num1) == -2);
		REQUIRE((num2%num1) == 0);
		REQUIRE((num2/num2) == 1);
		REQUIRE((num2%num2) == 0);
		//
		num1 /= 5;
		REQUIRE(num1 == 1);
		num1 += 4;
		num1 %= 5;
		REQUIRE(num1 == 0);
		cout << "PASSED!" << endl;
	}

	/*SECTION("Testing the ReallyLongInt to long long converter..."){
		cout << "\nTesting the long long converter...";
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
	}*/

	/*SECTION("Testing the ReallyLongInt output stream overloader..."){
		cout << "\nTesting the output stream overloader...";
		ReallyLongInt myNum1("123");
		ReallyLongInt myNum2("1234");
		ReallyLongInt myNum3("999");
		ReallyLongInt myNum4("-11");
		//--
		cout << "Num1: " << myNum1;
		cout << "Num2: " << myNum2;
		cout << "Num3: " << myNum3;
		cout << "Num4: " << myNum4;
		cout << "\nPASSED!" << endl;
	}*/

	/*SECTION("Testing the ReallyLongInt assignment overload..."){
		cout << "\nTesting the assignment overload...";
		ReallyLongInt x(10);
		ReallyLongInt y;
		y = x;
		cout << "\n" << y << endl;
		y = -58;
		cout << y << endl;
		ReallyLongInt z("10");
		cout << z << endl;
		y = string("123456789");
		cout << y << endl; 
		cout << "\nPASSED!" << endl;
	}*/

	/*SECTION("Testing the ReallyLongInt flipSign operator..."){
		cout << "\nTesting the flipSign operator...";
		ReallyLongInt myNum1("123");
		ReallyLongInt myNum2("0234");
		ReallyLongInt myNum3("0");
		ReallyLongInt myNum4("-11");
		//
		ReallyLongInt n1("-123");
		ReallyLongInt n2("-0234");
		ReallyLongInt n3("0");
		ReallyLongInt n4("11");
		//
		REQUIRE(-myNum1 == n1);
		REQUIRE(-myNum2 == n2);
		REQUIRE(-myNum3 == n3);
		REQUIRE(-myNum4 == n4);
		cout << "PASSED!" << endl;
	}*/



}