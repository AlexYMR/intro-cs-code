import java.util.Random;

/**
 * A very simple set of random numbers can be generated
 * using the formula:
 * randNum = (a*randNum + c) mod m
 * and the initial value for randNum is
 * found by using some initial seed value as in
 * (a*seed + c) mod m
 *
 * The values a, c, and m are constants
 *
 * This method of generating random numbers is
 * know as a Linear Congruential Generator
 */
public class RandomNum
{
    /**
     * These are two constants used in mathematical formula
     * to generate a random number.  The third, m, should be 2^48
     */
    private static final long a = 25214903917L;
    private static final int c = 11;

    /**
     * Instance variable to hold the current value of the random number
     */
    private long randNum;

    /**
     * Empty constructor
     * Initializes randNum using the current system time as the seed
     * where the current system time is usually in milliseconds
     * or nanoseconds
     */
    public RandomNum()
    {
	
    }

    /**
     * Initializes the current random number using the given seed
     */
    public RandomNum(long seed)
    {
	
    }

    /**
     * Produces the next random number as an int
     * based on the mathematical formula given above.
     * Here the variable bits is used to control which
     * bits within randNum are used as the random number
     * Simulations have shown that using certain groups of bits produces
     * sequences of random numbers that seem to be truly random
     */ 
    protected int next(int bits)
    {
       
    }

    /**
     * returns the next random number as a double 
     * between 0.0 (inclusive) and 1.0(exclusive)
     */
    public double nextDouble()
    {
	
    }
}

