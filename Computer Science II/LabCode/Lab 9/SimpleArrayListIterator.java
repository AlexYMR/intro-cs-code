public class SimpleArrayListIterator extends SimpleListIterator
{
   private SimpleArrayList list;
   private int index;
   
   public SimpleArrayListIterator(SimpleArrayList list, int index)
   {
      this.list = list;
      this.index = index;
   }

   @Override public Integer next()
   {
      this.index++;
      return list.get(index);
   }   
   
   @Override public Integer previous()
   {
      this.index--;
      return list.get(index);
   }

   @Override public void set(Integer item)
   {
      list.set(index, item);
   }
   
   @Override public boolean hasNext()
   {
      return this.index < this.list.size()-1;
   }

   @Override public boolean hasPrevious()
   {
      return this.index > 0;
   }

   @Override public boolean equals(Object obj)
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

   @Override public boolean before(SimpleListIterator other)
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

   @Override public SimpleListIterator clone()
   {
      return new SimpleArrayListIterator(list, index);
   }
   
   @Override public String toString()
   {
      return ""+index;
   }
}
