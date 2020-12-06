'''

Description: Demonstrates use of Monte Carlo Simulation
             technique to estimate Pi.
             Includes visualization.

             It is not necessary to fully understand
             the graphics (turtle) piece or the use
             of input function
'''

import random
import math
import turtle

def monteCarloPiDemo():
    drawingT = turtle.Turtle()
    drawingT.hideturtle()
    turtle.setworldcoordinates(-2.5, -2, 2.5, 2)
    turtle.tracer(10)
    drawingT.hideturtle()    

    drawingT.up()
    drawingT.goto(-1, 0)
    drawingT.down()
    drawingT.goto(1, 0)

    drawingT.up()
    drawingT.goto(0, 1)
    drawingT.down()
    drawingT.goto(0, -1)

    drawingT.up()
    drawingT.goto(0, -1)
    drawingT.down()
    drawingT.circle(1, 360, 200)

    drawingT.up()
    drawingT.goto(-1, 1)
    drawingT.down()
    drawingT.goto(1, 1)
    drawingT.goto(1, -1)
    drawingT.goto(-1, -1)
    drawingT.goto(-1, 1)

    dartsInCircle = 0
    totalDarts = 0
    drawingT.up()

    userIn = input('How many darts? (q for quit) ')
    if userIn != 'q':
        graphicsIn = input('Graphics? (y/n) ')
        for i in range(int(userIn)):
            print(i)
            x = random.random()
            y = random.random()

            d = math.sqrt(x**2 + y**2)

            if graphicsIn == 'y':
                drawingT.goto(x, y)

            if d <= 1:
                dartsInCircle = dartsInCircle + 1
                if graphicsIn == 'y':
                    drawingT.color("blue")
            else:
                if graphicsIn == 'y':
                    drawingT.color("red")

            totalDarts = totalDarts + 1
            if graphicsIn == 'y':
                drawingT.dot()
        print("Blue:", dartsInCircle, "Red:", totalDarts - dartsInCircle, "pi:", dartsInCircle/totalDarts * 4)
        #userIn = input('How many darts? (q for quit) ')

# Estimates the value of pi based on 
# randomness
def monteCarloPiNoGraphics(numDarts):
    dartsInCircle = 0
    for i in range(numDarts):
        x = random.random()
        y = random.random()

        # Determine where the dart landed
        d = math.sqrt(x**2 + y**2)

        if d <= 1:
            dartsInCircle = dartsInCircle + 1

    pi = dartsInCircle/numDarts * 4
    return pi
    
def main():
    monteCarloPiDemo()
    #print(monteCarloPiNoGraphics(10000))

main()
