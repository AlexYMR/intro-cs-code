/*
 * Creature.java
 * Contains the abstract class Creature, under which is the parent of all mobile objects in the game (whether they be predators or the fly)
 * Part of Homework 2, part 7
*/

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

abstract class Creature{
    protected GridLocation location;
    protected FlyWorld world;
    protected BufferedImage image;
    
    //Constructor
    public Creature(GridLocation loc, FlyWorld fw, String imgFile){
	location = loc;
	world = fw;
	try
	{
	    image = ImageIO.read(new File(imgFile));
	}
	catch (IOException ioe)
	{
	    System.out.println("Unable to read image file: " + imgFile);
	    System.exit(0);
	}
    }
    
    public BufferedImage getImage()
    {
	return image;
    }
    public GridLocation getLocation()
    {
	return location;
    }

    abstract boolean isPredator();

}
