import java.util.Iterator;
import java.util.Arrays;

/**
 * An implementation of HashMap using an array<br>
 * as the underlying data structure and<br>
 * linear probing for collision resolution<br><br>
 *
 * Key/Value pairs are stored in a single array
 * as Entry type
 *
 * @see Entry
 */
public class ProbingHashMap extends AbstractHashMap
{
    private Entry [] entries;

    /**
     * Call parent class constructor
     * with an initial maxLoad of .5 
     * and initialize entries array
     * to be appropriate capacity
     */
    public ProbingHashMap()
    {
	super(.5);
	entries = new Entry[capacity];
	/*capacity = 10;
	numKeys = 0;
	maxLoad = numKeys/capacity;*/
    }
    
    public ProbingHashMapIterator iterator()
    {	   
	return new ProbingHashMapIterator(entries);
    }

    /**
     * Adds key/value pair to appropriate<br>
     * hashed location in entries as an Entry type,<br> 
     * linear probing if another key/value pair is found at index<br>
     * Will also resize capacity of entries if needed, before adding<br>
     * the key/value pair.
     *
     * @param key
     * @param value
     */
    @Override
    public void put(Object key, Object value)
    {
	double currentLoad = numKeys/capacity;
	if (currentLoad >= maxLoad){
	    this.resize();
	}
	int i = 1;
	int trueKey = super.hash(key);
	boolean updated = false;
	while(entries[trueKey] != null){
	    if (entries[trueKey].key.equals(key)){
		updated = true;
		break;
	    }
	    trueKey = super.hash(key) + i;
	    i++;
	}
	Entry entry = new Entry(key,value);
	entries[trueKey] = entry;
	if (!updated){
	    numKeys++;
	}
    }

    /**
     * @param key
     *
     * @return value associated with key<br>
     *         (i.e., the value instance variable of an Entry object)<br>
     *         or null if key is not in entries
     */
    @Override
    public Object get(Object key)
    {
	int trueKey = super.hash(key);
	int i = 1;
	while(entries[trueKey] != null){
	    if (entries[trueKey].key.equals(key)){
		return entries[trueKey].value;
	    }
	    trueKey = super.hash(key) + i;
	    i++;
	}
	return null; // just for compile purposes
    }

    /**
     * Make the entries arraytwice as big (don't forget about capacity)<br>
     * You can't just make it bigger though<br>
     * you need to rehash the Entries currently<br>
     * in hashmap after you make it bigger
     */
    @Override
    protected void resize()
    {
	Entry tmp[] = entries;//new Entry[capacity*2];
	entries = new Entry[capacity*2];
	numKeys = 0;
	
	for (int i = 0; i < capacity; i++){
	    //tmp[i] = entries[i];
	    this.put(tmp[i].key,tmp[i].value);
	}
	capacity = capacity * 2;
    }
	
    /**
     * Helper method useful for debugging problems.<br>
     * When you are testing I recommend you<br>
     * use Integer keys so you know exactly where they<br>
     * should hash to.
     */
    public void printEntries()
    {
	System.out.println("Entries array: " + Arrays.toString(entries));
    }	    
}

    
