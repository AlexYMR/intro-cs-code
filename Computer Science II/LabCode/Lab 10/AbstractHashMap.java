/**
 * Abstract class detailing basic set of operations<br>
 * any concrete implementation of a HashMap will need<br>
 * to provide.<br>
 */
public abstract class AbstractHashMap
{
    protected double maxLoad;
    
    protected int numKeys;
    protected int capacity;

    /**
     * Initializes properties of a HashMap<br><br>
     *
     * maxLoad is the maximum load value the HashMap can reach<br>
     * before possibly resizing (i.e. increasing the capacity)<br><br>
     *
     * numKeys is the number of key/value pairs in HashMap<br><br>
     *
     * capacity is the upper limit on number of items the HashMap<br> 
     * can hold
     */
    public AbstractHashMap(double maxLoad)
    {
	numKeys = 0;
	capacity = 3;
	this.maxLoad = maxLoad;
    }

    /**
     * Adds the key/value pair to the HashMap
     *
     * @param key
     * @param value
     */
    public abstract void put(Object key, Object value);

    /**
     * @param key
     *
     * @return value assoicated with key or null if key
     *         not in the HashMap
     */
    public abstract Object get(Object key);

    /**
     * Increases the capacity of the HashMap<br>
     * This usually reduces the number of collisions that occur
     */
    protected abstract void resize();

    /**
     * @return the number of key/value pairs in the HashMap
     */
    public int size()
    {
	return numKeys;
    }
    
    public boolean isEmpty()
    {
	return size() == 0;
    }

    /**
     * @param key
     *
     * @return the index position this key maps to in the<br> 
     *         data structure underlying the HashMap
     */
    protected int hash(Object key)
    {
	return (key.hashCode() % capacity + capacity) % capacity;
    }
}
    
    
