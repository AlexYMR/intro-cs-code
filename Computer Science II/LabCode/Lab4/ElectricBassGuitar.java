public class ElectricBassGuitar extends stringInstruments
{
    public ElectricBassGuitar()
    {
	this(6);
    }
    public ElectricBassGuitar(int numStrings)
    {
	this.instrumentName = "Electric Bass Guitar";
	this.numStrings = numStrings;
    }

    public void play()
    {
	System.out.println("A " + getStrings() + "-string " + getName() + " hits all the right notes");
    }
} 
