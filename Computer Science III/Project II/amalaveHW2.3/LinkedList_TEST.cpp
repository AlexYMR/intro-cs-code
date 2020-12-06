#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.hpp"
#include<iostream>

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the LinkedList class functions"){
		cout << "\nTesting LinkedList class functions...";
		LinkedList<int> list;
		int size = 4;

		for(int i = 0; i < size; i++){
			list.pushBack(i+1);
		}
		
		int array[] = {0,1,2,3,4};

		REQUIRE(list.getSize() == size);
		REQUIRE(list.isEmpty() == false);

		REQUIRE(list.getFront() == 1);
		REQUIRE(list.getBack() == 4);
		list.popBack();
		REQUIRE(list.getBack() == 3);
		list.popFront();
		REQUIRE(list.getFront() == 2);

		list.pushFront(1);
		list.pushBack(4);

		REQUIRE(list.getItem(1) == 2);
		list.setItem(1,3);
		REQUIRE(list.getItem(1) == 3);
		list.setItem(1,2);

		list.remove(2);
		REQUIRE(list.getItem(size-2) == 4);

		list.insert(2,3);
		REQUIRE(list.getItem(size-2) == 3);
		REQUIRE(list.getItem(size-1) == 4);

		cout << "PASSED!" << endl;
	}
}