import sys

def getInfo(ifile):
    line = ifile.readline()
    info = {}
    readingChapters = False
    newChapter = True
    augur = False
    currentBook = ""
    while line != "":
        ls = line.split("*")
        if readingChapters:
            print(ls)
        if ls[0] == "(":
            readingChapters = False
            newChapter = True
        elif ls[-1] == ")\n" and ls[0] != "The two towers\n" and newChapter:
            readingChapters = True
            newChapter = False
            currentBook = ls[0]
            info[currentBook] = ""
                
                
        line = ifile.readline()

def printReview(ifile):
    line = ifile.readline()
    reviews = {}
    readingReview = False
    numReview = 0
    augur = False
    while line != "":
        if augur:
            augur = False
            readingReview = False
        ls = line.split("*")
        if ls[0] == "(":
            readingReview = True
            numReview = numReview + 1
        elif ls[-1] == ")\n":
            augur = True
            ls[-1] = ")"
        if readingReview:
            if numReview in reviews.keys():
                ls[len(ls)-1] = ls[len(ls)-1][:-1]
                for i in range(len(ls)):
                   reviews[numReview] = reviews[numReview] + ls[i]
            else:
                reviews[numReview] = ""
        line = ifile.readline()
    for i,v in reviews.items():
        print(v)-

def main():
    ifile = sys.argv[1]
    ifile = open(ifile,"r")
    printReview(ifile)
    #getInfo(ifile)
    ifile.close()

main()
