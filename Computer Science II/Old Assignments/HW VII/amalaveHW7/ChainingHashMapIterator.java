/*
 * ChainingHashMapIterator.java
 * Contains the class ChainingHashMapIterator, which has two methods, hasNext and next; it extends the abstract class AbstractHashMapIterator
 * Part of Homework 7, Problem 1
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class ChainingHashMapIterator extends AbstractHashMapIterator{

    private ArrayList<Entry>[] entries;
    private int rowIndex;
    private int colIndex;

    public ChainingHashMapIterator(ArrayList<Entry>[] entries)
    {
	this.entries = (ArrayList<Entry>[])entries;
	this.rowIndex = 0;
	this.colIndex = -1;
    }
    
    //-- Checks if the current index (of the outer array) has any values "chained" to it
    // -- If so, returns true, otherwise checks if the next index (of the outer HashMap) has any chained values
    // -- Repeated until the end of the array is reached
    // -- If nothing found, returns false
    public boolean hasNext(){
	int tempColIdx = colIndex + 1;
	for (int i = rowIndex; i < entries.length; i++){
	    for (int j = tempColIdx; j < entries[i].size(); j++){
		Entry e = (Entry)entries[i].get(j);
		if (!e.equals(null)){
		    return true;
		}
	    }
	    tempColIdx = 0;
	}
	return false;
    }
    
    // -- Returns the next value (in the current current column), exhausting row possibilities for that column index
    // -- Returns true if value found (or if value found in any subsequent column indexes within the size of the array), false otherwise
    public Entry next(){
	for (int i = rowIndex; i< entries.length; i++){
	    for (int j = colIndex+1; j < entries[i].size();j++){
		Entry e = (Entry)entries[i].get(j);
		if(!e.equals(null)){
		    colIndex++;
		    return e;
		}
	    }
	    rowIndex++;
	    colIndex = -1;
	}
	return null;
    }
}
