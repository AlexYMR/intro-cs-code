#ifndef SCHEDULER
#define SCHEDULER

//these both include List.hpp... is that a problem?
#include "LinkedList.hpp"
#include "ArrayList.hpp"
#include "Process.hpp"

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

#endif