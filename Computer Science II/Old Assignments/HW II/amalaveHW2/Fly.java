/*
 * Fly.java
 * Contains the Fly class, which is essentially the avatar the user will control in the game.
 * Part of Homework 2, problem 2
*/

public class Fly extends Creature
{
    private static final String imgFile = "fly.jpg";
    
    public Fly(GridLocation loc, FlyWorld fw)
    {
	super(loc,fw,imgFile);
	location.setCreature(this);
    }
    
    public boolean isPredator()
    {
	return false;
    }
    
    //Updates the position of the Fly
    public void update(int direction)
    {
	int r = location.row;
	int c = location.col;
	if (direction == FlyWorldGUI.NORTH){
	    r -= 1;
	}
	else if (direction == FlyWorldGUI.SOUTH){
	    r += 1;
	}
	else if (direction == FlyWorldGUI.WEST){
	    c -= 1;
	}
	else if (direction == FlyWorldGUI.EAST){
	    c+= 1;
	}
	if (world.isValidLoc(r,c)){
	    location.removeCreature();
	    this.location = world.getLocation(r,c);
	    location.setCreature(this);
	}
    }
}
