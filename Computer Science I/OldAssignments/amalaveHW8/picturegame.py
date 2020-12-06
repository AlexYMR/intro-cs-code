#------------------------------------------
# // picturegame.py
# // Part of HW8
# // Extra Credit - Problem 2
#------------------------------------------

from pictureslidingpuzzle import *
import sys
import cImage

def main():
     """
    Initiates a game with the user using an imported "slidingpuzzle" module. The goal of the game is to organize the picture so that it looks as it should. The picture is split into a grid-like structure, with each box representing a tile.
    The user can choose arbitrary values for the row and column sizes, and they can select their difficulty level as well.
    Input: Image file
    Output: A series of image windows
    """
    filename = sys.argv[1]
    image = cImage.FileImage(filename)
    frame = cImage.ImageWin("Sliding Puzzle",image.getWidth(),image.getHeight())
    print("\n=========================================================")
    print("[ Welcome to the Sliding Puzzle Game ]")
    width = int(input("-- Enter the width of the puzzle (integer): ") or 2)
    height = int(input("-- Enter the height of the puzzle (integer): ") or 2)
    #--Creates the puzzle
    puzzle = SlidingPuzzle(height,width,filename,frame)
    
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
    
    #--Initiates the gmae for as long as the puzzle isn't solved 
    while not SlidingPuzzle.isSolved(puzzle):
        print("\n")
        selected = False
        selectedBox = (0,0)
        #--Redraws the image window to update it
        SlidingPuzzle.displayPuzzle(puzzle)
        #--Waits until the user clicks on a tile (this stops it from closing automatically as well)
        while not selected:
            print("Please select a tile to move.")
            selection = frame.getMouse()
            tileIdx = SlidingPuzzle.returnTileIdx(puzzle,selection,image)
            defaultAns = SlidingPuzzle.returnDefaultSolution(puzzle)
            #print(defaultAns)
            for i in range(len(defaultAns)):
                for ii in range(len(defaultAns[i])):
                    if defaultAns[i][ii] == tileIdx:
                        selectedBox = (i,ii)
            selected = True
        print(selectedBox)
        row = selectedBox[0] #int(input("Select a row number: ") or 0)
        column = selectedBox[1] #int(input("Select a column number: ") or 0)
        attemptedMove = (row,column)
        #--Checks if the move they are attempting is legal--if not, keeps asking them to pick a legal move
        while not attemptedMove in SlidingPuzzle.legalMoves(puzzle):
            print("Illegal move!")
            selected = False
            selectedBox = (0,0)
            while not selected:
                print("Please select a tile to move.")
                selection = frame.getMouse()
                tileIdx = SlidingPuzzle.returnTileIdx(puzzle,selection,image)
                defaultAns = SlidingPuzzle.returnDefaultSolution(puzzle)
                for i in range(len(defaultAns)):
                    for ii in range(len(defaultAns[i])):
                        if defaultAns[i][ii] == tileIdx:
                            selectedBox = (i,ii)
                selected = True
            row = selectedBox[0] #int(input("Select a row number: ") or 0)
            column = selectedBox[1] #int(input("Select a column number: ") or 0)
            attemptedMove = (row,column)
        SlidingPuzzle.move(puzzle,attemptedMove[0],attemptedMove[1])
        
    SlidingPuzzle.displayPuzzle(puzzle)
    print("\nYou win!")

main()
