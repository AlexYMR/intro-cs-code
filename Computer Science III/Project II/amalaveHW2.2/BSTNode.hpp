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
		void setValue(const val_t& v);
		void setKey(const key_t& k);
		void setLeftChild(BSTNode* L);
		void setRightChild(BSTNode* R);
		void setParent(BSTNode* P);

		const val_t& getValue() const;
		const key_t& getKey() const;
		BSTNode<key_t,val_t>* getLeftChild() const;
		BSTNode<key_t,val_t>* getRightChild() const;
		BSTNode<key_t,val_t>* getParent() const;

};

#include "BSTNode.tpp"

#endif