
public class Bitonic
{
    public static int linearFindMax(int [] aList)
    {
	int max = aList[0];
	int maxIndex = 0;
	for (int i = 0; i < aList.length; i++){
	    if (aList[i] >= max){
		max = aList[i];
		maxIndex = i;
	    }
	}
	return maxIndex;
    }
    
    public static int binaryFindMax(int[] aList, int s_index, int f_index){
	if (s_index == f_index)
         return s_index;
       if ((f_index == s_index + 1) && aList[s_index] >= aList[f_index])
          return s_index;
       if ((f_index == s_index + 1) && aList[s_index] < aList[f_index])
          return f_index;
       int mid = (s_index + f_index)/2;   
       if ( aList[mid] > aList[mid + 1] && aList[mid] > aList[mid - 1])
          return mid;
       if (aList[mid] > aList[mid + 1] && aList[mid] < aList[mid - 1])
         return binaryFindMax(aList, s_index, mid-1);
       else
         return binaryFindMax(aList, mid + 1, f_index);
    }
 
    public static void main(String [] args)
    {
	int [] list1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int [] list2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int [] list3 = {-1, 0, 1, 2, 3, 1, 2, 0, -1, -2};

	boolean testFailed = false;
	
	int test1 = linearFindMax(list1);
	int test2 = linearFindMax(list2);
	int test3 = linearFindMax(list3);
	if (test1 != 0)
	{
	    System.out.println("linearFindMax on list 1 returned " + test1 + " but should have returned 0");
	    testFailed = true;
	}
	if (test2 != 9)
	{
	    System.out.println("linearFindMax on list 2 returned " + test2 + " but should have returned 9");
	    testFailed = true;
	}
	if (test3 != 4)
	{
	    System.out.println("linearFindMax on list 3 returned " + test3 + " but should have returned 4");
	    testFailed = true;
	}

	if (testFailed)
	    System.out.println("*** THERE WAS ONE OR MORE PROBLEMS WITH linearFindMax ***");
	else
	    System.out.println("*** linearFindMax PASSED ***");

	// binaryFindMax tests
	testFailed = false;
	
	test1 = binaryFindMax(list1,0,list1.length-1);
	test2 = binaryFindMax(list2,0,list2.length-1);
	test3 = binaryFindMax(list3,0,list3.length-1);
	if (test1 != 0)
	{
	    System.out.println("binaryFindMax on list 1 returned " + test1 + " but should have returned 0");
	    testFailed = true;
	}
	if (test2 != 9)
	{
	    System.out.println("binaryFindMax on list 2 returned " + test2 + " but should have returned 9");
	    testFailed = true;
	}
	if (test3 != 4)
	{
	    System.out.println("binaryFindMax on list 3 returned " + test3 + " but should have returned 4");
	    testFailed = true;
	}

	if (testFailed)
	    System.out.println("*** THERE WAS ONE OR MORE PROBLEMS WITH binaryFindMax ***");
	else
	    System.out.println("*** binaryFindMax PASSED ***");
    }
}
    
