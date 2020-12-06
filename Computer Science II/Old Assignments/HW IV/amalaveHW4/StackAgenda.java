/*
 * StackAgenda.java
 * Part of Homework 4, part 2
*/

import java.util.Stack;

//Creates a Stack class that's parented to Agenda
//Does most of the basic functions of Java Stacks
public class StackAgenda extends Agenda{
    protected Stack<Location> agenda;
    public StackAgenda(){
	agenda = new Stack<Location>();
    }
    public void addLocation(Location loc){
	agenda.push(loc);
    }
    public Location getLocation(){
        return agenda.pop();
    }
    public boolean isEmpty(){
	return agenda.empty();
    }
    public void clear(){
	agenda = new Stack<Location>();
    }
}
