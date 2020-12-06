#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "RBTNode.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the RBTNode class functions"){
		cout << "\nTesting RBTNode class functions...";
		
		RBTNode<int,int>* node = new RBTNode<int,int>(3,2,false);
		RBTNode<int,int>* rightNode = new RBTNode<int,int>(3,3,true);
		RBTNode<int,int>* leftNode = new RBTNode<int,int>(3,1,true);

		node->setRightChild(rightNode);
		node->setLeftChild(leftNode);

		REQUIRE(node->getValue() == 2);
		REQUIRE(node->getRightChild() == rightNode);
		REQUIRE(node->getLeftChild() == leftNode);

		rightNode->setParent(node);
		leftNode->setParent(node);
		REQUIRE(rightNode->getParent() == node);
		REQUIRE(leftNode->getParent() == node);

		node->setIsRed(true);
		REQUIRE(node->isRed() == true);
		node->setIsRed(false);

		delete node;
		delete rightNode;
		delete leftNode;

		cout << "PASSED!" << endl;
	}

}