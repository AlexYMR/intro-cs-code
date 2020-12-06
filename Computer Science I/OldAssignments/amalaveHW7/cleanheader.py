#-----------------------------
# // cleanheader.py
# // Part of HW7
# // Problem 1
#------------------------------

import sys

def main():
    """
    Removes the header of the play provided by searching for the 
    Input: File
    Output:
    """
    ifile = sys.argv[1]
    ofile = sys.argv[2]

    ifile = open(ifile,"r")
    ofile = open(ofile,"w")
    
    line = ifile.readline()
    newLine = line.split()
    title = ""
    writingTitle = False
    first = True
    #--Looks for the title of the play between the words "by" and "of" in the first line
    for i in newLine:
        if writingTitle and i != "by":
            if first:
                first = False
                title = title +  i
            else:
                title = title + " " + i
        if i == "of":
            writingTitle = True
        elif i == "by":
            writingTitle = False
    
    #--Skips all lines until it comes across "ACT"
    while line.split()[0] != "ACT":
        line = ifile.readline()
    
    restOfText = ""
    #--Collects the rest of the text (after the header)
    while line != "":
        restOfText = restOfText + line
        line = ifile.readline()
    
    #--Concatenates the title with the text without the header to finish
    ofile.write(title + "\n" + restOfText)

    ifile.close()
    ofile.close()

main()
