#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "RBTMultimap.hpp"
#include<string>

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the RBTMultimap class functions"){
		cout << "\nTesting RBTMultimap class functions...\n";
		
		RBTMultimap<int,int>* tree = new RBTMultimap<int,int>();

		tree->insert(6,4);
		tree->insert(7,2);
		tree->insert(8,3);
		tree->insert(10,6);
		tree->insert(1,1);
		tree->insert(2,3);
		tree->insert(3,3);
		cout << tree->toString();
		cout << "=======================" << endl;

		REQUIRE(tree->getSize() == 7);
		REQUIRE(tree->isEmpty() == false);

		REQUIRE(tree->contains(10) == true);
		REQUIRE(tree->contains(123) == false);

		//Iterator testing...

		/*BSTForwardIterator<int,int> iter = tree->getMin();
		while(!iter.isPastEnd()){
			cout << "Current iterator node - K: " << iter.getKey() << ", V: " << iter.getValue() << endl;
			iter.next();
		}*/

		tree->clear();
		REQUIRE(tree->isEmpty() == true);
		REQUIRE(tree->getSize() == 0);

		tree->insert(2,1);
		tree->insert(3,1);
		tree->insert(5,1);
		tree->insert(5,2);
		tree->insert(5,3);
		tree->insert(7,1);

		cout << tree->toString();
		cout << "=======================" << endl;

		//BSTForwardIterator<int,int> first = tree->findFirst(5);
		//BSTForwardIterator<int,int> last = tree->findLast(5);

		//REQUIRE(first.getValue() == 1);
		//REQUIRE(last.getValue() == 3);

		tree->clear();
		tree->insert(5,1);
		tree->insert(2,1);
		tree->insert(1,1);
		tree->insert(4,2);
		tree->insert(6,3);
		tree->insert(8,1);
		tree->insert(7,3);
		tree->insert(9,1);
		cout << tree->toString();
		cout << "======================" << endl;

		/*cout << "Iteration beginning at the minimum value:" << endl;
		BSTForwardIterator<int,int> iterMin = tree->getMin();
		while(!iterMin.isPastEnd()){
			cout << "Current iterator node - K: " << iterMin.getKey() << ", V: " << iterMin.getValue() << endl;
			iterMin.next();
		}

		cout << "Iteration beginning at the maximum value:" << endl;
		BSTForwardIterator<int,int> iterMax = tree->getMax();
		while(!iterMax.isPastEnd()){
			cout << "Current iterator node - K: " << iterMax.getKey() << ", V: " << iterMax.getValue() << endl;
			iterMax.next();
		}*/

		//Removal tests... 8 cases to test
		BSTForwardIterator<int,int> f = tree->findFirst(6);
		tree->remove(f);

		REQUIRE(tree->contains(6) == false);

		cout << "Tree after removal of key 6:" << endl;
		cout << tree->toString();

		BSTForwardIterator<int,int> f2 = tree->findFirst(5);
		tree->remove(f2);

		REQUIRE(tree->contains(5) == false);

		cout << "Tree after removal of key 5:" << endl;
		cout << tree->toString();

		tree->clear();
		tree->insert(8,0);
		tree->insert(10,0);
		tree->insert(6,0);
		tree->insert(1,0);

		cout << "========================" << endl;
		BSTForwardIterator<int,int> f3 = tree->findFirst(1);
		tree->remove(f3);
		cout << tree->toString();

		cout << "========================" << endl;
		BSTForwardIterator<int,int> f4 = tree->findFirst(6);
		tree->remove(f4);
		cout << tree->toString();

		delete tree;

		cout << "PASSED!" << endl;
	}

}