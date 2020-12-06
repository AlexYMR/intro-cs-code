#define CATCH_CONFIG_MAIN
#include "Scheduler.hpp"
#include "catch.hpp"
#include<iostream>

using namespace std;

TEST_CASE("Initiating test..."){
	SECTION("Testing the RoundRobin class functions"){
		cout << "\nTesting RoundRobin class functions...";

		RoundRobin* ioProcQueue = new RoundRobin;
		//make an ioboundproc queue = {1,2,3}, where 1 and 3 are unblocked
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
			ioProcQueue->addProcess(proc);
		}

		for(int i = 0; i < 3; i++){
			if(i == 0){
				Process* p = ioProcQueue->popNext(curCycle1);
				REQUIRE(p->getID() == 1);
				delete p;
			} else if(i == 1){
				Process* p = ioProcQueue->popNext(curCycle2);
				REQUIRE(p->getID() == 3);
				delete p;
			} else if(i == 2){
				Process* p = ioProcQueue->popNext(curCycle3);
				REQUIRE(p == 0);
			}
		}

		delete ioProcQueue;
		RoundRobin* cpuProcQueue = new RoundRobin;

		int curCycle = 1;
		for(int i = 0; i < 3; i++){
			CPUBoundProcess* p = new CPUBoundProcess(i+1);
			Process* proc = p;
			p->useCPU(curCycle,sliceSize);
			cpuProcQueue->addProcess(proc);
		}

		Process* p = cpuProcQueue->popNext(curCycle);
		REQUIRE(p->getID() == 1);
		delete p;
		p = cpuProcQueue->popNext(curCycle);
		REQUIRE(p->getID() == 2);
		delete p;
		delete cpuProcQueue;

		cout << "PASSED!" << endl;
	}

	SECTION("Testing the FastRoundRobin class functions"){
		cout << "\nTesting FastRoundRobin class functions...";

		FastRoundRobin* ioProcQueue = new FastRoundRobin;
		//make an ioboundproc queue = {1,2,3}, where 1 and 3 are unblocked
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
			ioProcQueue->addProcess(proc);
		}

		for(int i = 0; i < 3; i++){
			if(i == 0){
				Process* p = ioProcQueue->popNext(curCycle1);
				REQUIRE(p->getID() == 1);
				delete p;
			} else if(i == 1){
				Process* p = ioProcQueue->popNext(curCycle2);
				REQUIRE(p->getID() == 3);
				delete p;
			} else if(i == 2){
				Process* p = ioProcQueue->popNext(curCycle3);
				REQUIRE(p == 0);
			}
		}

		delete ioProcQueue;
		FastRoundRobin* cpuProcQueue = new FastRoundRobin;

		int curCycle = 1;
		for(int i = 0; i < 3; i++){
			CPUBoundProcess* p = new CPUBoundProcess(i+1);
			Process* proc = p;
			p->useCPU(curCycle,sliceSize);
			cpuProcQueue->addProcess(proc);
		}

		Process* p = cpuProcQueue->popNext(curCycle);
		REQUIRE(p->getID() == 1);
		delete p;
		p = cpuProcQueue->popNext(curCycle);
		REQUIRE(p->getID() == 2);
		delete p;
		delete cpuProcQueue;

		cout << "PASSED!" << endl;
	}
}
