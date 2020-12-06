#-------------------------
# // game.py
# // Part of HW8
# // Problem 1
#-------------------------

from slidingpuzzle import *

def main():
    """
    Initiates a game with the user using an imported "slidingpuzzle" module. The goal of the game is to organize the game board in such a way that all numbers are in order from least to greatest.
    The user can choose arbitrary values for the row and column sizes, and they can select their difficulty level as well.
    Input: Nothing
    Output: The game process
    """
    print("\n=========================================================")
    print("[ Welcome to the Sliding Puzzle Game ]")
    width = int(input("-- Enter the width of the puzzle (integer): ") or 2)
    height = int(input("-- Enter the height of the puzzle (integer): ") or 2)
    #--Creates the puzzle
    puzzle = SlidingPuzzle(height,width)
    
    difficulty = int(input("-- Enter the difficulty level (1, 2, or 3)\n>>> 1: Easiest, 2: Medium, 3: Hardest ---:  ") or 1)

    while difficulty != 1 and difficulty != 2 and difficulty != 3:
        difficulty = int(input("-- Please enter a valid difficulty level! (1, 2, or 3):  ") or 1)
    
    shuffleNum = 0
    if difficulty == 1:
        shuffleNum = 3
    elif difficulty == 2:
        shuffleNum = 11
    elif difficulty == 3:
        shuffleNum = 19
    #--Scrambles the puzzle based on the difficulty number they chose
    SlidingPuzzle.scramble(puzzle,shuffleNum)
    print("The puzzle has been shuffled! Have fun!")
    print("=========================================================")
    
    #--Initiates the game for as long as the puzzle isn't solved
    while not SlidingPuzzle.isSolved(puzzle):
        print("\n")
        #--Displays the board again to constantly update it
        SlidingPuzzle.displayPuzzle(puzzle)
        row = int(input("Select a row number: ") or 0)
        column = int(input("Select a column number: ") or 0)
        attemptedMove = (row,column)
        #--Checks if the move they are attempting is legal--if not, keeps asking them to pick a legal move
        while not attemptedMove in SlidingPuzzle.legalMoves(puzzle):
            print("Illegal move!")
            row = int(input("Select a row number: ") or 0)
            column = int(input("Select a column number: ") or 0)
            attemptedMove = (row,column)
        SlidingPuzzle.move(puzzle,attemptedMove[0],attemptedMove[1])

    print("\n")
    SlidingPuzzle.displayPuzzle(puzzle)
    print("\nYou win!")

main()
