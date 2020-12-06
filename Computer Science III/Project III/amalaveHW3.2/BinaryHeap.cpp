#include "BinaryHeap.hpp"

//============
// PROTECTED
//============

int BinaryHeap::getLeft(int pos){
	int leftPos = (2*pos)+1;
	if(leftPos >= numItems){
		return -1;
	} else{
		return leftPos;
	}
}

int BinaryHeap::getRight(int pos){
	int rightPos = 2*(pos+1);
	if(rightPos >= numItems){
		return -1;
	} else{
		return rightPos;
	}
}

int BinaryHeap::getParent(int pos){
	int parentPos = (pos-1)/2;
	return parentPos;
}

void BinaryHeap::swap(int pos1,int pos2){
	double temp = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = temp;

	int temp2 = positions[pos1];
	positions[pos1] = positions[pos2];
	positions[pos2] = temp2;
}

void BinaryHeap::siftDown(int pos){
	int left = getLeft(pos);
	int right = getRight(pos);
	int minPos = pos;
	if(left != -1 and heap[left] < heap[minPos]){
		minPos = left;
	}
	if(right != -1 and heap[right] < heap[minPos]){
		minPos = right;
	}
	if(minPos != pos){
		swap(pos,minPos);
		siftDown(minPos);
	}
}

void BinaryHeap::heapify(int pos){
	int parent = getParent(pos);
	int minPos = parent;
	int left = getLeft(parent);
	int right = getRight(parent);
	if(left != -1 and heap[left] < heap[minPos]){
		minPos = left;
	}
	if(right != -1 and heap[right] < heap[minPos]){
		minPos = right;
	}
	if(minPos != parent){
		swap(parent,minPos);
		heapify(parent);
	}
}

//============

//============
// PUBLIC
//============

BinaryHeap::BinaryHeap(const double* priorities, int numItems){
	this->heap = new double[numItems];
	for(int i = 0; i < numItems; i++){
		heap[i] = priorities[i];
	}
	this->positions = new int[numItems];
	this->numItems = numItems;
	for(int i = 0; i < numItems; i++){
		positions[i] = i;
	}
	for(int i = numItems-1; i > 0; i--){
		heapify(i);
	}
}

BinaryHeap::~BinaryHeap(){
	delete[] heap;
	delete[] positions;
}

int BinaryHeap::getMin() const{ //returns item number that has min priority
	return positions[0];
}

void BinaryHeap::popMin(){
	heap[0] = heap[numItems-1];
	positions[0] = positions[numItems-1];
	numItems -= 1;
	siftDown(0);
}

bool BinaryHeap::contains(int item) const{
	return (item >= 0 and item < numItems);
}

double BinaryHeap::getPriority(int item){
	return heap[getPos(item)];
}

void BinaryHeap::decreasePriority(int item, double newPriority){
	if(contains(item) and newPriority < getPriority(item)){
		heap[getPos(item)] = newPriority;
		heapify(getPos(item));
	}
}

int BinaryHeap::getSize() const{
	return numItems;
}

int BinaryHeap::getItem(int pos) const{
	return positions[pos];
}

int BinaryHeap::getPos(int item) const{
	return positions[item];
}

//============