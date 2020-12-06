#--------------------------
# // cleanfooter.py
# // Part of HW7
# // Problem 1
#--------------------------

import sys

def main():
    """
    Removes the final two lines of the file to eliminate the footer of the play.
    Input: File (a play)
    Output: File without the footer
    """
    ifile = sys.argv[1]
    ofile = sys.argv[2]

    ifile = open(ifile,"r")
    ofile = open(ofile,"w")
    
    text = ifile.readlines()
    text = text[:-2]
    
    s = ""
    for i in text:
        s = s + i
    
    ofile.write(s)

    ifile.close()
    ofile.close()

main()
