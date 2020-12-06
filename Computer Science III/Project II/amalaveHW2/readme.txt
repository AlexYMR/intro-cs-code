Alex Malavé
--

CPS 222 Project 2

===================
// FILES
--

ArrayList.hpp/tpp
LinkedListNode.hpp/tpp
List.hpp
LinkedList.hpp/tpp
BSTNode.hpp/tpp
BSTMultimap.hpp/tpp
BSTForwardIterator.hpp/tpp
RBTNode.hpp/tpp
RBTMultimap.hpp/tpp
Process.hpp/cpp
Scheduler.hpp/cpp
simulate.hpp/cpp
schedulesim.cpp
ArrayList_TEST.cpp
LinkedList_TEST.cpp
BSTNode_TEST.cpp
BSTMultimap_TEST.cpp
RBTNode_TEST.cpp
RBTMultimap_TEST.cpp
RoundRobin_TEST.cpp
CompletelyFair_TEST.cpp
catch.hpp
Makefile
timing.pdf
cputimes.pdf
CoverSheet.pdf
readme.txt

--

Use "make all" in order to compile the entire project, which contains several files. It will compile the program below, creating an executable, which can be used as described below.

====================

schedulesim.cpp:
	Compilation: make schedulesim
	Usage: ./schedulesim <CPUBound_Processes> <IOBound_Processes> <CPUCycles>
	Description: Simulates process scheduling on a CPU. This simulation lasts for a certain number of CPUCycles, which is one of the parameters given to program. It repeatedly asks a given scheduler for a process, then allows that process access to the simulated CPU for a slice (a certain number of CPUCycles). Statistics are kept in order to evaluate the efficacy of different schedulers. Different data structures are used to implement different schedulers, for a total of four: an ArrayList (RoundRobin), a LinkedList (FastRoundRobin), a Binary Search Tree (CompletelyFair), and a Red-Black Tree (FastCompletelyFair). A string collects the results of the simulation, which is then neatly printed. The data collected contains information regarding the overhead caused by the data structure on the procedure, the average CPU time of CPU-bound processes, the average wait time of CPU-bound processes, the average CPU time of IO-bound processes, and the average wait time of IO-bound processes. The simulation runs on all four schedulers, and data is collected for each one in order to make for straightforward comparisons in efficiency between the schedulers.


====================
// KNOWN ISSUES
--

- For extremely large input parameters, schedulesim will run into integer overflow issues

- In BSTMultimap, using any of the get functions on a node that points to the sentinel will crash the program

- Cannot handle typos/missing argument exceptions when incorrect parameters are given

====================