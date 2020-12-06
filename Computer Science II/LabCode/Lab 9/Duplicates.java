
public class Duplicates
{
   /**
    * Returns true if the underlying list contains duplicates (false otherwise)
    * @param begin an iterator positioned just before the first element
    */
   public static boolean duplicateCheck(SimpleListIterator begin)
   {
       SimpleListIterator iter = begin.clone();
       while(iter.hasNext()){
	   int val = iter.next();
	   SimpleListIterator iter2 = iter.clone();
	   while(iter2.hasNext()){
	       if (val == iter2.next()){
		   return true;
	       }
	   }
       }
       return false;
   }
   
   public static void main(String[] args)
   {
      SimpleArrayList aList = new SimpleArrayList();
      SimpleLinkedList bList = new SimpleLinkedList();
      SimpleArrayList cList = new SimpleArrayList();
      SimpleLinkedList dList = new SimpleLinkedList();
      for(int k = 0; k < 10; k++)
      {
	  aList.add(k);
	  bList.add(k);
	  cList.add(k);
	  dList.add(k);
      }

      // cList and dList will contain duplicates
      cList.add(4);
      dList.add(4);

      boolean passedTest = true;
      if (duplicateCheck(aList.begin()))
      {
	  System.out.println("Duplicates found in aList, but there are no duplicates");
	  passedTest = false;
      }
      
      if (duplicateCheck(bList.begin()))
      {
	  System.out.println("Duplicates found in bList, but there are no duplicates");
	  passedTest = false;
      }
      
      if (!duplicateCheck(cList.begin()))
      {
	  System.out.println("Duplicates not found in cList, but there are duplicates");
	  passedTest = false;
      }
      
      if (!duplicateCheck(dList.begin()))
      {
	  System.out.println("Duplicates not found in dList, but there are duplicates");
	  passedTest = false;
      }

      if (passedTest)
	  System.out.println("*** TESTS PASSED ***");
      else
	  System.out.println("*** ONE OR MORE TESTS FAILED ***");
      
   }
}
