#ifndef BSTMULTIMAP
#define BSTMULTIMAP

#include<string>//should this be in the hpp or the tpp file?
#include<queue>
#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"

template<class key_t,class val_t>
class BSTMultimap{
 protected:
 	int numItems;

 	BSTNode<key_t,val_t>* root;
 	BSTNode<key_t,val_t>* sentinel;

 	void deleteTree(BSTNode<key_t,val_t>* node);

 	void swap(BSTNode<key_t,val_t>* n, BSTNode<key_t,val_t>* replacement);

 public:
 	BSTMultimap();

 	virtual ~BSTMultimap();

 	virtual void insert(const key_t& key,const val_t& val);

 	virtual bool contains(const key_t& key) const;

 	virtual BSTForwardIterator<key_t,val_t> getMin() const;

 	virtual BSTForwardIterator<key_t,val_t> getMax() const;

 	virtual BSTForwardIterator<key_t,val_t> findFirst(const key_t& key) const;

 	virtual BSTForwardIterator<key_t,val_t> findLast(const key_t& key) const;

 	virtual BSTForwardIterator<key_t,val_t> remove(const BSTForwardIterator<key_t,val_t>& pos);

 	virtual void clear();

 	virtual int getSize();

 	virtual bool isEmpty();

 	virtual std::string toString();

};

#include "BSTMultimap.tpp"

#endif