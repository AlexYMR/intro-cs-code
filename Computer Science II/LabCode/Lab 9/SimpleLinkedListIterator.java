public class SimpleLinkedListIterator extends SimpleListIterator
{
   private SimpleLinkedList list;
   private Node node;
   private int index;
   
   public SimpleLinkedListIterator(SimpleLinkedList list, Node node, int index)
   {
      this.list = list;
      this.node = node;
      this.index = index;
   }

   @Override public Integer next()
   {
      this.index++;
      this.node = node.getNext();
      return node.getValue();
   }   
   
   @Override public Integer previous()
   {
      this.index--;
      this.node = node.getPrevious();
      return node.getValue();
   }

   @Override public void set(Integer item)
   {
      node.setValue(item);
   }
   
   @Override public boolean hasNext()
   {
      return index < list.size() - 1;
   }

   @Override public boolean hasPrevious()
   {
      return index > 0;
   }

   @Override public boolean equals(Object obj)
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

   @Override public boolean before(SimpleListIterator other)
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

   @Override public SimpleListIterator clone()
   {
      return new SimpleLinkedListIterator(list, node, index);
   }
   
   @Override public String toString()
   {
      return ""+index;
   }
}
