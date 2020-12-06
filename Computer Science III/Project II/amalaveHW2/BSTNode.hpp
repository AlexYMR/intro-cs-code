#ifndef BSTNODE
#define BSTNODE
template <class key_t, class val_t>
class BSTNode{
	protected:
		key_t key;
		val_t value;
		BSTNode<key_t,val_t>* left; 
		BSTNode<key_t,val_t>* right;
		BSTNode<key_t,val_t>* parent;

	public:
		BSTNode(const key_t& k, const val_t& v);
		virtual ~BSTNode(){};
		virtual void setValue(const val_t& v);
		virtual void setKey(const key_t& k);
		virtual void setLeftChild(BSTNode* L);
		virtual void setRightChild(BSTNode* R);
		virtual void setParent(BSTNode* P);

		virtual const val_t& getValue() const;
		virtual const key_t& getKey() const;
		virtual BSTNode<key_t,val_t>* getLeftChild() const;
		virtual BSTNode<key_t,val_t>* getRightChild() const;
		virtual BSTNode<key_t,val_t>* getParent() const;
};

#include "BSTNode.tpp"

#endif