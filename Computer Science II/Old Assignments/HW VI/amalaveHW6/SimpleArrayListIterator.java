/**
 * An iterator for array-backed lists that allows
 * bidirectional movement, reading, writing, cloning
 * and comparison.
 */
public class SimpleArrayListIterator extends SimpleListIterator
{
   /**
    * The list the iterator points to
    */
   private SimpleArrayList list;
   /**
    * The index the iterator is pointing to
    */
   private int index;

   /**
    * Create the iterator
    * @param list the list the iterator points to
    * @param index the index the iterator should point to
    */
   public SimpleArrayListIterator(SimpleArrayList list, int index)
   {
      this.list = list;
      this.index = index;
   }

   /**
    * @return the element after the last element returned
    */
   @Override
   public int next()
   {
      this.index++;
      return list.get(index);
   }   
   
   /**
    * @return the element before the last element returned
    */
   @Override
   public int previous()
   {
      this.index--;
      return list.get(index);
   }

   /**
    * Replaces the last element returned with the given item
    * @param item the item to put in the list
    */
   @Override
   public void set(int item)
   {
      list.set(index, item);
   }
   
   /**
    * @return true if there is an element after the last one returned (false otherwise)
    */
   @Override
   public boolean hasNext()
   {
      return this.index < this.list.size()-1;
   }

   /**
    * @return true if there is an element before the last one returned (false otherwise)
    */
   @Override
   public boolean hasPrevious()
   {
      return this.index > 0;
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
      else if (!(obj instanceof SimpleArrayListIterator))
	 return false;
	
      SimpleArrayListIterator iter2 = (SimpleArrayListIterator) obj;

      return list == iter2.list && index == iter2.index;
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
      else if(!(other instanceof SimpleArrayListIterator))
	 return false;
      
      SimpleArrayListIterator iter2 = (SimpleArrayListIterator) other;

      return list == iter2.list && index < iter2.index;
   }

   /**
    * @return a new iterator pointing to the same location as this
    */
   @Override
   public SimpleListIterator clone()
   {
      return new SimpleArrayListIterator(list, index);
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
