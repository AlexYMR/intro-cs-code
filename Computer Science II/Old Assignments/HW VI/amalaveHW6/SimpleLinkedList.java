/**
 * Represents a node of a linked list
 */
class Node
{
   /**
    * The value contained by the node
    */
   private int value;
   /**
    * The previous node in the list
    */
   private Node previous;
   /**
    * The next node in the list
    */
   private Node next;

   /**
    * Creates a node containing the given value
    * (and null as the next and previous)
    * @param val the value the node should contain
    */
   public Node(int val)
   {
      value = val;
      previous = null;
      next = null;
   }

   /**
    * @return the value contained within the node
    */
   public int getValue()
   {
      return value;
   }

   /**
    * Replace the value in the node with the given value
    * @param val the new value for the node
    */
   public void setValue(int val)
   {
      value = val;
   }

   /**
    * @return the next node in the list
    */
   public Node getNext()
   {
      return next;
   }

   /**
    * @return the previous node in the list
    */
   public Node getPrevious()
   {
      return previous;
   }

   /**
    * Set the node's reference to the next node in the list
    * @param the new next node
    */
   public void setNext(Node n)
   {
      next = n;
   }

   /**
    * Set the node's reference to the previous node in the list
    * @param the new previous node
    */
   public void setPrevious(Node n)
   {
      previous = n;
   }
}

/**
 * Represents a linked list of ints
 */
public class SimpleLinkedList extends SimpleList
{
   /**
    * The node that represents the ends of the list
    */
   private Node sentinel;

   /**
    * Create an empty list
    */
   public SimpleLinkedList()
   {
      super();
	
      sentinel = new Node(0);
      sentinel.setNext(sentinel);
      sentinel.setPrevious(sentinel);
   }

   /**
    * Finds the node at the given index
    * @param index the index of the node to get
    * @return the node at the given index
    */
   private Node findNode(int index)
   {
      Node current = sentinel;
      if(index < size()/2)
      {
	 for(int i = -1; i < index; i++)
	 {
	    current = current.getNext();
	 }
      }
      else
      {      
	 for (int i = size(); i > index; i--)
	 {
	    current = current.getPrevious();
	 }
      }
      return current;
   }

   /**
    * Adds the given item to the end of the list
    * @param val the value to add to the list
    */
   @Override
   public void add(int item)
   {
      add(size(), item);
   }

   /**
    * Adds the given item to the list at the given index
    * @param index the location for the new item
    * @param val the value to add to the list
    */
   @Override
   public void add(int index, int item)
   {
      Node n = new Node(item);
      Node prev = findNode(index-1);

      n.setPrevious(prev);
      n.setNext(prev.getNext());
      prev.getNext().setPrevious(n);
      prev.setNext(n);

      size++;
   }

   /**
    * Remove the item at the given position from the list
    * @return the removed item
    */
   @Override
   public int remove(int index)
   {
      Node current = findNode(index);     
      int value = current.getValue();
      
      Node next = current.getNext();
      Node prev = current.getPrevious();
      
      current.getPrevious().setNext(next);
      current.getNext().setPrevious(prev);

      size--;

      return value;
   }

   /**
    * Gets the item at the given index
    * @param index the position of the item to get
    * @return the item at the given position
    */
   @Override
   public int get(int index)
   {
      Node current = findNode(index);     
      int value = current.getValue();      
      return value;
   }

   /**
    * Replaces the item at the given index with the given value
    * @param index the position in the list to replace
    * @param val the value to put in the list
    */
   @Override
   public void set(int index, int val)
   {
      Node current = findNode(index);
      current.setValue(val);
   }

   /**
    * @return an iterator positioned just before the first element
    */
   @Override
   public SimpleListIterator begin()
   {
      return new SimpleLinkedListIterator(this, sentinel, -1);
   }

   /**
    * @return an iterator positioned just after the last element
    */
   @Override
   public SimpleListIterator end()
   {
      return new SimpleLinkedListIterator(this, sentinel, size());
   }

   /**
    * @return a string representing the list
    */
   @Override
   public String toString()
   {
      String s = "";
      for(int i = 0; i < size-1; i++)
      {
	 s += get(i) + " <-> ";
      }
      if(size > 0)
      {
	 s += get(size-1);
      }
      s += "";
      return s;
   }
}
