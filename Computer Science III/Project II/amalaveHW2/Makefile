OPTS = -Wall -std=c++11

all: schedulesim

RBTNode_TEST: RBTNode_TEST.cpp BSTNode.hpp BSTNode.tpp RBTNode.hpp RBTNode.tpp
	g++ ${OPTS} -o RBTNodeTest RBTNode_TEST.cpp

RBTNode_COV: RBTNode_TEST.cpp BSTNode.hpp BSTNode.tpp RBTNode.hpp RBTNode.tpp
	g++ ${OPTS} --coverage -o RBTNodeCov RBTNode_TEST.cpp

RBTMultimap_TEST: RBTNode_TEST.cpp BSTNode.hpp BSTNode.tpp RBTNode.hpp RBTNode.tpp RBTMultimap.tpp RBTMultimap.hpp
	g++ ${OPTS} -o RBTMultimapTest RBTMultimap_TEST.cpp

RBTMultimap_COV: RBTNode_TEST.cpp BSTNode.hpp BSTNode.tpp RBTNode.hpp RBTNode.tpp RBTMultimap.tpp RBTMultimap.hpp
	g++ ${OPTS} --coverage -o RBTMultimapCov RBTMultimap_TEST.cpp

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp
	g++ ${OPTS} -o BSTNodeTest BSTNode_TEST.cpp

BSTNode_COV: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp
	g++ ${OPTS} --coverage -o BSTNodeCov BSTNode_TEST.cpp

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp
	g++ ${OPTS} -o BSTMultimapTest BSTMultimap_TEST.cpp

BSTMultimap_COV: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp
	g++ ${OPTS} --coverage -o BSTMultimapCov BSTMultimap_TEST.cpp

CompletelyFair_TEST: CompletelyFair_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} -o CompletelyFairTest CompletelyFair_TEST.cpp Process.cpp Scheduler.cpp

CompletelyFair_COV: CompletelyFair_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} --coverage -o CompletelyFairCov CompletelyFair_TEST.cpp Process.cpp Scheduler.cpp

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -o ArrayListTest ArrayList_TEST.cpp

ArrayList_COV: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} --coverage -o ArrayListCov ArrayList_TEST.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.tpp LinkedListNode.hpp
	g++ ${OPTS} -o RoundRobinTest RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

RoundRobin_COV: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp LinkedList.tpp LinkedList.hpp LinkedListNode.tpp LinkedListNode.hpp
	g++ ${OPTS} --coverage -o RoundRobinCov RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

RoundRobin_DEBUG: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp
	g++ ${OPTS} -g -o RoundRobinDebug RoundRobin_TEST.cpp Scheduler.cpp Process.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} -o LinkedListTest LinkedList_TEST.cpp

LinkedList_COV: LinkedList_TEST.cpp LinkedList.hpp LinkedListNode.hpp LinkedListNode.tpp List.hpp
	g++ ${OPTS} --coverage -o LinkedListCov LinkedList_TEST.cpp

schedulesim: schedulesim.cpp simulate.cpp simulate.hpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp RBTNode.hpp RBTNode.tpp RBTMultimap.tpp RBTMultimap.hpp
	g++ ${OPTS} -o schedulesim schedulesim.cpp simulate.cpp Scheduler.cpp Process.cpp

schedulesim_DEBUG: schedulesim.cpp simulate.cpp simulate.hpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp List.hpp ArrayList.hpp ArrayList.tpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp RBTNode.hpp RBTNode.tpp RBTMultimap.tpp RBTMultimap.hpp
	g++ ${OPTS} -g -o schedulesimDebug schedulesim.cpp simulate.cpp Scheduler.cpp Process.cpp

cleancov: #Cleans up the files generated when we measure coverage
	rm -r -f *.gcda *.gcno *.gcov *.info *.coverage RBTNodeCov RBTMultimapCov CompletelyFairCov BSTMultimapCov BSTNodeCov RoundRobinCov ArrayListCov LinkedListCov

tests: RBTNode_TEST BSTNode_TEST RBTMultimap_TEST BSTMultimap_TEST CompletelyFair_TEST ArrayList_TEST RoundRobin_TEST LinkedList_TEST