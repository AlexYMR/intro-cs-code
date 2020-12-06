import java.util.Scanner;

public class SquareIt
{
    /**
     * Should square any number in the range
     * [0 to 1000]
     */
    public static int squareIt(int num) //this previously took a byte num
    {
	return num * num;
    }

    public static void main(String[] args)
    {
	Scanner input = new Scanner(System.in);
	System.out.print("Enter a number: ");

	//byte num = Byte.parseByte(input.next()); //java.lang.Byte not imported?

	int num = input.nextInt(); //Changed byte type to short and used nextInt() method on it

	// An alternative way to get the number
	// byte num = input.nextByte();

	if (num >= 0 && num <= 1000) //changed or to and
	{
	    // Print out the value squared
	    System.out.println("Squared: " + squareIt(num));
	}
	else
	{
	    System.out.println("Invalid number.");
	}
    }
}
