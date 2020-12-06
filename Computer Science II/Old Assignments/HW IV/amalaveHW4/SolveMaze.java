/*
 * SolveMaze.java
 * Part of Homework 4, part 2
*/

import java.io.FileNotFoundException;

//Test code for MazeSolver.java
public class SolveMaze{
    public static void main(String[] args) throws FileNotFoundException{
	if (args.length != 2){
	    System.out.println("\tUsage: java SolveMaze <maze file> <agenda type>");
	    System.out.println("\tWhere agenda type should be s (for stack) or q (for queue)");
	    System.exit(1);
	}
	Agenda agenda = null;
	Maze maze = new Maze(args[0]);
	MazeGUI gui = new MazeGUI(maze);
	if (args[1].equalsIgnoreCase("s"))
	    agenda = new StackAgenda();
	else if (args[1].equalsIgnoreCase("q"))
	    agenda = new QueueAgenda();
	else
	{
	    System.out.println("\tUsage: java SolveMaze <maze file> <agenda type>");
	    System.out.println("\tWhere agenda type should be s (for stack) or q (for queue)");
	    System.exit(1);
	}
	MazeSolver solver = new MazeSolver(agenda,gui);
	System.out.println(solver.solveMaze(maze));
    }
}
