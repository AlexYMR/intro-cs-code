/*
 * Test.java
 * A file used for testing the operations of the ChainingHashMap and the ChainingHashMapIterator
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class Test{
    public static void main(String[] args){
	ChainingHashMap c = new ChainingHashMap();
	c.put("A",2);
	c.put("A",5);
	/*for (int i = 0; i < 150; i++){
	    c.put(i,5);
	    }*/
	//System.out.println(c.get(12));
	c.printEntries();
        Iterator<Entry> iter = c.iterator();
	while(iter.hasNext()){
	    System.out.println(iter.next());
	}
    }
}
