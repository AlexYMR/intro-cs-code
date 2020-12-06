#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "reallyLongInt.h"

using namespace std;

TEST_CASE("Initiating test..."){
	cout << "\nInitiating test..." << endl;
	SECTION("Testing the rlIntMake function..."){
		cout << "Testing the rlIntMake function...";
		string t1 = "1";
		string t2 = "11";
		string t3 = "77";
		string t4 = "68";
		unsigned num1 = t1.size();
		unsigned num2 = t2.size();
		unsigned num3 = t3.size();
		unsigned num4 = t4.size();
		unsigned int* myNum1 = rlIntMake(t1,num1);
		unsigned int* myNum2 = rlIntMake(t2,num2);
		unsigned int* myNum3 = rlIntMake(t3,num3);
		unsigned int* myNum4 = rlIntMake(t4,num4);
		cout << " GOOD!" << endl;
		cout << "\nTesting the rlIntToString function..." << endl;
		string numberString1 = rlIntToString(myNum1,num1);
		string numberString2 = rlIntToString(myNum2,num2);
		string numberString3 = rlIntToString(myNum3,num3);
		string numberString4 = rlIntToString(myNum4,num4);
		cout << "Test 1: " << numberString1 << ", Size: " << num1 << endl;
		cout << "Test 2: " << numberString2 << ", Size: " << num2 << endl;
		cout << "Test 3: " << numberString3 << ", Size: " << num3 << endl;
		cout << "Test 4: " << numberString4 << ", Size: " << num4 << endl;
		cout << "---------------" << endl;
		cout << "\nTesting the rlIntEqual function..." << endl;
		cout << "Test 5: " << numberString1 << " = " << numberString2 << ": " << ((rlIntEqual(myNum1,num1,myNum2,num2) == 1) ? "TRUE":"FALSE") << endl;
		cout << "Test 6: " << numberString2 << " = " << numberString3 << ": " << ((rlIntEqual(myNum2,num2,myNum3,num3) == 1) ? "TRUE":"FALSE") << endl;	
		cout << "\nTesting the rlIntGreater function..." << endl;
		cout << "Test 7: " << numberString1 << " > " << numberString2 << ": " << ((rlIntGreater(myNum1,num1,myNum2,num2) == 1) ? "TRUE":"FALSE") << endl;
		cout << "Test 8: " << numberString2 << " > " << numberString3 << ": " << ((rlIntGreater(myNum2,num2,myNum3,num3) == 1) ? "TRUE":"FALSE") << endl;
		cout << "Test 9: " << numberString4 << " > " << numberString3 << ": " << ((rlIntGreater(myNum4,num4,myNum3,num3) == 1) ? "TRUE":"FALSE") << endl;	
		delete[] myNum1;
		delete[] myNum2;
		delete[] myNum3;
		delete[] myNum4;
	}
}