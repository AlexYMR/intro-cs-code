/*
 * ISBN.java
 * A program for calculating the last digit of a 9- or 13-digit ISBN number
 * Part of Homework 1, problems 2 & 3
*/

import java.util.Scanner;

/**
 * Class contains two methods that determine the last digit of a 9- or 13-digit ISBN number, and a main method that executes the code.
*/

public class ISBN
{
    /**
     * Determines the last digit of a 9-digit ISBN number.

     * @param int n, the value 9-digit integer

     * @returns string, either "X" if the sum mod 11 is 10, or the string of  the sum mod 11
    */
    public static String isbn10(int n){
	int i = n;
	int sum = 0;
	int idx = 9;
	while (i > 0){ //repeatedly divides the given number by 10 and performs arithmetic on the remainder as a way of segmenting a large value into single values
	    sum = sum + (i%10)*idx;
	    i = i / 10;
	    idx = idx - 1;
	}
	if ((sum%11) == 10){
	    return "X";
	}
	else {
	    return "" + (sum%11);
	}
    }
    /**
     * Determines the last digit of a 13-digit ISBN number.

     * @param long n, the value 13-digit integer

     * @returns string, either "0" if 10 minus the sum mod 10 is 10, or the string of 10 minus the sum mod 10
    */
    public static String isbn13(long n){
	long i = n;
	long sum = 0;
	int idx = 3;
	while (i > 0){ //repeatedly divides the given number by 10 and performs arithmetic on the remainder as a way of segmenting a large value into single values
	    sum = sum + (i%10)*idx;
	    i = i / 10;
	    if (idx == 3){
		idx = 1;
	    }
	    else {
		idx = 3;
	    }
	}
	if ((10-(sum%10)) == 10){
	    return "0";
	}
	else {
	    return "" + (10-(sum%10));
	}
    }
    /**
     * Main method that uses a while loop to determine valid user input, and determines which  of the two methods, isbn10 or isbn13, to use, based on the length of the user's input.
    */
    public static void main(String[] args){
	System.out.println("Please enter a 9- or 13-digit ISBN number: ");
	Scanner input = new Scanner(System.in);
	String type = "none";
	Long n = null;
	while (n == null){ //while n does not equal the user input
	    if (input.hasNextLong()){
		n = input.nextLong();
		String s = String.valueOf(n); //makes a string var to check length
		if (s.length() != 9 && s.length() != 12){ //check length
		    System.out.println("\nThe input was invalid.");
		    System.out.println("Please enter a 9- or 13-digit ISBN number: ");
		    n = null; //reset n's value
		}
		else {
		    if (s.length() == 9) {
			type = "isbn10";
		    }
		    else {
			type = "isbn13";
		    }
		}
	    }
	    else {
		System.out.println("\nThe input was invalid.");
		System.out.println("Please enter a 9- or 13-digit ISBN number: ");
	    }
	}
	//
	if (type == "isbn10"){ //uses isbn10 to determine value
	    int i = n.intValue();
	    String newNum = isbn10(i);
	    System.out.println("The tenth digit is: " + newNum);
	}
	else if (type == "isbn13"){ //uses isbn13 to determine value
	    String newNum = isbn13(n);
	    System.out.println("The thirteenth digit is: " + newNum);
	}
    }
}
