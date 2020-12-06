import sys
import math

def main():
    numTerms = int(sys.argv[1])
    acc = 0
    sign = -1
    for i in range(0,numTerms+1):
        denominator = (2*i+1)*3**(i)
        sign = sign * (-1)
        currentTerm = 1/denominator
        acc = acc + currentTerm
    return math.sqrt(12)*acc

print(main())
