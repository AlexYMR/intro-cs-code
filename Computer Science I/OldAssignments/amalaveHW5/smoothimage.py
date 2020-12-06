#--------------------
# // smoothimage.py
# // Part of HW5
# // Problem 1
#--------------------

import cImage as ci
import sys

def smoothImage(image):
    """
    Smoothens images by calculating the mean of a given pixel's and its eight neighboring pixels' color intensities. It
    calculates the mean for each color (r,g,b) discretely, and then combines the values to make a single pixel.
    Input: original image
    Output: smoothened image
    """
    newImg = ci.EmptyImage(image.getWidth(),image.getHeight())
            
    for x in range(1,image.getWidth()-1):
        for y in range(1,image.getHeight()-1):
            #--Accumulators for the sums used to calculate the mean for each color intensity
            redAcc = 0
            greenAcc = 0
            blueAcc = 0
            #--For loop automatically handles the summation for calculating the mean of the color intensities
            for i in range(-1,2):
                for j in range(-1,2):
                    p2 = image.getPixel(x+i,y+j)
                    redAcc = redAcc + p2.getRed()
                    greenAcc = greenAcc + p2.getGreen()
                    blueAcc = blueAcc + p2.getBlue()
            #--Calculates the averages for each color intensity
            redAvg = redAcc//9
            greenAvg = greenAcc//9
            blueAvg = blueAcc//9

            newP = ci.Pixel(redAvg,greenAvg,blueAvg)
            newImg.setPixel(x-1,y-1,newP) #--Makes sure that the pixels are placed at the borders
    return newImg

def main():
    """
    Uses smoothImage in order to smoothen an image inputted by the user. 
    """
    fileName = sys.argv[1]

    imageToProcess = ci.FileImage(fileName)
    
    newImg = smoothImage(imageToProcess)
    
    #--Ensuring that the window is wide enough to fit both images
    myImageWin = ci.ImageWin('Image Processing', 2*imageToProcess.getWidth(),imageToProcess.getHeight())
    
    imageToProcess.draw(myImageWin)
    
    #--Changes the position at which the second image will be drawn (so they don't overlap)
    newImg.setPosition(imageToProcess.getWidth(),0)

    newImg.draw(myImageWin)

    myImageWin.exitOnClick()

main()
