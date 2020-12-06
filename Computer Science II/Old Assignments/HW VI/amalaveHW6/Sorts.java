/* 
 * Sorts.java
 * Contains the class Sorts, which has two sorting methods (selection and insertion)
 * Part of Homework 6, Problems 1 & 2
 */

/**
 * Contains several methods for sorting lists using iterators
 */
public class Sorts
{
   /**
    * Performs the Selection Sort algorithm on the list
    * that created the given iterator
    * @param begin an iterator positioned just before the first element
    */
    public static void selectionSort(SimpleListIterator begin)
    {
       SimpleListIterator iter = begin.clone();
       while(iter.hasNext()){
	   int val1 = iter.next();
	   SimpleListIterator iter2 = iter.clone();
	   SimpleListIterator iter3 = iter2.clone();
	   int min = val1;
	   boolean minChanged = false;
	   while(iter2.hasNext()){
	       int val2 = iter2.next();
	       if (min > val2){
		   iter3 = iter2.clone();
		   min = val2;
		   minChanged = true;
	       }
	   }
	   if (minChanged){
	       iter.set(min);
	       iter3.set(val1);
	   }
       }
   }

   /**
    * Performs the Insertion Sort algorithm on the list
    * that created the given iterator
    * @param begin an iterator positioned just before the first element
    */
    public static void insertionSort(SimpleListIterator begin)
   {
       SimpleListIterator iter = begin.clone();
       while(iter.hasNext()){
	   int val1 = iter.next();
	   SimpleListIterator iter2 = iter.clone();
	   int difference = 0; //difference between iter's next and iter2's previous that's < iter's next
	   int currentVal = val1; //cached value used to shift all other values forwards
	   int val2 = val1;
	   while(iter2.hasPrevious()){
	       val2 = iter2.previous();
	       if (val1 < val2){
		   currentVal = val2;
		   difference += 1;
	       }
	       else{
		   break;
	       }
	   }
	   if (difference > 0 && val1 < val2){
	       iter2.set(val1);
	   }
	   else if (difference > 0 && val1 >= val2){ // >= in case the smallest number appears twice in the list
	       iter2.next();
	       iter2.set(val1);
	   }
	   while(difference > 0){
	       int temp = iter2.next();
	       iter2.set(currentVal);
	       currentVal = temp;
	       difference--;
	   }
       }
   }
   
   public static void main(String[] args)
   {
      String[] sortLabels = {"---Selection Sort---", "---Insertion Sort---"};
      String[] listLabels = {"Array-Backed List", "Linked List"};
      
      for(int i = 0; i < 2; i++)
      {	 
	 System.out.println(sortLabels[i]);
	 for(int j = 0; j < 2; j++)
	 {
	    System.out.println(listLabels[j]);
	    SimpleList list;
	    if(j == 0)
	       list = new SimpleArrayList();
	    else
	       list = new SimpleLinkedList();

	    for(int k = 0; k < args.length; k++)
	    {
	       list.add(Integer.parseInt(args[k]));
	    }
	    System.out.println("Before: " + list);
	    if(i == 0)
	       selectionSort(list.begin());
	    else if(i == 1)
		insertionSort(list.begin());
	    System.out.println("After: " + list + "\n");
	 }
      }
   }
}
