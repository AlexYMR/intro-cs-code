import java.util.Iterator;
/**
 * Goes through each Entry (key/value pair) in the HashMap
 * Assumes the entries are stored in an array.
 * @see ProbingHashMap
 */
public class ProbingHashMapIterator implements Iterator<Entry>
{
    private Entry [] entries;
    private int index;

    /**
     * Initializes the array and starting position for index
     */
    public ProbingHashMapIterator(Entry [] entries)
    {
	this.entries = entries;
	index = -1;
    }

    /**
     * Determines if there are still more entries
     * Care must be taken because entries are not stored
     * at consecutive index positions
     *
     * @return true if there are still unaccessed entries, false otherwise
     */
    @Override
    public boolean hasNext()
    {
	for (int i = index+1; i < entries.length; i++){
	    if (entries[i] != null){
		return true;
	    }
	}
	return false;
    }

    /**
     * @return the next Entry (key/value pair).
     *         As with hasNext, need to consider fact that entries
     *         are not stored in consecutive index positions.
     */
    @Override
    public Entry next()
    {
	for (int i = index+1; i< entries.length; i++){
	    if (entries[i] != null){
		index++;
		return entries[i];
	    }
	}
	return null;
    }

    @Override
    public void remove()
    {
	throw new UnsupportedOperationException("Remove not supported");
    }
}
