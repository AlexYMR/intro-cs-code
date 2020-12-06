#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

/*
Takes: int id
Effect: Sets member variable values
Returns: nothing
*/
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

/*
Takes: nothing
Effect: nothing
Returns: ID of the Process
*/
int Process::getID() const
{
   return id;
}

/*
Takes: nothing
Effect: nothing
Returns: total time run on CPU
*/
int Process::getCPUTime() const
{
   return cpuTime;
}

/*
Takes: int curCycleNum
Effect: calculates total cycles for which the process has been waiting for the CPU
Returns: number of CPU cycles for which the process has been waiting for the CPU
*/
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

/*
Takes: int id
Effect: CPUBoundProcess constructor, sets last CPU wait time to 0
Returns: nothing
*/
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

/*
Takes: int curCycleNum
Effect: nothing (CPUBoundProcess will never be blocked by I/O), necessary definition to become concrete class
Returns: false
*/
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

/*
Takes: int curCycleNum, int sliceSize
Effect: simulates running an expensive process, where the whole window of time given to it is used up
Returns: number of cycles used up by the Process
*/
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

/*
Takes: int id
Effect: Uses the Process constructor with an input of id, and sets member variable values
Returns: nothing
*/
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

/*
Takes: int curCycleNum
Effect: Reflects whether enough cycles have passed for the CPU to return to the process
Returns: true or false
*/
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

/*
Takes: int curCycleNum, int sliceSize
Effect: simulates running an I/O process, blocking it for a certain time to allow for input, and unblocking it for a burst of time
Returns: number of cycles used while running the Process 
*/
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;
      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
   	 remainingBurst -= sliceSize;
   	 timeUsed = sliceSize;
   	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
   	 timeUsed = remainingBurst;
   	 remainingBurst = 0;
   	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
   	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
