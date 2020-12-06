import java.util.ArrayList;

public class QuadraticEq {
    
    private int a = 0;
    private int b = 0;
    private int c = 0;
    private Double root1 = null;
    private Double root2 = null;
    private double d = 0;

    public QuadraticEq(int m,int n,int b) {
	this.a = m;
	this.b = n;
	this.c = b;
    }
   public static void main(String[] args) {
       ArrayList<QuadraticEq> array = new ArrayList<QuadraticEq>(){{
       add(new QuadraticEq(6,11,-35));
       add(new QuadraticEq(1,0,-4));
       add(new QuadraticEq(1,-3,-4));
       add(new QuadraticEq(1,-7,0));
       add(new QuadraticEq(3,2,-1));
       add(new QuadraticEq(1,-6,9));
	   }};
       for (QuadraticEq member: array){
	   member.findRoots();
	   System.out.println(member.toString());
	   System.out.println("Given the above equation, with a value of x = 3, the output is: " + member.solve(3));
       }       
   }
    public void findRoots(){
	//System.out.println("Given quadratic equation:"+a+"x^2 + "+b+"x + "+c);
        this.d = this.b * this.b - 4 * this.a * this.c;
        if(this.d > 0){
            this.root1 = ( - this.b + Math.sqrt(this.d))/(2*this.a);
            this.root2 = (-this.b - Math.sqrt(this.d))/(2*this.a);
        }
        else if(this.d == 0){
            this.root1 = (-this.b+Math.sqrt(d))/(2*this.a);
        }
        else{
            System.out.println("Roots are imaginary.");
	    return;
        }
    }
    public double solve(int x){
	return this.a*Math.pow(x,2)+this.b*x+this.c;
    }
    public String toString(){
	return ""+this.a+"x^2 + "+this.b+"x + "+this.c + " has roots " + this.root1 + " and " + this.root2;
    }
}
