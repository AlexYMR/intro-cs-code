public class Violin extends stringInstruments
{
    public Violin()
    {
	this(4);
    }
    public Violin(int numStrings)
    {
	this.instrumentName = "Violin";
	this.numStrings = numStrings;
    }

    public void play()
    {
	System.out.println("A " + getStrings() + "-string " + getName() + " is so calming");
    }
} 
