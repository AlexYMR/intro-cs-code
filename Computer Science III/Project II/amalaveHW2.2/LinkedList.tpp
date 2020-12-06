//LinkedListNode* head;
//LinkedListNode* tail;
//int size;

//LOOK AT:
// pushBack: explain why things should be instantiated on the heap
// explain why you must use pointers in b* = new b(item); things
// RoundRobin_TEST

#include<iostream>

using namespace std;

//===========
// PRIVATE
//===========

template<class item_t>
LinkedListNode<item_t>* LinkedList<item_t>::getNode(int index) const{
	LinkedListNode<item_t>* n = head;
	for(int i = 0; i < index; i++){//size-1
		n = n->getNext();
	}
	return n;
}

//===========

//===========
// PUBLIC
//===========

//Creates a list with the given capacity
template <class item_t>
LinkedList<item_t>::LinkedList(){
	head = 0;
	tail = 0;
	size = 0;
}

//deletes ALL nodes in the list
template <class item_t>
LinkedList<item_t>::~LinkedList(){
	if(size > 2){
		for(int i = 1; i < size; i++){
			LinkedListNode<item_t>* n = head->getNext();
			head->setNext(n->getNext());
			delete n;
		}
	} else if(size == 2){
		delete tail;
	}
	delete head;
}

//Pushes item to the back of the list
template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item){
	if(size == 0){
		LinkedListNode<item_t>* entry = new LinkedListNode<item_t>(0,item);
		head = entry;
		tail = entry;
	} else if(size == 1){
		LinkedListNode<item_t>* entry = new LinkedListNode<item_t>(0,item);
		head->setNext(entry);
		tail = entry;
	} else{
		LinkedListNode<item_t>* entry = new LinkedListNode<item_t>(0,item);
		tail->setNext(entry);
		tail = entry;
	}
	size++;
}

//Removes, but does not return, the last item
template <class item_t>
void LinkedList<item_t>::popBack(){
	LinkedListNode<item_t>* n = getNode(size-2);
	delete tail;
	size--;
	if(size == 0){
		head = sentinel;
		tail = sentinel;
	} else{
		tail = n;
		n.setNext(sentinel);
	}
}

//Returns a reference to the last item (does not remove it).
template <class item_t>
const item_t& LinkedList<item_t>::getBack() const{
	const item_t& ref = tail->getItem();
	return ref;
}
   
//Pushes item to the front of the list
template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item){
	LinkedListNode<item_t>* entry = new LinkedListNode<item_t>(head,item);
	head = entry;
	size++;
	if(size == 0){
		tail = entry;
	}
}

//Removes, but does not return, the first item
template <class item_t>
void LinkedList<item_t>::popFront(){
	LinkedListNode<item_t>* n = head->getNext();
	delete head;
	size--;
	if(size == 0){
		head = sentinel;
		tail = sentinel;
	} else{
		head = n;
	}
}

//Returns a reference to the first item (does not remove it).
template <class item_t>
const item_t& LinkedList<item_t>::getFront() const{
	const item_t& ref = head->getItem();
	return ref;
}

//Returns a reference to the item at the given index
template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const{
	if(index == size-1){
		return getBack();
	} else if (index == 0){
		return getFront();
	} else{
		LinkedListNode<item_t>* n = getNode(index);
		const item_t& ref = n->getItem();
		return ref;
	}
}

//Sets the item at the given index
template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item){
	if(index == size-1){
		tail->setItem(item);
	} else if (index == 0){
		head->setItem(item);
	} else{
		LinkedListNode<item_t>* n = getNode(index);
		n->setItem(item);
	}
}

//Inserts the given item at the given index
//(items at index or beyond shift up one position)
//Inserting just past the last element (i.e. position
//size) should be equivalent to pushBack.
template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item){
	if(index == size){
		pushBack(item);
	} else if (index == 0){
		pushFront(item);
	} else{
		LinkedListNode<item_t>* n = getNode(index-1);
		LinkedListNode<item_t>* nextNode = n->getNext();
		LinkedListNode<item_t>* newNode = new LinkedListNode<item_t>(nextNode,item);
		n->setNext(newNode);
		size++;
	}
}

//Removes the item at the given index
//(items beyond index shift down one position)
template <class item_t>
void LinkedList<item_t>::remove(int index){
	if(index == size-1){
		popBack();
	} else if (index == 0){
		popFront();
	} else{
		LinkedListNode<item_t>* n = getNode(index-1);
		LinkedListNode<item_t>* delNode = n->getNext();
		n->setNext(delNode->getNext());
		delete delNode;
		size--;
	}
}

//Returns the number of items in the list
template <class item_t>
int LinkedList<item_t>::getSize() const{
	return size;
}

//Returns true if the list is empty (false otherwise)
template <class item_t>
bool LinkedList<item_t>::isEmpty() const{
	if(size == 0){
		return true;
	} else{
		return false;
	}
}

//===========