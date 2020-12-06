import java.util.ArrayList;
import java.util.HashMap;

/**
 * Basic class for a 
 * Stack to hold String
 */

public class Stack
{
    // Fill in the type for diamond operator
    private ArrayList<String> data;

    public Stack()
    {
	data = new ArrayList<String>();
    }

    // Takes only one parameter, fill in parameter type
    public void push(String val)
    {
	data.add(val);
    }

    // Fill in the return type as well as code
    public String pop()
    {	
	if(!this.isEmpty()){
	    return data.remove(data.size()-1);
	} else {
	    return "0";
	}
    }

    // Fill in the return type as well as code
    public String peek()
    {
	if(!this.isEmpty()){
	    return data.get(data.size()-1);
	} else {
	    return "0";
	}
    }

    // Only needs 1 line of code
    public boolean isEmpty()
    {
	return data.size() == 0;
    }

    // Only needs 1 line of code
    public int size()
    {
	return data.size();
    }

    // Don't fill in this method until after midway check
    public static String infix2Postfix(String infix)
    {
	String postfix = "";
	Stack opStack = new Stack();

	// Used to keep track of operator precedence
	// DO NOT MODIFY
	HashMap<String, Integer> opPrec = new HashMap<String, Integer>();
	opPrec.put("*", 3);
	opPrec.put("/", 3);
	opPrec.put("+", 2);
	opPrec.put("-", 2);
	opPrec.put("(", 1);
	opPrec.put(")", 0);
	
	for (int i=0; i<infix.length(); i++) {
	    String c = Character.toString(infix.charAt(i));
	    if (!opPrec.containsKey(c)){
		postfix = postfix + c;
	    } else if (c.equals("(")){
		opStack.push(c);
	    } else if (c.equals(")")){
		String top = opStack.peek();
		while (!top.equals("(")){
		    postfix = postfix + opStack.pop();
		    top = opStack.peek();
		}
		opStack.pop();
	    } else {
		    String top = opStack.peek();
		    while(!top.equals("0") && opPrec.get(top) >= opPrec.get(c)){
			postfix = postfix + opStack.pop();
			top = opStack.peek();
		    }
		opStack.push(c);
	    }	
	}

	while(!opStack.isEmpty()){
	    if (!opStack.peek().equals("(") && !opStack.peek().equals(")")){
		postfix = postfix + opStack.pop();
	    } else {
		opStack.pop();
	    }
	}
		
	return postfix;
    }

    public static int postfixEval(String postfix)
    {
	//String evaluation = 0;
	Stack opStack = new Stack();
	
	HashMap<String, Integer> opPrec = new HashMap<String, Integer>();
	opPrec.put("*", 3);
	opPrec.put("/", 3);
	opPrec.put("+", 2);
	opPrec.put("-", 2);
	opPrec.put("(", 1);
	opPrec.put(")", 0);

	for (int i=0; i<postfix.length(); i++) {
	    String c = Character.toString(postfix.charAt(i));
	    if (!opPrec.containsKey(c)){
		opStack.push(c);
	    } else {
		int op2 = Integer.parseInt(opStack.pop());
		int op1 = Integer.parseInt(opStack.pop());
		String result = "0";
		if (c.equals("*")){
		    result = Integer.toString(op1*op2);
		} else if (c.equals("/")){
		    result = Integer.toString(op1/op2); //since this is integer division, it will not return an accurate value
		} else if (c.equals("+")){
		    result = Integer.toString(op1+op2);
		} else if (c.equals("-")){
		    result = Integer.toString(op1-op2);
		}
		opStack.push(result);
	    }
	}
	
	return Integer.parseInt(opStack.pop());
    }

    /**
     * Uncomment various pieces to test
     *
     */
    public static void main(String [] args)
    {
	String str1 = "2+1*4";
	String str2 = "(2+1)*(4+3)";
	String str3 = "2*(1+4/3)+5"; //this solution in postfix returns 9 rather than 29/3, since the function postfixEval is supposed to return an int, and since it's been set that way, I'm leaving it as is
	
	String postfix1 = infix2Postfix(str1);
	String postfix2 = infix2Postfix(str2);
	String postfix3 = infix2Postfix(str3);
	
	System.out.println(str1 + " => " + postfix1);
	System.out.println(str2 + " => " + postfix2);
	System.out.println(str3 + " => " + postfix3);

	System.out.println(postfix1 + " = " + postfixEval(postfix1));
	System.out.println(postfix2 + " = " + postfixEval(postfix2));
	System.out.println(postfix3 + " = " + postfixEval(postfix3));
     }
}
