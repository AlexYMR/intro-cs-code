#--------------------------
# // cleansongs.py
# // Part of HW7
# // Problem 1
#--------------------------

import sys

def main():
    """
    Removes the songs contained within plays by looking for indentations and capitalization.
    Input: File (a play)
    Output: Revised file without songs
    """
    ifile = sys.argv[1]
    ofile = sys.argv[2]
    ifile = open(ifile,"r")
    ofile = open(ofile,"w")
    lines = ifile.readlines()
    text = ""
    for i in lines:
        #--Checks if there's an indent
        if i[0] == " ":
            #--Checks if the line is in all caps
            if i != i.upper():
                text = text + i
        else:
            text = text + i

    ofile.write(text)

    ifile.close()
    ofile.close()

main()
