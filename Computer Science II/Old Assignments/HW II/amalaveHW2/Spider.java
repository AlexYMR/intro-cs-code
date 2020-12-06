/*
 * Spider.java
 * Contains the subclass Spider, which inherits methods and properties from the abstract class Predator
 * Part of Homework 2, part 10
*/

import java.util.ArrayList;

public class Spider extends Predator
{
    private static final String imgFile = "spider.jpg";

    public Spider(GridLocation loc, FlyWorld fw)
    {
	super(loc,fw,imgFile);
    }

    //Moves by always approaching the fly
    public ArrayList<GridLocation> generateLegalMoves()
    {
	ArrayList<GridLocation> array = new ArrayList<GridLocation>();
	GridLocation FL = world.getFlyLocation();
	if (FL.col > location.col && !world.getLocation(location.row,location.col+1).hasPredator()){
	    array.add(world.getLocation(location.row,location.col+1));
	}
	else if (FL.col < location.col && !world.getLocation(location.row,location.col-1).hasPredator()){
	    array.add(world.getLocation(location.row,location.col-1));
	}

	if (FL.row > location.row && !world.getLocation(location.row+1,location.col).hasPredator()){
	    array.add(world.getLocation(location.row+1,location.col));
	}
	else if (FL.row < location.row && !world.getLocation(location.row-1,location.col).hasPredator()){
	    array.add(world.getLocation(location.row-1,location.col));
	}
	return array;
    }

    //Checks if fly can be eaten
    public boolean eatsFly()
    {
	if(world.isValidLoc(location.row,location.col) && world.getLocation(location.row,location.col).equals(world.getFlyLocation())){
	    return true;
	} else {
	    return false;
	}
    }   
}
