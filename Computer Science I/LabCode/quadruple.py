import cImage
import sys
    

def quadrupleIt(sourceImg, factor):
    newImg = cImage.EmptyImage(factor*sourceImg.getWidth(), factor*sourceImg.getHeight())

    for x in range(sourceImg.getWidth()):
        for y in range(sourceImg.getHeight()):
            p = sourceImg.getPixel(x, y)
            for i in range(factor):
                for j in range(factor):
                    newImg.setPixel(factor*x+i, factor*y+j, p)
              
    return newImg

def main():
    fileName = sys.argv[1]

    imageToProcess = cImage.FileImage(fileName)

    newImg = quadrupleIt(imageToProcess, 4)

    myImageWin = cImage.ImageWin('Image Processing', 5*imageToProcess.getWidth()+10,\
                                     imageToProcess.getHeight()*4 )
    imageToProcess.draw(myImageWin)

    newImg.setPosition(imageToProcess.getWidth()+10,0)

    newImg.draw(myImageWin)

    myImageWin.exitOnClick()

main()
