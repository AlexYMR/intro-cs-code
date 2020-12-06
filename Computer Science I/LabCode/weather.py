import sys

def main():
    ifile = sys.argv[1]
    ifile = open(ifile,"r")
    line = ifile.readline()
    weatherList = []
    readingData = False
    attributes = []
    while line != "":
        ls = line.split(" ")
        if readingData:
            ln = line.split(",")
            ln[4] = ln[4][:-1]
            weatherList.append(ln)
        if ls[0] == "@data\n":
            readingData = True
        line = ifile.readline()
    print(weatherList)
    ifile.close()

def main2():
    ifile = sys.argv[1]
    ifile = open(ifile,"r")
    line = ifile.readline()
    weatherList = []
    readingData = False
    attributes = []
    while line != "":
        ls = line.split(" ")
        if readingData:
            ln = line.split(",")
            ln[4] = ln[4][:-1]
            weatherDict = {}
            for i in range(len(ln)):
                weatherDict[attributes[i]] = ln[i]
            weatherList.append(weatherDict)
        if ls[0] == "@attribute":
            attributes.append(ls[1])
        elif ls[0] == "@data\n":
            readingData = True
        line = ifile.readline()
    print(weatherList)
    ifile.close()
main()
