import java.util.Random;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.ArrayList;

public class Grades
{
   public static void main(String [] args)
   {
      File inFile = new File(args[0]);
      HashMap<String, Float> hmap = new HashMap<String, Float>();
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
     
      while(input.hasNextLine())          
     {
	 String line = input.nextLine();
	 Scanner lineScanner = new Scanner(line);
	 lineScanner.useDelimiter(" "); //Now uses tab to separate tokens
	 String name = lineScanner.next(); //Get a string
	 ArrayList<Float> array = new ArrayList<Float>();
	 float lowestG = 100;
	 while (lineScanner.hasNextFloat()){
	     float grade = lineScanner.nextFloat();
	     if (grade < lowestG){
		 lowestG = grade;
	     }
	     array.add(grade);
	 }
	 float avgG = findAverage(array,lowestG);
	 hmap.put(name,avgG);
	 //System.out.println(name "'s Average Grade: " + avgG);
      }
      for (String member: hmap.keySet()){
	  String name = member.toString();
	  String g = hmap.get(member).toString();
	  System.out.println(name + "'s Average Grade: " + g);
      }
      input.close();	 
   }

    public static float findAverage(ArrayList<Float> array, float minGrade){
	array.remove(new Float(minGrade));
	float sum = 0;
	for (float member: array){
	    sum += member;
	}
	return sum/array.size();
    }
}
	    
