#----------------------------------
# // shakespearequiz.py
# // Part of HW7
# // Problem 2
#----------------------------------

import random
import sys

def readPlay(ifile):
    """
    Makes a list out of a play file given. The function then seeks out the act, scene, characters (within the scene), and lines (said by these characters), 
    which it organizes into a list of lists of dictionaries of lists.
    Input: File object
    Output: The play file given in list form, organized by: act, scene, character, lines (said by character)
    """
    ifile = open(ifile,"r")
    line = ifile.readline()
    line = ifile.readline()
    play = []
    #--Defines accumulators
    actIdx = -1
    sceneIdx = -1
    lineIdx = 0
    #--
    currentCharacter = ""
    while line != "" and len(line.split()) > 0:
        splt = line.split()
        if splt[0] == "ACT":
            play.append([])
            actIdx = actIdx + 1
            sceneIdx = -1
        elif splt[0] == "SCENE":
            play[actIdx].append({})
            sceneIdx = sceneIdx + 1
        elif splt[0] != "SCENE" and splt[0] != "ACT" and line == line.upper():
            currentCharacter = ""
            for i in range(len(splt)):
                if splt[i][-1] == "." or splt[i][-1] == "\n":
                    splt[i] = splt[i][:-1]
                    if splt[i][-1] == ".":
                        splt[i] = splt[i][:-1]
            for i in range(len(splt)):
                currentCharacter = currentCharacter + splt[i] + " "
            currentCharacter = currentCharacter[:-1]
            if not currentCharacter in play[actIdx][sceneIdx]:
                play[actIdx][sceneIdx][currentCharacter] = []
        else:
            if currentCharacter in play[actIdx][sceneIdx]:
                play[actIdx][sceneIdx][currentCharacter].append(line[:-1])
        line = ifile.readline()
    ifile.close()
    return play

def printQuestion(play, actIndex, sceneIndex, characterName, lineIndex, questionNum):
    
    #Print the question
    print("Question " + str(questionNum) + ": In act " + str(actIndex + 1) + ", scene " + str(sceneIndex + 1) + ", who says:")
    print('"' + play[actIndex][sceneIndex][characterName][lineIndex] + '"')

    #Now we have to build the list of choices the user
    #will choose from
    choices = [characterName]

    #Get the list of characters in the scene
    characterList = list(play[actIndex][sceneIndex].keys())
    characterList.remove(characterName)
    if len(characterList) > 3:
        #Pick 3 random alternate choices from the scene
        for i in range(3):
            idx = random.randint(0, len(characterList) - 1)
            choices.append(characterList[idx])
            characterList.pop(idx)
    else:
        #There are 4 or fewer characters in the scene
        #Just add all the characters to the list
        choices += characterList
            
    #Place the correct character in a random position
    #in the list of answers
    correctPos = random.randint(0, len(choices) - 1)
    tmp = choices[correctPos]
    choices[correctPos] = choices[0]
    choices[0] = tmp
        
    #Print the choices
    answerList = 'abcd'
    for i in range(len(choices)):
        print(answerList[i] + ") " + choices[i])
    
    return answerList[correctPos]


def main():
    """
    Initiates a game with the user, quizzing them on a given play.
    Input: File (a play)
    Output: a game on the terminal
    """
    ifile = sys.argv[1]
    fin = open(ifile,"r")
    title = fin.readline()
    fin.close()
    
    playList = readPlay(ifile)

    print(title)
    numQuestion = 1
    numRight = 0
    Continue = True
    #--Keeps the game going as long as the person wishes to continue
    while Continue:
        #--Randomizes the act, scene, character, and line (said by the character) in sequential order
        randomAct = random.randint(0,len(playList)-1)
        randomScene = random.randint(0,len(playList[randomAct])-1)
        charList = []
        for i in playList[randomAct][randomScene].keys():
            charList.append(i)
        randomChar = charList[random.randint(0,len(charList)-1)]
        randomLine = random.randint(0,len(playList[randomAct][randomScene][randomChar])-1)
        #--
        
        #--Grabs the correct answer
        answer = printQuestion(playList,randomAct,randomScene,randomChar,randomLine,numQuestion)
    
        response = str(input("\nYour answer: "))
        #--Checks that the response makes sense (to an extent)
        if len(response) > 1:
            while len(response) > 1:
                response = str(input("\nYour answer (enter something more reasonable): "))
        #--Checks if their response matches the correct answer
        elif response == answer:
            numRight = numRight + 1
            ans = str(input("\nCongratulations! You answered correctly. Would you like to continue? (y/n) "))
            if ans == "y":
                Continue = True
            else:
                #--Prints ratio of correct answers to questions asked
                print("Thanks for playing! You answered " + str(numRight) + "/" + str(numQuestion) + " questions correctly.")
                Continue = False
        #--If they guess incorrectly, gives them the correct answer and asks if they wish to continue
        else:
            ans = str(input("\nSorry! The correct answer was: " + answer + ". Would you like to continue? (y/n) "))
            if ans == "y":
                Continue = True
            else:
                #--Prints ratio of correct answers to questions asked
                print("Thanks for playing! You answered " + str(numRight) + "/" + str(numQuestion) + " questions correctly.")
                Continue = False
        numQuestion = numQuestion + 1
    
main()
