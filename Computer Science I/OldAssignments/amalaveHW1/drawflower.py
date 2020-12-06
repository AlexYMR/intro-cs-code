#######################
# drawflower.py
# Alex Malave
# Creates multiple squares based on parameters given via command terminal
# in order to create a flower-like shape
#######################

import turtle
import sys

def drawSquare(turt,sideLength):
    # creates a square using the given sideLength parameter
    for i in range(4):
        turt.forward(sideLength)
        turt.right(90)
        

def main():
    # Draws a flower-like shape made out of squares, each evenly separated
    sideLength = float(input("How long would you like the sides to be? "))
    numPetals = float(input("How many petals would you like it to have? "))
    turt = turtle.Turtle()
    turt.hideturtle()
    turtle.bgcolor("black")
    turt.color("red", "pink")
    turt.speed(9)
    turt.width(5)
    turt.begin_fill()
    for i in range(int(numPetals)):
        drawSquare(turt,sideLength)
        turt.right(360.0/numPetals)
    turt.end_fill()
    turtle.exitonclick()

main()
