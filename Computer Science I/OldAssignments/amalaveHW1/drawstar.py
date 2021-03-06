#######################
# drawstar.py
# Alex Malave
# Creates a multi-pointed star by attaching equalateral triangles to polygon
# edges
#######################

import turtle
import sys
   
def drawPolygon(turt,sideLength,numSides):
    # creates the star
    turnAngle = 360/numSides # calculates the rotation necessary for each angle
    for i in range(numSides):
        turt.up() # makes the image nicer by removing the inside lines
        turt.forward(sideLength)
        turt.down()
        turt.left(120)
        turt.forward(sideLength)
        turt.left(120)
        turt.forward(sideLength)
        turt.left(120)
        turt.up()
        turt.forward(sideLength)
        turt.right(turnAngle)

def main():
    # Draws a star based off of the number of points & side length provided
    # through the console
    turt = turtle.Turtle()
    points = int(sys.argv[1])
    sideLength = int(sys.argv[2])
    turt.speed(8)
    turt.hideturtle()
    turt.width(10)
    drawPolygon(turt,sideLength,points)
    turtle.exitonclick()

main()
