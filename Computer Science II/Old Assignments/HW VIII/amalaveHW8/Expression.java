/*
 * Expression.java
 * Part of Homework 8, problems 1-6
 * Contains multiple classes used in building an expression tree
 */

import java.util.HashMap;
import java.util.Stack;
import java.util.Set;
import java.util.TreeSet;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public abstract class Expression
{
    //Determines whether a string can be expressed as an integer value
    private static boolean isInteger(String s){
	boolean decimalFound = false;
	boolean minusFound = false;
	for (int i = 0; i<s.length();i++){
	    char c = s.charAt(i);
	    decimalFound = ((c == '.' && !decimalFound) ? true:false);
	    minusFound = ((c == '-' && !minusFound) ? true:false);
	    if (!Character.isDigit(c) && !minusFound && !decimalFound || decimalFound && s.length() < 2 || minusFound && s.length() < 2){
		return false;
	    } 
	}
	return true;
    }

    //Determines whether a string fits the criteria of being an operator
    private static boolean isOperator(String s){
	for (int i = 0; i<s.length();i++){
	    char c = s.charAt(i);
	    if (s.length()>1 || c != '+' && c != '-' && c != '*' && c != '/'){
		return false;
	    }
	}
	return true;
    }
    
   public static Expression expressionFromPostfix(String[] postfix)
   {
       Stack<Expression> expStack = new Stack<Expression>();
       for (int i = 0; i < postfix.length; i++){
	   //operator, operand, or variable?
	   //must know whether string can be quantified (then it's a number), else, must know if it begins w/ a letter (variable), or if it's + - / * (operator)
	   if (isInteger(postfix[i])){
	       Expression integ = new IntegerOperand(Integer.parseInt(postfix[i]));
	       expStack.push(integ);
	   }
	   else{
	       if (isOperator(postfix[i])){
		   Expression term2 = expStack.pop();
		   Expression term1 = expStack.pop();
		   Expression oper = null;
		   if (postfix[i].equals("+")){
		       oper = new SumExpression(term1,term2);
		   }
		   else if (postfix[i].equals("-")){
		       oper = new DifferenceExpression(term1,term2);
		   }
		   else if (postfix[i].equals("*")){
		       oper = new ProductExpression(term1,term2);
		   }
		   else if (postfix[i].equals("/")){
		       oper = new QuotientExpression(term1,term2);
		   }
		   expStack.push(oper);
	       }
	       else{
		   Expression var = new VariableOperand(postfix[i]);
		   expStack.push(var);
	       }
	   }
       }
       return expStack.pop();
   }
    
    //Used for expressionFromInfix
    //Cycles through the operator stack in order to group expressions properly
    public static void cycleThroughStack(Stack<Expression> expStack, Stack<String> opStack, HashMap<String,Integer> precedence, boolean pass){ 
	while(!opStack.empty() && !opStack.peek().equals("(") && pass){
	    String operString = opStack.pop();
	    Expression term2 = expStack.pop();
	    Expression term1 = expStack.pop();
	    Expression oper = null;
	    if (operString.equals("+")){
		oper = new SumExpression(term1,term2);
		expStack.push(oper);
	    }
	    else if (operString.equals("-")){
		oper = new DifferenceExpression(term1,term2);
		expStack.push(oper);
	    }
	    else if (operString.equals("*")){
		oper = new ProductExpression(term1,term2);
		expStack.push(oper);
	    }
	    else if (operString.equals("/")){
		oper = new QuotientExpression(term1,term2);
		expStack.push(oper);
	    }
	}
	if (!opStack.empty() && opStack.peek().equals("(")){
	    opStack.pop();
	}
    }

    public static Expression expressionFromInfix(String[] infix)
   {
       Stack<Expression> expStack = new Stack<Expression>();
       Stack<String> opStack = new Stack<String>();
       
       //Set-up of operator precedence reference
       HashMap<String,Integer> precedence = new HashMap<String,Integer>();
       precedence.put("*",1);
       precedence.put("/",1);
       precedence.put("+",2);
       precedence.put("-",2);
       precedence.put("(",0); //value is not actually used (in HashMap in order to tell if it's an operator or not)
       precedence.put(")",0); //value is not actually used (in HashMap in order to tell if it's an operator or not)
       
      for (int i = 0; i < infix.length; i++){
	   if (isInteger(infix[i])){
	       Expression integ = new IntegerOperand(Integer.parseInt(infix[i]));
	       expStack.push(integ);
	   }
	   else{
	       if (precedence.containsKey(infix[i])){
		   if (infix[i].equals("(") || opStack.empty() || (!opStack.empty() && precedence.get(opStack.peek()) > precedence.get(infix[i]) && !infix[i].equals(")"))){
		       opStack.push(infix[i]);
		   }
		   else if(!opStack.empty() && precedence.get(opStack.peek()) < precedence.get(infix[i]) && !infix[i].equals(")")){ //if operation has higher precedence
		       boolean pass = (precedence.get(opStack.peek()) < precedence.get(infix[i]) ? true:false);
		       cycleThroughStack(expStack, opStack, precedence, pass);
		       opStack.push(infix[i]);
		   }
		   else if (infix[i].equals(")")){
		       cycleThroughStack(expStack, opStack, precedence, true);
		   }
	       }
	       else{
		   Expression var = new VariableOperand(infix[i]);
		   expStack.push(var);
	       }
	   }
       }
      cycleThroughStack(expStack, opStack, precedence, true);
      return expStack.pop();
   }

   public abstract String toPrefix();

   public abstract String toInfix();

   public abstract String toPostfix();

   @Override
   public String toString()
   {
      return toInfix();
   }
   
   public abstract Expression simplify();

   public abstract int evaluate(HashMap<String, Integer> assignments);

   public abstract Set<String> getVariables();

   @Override
   public abstract boolean equals(Object obj);

   public void drawExpression(String filename) throws IOException
   {
      BufferedWriter bw = null;
      FileWriter fw = new FileWriter(filename);
      bw = new BufferedWriter(fw);
      
      bw.write("graph Expression {\n");
      
      drawExprHelper(bw);
      
      bw.write("}\n");
      
      bw.close();
      fw.close();     
   }
   protected abstract void drawExprHelper(BufferedWriter bw) throws IOException;
}

abstract class Operand extends Expression{}
/************
   
   INTEGERS

************/
class IntegerOperand extends Operand
{
   protected int operand;
   public IntegerOperand(int operand)
   {
      this.operand = operand;
   }
   public String toPrefix()
   {
       return String.valueOf(operand);
   }
   public String toPostfix()
   {
       return String.valueOf(operand);
   }   
   public String toInfix()
   {
       return String.valueOf(operand);      
   }
   public Expression simplify()
   {
       return new IntegerOperand(operand);
   }   
   public int evaluate(HashMap<String, Integer> assignments)
   {         
       return operand;
   }
   public Set<String> getVariables()
   {
      return new TreeSet<String>();
   }
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof IntegerOperand))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;

       IntegerOperand o = (IntegerOperand) obj;
       return operand == o.operand;
   }   

   protected void drawExprHelper(BufferedWriter bw) throws IOException
   {
      bw.write("\tnode"+hashCode()+"[label="+operand+"];\n");
   }
}
/************
   
   VARIABLES

************/
class VariableOperand extends Operand
{
   protected String variable;

   public VariableOperand(String variable)
   {
      this.variable = variable;
   }

   public String toPrefix()
   {
       return this.variable;
   }

   public String toPostfix()
   {
       return this.variable;
   }   

   public String toInfix()
   {
       return this.variable;      
   }

   public Expression simplify()
   {
       return new VariableOperand(variable);
   }   

   public int evaluate(HashMap<String, Integer> assignments)
   {
       return assignments.get(variable);
   }

   public Set<String> getVariables()
   {
       TreeSet<String> ts = new TreeSet<String>();
       ts.add(variable);
       return ts;
   }

   @Override
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof VariableOperand))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;

       VariableOperand o = (VariableOperand) obj;
       return variable.equals(o.variable);
   }   

   protected void drawExprHelper(BufferedWriter bw) throws IOException
   {
      bw.write("\tnode"+hashCode()+"[label="+variable+"];\n");
   }   
}

abstract class OperatorExpression extends Expression
{
   protected Expression left;
   protected Expression right;

   public OperatorExpression(Expression left, Expression right)
   {
      this.left = left;
      this.right = right;
   }
    
    public String toPrefix()
   {
       return new String(getOperator() + left.toPrefix() + right.toPrefix());
   }

   public String toPostfix()
   {
       return new String(left.toPostfix() + right.toPostfix() + getOperator());
   }   

   public String toInfix()
   {
       return new String("(" + left.toInfix() + getOperator() + right.toInfix() + ")");
   }

    public Set<String> getVariables()
    {
	TreeSet<String> ts = new TreeSet<String>();
	ts.addAll(left.getVariables());
	ts.addAll(right.getVariables());
	return ts;
    }

   protected abstract String getOperator();     

   protected void drawExprHelper(BufferedWriter bw) throws IOException
   {
      String rootID = "\tnode"+hashCode();
      bw.write(rootID+"[label=\""+getOperator()+"\"];\n");

      bw.write(rootID + " -- node" + left.hashCode() + ";\n");
      bw.write(rootID + " -- node" + right.hashCode() + ";\n");
      left.drawExprHelper(bw);
      right.drawExprHelper(bw);
   }   
}
/************
   
   SUM OP

************/
class SumExpression extends OperatorExpression
{
   public SumExpression(Expression left, Expression right)
   {
      super(left, right);
   }

   protected String getOperator()
   {
      return "+";
   }

   public Expression simplify()
   {
       if (left instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) left;
	   if (IO.operand == 0){
	       return right.simplify();
	   }
       }
       if (right instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) right;
	   if (IO.operand == 0){
	       return left.simplify();
	   }
       }
       if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand rightIO = (IntegerOperand) right;
	   IntegerOperand leftIO = (IntegerOperand) left;
	   return new IntegerOperand(leftIO.operand + rightIO.operand);
       }
       else if (!(right instanceof OperatorExpression) && !(left instanceof OperatorExpression)){
	   return this; //breaks if an expression such as 1 2 + 3 4 + a + + is passed through (not sure if this is a case that we're supposed to be able to handle) [stack overload]
	   // if it is a case we're supposed to handle, encouragement in the right direction would be appreciated
       }
       right = right.simplify();
       left = left.simplify();
       return this.simplify();
   }   

   public int evaluate(HashMap<String, Integer> assignments)
   {
       return left.evaluate(assignments) + right.evaluate(assignments);
   }

   @Override
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof OperatorExpression))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;

       OperatorExpression e = (OperatorExpression) obj;
       return (this.getOperator().equals(e.getOperator()) &&
	   ((this.right.equals(e.right) &&
	     this.left.equals(e.left)) || (this.right.equals(e.left) && this.left.equals(e.right))));
   }   
}
/*****************
   
   DIFFERENCE OP

*****************/
class DifferenceExpression extends OperatorExpression
{
   public DifferenceExpression(Expression left, Expression right)
   {
      super(left, right);
   }

   protected String getOperator()
   {
      return "-";
   }

   public Expression simplify()
   {
       if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand leftIO = (IntegerOperand) left;
	   IntegerOperand rightIO = (IntegerOperand) right;
	   if (leftIO.operand == rightIO.operand){
	       return new IntegerOperand(0);
	   }
       }
       if (right instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) right;
	   if (IO.operand == 0){
	       return left.simplify();
	   }
       }
       if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand rightIO = (IntegerOperand) right;
	   IntegerOperand leftIO = (IntegerOperand) left;
	   return new IntegerOperand(leftIO.operand - rightIO.operand);
       }
       else if (!(right instanceof OperatorExpression) && !(left instanceof OperatorExpression)){
	   return this; 
       }
       right = right.simplify();
       left = left.simplify();
       return this.simplify();
   }   

   public int evaluate(HashMap<String, Integer> assignments)
   {
       return left.evaluate(assignments) - right.evaluate(assignments);
   }

   @Override
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof OperatorExpression))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;
       
       OperatorExpression e = (OperatorExpression) obj;
       return (this.getOperator().equals(e.getOperator()) &&
	   (this.right.equals(e.right) &&
	    this.left.equals(e.left)));
   }      
}
/***************
   
   PRODUCT OP

***************/
class ProductExpression extends OperatorExpression
{
   public ProductExpression(Expression left, Expression right)
   {
      super(left, right);
   }

   protected String getOperator()
   {
      return "*";
   }

   public Expression simplify()
   {
       if (left instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) left;
	   if (IO.operand == 1){
	       return right.simplify();
	   }
	   else if (IO.operand == 0){
	       return new IntegerOperand(0);
	   }
       }
       if (right instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) right;
	   if (IO.operand == 1){
	       return left.simplify();
	   }
	   else if (IO.operand == 0){
	       return new IntegerOperand(0);
	   }
       }
       if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand rightIO = (IntegerOperand) right;
	   IntegerOperand leftIO = (IntegerOperand) left;
	   return new IntegerOperand(leftIO.operand * rightIO.operand);
       }
       else if (!(right instanceof OperatorExpression) && !(left instanceof OperatorExpression)){
	   return this;
       }
       right = right.simplify();
       left = left.simplify();
       return this.simplify();
   }   

   public int evaluate(HashMap<String, Integer> assignments)
   {
       return left.evaluate(assignments)*right.evaluate(assignments);
   }

   @Override
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof OperatorExpression))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;
       
       OperatorExpression e = (OperatorExpression) obj;
       return (this.getOperator().equals(e.getOperator()) &&
	   ((this.right.equals(e.right) &&
	     this.left.equals(e.left)) || (this.right.equals(e.left) && this.left.equals(e.right))));
   }      
}
/***************
   
   QUOTIENT OP

***************/
class QuotientExpression extends OperatorExpression
{
   public QuotientExpression(Expression left, Expression right)
   {
      super(left, right);
   }

   protected String getOperator()
   {
      return "/";
   }

   public Expression simplify()
   {
      if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand leftIO = (IntegerOperand) left;
	   IntegerOperand rightIO = (IntegerOperand) right;
	   if (leftIO.operand == rightIO.operand){
	       return new IntegerOperand(1);
	   }
       }
       if (right instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) right;
	   if (IO.operand == 1){
	       return left.simplify();
	   }
       }
       if (left instanceof IntegerOperand){
	   IntegerOperand IO = (IntegerOperand) left;
	   if (IO.operand == 0){
	       return new IntegerOperand(0);
	   }
       }
       if (left instanceof IntegerOperand && right instanceof IntegerOperand){
	   IntegerOperand rightIO = (IntegerOperand) right;
	   IntegerOperand leftIO = (IntegerOperand) left;
	   return new IntegerOperand(leftIO.operand / rightIO.operand);
       }
       else if (!(right instanceof OperatorExpression) && !(left instanceof OperatorExpression)){
	   return this; 
       }
       right = right.simplify();
       left = left.simplify();
       return this.simplify();
   }   

   public int evaluate(HashMap<String, Integer> assignments)
   {
       return left.evaluate(assignments) / right.evaluate(assignments);
   }

   @Override
   public boolean equals(Object obj)
   {
       if (obj == null || !(obj instanceof OperatorExpression))
	 return false;
      else if (this == obj) // Refer to same object in memory or not
	 return true;
       
       QuotientExpression e = (QuotientExpression) obj;
       return (this.getOperator().equals(e.getOperator()) &&
	   (this.right.equals(e.right) &&
	    this.left.equals(e.left)));
   }      
}
