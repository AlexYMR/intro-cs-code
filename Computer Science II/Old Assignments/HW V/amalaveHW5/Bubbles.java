import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;

public class Bubbles
{
    private static int[][] grid;

    private static int numCols;
    private static int numRows;

    private static int money = 0;

    //A helper method for memoization: recursively "pops" bubbles and accrues the money within them (maximizing profits)
    public static int memoBubbleMoney(int row, int col, int[][] array)
    {
	if (row > numRows - 1 || row < 0 || col > numCols - 1 || col < 0)
	    return 0;
	else if (array[row][col] != 0)
	    return array[row][col];
	else{
	    int temp = grid[row][col];
	    int path1Value = temp + memoBubbleMoney(row-1,col-1, array);
	    int path2Value = temp + memoBubbleMoney(row-1,col+1, array);
	    array[row][col] = money + (path1Value > path2Value ? path1Value:path2Value);
	    return array[row][col];
	}
    }
    
    //Constructs an array within which to store values that have already been calculated by the recursive helper method (so as to avoid redundant calculations and improve time efficiency)
    public static int memoizedBubbleMoney(int row, int col){
	int[][] array = new int[numRows+1][numCols+1];
	for (int i = 0;i<=numRows;i++){
	    for (int j = 0;j<=numCols;j++){
		array[i][j] = 0;
	    }
       }
	return memoBubbleMoney(row,col,array);
    }

    /*public static int bubbleMoney(int row, int col)
    {
	if (row > numRows - 1 || row < 0 || col > numCols - 1 || col < 0)
	    return 0;
	else if (row == 0)
	    return grid[row][col];
	else{
	    int temp = grid[row][col];
	    int path1Value = temp + bubbleMoney(row-1,col-1);
	    int path2Value = temp + bubbleMoney(row-1,col+1);
	    return money + (path1Value > path2Value ? path1Value:path2Value);
	}
	}*/

    public static void main(String [] args)
    {
	File inFile = new File(args[0]);
	Scanner input = null;
	try
	    {
		input = new Scanner(inFile);
	    }
	catch(FileNotFoundException fnfe)
	    {
		System.out.println("File not found.");
		System.exit(1);
	    }

	numRows = input.nextInt();
	numCols = input.nextInt();

	grid = new int[numRows][numCols];

	int lineNumber = 0;
	input.nextLine();
	//Reads the file line-by-line
	while(input.hasNextLine())         
	    {
		String line = input.nextLine();
		int colNum = 0;
		for (int i = 0; i < line.length(); i++){
		    if (line.charAt(i) != ' '){
			grid[lineNumber][colNum] = Integer.parseInt(Character.toString(line.charAt(i)));
			colNum += 1;
		    }
		}
		lineNumber += 1;
	    }
	input.close();
	String stringMaze = "";
	LinkedList<String> printLst = new LinkedList<String>();
	for (int[] r: grid){
	    printLst.addLast(Arrays.toString(r));
	}
	while (!printLst.isEmpty()){
	    System.out.println(printLst.removeFirst());
	}
	System.out.print(stringMaze);
	int r = Integer.parseInt(args[1]);
	int c = Integer.parseInt(args[2]);
	System.out.println(memoizedBubbleMoney(r,c));
    }
}
