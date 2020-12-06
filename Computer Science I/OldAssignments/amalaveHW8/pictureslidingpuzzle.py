#----------------------------------------
# // pictureslidingpuzzle.py
# // Part of HW8
# // Extra Credit - Problem 1
#----------------------------------------

import sys
import cImage
import random

class SlidingPuzzle:
    def __init__(self,rows,columns,imageFile,imageFrame):
        """
        Constructs a new SlidingPuzzle object based on abitrary row and column values chosen by the user
        Input: number of rows, number or columns desired
        Output: Nothing
        """
        image = cImage.FileImage(imageFile)
        h = image.getHeight()
        w = image.getWidth()
        self.__frame = imageFrame #cImage.EmptyImage(w,h)
        self.__boxHeight = h // rows
        self.__boxWidth = w // columns
        #list format: [(upperleftbound),(lowerrightbound)]
        self.__tiles = []
        #--
        self.__bounds = []
        self.__answer = []
        acc = 0
        for y in range(rows):
            tempList = []
            upperY = y*self.__boxHeight
            lowerY = y*self.__boxHeight + self.__boxHeight
            for x in range(columns):
                tempList.append(acc)
                acc = acc + 1
                upperX = x*self.__boxWidth
                lowerX = x*self.__boxWidth + self.__boxWidth
                upperBound = (upperY,upperX)
                lowerBound = (lowerY,lowerX)
                self.__bounds.append([upperBound,lowerBound])
            self.__answer.append(tempList)
        
        #--Prepares dummy solution for uses in the driver program
        self.__defaultAns = []
        acc = 0
        for y in range(rows):
            tempList = []
            for x in range(columns):
                tempList.append(acc)
                acc = acc + 1
            self.__defaultAns.append(tempList)

        #--Makes the 0's tile completely white
        for y in range(self.__bounds[0][1][0]): #boxHeight
            for x in range(self.__bounds[0][1][1]): #boxWidth
                newP = cImage.Pixel(255,255,255)
                image.setPixel(x,y,newP)
        
        #--Creates imageWindow objects for each "tile"
        for i in range(len(self.__bounds)):
            tile = cImage.EmptyImage(self.__boxWidth,self.__boxHeight)
            for y in range(h):
                if y >= self.__bounds[i][0][0] and y < self.__bounds[i][1][0]:
                    for x in range(w):
                        if x >= self.__bounds[i][0][1] and x < self.__bounds[i][1][1]:
                            newP = image.getPixel(x,y)
                            #--Adjusts the pixel position for each new empty image so that the top left corner is at (0,0)
                            tile.setPixel(x-(self.__bounds[i][0][1]),y-(self.__bounds[i][0][0]),newP)
            self.__tiles.append(tile)
    
    def displayPuzzle(self):
        """
        Draws tiles on the image window
        """
        for y in range(len(self.__answer)):
            for x in range(len(self.__answer[y])):
                self.__tiles[self.__answer[y][x]].setPosition(x*self.__boxWidth,y*self.__boxHeight)
                self.__tiles[self.__answer[y][x]].draw(self.__frame)
        #self.__frame.exitOnClick()
                
    
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
        #--Again, iterates through the list, this time checking for adjacent tiles
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

    def returnTileIdx(self,bound,image):
        """
        Returns the tile index of the tile within the bounds provided (since I don't use a dictionary, the tile returned is always in "order").
        """
        row = bound[1]
        column = bound[0]
        for i in range(len(self.__bounds)):
            for y in range(image.getHeight()):
                if row >= self.__bounds[i][0][0] and row < self.__bounds[i][1][0]:
                    for x in range(image.getWidth()):
                        if column >= self.__bounds[i][0][1] and column < self.__bounds[i][1][1]:
                            return i

    def returnDefaultSolution(self):
        """
        Returns the default correct answer (I had some troubles duplicating self.__answer during construction, so...).
        """
        return self.__defaultAns

"""
Prey: moves and breeds after a certain time
Predator: moves, feeds (eats neighboring prey), starves if it doesn't eat after a certain time,
breeds after a certain time
Zombie: moves, feeds (turns a neighbor into a zombie, if it isn't already a zombie)
Terminator: moves, kills everything, never breeds, never dies
"""
