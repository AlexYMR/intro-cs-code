#----------------
# // squareroot.py
# // Part of homework 2
# // Problem 1
#-----------------

import sys
import math

def squareRoot(n):
    """
    Utilizes a formula in order to approximate the value of sqrt(2);
    the more terms, the more accurate the estimate
    """
    acc = 0
    for i in range(n):
        #1 is a constant in the formula, so I leave it alone for the
        #calculations
        acc = 1/(2+acc)
        #prints the estimation along with the difference between it and
        #the math module's estimation of sqrt(2)
        print(acc+1, " ",(acc+1)-math.sqrt(2))

def main():
    #calls squareRoot with a value of 20, as the homework requires
    squareRoot(20)

main()
