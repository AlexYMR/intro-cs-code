#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BinaryHeap.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the BinaryHeap class"){
		cout << "\nTesting the BinaryHeap class...";
		double priorities[] = {2.9,2.2,3,3.3};
		int numItems = 4;

		BinaryHeap heap(priorities,numItems);
		REQUIRE(heap.getPriority(heap.getMin()) == 2.2);
		REQUIRE(heap.contains(2) == true);
		REQUIRE(heap.getSize() == 4);

		heap.decreasePriority(3,1.5);

		REQUIRE(heap.getMin() == 3);
		REQUIRE(heap.getPriority(heap.getMin()) == 1.5);
		
		heap.popMin();
		
		REQUIRE(heap.getSize() == 3);
		REQUIRE(heap.getPriority(heap.getMin()) == 2.2);

		cout << "\nPASSED!" << endl;
	}
}