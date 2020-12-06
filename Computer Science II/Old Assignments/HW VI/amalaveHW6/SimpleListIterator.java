/**
 * An abstract iterator for lists that allows
 * bidirectional movement, reading, writing, cloning
 * and comparison.
 */
public abstract class SimpleListIterator
{
   /**
    * @return the element after the last element returned
    */
   public abstract int next();
   
   /**
    * @return the element before the last element returned
    */
   public abstract int previous();

   /**
    * Replaces the last element returned with the given item
    * @param item the item to put in the list
    */
   public abstract void set(int item);

   /**
    * @return true if there is an element after the last one returned (false otherwise)
    */
   public abstract boolean hasNext();

   /**
    * @return true if there is an element before the last one returned (false otherwise)
    */
   public abstract boolean hasPrevious();

   /**
    * @return true if the given object is an iterator pointing to the same location as this
    */
   @Override public abstract boolean equals(Object obj);

   /**
    * @return true if the given iterator is pointing to a location before this
    */
   public abstract boolean before(SimpleListIterator other);

   /**
    * @return a new iterator pointing to the same location as this
    */
   public abstract SimpleListIterator clone();

   /**
    * @return a string containing the index the iterator is pointing to
    */
   @Override public abstract String toString();
}
