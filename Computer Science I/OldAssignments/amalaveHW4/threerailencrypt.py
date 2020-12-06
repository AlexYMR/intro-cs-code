#--------------------------
# // threerailencrypt.py
# // Part of HW4
# // Problem 2, Part A
#--------------------------

import sys

def encrypt(plainText):
    """
    Encrypts a given string by making three rails and combining them. The three rails are filled by characters depending on where they are positioned
    in the string. In this instance, every third character gets put into a rail, and the string is processed three times, for a total of three rails.
    Input: plainText (string to encrypt)
    Output: Encrypted text
    """
    rail1 = ""
    rail2 = ""
    rail3 = ""
    temporary = ""
    for i in range(len(plainText)):
        #--Splits plainText into two rails, so that temporary can be split into two again (thus ending up with three rails)
        if i % 3 == 0: #--If i is divisible by 3 (if it is a "third character")
            rail1 = rail1 + plainText[i]
        else:
            temporary = temporary + plainText[i]
    for i in range(len(temporary)):
        #--Splits temporary into two rails
        if i % 2 == 0: #--Same as comparing i%3 == 1 and i%3 == 2 for all of the text, but I thought about it this way first
            rail2 = rail2 + temporary[i]
        else:
            rail3 = rail3 + temporary[i]

    return rail1+rail2+rail3 #--Concatenates all rails and returns encrypted text

def main():
    """
    Takes two arguments, an input file and an output file. Uses the text in the input file, line by line, and encrypts it, line by line.
    The encrypted text is then written into the output file.
    """
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

    iFile.close()
    oFile.close()

main()
