#--------------------------------
# // cleandirections.py
# // Part of HW2
# // Problem 1
#-------------------------------

import sys

def main():
    """
    Removes any directorial comments, which are enclosed in brackets: []. 
    Input: File (a play)
    Output: a modified file without the play directions
    """
    ifile = sys.argv[1]
    ofile = sys.argv[2]

    ifile = open(ifile,"r")
    ofile = open(ofile,"w")
    
    lines = ifile.readlines()
    inside = False
    text = ""
    #--Uses a boolean system to check if the computer is within a bracket
    #--If so, marks it for skipping, if not, concatenates it to a string accumulator
    for i in lines:
        skip = False
        line = i.split()
        if line[0].startswith("["):
            inside = True
            #print(line)
        if inside and (line[-1].endswith("]\n") or line[-1].endswith("]")):
            skip = True
            inside = False
        if not inside and not skip:
            text = text + i

    ofile.write(text)

    ifile.close()
    ofile.close()

main()
