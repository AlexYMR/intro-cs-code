#ifndef BINARYHEAP
#define BINARYHEAP

#include<iostream>
#include<limits>

using namespace std;

class BinaryHeap{
	protected:
		double* heap;
		int* positions;
		int numItems;

		int getLeft(int pos);
		int getRight(int pos);
		int getParent(int pos);
		void swap(int pos1,int pos2);
		void siftDown(int pos);
		void heapify(int pos);

	public:
		BinaryHeap(const double* priorities, int numItems);
		~BinaryHeap();
		
		int getMin() const;
		void popMin();
		bool contains(int item) const;
		double getPriority(int item);
		void decreasePriority(int item, double newPriority);
		int getSize() const;
		int getItem(int pos) const;
		int getPos(int item) const;
};

#endif