/*
 * Bird.java
 * Contains the subclass Bird, which inherits methods and properties from the abstract class Predator
 * Part of Homework 2, part 9
*/

import java.util.ArrayList;

public class Bird extends Predator
{
    private static final String imgFile = "bird.jpg";

    public Bird(GridLocation loc, FlyWorld fw)
    {
	super(loc,fw,imgFile);
    }
    
    //Capable of moving to any location on the grid that doesn't contain a predator
    public ArrayList<GridLocation> generateLegalMoves()
    {
	ArrayList<GridLocation> array = new ArrayList<GridLocation>();
	for (int i = 0; i<world.getNumRows();i++){
	    for(int j=0;j<world.getNumCols();j++){
		if (world.isValidLoc(i,j) && !world.getLocation(i,j).hasPredator()){
		    array.add(world.getLocation(i,j));
		}
	    }
	}
	return array;
    }
    
    //Decides whether it can eat the fly
    public boolean eatsFly()
    {
	if(world.isValidLoc(location.row,location.col) && world.getLocation(location.row,location.col).equals(world.getFlyLocation())){
	    return true;
	} else {
	    return false;
	}
    }   
}
