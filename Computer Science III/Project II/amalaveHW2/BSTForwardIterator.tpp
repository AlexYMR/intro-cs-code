#include "BSTForwardIterator.hpp"

/*
BSTNode<key_t, val_t>* current; - node iterator is currently pointing to
BSTNode<key_t, val_t>* sentinel; - pointer val that represents end of tree
*/

//==============
// PUBLIC
//==============

template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel){
	current = node;
	this->sentinel = sentinel;
}

template<class key_t,class val_t>
void BSTForwardIterator<key_t,val_t>::next(){
	if(current != sentinel){
		if(current->getRightChild() != sentinel){
			BSTNode<key_t,val_t>* x = current->getRightChild();
			//gets min val in right subtree
			while(x->getLeftChild() != sentinel){
				x = x->getLeftChild();
			}
			current = x;
		} else{
			BSTNode<key_t,val_t>* y = current->getParent();
			while(y != sentinel and current == y->getRightChild()){
				current = y;
				y = y->getParent();
			}
			current = y;
		}
	}
}

template<class key_t,class val_t>
bool BSTForwardIterator<key_t,val_t>::isPastEnd() const{
	return (current == sentinel);
}

//what if current is sentinel?
template<class key_t,class val_t>
const key_t& BSTForwardIterator<key_t,val_t>::getKey() const{
	return current->getKey();
}

template<class key_t,class val_t>
const val_t& BSTForwardIterator<key_t,val_t>::getValue() const{
	return current->getValue();
}

template<class key_t,class val_t>
void BSTForwardIterator<key_t,val_t>::setValue(const val_t& newVal){
	current->setValue(newVal);
}

//==============