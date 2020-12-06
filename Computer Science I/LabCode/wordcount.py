import sys

def countWords(iFile):
    text =  iFile.read()
    s = text.split()
    print("Word count: " + str(len(s)))
    print(len(text))
def main():
    iFile = sys.argv[1]
    iFile = open(iFile,"r")
    countWords(iFile)
    iFile.close()

main()
