/**
 * Represents an array-backed list of ints
 */
public class SimpleArrayList extends SimpleList
{
   /**
    * The array that contains the data
    */
   private int[] arr;
   /**
    * The size of the array
    */
   private int capacity;

   /**
    * Create an empty array list with a capacity of 10
    */
   public SimpleArrayList()
   {
      this(10);
   }

   /**
    * Create an empty array with the given capacity
    * @param capacity the capacity of the list
    */
   public SimpleArrayList(int capacity)
   {
      this.capacity = capacity;
      arr = new int[capacity];      
   }

   /**
    * Creates a new, larger array to hold the data
    * and increases capacity
    */
   private void resize()
   {
      int[] newArr = new int[2*capacity];
      for(int i = 0; i < capacity; i++)
      {
	 newArr[i] = arr[i];
      }
      arr = newArr;
   }
   
   /**
    * Adds the given item to the list at the given index
    * @param index the location for the new item
    * @param val the value to add to the list
    */
   @Override
   public void add(int index, int val)
   {
      if(size == capacity)
      {
	 resize();
      }

      for(int i = size-1; i >= index; i--)
      {
	 arr[i+1] = arr[i];
      }
      arr[index] = val;
      size++;
   }

   /**
    * Gets the item at the given index
    * @param index the position of the item to get
    * @return the item at the given position
    */
   @Override
   public int get(int index)
   {
      return arr[index];
   }

   /**
    * Replaces the item at the given index with the given value
    * @param index the position in the list to replace
    * @param val the value to put in the list
    */
   @Override
   public void set(int index, int val)
   {
      arr[index] = val;
   }

   /**
    * Remove the item at the given position from the list
    * @return the removed item
    */
   @Override
   public int remove(int index)
   {
      int item = arr[index];
      for(int i = index; i < size-1; i++)
      {
	 arr[i] = arr[i+1];
      }
      size--;

      return item;
   }

   /**
    * @return an iterator positioned just before the first element
    */
   @Override
   public SimpleListIterator begin()
   {
      return new SimpleArrayListIterator(this, -1);
   }

   /**
    * @return an iterator positioned just after the last element
    */
   @Override
   public SimpleListIterator end()
   {
      return new SimpleArrayListIterator(this, size);
   }

   /**
    * @return a string representing the list
    */
   @Override
   public String toString()
   {
      String s = "[";
      for(int i = 0; i < size-1; i++)
      {
	 s += get(i) + ", ";
      }
      if(size > 0)
      {
	 s += get(size-1);
      }
      s += "]";
      return s;
   }
}
