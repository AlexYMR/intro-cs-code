template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

template<class key_t,class val_t>
RBTMultimap<key_t,val_t>::RBTMultimap(){
	key_t k;
	val_t v;
	RBTNode<key_t,val_t>* sentinel = new RBTNode<key_t,val_t>(k,v,false);
	this->sentinel = sentinel;
	this->root = sentinel;
}

template<class key_t,class val_t>
RBTMultimap<key_t,val_t>::~RBTMultimap(){
	this->clear();
	delete this->sentinel;
}

//=============
// PROTECTED
//=============

//Performs the rotate left operation
//(assumes node has a right child)
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::rotateLeft(BSTNode<key_t, val_t>* node){
	BSTNode<key_t,val_t>* y = node->getRightChild();

	y->setParent(node->getParent());
	if(node->getParent() == this->sentinel){
		this->root = y;
	} else if(node == node->getParent()->getLeftChild()){
		node->getParent()->setLeftChild(y);
	} else{
		node->getParent()->setRightChild(y);
	}

	node->setRightChild(y->getLeftChild());
	if(y->getLeftChild() != this->sentinel){
		y->getLeftChild()->setParent(node);
	}

	y->setLeftChild(node);
	node->setParent(y);
}

//Performs the rotate right operation
//(assumes node has a left child)
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::rotateRight(BSTNode<key_t, val_t>* node){
	BSTNode<key_t,val_t>* y = node->getLeftChild();

	y->setParent(node->getParent());
	if(node->getParent() == this->sentinel){
		this->root = y;
	} else if(node == node->getParent()->getLeftChild()){
		node->getParent()->setLeftChild(y);
	} else{
		node->getParent()->setRightChild(y);
	}

	node->setLeftChild(y->getRightChild());
	if(y->getRightChild() != this->sentinel){
		y->getRightChild()->setParent(node);
	}

	y->setRightChild(node);
	node->setParent(y);
}

//Fix up the tree after an insert
//(assumes insertedNode is red)
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::insertFixup(RBTNode<key_t,val_t>* insertedNode){
	while(insertedNode->getParent()->isRed()){
		if(insertedNode->getParent() == insertedNode->getParent()->getParent()->getLeftChild()){
			RBTNode<key_t,val_t>* y = insertedNode->getParent()->getParent()->getRightChild(); //uncle
			if(y->isRed()){
				//push the black down to children
				insertedNode->getParent()->setIsRed(false);
				y->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			} else{ //uncle is black, and parent is red
				if(insertedNode == insertedNode->getParent()->getRightChild()){
					//if it's the right child, there's a zig-zag--we want a chain
					//rotate left to fix this, parent becomes node to fix
					insertedNode = insertedNode->getParent();
					rotateLeft(insertedNode); //orig. insNode -> child of its grandparent
				}
				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				rotateRight(insertedNode->getParent()->getParent());
			}
		} else{ //inserted node's parent is the right child of its parent
			//symmetric code
			RBTNode<key_t,val_t>* y = insertedNode->getParent()->getParent()->getLeftChild();
			if(y->isRed()){
				insertedNode->getParent()->setIsRed(false);
				y->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			} else{
				if(insertedNode == insertedNode->getParent()->getLeftChild()){
					insertedNode = insertedNode->getParent();
					rotateRight(insertedNode);
				}
				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				rotateLeft(insertedNode->getParent()->getParent());
			}
		}
	}
	dynamic_cast<RBTNode<key_t,val_t>*>(this->root)->setIsRed(false);
}

//Fix up the tree after deleting a node
//ReplacementNode is the node that replaced the deleted node
//(possibly the sentinel)
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode){
	while(replacementNode != dynamic_cast<RBTNode<key_t,val_t>*>(this->root) and replacementNode->isRed() == false){
		if(replacementNode == replacementNode->getParent()->getLeftChild()){
			RBTNode<key_t,val_t>* nodeSibling = replacementNode->getParent()->getRightChild();
			if(nodeSibling->isRed()){
				nodeSibling->setIsRed(false);
				replacementNode->getParent()->setIsRed(true);
				rotateLeft(replacementNode->getParent());
				nodeSibling = replacementNode->getParent()->getRightChild();
			}
			if(!nodeSibling->getLeftChild()->isRed() and !nodeSibling->getRightChild()->isRed()){
				nodeSibling->setIsRed(true);
				replacementNode = replacementNode->getParent();
			} else{
				if(!nodeSibling->getRightChild()->isRed()){
					nodeSibling->getLeftChild()->setIsRed(false);
					nodeSibling->setIsRed(true);
					rotateRight(nodeSibling);
					nodeSibling = replacementNode->getParent()->getRightChild();
				}
				nodeSibling->setIsRed(replacementNode->getParent()->isRed());
				replacementNode->getParent()->setIsRed(false);
				nodeSibling->getRightChild()->setIsRed(false);
				rotateLeft(replacementNode->getParent());
				replacementNode = dynamic_cast<RBTNode<key_t,val_t>*>(this->root);
			}
			
		} else{ //symmetric code
			RBTNode<key_t,val_t>* nodeSibling = replacementNode->getParent()->getLeftChild();
			if(nodeSibling->isRed()){
				nodeSibling->setIsRed(false);
				replacementNode->getParent()->setIsRed(true);
				rotateRight(replacementNode->getParent());
				nodeSibling = replacementNode->getParent()->getLeftChild();
			}
			if(!nodeSibling->getLeftChild()->isRed() and !nodeSibling->getRightChild()->isRed()){
				nodeSibling->setIsRed(true);
				replacementNode = replacementNode->getParent();
			} else{
			 	if(!nodeSibling->getLeftChild()->isRed()){
					nodeSibling->getRightChild()->setIsRed(false);
					nodeSibling->setIsRed(true);
					rotateLeft(nodeSibling);
					nodeSibling = replacementNode->getParent()->getLeftChild();
				}
				nodeSibling->setIsRed(replacementNode->getParent()->isRed());
				replacementNode->getParent()->setIsRed(false);
				nodeSibling->getLeftChild()->setIsRed(false);
				rotateRight(replacementNode->getParent());
				replacementNode = dynamic_cast<RBTNode<key_t,val_t>*>(this->root);
			}
		}
	}
	replacementNode->setIsRed(false);
}

//Puts replacementNode in nodeToReplace's position in the tree
//(replacementNode takes its children along with it)
//Assumes nodeToReplace is a real node (not the sentinel)
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode){
	if(nodeToReplace->getParent() == this->sentinel){
		this->root = replacementNode;
	} else if(nodeToReplace == nodeToReplace->getParent()->getLeftChild()){
		nodeToReplace->getParent()->setLeftChild(replacementNode);
	} else{
		nodeToReplace->getParent()->setRightChild(replacementNode);
	}
	//if(replacementNode != this->sentinel){
	replacementNode->setParent(nodeToReplace->getParent());
	//}
}

//=============

//=============
// PUBLIC
//=============


//Inserts (key, value) into the multimap
template <class key_t,class val_t>
void RBTMultimap<key_t,val_t>::insert(const key_t& key, const val_t& value){
	RBTNode<key_t,val_t>* node = new RBTNode<key_t,val_t>(key,value,true);
	//setting children to sentinel so that they're not 0 (nil)
	node->setRightChild(this->sentinel);
	node->setLeftChild(this->sentinel);
	this->insertNode(node);
	insertFixup(node);
}

//Removes the key/value pair pointed to by pos
//(if pos is off the end, does nothing)
//Returns an iterator pointing to the next node after the
//deleted node
//NOT WORKING -- SENTINEL GETS SENT AS RNODE BUT IT SHOULD NOT BE (?)
template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t,val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){
	RBTNode<key_t,val_t>* x = dynamic_cast<RBTNode<key_t,val_t>*>(pos.current); //node marked for deletion
	RBTNode<key_t,val_t>* rNode = x;
	RBTNode<key_t,val_t>* nodeToBeDeleted = x;
	bool deletedNodeColor = x->isRed();

	BSTForwardIterator<key_t,val_t> replacement(x,this->sentinel);
	replacement.next();

	if(x->getLeftChild() == this->sentinel){
		rNode = x->getRightChild();
		transplant(x,rNode);
	} else if(x->getRightChild() == this->sentinel){
		rNode = x->getLeftChild();
		transplant(x,rNode);
	} else{
		nodeToBeDeleted = dynamic_cast<RBTNode<key_t,val_t>*>(replacement.current); //the successor node
		deletedNodeColor = nodeToBeDeleted->isRed();
		rNode = nodeToBeDeleted->getRightChild();

		if(nodeToBeDeleted->getParent() == x){
			rNode->setParent(nodeToBeDeleted);
		} else{//if the successor is not the immediate child of the node
			transplant(nodeToBeDeleted,nodeToBeDeleted->getRightChild());
			nodeToBeDeleted->setRightChild(x->getRightChild());
			nodeToBeDeleted->getRightChild()->setParent(nodeToBeDeleted);
		}
		transplant(x,nodeToBeDeleted);
		nodeToBeDeleted->setLeftChild(x->getLeftChild());
		nodeToBeDeleted->getLeftChild()->setParent(nodeToBeDeleted);
		nodeToBeDeleted->setIsRed(x->isRed());
	}
	delete x;
	if(deletedNodeColor == false){
		deleteFixup(rNode);
	}
	this->numItems--;
	return BSTForwardIterator<key_t,val_t>(replacement.current,this->sentinel);
}

template<class key_t,class val_t>
string RBTMultimap<key_t,val_t>::toString(){
	queue<RBTNode<key_t,val_t>*> q;
	q.push(dynamic_cast<RBTNode<key_t,val_t>*>(this->root));
	stringstream result;
	while(!q.empty()){
		RBTNode<key_t,val_t>* node = q.front();
		key_t k = node->getKey();
		val_t v = node->getValue();
		RBTNode<key_t,val_t>* p = node->getParent();
		if(p != dynamic_cast<RBTNode<key_t,val_t>*>(this->sentinel)){
			result << "K: " << k << ", V: " << v << ", RED: " << node->isRed() << ", P: " << p->getKey() << "\n";
		} else{
			result << "K: " << k << ", V: " << v << ", RED: " << node->isRed() << ", P: sentinel" << "\n";
		}
		
		RBTNode<key_t,val_t>* left = node->getLeftChild();
		if(left != dynamic_cast<RBTNode<key_t,val_t>*>(this->sentinel)){
			q.push(left);
		}
		
		RBTNode<key_t,val_t>* right = node->getRightChild();
		if(right != dynamic_cast<RBTNode<key_t,val_t>*>(this->sentinel)){
			q.push(right);
		}
		q.pop();
	}
	return result.str();
}

//=============
