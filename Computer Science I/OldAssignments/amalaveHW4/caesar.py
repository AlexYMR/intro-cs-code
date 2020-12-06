#------------------
# // caesar.py
# // Part of HW4
# // Problem 1
#------------------

import sys

def caesarEncrypt(plainText,numShift):
    """
    Uses a Caesar Cipher to encrypt the plainText string provided, using a rotation of numShift.
    Input: plainText (string used for encryption), numShift (number that determines the shift of the substituted letters used in the encryption)
    Output: Encrypted message
    """
    alphabet = "abcdefghijklmnopqrstuvwxyz " #--Defines the alphabet we'll use
    newText = "" #--Creates an empty string value that we'll fill later
    for i in range(len(plainText)):
        #--Goes through the alphabet, finding the plainText's characters individually, and then fills
        #--newText with the letter substitutions
        if alphabet.find(plainText[i]) or alphabet.find(plainText[i]) == 0:
            newLetter = alphabet.index(plainText[i])
            newText = newText + alphabet[(newLetter+numShift)%27]
            
    return newText

def caesarDecrypt(cipherText,numShift):
    """
    Undoes a Caesar Cipher using a given rotation (numShift), and a given encrypted text (cipherText)
    Input: cipherText (string that has been encrypted by a Caesar Cipher), numShift(number that determines the shift of the substituted letters used in the
    decryption
    """
    alphabet = "abcdefghijklmnopqrstuvwxyz " #--Defines the alphabet we'll use
    newText = "" #--Creates an empty string value that we'll fill later
    for i in range(len(cipherText)):
        #--Goes through the alphabet, finding the cipherText's characters individually, and then fills
        #--newText with the letter substitutions (in reverse)
        if alphabet.find(cipherText[i]) or alphabet.find(cipherText[i]) == 0:
            newLetter = alphabet.index(cipherText[i])
            newText = newText + alphabet[(newLetter-numShift)%27] #--Rather than adding, we subtract, to go backwards in the alphabet
            
    return newText

def caesarBreak(cipherText):
    """
    Uses a brute-force method to break the Caesar Cipher (goes through all of the possible shifts, in order to find out which one was used to encrypt
    the given encrypted text).
    Input: cipherText (text encrypted using a Caesar Cipher)
    Output: prints 27 guesses, each of which uses one of the 27 different possible number shifts
    """
    alphabet = "abcdefghijklmnopqrstuvwxyz " #--Defines the alphabet we'll use
    newText = "" #--Creates an empty string value that we'll fill later
    numShift = 0 #--Initial number shift (step)
    print("Trying to decrypt the secret message...")
    for v in range(1,28):
        newText = caesarDecrypt(cipherText,v-1)
        print("Guess " + str(v) + ": " + newText)
        numShift = numShift + 1
        newText = ""

def main():
    s = input("\nEnter a string to encrypt: ")
    num = int(sys.argv[1])
    print("\nThe encrypted message using a Caesar Cipher with a step of " + str(num) + " is: " + caesarEncrypt(s,num))
    print("\nThe decrypted message using a Caesar Cipher with a step of " + str(num) + " is: " + caesarDecrypt(caesarEncrypt(s,num),num) + "\n")
    caesarBreak("we ovugpzghugpu lylz pungwyvnyhttpungshunahnl")

main()
