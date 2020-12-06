/*
 * TextGenerator.java
 * Contains the class TextGenerator, along with methods train, sampleWord, generateText, and main
 * Part of Homework 7, Problem 2 & 3
 */

import java.util.Random;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * A class for training a Markov chain from a body of text
 * and then generating new text using the estimated frequencies.
 */
class TextGenerator
{
   protected ChainingHashMap countTable;
   protected ChainingHashMap totalTable;
   protected int totalWords;
   protected Random rand;

   public TextGenerator()
   {
      rand = new Random();
      countTable = new ChainingHashMap();
      totalTable = new ChainingHashMap();
      totalWords = 0;
   }

   /**
    * Trains the Markov chain on the given body of text
    * @param text a String containing the text to train on
    */
   public void train(String text)
   {
      String [] words = text.split("\\s+"); //Split the string on whitespace

      int i = 0;
      String currentWord = "";
      while(i < words.length - 1){
	  currentWord = words[i];
	  Object wordCount = totalTable.get(currentWord);
	  if (wordCount != null){
	      Integer wordC = (Integer)wordCount;
	      totalTable.put(currentWord,wordC+1);
	  }
	  else{
	      totalTable.put(currentWord,1);
	  }
	  //
	  ChainingHashMap m = (ChainingHashMap) countTable.get(currentWord);
	  if (m != null){
	      String nextWord = words[i+1];
	      Object wordCount2 = m.get(nextWord);
	      if (wordCount2 != null){
		  Integer wordC2 = (Integer)wordCount2;
		  m.put(nextWord,wordC2+1);
	      }
	      else{
		  m.put(nextWord,1);
	      }
	  }
	  else{
	      ChainingHashMap newHM = new ChainingHashMap();
	      String nextWord = words[i+1];
	      Object wordCount2 = newHM.get(nextWord);
	      newHM.put(nextWord,1);
	      countTable.put(currentWord,newHM);
	  }
	  //
	  totalWords++;
	  i++;
      }
   }

   /**
    * Picks a random word from the given frequencies
    * @param counts a hash map that maps words (String) to the frequency of that word (Integer)
    * @param totalCount the sum of all the frequencies in counts
    * @return the randomly chosen word
    */
   public String sampleWord(ChainingHashMap counts, int totalCount)
   {
      //Pick a random number between 0.0 and 1.0
      double randNum = rand.nextDouble();
      
      double probSum = 0.0;
      for (Entry e : counts)
      {
	 //Add this word's frequency to the cumulative probability so far
	 int num = (Integer) e.value;
	 probSum += ((double)num / (double)totalCount);
	 //If the sum crosses the random number, this is the randomly selected word
	 if (randNum < probSum){
	     return (String) e.key;
	 }
      }

      //We should never reach this line!
      //System.out.println("Here");
      return "";
   }

   /**
    * Uses the Markov chain to generate a sequence of words of the given length
    * (Randomly picks a word, then based on that word picks a next word, and so on)
    * @param numWords the number of words to generate
    * @return a String containing the generated text
    */
   public String generateText(int numWords)
   {
       String s = sampleWord(totalTable,totalWords);
       String lastWord = s;
       for (int i = 0; i < numWords; i++){
	   ChainingHashMap c = (ChainingHashMap) countTable.get(lastWord);
	   Integer t = (Integer) totalTable.get(lastWord);
	   lastWord = sampleWord(c,t);
	   s = s + " " + lastWord;
       }
      return "\n..." + s + "...\n";
   }

   /**
    * Takes a file as a command-line argument, passes the contents
    * to train and then uses generateText to generate and print
    * a 100-word passage.
    */
   public static void main(String [] args)
   {
       if(args.length == 0)
      {
	 System.out.println("Requires a file containing the source text!");
	 System.exit(1);
      }

      //Open the file
      File file = new File(args[0]);

      Scanner scan = null;
      try
      {
	 scan = new Scanner(file);
      }
      catch (FileNotFoundException fnf)
      {
	 System.err.println("Input file not found");
	 System.exit(1);
      }

      //Read the entire file into a String
      scan.useDelimiter("\\Z");
      String text = scan.next();
      TextGenerator t = new TextGenerator();
      t.train(text);
      
      System.out.println(t.generateText(100));
   }
}
