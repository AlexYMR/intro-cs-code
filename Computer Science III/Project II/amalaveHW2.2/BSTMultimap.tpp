
#include<iostream>
using namespace std;

//===============
// PROTECTED
//===============

template<class key_t,class val_t>
void BSTMultimap<key_t,val_t>::deleteTree(BSTNode<key_t,val_t>* node){
	if(node == sentinel){
		return;
	}
	deleteTree(node->getLeftChild());
	deleteTree(node->getRightChild());

	cout << "Deleting node with K: " << node->getKey() << ", and V: " << node->getValue() << endl;
	delete node;
}

template<class key_t,class val_t>
void BSTMultimap<key_t,val_t>::swap(BSTNode<key_t,val_t>* n, BSTNode<key_t,val_t>* replacement){
	if(n->getParent() == sentinel){
		root = replacement;
	} else if(n == n->getParent()->getLeftChild()){
		n->getParent()->setLeftChild(replacement);
	} else{
		n->getParent()->setRightChild(replacement);
	}
	if(replacement != sentinel){
		replacement->setParent(n->getParent());
	}
}

//==============

//==============
// PUBLIC
//==============

template<class key_t,class val_t>
BSTMultimap<key_t,val_t>::BSTMultimap(){
	sentinel = 0;
	root = sentinel;
	numItems = 0;
}

template<class key_t,class val_t>
BSTMultimap<key_t,val_t>::~BSTMultimap(){
	clear();
}

template<class key_t,class val_t>
void BSTMultimap<key_t,val_t>::insert(const key_t& key,const val_t& val){
	//what's supposed to happen when key == root's value??
	BSTNode<key_t,val_t>* y = sentinel;
	BSTNode<key_t,val_t>* x = root;
	BSTNode<key_t,val_t>* z = new BSTNode<key_t,val_t>(key,val);
	while(x != sentinel){
		y = x;
		if(key < y->getKey()){
			x = x->getLeftChild();
		} else{
			x = x->getRightChild();
		}
	}
	z->setParent(y);
	if(y == sentinel){
		root = z;
	} else if(key < y->getKey()){
		y->setLeftChild(z);
	} else{
		y->setRightChild(z);
	}
	numItems++;
}

template<class key_t,class val_t>
bool BSTMultimap<key_t,val_t>::contains(const key_t& key) const{
	//true if key is in tree, false otherwise
	BSTNode<key_t,val_t>* node = root;
	while(node != sentinel and key != node->getKey()){
		if(key < node->getKey()){
			node = node->getLeftChild();
		} else{
			node = node->getRightChild();
		}
	}
	if(node == sentinel){
		return false;
	} else{
		return true;
	}
}

template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>::getMin() const{
	if(numItems == 0){
		return BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
	}

	BSTNode<key_t,val_t>* x = root;
	//gets min val in right subtree
	while(x->getLeftChild() != sentinel){
		x = x->getLeftChild();
	}
	
	return BSTForwardIterator<key_t,val_t>(x,sentinel);
}

template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>::getMax() const{
	if(numItems == 0){
		return BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
	}

	BSTNode<key_t,val_t>* x = root;
	//gets min val in right subtree
	while(x->getRightChild() != sentinel){
		x = x->getRightChild();
	}
	
	return BSTForwardIterator<key_t,val_t>(x,sentinel);
}

template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>::findFirst(const key_t& key) const{
	//returns an iterator pointing to the first node (in an inorder sequence) that has the given key
	//if they key is not present, returns an iterator to the sentinel
	BSTNode<key_t,val_t>* node = root;
	BSTNode<key_t,val_t>* lastOccurrence = sentinel;
	while(node != sentinel){
		if(key < node->getKey()){
			node = node->getLeftChild();
		} else if(key > node->getKey()){
			node = node->getRightChild();
		} else{
			//go left
			lastOccurrence = node;
			node = node->getLeftChild();
		}
	}
	if(lastOccurrence != sentinel){
		return BSTForwardIterator<key_t,val_t>(lastOccurrence,sentinel);
	} else{
		return BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
	}
}

//BROKEN
template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>::findLast(const key_t& key) const{
	//returns an iterator pointing to the last node (in an inorder sequence) that has the given key
	//if the key is not present, return an iterator to the sentinel
	BSTNode<key_t,val_t>* node = root;
	BSTNode<key_t,val_t>* lastOccurrence = sentinel;
	while(node != sentinel){
		if(key < node->getKey()){
			node = node->getLeftChild();
		} else if(key > node->getKey()){
			node = node->getRightChild();
		} else{
			//go right
			lastOccurrence = node;
			node = node->getRightChild();
		}
	}
	if(lastOccurrence != sentinel){
		return BSTForwardIterator<key_t,val_t>(lastOccurrence,sentinel);
	} else{
		return BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
	}
}

template<class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>::remove(const BSTForwardIterator<key_t,val_t>& pos){
	//removes node pointed to by the iterator, and returns an iterator pointing to that node's successor
	BSTNode<key_t,val_t>* x = pos.current;
	BSTForwardIterator<key_t,val_t> replacement(x,sentinel);
	replacement.next();
	BSTNode<key_t,val_t>* y = replacement.current;
	if(x->getLeftChild() == sentinel){
		swap(x,x->getRightChild());
	} else if(x->getRightChild() == sentinel){
		swap(x,x->getLeftChild());
	} else{
		if(y->getParent() != x){//if the successor is not the immediate child of the node
			swap(y,y->getRightChild());
			y->setRightChild(x->getRightChild());
			y->getRightChild()->setParent(y);
		}
		swap(x,y);
		y->setLeftChild(x->getLeftChild());
		y->getLeftChild()->setParent(y);
	}
	return BSTForwardIterator<key_t,val_t>(y,sentinel);
}

template<class key_t,class val_t>
void BSTMultimap<key_t,val_t>::clear(){
	//deletes all nodes, resets root, and numItems (you had to go through all nodes to print the tree too)
	deleteTree(root);
	numItems = 0;
	root = sentinel;
}

template<class key_t,class val_t>
int BSTMultimap<key_t,val_t>::getSize(){
	return numItems;
}

template<class key_t,class val_t>
bool BSTMultimap<key_t,val_t>::isEmpty(){
	return numItems == 0;
}

template<class key_t,class val_t>
string BSTMultimap<key_t,val_t>::toString(){
	//queue<BSTNode<key_t,val_t>*> q;
	//q.push(root);
	string result = "";
	/*while(!q.empty()){
		BSTNode<key_t,val_t>* node = q.front();
		key_t k = node->getKey();
		val_t v = node->getValue();
		BSTNode<key_t,val_t>* p = node->getParent();
		result = result + "K: " + to_string(k) + ", V: " + to_string(v) + ", P: " + (p != sentinel ? to_string(p->getKey()):"sentinel") + "\n";
		
		BSTNode<key_t,val_t>* left = node->getLeftChild();
		if(left != sentinel){
			q.push(left);
		}
		
		BSTNode<key_t,val_t>* right = node->getRightChild();
		if(right != sentinel){
			q.push(right);
		}
		q.pop();
	}*/
	return result;
}