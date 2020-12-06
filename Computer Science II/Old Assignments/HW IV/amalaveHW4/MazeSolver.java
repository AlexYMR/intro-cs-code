/*
 * MazeSolver.java
 * Determines a whether a maze can be solved or not
 * Part of Homework 4, part 2 & 3
*/

import java.util.ArrayList;

public class MazeSolver{
    protected Agenda agenda;
    protected ArrayList<Location> solutionPath;
    protected MazeGUI gui;
    
    //Constructs a solver using an Agenda object as a parameter
    public MazeSolver(Agenda a){
	agenda = a;
	solutionPath = new ArrayList<Location>();
    }

    //Takes a Maze object as a parameter and returns a direct path to the goal if one is possible (in the form of an ArrayList of Location objects, otherwise returns an empty ArrayList
    public ArrayList<Location> solveMaze(Maze maze, MazeGUI gui){
	agenda.clear();
	agenda.addLocation(maze.getStartLocation());
	//
	gui.addLocToAgenda(maze.getStartLocation());
	//
	maze.getStartLocation().addedToPath = true;
	while(!agenda.isEmpty()){
	    Location loc = agenda.getLocation();
	    //
	    gui.pause();
	    gui.visitLoc(loc);
	    //
	    loc.trailPath.add(loc);
	    if (loc.equals(maze.getGoalLocation())){
		for (int i = 0; i < loc.trailPath.size();i++){
		    gui.addLocToPath(loc.trailPath.get(i));
		}
		return loc.trailPath;
	    } else {
		if (loc.row+1<maze.grid.length){
		    Location temp = maze.locationGrid[loc.row+1][loc.col];
		    if (!temp.addedToPath){           
			if (maze.grid[loc.row+1][loc.col] != '#'){
			    temp.trailPath = loc.trailPath;
			    agenda.addLocation(temp);
			    //
			    gui.addLocToAgenda(temp);
			    //
			    temp.addedToPath = true;
			}
		    }
		}
		if (loc.row-1>=0){
		    Location temp = maze.locationGrid[loc.row-1][loc.col];
		    if (!temp.addedToPath){                    
			if (maze.grid[loc.row-1][loc.col] != '#'){
			    temp.trailPath = loc.trailPath;
			    agenda.addLocation(temp);
			    //
			    gui.addLocToAgenda(temp);
			    //
			    temp.addedToPath = true;
			}
		    }
		}
		if (loc.col-1>=0){
		    Location temp = maze.locationGrid[loc.row][loc.col-1];
		    if (!temp.addedToPath){                    
			if (maze.grid[loc.row][loc.col-1] != '#'){
			    temp.trailPath = loc.trailPath;
			    agenda.addLocation(temp);
			    //
			    gui.addLocToAgenda(temp);
			    //
			    temp.addedToPath = true;
			}
		    }
		}
		if (loc.col+1<maze.grid[loc.row].length){
		    Location temp = maze.locationGrid[loc.row][loc.col+1];
		    if (!temp.addedToPath){                    
			if (maze.grid[loc.row][loc.col+1] != '#'){
			    temp.trailPath = loc.trailPath;
			    agenda.addLocation(temp);
			    //
			    gui.addLocToAgenda(temp);
			    //
			    temp.addedToPath = true;
			}
		    }
		}
	    }
	}
	return solutionPath;
    }

}
