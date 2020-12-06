import sys

def decrypt(cipherText):
    rail1 = ""
    rail2 = ""
    lengthOfRail1 = 0
    if len(cipherText) % 3 > 0:
        lengthOfRail1 = int(len(cipherText)/3+1)
        rail1 = cipherText[:lengthOfRail1]
    else:
        lengthOfRail1 = int(len(cipherText)/3)
        rail1 = cipherText[:lengthOfRail1]
    rail2 = cipherText[lengthOfRail1:]
    plainText = ""
    for i in range(len(cipherText)):
        if i % 3 == 0:
            plainText = plainText + rail1[0]
            rail1 = rail1[1:]
        else:
            plainText = plainText + rail2[0]
            rail2 = rail2[1:]
    return plainText

def main():
    iFile = sys.argv[1]
    oFile = sys.argv[2]

    iFile = open(iFile,"r")
    oFile = open(oFile,"w")
    
    text = iFile.read()
    s = ""
    for i in range(len(text)):
        if text[i:i+1] == "\n":
            s = s + decrypt(text[:i]) + "\n"
            text = text[i+1:]
    s = s + decrypt(text)
    oFile.write(s)

    #print(repr(text))

    iFile.close()
    oFile.close()

    #print(decrypt("aaabcbcbc"))
    
    
main()
