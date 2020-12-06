OPTS = -Wall -std=c++11

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp
	g++ ${OPTS} -o BSTNodeTest BSTNode_TEST.cpp

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp
	g++ ${OPTS} -o BSTMultimapTest BSTMultimap_TEST.cpp

CompletelyFair_TEST: CompletelyFair_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} -o CompletelyFairTest CompletelyFair_TEST.cpp Process.cpp Scheduler.cpp

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -o ArrayListTest ArrayList_TEST.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.tpp LinkedListNode.hpp
	g++ ${OPTS} -o RoundRobinTest RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

RoundRobin_DEBUG: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -g -o RoundRobinDebug RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} -o LinkedListTest LinkedList_TEST.cpp

ScheduleSim: schedulesim.cpp simulate.cpp simulate.hpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp
	g++ ${OPTS} -o ScheduleSim schedulesim.cpp simulate.cpp Scheduler.cpp Process.cpp

ScheduleSim_DEBUG: schedulesim.cpp simulate.cpp simulate.hpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -g -o ScheduleSimDebug schedulesim.cpp simulate.cpp Scheduler.cpp Process.cpp	