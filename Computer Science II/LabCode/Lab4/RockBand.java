import java.util.ArrayList;

class RockBand
{
    public static void main(String[] args)
    {
	Trumpet trumpet = new Trumpet();
	Cannon cannon = new Cannon();
	Violin violin = new Violin();
	ElectricGuitar guitar1 = new ElectricGuitar();
	ElectricGuitar guitar2 = new ElectricGuitar(7);
	ElectricBassGuitar bass = new ElectricBassGuitar(4);
	
	ArrayList<Instruments> array = new ArrayList<Instruments>();
	array.add(trumpet);
	array.add(cannon);
	array.add(violin);
	array.add(guitar1);
	array.add(guitar2);
	array.add(bass);
	
	for (Instruments member: array){
	    member.play();
	};
	/*
	trumpet.play();
	cannon.play();
	violin.play();
	guitar1.play();
	guitar2.play();
	bass.play();
	*/

	System.out.println("\n*** What an incredible concert ***");
    }
}
