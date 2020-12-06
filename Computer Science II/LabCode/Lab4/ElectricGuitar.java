public class ElectricGuitar extends stringInstruments
{
    public ElectricGuitar()
    {
	this(6);
    }

    public ElectricGuitar(int numStrings)
    {
	this.instrumentName = "Electric Guitar";
	this.numStrings = numStrings;
    }

    public void play()
    {
	System.out.println("A " + getStrings() + "-string " + getName() + " is rocking");
    }
} 
