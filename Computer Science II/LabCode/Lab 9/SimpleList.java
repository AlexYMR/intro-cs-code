public abstract class SimpleList
{
   protected int size;
   
   public SimpleList()
   {
      size = 0;
   }

   public abstract void add(int index, int val);

   public void add(int val)
   {
      add(size, val);
   }

   public abstract int get(int index);

   public abstract void set(int index, int val);   

   public abstract int remove(int index);

   public int size()
   {
      return size;
   }

   public boolean isEmpty()
   {
      return size == 0;
   }

   public abstract SimpleListIterator begin();

   public abstract SimpleListIterator end();
}
