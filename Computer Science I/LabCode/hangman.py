#!/usr/bin/env python


import random

def getSpots(l, word):
        numbers = []
        for i in range(len(word)):
                if word[i] == l:
                        numbers.append(i)
        return numbers


def main():
        words = ['extracurriculum', 'unescapably', 'increment', 'mario', 'luigi', 'openhanded', 'super', 'shell', 'harvest', 'reputation', 'sonic', 'dispersement', 'tails', 'zelda', 'link', 'sword', 'pacman', 'extra', 'rick', 'conceivably', 'morty', 'agile', 'connection', 'fiddler', 'theologically', 'enrichment', 'primarily', 'primary','diamondium', 'semiterrestrial', 'election', 'marriage', 'eclectic']
        randWord = words[random.randint(0,len(words))]
        charCount = len(randWord)
        guessesLeft = charCount
        wordList = []
        lettersGuessed = []
        hasWon = False
        print("I'm thinking of a word. It may be in the dictionary, or it may be a proper noun.\nCan you guess what it is?\n\n")
        for i in range(charCount):
                wordList.append("_")
        print(wordList)
        print(randWord)
        for i in range(guessesLeft):
                if not hasWon:
                        if guessesLeft > 0:
                                letter = input("\nPlease guess a letter! (or type 'solve' to solve the puzzle!)")
                                if letter != "solve":
                                        tab = getSpots(letter,randWord)
                
                                        if len(tab) > 0 and len(getSpots(letter,lettersGuessed)) == 0:
                                                print("Correct! That letter is in the word!\n\n")
                                                lettersGuessed.append(letter)
                                                guessesLeft = guessesLeft - 1
                                                for ii in range(len(tab)):
                                                        wordList[tab[ii]] = letter
                                                        print(wordList)
                                                        if len(getSpots("_",wordList)) == 0:
                                                                hasWon = True
                                                        else:
                                                                print("\nYou have " + str(guessesLeft) + " guesses left.")
                                        else:
                                                print("Wrong! :( ''"+letter+"'' is not in the word, or you have already guessed that letter.\n\n")
                                                guessesLeft = guessesLeft - 1
                                                print(wordList)
                                                print("\nYou have " + str(guessesLeft) + " guesses left.")
                                else:
                                        guess = input("What do you think the word is? ")
                                        if guess == randWord:
                                                hasWon = True
                                        else:
                                                guessesLeft = 0
                        else:
                                print("\nSorry, you lose! The word was ''" + randWord + ".'' Please play again!")
                                break
                else:
                        print("\nCongratulations! YOU WIN!")
                        break
        if hasWon and guessesLeft == 0:
                print("\nCongratulations! YOU WIN!")
        elif guessesLeft == 0 and not hasWon:
                print("\nSorry, you lose! The word was ''"+ randWord + ".'' Please play again!")
main()
