/**
 * An abstract class representing a list of ints
 */
public abstract class SimpleList
{
   /**
    * The size of the list
    */
   protected int size;

   /**
    * Creates an empty list (size 0)
    */
   public SimpleList()
   {
      size = 0;
   }

   /**
    * Adds the given item to the list at the given index
    * @param index the location for the new item
    * @param val the value to add to the list
    */
   public abstract void add(int index, int val);
   
   /**
    * Adds the given item to the end of the list
    * @param val the value to add to the list
    */
   public void add(int val)
   {
      add(size, val);
   }

   /**
    * Gets the item at the given index
    * @param index the position of the item to get
    * @return the item at the given position
    */
   public abstract int get(int index);

   /**
    * Replaces the item at the given index with the given value
    * @param index the position in the list to replace
    * @param val the value to put in the list
    */
   public abstract void set(int index, int val);   

   /**
    * Remove the item at the given position from the list
    * @return the removed item
    */
   public abstract int remove(int index);

   /**
    * @return the size of the list
    */
   public int size()
   {
      return size;
   }

   /**
    * @return true if the list is empty (false otherwise)
    */
   public boolean isEmpty()
   {
      return size == 0;
   }

   /**
    * @return an iterator positioned just before the first element
    */
   public abstract SimpleListIterator begin();

   /**
    * @return an iterator positioned just after the last element
    */
   public abstract SimpleListIterator end();
}
