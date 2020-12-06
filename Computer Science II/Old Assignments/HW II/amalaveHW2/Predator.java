/*
 * Predator.java
 * Contains the abstract class Predator, which inherits methods and properties from the abstract class Creature
 * Part of Homework 2, part 8
*/

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.util.ArrayList;

abstract class Predator extends Creature{
    public Predator(GridLocation loc, FlyWorld fw, String imgFile){
	super(loc,fw,imgFile);
	location.setCreature(this);
    }
    
    //Serves as an update for all predators
    public void update(){
	ArrayList<GridLocation> array = generateLegalMoves();
	if (array.size() > 0){
	    int n = (int) (Math.random() * array.size());
	    this.location.removeCreature();
	    this.location = world.getLocation(array.get(n).row,array.get(n).col);
	    this.location.setCreature(this);
	}
    }

    public boolean isPredator(){
	return true;
    }
    
    //Defining abstract methods here, which will be overridden by subclasses
    public abstract ArrayList<GridLocation> generateLegalMoves();
    public abstract boolean eatsFly();

}
