/*
 * Location.java
 * Part of Homework 4, part 2
*/
import java.util.ArrayList;

public class Location
{
    protected int row;
    protected int col;
    
    //Keeps track of any previous locations (used in the solver)
    protected boolean addedToPath;
    protected ArrayList<Location> trailPath;
    //Location linkedLocation;
    
    public Location(int r, int c)
    {
	row = r;
	col = c;
	trailPath = new ArrayList<Location>();
	//linkedLocation = null;
    }

    public int getRow()
    {
	return row;
    }

    public int getColumn()
    {
	return col;
    }
    
    @Override
    public boolean equals(Object obj)
    {
	if (obj == null)
	    return false; 
	else if (this == obj)
	    return true;
	else if (!(obj instanceof Location))
	    return false;

	Location other = (Location) obj;
	return this.getRow() == other.getRow() &&
	       this.getColumn() == other.getColumn();
    }

    @Override
    public String toString()
    {
	String s = "(" + Integer.toString(getRow()) + " ," + Integer.toString(getColumn()) + ")";

	return s;
    }
}
