#----------------------------
# // cleanblanks.py
# // Part of HW7
# // Problem 1
#----------------------------

import sys

def main():
    """
    Removes the blank lines of a given file by checking for the character "\n."
    Input: Input file (play)
    Output: File without blank lines
    """
    ifile = sys.argv[1]
    ofile = sys.argv[2]

    ifile = open(ifile,"r")
    ofile = open(ofile,"w")
    
    #--Iterates through each line individually
    for line in ifile:
        if line == "\n":
            line = ""
        ofile.write(line)

    ifile.close()
    ofile.close()

main()
