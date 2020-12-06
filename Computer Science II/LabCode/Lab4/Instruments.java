public abstract class Instruments{
    protected String instrumentName;
    //public Instruments(String name){
    //this.instrumentName = name;
    //}
    public abstract void play();
    public String getName(){
	return instrumentName;
    }
    public void setName(String name){
	instrumentName = name;
    }
}
