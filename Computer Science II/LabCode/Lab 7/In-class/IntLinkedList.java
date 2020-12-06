import java.util.Iterator;

/**
 * Simplified singly-linked-list class
 *
 */
class IntLinkedList extends AbstractIntList implements Iterable<Integer>

{
    Node head;
    Node tail;

    /**
     * Initialize the two instance variables.
     */
    public IntLinkedList()
    {
	head = null;
	tail = null;
    }

    /**
     * Check if the index is valid
     * If it is not valid, throw an IndexOutOfBoundsException
     * Otherwise return the int stored at the given index position
     */
    public int get(int index)
    {
	if(index>this.numItems-1 || index < 0){
	    throw new IndexOutOfBoundsException("Index " + index + " is out of bounds.");
	}
	Node curNode = head;
	for (int i = 1;i<=index;i++){
	    curNode = curNode.getNext();
	}
	return curNode.getValue();
	
    }

    /**
     * Check if the index is valid
     * If it is not valid, throw an IndexOutOfBoundsException
     * Otherwise set the int stored at the given index position
     * to the updated value
     */
    public void set(int index, int value)
    {
	if(index>this.numItems-1 || index < 0){
	    throw new IndexOutOfBoundsException("Index " + index + " is out of bounds.");
	}
	Node curNode = head;
	for (int i = 0;i<this.numItems;i++){
	    if (i == index){
		curNode.setValue(value);
	    }
	    curNode = curNode.getNext();
	}
    }

    /**
     * No index checking necessary
     */
    public void add(int value)
    {
	if (this.numItems==0){
	    head = new Node(value);
	    tail = head;
	} else {
	    Node tmp = new Node(value);
	    tail.setNext(tmp);
	    tail = tmp;
	}
	this.numItems += 1;
    }

    /**
     * Check if the index is valid
     * If it is not valid, throw an IndexOutOfBoundsException
     * Otherwise add a node with the given  to proper spot
     * to the linked list
     */
    public void add(int index, int value)
    {
	if(index>this.numItems || index < 0){
	    //System.out.println(this.numItems);
	    throw new IndexOutOfBoundsException("Index " + index + " is out of bounds.");
	}
	Node tmp = head;
	int i = 0;
	if (index == 0){
	    Node newNode = new Node(value);
	    newNode.setNext(tmp);
	    head = newNode;
	    if(this.numItems == 0){
		tail = head;
	    }
	} else if(index == this.numItems-1){
	    Node newNode = new Node(value);
	    tail.setNext(newNode);
	    tail = newNode;
	} else {
	    while(tmp != null && i<index-1){
		tmp = tmp.getNext();
		i++;
	    }
	    if(tmp != null){
		Node newNode = new Node(value);
		newNode.setNext(tmp.getNext());
		tmp.setNext(newNode);
	    }
	}
	this.numItems += 1;
    }

    /**
     * Check if the index is valid
     * If it is not valid, throw an IndexOutOfBoundsException
     * Otherwise remove Node at given index position and return
     * its value
     */
    public int remove(int index)
    {
	if(index>this.numItems-1 || index < 0){
	    throw new IndexOutOfBoundsException("Index " + index + " is out of bounds.");
	}
	Node tmp = head;
	int data = -1;
	int i = 0;
	if (index == 0){
	    Node tmpHead = tmp.getNext();
	    data = tmp.getValue();
	    head.setNext(null);
	    head = tmpHead;
	} else if(index == this.numItems-1){
	    Node currNode = head;
	    for(int j = 0;j<index-1;j++){
		currNode = currNode.getNext();
	    }
	    data = tail.getValue();
	    currNode.setNext(null);
	    tail = currNode;
	} else {
	    while(tmp != null && i<index-1){
		tmp = tmp.getNext();
		i++;
	    }
	    if(tmp != null){
		data = tmp.getNext().getValue();
		Node tmp2 = tmp.getNext();
		tmp.setNext(tmp.getNext().getNext());
		tmp2.setNext(null);
	    }
	}
	this.numItems -= 1;
	if (numItems == 0){
	    head = null;
	    tail = null;
	}
	return data;
    }

    

    /**
     * No coding needed here
     * This is to help you with debugging
     */
    public String getListHead()
    {
	if (head != null)
	    return head.toString();
	
	return null;
    }

    /**
     * No coding needed here
     * This is to help you with debugging
     */
    public String getListTail()
    {
	if (tail != null)
	    return tail.toString();
	
	return null;
    }

    /**
     * No coding needed here
     * This is to help you with debugging
     */
    @Override
    public String toString()
    {
	if (size() == 0)
	    return "Nothing in list";
	
	String s = head.getValue() + "->";
	Node current = head.getNext();
	for (int i = 1; i < size(); i++)
	{
	    s = s + current.getValue() + "->";
	    current = current.getNext();
	}

	return s += "null";
    }
    
    @Override
    public Iterator<Integer> iterator()
    {	   
	return new LinkedListIter(head);
    }
}
