/*
 * Palindrome.java
 * Contains the class Palindrome, whose methods check whether a given word is a palindrome or not
 * Part of Homework 5, Problem 1
 */

class Palindrome
{
    //Takes a string, starting index, and ending index as parameters, returns whether or not the string is a palindrome
    public static boolean isPalindrome(String s, int f_index, int s_index)
    {
	if (f_index == s_index)
	    return true;
	else if (s.charAt(f_index) == s.charAt(s_index) && f_index == s_index - 1)
	    return true;
	else if (s.charAt(f_index) == s.charAt(s_index))
	    return isPalindrome(s,f_index+1,s_index-1);
	else
	    return false;
    }

    public static void main(String [] args)
    {
	String s = args[0].toLowerCase();
	if (isPalindrome(s,0,s.length() - 1))
	    System.out.println(s + " is a palindrome");
	else
	    System.out.println(s + " is not a palindrome");
    }
}
    
