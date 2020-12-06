#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"
#include "BSTNode.hpp"
#include "BSTMultimap.hpp"
#include "Scheduler.hpp"
#include<string>

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the CompletelyFair class functions"){
		cout << "\nTesting CompletelyFair class functions...";

		CompletelyFair ioProcTree;
		//make an ioboundproc tree = {1,2,3}, where 1 and 3 are unblocked
		//and 2 is blocked
		int sliceSize = 1;
		int curCycle1 = 1;
		int curCycle2 = 1;
		int curCycle3 = 1;
		for(int i = 0; i < 3; i++){
			IOBoundProcess* p = new IOBoundProcess(i+1);
			Process* proc = p;
			if(i == 0){
				while(p->isBlocked(curCycle1)){
					p->useCPU(curCycle1,sliceSize);
					curCycle1++;
				}
			} else if(i == 1){
				while(!p->isBlocked(curCycle2)){
					p->useCPU(curCycle2,sliceSize);
					curCycle2++;
				}
			} else{
				while(p->isBlocked(curCycle3)){
					p->useCPU(curCycle3,sliceSize);
					curCycle3++;
				}
			}
			ioProcTree.addProcess(proc);
		}

		int p1Time = 0;
		int p2Time = 0;
		for(int i = 0; i < 3; i++){
			if(i == 0){
				Process* p = ioProcTree.popNext(curCycle1);
				p1Time = p->getCPUTime();
			} else if(i == 1){
				Process* p = ioProcTree.popNext(curCycle2);
				p2Time = p->getCPUTime();
			} else if(i == 2){
				Process* p = ioProcTree.popNext(curCycle3);
				REQUIRE(p == 0);
			}
		}
		REQUIRE(p1Time <= p2Time);

		CompletelyFair cpuProcTree;

		int curCycle = 1;
		for(int i = 0; i < 3; i++){
			CPUBoundProcess* p = new CPUBoundProcess(i+1);
			Process* proc = p;
			p->useCPU(curCycle,sliceSize);
			cpuProcTree.addProcess(proc);
		}

		Process* p = cpuProcTree.popNext(curCycle);
		REQUIRE(p->getID() == 1);
		p = cpuProcTree.popNext(curCycle);
		REQUIRE(p->getID() == 2);

		cout << "PASSED!" << endl;
	}
}