#include "Scheduler.hpp"
#include<iostream>

using namespace std;

RoundRobin::RoundRobin(){
	ArrayList<Process*>* array = new ArrayList<Process*>;
	procQueue = array;
}

RoundRobin::~RoundRobin(){
	delete procQueue; //calls ArrayList's destructor...
}

void RoundRobin::addProcess(Process* proc){
	//cout << "Process ID: " << proc->getID() << endl;
	procQueue->pushBack(proc);
}

//supposed to move all blocked procs to the back of the queue each time??
Process* RoundRobin::popNext(int curCycle){
	for(int i = 0; i < procQueue->getSize(); i++){
		if(!procQueue->getItem(i)->isBlocked(curCycle)){
			Process* p = procQueue->getItem(i);
			procQueue->remove(i);
			return p;
		} else{
			Process* p = procQueue->getItem(i);
			procQueue->remove(i);
			procQueue->pushBack(p);
		}
	}
	return 0;
}

FastRoundRobin::FastRoundRobin(){
	delete procQueue;
	LinkedList<Process*>* array = new LinkedList<Process*>;
	procQueue = array;
}