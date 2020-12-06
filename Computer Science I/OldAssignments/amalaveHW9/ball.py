#-------------------------
# // ball.py
# // Part of HW9
# // Problem 2
#-------------------------

import random
import math
import turtle

class Ball:
    def __init__(self):
        """
        Constructs a ball with multiple instance variables that determine specific attributes of the ball (position, velocity, size, color, and shape). 
        Uses the turtle module in order to draw the ball object.
        """
        self.minTranslation = 0
        self.origX = 0
        self.origY = 0
        self.x = random.random()
        self.y = random.random()
        self.xVel = (random.random()/100)-.005
        self.yVel= (random.random()/100)-.005
        self.size = random.random()+1
        self.rColor = random.random()
        self.gColor = random.random()
        self.bColor = random.random()
        self.bTurtle = turtle.Turtle()
        self.bTurtle.shape("circle")
        self.bTurtle.resizemode("user")
        self.bTurtle.turtlesize(self.size)
        self.bTurtle.color(self.rColor,self.gColor,self.bColor)
        self.bTurtle.up()
        self.bTurtle.setpos(self.x,self.y)
    
    def setPos(self,x,y):
        """
        Updates the position instance variables and moves the ball to the given position.
        """
        self.x = x
        self.y = y
        self.bTurtle.setpos(x,y)

    def setColor(self,r,g,b):
        """
        Updates the color instance variables and changes the color of the ball.
        """
        self.rColor = r
        self.gColor = g
        self.bColor = b
        self.bTurtle.color(r,g,b)

    def setSize(self,size):
        """
        Updates the size instance variable and changes the size of the ball.
        """
        self.size = size
        self.bTurtle.turtlesize(size)

    def setVel(self,x,y):
        """
        Updates the velocity instance variables.
        """
        self.xVel = x
        self.yVel = y

    def setMinTrans(self,val,x,y):
        """
        Extra Credit: Used to define a minimum translation balls need to travel before they become collidable again (to avoid balls getting stuck inside each other)
        """
        self.minTranslation = val
        self.origX = x
        self.origY = y
        
    def update(self):
        """
        Causes the ball to appear to bounce from the edges of the screen by inverting the velocity of the balls when they stray too far.
        """
        if self.x > 1 or self.x < 0:
            self.xVel = self.xVel * (-1)
        elif self.y > 1 or self.y < 0:
            self.yVel = self.yVel * (-1)

    def move(self):
        """
        Moves the ball slowly by adding its velocity to its position.
        """
        self.x = self.x + self.xVel
        self.y = self.y + self.yVel
        self.bTurtle.setpos(self.x,self.y)
    
    def __str__(self):
        """
        Extra Credit: Used for testing purposes.
        """
        return "Size: " + str(self.size) + " Pos: X (" + str(self.x) + ") Y (" + str(self.y) + ")"

class BreathingBall(Ball):
    def __init__(self):
        """
        Creates a ball similar to Ball, with the addition of the step instance variable.
        """
        super().__init__()
        self.step = random.randint(0,120)
        
    def update(self):
        """
        Overwrites the update method of the Ball class in order to simulate a "breathing" animation.
        """
        super().update()
        super().setSize((math.sin(self.step/20)*1.5)+2) #radius of .5 to 3.5
        self.step = self.step+1

class WarpBall(Ball):
    def __init__(self):
        """
        Uses the Ball class's constructor.
        """
        super().__init__()

    def update(self):
        """
        Overwrites the update method of the Ball class so that ball objects of this class warp to the other side of the screen at the same velocity, rather than "bouncing" off of the edges.
        """
        if self.x > 1:
            self.x = 0
        elif self.x < 0:
            self.x = 1
        elif self.y > 1:
            self.y = 0
        elif self.y < 0:
            self.y = 1

class BallWorld:
    def __init__(self,blist):
        """
        Creates an instance variable out of a list of ball objects provided.
        """
        self.balls = blist
    
    def checkCollision(self,b1,b2):
        """
        Checks whether a ball object is within another by using the equation of circles, x^2 + y^2 = r^2.
        The logic behind this is creating a larger circle with the radii of two other circles (balls).
        If the balls are within the larger circle's diameter (when its radius is the smallest it can be [the radii of the two ball objects added together]), then the ball objects must be touching.
        The problem with this is that the units the canvas turtle uses (from which I must calculate distance between ball objects) and the units turtle uses to determine the size of each object are different.
        I don't know the exact conversion, so I use an estimation (I multiply the radii by 1/35, as that seemed close enough with my testing). Therefore, the hitboxes are definitely off, and that causes overlapping.
        """
        distX = b1.x - b2.x
        distY = b1.y - b2.y
        sqrDist = (distX**2) + (distY**2)
        
        #--The radii aren't in the same units as the length, and I don't know the conversion, so I can't exactly use this method accurately
        rads = (b1.size/2 + b2.size/2)/35
        
        if (sqrDist <= (rads**2)):
            return True
            
        return False

    def bounce(self,b1,b2):
        """
        Makes the balls "bounce" off of each other in a very simple way. Since we didn't cover vectors in class too much, I didn't feel the need to do vector math.
        """
        if b1.x >= b2.x:
            b1.setVel((-1)*b1.xVel,(-1)*b1.yVel)
        elif b1.y >= b2.y:
            b1.setVel((-1)*b1.xVel,(-1)*b1.yVel)
        elif b2.y >= b1.y:
            b2.setVel((-1)*b2.xVel,(-1)*b2.yVel)
        elif b2.x >= b1.x:
            b2.setVel((-1)*b2.xVel,(-1)*b2.yVel)
        
    def update(self):
        """
        Checks each ball's position in relation to that of others every step. If the balls are within range of one another (are touching), they bounce off of each other (in a rather physically inaccurate way, but...).
        """
        for i in range(len(self.balls)):
            for ii in range(len(self.balls)):
                #--Makes sure objects aren't the same
                if self.balls[i] != self.balls[ii]:
                    #--Pythagorean theorem to get the distance and check if the ball has traveled its minimum distance
                    if ((self.balls[i].origX - self.balls[i].x)**2+(self.balls[i].origY - self.balls[i].y)**2)**.5 >= self.balls[i].minTranslation:
                        self.balls[i].setMinTrans(0,0,0)
                        if ((self.balls[ii].origX - self.balls[ii].x)**2+(self.balls[ii].origY - self.balls[ii].y)**2)**.5 >= self.balls[ii].minTranslation:
                            self.balls[ii].setMinTrans(0,0,0)
                            #--Checks if balls are within range of one another (are touching)
                            if BallWorld.checkCollision(self,self.balls[i],self.balls[ii]):
                                if self.balls[i].minTranslation == 0 and self.balls[ii].minTranslation == 0:
                                    #--Sets the minimum translation to the estimated radius (converted) of the other ball to try to make balls go-through for as little time as possible
                                    self.balls[i].setMinTrans(self.balls[ii].size/2/35,self.balls[i].x,self.balls[i].y)
                                    self.balls[ii].setMinTrans(self.balls[i].size/2/35,self.balls[ii].x,self.balls[ii].y)
                                    #--Makes balls bounce off of one another
                                    BallWorld.bounce(self,self.balls[i],self.balls[ii])
                        

