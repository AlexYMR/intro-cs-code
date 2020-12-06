
public class IntArrayList extends AbstractIntList
{
    // The capacity of the array (i.e., the number of items it can hold)
    protected int arrayCapacity;
    protected int [] items;

    /**
     * Create an IntArrayList with defualt capacity of 10
     */
    public IntArrayList()
    {
	// Default initial capacity is 10
	this(10);
    }

    /**
     * Create an IntArrayList with capacity specified by 
     * initialCapacity parameter.
     *
     * @param initialCapactiy, the initial number of items the
     *                         IntArrayList (and the underlying array)
     *                         can hold
     */
    public IntArrayList(int initialCapacity)
    {
	super();

	arrayCapacity = initialCapacity;
	int [] items = new int[arrayCapacity];
    }

    /**
     * Resizes array when it gets full
     */
    private void resize()
    {
	// Update capacity
	arrayCapacity = (arrayCapacity * 3) / 2 + 1;
	// Create temporary array and fill it
	// with items in current array
	int[] tmp =  new int[arrayCapacity];
	for (int i = 0; i < items.length; i++){
	    tmp[i] = items[i];
	}
	// Re-assign the current array to be bigger array
	items = tmp;
    }

    /**
     * Return integer at given index position in the list
     *
     * @param index, index position within list
     *
     * @return int, the integer value stored at the given index position
     */
    public int get(int index)
    {
	return items[index];
    }

    /**
     * The the integer at the given index position to some new value
     *
     * @param index, Position in the list
     * @param item,  The updated value
     */
    public void set(int index, int item)
    {
	items[index] = item;
    }
    
    /**
     * Insterts item at end of list
     *
     * @param item, value to be appended
     */
    public void add(int item)
    {
	add(size(), item);
    }

    /**
     * Inserts item at specific location in list
     *
     * @param index, location to insert new item
     * @param item,  value to be added to list
     */
    public void add(int index, int item)
    {
	if (numItems == arrayCapacity)
	    resize();

	// Shift right
	for (int i = numItems - 1; i >= index; i--)
	    items[i+1] = items[i];

	items[index] = item;
	numItems++;
    }

    public int remove(int index)
    {
	// Save the return value
	int item = items[index];

	// Shift items left
	for (int i = index + 1; i < numItems; i++)
	    items[i-1] = items[i];

	numItems--;
	
	return item;
    }

    /**
     * Prints the list (not the array)
     * in a 'pretty' way
     *
     * @return String, representation of the list
     */
    @Override
    public String toString()
    {
	if (size() == 0)
	    return "[ ]";
	
	String output = "[";
	for (int i = 0; i < numItems - 1; i++)
	    output = output + items[i] + ", ";

	output = output + items[numItems - 1] + "]";
	return output;
    }
}
