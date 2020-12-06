/*
 * FlyWorld.java
 * Contains the world, or grid, of the game
 * Part of Homework 2, part 1
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.awt.Color;
import java.util.Random;

/**
 * Contains information about the world (i.e., the grid of squares)<br>
 * and handles most of the game play work that is NOT GUI specific
 */
class FlyWorld
{
    protected int numRows;
    protected int numCols;

    protected GridLocation [][] world;
    protected GridLocation start;
    protected GridLocation goal;

    protected ArrayList<Predator> predators;
   
    protected Fly mosca;

    public FlyWorld(String fileName)
    {
	File inFile = new File(fileName);
	Scanner input = null;
	try
	    {
		input = new Scanner(inFile);
	    }
	catch(FileNotFoundException fnfe)
	    {
		System.out.println("File not found!");
		System.exit(1);
	    }

	this.numRows = input.nextInt();
	this.numCols = input.nextInt();

	world = new GridLocation[this.numRows][this.numCols];
	predators = new ArrayList<Predator>();

	int lineNumber = 0;
	input.nextLine();
	//Reads the file line-by-line
	while(input.hasNextLine())         
	    {
		String line = input.nextLine();
		for (int i = 0; i < line.length(); i++){
		    GridLocation square = new GridLocation(lineNumber,i);
		    world[lineNumber][i] = square;
		    char c = line.charAt(i);
		    //Checks to see if certain characters match, instantiating certain objects accordingly
		    if (c == 's'){
			this.start = world[lineNumber][i];
			square.setBackgroundColor(Color.GREEN);
			mosca = new Fly(this.start,this);
		    }
		    else if(c == 'h'){
			this.goal = world[lineNumber][i];
			square.setBackgroundColor(Color.RED);
		    }
		    else if (c == 'f'){
			Predator frog = new Frog(square,this);
			predators.add(frog);
		    }
		    else if (c == 'b'){
			Predator bird = new Bird(square,this);
			predators.add(bird);
		    }
		    else if (c == 'a'){
			Predator spider = new Spider(square,this);
			predators.add(spider);
		    }
		}
		lineNumber += 1;
	    }
	input.close();
    }
    public int getNumRows()
    {
	return numRows;
    }
    public int getNumCols()
    {
	return numCols;
    }
    public boolean isValidLoc(int r, int c)
    {
	//bounds are not left of [n][0], not right of [n][this.numCols-1], not down from [this.numRows-1][n], not above [0][n] 
	if (r <= this.numRows-1 && r >= 0 && c <= this.numCols-1 && c >= 0){
	    return true;
	}
	else{
	    return false;
	}
    }
    public GridLocation getLocation(int r, int c)
    {
	return world[r][c];
    }
    public GridLocation getFlyLocation()
    {
	return mosca.getLocation();
    }
    public int moveFly(int direction)
    {
	mosca.update(direction);
	if (mosca.getLocation().equals(this.goal)){
	    return FlyWorldGUI.ATHOME;
	}
	else{
	    for(Predator f:predators){
		if(f.eatsFly()){
		    return FlyWorldGUI.EATEN;
		}
	    }
	    return FlyWorldGUI.NOACTION;
	}
    }
    public boolean movePredators()
    {
	boolean t = false;
	for(Predator f:predators){
	    f.update();
	    t = f.eatsFly();
	}
	return t;
    }
}
		    
			
			      
