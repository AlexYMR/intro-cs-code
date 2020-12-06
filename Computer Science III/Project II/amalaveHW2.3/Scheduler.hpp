#ifndef SCHEDULER
#define SCHEDULER

#include "LinkedList.hpp"
#include "ArrayList.hpp"
#include "Process.hpp"
#include "RBTMultimap.hpp"

class Scheduler{
	public:
		//Adds given proc to procs to be scheduled
		virtual void addProcess(Process* proc) = 0;

		//removes and returns the next proc in the queue
		//returns 0 if there is no proc
		virtual Process* popNext(int curCycle) = 0;

		virtual ~Scheduler(){}
};

class RoundRobin : public Scheduler{
	protected:
		List<Process*>* procQueue; //procQueue will be an ArrayList

	public:
		//init procQueue as empty ArrayList
		RoundRobin();

		//deletes procQueue (not its contents)
		virtual ~RoundRobin();

		//adds given proc to back of procQueue
		virtual void addProcess(Process* proc);

		//returns first unblocked proc in queue, moving any blocked
		//procs to the back of queue
		//returns 0 if all procs are blocked
		virtual Process* popNext(int curCycle);
};

class FastRoundRobin: public RoundRobin{
	public:
		FastRoundRobin();
};

class CompletelyFair: public Scheduler{
	protected:
		BSTMultimap<int,Process*>* procTree;

	public:
		//inits procTree as empty BSTMultimap
		CompletelyFair();

		//deletes procTree (not its contents)
		virtual ~CompletelyFair();

		//adds given proc to tree with the proc's current CPU time as its key
		virtual void addProcess(Process* proc);

		//First obtain an iterator pointing to the proc with the minimum CPU time
		//Use the iterator to go through the tree until you find proc that is not blocked
		//Remove and return that proc
		virtual Process* popNext(int curCycle);
};

class FastCompletelyFair: public CompletelyFair{
	public:
		FastCompletelyFair();
};

#endif