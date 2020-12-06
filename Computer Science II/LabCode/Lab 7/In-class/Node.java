/**
 * Basic node class
 * 
 * value is the data held by the Node
 * next is the Node linked as next to this one
 */
class Node
{
    private int value;
    private Node next;

    public Node(int val)
    {
	value = val;
	next = null;
    }

    public int getValue()
    {
	return value;
    }
    
    public Node getNext()
    {
	return next;
    }

    public void setValue(int val)
    {
	value = val;
    }

    public void setNext(Node n)
    {
	next = n;
    }

    @Override
    public String toString()
    {
	return Integer.toString(value);
    }
}
