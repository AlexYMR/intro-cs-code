/*
 * Agenda.java
 * Abstract class for Agendas
 * Part of Homework 4, part 2
*/

public abstract class Agenda{
    public abstract void addLocation(Location loc); // adds a location(row, column pos) to agenda
    public abstract Location getLocation(); //removes and returns a location from agenda
    public abstract boolean isEmpty(); //returns true if agenda is empty
    public abstract void clear(); //removes all items from the agenda
}
