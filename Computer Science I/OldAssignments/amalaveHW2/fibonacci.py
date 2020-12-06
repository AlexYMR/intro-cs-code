#----------------
# // fibonacci.py
# // Part of homework 2
# // Problem 2
#-----------------

import sys

def fibo(n):
    """
    This function determines numbers in the fibonacci sequence
    Input: desired number of terms
    Output: term, alongside corresponding fibonacci number
    """
    first = 0
    second = 1
    for i in range (1,n+1):
        if (i<=1): 
            #begins sequence (terms 0 and 1 do not have two prior terms)
            newVal = i
        else:
            #continues sequence by adding the previous two numbers in the
            #sequence, and updating the variables
            newVal = first + second
            first = second
            second = newVal
        print(i,newVal)

def main():
    #grabs the desired number of terms from the terminal and calls fibo
    var = int(sys.argv[1])
    fibo(var)

main()
    
