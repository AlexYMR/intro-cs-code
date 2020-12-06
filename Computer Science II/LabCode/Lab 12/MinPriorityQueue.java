import java.util.ArrayList;

class MinPriorityQueue
{
   //Pararallel lists: each item and its priority appear in the same place in their respective lists
   ArrayList<Object> items;
   ArrayList<Double> priorities;

   /**
    * Creates an empty priority queue
    */
   public MinPriorityQueue()
   {
      items = new ArrayList<Object>();
      priorities = new ArrayList<Double>();
   }

   /**
    * @return the item with the minimum priority
    */
   public Object peek()
   {
      return items.get(0);
   }
   
   /**
    * Removes and returns the item with the minimum priority
    * @return the item associated with the minimum priority
    */
   public Object dequeue()
   {
       Object retObj = peek();
       Object lastObj = items.get(items.size()-1);
       
       items.set(0,lastObj);
       priorities.set(0,priorities.get(priorities.size()-1));
       items.remove(items.size()-1);
       priorities.remove(priorities.size()-1);
       //percolate down in order to position it correctly
       percolateDown(0);
       
       return retObj;
   }

   /**
    * Moves an item at the given index down the tree
    * As long as at least one of it's children is smaller
    * or we reach a leaf position.
    * @param idx the index of the item to move
    */
    protected void percolateDown(int idx)
    {
	//must check that the position of the first child < items.size()
	if (2*idx+1 < items.size()){
	    int LCindex = 2*idx+1;
	    int RCindex = LCindex + 1;
	    Double parentPriority = priorities.get(idx);
	    int smallestIdx = getMinChild(idx);
	    Double smallestPriority = priorities.get(smallestIdx);
	    if (parentPriority > smallestPriority){
		Object parentItem = items.get(idx);
		Object child = items.get(smallestIdx);
		items.set(idx,child);
		items.set(smallestIdx,parentItem);
		
		priorities.set(idx,smallestPriority);
		priorities.set(smallestIdx,parentPriority);
	    
		percolateDown(smallestIdx);
	    }
	}
    }

    /**
     * Returns index position of the child node
     * whose priority is smallest.
     * A given index may only have 1 or no children.
     */
    protected Integer getMinChild(int idx)
    {
	int LCindex = 2*idx+1;
	int RCindex = LCindex +1;
	int smallestIdx = LCindex;
	if (RCindex < items.size() && priorities.get(LCindex) > priorities.get(RCindex)){
	    smallestIdx = RCindex;
	}
	return smallestIdx;
    }
    
   /**
    * Inserts an item into the queue with the given priority
    * @param item the item to insert
    * @param priority the item's priority value
    */
   public void enqueue(Object item, Double priority)
   {
      //The last thing in the list, is the last thing in the bottom layer
      items.add(item);
      priorities.add(priority);

      percolateUp(items.size() - 1);
   }

   /**
    * Moves the item at the given index "up" the "tree" until its parent is smaller
    * @param idx the index of the item to move
    */
   protected void percolateUp(int idx)
   {
      int parent = (idx-1)/2; //if idx == 0, parent == 0, so priorities are the same!
      Double parentPriority = priorities.get(parent);
      Double currentPriority = priorities.get(idx);
      if(currentPriority < parentPriority)
      {
	 //Swap items
	 Object parentItem = items.get(parent);
	 Object currentItem = items.get(idx);
	 items.set(parent, currentItem);
	 items.set(idx, parentItem);

	 //Swap priorities
	 priorities.set(parent, currentPriority);
	 priorities.set(idx, parentPriority);

	 percolateUp(parent);
      }
   }

   /**
    * @return a string representation of the heap
    */
   public String toString()
   {
      String hStr = "";
      for(int i = 0; i < items.size()-1; i++)
      {
	 hStr += items.get(i) + " (" + priorities.get(i) + "), ";
      }
      if(items.size() > 0)
	 hStr += items.get(items.size()-1) + " (" + priorities.get(items.size()-1) + ")";

      return hStr;
   }
   
   public static void main(String [] args)
   {
      MinPriorityQueue queue = new MinPriorityQueue();

      double[] vals = {12,23,9,8,10,15};

      for(double v : vals)
      {
	 System.out.println("Enqueuing " + v);
	 queue.enqueue(v, v);
	 System.out.println(queue);
      }

      
      //System.out.println(min);
      for(double v: vals){
	  System.out.println("Dequeueing... (should've removed " + queue.peek() +")");
	  Object min = queue.dequeue();
	  System.out.println(queue);
      }
      // TEST DEQUEUE HERE WITH EXAMPLE FROM PROBLEM 1
   }
}
