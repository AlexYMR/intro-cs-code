import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class ASCIIArt
{
    ArrayList<String> data = new ArrayList<String>();

    /**
     * Opens the file
     * Reads each line of file storing it in data instance variable
     */
    public ASCIIArt(String fileName)
    {
	Scanner input = null;
	try
	{
	    input = new Scanner(new File(fileName));
	}
	catch(FileNotFoundException fnfe)
	{
	    System.out.println("Could not find file: " + fileName);
	    System.exit(0);
	}

	while (input.hasNextLine())
	{
	    String line = input.nextLine();
	    line += "\n";
	    data.add(line);
	}

	input.close();
    }

    @Override
    public String toString()
    {
	String str = "";
	for (int i = 0; i < data.size(); i++)
	    str += data.get(i);

	return str;
    }

    public static void main(String [] args)
    {
	ASCIIArt art = new ASCIIArt(args[0]);
	System.out.println("\n\n");
	
	System.out.println(art);
    }
}
