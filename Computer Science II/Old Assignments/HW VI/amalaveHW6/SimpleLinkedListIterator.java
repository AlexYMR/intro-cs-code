/**
 * An iterator for linked lists that allows
 * bidirectional movement, reading, writing, cloning
 * and comparison.
 */
public class SimpleLinkedListIterator extends SimpleListIterator
{
   /**
    * The list the iterator points to
    */
   private SimpleLinkedList list;
   /**
    * The node the iterator currently points to
    */
   private Node node;
   /**
    * The index the iterator is pointing to
    */
   private int index;
   
   /**
    * Create the iterator
    * @param list the list the iterator points to
    * @param node the node the list should point to
    * @param index the index the iterator should point to
    */
   public SimpleLinkedListIterator(SimpleLinkedList list, Node node, int index)
   {
      this.list = list;
      this.node = node;
      this.index = index;
   }

   /**
    * @return the element after the last element returned
    */
   @Override
   public int next()
   {
      this.index++;
      this.node = node.getNext();
      return node.getValue();
   }   
   
   /**
    * @return the element before the last element returned
    */
   @Override
   public int previous()
   {
      this.index--;
      this.node = node.getPrevious();
      return node.getValue();
   }

   /**
    * Replaces the last element returned with the given item
    * @param item the item to put in the list
    */
   @Override
   public void set(int item)
   {
      node.setValue(item);
   }
   
   /**
    * @return true if there is an element after the last one returned (false otherwise)
    */
   @Override
   public boolean hasNext()
   {
      return index < list.size() - 1;
   }

   /**
    * @return true if there is an element before the last one returned (false otherwise)
    */
   @Override
   public boolean hasPrevious()
   {
      return index > 0;
   }

   /**
    * @return true if the given object is an iterator pointing to the same location as this
    */
   @Override
   public boolean equals(Object obj)
   {
      if (obj == null)
	 return false;
      else if (this == obj)
	 return true;
      else if (!(obj instanceof SimpleLinkedListIterator))
	 return false;
	
      SimpleLinkedListIterator iter2 = (SimpleLinkedListIterator) obj;

      return list == iter2.list && node == iter2.node;
   }

   /**
    * @return true if the given iterator is pointing to a location before this
    */
   @Override
   public boolean before(SimpleListIterator other)
   {
      if(other == null)
	 return false;
      else if(this == other)
	 return false;
      else if(!(other instanceof SimpleLinkedListIterator))
	 return false;
      
      SimpleLinkedListIterator iter2 = (SimpleLinkedListIterator) other;

      return list == iter2.list && index < iter2.index;
   }

   /**
    * @return a new iterator pointing to the same location as this
    */
   @Override
   public SimpleListIterator clone()
   {
      return new SimpleLinkedListIterator(list, node, index);
   }
   
   /**
    * @return a string containing the index the iterator is pointing to
    */
   @Override
   public String toString()
   {
      return ""+index;
   }
}
