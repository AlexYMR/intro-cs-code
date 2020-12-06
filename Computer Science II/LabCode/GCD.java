/**
 * In this class you will write two different methods
 * to calculate the GCD of two integers.
 */
import java.util.Scanner;

public class GCD
{
    public static int gcdNaive(int a, int b)
    {
	int n = 0;
	int lesser;
	if (a > b) {
	    lesser = b;
	}
	else {
	    lesser = a;
	}

	for (int i = 1; i <= lesser; i++)
	    {
		if ((a%i) == 0 && (b%i) == 0){
			n = i;
		}
	    }
	return n;
    }
     public static int gcdEuclid(int a, int b)
    {
	int n = 0;
	int holder;
	if (a > b) {
	    holder = a;
	    a = b;
	    b = holder;
	}
	int remainder;
	while (b != 0){
	    remainder = a % b;
	    a = b;
	    b = remainder;
	} 
	return a;
    }
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	System.out.print("Enter a number for m: ");
	int a = in.nextInt();
	if (a < 0) {
		System.out.println("Invalid value for m.");
		return;
	    }
	System.out.print("Enter a number for n: ");
	int b = in.nextInt();
	if (b < 0) {
		System.out.println("Invalid value for n.");
		return;
	    }
	if (a >= 0 && b >= 0) {
		System.out.println("GCD [Naive]: " + gcdNaive(a,b));
		System.out.println("GCD [Euclid]:" + gcdEuclid(a,b));
	    }
    }
 
}
	
