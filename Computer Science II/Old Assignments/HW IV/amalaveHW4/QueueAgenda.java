/*
 * QueueAgenda.java
 * Part of Homework 4, part 4
*/

import java.util.LinkedList;

//Creates a Queue class that's parented to Agenda
//Implements queue-like behavior using a linked list
public class QueueAgenda extends Agenda{
    protected LinkedList<Location> agenda;
    public QueueAgenda(){
	agenda = new LinkedList<Location>();
    }
    public void addLocation(Location loc){
	agenda.add(loc);
    }
    public Location getLocation(){
        return agenda.removeFirst();
    }
    public boolean isEmpty(){
	return agenda.size() == 0;
    }
    public void clear(){
	agenda = new LinkedList<Location>();
    }
}
