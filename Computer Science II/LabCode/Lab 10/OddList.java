/**
 * An IntArrayList that only holds
 * odd numbers
 */

public class OddList extends IntArrayList
{
    public OddList()
    {
	super();
    }

    @Override
    public void set(int index, int item)
    {
	// Don't change if item is even
	if (item % 2 == 0)
	    return;

	super.set(index, item);
    }

    @Override
    public void add(int item)
    {
	// Don't add even numbers
	if (item % 2 == 0)
	    return;

	super.add(item);
    }

    @Override
    public void add(int index, int item)
    {
	// Don't add even number
	if (item % 2 == 0)
	    return;

	super.add(index, item);
    }

    public static void main(String [] args)
    {
	OddList odd = new OddList();
	for (int i = 0; i < 16; i++)
	{
	    odd.add(i);
	    System.out.println("Attempt to add " + i + " odd list: " + odd);
	    System.out.println();
	}
    }
}
