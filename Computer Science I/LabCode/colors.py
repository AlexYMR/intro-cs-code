import cImage
import sys

def getColorComponent(origImg,color):
    newImg = cImage.EmptyImage(origImg.getWidth(),origImg.getHeight())
    
    for x in range(origImg.getWidth()):
        for y in range(origImg.getHeight()):
            p = origImg.getPixel(x,y)
            if color == "r":
                newP = cImage.Pixel(p.getRed(),0,0)
            elif color == "b":
                newP = cImage.Pixel(0,p.getBlue(),0)
            elif color == "g":
                newP = cImage.Pixel(0,0,p.getGreen())
            newImg.setPixel(x,y,newP)
    return newImg

def main():
    fileName = sys.argv[1]

    imageToProcess = cImage.FileImage(fileName)
    
    newImg = getColorComponent(imageToProcess, "r")
    newImg2 = getColorComponent(imageToProcess, "b")
    newImg3 = getColorComponent(imageToProcess, "g")

    myImageWin = cImage.ImageWin('Image Processing', 3*imageToProcess.getWidth()+10,imageToProcess.getHeight() )
    
        
    newImg.draw(myImageWin)

    newImg2.setPosition(imageToProcess.getWidth()+10,0)

    newImg2.draw(myImageWin)

    newImg3.setPosition((imageToProcess.getWidth()+10)*2,0)

    newImg3.draw(myImageWin)

    myImageWin.exitOnClick()

main()
