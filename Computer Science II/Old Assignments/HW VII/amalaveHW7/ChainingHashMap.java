/*
 * ChainingHashMap.java
 * Contains the class ChainingHashMap, which has methods put, get, iterator, resize, and printEntries
 * Part of Homework 7, Problem 1
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class ChainingHashMap extends AbstractHashMap{

    private ArrayList<Entry>[] entries;

    public ChainingHashMap(){
	super(5);
	entries = (ArrayList<Entry>[])new ArrayList[capacity];
	for (int i = 0; i < capacity; i++){
	    entries[i] = new ArrayList<Entry>();
	}
    }
    
    //-- Inserts objects into the ChainedHashMap with an associated key and value
    public void put(Object key, Object value)
    {
	double currentLoad = numKeys/capacity;
	if (currentLoad >= maxLoad){
	    this.resize();
	}
	int j = 0;
	int trueKey = super.hash(key);
	boolean updated = false;
	while(j < entries[trueKey].size()){
	    Entry e = (Entry)entries[trueKey].get(j);
	    if (e.key.equals(key)){
		updated = true;
		break;
	    }
	    j++;
	}
	Entry entry = new Entry(key,value);
	if(updated){
	    entries[trueKey].set(j,entry);
	}
	else{
	    entries[trueKey].add(entry);
	    numKeys++;
	}
    }

    //-- Returns the first object found in the ChainedHashMap with a given key, otherwise returns null
    public Object get(Object key){
	int trueKey = super.hash(key);
	int i = 0;
	int j = 0;
	while(i < capacity){
	    while(j < entries[trueKey].size()){
		Entry e = (Entry)entries[trueKey].get(j);
		if (e.key.equals(key)){
		    return e.value;
		}
		j++;
	    }
	    i++;
	}
	return null;
    }
    
    //-- Changes the size of the ArrayList that comprises the HashMap (doubles the capacity and rehashes keys to fit the new ArrayList)
    public void resize(){
	ArrayList<Entry>[] tmp = (ArrayList<Entry>[])entries;
	entries = (ArrayList<Entry>[])new ArrayList[capacity*2];
	numKeys = 0;
	int oldCapacity = capacity;
	capacity = capacity * 2;
	for (int i = 0; i < capacity; i++){
	    entries[i] = new ArrayList<Entry>();
	}

	for (int i = 0; i < oldCapacity; i++){
	    for(int j = 0; j<tmp[i].size();j++){
		Entry e = (Entry)tmp[i].get(j);
		this.put(e.key,e.value);
	    }
	}
    }
    
    //-- Returns an iterator
    public Iterator<Entry> iterator(){
	return new ChainingHashMapIterator(entries);
    }

    //-- Prints the key-value pairs in the HashMap, delimited by tab space
    public void printEntries()
    {
	String s = "";
	for (int i = 0; i < capacity; i++){
	    for (int j = 0; j < entries[i].size(); j++){
		Entry e = (Entry)entries[i].get(j);
		s = s + e;
		s = s + "\t";
	    }
	}
	System.out.println(s);
    }	   
}
