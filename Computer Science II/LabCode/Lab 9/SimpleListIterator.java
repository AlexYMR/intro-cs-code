public abstract class SimpleListIterator
{
   public abstract Integer next();
   
   public abstract Integer previous();

   public abstract void set(Integer item);
   
   public abstract boolean hasNext();

   public abstract boolean hasPrevious();

   @Override public abstract boolean equals(Object obj);

   public abstract boolean before(SimpleListIterator other);

   public abstract SimpleListIterator clone();
   
   @Override public abstract String toString();
}
