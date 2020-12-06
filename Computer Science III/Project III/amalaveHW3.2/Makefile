OPTS = -Wall -std=c++11

all: matrixdijkstra listdijkstra bellmanford

readGraph.o: readGraph.hpp readGraph.cpp
	g++ ${OPTS} -c readGraph.cpp

readGraph_TEST: readGraph_TEST.cpp readGraph.o
	g++ ${OPTS} -o readGraphTest readGraph_TEST.cpp readGraph.o

readGraph_COV: readGraph_TEST.cpp readGraph.o
	g++ ${OPTS} --coverage -o readGraphCov readGraph_TEST.cpp readGraph.o

shortestPath.o: shortestPath.hpp shortestPath.cpp BinaryHeap.hpp BinaryHeap.cpp
	g++ ${OPTS} -c shortestPath.cpp BinaryHeap.cpp

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.o readGraph.o BinaryHeap.o
	g++ ${OPTS} -o shortestPathTest shortestPath_TEST.cpp shortestPath.o readGraph.o BinaryHeap.o

shortestPath_COV: shortestPath_TEST.cpp shortestPath.hpp shortestPath.cpp readGraph.hpp readGraph.cpp BinaryHeap.o
	g++ ${OPTS} --coverage -o shortestPathCov shortestPath_TEST.cpp shortestPath.o readGraph.o BinaryHeap.o

BinaryHeap.o: BinaryHeap.hpp BinaryHeap.cpp
	g++ ${OPTS} -c BinaryHeap.cpp

BinaryHeap_TEST: BinaryHeap.o BinaryHeap_TEST.cpp
	g++ ${OPTS} -o BinaryHeapTest BinaryHeap_TEST.cpp BinaryHeap.o

BinaryHeap_COV: BinaryHeap.o BinaryHeap_TEST.cpp
	g++ ${OPTS} --coverage -o BinaryHeapCov BinaryHeap.o BinaryHeap_TEST.cpp

matrixdijkstra: matrixDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o
	g++ ${OPTS} -o matrixdijkstra matrixDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o

listdijkstra: listDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o
	g++ ${OPTS} -o listdijkstra listDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o

bellmanford: bellmanFord.cpp shortestPath.o readGraph.o BinaryHeap.o
	g++ ${OPTS} -o bellmanford bellmanFord.cpp shortestPath.o readGraph.o BinaryHeap.o

currency: currency.cpp shortestPath.o readGraph.o BinaryHeap.o
	g++ ${OPTS} -o currency currency.cpp shortestPath.o readGraph.o BinaryHeap.o

cleancov: #Cleans up the files generated when we measure coverage
	rm -r -f *.gcda *.gcno *.gcov *.info *.coverage RBTNodeCov RBTMultimapCov CompletelyFairCov BSTMultimapCov BSTNodeCov RoundRobinCov ArrayListCov LinkedListCov

tests: readGraph_TEST shortestPath_TEST BinaryHeap_TEST