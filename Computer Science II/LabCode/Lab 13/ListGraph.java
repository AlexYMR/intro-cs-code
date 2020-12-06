import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Set;
import java.util.Scanner;

/**
 * Modified version from last week
 * to handle weighted graphs
 */
public class ListGraph
{
    private static int time;
    
    private HashMap<Vertex, HashMap<Vertex, Double>> vertList;

    public ListGraph()
    {
	vertList = new HashMap<Vertex, HashMap<Vertex, Double>>();
    }

    public void addVertex(Vertex v)
    {
	if (!vertList.containsKey(v))
	    vertList.put(v, new HashMap<Vertex, Double>());
    }

    public void addEdge(Vertex v1, Vertex v2, double weight)
    {
	addVertex(v1);
	addVertex(v2);

	HashMap<Vertex, Double> v1Edges = vertList.get(v1);
	HashMap<Vertex, Double> v2Edges = vertList.get(v2);

	
	v1Edges.put(v2, weight);
	v2Edges.put(v1, weight);
    }

    public Set<Vertex> getNeighbors(Vertex v1)
    {
	return vertList.get(v1).keySet();
    }

    public double getEdgeWeight(Vertex v1, Vertex v2)
    {
	return vertList.get(v1).get(v2);
    }
    
    public boolean isAdjacent(Vertex v1, Vertex v2)
    {
	return vertList.get(v1).containsKey(v2);
    }

    /**
     * Perform a DFS traversal on the graph starting at given vertex
     */
    public void DFS()
    {
	time = 0;
	for (int i = 0; i < vertList.size(); i++){
	    
	}
    }

    public void DFSVisit(Vertex u)
    {
	u.discovery = u.predecessor.discovery + 1;
	u.finish = -1;
	u.color = Vertex.GRAY;
    }
    
    /**
     * Perform basic BFS traversal of graph starting at Vertex V
     */
    public void BFS(Vertex start)
    {
	// BFS uses Queue data structure
	Queue queue = new LinkedList();
	queue.add(this.rootNode);
	rootNode.visited = true;
	while(!queue.isEmpty()) {
	    Node node = (Node)queue.remove();
	    Node child=null;
	    while((child=getUnvisitedChildNode(node))!=null) {
		child.visited=true;
		printNode(child);
		queue.add(child);
	    }
	}
	// Clear visited property of nodes
	clearNodes();
    }

    /**
     * Helper function to reset vertex states
     * Used in the main method between the 
     * Different calls to BFS/DFS
     * So you don't have to code it twice in your
     * implementation of those methods
     */
    private void resetVertices()
    {
	for (Vertex v : vertList.keySet())
	{
	    v.discovery = -1;
	    v.finish = -1;
	    v.color = Vertex.WHITE;
	    v.distance = Double.POSITIVE_INFINITY;
	    v.predecessor = null;
	}
    }
    
    public String toString()
    {
	String s = "";
	for (Vertex v : vertList.keySet())
	    s = s + v;

	return s;
    }

    public static void main(String [] args)
    {
	Vertex v0 = new Vertex(0);
	Vertex v1 = new Vertex(1);
	Vertex v2 = new Vertex(2);
	Vertex v3 = new Vertex(3);
	Vertex v4 = new Vertex(4);
	Vertex v5 = new Vertex(5);
	Vertex v6 = new Vertex(6);
	Vertex v7 = new Vertex(7);
	Vertex v8 = new Vertex(8);

	ListGraph g = new ListGraph();

	g.addEdge(v0, v1, 4.0);
	g.addEdge(v0, v7, 8.0);
	
	g.addEdge(v1, v2, 8.0);
	g.addEdge(v1, v7, 11.0);
	
	g.addEdge(v2, v3, 7.0);
	g.addEdge(v2, v5, 4.0);
	g.addEdge(v2, v8, 2.0);
	
	g.addEdge(v3, v4, 9.0);
	g.addEdge(v3, v5, 14.0);
	
	g.addEdge(v4, v5, 10.0);

	g.addEdge(v5, v6, 2.0);

	g.addEdge(v6, v7, 1.0);
	g.addEdge(v6, v8, 6.0);

	g.addEdge(v7, v8, 7.0);

	System.out.println("*** DFS ***");
	g.DFS();
	System.out.println(g);

	Scanner scan = new Scanner(System.in);
	System.out.println("\n\tDFS complete check vertex finish times");
	System.out.print("\tPress enter when done to perform BFS...");

	scan.nextLine();
	
	System.out.println("\n*** BFS ***");
	g.BFS(v0);
	System.out.println(g);
    }
}
