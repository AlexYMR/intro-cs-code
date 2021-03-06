import sys

from tkinter import Tk, Canvas, Frame, Button, BOTH, TOP, BOTTOM

boards = ["debug","easy","medium","hard"] #--List of puzzles
cellWidth = 50 #--Size of each number block
marginSize = 20 #--Size of the margin of the puzzle window (in pixels)
boardWidth = marginSize*2+cellWidth*9 #--Width of the board (both margins & width of the puzzle)
boardHeight = boardWidth #--Since the puzzle is a square, the height is the same as the width

class PuzzleBoard: #--The board list for the game
    def __init__(self, ifile):
        """
        Creates a list out of a file (given parameter) that is assumed to contain 81 numbers, with 9 numbers per line (each row represents a row in the puzzle).
        """
        self.board = []
        for line in ifile:
            #if len(line) != 9:
               # print("All lines in the file must be 9 characters long.")
            self.board.append([])
            for i in line:
                if i != "\n": #--Makes sure this special character is not considered part of the list (when reading the file)
                    #--Could add a check to make sure the characters are numbers between 0 & 9
                    self.board[-1].append(int(i))

class SudokuInstance: #--The game itself, checks for win and changes state of board
    def __init__(self,ifile):
        """
        Sets up some instance variables that will be needed later.
        """
        self.ifile = ifile
        self.origPuzzle = PuzzleBoard(ifile).board

    def begin(self):
        """
        Initiates the puzzle: sets up a copy of the original puzzle (the list), which will be edited by the user later on.
        """
        self.isSolved = False #--Determines whether the game has been won or not, checked whenever the user inputs a number
        self.currentPuzzle = []
        #--Copies origPuzzle into currentPuzzle
        for i in range(9):
            self.currentPuzzle.append([])
            for ii in range(9):
                self.currentPuzzle[i].append(self.origPuzzle[i][ii])
                
    def checkEachSquare(self,numLine):
        """
        Makes a list that contains the numbers 1-9 and checks it with the given list (parameter). The method will
        return true if the list contains the numbers 1-9 without repeats, and false otherwise.
        """
        numList = []
        for i in range(1,10):
            numList.append(i)
        #--numList now has numbers from 1-9 in order

        for i in range(9): #--Must go from 0 to 8 in order to get the indexes right
            if numLine[i] in numList:
                foundIdx = numList.index(numLine[i])
                numList = numList[:foundIdx] + numList[-1:foundIdx-len(numList)] #--Pops the number that matches out of numList
        if len(numList) > 0: #--This can only be the case if the numbers repeat or aren't in the range 1-9
            return False
        return True

    def checkRow(self,rowIdx):
        """
        Calls the checkEachSquare method in order to determine whether a row list is complete.
        """
        return SudokuInstance.checkEachSquare(self,self.currentPuzzle[rowIdx]) #--Checks each square in the row

    def checkColumn(self,columnIdx):
        """
        Creates a list out of the (columnIdx) indexes of all 9 row lists, and then calls the checkEachSquare method in
        order to determine whether the list is complete.
        """
        columnNumList = []
        for r in range(9):
            columnNumList.append(self.currentPuzzle[r][columnIdx])
        return SudokuInstance.checkEachSquare(self,columnNumList)
        
    def checkBox(self,rowIdx,columnIdx):
        """
        Creates a list out of the numbers within a box. Treats each box as indexes in their own right (0-2 rows, 0-2 columns).
        Calls checkEachSquare with the list of numbers procured from each box to determine whether the list is complete.
        """
        numList = []
        for r in range(rowIdx*3,(rowIdx+1)*3):
            for c in range(columnIdx*3,(columnIdx+1)*3):
                numList.append(self.currentPuzzle[int(r)][int(c)])
        return SudokuInstance.checkEachSquare(self,numList)

    def checkIfSolved(self):
        """
        Used to determine whether the puzzle has been solved or not.
        """
        for r in range(9): #--Checks all rows
            if not SudokuInstance.checkRow(self,r):
                return False
        for c in range(9): #--Checks all columns
            if not SudokuInstance.checkColumn(self,c):
                return False
        for r in range(3): #--Checks all boxes
            for c in range(3):
                if not SudokuInstance.checkBox(self,r,c):
                    return False
        self.isSolved = True #--If all the above doesn't return False, the puzzle must be solved
        return True

class PuzzleGui(Frame):
    """
    The Tkinter UI, responsible for drawing the board and accepting user input.
    """
    def __init__(self, parent, game):
        self.game = game
        self.parent = parent #--The "parent" as opposed to "child" of the widget we'll create (the window)
        self.row = -1 #--Sets up variable for use 
        self.col = -1 #--Sets up variable for use
        
        self.editableNumbers = []
        Frame.__init__(self, parent) #--Just a region on the screen (rectangular), basically just a widget of the puzzle
        self.__initUI()

    def __initUI(self):
        self.parent.title("Sudoku") #--Title of the window
        self.pack(fill=BOTH) #--Sets the frame's position relative to its parent. BOTH fills any extra space (both) horizontally and vertically that isn't used by the parent.
        self.canvas = Canvas(self,width=boardWidth,height=boardHeight) #--Widget used generally for display
        self.canvas.pack(fill=BOTH)#, side=TOP) #--The whole square of the puzzle will fill the space, and will be pulled to the top of the window
        clear_button = Button(self,text="Clear answers",command=self.__clear_answers) #--Sends the text the button will display, along with the function it will call when clicked
        clear_button.pack(fill=BOTH, side=BOTTOM) #--Fills the space, and is placed at the bottom of the window

        self.__draw_grid()
        self.__draw_puzzle()

        self.canvas.bind("<Button-1>", self.__cell_clicked) #--Binds an action (clicking the left mouse button to a function)
        self.canvas.bind("<Key>", self.__key_pressed) #--Fired when a key is pressed (e.g. a number [for input])

    def __draw_grid(self):
        """
        Draws grid divided with red lines into 3x3 squares
        """
        for i in range(10):
            if i % 3 == 0:
                color = "purple"
            else:
                color = "gray"
			
            #--Draws the vertical lines (with initial point (x0,y0) and endpoint (x1,y1))
            x0 = marginSize + i * cellWidth
            y0 = marginSize
            x1 = marginSize + i * cellWidth
            y1 = boardHeight - marginSize
            self.canvas.create_line(x0, y0, x1, y1, fill=color)

            #--Draws the horizontal lines (with initial point (x0,y0) and endpoint (x1,y1))
            x0 = marginSize
            y0 = marginSize + i * cellWidth
            x1 = boardWidth - marginSize
            y1 = marginSize + i * cellWidth
            self.canvas.create_line(x0, y0, x1, y1, fill=color)

    def __draw_puzzle(self):
        """
        Creates a cell for each of the numbers within the lists. This method will be called every time a
        user inputs an answer to a cell.
        """
        self.canvas.delete("numbers") #--Clears out any previous numbers
        for r in range(9):
            for c in range(9):
                answer = self.game.currentPuzzle[r][c]
                if answer != 0: #--If the number is 0, it's left blank
                    x = marginSize + c * cellWidth + cellWidth / 2
                    y = marginSize + r * cellWidth + cellWidth / 2
                    original = self.game.origPuzzle[r][c]
                    if answer == original:
                        color = "black"
                    else:
                        color = "gray"
                    self.canvas.create_text(x, y, text=answer, tags="numbers", fill=color) #--The tag "numbers" allows for an easy reference later
                    #self.editableNumbers.append(n)

    def __clear_answers(self):
        """
        Clears all user-inputted numbers on the board (the board is reset).
        """
        self.game.begin() #--Resets the puzzle to original state
        self.canvas.delete("victory") #--Deletes the victory circle if it's showing
        self.__draw_puzzle() #--Draws the puzzle again with the newly reset values
		
    def __cell_clicked(self, arg):
        if self.game.isSolved:
            return
        x = arg.x
        y = arg.y
        if (marginSize < x < boardWidth - marginSize) and (marginSize < y < boardHeight - marginSize): #--Making sure that the coordinates of the mouse are within the bounds of the puzzle
            self.canvas.focus_set() #--Sets the focus of the canvas (used later in order to highlight the region)

            #--Get row and column numbers from x,y coordinates
            row = int((y- marginSize) / cellWidth)
            col = int((x - marginSize) / cellWidth)

            #--Deselect cell if already selected
            if row == self.row and col == self.col:
                self.row = -1
                self.col = -1
            else:
                num = self.game.currentPuzzle[row][col]
                if num != self.game.origPuzzle[row][col] or num == 0:
                    self.row = row
                    self.col = col
                    
        else:
            self.row = -1
            self.col = -1

        self.__draw_cursor()
		
    def __draw_cursor(self):
            """
            Draws a box outside of the cell (highlights it), so that you know which box you're changing the value of.
            """
            self.canvas.delete("cursor") #--Removes the cursor from any other potentially highlighted cell
            if self.row >= 0 and self.col >= 0:
                """
                Makes two points (a left upper point & a right lower point), which it sends to a method to create a rectangle.
                The borders are offset to be one pixel within the cell itself, so that you can see the outline better.
                """
                x0 = marginSize + self.col * cellWidth + 1
                y0 = marginSize + self.row * cellWidth + 1
                x1 = marginSize + (self.col + 1) * cellWidth - 1
                y1 = marginSize + (self.row + 1) * cellWidth - 1
                self.canvas.create_rectangle(x0, y0, x1, y1,outline="dark slate blue", tags="cursor") 

    def __key_pressed(self, arg):
        if self.game.isSolved:
            return
        if self.row >= 0 and self.col >= 0 and arg.char in "1234567890": #--If the key pressed is a character in the string (note: arg.char returns an ordinal value)
            self.game.currentPuzzle[self.row][self.col] = int(arg.char)
            
            #--Resets the cursor selection
            self.col = -1
            self.row = -1
			
            self.__draw_puzzle() #--Redraws the puzzle as it now is
            self.__draw_cursor() #--Redraws the cursor (now it shouldn't be selecting anything)
            if self.game.checkIfSolved():
                self.__draw_victory()

    def __draw_victory(self):
        """
        Creates text circumscribed within a circle, whose position is determined using rows and columns.
        """
        #--Creates an oval (which will be a circle)
        x0 = marginSize + cellWidth * 2 #--Position in relation to columns
        y0 = x0
        x1 = marginSize + cellWidth * 7 #--Position in relation to rows
        y1 = x1
        self.canvas.create_oval(x0, y0, x1, y1,tags="victory", fill="dark red", outline="red")
        #--Creates the text
        x = y = marginSize + 4 * cellWidth + cellWidth / 2
        self.canvas.create_text(x, y,text="You win!", tags="victory",fill="white", font=("Arial", 32))
		
def main():
    board = str(input("Type the difficulty level you would prefer (easy, medium, hard): "))
    while board not in boards:
        board = str(input("Invalid input. Type the difficulty level you would prefer (easy, medium, hard): "))

    boardFile = open((board+".txt"),"r")
    game = SudokuInstance(boardFile)
    game.begin()

    root = Tk() #--Initiates Tkinter
    PuzzleGui(root,game)
    root.geometry("%dx%d" % (boardWidth,boardHeight+40)) #--Essentially makes the parent dimensions (the root) a bit larger than those of the puzzle.
    root.mainloop() #--Launches the program

main()
