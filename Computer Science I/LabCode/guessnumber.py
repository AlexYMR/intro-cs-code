import random

def main():
    secretNum = random.randint(0, 9)
    guessedIt = False
    print("I'm thinking of a number from 0 to 9.  You have unlimited guesses!")
    guesses = 0
    while not guessedIt:
        print("Guess " + str(guesses + 1))
        guess = int(input("-- Input a number (0 - 9): "))
        if guess >= 0 and guess <= 9:
            if guess < secretNum:
                print("Too small")
            elif guess > secretNum:
                print("Too big")
            else:
                print("Perfect")
                guessedIt = True
            guesses = guesses + 1

    if guessedIt:
        print("You win! It took you " + str(guesses) + " guesses.")

main()
