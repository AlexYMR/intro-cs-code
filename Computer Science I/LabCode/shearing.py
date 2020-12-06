import sys
import math
import cImage

def shearXAxis(origImg,factor):
    newImg = cImage.EmptyImage(origImg.getWidth(), origImg.getHeight())
    factor = math.radians(factor)
    m = math.cos(factor)/math.sin(factor)
    maxX = int(origImg.getWidth())
    maxNewX = int(maxX+m*origImg.getHeight())
    print(maxNewX)
    
    for x in range(origImg.getWidth()):
        for y in range(origImg.getHeight()):
            p = origImg.getPixel(x, y)
            
            newX = int(x+m*y)
            print(y)
            newImg.setPixel(x,y,p)
              
    return newImg

def main():
    fileName = sys.argv[1]
    factor = int(sys.argv[2])

    imageToProcess = cImage.FileImage(fileName)

    newImg = shearXAxis(imageToProcess,factor)

    myImageWin = cImage.ImageWin('Image Processing', imageToProcess.getWidth(),imageToProcess.getHeight() )
    
    newImg.draw(myImageWin)

    myImageWin.exitOnClick()

main()
