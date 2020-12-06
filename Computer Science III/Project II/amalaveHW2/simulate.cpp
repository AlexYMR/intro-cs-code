#include<iostream>
#include<chrono>
#include "simulate.hpp"

using namespace std;

//reports the number of real-world nanoseconds the simulation took/number of times popNext was called
//reports the average total CPU time and average total wait time of both kinds of processes after the simulation
double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles){
	//allocate processes and add them to the scheduler (numIOBound IOBound procs, and numCPUBound CPUBound procs)
	ArrayList<Process*>* collection = new ArrayList<Process*>(numCPUBound+numIOBound);

	//IOBs: even IDs
	for(int i = 0; i < numIOBound; i++){
		Process* p = new IOBoundProcess(2*i);
		sched->addProcess(p);
		collection->pushBack(p);
	}

	//CPUBs: odd IDs
	for(int i = 1; i <= numCPUBound; i++){
		Process* p = new CPUBoundProcess(2*i+1);
		sched->addProcess(p);
		collection->pushBack(p);
	}
	
	auto start = chrono::system_clock::now();
	int curCycleNumber = 1;
	while(curCycleNumber <= numCycles){
		Process* p = sched->popNext(curCycleNumber);
		if(p == 0){
			curCycleNumber += 10; //increment the "cycle number" by 10...?
		} else{
			int numCyclesUsed = p->useCPU(curCycleNumber,10);
			curCycleNumber += numCyclesUsed;
			sched->addProcess(p);
		}
	}

	//overhead caused
	auto end = chrono::system_clock::now();
	auto duration = end - start;
	auto durationNS = chrono::duration_cast<chrono::nanoseconds>(duration);
	long long elapsed = durationNS.count();
	double overhead = elapsed/(curCycleNumber);

	long long CPUBTotalTime = 0;
	long long CPUBWaitTime = 0;
	long long IOBTotalTime = 0;
	long long IOBWaitTime = 0; 
	for(int i = 0; i < numCPUBound+numIOBound; i++){
		Process* proc = collection->getItem(i);
		if(proc->getID() % 2 == 0){
			IOBTotalTime += proc->getCPUTime();
			IOBWaitTime += proc->getWaitTime(curCycleNumber);
		} else{
			CPUBTotalTime += proc->getCPUTime();
			CPUBWaitTime += proc->getWaitTime(curCycleNumber);
		}
	}
	//CPUB: average cpu time -- getCPUTime of all/number of procs
	double avgCPUBTime = (double)CPUBTotalTime/(double)numCPUBound;

	//CPUB: average wait time -- getWaitTime of all/number of procs
	double avgCPUBWaitTime = (double)CPUBWaitTime/(double)numCPUBound;

	//IOB: average cpu time
	double avgIOBTime = (double)IOBTotalTime/(double)numIOBound;

	//IOB: average wait time
	double avgIOBWaitTime = (double)IOBWaitTime/(double)numIOBound;

	//array creation
	double* info = new double[5];
	info[0] = overhead;
	info[1] = avgCPUBTime;
	info[2] = avgCPUBWaitTime;
	info[3] = avgIOBTime;
	info[4] = avgIOBWaitTime;
	//for(int i = 0; i < 5; i++){
		//cout << i << ": " << info[i] << endl;
	//}

	//clean-up
	/*long long totalBound = numCPUBound+numIOBound;
	while(totalBound > 0){
		Process* p = collection->getFront();
		delete p;
		collection->popFront();
		totalBound--;
	}*/ //this wouldn't make much of a difference
	//I can't make it a linkedList because I want fast random access for part above
	for(int i = 0; i < (numCPUBound+numIOBound);i++){
		delete collection->getItem(i);
	}
	delete collection;

	return info;
}