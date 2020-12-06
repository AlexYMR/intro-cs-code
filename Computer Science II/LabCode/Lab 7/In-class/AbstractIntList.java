/**
 * An abstract class defining a list ADT for storing ints
 * Includes iteration
 */
public abstract class AbstractIntList 
{
   /**
    * Represents the size of the list
    */
   protected int numItems;

   /**
    * Adds an item to the end of the list
    * @param item the item to be added
    */
   public abstract void add(int item);

   /**
    * Adds an item to the given location, shifting every item
    * at or beyond that location up one position.
    * @param index the location for the new item
    * @param item the item to be added
    */
   public abstract void add(int index, int item);

   /**
    * Removes the item at the given location, shifting
    * every item beyond that location down one position.
    * @param index the location of the item to remove
    * @return the removed item
    */
   public abstract int remove(int index);

   /**
    * Returns the item at the given location
    * @param index the location of the item to return
    */
   public abstract int get(int index);

   /**
    * Replaces the item at the given location
    * @param index the location of the item to replace
    * @param newItem the new value to put at the given index
    */
   public abstract void set(int index, int newItem);

   /**
    * Returns the number of items in the list
    * @return int, the number of items in the list
    */
   public int size()
   {
      return numItems;
   }

   /**
    * Returns true if the list is empty, false otherwise
    * @return boolean indicating whether the list is empty
    */
   public boolean isEmpty()
   {
      return numItems == 0;
   }

}
