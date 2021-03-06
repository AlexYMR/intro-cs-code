import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Iterator;

/**
 * Implementation of BinaryTree without the use
 * of Nodes
 */
class BinaryTree implements Iterable<String>
{
    private Object data;
    private BinaryTree leftChild;
    private BinaryTree rightChild;

    // Special variables to help with tree drawing to a file
    // You can ignore these
    private static int gapCount = 0;
    private static final String gapNode = "[style=\"invis\"];\n";
    private static final String gapEdge = "[weight=100, style=\"invis\"];\n";

    public BinaryTree(Object value)
    {
	data = value;
	leftChild = null;
	rightChild = null;
    }

    public Object getRootValue()
    {
	return data;
    }

    public void setRootValue(Object value)
    {
	data = value;
    }
	
    public void setLeftChild(BinaryTree t)
    {
	leftChild = t;
    }

    public BinaryTree getLeftChild()
    {
	return leftChild;
    }

    public void setRightChild(BinaryTree t)
    {
	rightChild = t;
    }

    public BinaryTree getRightChild()
    {
	return rightChild;
    }

    public boolean isLeaf()
    {
	return (leftChild == null && rightChild == null);
    }

    public int countLeaves(){
        if (this.leftChild == null && this.rightChild == null)
            return 1;
        else
            return getLeafCount(this.left) + getLeafCount(this.right);
    }

    public int height()
    {
	if (isLeaf())
	    return 1;
	else if (leftChild != null && rightChild != null)
	    return Math.max(leftChild.height(), rightChild.height()) + 1;
	else if (leftChild != null)
	    return leftChild.height() + 1;
	else
	    return rightChild.height() + 1;
    }

    public void preOrderPrint()
    {
	System.out.println("Node contains: " + data);
	if (leftChild != null)
	    leftChild.preOrderPrint();
	if (rightChild != null)
	    rightChild.preOrderPrint();
    }

    public void inOrderPrint()
    {
	if (leftChild != null)
	    leftChild.inOrderPrint();
	System.out.println("Node contains: " + data);
	if (rightChild != null)
	    rightChild.inOrderPrint();
    }

    public void postOrderPrint()
    {
	if (leftChild != null)
	    leftChild.postOrderPrint();
	if (rightChild != null)
	    rightChild.postOrderPrint();

	System.out.println("Node contains: " + data);
    }

    public Iterator<String> iterator()
    {
	return new BreadthFirstIter(this);
    }

    /******************************************************************/
    /**      NEXT TWO METHODS ARE JUST TO DRAW THE TREE TO A PDF     **/
    /******************************************************************/
    
    /**
     * Creates a text file for use with Graphviz's<br>
     * dot and dotty programs.<br><br>
     * Once the file is created you can create a pdf with an image of<br>
     * your tree by typing the following at the command-line:<br>
     * dot -Tpdf -o outputFile.pdf inputFile<br>
     * replacing outputFile.pdf with the name you wish to use<br>
     * for the output file and replacing inputFile with the name of<br>
     * the input file you generated.
     *
     * @param fileName
     */
    public void drawTree(String fileName)
    {
	BufferedWriter bw = null;

	try
	{
	    FileWriter fw = new FileWriter(fileName);
	    bw = new BufferedWriter(fw);

	    bw.write("graph BinaryTree {\n");

	    writeDot(this, bw);

	    bw.write("}\n");

	    bw.close();
	    fw.close();
	}
	catch (IOException ioe)
	{
	    System.out.println("Error opening file: " + ioe);
	}
    }

    private void writeDot(BinaryTree bt, BufferedWriter bw) throws IOException
    {
	String nodeID = "node" + ((Integer)bt.hashCode()).toString();
	bw.write("\t" + nodeID + "[label=\"" + bt.data.toString() + "\"];\n");

	String leftID = null;
	String rightID = null;
	
	if (bt.leftChild != null)	
	    leftID = "node" + ((Integer)bt.leftChild.hashCode()).toString();
	if (bt.rightChild != null)
	    rightID = "node" + ((Integer)bt.rightChild.hashCode()).toString();

	// Two children 
	if (bt.leftChild != null && bt.rightChild != null)
	{
	    gapCount++;
	    String gapID = "nodeg" + new Integer(gapCount).toString();
	    String gNode = gapID + gapNode;

	    // Write the nodes left, gap, right
	    bw.write("\t" + leftID + ";\n");
	    bw.write("\t" + gNode);
	    bw.write("\t" + rightID + ";\n");

	    // Write the edges left, gap, right
	    bw.write("\t" + nodeID + " -- " + leftID + ";\n");
	    bw.write("\t" + nodeID + " -- " + gapID + gapEdge);
	    bw.write("\t" + nodeID + " -- " + rightID + ";\n");

	    // Recurse left and right subtrees
	    writeDot(bt.leftChild, bw);
	    writeDot(bt.rightChild, bw);
	}
	else if (bt.leftChild != null)
	{
	    gapCount++;
	    String gapID = "nodeg" + new Integer(gapCount).toString();
	    String gNode = gapID + gapNode;

	    // Write the nodes left, gap
	    bw.write("\t" + leftID + ";\n");
	    bw.write("\t" + gNode);

	    // Write the edges left, gap
	    bw.write("\t" + nodeID + " -- " + leftID + ";\n");
	    bw.write("\t" + nodeID + " -- " + gapID + gapEdge);

	    // Recurse left subtree
	    writeDot(bt.leftChild, bw);   
	}
	else if (bt.rightChild != null)
	{
	    gapCount++;
	    String gapID = "nodeg" + new Integer(gapCount).toString();
	    String gNode = gapID + gapNode;

	    // Write the nodes gap, right
	    bw.write("\t" + gNode);
	    bw.write("\t" + rightID + ";\n");

	    // Write the edges gap, right
	    bw.write("\t" + nodeID + " -- " + gapID + gapEdge);
	    bw.write("\t" + nodeID + " -- " + rightID + ";\n");

	    // Recurse right subtree
	    writeDot(bt.rightChild, bw);
	}
    }

    public static void main(String [] args)
    {
	BinaryTree t0 = new BinaryTree(new String("A"));
	BinaryTree t1 = new BinaryTree(new String("B"));
	BinaryTree t2 = new BinaryTree(new String("C"));
	BinaryTree t3 = new BinaryTree(new String("D"));
	BinaryTree t4 = new BinaryTree(new String("E"));
	BinaryTree t5 = new BinaryTree(new String("/"));
	BinaryTree t6 = new BinaryTree(new String("+"));
	BinaryTree t7 = new BinaryTree(new String("*"));
	BinaryTree t8 = new BinaryTree(new String("+"));

	t5.setLeftChild(t2);
	t5.setRightChild(t3);

	t6.setLeftChild(t1);
	t6.setRightChild(t5);

	t7.setLeftChild(t0);
	t7.setRightChild(t6);

	t8.setLeftChild(t7);
	t8.setRightChild(t4);
	
	System.out.println("Number of leaves: " + t8.countLeaves());
	
	System.out.println("Doing a Breadth-First iteration");
	for (String str : t8)
	System.out.println("Node: " + str);
    }
}

    

    

    
