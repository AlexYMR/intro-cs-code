/*
 * Frog.java
 * Contains the subclass Frog, which inherits methods and properties from the abstract class Predator
 * Part of Homework 2, part 3
*/

import java.util.ArrayList;

public class Frog extends Predator
{
    private static final String imgFile = "frog.jpg";

    public Frog(GridLocation loc, FlyWorld fw)
    {
	super(loc,fw,imgFile);
    }
    
    //Can move N,S,W,E, and does so randomly
    public ArrayList<GridLocation> generateLegalMoves()
    {
	ArrayList<GridLocation> array = new ArrayList<GridLocation>();
	//Ask about how to make this more efficient, as it seems like it could be made so
	int[][] pos = {
	    {location.row-1,location.col},
	    {location.row+1,location.col},
	    {location.row,location.col+1},
	    {location.row,location.col-1}
	};
	if(world.isValidLoc(pos[0][0],pos[0][1]) && !world.getLocation(pos[0][0],pos[0][1]).hasPredator()){
	    array.add(world.getLocation(pos[0][0],pos[0][1]));
	}
	if(world.isValidLoc(pos[1][0],pos[1][1]) && !world.getLocation(pos[1][0],pos[1][1]).hasPredator()){
	    array.add(world.getLocation(pos[1][0],pos[1][1]));
	}
	if(world.isValidLoc(pos[2][0],pos[2][1]) && !world.getLocation(pos[2][0],pos[2][1]).hasPredator()){
	    array.add(world.getLocation(pos[2][0],pos[2][1]));
	}
	if(world.isValidLoc(pos[3][0],pos[3][1]) && !world.getLocation(pos[3][0],pos[3][1]).hasPredator()){
	    array.add(world.getLocation(pos[3][0],pos[3][1]));
	}
	return array;
    }

    //Decides whether the fly can be eaten
    public boolean eatsFly()
    {
	int[][] pos = {
	    {location.row-1,location.col},
	    {location.row+1,location.col},
	    {location.row,location.col+1},
	    {location.row,location.col-1},
	    {location.row,location.col}
	};
	if(world.isValidLoc(pos[0][0],pos[0][1]) && world.getLocation(pos[0][0],pos[0][1]).equals(world.getFlyLocation())){
	    return true;
	}
	else if(world.isValidLoc(pos[1][0],pos[1][1]) && world.getLocation(pos[1][0],pos[1][1]).equals(world.getFlyLocation())){
	    return true;
	}
	else if(world.isValidLoc(pos[2][0],pos[2][1]) && world.getLocation(pos[2][0],pos[2][1]).equals(world.getFlyLocation())){
	    return true;
	}
	else if(world.isValidLoc(pos[3][0],pos[3][1]) && world.getLocation(pos[3][0],pos[3][1]).equals(world.getFlyLocation())){
	    return true;
	}
	else if(world.isValidLoc(pos[4][0],pos[4][1]) && world.getLocation(pos[4][0],pos[4][1]).equals(world.getFlyLocation())){
	    return true;
	} else {
	    return false;
	}
    }   
}
