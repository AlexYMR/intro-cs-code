#----------------------------
# // fractiontest.py
# // Part of HW9
# // Problem 1
#----------------------------

from fraction import *

def main():
    """
    Several lines of code that test the methods of the module fraction.py
    """
    f1 = Fraction(1,3)
    f2 = Fraction(1,2)
    
    print(f1/f2)
    print(Fraction(20,100))
    print(f1-f2)
    print(f1+f2)
    print(f1 < f2)
    print(f2 < f1)
    print(float(f2))
    print(int(f2))
    print(Fraction(0,0)-f1)

main()
