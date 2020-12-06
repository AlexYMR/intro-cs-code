import java.util.Iterator;
import java.util.Scanner;

public class TestLinkedList
{
    public static IntLinkedList list;

    public static void resetList()
    {
	list = new IntLinkedList();
    }

    public static void testSingleItemList()
    {
	resetList();
	System.out.println("Testing list operations with single item in it");
	
	list.add(0);
	System.out.println("*** add(0) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	System.out.println("\n*** get(0) -- the list should not be modified ***");
	System.out.println("\tget returns: " + list.get(0));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	System.out.println("\n*** set(0, 99) ***");
	list.set(0, 99);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
	
	System.out.println("\n*** remove(0) ***");
	System.out.println("remove(0) returned: " + list.remove(0));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	list.add(0, 0);
	System.out.println("*** add(0, 0) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	System.out.println("\n*** get(0) -- the list should not be modified ***");
	System.out.println("\tget returns: " + list.get(0));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	resetList();
	list.add(list.size(), 0);
	System.out.println("*** add(list.size(), 0) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	System.out.println("\n*** get(list.size() - 1) -- the list should not be modified ***");
	System.out.println("\tget returns: " + list.get(list.size() - 1));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
	
	System.out.println("\n*** set(list.size() - 1, 99) ***");
	list.set(list.size() - 1, 99);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
	
	System.out.println("\n*** remove(list.size() - 1) ***");
	System.out.println("remove(list.size() - 1) returned: " + list.remove(list.size() - 1));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

    }

    public static void testAppends()
    {
	System.out.println("Testing appends");
	resetList();
	System.out.println("\n*** Doing several add (append) with values 1 to 5 ***");
	for (int i = 1; i < 6; i++)
	    list.add(i);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	System.out.println("\n*** Doing several get operations ***");
	for (int i = 0; i < list.size(); i++)
	    System.out.println("\tget("+ i + ") => " + list.get(i));
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	resetList();
	System.out.println("\n*** Doing several add(list.size(), value) with values 1 to 5 ***");
	for (int i = 1; i < 6; i++)
	    list.add(list.size(), i);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
	
    }

    public static void testPrepends()
    {
	resetList();
	System.out.println("\n*** Doing several add(0, value) with values 1 to 5 ***");
	for (int i = 1; i < 6; i++)
	    list.add(0, i);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
    }

    public static void testInsert()
    {
	System.out.println("\nTesting add to middle of list");
	System.out.println("*** Doing add at index positions 6 and 9 of values 98 and 99 ***");
	resetList();
	for (int i = 0; i < 12; i++)
	    list.add(i*2);
	System.out.println("List before inserting anything: " + list);
	list.add(6, 98);
	list.add(9, 99);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
    }
    
    public static void testRemove()
    {
	System.out.println("\nTesting remove");
	resetList();
	for (int i = 0; i < 12; i++)
	    list.add(i*2);

	System.out.println("List before removing anything: " + list);
	
	int value = list.remove(0);
	System.out.println("\n*** remove(0) ***");
	System.out.println("\tRemove returned: " + value);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	value = list.remove(list.size() - 1);
	System.out.println("\n*** remove(list.size() - 1) ***");
	System.out.println("\tRemove returned: " + value);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	value = list.remove(1);
	System.out.println("\n*** remove(1) ***");
	System.out.println("\tRemove returned: " + value);
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
    }

    public static void testSet()
    {
	System.out.println("\nTesting set");
	resetList();
	for (int i = 0; i < 12; i++)
	    list.add(i*2);

	System.out.println("List before changing anything: " + list);
	
	list.set(0, 99);
	System.out.println("\n*** set(0, 99) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	list.set(list.size() - 1, 109);
	System.out.println("\n*** set(list.size() - 1, 109) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());

	list.set(7, 199 );
	System.out.println("\n*** set(7, 199) ***");
	System.out.println("\tList: " + list);
	System.out.println("\tSize: " + list.size());
	System.out.println("\tHead: " + list.getListHead());
	System.out.println("\tTail: " + list.getListTail());
    }

    public static void testErrorHandling()
    {
	resetList();
	System.out.println("\n*** Testing bounds checks for get/add/remove/set ***");
	try
	{
	    list.get(-1);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tget(-1)...OK");
	}
	try
	{
	    list.get(list.size());
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tget(list.size())...OK");
	}
	try
	{
	    list.add(-1, 99);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tadd(-1, 99)...OK");
	}
	try
	{
	    list.add(list.size() + 1, 99);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tadd(list.size() + 1, 99)...OK");
	}
	try
	{
	    list.remove(-1);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tremove(-1)...OK");
	}
	try
	{
	    list.remove(list.size());
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tremove(list.size())...OK");
	}
	try
	{
	    list.set(-1, 99);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tset(-1)...OK");
	}
	try
	{
	    list.set(list.size(), 99);
	}
	catch (IndexOutOfBoundsException e)
	{
	    System.out.println("\tset(list.size(), 99)...OK");
	}
    }

    public static void testIterator()
    {
	resetList();
	for (int i = 0; i < 12; i++)
	    list.add(i*2);

	System.out.println("List before iterating: " + list);
	System.out.println("Using for-each style loop");
	for(int x : list)
	    System.out.println("Value: " + x);

	System.out.println("\nUsing while loop with Iterator object");
	Iterator<Integer> iter = list.iterator();
	while(iter.hasNext())
	    System.out.println("Value: " + iter.next());
    }
	
    public static void promptContinue()
    {
	System.out.println("\nPress Enter to continue...");
	Scanner scan = new Scanner(System.in);
	scan.nextLine();
    }
    
    public static void main(String [] args)
    {
	testSingleItemList();
	promptContinue();
	
	testAppends();
	promptContinue();
	
	testPrepends();
	promptContinue();
	
	testInsert();
	promptContinue();
	
	testRemove();
	promptContinue();
	
	testSet();
	promptContinue();
	
	testErrorHandling();
	promptContinue();
	
	testIterator();
    }
}
