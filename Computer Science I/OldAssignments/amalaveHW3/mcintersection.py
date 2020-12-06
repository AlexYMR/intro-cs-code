#-----------------------
# // mcintersection.py
# // Part of HW3
# // Problem 1
#-----------------------

import sys
import random
import math

def monteCarlo(dist,numDarts):
    """
    Creates two circles and uses the random module in order to pick random
    coordinates in the range [0,1]. Approximates pi by calculating how many
    times the random coordinates refer to a point inside both circles.
    Input: Distance between circle centers from the origin (0,0), number of
    "darts" to use in the simulation
    Output: Estimated number of darts expected to land within the region
    within the two circles
    """
    dartsInCircle = 0
    if dist > 0 and dist < 1:
        leftPoint = (-1-dist)+2*dist #--Leftmost point of the rightmost circle
        rightPoint = (1+dist)-2*dist #--Rightmost point of the leftmost circle
        #--leftPoint & rightPoint are used to determine the smallest width of
        #--the rectangle
        for i in range(numDarts):
            x = random.random()*rightPoint*2-rightPoint
            y = (random.random()*2)-1

            #--Determine where the dart landed
            d1 = math.sqrt((x+dist)**2 + y**2)
            d2 = math.sqrt((x-dist)**2 + y**2)

            if d1 <= 1 and d2 <= 1: #--If the "dart" is inside of both circles
                dartsInCircle = dartsInCircle + 1

        area = dartsInCircle/numDarts * 2*(rightPoint-leftPoint)

        return area
    else:
        return 0

def main():
    dist = float(sys.argv[1])
    numDarts = int(sys.argv[2])
    print(monteCarlo(dist,numDarts))

main()
