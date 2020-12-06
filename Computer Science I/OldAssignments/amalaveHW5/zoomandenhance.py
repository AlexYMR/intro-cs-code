#-----------------------
# // zoomandenhance.py
# // Part of HW 5
# // Problem 2
#-----------------------

import cImage
import sys

def zoom(image, upperLeftX, upperLeftY, lowerRightX, lowerRightY, factor):
    """
    Utilizes upper--left and lower-right coordinates in order to define a region, and creates a fitting empty frame judging by that region and
    the zooming factor given.
    Input: original image, upper bound, lower bound, zooming factor
    Output: processed image (zoomed)
    """
    width = factor*(lowerRightX-upperLeftX)
    height = factor*(lowerRightY-upperLeftY)
    newImg = cImage.EmptyImage(width,height)

    for x in range(image.getWidth()):
        if x >= upperLeftX and x < lowerRightX:
            for y in range(image.getHeight()):
                if y >= upperLeftY and y < lowerRightY:
                    p = image.getPixel(x, y)
                    for i in range(factor):
                        for j in range(factor):
                            newImg.setPixel(factor*(x-upperLeftX)+i, factor*(y-upperLeftY)+j, p)
              
    return newImg

def restrict(num, minNum, maxNum):
    """
    Restricts a number range. That is, provided a number and a range, it will not allow the number to go beyond or below that range.
    Input: number, minimum number of the range, maximum number of the range
    Output: the original number, or the minimum or maximum number of the range provided, if the number is too small or too large, respectively
    """
    if num >= minNum or num <= maxNum:
        return num
    elif num < minNum:
        return minNum
    elif num > maxNum:
        return maxNum

def sharpenImage(image):
    """
    Takes an image and makes the difference between pixel intensities starker.
    Input: original image
    Output: processed image (sharpened)
    """
    newImg = cImage.EmptyImage(image.getWidth(),image.getHeight())
            
    for x in range(1,image.getWidth()-1):
        for y in range(1,image.getHeight()-1):
            #--Accumulators for the values needed to calculate each new pixel's color intensity
            redAcc = 0
            greenAcc = 0
            blueAcc = 0
            #--For loop automatically grabs the nine-pixel region in order to collect the color intensities
            for i in range(-1,2):
                for j in range(-1,2):
                    p2 = image.getPixel(x+i,y+j)
                    #--Checks to see if this is the center pixel or not
                    if i == 0 and j == 0:
                        origRed = p2.getRed()
                        origGreen = p2.getGreen()
                        origBlue = p2.getBlue()
                    else:
                        redAcc = redAcc + p2.getRed()
                        greenAcc = greenAcc + p2.getGreen()
                        blueAcc = blueAcc + p2.getBlue()
            #--Ensures that the numbers given by the calculation neither exceed 255, nor go below 0 by calling restrict
            #--Makes each pixel more discernable by using the given formula
            redAvg = restrict((origRed*9)-redAcc,0,255)
            greenAvg = restrict((origGreen*9)-greenAcc,0,255)
            blueAvg = restrict((origBlue*9)-blueAcc,0,255)

            newP = cImage.Pixel(redAvg,greenAvg,blueAvg)
            newImg.setPixel(x-1,y-1,newP) #--Makes sure that the pixels are placed at the borders
    return newImg

def main():
    """Takes an image filename as a command line argument. The function allows the user to select a region to zoom in on using the mouse as well as to specify a scaling factor. The region is "Zoomed...and Enhanced!" and displayed on the screen."""
    filename = sys.argv[1]

    #Create two copies of the given image
    #One that we will draw a green box on
    image = cImage.FileImage(filename)
    #The other we will pass to the processing functions
    imageCopy = cImage.FileImage(filename)

    #Display the given image
    originalWin = cImage.ImageWin("Original", image.getWidth(), image.getHeight())
    image.draw(originalWin)

    #Keeps asking the user to pick a region to zoom in on
    #until they make a valid choice
    picked = False
    while not picked:
        print("Please click the upper-left corner of the region")
        upperLeft = originalWin.getMouse()
        print("Please click the lower-right corner of the region")
        lowerRight = originalWin.getMouse()
        
        if lowerRight[0] < upperLeft[0] or lowerRight[1] < upperLeft[1]:
            print("Not a valid region")
        else:
            picked = True

    #Have to adjust the coordinates in the windw to account 
    #for the white border created by cImage
    ulX = upperLeft[0] - 5
    ulY = upperLeft[1] - 5
    lrX = lowerRight[0] - 5
    lrY = lowerRight[1] - 5

    #Create a green pixel for drawing a box around the zoom region.
    boxPixel = cImage.Pixel(0, 255, 0)

    #Draw the top and bottom sides of the box
    for x in range(ulX, lrX + 1):
        if ulY > 0:
            image.setPixel(x, ulY - 1, boxPixel)
            
        if lrY < image.getHeight() - 1:
            image.setPixel(x, lrY + 1, boxPixel)

    #Draw the left and right sides of the box
    for y in range(ulY, lrY + 1):
        if ulX > 0:
            image.setPixel(ulX - 1, y, boxPixel)

        if lrX < image.getWidth() - 1:
            image.setPixel(lrX + 1, y, boxPixel)

    #Keeps asking the user for a scaling factor
    #until they input something that is at least 1.
    scale = 0
    while scale <= 0:
        scale = int(input("Please pick a scaling factor (at least 1): "))

    print("Zooming and Enhancing...")
    
    #Sharpen the image ("enhance")
    enhanced = sharpenImage(imageCopy)
   
    #Zoom in on the specified region
    zoomed = zoom(enhanced, ulX, ulY, lrX, lrY, scale)

    #Display the enhanced and zoomed image
    zoomWin = cImage.ImageWin("Zoom...and Enhance!", zoomed.getWidth(), zoomed.getHeight())
    zoomed.draw(zoomWin)

    print("Click the zoom window to exit, when ready.")
    zoomWin.exitOnClick()

main()
    
