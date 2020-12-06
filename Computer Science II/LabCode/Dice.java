import java.util.Random;

public class Dice {

   public static void main(String[] args) {
       int[] list = {0,0,0,0,0,0};
       Random rand = new Random();
       for (int i = 0; i < 5000; i++){
	   int n = rand.nextInt(6)+1;
	   list[n-1] = list[n-1] + 1;
       }
       int idx = 1;
       for (int member: list){
	   System.out.println("" + idx + " was rolled: " + member + " times.");
	   idx += 1;
       }
       int sum = 0;
       for (int member: list){
	   sum += member;
       }
       System.out.println("The total number of rolls was : " + sum);
   }
}
