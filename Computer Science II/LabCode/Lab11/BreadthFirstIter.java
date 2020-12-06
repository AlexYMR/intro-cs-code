import java.util.LinkedList;
import java.util.Iterator;

public class BreadthFirstIter implements Iterator<String>
{
    private LinkedList<BinaryTree> q;
    
    public BreadthFirstIter(BinaryTree node)
    {
	q = new LinkedList<BinaryTree>();
	q.addFirst(node);
    }

    @Override
    public boolean hasNext()
    {
	return (q.size() != 0);
    }

    /**
     * In addition to anything  else you 
     * do in this method, make sure
     * when you get the value of the current
     * node (i.e., BinaryTree) you convert it
     * to a String (it's an Object type)
     */
    @Override
    public String next()
    {
	BinaryTree last = q.removeLast();
	
	BinaryTree left = last.getLeftChild();
	BinaryTree right = last.getRightChild();
	
	if (left != null){
	    q.addFirst(left);
	}
	if (right != null){
	    q.addFirst(right);
	}
	return last.getRootValue().toString();
	//System.out.println("ROOT: " + val);
    }

    @Override
    public void remove()
    {
	throw new UnsupportedOperationException("Can't do this");
    }
}
