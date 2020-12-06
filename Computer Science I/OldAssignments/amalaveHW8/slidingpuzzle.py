#--------------------------------
# // slidingpuzzle.py
# // Part of HW8
# // Problem 1
#--------------------------------

import random

class SlidingPuzzle:
    def __init__(self,rows,columns):
        """
        Constructs a new SlidingPuzzle object based on abitrary row and column values chosen by the user
        Input: number of rows, number or columns desired
        Output: Nothing
        """
        self.__answer = []
        acc = 0
        for y in range(rows):
            tempList = []
            for x in range(columns):
                tempList.append(acc)
                acc = acc + 1
            self.__answer.append(tempList)
    
    def displayPuzzle(self):
        """
        Prints the puzzle onto the terminal in a legible, neat way.
        """
        for y in range(len(self.__answer)):
            currentRow = ""
            for x in self.__answer[y]:
                numString = str(x)
                reps = 2
                if len(numString) > 1: #or numString[-1] == "9":
                    reps = 1
                currentRow = currentRow + numString + " "*reps
            currentRow = currentRow[:-1]
            print(currentRow)
    
    def move(self,ridx,cidx):
        """
        Moves the 0 "tile" by swapping it for the value of another "tile."
        """
        zeroPos = [0,0]
        #--Iterates through the list self.__answer in order to find the position of the 0
        for y in range(len(self.__answer)):
            for x in range(len(self.__answer[y])):
                if self.__answer[y][x] == 0:
                    zeroPos[0] = y
                    zeroPos[1] = x
        #--Temporary holder variable in order to make the swap possible
        numToSwap = self.__answer[ridx][cidx]
        self.__answer[ridx][cidx] = 0
        self.__answer[zeroPos[0]][zeroPos[1]] = numToSwap

    def legalMoves(self):
        """
        Ensures that the move the user is attempting is a legal one. Does so by checking that the "tile" the user wants to move the 0 "tile" to is directly adjecent to the 0 "tile." 
        Returns a list of tuples that denote possible moves.
        """
        zeroPos = [0,0]
        legalMvs = []
        #--Iterates through the list to find the 0
        for y in range(len(self.__answer)):
            for x in range(len(self.__answer[y])):
                if self.__answer[y][x] == 0:
                    zeroPos[0] = y
                    zeroPos[1] = x
                    #print(zeroPos)
        #--Again, iterates through the list, this time checking for adjecent tiles
        for y in range(len(self.__answer)):
            if (zeroPos[0] - 1) >= 0 and (zeroPos[0] - 1) == y or (zeroPos[0] + 1) < len(self.__answer) and (zeroPos[0] + 1) == y or zeroPos[0] == y:
                for x in range(len(self.__answer[y])):
                    if zeroPos[0] == y:
                        if (zeroPos[1] - 1) >= 0 and (zeroPos[1] - 1) == x or (zeroPos[1] + 1) < len(self.__answer[y]) and (zeroPos[1] + 1) == x:
                            t = (y,x)
                            legalMvs.append(t)
                    else:
                        if x == zeroPos[1]:
                            t = (y,x)
                            legalMvs.append(t)
        
        return legalMvs

    def scramble(self,shuffleNum):
        """
        Scrambles the puzzle by moving the 0 tile several times around the board randomly. This way, the puzzle remains solvable.
        """
        for i in range(shuffleNum):
            moves = SlidingPuzzle.legalMoves(self)
            rand = random.randint(0,len(moves)-1)
            SlidingPuzzle.move(self,moves[rand][1], moves[rand][0])

    def isSolved(self):
        """
        Checks whether the puzzle has been solved or not by making sure that all numbers (or "tiles") in the lists are in order.
        Returns true if the puzzle is solved, otherwise returns false.
        """
        solved = False
        prevNum = self.__answer[0][0]
        for y in range(len(self.__answer)):
            for x in self.__answer[y]:
                if prevNum != 0 and prevNum > x:
                    return False
                prevNum = x
        return True

