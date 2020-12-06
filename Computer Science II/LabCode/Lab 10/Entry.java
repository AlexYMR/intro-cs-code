/**
 * A class representing a key/value pair for use with 
 * HashMaps
 *
 * The key and the value instance variables are both public
 * You can directly access them (no need for get/set methods)
 */
public class Entry
{
    public Object key;
    public Object value;

    /**
     * Empty constructor
     */
    public Entry()
    {
	key = null;
	value = null;
    }
    
    /**
     * Defualt constructor
     *
     * @param k the key
     * @param v the value
     */
    public Entry(Object k, Object v)
    {
	key = k;
	value = v;
    }

    /**
     * Copy constructor
     *
     * @param e another Entry 
     */
    public Entry(Entry e)
    {
	this(e.key, e.value);
    }

    /**
     * @return the key/value pair as a String in form of (key, value)
     */
    @Override
    public String toString()
    {
	return "(" + key.toString() + ", " + value.toString() + ")";
    }

    /**
     * Overriden equals method
     *
     * @param obj (presumably an Entry type)
     *
     * @return boolean
     */
    @Override
    public boolean equals (Object obj)
    {
	if (obj == null)
	    return false;
	else if (obj == this)
	    return true;
	else if (!(obj instanceof Entry))
	    return false;

	Entry other = (Entry) obj;
	return this.key.equals(other.key) && this.value.equals(other.value);
    }
}
