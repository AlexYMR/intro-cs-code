#--------------------
# // guessnumber.py
# // Part of HW3
# // Problem 3
#--------------------

import random

def main():
    """
    A game in which a user tries to guess a randomly generated integer between
    0 & 9. The user has three guesses. Even if he/she guesses correctly, they
    must keep guessing until they use up all of their guesses in order to win.
    Input: Random integer
    Output(s): "Too small","Too big", "Perfect", "You win!", "You lose!"
    """
    rnum = random.randint(0,9)
    hasWon = False #--Boolean that determines the outcome
    print("\nI'm thinking of a number between 0 and 9. You have three guesses.")
    for i in range(1,4):
        num = int(input("\nGuess #"+str(i)+": "))
        if num > rnum: #--Checks if the guess is higher than the actual number
            print("Too big")
        elif num < rnum: #--Checks if the guess is lower than the actual number
            print("Too small")
        elif num == rnum: #--Checks if the guess matches the actual number
            print("Perfect!")
            #--Records that the user has guessed correctly at least once
            hasWon = True
    if hasWon:
        print("\nYou win!\n")
    else:
        print("\nYou lose!\n")
    

main()
