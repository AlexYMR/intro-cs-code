import java.util.Random;

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
	items = new int[10];
	arrayCapacity = 10;
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
	items = new int[initialCapacity];
	arrayCapacity = 10;
    }

    /**
     * Resizes array when it gets full
     */
    private void resize()
    {
	if (this.numItems == arrayCapacity){
	    int[] temporaryArray = new int[(arrayCapacity*3)/2+1];
	    for(int i = 0; i<items.length;i++){
		temporaryArray[i] = items[i];
	    }
	    items = temporaryArray;
	    arrayCapacity = temporaryArray.length;
	}
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
	if (index < items.length && index>=0){
	    return items[index];
	} else {
	    return -1;
	}
    }

    /**
     * Set the integer at the given index position to some new value
     *
     * @param index, Position in the list
     * @param item,  The updated value
     */
    public void set(int index, int item)
    {
	if (index<items.length && index>=0){
	    items[index] = item;
	}
    }
    
    /**
     * Insterts item at end of list
     *
     * @param item, value to be appended
     */
    public void add(int item)
    {
	//int num = items.length-1;
	if (this.numItems + 1 == arrayCapacity){
	    this.resize();
	}
	items[this.numItems] = item;
	this.numItems++;
    }

    /**
     * Inserts item at specific location in list
     *
     * @param index, location to insert new item
     * @param item,  value to be added to list
     */
    public void add(int index, int item)
    {
	if (index<items.length && index>=0){
	    if (this.numItems==arrayCapacity){
		this.resize();
	    }	    
	    int tmp = index;
	    while(tmp < this.numItems){
		items[tmp+1] = items[tmp];
		tmp++;
	    }
	    
	    items[index] = item;
	    this.numItems++;
	}
    }

    public int remove(int index)
    {
	if (index<items.length && index>=0){
	    int itm = items[index];
	    int tmp = index;
	    
	    while(tmp < this.numItems-1){
		items[tmp] = items[tmp+1];
		tmp++;
	    }
	    
	    //items[index] = 0;
	    this.numItems--;
	    return itm;
	} else {
	    return -1;
	}
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
	String output = "[";
	for (int i = 0; i < numItems - 1; i++)
	    output = output + items[i] + ", ";

	output = output + items[numItems - 1] + "]";
	return output;
    }

    /**
     * Shuffle (i.e., randomly re-order) the items in the list
     */
    public void shuffle()
    {
	for (int i = this.numItems-1; i >= 1; i--){
	    Random rand = new Random();
	    int n = rand.nextInt(i);
	    int tmp = items[i];
	    items[i] = items[n];
	    items[n] = tmp;
	}
    }
}
