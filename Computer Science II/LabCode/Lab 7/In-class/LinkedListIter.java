import java.util.Iterator;

public class LinkedListIter implements Iterator<Integer>
{
    private Node currentNode = null;
    
    public LinkedListIter(Node node)
    {
	currentNode = node;
    }

    @Override
    public boolean hasNext() //is there another value in the LinkedList
    {
	return currentNode.getNext() != null;
    }

    @Override
    public Integer next() // returns next value
    {
	if (this.hasNext()){
	    //System.out.println(currentNode.getNext());
	    currentNode = currentNode.getNext();
	}
	return currentNode.getValue();
    }

    @Override
    public void remove()
    {
	throw new UnsupportedOperationException("Remove via iteration not supported");
    }
}

    
