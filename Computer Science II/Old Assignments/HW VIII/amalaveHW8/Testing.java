import java.util.HashMap;
import java.io.IOException;
import java.util.Set;
import java.util.TreeSet;

public class Testing{
    public static void main(String[] args) throws IOException{
	//Expression e = null;//Operand or OperatorExpression
	//String[] postfix = {"4","5","a","-9","+","-","*"};
	//String[] postfix = {"1","2","+","3","4","+","a","+", "+"};
	//String [] postfix = {"7","a","+"};
	//String[] postfix = {"a","b","+"};
	//String[] postfix = {"y","4","x","0","*","+","*"};
	//String[] postfix = {"1","2","+"};
	//String[] infix = {"1","+","2","*","3"};
	//String[] infix = {"2","*","3","+","1","*","2"};
	//String[] infix = {"(","1","+","2",")","*","3"};
	String[] infix = {"(","1","+","2",")","*","(","4","+","4",")","/","2"};
	//Expression e = Expression.expressionFromPostfix(postfix);
	Expression e = Expression.expressionFromInfix(infix);
	System.out.println(e.toPrefix());
	System.out.println(e.toPostfix());
	System.out.println(e.toInfix());
	/*Set<String> ts = e.getVariables();
	HashMap<String, Integer> hs = new HashMap<String,Integer>();
	for (String s : ts){
	    if (s.equals("x")){
		hs.put(s,3);
	    }
	    else{
		hs.put(s,4);
	    }
	}
	System.out.println(e.evaluate(hs));*/
	//e.drawExpression("somth.dot")
	//String[] postfix2 = {"b","a","+"};
	//String[] postfix2 = {"y","4","0","x","*","+","*"};
	//Expression e2 = Expression.expressionFromPostfix(postfix2);
	//System.out.println(e.equals(e2));
	//System.out.println(e.simplify());
	//System.out.println(e.getClass());
    }
}
