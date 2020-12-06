//item_t* items; ARRAY ITSELF
//int size; LENGTH OF DATA WITHIN ARRAY
//int capacity; LENGTH OF ARRAY
#include<iostream>

using namespace std;

template <class item_t>
ArrayList<item_t>::ArrayList(){
	items = new item_t[10];
	size = 0;
	capacity = 10;
}

//===========
// PRIVATE
//===========

template <class item_t>
void ArrayList<item_t>::doubleCapacity(){
	capacity *= 2;
	item_t* newArray = new item_t[capacity];
	for(int i = 0; i < size; i++){
		newArray[i] = items[i];
	}
	delete[] items;
	items = newArray;
	size++;
}

template <class item_t>
void ArrayList<item_t>::variablePush(int index){
	item_t temp;
	for(int i = index+1; i < size; i++){
		temp = items[i];
		items[i] = items[index];
		items[index] = temp;
	}
}

template <class item_t>
void ArrayList<item_t>::variablePop(int index){
	for(int i = index; i < size-1; i++){
		items[i] = items[i+1];
	}
	size--;
}

//===========

//===========
// PUBLIC
//==========

//Creates a list with the given capacity
template <class item_t>
ArrayList<item_t>::ArrayList(int capacity){
	items = new item_t[capacity];
	this->capacity = capacity;
	size = 0;
}

template <class item_t>
ArrayList<item_t>::~ArrayList(){
	delete[] items;
}

//Pushes item to the back of the list
template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item){
	if(size < capacity){
		items[size] = item;
		size++;
	} else{
		this->doubleCapacity();
		items[size-1] = item;
	}
}

//Removes, but does not return, the last item
template <class item_t>
void ArrayList<item_t>::popBack(){
	size--;
}

//Returns a reference to the last item (does not remove it).
template <class item_t>
const item_t& ArrayList<item_t>::getBack() const{
	const item_t& ref = items[size-1];
	return ref;
}
   
//Pushes item to the front of the list
template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item){
	this->insert(0,item);
}

//Removes, but does not return, the first item
template <class item_t>
void ArrayList<item_t>::popFront(){
	this->variablePop(0);
}

//Returns a reference to the first item (does not remove it).
template <class item_t>
const item_t& ArrayList<item_t>::getFront() const{
	const item_t& ref = items[0];
	return ref;
}

//Returns a reference to the item at the given index
template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const{
	const item_t& ref = items[index];
	return ref;
}

//Sets the item at the given index
template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item){
	items[index] = item;
}

//Inserts the given item at the given index
//(items at index or beyond shift up one position)
//Inserting just past the last element (i.e. position
//size) shoud be equivalent to pushBack.
template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item){
	if(index == size){
		this->pushBack(item);
	} else{
		if(size < capacity){
			size++;
			this->variablePush(index);
			items[index] = item;
		} else {
			this->doubleCapacity();
			this->variablePush(index);
			items[index] = item;
		}
	}
}

//Removes the item at the given index
//(items beyond index shift down one position)
template <class item_t>
void ArrayList<item_t>::remove(int index){
	this->variablePop(index);
}

//Returns the number of items in the list
template <class item_t>
int ArrayList<item_t>::getSize() const{
	return size;
}

//Returns true if the list is empty (false otherwise)
template <class item_t>
bool ArrayList<item_t>::isEmpty() const{
	if(size == 0){
		return true;
	} else{
		return false;
	}
}
 
//Returns the size of the array that contains the list
template <class item_t>
int ArrayList<item_t>::getCapacity() const{
	return capacity;
}