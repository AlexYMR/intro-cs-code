import sys

def encrypt(plainText):
    rail1 = ''
    rail2 = ''
    for i in range(len(plainText)):
        #--Every third character gets added to rail1, and the rest
        #--go to rail2 (encryption pattern from the first part of the lab)
        if i % 3 == 0:
            rail1 = rail1 + plainText[i]
        else:
            rail2 = rail2 + plainText[i]

    return rail1+rail2

def main():
    iFile = sys.argv[1]
    oFile = sys.argv[2]

    iFile = open(iFile,"r")
    oFile = open(oFile,"w")
    
    text = iFile.read()
    s = ""
    for i in range(len(text)):
        if text[i:i+1] == "\n":
            s = s + encrypt(text[:i]) + "\n"
            text = text[i+1:]
    s = s + encrypt(text)
    oFile.write(s)

    print(repr(text))

    iFile.close()
    oFile.close()
    
main()
