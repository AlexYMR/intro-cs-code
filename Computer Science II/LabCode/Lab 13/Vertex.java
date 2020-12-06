/**
 * Simple Vertex class
 * For use in Graphs to facilitate
 * coding for BFS/DFS
 *
 * Other than the label, all instance variables
 * are public just to make coding faster
 *
 */
public class Vertex
{
    public static final String WHITE = "white";
    public static final String BLACK = "black";
    public static final String GRAY = "gray";
    
    private Integer label;
    
    public int discovery;
    public int finish;

    public String color;
    
    public double distance;

    public Vertex predecessor;
    
    public Vertex (Integer label)
    {
	this.label = label;
	
	discovery = -1;
	finish = -1;

	color = Vertex.WHITE;
	
	distance = Double.POSITIVE_INFINITY;

	predecessor = null;
    }

    @Override
    public int hashCode()
    {
	return label.hashCode();
    }

    @Override
    public String toString()
    {
	String s = "Vertex: " + label + "\n";
	s = s + "\tDiscovery: " + discovery + "\n";
	s = s + "\tFinish: " + finish + "\n";
	s = s + "\tDistance: " + distance + "\n";
	s = s + "\tPredecessor: ";
	if (predecessor != null)
	    s = s + predecessor.label.toString();
	else
	    s = s + "null";

	s = s + "\n";

	return s;
    }
	
}
