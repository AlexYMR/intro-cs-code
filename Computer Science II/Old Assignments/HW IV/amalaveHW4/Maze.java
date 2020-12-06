/*
 * Maze.java
 * Part of Homework 4, part 2
*/

import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Arrays;
import java.util.LinkedList;

public class Maze{
    private int numRows;
    private int numCols;

    private Location start;
    private Location goal;

    protected char[][] grid;
    protected Location[][] locationGrid;
    
    //Reads a text file (its parameter) and fills a character double array with the characters of its text lines
    public Maze(String filename) throws FileNotFoundException{ 
	File ifile = new File(filename);
	Scanner input = new Scanner(ifile);
     
	this.numRows = input.nextInt();
	this.numCols = input.nextInt();

	grid = new char[this.numRows][this.numCols];
	locationGrid = new Location[this.numRows][this.numCols];

	int lineNumber = 0;
	input.nextLine();
	//Reads the file line-by-line
	while(input.hasNextLine())
	    {
		String line = input.nextLine();
		for (int i = 0; i < line.length(); i++){
		    char c = line.charAt(i);
		    grid[lineNumber][i] = c;
		    Location tmp = new Location(lineNumber,i);
		    locationGrid[lineNumber][i] = tmp;
		    //Checks to see if certain characters match, instantiating certain objects accordingly
		    if (c == 'o'){
			start = tmp;
		    }
		    else if(c == '*'){
			goal = tmp;
		    }
		}
		lineNumber += 1;
	    }
	input.close();
    }
    public int getNumColumns(){
	return numCols;
    }
    public int getNumRows(){
	return numRows;
    }
    public Location getStartLocation(){
	return start;
    }
    public Location getGoalLocation(){
	return goal;
    }
    public char getSquare(Location loc){
	return grid[loc.row][loc.col];
    }
    public String toString(){
	String stringMaze = "";
	LinkedList<String> printLst = new LinkedList<String>();
	for (char[] r: grid){
	    printLst.addLast(Arrays.toString(r));
	}
	while (!printLst.isEmpty()){
	    System.out.println(printLst.removeFirst());
	}
	return stringMaze;
    }
    
    public static void main(String[] args) throws Exception{
	Maze maze = new Maze(args[0]);
	System.out.println(maze);
    }

}
