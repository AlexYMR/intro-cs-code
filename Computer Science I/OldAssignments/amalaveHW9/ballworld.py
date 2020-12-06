#--------------------------
# // ballworld.py
# // Part of HW9
# // Problem 2
#--------------------------

import turtle
import random
from ball import *

def main():
    """
    Utilizes the module ball.py in order to simulate balls in an environment with the region (0,0,1,1).
    There are three kinds of balls: normal (move and bounce off of walls), warpBall (instead of bouncing off of the walls, warps to other side of the screen at the same velocity), 
    and breathingBall (has a dynamic size).
    """
    simTurtle = turtle.Turtle()
    turtle.setworldcoordinates(0, 0, 1, 1)
    turtle.tracer(50)
    simTurtle.hideturtle()
    
    #--Creates a list to be filled with ball objects of varying classes
    ballList = []
    for i in range(50):
        ball = random.randint(1,3)
        if ball == 1:
            ballList.append(Ball())
        elif ball == 2:
            ballList.append(BreathingBall())
        elif ball == 3:
            ballList.append(WarpBall())
    
    #--Updates and moves all of the balls each step
    liveBallList = BallWorld(ballList) #--Remove this to test out original version (non-EC)
    while True:
        for b in ballList:
            b.update()
            b.move()
        liveBallList.update() #--Remove this to test out original version (non-EC)

main()
