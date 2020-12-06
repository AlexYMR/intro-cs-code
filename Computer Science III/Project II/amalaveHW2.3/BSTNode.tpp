template <class key_t, class val_t>
BSTNode<key_t,val_t>::BSTNode(const key_t& k, const val_t& v){
	key = k;
	value = v;
	left = 0;
	right = 0;
	parent = 0;
}

//template<class key_t,class val_t>
//BSTNode<key_t,val_t>::~BSTNode(){}

template <class key_t, class val_t>
void BSTNode<key_t,val_t>::setValue(const val_t& v){
	value = v;
}

template <class key_t, class val_t>
void BSTNode<key_t,val_t>::setKey(const key_t& k){
	key = k;
}

template <class key_t, class val_t>
void BSTNode<key_t,val_t>::setLeftChild(BSTNode<key_t,val_t>* L){
	left = L;
}

template <class key_t, class val_t>
void BSTNode<key_t,val_t>::setRightChild(BSTNode<key_t,val_t>* R){
	right = R;
}

template <class key_t, class val_t>
void BSTNode<key_t,val_t>::setParent(BSTNode<key_t,val_t>* P){
	parent = P;
}

template <class key_t, class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getParent() const{
	return parent;
}


template <class key_t, class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getRightChild() const{
	return right;
}

template <class key_t, class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getLeftChild() const{
	return left;
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t,val_t>::getValue() const{
	return value;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t,val_t>::getKey() const{
	return key;
}

