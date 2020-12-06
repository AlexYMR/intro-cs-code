#-------------------------
# // rating.py
# // Part of HW6
# // Problem 2
#-------------------------

import sys

def processRowFormat(iFile,oFile):
    """
    Takes a file containing movie reviews in "row" format, reads it line by line, and returns average scores out of the ratings for each movie alongside the movie names,
    which are written to an output file.
    Input: Input file and output file
    Output: Nothing
    """
    tab = []
    for line in iFile:
        acc = 0
        #--Makes each line into a list
        s = line.split()
        #--Ensures that the line is not empty
        if len(s) > 1:
            for i in range(1,len(s)):
                acc = acc + int(s[i])
        #--Calculates the average score for each movie and formats
        tab.append(s[0] + ": " + str(acc/(len(s)-1)))
    for line in tab:
        #--Writes each index in tab to the file, using "\n" for formatting reasons
        oFile.write(line+"\n")

def processColumnFormat(iFile,oFile):
    """
    Takes a file containing movie reviews in "column" format, reads it line by line, and returns average scores out of the ratings for each movie alongside the movie names,
    which are written to an output file.
    Input: Input file and output file
    Output: Nothing
    """
    #--Dictionary to be used to gather the total number of reviews (the numbers to divide by to calculate the average rating for each movie)
    numReviews = {}
    #--Dictionary to be used to determine the sums of each of the movie reviews
    reviewSums = {}
    for line in iFile:
        #--Makes each line into a list
        s = line.split()
        #--Ensures that the line is not empty
        if len(s) > 1:
            #--Checks if numReviews has the movie title as an index already
           if  s[0] in numReviews:
               numReviews[s[0]] = numReviews[s[0]] + 1
               reviewSums[s[0]] = reviewSums[s[0]] + int(s[1])
           else:
               numReviews[s[0]] = 1
               reviewSums[s[0]] = int(s[1])
    tab = []
    for i,v in reviewSums.items():
        #--Calculates the average score for each movie and formats
        tab.append(i + ": " + str(v/numReviews[i]))
    for line in tab:
        #--Writes each index in tab to the file, using "\n" for formatting reasons
        oFile.write(line+"\n")
        
def main():
    """
    Handles the opening and closing of input and output files, as well as checking whether the files should be processed with
    processRowFormat or processColumnFormat.
    """
    iFile = sys.argv[1]
    oFile = sys.argv[2]

    iFile = open(iFile,"r")
    oFile = open(oFile,"w")
    
    #--Reads the first line and determines which of the two processing functions to use
    line = iFile.readline()
    if line == "#Format: Row\n":
        processRowFormat(iFile,oFile)
    elif line == "#Format: Column\n":
        processColumnFormat(iFile,oFile)
   
    iFile.close()
    oFile.close()

main()
