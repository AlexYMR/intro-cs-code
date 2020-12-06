#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "BSTNode.hpp"

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the BSTNode class functions"){
		cout << "\nTesting BSTNode class functions...";
		
		BSTNode<int,int>* node = new BSTNode<int,int>(3,2);
		BSTNode<int,int>* rightNode = new BSTNode<int,int>(3,3);
		BSTNode<int,int>* leftNode = new BSTNode<int,int>(3,1);

		node->setRightChild(rightNode);
		node->setLeftChild(leftNode);

		REQUIRE(node->getValue() == 2);
		REQUIRE(node->getKey() == 3);
		REQUIRE(node->getRightChild() == rightNode);
		REQUIRE(node->getLeftChild() == leftNode);

		rightNode->setParent(node);
		leftNode->setParent(node);
		REQUIRE(rightNode->getParent() == node);
		REQUIRE(leftNode->getParent() == node);

		rightNode->setKey(4);
		rightNode->setValue(5);
		REQUIRE(rightNode->getKey() == 4);
		REQUIRE(rightNode->getValue() == 5);

		delete node;
		delete rightNode;
		delete leftNode;

		cout << "PASSED!" << endl;
	}

}