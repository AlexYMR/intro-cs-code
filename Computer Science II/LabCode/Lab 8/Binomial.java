import java.util.Arrays;

public class Binomial{
    public static int memoizedRecurse(int n, int k){
	int[][] array = new int[n+1][k+1];
       for (int i = 0;i<=n;i++){
	    for (int j = 0;j<=k;j++){
		if (j == 0 || i == j)
		    array[i][j] = 1;
		else{
		    array[i][j] = 0;
		}
	    }
       }
	return memoRecurse(n,k,array);
    }
    public static int memoRecurse(int n, int k, int[][] array){
	if (array[n][k] != 0)
	    return array[n][k];
	else{
	    array[n][k] = memoRecurse(n-1,k-1,array)+memoRecurse(n-1,k,array);
	    return array[n][k];
	}
    }
    public static int recurse(int n, int k){
	if ((n == k) || (k == 0))
	    return 1;
	else{
	    return recurse(n-1,k-1)+recurse(n-1,k);
	}
    }
    public static void main (String[] args){
	for (int i = 0; i <= 6; i++){
	    for (int j = 0; j <= i;  j++){
		int coeff = recurse(i,j);
		System.out.println("(n: " + i + ", k: " + j + "): " + coeff);
	    }
	}
	for (int i = 0; i <= 6; i++){
	    for (int j = 0; j <= i;  j++){
		int coeff = memoizedRecurse(i,j);
		System.out.println("Memoized (n: " + i + ", k: " + j + "): " + coeff);
	    }
	}
    }
}
