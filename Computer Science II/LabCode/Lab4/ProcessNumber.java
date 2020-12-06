import java.util.Scanner;

public class ProcessNumber{
    private static int number;
    
    public static int setNumber(){
	return number;
    }
    public static void main(String[] args){
	String binaryNumber = new String("");
	Scanner input = new Scanner(System.in);
	System.out.print("Enter a number: ");
	if(input.hasNextInt()){
	    number = input.nextInt();
	    System.out.println("Your number: " + number);
	}
	while (number != 0){
	    binaryNumber = (number % 2) + binaryNumber;
	    number = number / 2;
	}
	System.out.println("The number in binary is: " + binaryNumber);
    }
}
