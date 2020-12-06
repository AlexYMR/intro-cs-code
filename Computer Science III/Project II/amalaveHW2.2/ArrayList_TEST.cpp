#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "ArrayList.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the ArrayList class functions"){
		cout << "\nTesting ArrayList class functions...";
		ArrayList<int> arr;
		int size = 15;
		
		for(int i = 0; i < size; i++){
			arr.pushBack(i+1);
		}
		
		int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

		REQUIRE(arr.getSize() == size);

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		arr.pushFront(0);

		for(int i = 0; i < size+1; i++){
			REQUIRE(arr.getItem(i) == array[i]);
		}

		arr.popFront();

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		arr.remove(5);

		int array2[] = {1,2,3,4,5,7,8,9,10,11,12,13,14,15};

		REQUIRE(arr.getSize() == size-1);

		for(int i = 0; i < size-1; i++){
			REQUIRE(arr.getItem(i) == array2[i]);
		}

		arr.insert(5,6);

		REQUIRE(arr.getSize() == size);

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		cout << "PASSED!" << endl;
	}

	SECTION("Testing the ArrayList class functions with capacity 1..."){
		cout << "\nTesting ArrayList class functions with capacity 1...";
		ArrayList<int> arr(1);
		int size = 1;

		arr.pushFront(1);
		
		int array[] = {0,1};

		REQUIRE(arr.getSize() == size);

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		arr.pushFront(0);

		for(int i = 0; i < size+1; i++){
			REQUIRE(arr.getItem(i) == array[i]);
		}

		arr.popFront();

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		arr.remove(0);

		REQUIRE(arr.getSize() == size-1);

		arr.insert(0,1);

		REQUIRE(arr.getSize() == size);

		for(int i = 0; i < size; i++){
			REQUIRE(arr.getItem(i) == array[i+1]);
		}

		cout << "PASSED!" << endl;
	}
}