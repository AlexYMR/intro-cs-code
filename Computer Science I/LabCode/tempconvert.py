import sys

def convert(iFile):
    tab = []
    for line in iFile:
        s = line.split()
        if len(s) > 1:
            month = s[0]
            day = s[1]
            year = s[2]
            tempF = float(s[3])
            tempC = (tempF - 32)*(5/9)
        tab.append("On " + month + "/" + day + "/" + year + " the temperature was " + str(tempF) + " F or " + str(tempC) + " C" )
    for line in tab:
        print(line+"\n")
        
def main():
    iFile = sys.argv[1]
    iFile = open(iFile,"r")
    convert(iFile)
    iFile.close()

main()
