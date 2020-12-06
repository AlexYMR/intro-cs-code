public class SimpleArrayList extends SimpleList
{
   private int[] arr;
   private int capacity;
   
   public SimpleArrayList()
   {
      this(10);
   }

   public SimpleArrayList(int capacity)
   {
      this.capacity = capacity;
      arr = new int[capacity];      
   }

   private void resize()
   {
      int[] newArr = new int[2*capacity];
      for(int i = 0; i < capacity; i++)
      {
	 newArr[i] = arr[i];
      }
      arr = newArr;
   }
   
   @Override public void add(int index, int val)
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

   @Override public int get(int index)
   {
      return arr[index];
   }

   @Override public void set(int index, int val)
   {
      arr[index] = val;
   }

   @Override public int remove(int index)
   {
      int item = arr[index];
      for(int i = index; i < size-1; i++)
      {
	 arr[i] = arr[i+1];
      }
      size--;

      return item;
   }

   public SimpleArrayListIterator begin()
   {
      return new SimpleArrayListIterator(this, -1);
   }

   public SimpleArrayListIterator end()
   {
      return new SimpleArrayListIterator(this, size);
   }

   @Override public String toString()
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
