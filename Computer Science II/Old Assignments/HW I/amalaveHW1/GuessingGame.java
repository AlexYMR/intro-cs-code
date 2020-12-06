/*
 * GuessingGame.java
 * A program that simulates a number-guessing game. Guesses are numbers between 1 & 100, inclusive.
 * Part of Homework 1, problem 1
*/

import java.util.Random;
import java.util.Scanner;

/**
 * Class contains code that runs the guessing game. User is able to play for as long as they desire without the program ending. While loops check for validity of inputs by user.
*/

public class GuessingGame
{
    /**
     * Repeatedly asks a user to guess a number (an integer) between 1 and 100, inclusive, until the user guesses right, or decides to quit the program by inputting "q."
    */
    public static void main(String[] args)
    {
	System.out.println("Please enter an integer from 1 to 100 (or q to quit): ");
	Scanner input = new Scanner(System.in);
	Random rand = new Random();
	Integer num = rand.nextInt(101) + 1;
	Integer n = null;
	String ans = null;
	Integer guesses = 1;
	while (n == null || n != num) { //checks for validity of user input & whether the user chose to play again or not (for string purposes)
	    if (input.hasNextInt()){
		n = input.nextInt();
	    }
	    else if (input.hasNext("q")) {
		System.out.println("\nThe mystery number was: " + num);
		System.out.println("Thanks for playing!");
		return;
	    }
	    else {
		if (ans == null){
		    System.out.println("\nThe input was invalid.");
		    System.out.println("Please enter an integer from 1 to 100 (or q to quit): ");
		}
		else {
		    System.out.println("\nPlease enter an integer from 1 to 100 (or q to quit): ");
		    ans = null;
		}
		
		input = new Scanner(System.in);
		if (input.hasNextInt()) {
		    n = input.nextInt();
		}
	    }
	    if (n != null){ // if the input is valid...
		if (n == num) {
		    System.out.println("\nThat's correct! It took you " + guesses + " guesses.");
		    System.out.println("Would you like to play again? (y/n): ");
		    input = new Scanner(System.in);
		    while (ans == null){
			if (input.hasNext("y")) { //resets variables to accomodate for a new gameplay
			    num = rand.nextInt(101) + 1;
			    guesses = 0;
			    n = null;
			    ans = "y";
			}
			else if (input.hasNext("n")) {
			    ans = "n";
			    System.out.println("\nThanks for playing!");
			    return; //ends the program
			}
			else {
			    System.out.println("\nThe input was invalid.");
			    System.out.println("Would you like to play again? (y/n): ");
			    input = new Scanner(System.in);
			    if (input.hasNext("y")) { //resets variables to accomodate for a new gameplay
				num = rand.nextInt(101) + 1;
				guesses = 0;
				n = null;
				ans = "y";
			    }
			    else if (input.hasNext("n")) {
				ans = "n";
				System.out.println("\nThanks for playing!");
				return; //ends the program
			    }
			}
		    }
		}
		else if (n < num) {
		    System.out.println("\nYour guess was too low.");
		    System.out.println("Please enter an integer from 1 to 100 (or q to quit): ");
		    guesses += 1;
		}
		else if (n > num) {
		    System.out.println("\nYour guess was too high.");
		    System.out.println("Please enter an integer from 1 to 100 (or q to quit): ");
		    guesses += 1;
		}
	    }
	}
	
	System.out.println("Your input was: " + n);
    }
}
