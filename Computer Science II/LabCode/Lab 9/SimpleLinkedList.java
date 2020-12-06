class Node
{
   private int value;
   private Node previous;
   private Node next;
   
   public Node(int val)
   {
      value = val;
      previous = null;
      next = null;
   }

   public int getValue()
   {
      return value;
   }

   public void setValue(int val)
   {
      value = val;
   }
    
   public Node getNext()
   {
      return next;
   }

   public Node getPrevious()
   {
      return previous;
   }

   public void setNext(Node n)
   {
      next = n;
   }

   public void setPrevious(Node n)
   {
      previous = n;
   }
}

public class SimpleLinkedList extends SimpleList
{
   private Node sentinel;

   public SimpleLinkedList()
   {
      super();
	
      sentinel = new Node(0);
      sentinel.setNext(sentinel);
      sentinel.setPrevious(sentinel);
   }

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

   @Override
   public void add(int item)
   {
      add(size(), item);
   }

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

   @Override
   public int get(int index)
   {
      Node current = findNode(index);     
      int value = current.getValue();      
      return value;
   }

   @Override
   public void set(int index, int val)
   {
      Node current = findNode(index);
      current.setValue(val);
   }

   @Override
   public SimpleListIterator begin()
   {
      return new SimpleLinkedListIterator(this, sentinel, -1);
   }

   @Override
   public SimpleListIterator end()
   {
      return new SimpleLinkedListIterator(this, sentinel, size());
   }

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
