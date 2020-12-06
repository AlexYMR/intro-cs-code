import java.util.Arrays;

public class Blocks{
    //private static int[] array;
    public static int memoBlocksRec(int rows, int[] array){
	if (array[rows] != -1){
	    return array[rows];
	}
	else{
	    array[rows] = numBlocksRec(rows-1)+rows;
	    return array[rows];
	}
    }
    public static int numBlocksMemo(int rows){
	int[] array = new int[rows+1];
	Arrays.fill(array,-1);
	array[0] = 0;
	return memoBlocksRec(rows,array);
    }
    public static int numBlocksRec(int rows){
	if (rows == 1){
	    return 1;
	}
	else if (rows == 0){
	    return 0;
	}
	else{
	    return numBlocksRec(rows-1)+rows;
	}
    }
    public static void main(String args[]){
	for (int i = 0; i<= 10;i++){
	    System.out.println("Triangle with " + i + " rows has " + numBlocksRec(i) + " blocks.");
	}
	for (int i = 0; i<= 10;i++){
	    System.out.println("(Memoized) Triangle with " + i + " rows has " + numBlocksMemo(i) + " blocks.");
	}
    }
}
