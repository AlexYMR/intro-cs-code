#--------------------------
# // threeraildecrypt.py
# // Part of HW4
# // Problem 2, Part B
#--------------------------

import sys

def decrypt(cipherText):
    """
    Decrypts a given string by determining the size of three rails and combining them based on the rule that every third character gets put into a rail, and
    that the string is supposed to be processed three times (to fill up each rail).
    Input: plainText (string to encrypt)
    Output: Encrypted text
    """
    rail1 = ""
    rail2 = ""
    rail3 = ""
    lengthOfRail1 = 0
    lengthOfRail2 = 0
    tempText = ""

    if len(cipherText) % 3 > 0: #--Determines size of rail1
        lengthOfRail1 = int(len(cipherText)/3+1)
        rail1 = cipherText[:lengthOfRail1]
    else:
        lengthOfRail1 = int(len(cipherText)/3)
        rail1 = cipherText[:lengthOfRail1]

    tempText = cipherText[lengthOfRail1:]

    if len(tempText) % 3 > 0: #--Determines size of rail2
        lengthOfRail2 = int(len(tempText)/2+1)
        rail2 = tempText[:lengthOfRail2]
    else:
        lengthOfRail2 = int(len(tempText)/2)
        rail2 = tempText[:lengthOfRail2]

    rail3 = tempText[lengthOfRail2:] #--Determines size of rail3
    plainText = ""

    for i in range(len(cipherText)):
        #--Creates plainText by going through the rails and arranging their characters properly (rail1 characters into 0 slot, rail2 characters follow, and
        #--rail3 characters follow rail2 characters [individually])
        if i % 3 == 0:
            plainText = plainText + rail1[0]
            rail1 = rail1[1:]
        elif i % 3 == 1:
            plainText = plainText + rail2[0]
            rail2 = rail2[1:]
        elif i % 3 == 2:
            plainText = plainText + rail3[0]
            rail3 = rail3[1:]

    return plainText

def main():
    """
    Takes two arguments, an input file and an output file. Uses the text in the input file, line by line, and decrypts it, line by line.
    The decrypted text is then written into the output file.
    """
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

    iFile.close()
    oFile.close()

main()
