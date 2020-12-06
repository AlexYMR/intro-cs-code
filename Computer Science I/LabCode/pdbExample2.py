# This file is used to serve as an example of using PDB
# And as an example of function / variable scope


import pdb
 
# For each of the spots below, write down the answers to the questions from the lab on a separate piece of paper.  You should NOT modify the code in any way, but you can use the debugger to help you!


def foo(a):
    print("Spot 1")
    a = 16
    print("Spot 2")

def bar(b):
    print("Spot 3")
    b = b + "6"
    print("Spot 4")
    return int(b)



def main():
    pdb.set_trace()

    print("Here is the beginning!")
    print("Spot 5")
    a = "17"
    print("Spot 6")
    foo(a)
    print("Spot 7")
    a = bar(a)
    print("Spot 8")
    b = 19
    print("Spot 9")

main()
