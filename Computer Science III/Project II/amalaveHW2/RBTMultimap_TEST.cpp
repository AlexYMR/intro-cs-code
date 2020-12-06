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

		tree->insert(0,4);
		tree->insert(1,2);
		tree->insert(2,3);
		tree->insert(3,6);
		tree->insert(4,1);
		tree->insert(5,3);
		tree->insert(6,3);
		tree->insert(7,4);
		cout << tree->toString();
		cout << "=======================" << endl;

		REQUIRE(tree->getSize() == 8);
		REQUIRE(tree->isEmpty() == false);

		REQUIRE(tree->contains(6) == true);
		REQUIRE(tree->contains(123) == false);

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

		//Removal tests...
		BSTForwardIterator<int,int> f = tree->findFirst(6);
		BSTForwardIterator<int,int> ret = tree->remove(f);
		REQUIRE(ret.getKey() == 7);

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

		cout << "========================" << endl;
		tree->clear();
		for(int i = 0; i < 5; i++){
			tree->insert(i*2,1);
		}
		tree->insert(30,1);//
		tree->insert(25,1);//
		tree->insert(15,1);
		tree->insert(11,1);//
		tree->insert(14,1);
		tree->insert(17,1);//
		tree->insert(23,1);
		tree->insert(50,1);
		tree->insert(43,1);
		tree->insert(42,1);
		tree->insert(32,1);//
		tree->insert(37,1);//
		tree->insert(45,1);//

		f = tree->findFirst(2);
		tree->remove(f);
		f = tree->findFirst(17);
		tree->remove(f);
		f = tree->findFirst(11);
		tree->remove(f);
		f = tree->findFirst(32);
		tree->remove(f);
		f = tree->findFirst(37);
		tree->remove(f);
		f = tree->findFirst(45);
		tree->remove(f);
		f = tree->findFirst(25);
		tree->remove(f);
		f = tree->findFirst(30);
		tree->remove(f);

		tree->insert(16,1);
		tree->insert(25,1);
		tree->insert(18,1);
		tree->insert(26,1);
		tree->insert(39,1);
		tree->insert(13,1);
		tree->insert(49,1);
		tree->insert(40,1);

		tree->printDOT("rbTree1");

		f = tree->findFirst(23);
		tree->remove(f);
		f = tree->findFirst(26);
		tree->remove(f);
		f = tree->findFirst(6);
		tree->remove(f);
		f = tree->findFirst(8);
		tree->remove(f);
		tree->printDOT("rbTree2");
		cout << tree->toString();
		cout << "========================" << endl;
		
		delete tree;

		cout << "PASSED!" << endl;
	}

}