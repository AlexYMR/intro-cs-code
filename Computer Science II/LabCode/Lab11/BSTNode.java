/**
 * A node class for Binary Search trees<br>
 *
 * @see BinarySearchTree
 */
public class BSTNode
{
    public int value;
    
    public BSTNode left;
    public BSTNode right;
    public BSTNode parent;
    
    public BSTNode(int val)
    {
	value = val;

	left = null;
	right = null;
	parent = null;
    }
}
